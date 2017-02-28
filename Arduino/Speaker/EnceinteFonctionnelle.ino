    /*
    Adafruit Arduino - Lesson 3. RGB LED
    */

#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>
#include <VirtualWire.h>

    TMRpcm audio;
    File myFile;
 
    int redPin = A3;
    int greenPin = A4;
    int bluePin = A2;
unsigned long time = 0;

    // Receive info from 433MHz
    char Message[VW_MAX_MESSAGE_LEN]; 
    char Color[7];
    char Music[13];
     
    void setColor(int red, int green, int blue)
    {
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);  
    }
     
    void setup()
    {
      
        Serial.begin(9600);
      
            // Red color 
      setColor(255, 0, 0);  // red
      
        // SERVEUR 433MHz
        Serial.println("Serveur de reception ON");
        // Initialise the IO and ISR
        //vw_set_ptt_inverted(true); // Required for DR3100
        vw_setup(2000);   // Bits per sec
        vw_set_rx_pin(2); 
        vw_rx_start(); // Start the receiver PLL running
      
         // RGB LED
         pinMode(redPin, OUTPUT);
         pinMode(greenPin, OUTPUT);
         pinMode(bluePin, OUTPUT);  
      
        // SD Module
        Serial.println("Chargement du contenu de la carte SD");
      
        if (!SD.begin(4)) {
          Serial.println("Probleme carte SD. Est elle branchee ?");
          return;
        }
        Serial.println("Chargement terminé");
      
        // Module Son
        audio.speakerPin=9;
        audio.volume(1);
        audio.setVolume(5);

 

    }
    
    void loop()
    {

 
      // Buffer 433
      uint8_t buf[VW_MAX_MESSAGE_LEN];
      uint8_t buflen = VW_MAX_MESSAGE_LEN;

 if (vw_get_message(buf, &buflen)) 
  {
    int i;

    for (i = 0; i < buflen; i++)
    {               
      Message[i] = char(buf[i]);
    }

    if (Message[0] == 'C')
    {
        for (i = 0; i < 6; i++)
        {
          Color[i] = Message[i+6];
          }
          Color[6] = '\0';


          // Convertir hexa en RGB
          long number = (long) strtol( &Color[0], NULL, 16);
          int r = number >> 16;
          int g = number >> 8 & 0xFF;
          int b = number & 0xFF;
          
          setColor(r,g,b);

          Serial.print("Color : ");
          Serial.print(r);
          Serial.print(",");
          Serial.print(g);
          Serial.print(",");
          Serial.println(b);
      }
      
      else if (Message[0] == 'M')
      {
                for (i = 0; i < 12; i++)
        {
          Music[i] = Message[i+6];
          }
          Music[12] = '\0';
          
          Serial.print("Music : ");
          Serial.println(Music);

      // Lancement de la musique
      if (SD.exists(Music)) {
    
        audio.play(Music);
      }
        
        } else if(Message[0]=='T'){
          Serial.print("Message de test");
          }else {
          
          Serial.print("Message mal formaté : ");
          Serial.println(Message);
          }

    Message[buflen] = '\0';


 
}
    }
 
    
     

