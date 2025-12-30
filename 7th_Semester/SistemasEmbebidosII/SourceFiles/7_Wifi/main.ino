#include &lt;Arduino.h&gt;
#include &lt;WiFi.h&gt;
#include &lt;AsyncJson.h&gt;
#include &lt;ArduinoJson.h&gt;
#include &lt;ESPAsyncWebServer.h&gt;
#include &lt;FastLED.h&gt;
CRGB leds[2];
AsyncWebServer server(80);
const char *ssid = &quot;Galaxy A51&quot;;
const char *password = &quot;2444666668888888&quot;;

AsyncCallbackJsonWebHandler *handler = new AsyncCallbackJsonWebHandler(&quot;/&quot;,
[](AsyncWebServerRequest *request, JsonVariant &amp;json) {
 JsonObject jsonObject = json.as&lt;JsonObject&gt;();
 byte r = jsonObject[&quot;Red&quot;];
 byte g = jsonObject[&quot;Green&quot;];
 byte b = jsonObject[&quot;Blue&quot;];
 leds[0] = CRGB(r, g, b);
 leds[1] = CRGB(r, g, b);
 FastLED.show();
 Serial.print(&quot;R:&quot;);
 Serial.print(r);
 Serial.print(&quot; G:&quot;);
 Serial.print(g);
 Serial.print(&quot; B:&quot;);
 Serial.println(b);
 request-&gt;send(200, &quot;text/plain&quot;, &quot;Color actualizado&quot;);
});

void setup() {
 FastLED.addLeds&lt;WS2812, 13, RGB&gt;(leds, 2);
 Serial.begin(9600);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(1000);

   Serial.println(&quot;Connecting to WiFi...&quot;);
 }
 Serial.println(WiFi.localIP());
 DefaultHeaders::Instance().addHeader(&quot;Access-Control-Allow-Origin&quot;, &quot;*&quot;);
 DefaultHeaders::Instance().addHeader(&quot;Access-Control-Allow-Methods&quot;, &quot;GET, POST, OPTIONS&quot;);
 DefaultHeaders::Instance().addHeader(&quot;Access-Control-Allow-Headers&quot;, &quot;Content-Type&quot;);
 server.onNotFound([](AsyncWebServerRequest *request) {
   if (request-&gt;method() == HTTP_OPTIONS) {
     request-&gt;send(204);  // No Content (respuesta correcta para preflight)
   } else {
     request-&gt;send(404, &quot;text/plain&quot;, &quot;Not found&quot;);
   }
 });

 server.on(&quot;/&quot;, HTTP_GET, [](AsyncWebServerRequest *request) {
   request-&gt;send(200, &quot;application/json&quot;, &quot;{\&quot;msg\&quot;:\&quot;GET desde ESP32\&quot;}&quot;);
 });
 server.addHandler(handler);
 server.begin();
}

void loop() {
}
