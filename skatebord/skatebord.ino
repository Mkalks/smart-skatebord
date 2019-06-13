/*
  Created 2018
  by Mkalks
  Mkalks Home Labs Inc.
*/
#define red 9
#define green 10
#define blue 11
#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
short del = 5;
unsigned char mod = 0;
unsigned char r;
unsigned char g;
unsigned char b;
unsigned char r1;
unsigned char g1;
unsigned char b1;
boolean pin5 = 0;
boolean flag = 0;
unsigned char t = 0;
unsigned char t1 = 0;
unsigned char t2 = 0;
unsigned char t3 = 255;
unsigned char t4 = 255;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Auth Token";

SoftwareSerial SerialBLE(7, 8); // RX, TX
BlynkTimer timer;
// Attach virtual serial terminal to Virtual Pin V1
WidgetTerminal terminal(V1);
// You can send commands from Terminal to your hardware. Just use
// the same Virtual Pin as your Terminal Widget
BLYNK_WRITE(V1)
{
  if(String("Help") == param.asStr() && String("help") == param.asStr()) {
    terminal.println("Colour - ");
  }else if(String("Colour") == param.asStr() && String("colour") == param.asStr()) {
    terminal.print("Colour is: ") ;
    terminal.print("r=") ;
    terminal.print(r) ;
    terminal.print(" ") ;
    terminal.print("g=") ;
    terminal.print(g) ;
    terminal.print(" ") ;
    terminal.print("b=") ;
    terminal.println(b) ;
  }
  // Ensure everything is sent
  terminal.flush();
}
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V2
BLYNK_WRITE(V2)
{
r = param.asInt(); // assigning incoming value from pin V2 to a variable

  // process received value
}
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V3
BLYNK_WRITE(V3)
{
g = param.asInt(); // assigning incoming value from pin V3 to a variable

  // process received value
}
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V4
BLYNK_WRITE(V4)
{
b = param.asInt(); // assigning incoming value from pin V4 to a variable

  // process received value
}
BLYNK_WRITE(V5)
{
 pin5 = param.asInt(); // assigning incoming value from pin V5 to a variable

  // process received value
}
BLYNK_WRITE(V6)
{
 del = param.asInt(); // assigning incoming value from pin V8 to a variable

  // process received value
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");

  // This will print Blynk Software version to the Terminal Widget when
  // your hardware gets connected to Blynk Server
  terminal.println(F("Blynk v" BLYNK_VERSION));
  terminal.println("Program v1.0");
  terminal.flush();
  terminal.println("      ////      ////         ||   //        ////        ||        ||   //  ////////");
  delay(167);
  terminal.println("     //  //     //  //       ||  //        //  //       ||        ||  //   //      ");
  delay(167);
  terminal.println("    //    //   //    //      || //        //    //      ||        || //    //      ");
  delay(167);
  terminal.println("   //     //  //      //     ||//        //      //     ||        ||//     ////////");
  delay(167);
  terminal.println("  //       ////        //    || //      ////////////    ||        || //          //");
  delay(167);
  terminal.println(" //         //          //   ||  //    //          //   ||        ||  //         //");
  delay(167);
  terminal.println("//                       //  ||   //  //            //  ||||||||| ||   //  ////////");
  terminal.println();
  terminal.println("Device is started");
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer

  if(pin5 == 1){
    rainbol ();
  }else if(pin5 == 0){
  colour ();
  flag = 0;
  }
  
}
void colour ()
{
analogWrite(red,r);
analogWrite(green,g);
analogWrite(blue,b);
}
void rainbol ()
{
while(t < 255 && flag == 0){
  flag++;
  delay(del);
analogWrite(red,t);
analogWrite(green,0);
analogWrite(blue,0);
t++;
}
while(t1 < 255){
    delay(del);
analogWrite(red,t3);
analogWrite(green,t1);
analogWrite(blue,0);
t4=255;
t=0;
t3--;
t1++;
}
while(t2 < 255){
    delay(del);
analogWrite(red,0);
analogWrite(green,t4);
analogWrite(blue,t2);
t3=255;
t1=0;
t4--;
t2++;
}
while(t < 255){
    delay(del);
analogWrite(red,t);
analogWrite(green,0);
analogWrite(blue,t3);
t4=255;
t2=0;
t3--;
t++;
}
}
