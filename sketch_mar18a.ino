/*
  WiFi Web Server

 A simple web server that shows the value of the analog input pins.
 using a WiFi shield.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * Analog inputs attached to pins A0 through A5 (optional)

 created 13 July 2010  by dlf (Metodo2 srl)
 modified 31 May 2012  by Tom Igoe
 modified 27 Oct 2015  by Bob Martin

 */

//#include<Servo.h>
#include <SPI.h>
#include <WiFi101.h>
#include <Wire.h>


char ssid[] = "topkek";                  // your network SSID (name)
char pass[] = "123soleil3";               // your network password
int keyIndex = 0;                         // your network key Index number (needed only for WEP)

//Servo Monservo;

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup()
{
 // Monservo.attach(6);
  
  // STS Led
  pinMode(PIN_LED_13,OUTPUT);
  

  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  wifi_init();
}

void wifi_init(void)
{
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  server.begin();

  //  connected now, so print out the status:
  printWifiStatus();
}

void loop()
{
  // listen for incoming clients

  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = false;
    if (client.connected())
    {
      String chaineRecue = "";
      unsigned cptCar = 0;
      
      while (client.available())
      {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply

        cptCar = cptCar + 1;
        if (cptCar <= 100) chaineRecue = chaineRecue + c;
        
        if (c == '\n')
        {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else
        {
          if (c != '\r')
          {
            // you've gotten a character on the current line
            currentLineIsBlank = false;
          }
        }
      }
      
      Serial.println ("chaine lue : ");
      Serial.println (chaineRecue);
  
      if (chaineRecue.startsWith("GET"))
      {
        unsigned id = 5;
        String chaineAnalyse = chaineRecue.substring(id, id + 1);
  
        if (chaineAnalyse == "?")
        {
          chaineAnalyse = chaineRecue.substring(10, 12);

          if (chaineAnalyse == "ON")
          {
            digitalWrite(PIN_LED_13, LOW);
         //   Monservo.write(90);
          }
          else
          {
          //  Monservo.write(180);
            digitalWrite(PIN_LED_13, HIGH);
          }
        }
      }

      // send a standard http response header
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("Connection: close");  // the connection will be closed after completion of the response
      //client.println("Refresh: 5");  // refresh the page automatically every 5 sec
      client.println();
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");

      // output the value of each analog input pin
      client.println("<form method='get'>");
      client.println("<input type='checkbox' name='LED' value='ON'>Allumer le feu</input>");
      //client.println("<input type='checkbox' name='LEp' value='OFF'>Eteindre le feu</input>");
      client.println("<input type='submit'></input>");
      client.println("</form>");
      client.println("</html>");
          
    }
    // give the web browser time to receive the data
    delay(1);

    // close the connection:
    client.stop();
    //Serial.println("client disconnected");
  }
}

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
