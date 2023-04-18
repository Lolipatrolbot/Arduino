#include <Keypad.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);



#define LEDR 13
#define LEDG 12
#define LEDB 11

char keys[][4] = {
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};
byte pinFilas[4] = { 9, 8, 7, 6 };
byte pinColumnas[4] = { 5, 4, 3, 2 };

Keypad teclado = Keypad(makeKeymap(keys), pinFilas, pinColumnas, FILAS, COLUMNAS);
char tecla;
char password[7];
char realPassword[7] = "123456";
byte contador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT); 
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ingrese la");
  lcd.setCursor(0,1);
  lcd.print("contrasena");
}

void loop() {
  tecla = teclado.getKey();
  if (tecla != NO_KEY) {
    password[contador] = tecla;
    contador++;
    Serial.println(tecla);
  }
  if (contador == 6) {
    if (strcmp(password, realPassword) == 0) {
      lcd.clear();
      lcd.setCursor(0,0);
     lcd.print("Contrasena");
     lcd.setCursor(0,1);
     lcd.print("aceptada");
     blink(LEDG, 3, 500);
    } else {
      lcd.clear();
      lcd.setCursor(0,0);
       lcd.print("Contrasena");
       lcd.setCursor(0,1);
       lcd.print("incorrecta");
      blink(LEDR, 1, 3000);
    }
    contador = 0;
  }
}
void blink(int pin, int veces, int tiempo) {
  int i;
  for (i = 0; i < veces; i++) {
    digitalWrite(pin, HIGH);
    delay(tiempo);
    digitalWrite(pin, LOW);
    delay(tiempo);
  }
}
