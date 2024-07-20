#include <Arduino.h>
#include <IRremote.h>
#include <WiFi.h>
#include <WebServer.h>

#define ssid "ESP32_AP5555"
#define password "123456789"

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
WebServer server(80);

//declare functions
void handler();
void togglePower();
void volUp();
void volDown();
void mute();
void handle_NotFound();
void decoder();

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(26, ENABLE_LED_FEEDBACK);
  IrSender.begin(33);
  pinMode(14, INPUT);

  // Setup WiFi
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);

  // Define routes
  server.on("/", handler);
  server.on("/power", togglePower);
  server.on("/up", volUp);
  server.on("/down", volDown);
  server.on("/mute", mute);
  server.onNotFound(handle_NotFound);

  // Start the server
  server.begin();
  Serial.println("Server started");
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  server.handleClient();
  decoder();
}

void decoder() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      IrReceiver.printIRResultRawFormatted(&Serial, true);
      IrReceiver.resume();
    } else {
      IrReceiver.resume();
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.printIRSendUsage(&Serial);
    }
  }
}
String getHTML() {
  String htmlcode = "<!DOCTYPE html><html>\n";
  htmlcode += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  htmlcode += "<title>ESP32 Web Server</title>\n";
  htmlcode += "<style>\n";
  htmlcode += "body { font-family: Arial, sans-serif; text-align: center; }\n";
  htmlcode += "button { font-size: 18px; padding: 10px 20px; margin: 10px; cursor: pointer; }\n";
  htmlcode += "</style>\n";
  htmlcode += "</head>\n";
  htmlcode += "<body>\n";
  htmlcode += "<h1>ESP32 Web Server</h1>\n";
  htmlcode += "<button onclick=\"location.href='/power'\">Toggle Power</button>\n";
  htmlcode += "<button onclick=\"location.href='/up'\">Volume Up</button>\n";
  htmlcode += "<button onclick=\"location.href='/down'\">Volume Down</button>\n";
  htmlcode += "<button onclick=\"location.href='/mute'\">Mute</button>\n";
  htmlcode += "</body>\n";
  htmlcode += "</html>\n";
  return htmlcode;
}

void handler(){
  server.send(200, "text/html", getHTML());
}

void togglePower() {
  IrSender.sendSamsung(0x7, 0x2, 1);
  server.send(200, "text/html", getHTML());
}

void volUp() {
  IrSender.sendSamsung(0x7, 0x7, 1);
  server.send(200, "text/html", getHTML());
}

void volDown() {
  IrSender.sendSamsung(0x7, 0xB, 1);
  server.send(200, "text/html", getHTML());
}

void mute() {
  IrSender.sendSamsung(0x7, 0xF, 1);
  server.send(200, "text/html", getHTML());
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not Found");
}
