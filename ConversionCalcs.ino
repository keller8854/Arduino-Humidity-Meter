//Calculate Enthalpy
double Calch(double t, double w)
{
  double h = 0.24*t + w/7000*(1061 + 0.44*t);
  return h; 
}

//Calculate Humidity Ratio
double CalcW(double t, double rh, double p)
{
 //Convert p from in hg to psi
 p = p * 0.49;
 double w = (0.621945 * CalcPws(t) * rh * 7000) / ((p - CalcPws(t))*100);
 return w; 
}

//Calculate Dew Point based on temp (deg F), Relative Humidity (%), and pressure (in hg)
double CalcDP(double t, double rh)
{
  double C14 = 100.45;
  double C15 = 33.193;
  double C16 = 2.319;
  double C17 = 0.17074;
  double C18 = 1.2063;
  double DP;
  double pw = Calc_Pw(t, rh);
  double a = log(pw);
    if (t < 32)
    {
    DP = 90.12 + 26.142*a + 0.8927 * pow(a,2);
    }
    else
    {
    DP = C14 + C15 * a + C16*pow(a,2) + C17*pow(a,3) + C18*pow(pw,0.1984);
    }
  return DP;
}

//Calculate wetbulb based on temp (deg F), Relative Humidity (%), and pressure (in hg)
double CalcWB(double t, double rh, double p)
{
  //Convert p from in Hg to psi
  p = p * 0.49;
  //Calculate Humidity Ratio
  //Formula from ASHRAE Fundamentals 2013 Equation #24
  double W = 0.621945 * Calc_Pw(t, rh) / (p - Calc_Pw(t, rh));
  //Establish Wet Bulb Guess
  double WB_F = (CalcDP( t, rh) + t) / 2 + 3;
  double W_Test=1;
  //Define Change in wet bulb temperature for loop
  double Delta_WB_F = 0.5;
  //Loop to find wet bulb based on guess and itteration
    if (t > 32)    
    {
      while (W_Test > W) 
      {
      WB_F = WB_F - Delta_WB_F;
      double Pws = CalcPws(WB_F);
      float Ws = 0.621945 * Pws / (p - Pws);
      W_Test = ((1093 - 0.556 * WB_F) * Ws - 0.24 * (t - WB_F)) / (1093 + 0.444 * t - WB_F);
      }
    }
    else
    {
      while (W_Test > W)
      {
      WB_F = WB_F - Delta_WB_F;
      float Pws = CalcPws(WB_F);
      float Ws = 0.621945 * Pws / (p - Pws);
      W_Test = ((1220 - 0.4 * WB_F) * Ws - 0.24 * (t - WB_F)) / (1220 + 0.444 * t - 0.48 * WB_F);
      }
    }
  return WB_F;
}

double CalcPws(double T)
{
  if (T < 32)
  {
  //Convert to Rankine
  double DB_R = T + 459.67;
  double C1 = -10214.165;
  double C2 = -4.8932428;
  double C3 = -0.0053765794;
  double C4 = 0.00000019202377;
  double C5 = 3.5575832E-10;
  double C6 = -9.0344688E-14;
  double C7 = 4.1635019;
  //Calculate Pws
  double Pws = exp(C1 / DB_R + C2 + C3 * DB_R + C4*pow(DB_R,2) + C5*pow(DB_R,3) + C6*pow(DB_R,4) + C7 * log(DB_R));
  return Pws;
  }
  else
  {
  double DB_R = T + 459.67;
  double C8 = -10440.397;
  double C9 = -11.29465;
  double C10 = -0.027022355;
  double C11 = 0.00001289036;
  double C12 = -0.0000000024780681;
  double C13 = 6.5459673;
  //Calculate Pws
  double Pws = exp(C8 / DB_R + C9 + C10 * DB_R + C11*pow(DB_R,2) + C12*pow(DB_R,3) + C13 * log(DB_R));
  return Pws;
  }          
}

double Calc_Pw(double T, double rh)
{
  double Pw = CalcPws(T) * rh / 100;
  return Pw;
}
