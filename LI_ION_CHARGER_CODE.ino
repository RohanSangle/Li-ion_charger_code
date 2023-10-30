
/*
TEAM NAME : TECHWIZARDS 
TITLE : 7.4V LI-ION BATTERY TWO STEP BATTERY CHARGER (CC and CV)

*/


#include <LiquidCrystal.h> //Librarey to use 16*2 LCD display 


 //Mention the pin number for LCD connection

LiquidCrystal lcd(12, 11, 5 , 4, 3, 2);


int Charge = 9; //Pin to connect or disconnect the battery to the circuit 

int Mode = 8; //Pin to toggle between CC mode and CV mode 

int Voltage_divider = A0; //To measure battery Voltage

int Shunt_resistor = A1; //To measure charging current

float Charge_Voltage;

float Charge_current;



void setup() {

  lcd.begin(16, 2); //Initialise 16*2 LCD

  

  lcd.print("7.4V Li+ charger"); //Intro Message line 1

  lcd.setCursor(0, 1);

 

  lcd.clear();


  //pinMode (Charge, OUTPUT);

  pinMode (Mode, OUTPUT);


  //digitalWrite(Charge,HIGH); //Begin Chargig Initially by connecting the battery

  digitalWrite(Mode,LOW); //HIGH for CV mode and LOW of CC mode, initally CC mode


  delay(1000);

}


 


void loop() {


//Measure voltage and current initially

  //Charge_Voltage = analogRead(Voltage_divider) * 0.0092;
  
  //Measure Battery Voltage

  int analog_value = analogRead(A0);
  
float   Charge_voltage = (analog_value * 5.0) / 1024.0; 

  Charge_current = analogRead(Shunt_resistor) * 1.78; //Measure charging current


//If the battery voltage is less than 8.2V enter CC mode

  while(Charge_Voltage<8.2) //CC MODE Loop

  {

    digitalWrite(Mode,LOW); //Stay in CC mode


//Measure Voltage and Current

   int analog_value = analogRead(A0);
  
   Charge_voltage = (analog_value * 5.0) / 1024.0;  //Measure Battery Voltage

    Charge_current = analogRead(Shunt_resistor) * 1.78; //Measure charging current


//print detials on LCD

    lcd.print("V="); lcd.print(Charge_Voltage); 

    lcd.setCursor(0, 1);

    lcd.print("In CC mode"); 

    delay(1000);

    lcd.clear();

    

//Check if we have to exit CC mode 

    if(Charge_Voltage>=8.2) // If yes

    {

      digitalWrite(Mode,HIGH); //Change to CV mode

      break;

    }

  }



//If the battery voltage is greater than 8.2V enter CV mode 

  while (Charge_Voltage>=8.2) //CV MODE Loop

  {

    digitalWrite(Mode,HIGH); //Stay in CV mode


//Measure Voltage and Current

   int analog_value = analogRead(A0);
  
   Charge_voltage = (analog_value * 5.0) / 1024.0;  //Measure Battery Voltage

    Charge_current = analogRead(Shunt_resistor) * 1.78; //Measure charging current


//Display details to user in LCD

    lcd.print("V="); lcd.print(Charge_Voltage); 

    lcd.print("  I="); lcd.print(Charge_current);

    lcd.setCursor(0, 1);

    lcd.print("In CV mode"); 

    delay(1000);

    lcd.clear();

    

  }

}
