#include  <LiquidCrystal.h>     //inclui a biblioteca para o display
//definições
#define RS 2     
#define EN 3
#define DB4 4 
#define DB5 5
#define DB6 6
#define DB7 7
#define ledverde 11
#define ledvermelho 12
#define p 10
#define pTemp A0

int contadorfebre = 0 ;
int contador = 0;

LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);    //inicia o display LCD

void setup(){
  //pinagens
  pinMode(ledverde,OUTPUT);
  pinMode(ledvermelho,OUTPUT);
  pinMode(p,INPUT);
  pinMode(pTemp,INPUT);
  //configurações do display
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("DESLIGADO ");
}

void loop() {
   	int sensor;
  	sensor= digitalRead(p);
  	
    if (sensor==HIGH){
      float sinalTemp=analogRead(pTemp)*5;
	    float TempC=((sinalTemp/1023)-0.5)*100;
      
      if (TempC>= 37.5){
         contador++;
         contadorfebre++;
         limpa_tela ();
         lcd.setCursor(0,0);
         lcd.print("Febre ");
         lcd.print (TempC);
         lcd.setCursor(0,1);
         lcd.print("Nao pode entrar");
         digitalWrite(ledvermelho,HIGH);
         delay(1000);
         digitalWrite(ledvermelho,LOW);
         limpa_tela ();  
      }else {
         contador++;
         limpa_tela ();
         lcd.setCursor(0,0);
         lcd.print("Sem febre ");
         lcd.print (TempC);
         lcd.setCursor(0,1);
         lcd.print("Pode entrar");
         digitalWrite(ledverde,HIGH);
         delay(1000);
         digitalWrite(ledverde,LOW);
         limpa_tela ();
      }
    }else{// sensor desligado
    lcd.setCursor(0, 0);
    lcd.print("Visitantes: ");
    lcd.print(contador);
    lcd.setCursor(0, 1);
 	lcd.print("Com febre: ");
    lcd.print(contadorfebre);
    }
  delay(500);
}
void  limpa_tela () { //função que limpa a tela do display
 delay ( 1500 );
lcd. setCursor ( 0 , 0 );
lcd. print ( "                 " );
lcd. setCursor ( 0 , 1 );
lcd. print ( "                 " );
}
 