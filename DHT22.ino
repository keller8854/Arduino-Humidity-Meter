void GetRelHumTemp ()
{
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f))
    {
      if (OutputSerial) Serial.println("Failed to read from DHT sensor!");
    return;
    }
  //Store Value for Relative Humidity  
  DHT22_RH = h;
  //Store Value for Temperature  
  DHT22_T = f;  
    //Output Values to Serial
    if (OutputSerial) Serial.print("Humidity: "); 
    if (OutputSerial) Serial.print(h);
    if (OutputSerial) Serial.print(" %\t");
    if (OutputSerial) Serial.println();  
    if (OutputSerial) Serial.print("Temperature: "); 
    if (OutputSerial) Serial.print(f);
    if (OutputSerial) Serial.print(" deg F\t");
}
