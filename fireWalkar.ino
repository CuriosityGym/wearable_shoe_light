/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      45
unsigned long currentMillis=0;
unsigned long last_bounce=0;
boolean playing = false;
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

//int delayval = 500; // delay for half a second
byte count=0;
byte i=0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
 
    strip.begin();
    strip.setBrightness(50);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  //Serial.println(sensorValue);
  //delay(1);        // delay in between reads for stability
 /* currentMillis = millis();
  if (currentMillis - last_bounce > 2000 && playing == true) {
     
      playing=false;
      for(i=0; i<=NUMPIXELS; i++) {
        strip.setPixelColor(i, 0,0,0);
        strip.show();
        delay(40);}
        
      count = 0;
      
    }*/
  if(sensorValue > 40)
    {
      count++;
      playing = true;
     // last_bounce = millis();
     if(count==1)
       {
        for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 255,0,0);strip.show(); delay(10);}//Green
        //strip.show();
        delay(100);
       }
     if(count==2)
      {
       for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 255,0,255);strip.show(); delay(10);}//Cyan
        //strip.show();
      }
     if(count==3)
      {
       for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 0,0,255);strip.show(); delay(10);}//Blue
       // strip.show();
      }
      if(count==4)
      {
       for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 0,255,255);strip.show(); delay(10);}//Magenta
        //strip.show();
      }
      if(count==5)
      {
       for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 0,255,0);strip.show(); delay(10);}//Red
        //strip.show();
      }
      if(count==6)
      {
       for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 50,255,0);strip.show(); delay(10);}//Orange
        //strip.show();
      }
      if(count==7)
      {
       for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 255,255,0);strip.show(); delay(10);}//Yellow
        //strip.show();
      } 
      if(count==8)
      {
        count= count+1;
       for(i=0; i<=NUMPIXELS; i+2) {
        strip.setPixelColor(i, 128,128,128);strip.show(); delay(10);}//White
        //strip.show();
      } 
     
      if(count>=9)
        {
          //theaterChaseRainbow(50);
          for(i=0; i<=NUMPIXELS; i++) {
        strip.setPixelColor(i, 0,0,0);strip.show(); delay(10);}
        //strip.show();

          count=0; 
          delay(1000);      
        }
   delay(100);
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

