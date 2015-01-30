void tftPrint(double rt, double t, double rh, double p, String L1, String L2, String L3, boolean g, boolean d)
{
tft.setTextWrap(false);
  //Clear Screen
  tft.fillScreen(ST7735_BLACK);
  //Set Curser 
  tft.setCursor(0, 0);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(2);
  tft.println(String(t) + " F");
  tft.println(String(rh) + "%");
  tft.println(String(p,4) + " hg");
    //Print Run Time
    if (rt > 720)
    {
      tft.println(String(rt / 3600) + " h");
    }
    else
    {
      tft.println(String(rt / 60) + " m");
    }
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.println(L1);
  tft.println(L2);
  tft.println(L3);

  if (d)
  {
  tft.fillCircle(122,5,5, ST7735_RED); 
  }

  if (g)
  {
  tftGraph();
  }
  else
  {
   tftDPWBPrint(); 
  }
}

void tftGraph()
{
  tft.setCursor(0, (tft.height()-GraphHeight+2));
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(1);
  tft.println("A");
  
  tft.setCursor(0, 152);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(1);
  tft.println("B");
  
  //draw graph outlines
  tft.drawLine(0, tft.height()-GraphHeight, tft.width(), tft.height()-GraphHeight, ST7735_WHITE);
  tft.drawLine(tft.width()-GraphWidth, tft.height()-GraphHeight*0.8, tft.width(), tft.height()-GraphHeight*0.8, ST7735_WHITE);
  tft.drawLine(tft.width()-GraphWidth, tft.height()-GraphHeight*0.6, tft.width(), tft.height()-GraphHeight*0.6, ST7735_WHITE);
  tft.drawLine(tft.width()-GraphWidth, tft.height()-GraphHeight*0.4, tft.width(), tft.height()-GraphHeight*0.4, ST7735_WHITE);
  tft.drawLine(tft.width()-GraphWidth, tft.height()-GraphHeight*0.2, tft.width(), tft.height()-GraphHeight*0.2, ST7735_WHITE);  
  tft.drawLine((tft.width()-GraphWidth), tft.height()-GraphHeight, (tft.width()-GraphWidth), tft.height(), ST7735_WHITE);

  
  //define graph limits
  tft.setCursor(0, 80);
  tft.setTextColor(ST7735_RED);
  tft.print(GraphMinHum);
  tft.print("/");
  tft.print(GraphMaxHum);
  tft.print("% ");
  tft.setTextColor(ST7735_BLUE);
  tft.print(GraphMinTemp);
  tft.print("/");
  tft.print(GraphMaxTemp);
  tft.print("F");
  
  int n;
  int y1;
  int y2;
    //Humidity Graph
    for (n=0; n<(GraphWidth-1); n = n+1)
    {
    y1= round(tft.height()-(GraphHeight * (HumArray[n]- GraphMinHum)) / (GraphMaxHum - GraphMinHum) - 1);
    y2= round(tft.height()-(GraphHeight * (HumArray[n + 1]- GraphMinHum)) / (GraphMaxHum - GraphMinHum) - 1);
    if (HumArray[n] < GraphMaxHum && HumArray[n] > GraphMinHum && HumArray[n+1] < GraphMaxHum && HumArray[n+1] > GraphMinHum)
      {
        tft.drawLine(tft.width()-GraphWidth-1+n, y1, tft.width()-GraphWidth+n, y2, ST7735_RED);
      }
    }
    //Temperature Graph
    for (n=0; n<(GraphWidth-1); n = n+1)
    {
    y1= round(tft.height()-(GraphHeight * (TempArray[n]-GraphMinTemp)) / (GraphMaxTemp - GraphMinTemp));
    y2= round(tft.height()-(GraphHeight * (TempArray[n+1]-GraphMinTemp)) / (GraphMaxTemp - GraphMinTemp));
      if (TempArray[n] < GraphMaxTemp && TempArray[n] > GraphMinTemp && TempArray[n+1] < GraphMaxTemp && TempArray[n+1] > GraphMinTemp)
      {
      tft.drawLine(tft.width()-GraphWidth-1+n, y1, tft.width()-GraphWidth+n, y2, ST7735_BLUE);
      }
    }
}

void tftDPWBPrint()
{
  tft.setCursor(0, 88);
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(2);
  tft.print("DP:");
  tft.print(T_DP);
  tft.println(" F");
  tft.print("WB:");
  tft.print(T_WB);
  tft.println(" F");
  tft.print("W:");
  tft.print(W,1);
  tft.println(" g/lb");
  tft.print("h:");
  tft.print(h,1);
  tft.println(" btu/lb");
}
