//Sub Menu - Time
void TimeMenu()
{
int en = encoderValue;
//Display Menu Options
tft.fillScreen(ST7735_BLACK);
tft.setCursor(0, 0);
tft.println("Time");
tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
tft.println("");
tft.println("");
tft.setTextColor(ST7735_WHITE);
tft.setTextSize(2);
tft.setCursor(0, 0);
tft.println("Time");
tft.setTextColor(ST7735_RED);
tft.print("Hour: ");
tft.println(hour());
tft.setTextColor(ST7735_WHITE);
tft.print("Minute: ");
tft.println(minute());


delay (250);
  //Set encoder Value to match time
  encoderValue = hour() * 4;
  while (digitalRead(encoderSwitchPin)==0)
  {    
    Mode_Select = encoderValue/4;
      //Mode Select Minimium Value
      if (Mode_Select < 1)
        {
        encoderValue = 4;
        Mode_Select = encoderValue/4;
        }
        // Mode Select Maximium Value
      if (Mode_Select > 24)
        {
        encoderValue = 96;
        Mode_Select = encoderValue/4;
        }
    //Clear Hour Time Value
    tft.setCursor(0, 0);
    tft.println("");
    tft.setTextColor(ST7735_RED);
    tft.print("Hour: ");
    tft.fillRect(60,16,60,14,ST7735_BLACK);
    tft.println(Mode_Select);
    delay(100);
  }
  setTime(Mode_Select,minute(),0,day(),month(),year());
    //Set encoder Value to match time
  encoderValue = minute() * 4;
delay(250);
  while (digitalRead(encoderSwitchPin)==0)
  {    
    Mode_Select = encoderValue/4;
      //Mode Select Minimium Value
      if (Mode_Select < 1)
        {
        encoderValue = 4;
        Mode_Select = encoderValue/4;
        }
        // Mode Select Maximium Value
      if (Mode_Select > 60)
        {
        encoderValue = 240;
        Mode_Select = encoderValue/4;
        }
    //Clear Hour Time Value
    tft.setCursor(0, 0);
    tft.println("");
    tft.setTextColor(ST7735_WHITE);
    tft.print("Hour: ");
    tft.println(hour());
    tft.setTextColor(ST7735_RED);
    tft.print("Minute: ");
    tft.fillRect(85,32,40,14,ST7735_BLACK);
    tft.println(Mode_Select);
    delay(100);
  }
  setTime(hour(),Mode_Select,0,day(),month(),year());
  setDS3231time(second(), minute(), hour(), weekday(), day(), month(), year()-2000);
  //Restore Encoder Value
  encoderValue = en;
}
