void tftMenu()
{
  encoderValue = 4;
  Mode_Select = encoderValue/4;
  
  //Delay to wait for button press
  tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("Menu");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_RED);
        tft.println("Time");
        tft.setTextColor(ST7735_WHITE);
        tft.println("Date");
        tft.println("SD Card");
        tft.println("Graph");
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
    
    if (Mode_Select > 5)
    {
      encoderValue = 20;
      Mode_Select = encoderValue/4;
    }
    
    Serial.print("Mode:");
    Serial.println(Mode_Select);
    
    switch (Mode_Select)
      {
       case 1:
        {
        //tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("Menu");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_RED);
        tft.println("Time");
        tft.setTextColor(ST7735_WHITE);
        tft.println("Date");
        tft.println("SD Card");
        tft.println("Graph");
        tft.println("Exit");
        } break;
        case 2:
        {
        //tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("Menu");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_WHITE);
        tft.println("Time");
        tft.setTextColor(ST7735_RED);
        tft.println("Date");
        tft.setTextColor(ST7735_WHITE);
        tft.println("SD Card");
        tft.println("Graph");
        tft.println("Exit");
        } break;
       case 3:
        {
        //tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("Menu");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_WHITE);
        tft.println("Time");
        tft.println("Date");
        tft.setTextColor(ST7735_RED);
        tft.println("SD Card");
        tft.setTextColor(ST7735_WHITE);
        tft.println("Graph");
        tft.println("Exit");
        } break;
       case 4:
        {
        //tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("Menu");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_WHITE);
        tft.println("Time");
        tft.println("Date");
        tft.println("SD Card");
        tft.setTextColor(ST7735_RED);
        tft.println("Graph");
        tft.setTextColor(ST7735_WHITE);
        tft.println("Exit");
        } break;
        case 5:
        {
        //tft.fillScreen(ST7735_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.println("Menu");
        tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
        tft.setTextColor(ST7735_WHITE);
        tft.println("Time");
        tft.println("Date");
        tft.println("SD Card");
        tft.println("Graph");
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
         TimeMenu();
        } break;
        case 2:
        {
        DateMenu();
        } break;
       case 3:
        {
        SDCardMenu();
        } break;
       case 4:
        {
        GraphMenu();
        } break;
        case 5:
        {
        //Do Nothing and exit
        } break;
      }    
  delay (250);
}
