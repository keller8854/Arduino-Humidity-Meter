void GetPressureTemp ()
{
char status;
double T,P,p0,a;
if (OutputSerial) Serial.println();
status = pressure.startTemperature();
if (status != 0)
  {
  // Wait for the measurement to complete:
  delay(status);
  // Retrieve the completed temperature measurement:
  // Note that the measurement is stored in the variable T.
  // Function returns 1 if successful, 0 if failure.
  status = pressure.getTemperature(T);
    if (status != 0)
    {
    // Print out the measurement:
    BMP180_T = (9.0/5.0)*T+32.0,2;
      if (OutputSerial) Serial.print("BMP180 Temperature: ");
      if (OutputSerial) Serial.print(BMP180_T,2);
      if (OutputSerial) Serial.println(" deg F");
    // Start a pressure measurement:
    // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
    // If request is successful, the number of ms to wait is returned.
    // If request is unsuccessful, 0 is returned.
    status = pressure.startPressure(3);
      if (status != 0)
      {
      // Wait for the measurement to complete:
      delay(status);
      // Retrieve the completed pressure measurement:
      // Note that the measurement is stored in the variable P.
      // Note also that the function requires the previous temperature measurement (T).
      // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
      // Function returns 1 if successful, 0 if failure.
      status = pressure.getPressure(P,T);
        if (status != 0)
        {
        // Print out the measurement:
        BMP180_P = P*0.0295333727;
          if (OutputSerial) Serial.print("Absolute pressure: ");
          if (OutputSerial) Serial.print(BMP180_P,2);
          if (OutputSerial) Serial.println(" inHg");
          if (OutputSerial) Serial.print("Absolute pressure: ");
          if (OutputSerial) Serial.print(BMP180_P*13.595,2);
          if (OutputSerial) Serial.println(" w.g.");
        
          //Compensated Pressure
        BMP180_P_ALT = pressure.sealevel(P,Altitude*0.3048); 
          if (OutputSerial) Serial.print("relative (sea-level) pressure: ");
          if (OutputSerial) Serial.print(BMP180_P_ALT*0.0295333727,2);
          if (OutputSerial) Serial.println(" inHg");
        }
        else
        {
          if (OutputSerial) Serial.println("error retrieving pressure measurement\n");
        ErrorMsg = "error retrieving pressure measurement"; // Error Catch
        }
        }
        else
        {
        if (OutputSerial) Serial.println("error starting pressure measurement\n");
        ErrorMsg = "error starting pressure measurement"; // Error Catch
        } 
      }
      else
      {  
      if (OutputSerial) Serial.println("error retrieving temperature measurement\n");
      ErrorMsg = "error retrieving temperature measurement"; // Error Catch
      }
    }
    else
    {
      if (OutputSerial) Serial.println("error starting temperature measurement\n");
    ErrorMsg = "error starting temperature measurement"; // Error Catch
    }
}
