void WriteData(double rt, double tp, double rh, double absp, String L1, String L2, String L3)
{
 String DataString = ""; //data String to write to file
 DataString = "runtime:" "," + String(rt) + "," + "s" + ",";
 DataString = DataString + "Temp (DB):" + "," + String(tp) +"," + "deg F" + ",";
 DataString = DataString + "Relative Humidity:" + "," + String(rh) + "," + "%" + "," ;
 DataString = DataString + "Absolute Pressure:" + "," + String(absp,4) + "," + "in. hg." + ",";
 DataString = DataString + "Temp (DP)" + "," + String(T_DP) + "," + "deg F." + ",";
 DataString = DataString + "Temp (WB)" + "," + String(T_WB) + "," + "deg F." + ",";
 DataString = DataString + L1 + ",";
 DataString = DataString + L2 + ",";
 DataString = DataString + L3 + ",";
 DataString = DataString + "Month:" + "," + month() + ",";
 DataString = DataString + "Day:" + "," + day() + ",";
 DataString = DataString + "Year:" + "," + year() + ",";
 DataString = DataString + "Hour:" + "," + hour() + ",";
 DataString = DataString + "Min:" + "," + minute() + ",";
 DataString = DataString + "Second:" + "," + second();
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  // if the file is available, write to it:
  if (dataFile)
  {
    dataFile.println(DataString);
    dataFile.close();
    // print to the serial port too:
    if (OutputSerial) Serial.println(DataString);
  }  
  // if the file isn't open, pop up an error:
  else
  {
    if (OutputSerial) Serial.println("error opening datalog.txt");
  }
}


void WriteConfig()

{
 //Remove old config file
 SD.remove("settings.txt");
 //Recreate new config file
 File SettingsFile = SD.open("settings.txt", FILE_WRITE);
 //Save out Variable
   if (SettingsFile)
   {
   SettingsFile.print(GraphMinHum);
   SettingsFile.print(",");
   SettingsFile.print(GraphMaxHum);
   SettingsFile.print(",");
   SettingsFile.print(GraphMinTemp);
   SettingsFile.print(",");
   SettingsFile.print(GraphMaxTemp);
   SettingsFile.close();
     if (OutputSerial) Serial.println("WriteConfig Ran");
   }
   else
   {
   if (OutputSerial) Serial.println("error opening settings.txt");
   }
}

//read configuration settings saved on SD card
void ReadConfig()
{  
  //Display Read Configuration
  if (OutputSerial) Serial.println("Read Config Started"); 
  
//Open Settings File
File SettingsFile = SD.open("settings.txt");
     
     //Run Code if File is found
  if (SettingsFile)
  {
     //Get configuration string from SD Card     
     while (SettingsFile.available())
     {
     //Store each character from read
     int i = SettingsFile.read();
     //Create one string from each character in SD Card
     ConfigurationSettings = ConfigurationSettings + ConvertIntToASCII(i);
     }
   //Close Setting File
   SettingsFile.close();
   //Find Location of Commas
   int d = ConfigurationSettings.indexOf(',');
   int e = ConfigurationSettings.indexOf(',', d+1);
   int f = ConfigurationSettings.indexOf(',', e+1);
   //Copy Configuration Strin to each placeholder     
   String ds = ConfigurationSettings;
   String es = ConfigurationSettings;
   String fs = ConfigurationSettings;
   String gs = ConfigurationSettings;
   //Remove End of string for First variable
   ds.remove(d);     
   //Remove begin and end characters to leave second variable
   es.remove(e);
   es.remove(0,d+1);     
   //Remove begin and end characters to leave third variable
   fs.remove(f);
   fs.remove(0,e+1);
   //Remove begin fourth variable
   gs.remove(0,f+1);
   //Print out Variable to Serial  
   if (OutputSerial) Serial.println("Configuration File Found");
   if (OutputSerial) Serial.print("GraphMinHum:");
   if (OutputSerial) Serial.print(ds);
   if (OutputSerial) Serial.print("  GraphMaxHum:");
   if (OutputSerial) Serial.print(es);
   if (OutputSerial) Serial.print("  GraphMinTemp:");
   if (OutputSerial) Serial.print(fs);
   if (OutputSerial) Serial.print("  GraphMaxTemp:");
   if (OutputSerial) Serial.println(gs);
     
   //Restore graph variables from SD Card
   GraphMinHum = ds.toInt();
   GraphMaxHum = es.toInt();
   GraphMinTemp = fs.toInt();
   GraphMaxTemp = gs.toInt();
   }
   else
   {
   if (OutputSerial) Serial.println("Configuration File Not Found!");
   }
}
