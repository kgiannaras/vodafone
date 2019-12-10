#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0x90, 0xA2, 0xDA, 0x0D, 0x58, 0x6E };
IPAddress ip(192, 168, 1, 77);
IPAddress gateway(192, 168, 1, 1);
IPAddress mask(255, 255, 255, 0);
// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
int port = 8880;
EthernetServer server = EthernetServer(port);

void setup() {

// Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

pinMode(53, OUTPUT);

/// disabeling the SD card
pinMode(4, OUTPUT);
digitalWrite(4, HIGH);


  // start the Ethernet connection and the server:
  Ethernet.begin(mac , ip);//, gateway, mask);
  server.begin();
  Serial.print("server is at ");
  Serial.print(Ethernet.localIP()); Serial.print(":"); Serial.println(port);
}

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();

  if(client)
  {
      Serial.println("client connected");

      Serial.println(client.read());
      Serial.println(client.read());
     
      while(client.connected())
      {
          client.write("hi");
          client.println("hi, i am ethernet shield connected on mega 2560.");
          // give the web browser time to receive the data
          delay(1000);
          Serial.println("data sent to client.");
      }   
      // close the connection:
      client.stop();
      Serial.println("client disonnected");
  }
}
