#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
int sensor;
float temperatura;
float suma;
const int vent=9;



void setup() {
  lcd.begin(16,2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  pinMode(vent, OUTPUT);
  digitalWrite(vent, LOW);
}

void loop() {
  suma=0;
  for(int i=0; i<5;i++){
    sensor = analogRead(A0);
  temperatura = ((sensor*5000.0)/1023)/10;
  suma=temperatura + suma;
  delay(500);
  }
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(suma/5.0,1);
  lcd.print(" C");
  lcd.setCursor(0,1);

  if(temperatura>20){
  lcd.print("Ventilador 20% ");
  digitalWrite(vent, HIGH);
  //delay(7000);
  //digitalWrite(vent, LOW);
  }
  if(temperatura>60){
  lcd.print("Ventilador 50% ");
  digitalWrite(vent, HIGH);
  delay(4500);
  digitalWrite(vent, LOW);
  }
  if(temperatura>80){
  lcd.print("Ventilador 80% ");
  digitalWrite(vent, HIGH);
  delay(2000);
  digitalWrite(vent, LOW);
  }
  if(temperatura>95){
  lcd.print("Ventilador 100% ");
  digitalWrite(vent, HIGH);
  }


}
