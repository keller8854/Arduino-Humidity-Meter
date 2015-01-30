void GraphMenu()
{
  //Store Encoder Value
  int en = encoderValue;
  //Display Menu Options
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  tft.println("Graph");
  tft.drawLine(0, 14, tft.width(), 14, ST7735_WHITE);
  tft.setTextColor(ST7735_RED);
  tft.print("T Min: ");
  tft.println(GraphMinTemp);
  tft.setTextColor(ST7735_WHITE);
  tft.print("T Max: ");
  tft.println(GraphMaxTemp);
  tft.print("H Min: ");
  tft.println(GraphMinHum);
  tft.print("H Max: ");
  tft.println(GraphMaxHum);
  
delay(250);  
  //Set Min Graph Temp
  encoderValue = GraphMinTemp * 4;
  while (digitalRead(encoderSwitchPin)==0)
  {    
    
    Mode_Select = encoderValue/4;
      //Mode Select Minimium Value
      if (Mode_Select < -20)
        {
        encoderValue = -80;
        Mode_Select = encoderValue/4;
        }
        // Mode Select Maximium Value
      if (Mode_Select > 150)
        {
        encoderValue = 600;
        Mode_Select = encoderValue/4;
        }
    //Clear Hour Time Value
    tft.setCursor(0, 0);
    tft.println("");
    tft.setTextColor(ST7735_RED);
    tft.print("T Min: ");
    tft.fillRect(68,16,60,14,ST7735_BLACK);
    tft.println(Mode_Select);
    delay(150);
  }
  GraphMinTemp = Mode_Select;
  
delay(250);  
  //Set Max Graph Temp
  encoderValue = GraphMaxTemp * 4;
  while (digitalRead(encoderSwitchPin)==0)
  {    
    
    Mode_Select = encoderValue/4;
      //Mode Select Minimium Value
      if (Mode_Select < -20)
        {
        encoderValue = -80;
        Mode_Select = encoderValue/4;
        }
        // Mode Select Maximium Value
      if (Mode_Select > 150)
        {
        encoderValue = 600;
        Mode_Select = encoderValue/4;
        }
    //Clear Hour Time Value
    tft.setCursor(0, 0);
    tft.println("");
    tft.setTextColor(ST7735_WHITE);
    tft.print("T Min: ");
    tft.println(GraphMinTemp);
    tft.fillRect(68,32,60,14,ST7735_BLACK);
    tft.setTextColor(ST7735_RED);
    tft.print("T Max: ");
    tft.println(Mode_Select);
    delay(100);
  }
  GraphMaxTemp = Mode_Select;
  
delay(250);   
  //Set Min Graph Humidity
  encoderValue = GraphMinHum * 4;
  while (digitalRead(encoderSwitchPin)==0)
  {    
    
    Mode_Select = encoderValue/4;
      //Mode Select Minimium Value
      if (Mode_Select < 0)
        {
        encoderValue = 0;
        Mode_Select = encoderValue/4;
        }
        // Mode Select Maximium Value
      if (Mode_Select > 100)
        {
        encoderValue = 400;
        Mode_Select = encoderValue/4;
        }
    //Clear Hour Time Value
    tft.setCursor(0, 0);
    tft.println("");
    tft.println("");
    tft.setTextColor(ST7735_WHITE);
    tft.print("T Max: ");
    tft.println(GraphMaxTemp);
    tft.fillRect(68,48,60,14,ST7735_BLACK);
    tft.setTextColor(ST7735_RED);
    tft.print("H Min: ");
    tft.println(Mode_Select);
    delay(100);
  }
  GraphMinHum = Mode_Select;
  
delay(250);  
//Set Max Graph Humidity
  encoderValue = GraphMaxHum * 4;
  while (digitalRead(encoderSwitchPin)==0)
  {    
    
    Mode_Select = encoderValue/4;
      //Mode Select Minimium Value
      if (Mode_Select < 0)
        {
        encoderValue = 0;
        Mode_Select = encoderValue/4;
        }
        // Mode Select Maximium Value
      if (Mode_Select > 100)
        {
        encoderValue = 400;
        Mode_Select = encoderValue/4;
        }
    //Clear Hour Time Value
    tft.setCursor(0, 0);
    tft.println("");
    tft.println("");
    tft.println("");
    tft.setTextColor(ST7735_WHITE);
    tft.print("H Min: ");
    tft.println(GraphMinHum);
    tft.fillRect(68,64,60,14,ST7735_BLACK);
    tft.setTextColor(ST7735_RED);
    tft.print("H Max: ");
    tft.println(Mode_Select);
    delay(100);
  }
  GraphMaxHum = Mode_Select;
  WriteConfig();
  //Restor Encoder Value
  encoderValue = en;
}
