void setup()
{
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
    //Setup for Rotatary Encoder
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);
  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(4, updateEncoder, CHANGE); 
  attachInterrupt(5, updateEncoder, CHANGE);
  
  // iniatialize the pushbutton
  pinMode(encoderSwitchPin, INPUT);
  attachInterrupt(1, updateEncoder, HIGH);
  
  if (OutputSerial) Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
      // see if the card is present and can be initialized:

  if (OutputSerial) Serial.println("card initialized.");
  //ErrorMsg = "card initialized";
  if (OutputSerial) Serial.println("REBOOT");
  dht.begin();
  // Initialize the sensor (it is important to get calibration values stored on the device).
    if (pressure.begin())
    {
    if (OutputSerial) Serial.println("BMP180 init success");
    }
    else
    {
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.
    if (OutputSerial) Serial.println("BMP180 init fail\n\n");
    ErrorMsg = "BMP180 init fail"; // Error Catch
    //Mwhile(1); // Pause forever.
    }
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);
  
  // Used to Manually Set time
  //setTime(1,1,1,1,1,2015); // Set Time hour, minute, second, day, month, year
  
  //Retrieve Time from DS3231
  alignhtime();  
  
  if (!SD.begin(chipSelect))
  {
  if (OutputSerial) Serial.println("Card failed, or not present");
  ErrorMsg = "SD Card failed"; // Error Catch
  // don't do anything more:
  return;
  }
  //Get SD Values
  ReadConfig();
}
