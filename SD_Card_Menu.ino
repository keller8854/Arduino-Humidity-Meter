void SDCardMenu()
{
  //Display Menu Options
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  tft.println("SD Card");
  tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
  tft.setTextColor(ST7735_RED);
  tft.println("Erase Data");
  tft.setTextColor(ST7735_WHITE);
  tft.println("Exit");
  
  delay (2000);
  //   -------- Main Menu
  while (digitalRead(encoderSwitchPin)==0)
  {
    Mode_Select = encoderValue/4;
    if (Mode_Select < 1)
    {
      encoderValue = 4;
      Mode_Select = encoderValue/4;
    }
    
    if (Mode_Select > 2)
    {
      encoderValue = 8;
      Mode_Select = encoderValue/4;
    }
    
  
  switch (Mode_Select)
      {
       case 1:
        {
        //tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("SD Card");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_RED);
        tft.println("Erase Data");
        tft.setTextColor(ST7735_WHITE);
        tft.println("Exit");
        } break;
       case 2:
        {
        //tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("SD Card");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_WHITE);
        tft.println("Erase Data");
        tft.setTextColor(ST7735_RED);
        tft.println("Exit");
        } break;       
      }
  }
  //Function calls to sub menus
      switch (Mode_Select)
      {
       case 1:
        {
         EraseSD();
        } break;
        case 2:
        {
        //Do Nothing, Exit
        } break;
      }
}

void EraseSD()
{
   tft.fillScreen(ST7735_BLACK); 
   tft.setCursor(0, 0);
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(2);
   tft.println("Erasing:");
   delay(500);
     // delete the file:
  Serial.println("Removing datalog.txt...");
  SD.remove("datalog.txt");

  if (SD.exists("datalog.txt")){ 
    Serial.println("datalog.txt exists.");
    tft.setTextColor(ST7735_WHITE);
    tft.setTextSize(2);
    tft.println("datalog.txt exists.");
  }
  else {
    Serial.println("datalog.txt doesn't exist.");
    tft.setTextColor(ST7735_WHITE);
    tft.setTextSize(2);
    tft.println("datalog.txt doesn't exist.");  
  }
}
