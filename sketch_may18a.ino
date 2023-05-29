#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define bouton1 2 // les boutons de selections 
#define bouton2 3
#define bouton3 4
#define bouton4 5
#define ca A0 // potentiomètre pour le pourcentage d'alcol 
#define ma 12 // les moteurs qui sont égale au pompe de la machine 
#define mb 11
#define mc 10
#define md 9 
#define lr 6 // led pour informer les utilisateur de la machine 
#define lv 7 
#define vald 8
LiquidCrystal_I2C lcd(32,16,2);

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT); 
  Serial.begin(9600);
  pinMode(8, INPUT); 
  
  // Ecran LCD
  
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();

}

void loop()
{
  ba = digitalRead(bouton1);
  bb = digitalRead(bouton2);
  bc = digitalRead(bouton3);
  bd = digitalRead(bouton4);
  int p = analogRead(ca); 
  p= map(p,0,1023,0,100); 
  Serial.println(ba);
  Serial.println(bb);
  Serial.println(bc);
  Serial.println(bd);
  Serial.println(p);
 
  
  
  lcd.setCursor(0,0);
  lcd.print("Boisson1: Menthe");
  lcd.setCursor(0,1);
  lcd.print("Boisson2: Peche");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Boisson3: Fraise");
  lcd.setCursor(0,1);
  lcd.print("Boisson4: RICARD");
  delay(2000); 
  lcd.clear();
  
  
  
  if(ba == 1)
  {
    lcd.setCursor(0,0); 
    lcd.print("choix : Menthe");
    lcd.setCursor(0,1); 
    lcd.print("pourcentage: ");
    lcd.print(p);  
  }    
  
  if(bb == 1)
  {
    lcd.setCursor(0,0); 
    lcd.print("choix : Peche");
    lcd.setCursor(0,1); 
    lcd.print("pourcentage: ");
    lcd.print(p); 
  }
  
  if(bc == 1)
  {
    lcd.setCursor(0,0); 
    lcd.print("choix : Fraise");
    lcd.setCursor(0,1); 
    lcd.print("pourcentage: ");
    lcd.print(p); 
  }
  
  if(bd == 1)
  {
    lcd.setCursor(0,0); 
    lcd.print("choix : RICARD");
    lcd.setCursor(0,1); 
    lcd.print("pourcentage: ");
    lcd.print(p); 
  }
  
  int vald = digitalRead(8); 
  
  if(ba == 1 && vald == 1)
  {
     digitalWrite(ma, HIGH);
     delay(T1);
     digitalWrite(ma, LOW);                             

     digitalWrite(pompee, HIGH);
     delay(T2);
     digitalWrite(pompee, LOW);

  }
  
  if(bb == 1 && vald == 1)
  {
    digitalWrite(mb, HIGH);
    delay(T1);
    digitalWrite(mb, LOW);                             

    digitalWrite(pompee, HIGH);
    delay(T2);
    digitalWrite(pompe, LOW);

  }
  
  if(bc == 1 && vald == 1)
  {
    digitalWrite(mc, HIGH);
    delay(T1);
    digitalWrite(mc, LOW);                             

    digitalWrite(pompee, HIGH);
    delay(T2);
    digitalWrite(pompee, LOW);
  }
  
  if(bd == 1 && vald == 1)
  {
    digitalWrite(md, HIGH);
    delay(T1);
    digitalWrite(md, LOW);                             

    digitalWrite(pompee, HIGH);
    delay(T2);
    digitalWrite(pompee, LOW);
 
  }
  
  digitalWrite(lv, HIGH);
  delay(10000); 
  digitalWrite(lv, LOW); 
 
}