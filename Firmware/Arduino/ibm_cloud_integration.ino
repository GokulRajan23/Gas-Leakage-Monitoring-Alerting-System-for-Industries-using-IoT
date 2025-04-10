#include <WiFi.h>
#include <PubSubClient.h>
void callback(char* subscribetopic, byte* payload, unsigned int payloadLength);
//-------credentials of IBM Accounts------ #define ORG "ohyeah"//IBM ORGANITION ID
#define DEVICE_TYPE "NODEMCU"//Device type mentioned in ibm watson IOT Platform
#define DEVICE_ID "ASHFAQ1824"//Device ID mentioned in ibm watson IOT Platform
#define TOKEN "ashlord" //Token
String data3;
char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char publishTopic[] = "iot-2/evt/Gas/fmt/json";
char publishTopic2[] = "iot-2/evt/Loc/fmt/json";
char subscribetopic[] = "iot-2/cmd/home/fmt/String";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;
WiFiClient wifiClient;
PubSubClient client(server, 1883, callback ,wifiClient);
const int gasSensor = A0;
#define SOUND_SPEED 0.034
int gasValue = 0;
String latitude = "0.000000";
String longitude = "0.000000";
void setup()
{
Data Transfer:
As a system, it should send the data of sensor values along with latitudes and longitudes to the IBM cloud
PNT2022TMID53571
Serial.begin(115200);
wificonnect();
mqttconnect();
}
void loop()
{
gasValue = random(600,750);
Serial.print("Gas Value: ");
Serial.println(gasValue);
delay(1000);
PublishData(gasValue);
delay(1000);
if(gasValue > 700)
{
latitude = "13.148760";
longitude = "80.229100";
PublishString(latitude, longitude);
}
if (!client.loop())
{
mqttconnect();
}
Serial.println();
Serial.println("----------------------------------------------------------------------");
Serial.println();
delay(3000);
}
void PublishData(int gas)
{
mqttconnect();
String payload = "{\"Gas Value\":";
payload += gas;
payload += "}";
Serial.print("Sending payload Gas: ");
Serial.println(payload);
if (client.publish(publishTopic, (char*) payload.c_str()))
{
Serial.println("Gas is Published");
}
else
{
Serial.println("Gas is not Published");
}
}
void PublishString(String lat, String lon)
{
mqttconnect();
String payload2 = "{\"d\":{\"Latitude\":";
payload2 += lat;
payload2 += ",""\"Longitude\":";
payload2 +=lon;
payload2 +="}}";
Serial.print("Sending Payload Location: ");
Serial.println(payload2);
if (client.publish(publishTopic2, (char*) payload2.c_str()))
{
Serial.println("Location is Published");
}
else
{
Serial.println("Location is not Published");
}
}
void mqttconnect()
{
if (!client.connected())
{
Serial.print("Reconnecting client to ");
Serial.println(server);
while (!!!client.connect(clientId, authMethod, token))
{
Serial.print(".");
delay(500);
}
initManagedDevice();
Serial.println();
}
}
void wificonnect()
{
Serial.println();
Serial.print("Connecting to ");
WiFi.begin("Wokwi-GUEST", "", 6);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}
void initManagedDevice()
{
if (client.subscribe(subscribetopic))
{
Serial.println((subscribetopic));
Serial.println("subscribe to cmd OK");
}
else
{
Serial.println("subscribe to cmd FAILED");
}
}
void callback(char* subscribetopic, byte* payload, unsigned int payloadLength)
{
Serial.print("callback invoked for topic: ");
Serial.println(subscribetopic);
for (int i = 0; i < payloadLength; i++)
{
//Serial.print((char)payload[i]);
data3 += (char)payload[i];
}
Serial.println("data: "+ data3);
data3="";
}

