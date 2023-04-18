#include <Key.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define FILAS 4
#define COLUMNAS 4



char keys[][4] = {
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};

byte pinFilas[4] = { 9, 8, 7, 6 };
byte pinColumnas[4] = { 5, 4, 3, 2 };

Keypad keypad = Keypad(makeKeymap(keys), pinFilas, pinColumnas, FILAS, COLUMNAS);
char key;
int entrada=0;
void setup()
{
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Hola, bienvenido");
  lcd.setCursor(0,1);
  lcd.print("a mi menu");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("utiliza el");
  lcd.setCursor(0,1);
  lcd.print("teclado para");
 delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("navegar por el");
  lcd.setCursor(0,1);
  lcd.print("menu");
  delay(2500);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Cargando...");
 delay(3500);
 lcd.clear();
 lcd.setCursor(0,0);
lcd.print("Seleccione 0");
lcd.setCursor(0,1);
lcd.print("para iniciar");
}

void loop(){
key=keypad.getKey();

  if(key){
    
    if(key=='0'){
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1. Productos");
  lcd.setCursor(0,1);
  lcd.print("2. pago");
  key=keypad.getKey();
  }
  if(key=='1'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Vuelve a ");
    lcd.setCursor(0,1);
    lcd.print("presionar 1");
    entrada=1;
    //productos
  while(entrada){
    key=keypad.getKey();
    if(key=='1'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gansito");
    lcd.setCursor(0,1);
    lcd.print("Coca de a litro");
  }
  key=keypad.getKey();
    if(key=='2'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bubulubu");
    lcd.setCursor(0,1);
    lcd.print("Doritos");
  }
  key=keypad.getKey();
    if(key=='3'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mamut de a peso");
    lcd.setCursor(0,1);
    lcd.print("Kilo de tortilla");
  }
  key=keypad.getKey();
    if(key=='4'){
      entrada=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Regresando...");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Presione 0 para");
    lcd.setCursor(0,1);
    lcd.print("Regresar al menu");
    key=0;
  }
  }
  }
  //pago de productos
  else if(key=='2'){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Metodo de pago:");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
    lcd.print("1. Efectivo");
  lcd.setCursor(0,1);
    lcd.print("2. tarjeta");
  key=keypad.getKey();
  entrada=2;

  while(entrada){
    key=keypad.getKey();
    if(key=='1'||key=='2'){
      entrada=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Su pago fue ");
      lcd.setCursor(0,1);
      lcd.print("recibido");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Vuelva pronto");
       lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Procesando...");
    delay(1400);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Presione 0 para");
    lcd.setCursor(0,1);
    lcd.print("Regresar al menu");
    key=0;
    
    } 
}
}
   }
    
  }
  

 