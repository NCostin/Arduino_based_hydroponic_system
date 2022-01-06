#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include "Constante_Parametri_Sistem.h"
#include "Elemente_Actionare.h"
#include "Functii.h"
LiquidCrystal_I2C lcd(0X27, 16, 2);

//SoftwareSerial BTserial(0,1);




void setup() {
  // put your setup code here, to run once:
 // BTserial.begin(9600);
  Serial.begin(9600);
  pinMode(pin_lumina,OUTPUT);
  Initializare_LCD();
  Initializare_DHT_si_T_apa();
}

void loop() {
  // put your main code here, to run repeatedly:
  wlevel();
  tempval();
  humidity();
  watertemp();
  Val_pH();
  lumina_ON();
  P_Recirculare_ON();
  P_aerare_ON();

  Serial.print("Nivelul apei:");
  Serial.print(nivel_apa);

   Serial.print("Temperatura: ");
   Serial.print(temp);
   Serial.print("C");

   Serial.print("Umiditate: ");
   Serial.print(humid);
   Serial.print(" %");

   Serial.print("Temp apa: ");
   Serial.print(wtemp);
   Serial.print("C ");

  Serial.print("pH");
  Serial.println(ph);
  
    lcd.setCursor(0, 0);
   lcd.print("Nivel apa:");
   lcd.print(nivel_apa);
    delay(2000);
    lcd.clear();

    lcd.setCursor(0, 0);
   lcd.print("Temp:");
   lcd.print(temp);
   lcd.print("C");
   delay(2000);
   lcd.clear();
   
  lcd.setCursor(0, 0);
   lcd.print("Umiditate:");
   lcd.print(humid);
   lcd.print("%");
   delay(2000);
   lcd.clear();
   
  lcd.setCursor(0, 0);
   lcd.print("Temp apa:");
   lcd.print(wtemp);
   lcd.print(" C ");
   delay(2000);
   lcd.clear();
   
    lcd.setCursor(0, 0);

  lcd.print("pH ");
  lcd.print(ph);
  delay(2000);
  lcd.clear();

//BTserial.print(wtemp);
//BTserial.print(",");
//BTserial.print(humid);
//BTserial.print(";");
//delay(500);

  

if( ph < 6 )
{
  do
  {
 P_Baza_ON();
    delay(5000);
  P_Baza_OFF();
    delay(10000);
    Val_pH();
  }while(ph < 6);
   P_Baza_OFF();
};

if(ph > 7)
{
  do
  {
   P_Acid_ON();
    delay(5000);
   P_Acid_OFF();
    delay(10000);
    Val_pH();
  }while(ph > 7);
    P_Acid_OFF();
    
};

}



void Initializare_LCD()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();

};

void Initializare_DHT_si_T_apa()
{
  dht.begin();
  sensors.begin();
};
