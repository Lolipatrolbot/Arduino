#include <Key.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char key;
int dato;
void setup()
{
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hola amigos");
  lcd.setCursor(2,1);
  lcd.print("BIENVENIDOS");
  lcd.setCursor(2,2);
  lcd.print("CANAL EDITRONIKX");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("seleccione el menu");
  lcd.setCursor(3,2);
  lcd.print("con su teclado");
  delay(3000);
  lcd.clear();
}


void loop()
{
  lcd.setCursor(0,0);
  lcd.print("1.CONTROL LED");
  lcd.setCursor(0,1);
  lcd.print("2.JUEGO DE LUCES");
  lcd.setCursor(0,2);
  lcd.print("3.ACERCA DE...");
  key = keypad.getKey();
  
  if (key)
  {
    if(key == '1')
    { 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("1.prender LED");
      lcd.setCursor(0,1);
      lcd.print("2.apagar LED");
      lcd.setCursor(0,2);
      lcd.print("3.Menu principal");
      dato = 1;
      while(dato)
      {
        key = keypad.getKey();
        if(key == '1')
        {
          digitalWrite(13,HIGH);
          lcd.setCursor(0,3);
          lcd.print("LED ONN");
        }
        if(key == '2')
        {
          digitalWrite(13,LOW);
          lcd.setCursor(0,3);
          lcd.print("LED OFF");
        }
        if(key == '3')
        {
          dato = 0;
          lcd.clear();
          lcd.setCursor(0,3);
          lcd.print("RETORNANDO MENU");
          delay(2000);
          lcd.clear();
          key = 0;
        }
      }

    }
//////////////////////////////////
  if(key == '2')
    {
      lcd.clear();
      dato = 1;
      while(dato)
      {
      lcd.setCursor(3,1);
      lcd.print("JUEGO DE LUCES");
      lcd.setCursor(3,2);
      lcd.print("3.Menu principal");
      key = keypad.getKey();
        if(key == '3')
        {
          dato = 0;
          lcd.clear();
          lcd.setCursor(0,3);
          lcd.print("RETORNANDO MENU");
          delay(2000);
          lcd.clear();
          key = 0;
        }
        for(int i=0;i<3; i++)
        {
          digitalWrite(13,HIGH);
          delay(100);
          digitalWrite(13,LOW);
          delay(100);
          
        }
      }
    }
    //////
    if(key == '3')
    {
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("programa creado por");
       lcd.setCursor(0,1);
       lcd.print("editronikx 2022");
       lcd.setCursor(0,3);
       lcd.print("SUSCRIBETE...");
       delay(4000);
       lcd.clear();
    }
  
  }
}