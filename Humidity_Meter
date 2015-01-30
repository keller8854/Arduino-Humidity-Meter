//By Nicholas Keller
//Code used for Custom MAde Humidity Meter using BMP180 and DHT22
//Include Libbrary for BMP 180
#include <SFE_BMP180.h>
#include <Wire.h>

//Include string operators
#include <String.h>
//Include Libraries for Datalogging to Sd card
#include <SD.h>
// Libraries for DHT 22
#include "DHT.h"
//Libraries for LCD Screen
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
//Libraries for DS3231
#define DS3231_I2C_ADDRESS 0x68

//Variable for Rotary Encoder
int encoderPin1 = 19;
int encoderPin2 = 18;
volatile int lastEncoded = 0;
volatile long encoderValue = 2;

//Variable for Pushbutton/ Mode Select
int encoderSwitchPin = 3 ; //push button switch
int EncoderSwitchValue = 0;
int Mode_Select = 0;
int ButtonState = 0;
volatile int MenuCount = 0;

//Library for time and variables
#include <Time.h>

//Pin Variable for SD Card
const int chipSelect = 4;

//Pin Variables for DHT22
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

//Define Pins for TFT
#define TFT_CS     53
#define TFT_RST    9  // you can also connect this to the Arduino reset
#define TFT_DC     8
#define TFT_SCLK 52   // set these to be whatever pins you like!
#define TFT_MOSI 51   // set these to be whatever pins you like!
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

//SFE_BMP180 object, here called "pressure":
SFE_BMP180 pressure;
double BMP180_P = 0; //Store Variable for Pressure from BMP 180 Sensor
double BMP180_T = 0; //Store Variable for Temperture from BMP 180 Sensor
double BMP180_P_ALT = 0; //
int Altitude= 700; //altitude for indiana in feet
double DHT22_RH = 0; //Store Variable for RH from DHT22
double DHT22_T = 0; //Store Variable for T from DHT22

//Variable for read delays
int ReadDelay = 3000; // Delay in Milliseconds to read values
double RunTime = 0; //Define Runtime variable, used for data logging loops

//Variable for TFT Graph
#define GraphWidth 120
int GraphHeight = 72;
int i;//variable used for counting

//Graph Min and Max Settings
int GraphMinHum = 0;
int GraphMaxHum = 100;
int GraphMinTemp = 0;
int GraphMaxTemp = 95;
//String used to hold configuration settings
String ConfigurationSettings = "";


//Variables for Text Lines on Screen
String TextL1 = "";
String TextL2 = "";
String TextL3 = "";
int HumArray [GraphWidth]; // Array for storing humidity values
int TempArray [GraphWidth]; // Array for storing temperature values
String ErrorMsg = ""; //Error Message Catcher
//Variable for Calculating wet bulb, dew point, humidity ratio and enthalpy
double T_WB = 0;
double T_DP = 0;
double W = 0;
double h = 0;

//Variable for enable &disable of features
boolean Graph = false;
boolean Datalog = true;
boolean OutputSerial = true;

void loop()
{
  //Get Pushbutton state from encoder
  ButtonState = digitalRead(encoderSwitchPin);
  //If Pushbutton is pressed, open Menu
  if (ButtonState)
  {
   tftMenu(); 
  }
  
  //Switch Mode
  Mode();
  
  //Set up delay to get repeated reading on set interval
  if ( RunTime*1000 + ReadDelay < millis())
  {    
  RunTime = millis()/1000;
  //Set String to get current date and time
  TextL1 = String(month()) + "/" + String(day()) + "/" + String(year()) + " " + String(hour()) + ":" + String(minute()) + ":" + String(second());
  //Function to get Relative Humidity and Temperature from DHT22
  GetRelHumTemp ();
  //Function to get Atmospheric and Temperature from BMP180
  GetPressureTemp ();
  //Calculate Wet Bulb
  T_WB = CalcWB(DHT22_T, DHT22_RH, BMP180_P);
  //Calculate Dew Point
  T_DP = CalcDP(DHT22_T, DHT22_RH);
  //Calculate Humidity Ratio
  W = CalcW(DHT22_T, DHT22_RH, BMP180_P);
  //Calculate Enthalpy
  h = Calch(DHT22_T, W);
    //Store Humidity into Array
      for (i =0; i<(GraphWidth-1); i = i + 1)
      {
      HumArray [i] = HumArray [i+1];
      }
      HumArray [GraphWidth-1] = DHT22_RH;
      //Store Temperature into Array    
      for (i =0; i<(GraphWidth-1); i = i + 1)
      {
      TempArray [i] = TempArray [i+1];
      }
      TempArray [GraphWidth-1] = DHT22_T;
         
  //Display Error Message on Line 2
  TextL2 = ErrorMsg;
  //Send Variables to display function
  tftPrint(RunTime, DHT22_T, DHT22_RH, BMP180_P, TextL1, TextL2, TextL3, Graph, Datalog);
    //If Datalof is true, then write values to SD Card
    if (Datalog)
    {
      WriteData(RunTime, DHT22_T, DHT22_RH, BMP180_P, ErrorMsg, TextL1, TextL2);
    }    
  }
}
