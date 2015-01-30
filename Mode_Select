void Mode()

{
      Mode_Select = encoderValue/4;
      //Mode Select Minimium Value
      if (Mode_Select < 1)
        {
        encoderValue = 4;
        Mode_Select = encoderValue/4;
        }
        // Mode Select Maximium Value
      if (Mode_Select > 2)
        {
        encoderValue = 8;
        Mode_Select = encoderValue/4;
        }
        
        if (Mode_Select == 1) Graph = true;
        if (Mode_Select > 1) Graph = false;        
}
