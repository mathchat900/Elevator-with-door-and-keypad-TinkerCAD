// C++ code
//

#include <Servo.h>
#include <LiquidCrystal_I2C.h>

  int boutonpoussoire = 10;
  int ledrouge = 11;
  int ledverte = 12;
  int servomoteur = 13; 

  Servo monServo;
  LiquidCrystal_I2C lcd(0x20,16,2); //Allows the use of the lcd variable.

bool boutonpoussoirepoussee = false; //Allows checking the state of the button, whether it is pressed or not, in order to avoid loops.
void setup()
{
  pinMode(boutonpoussoire, INPUT_PULLUP);
  pinMode(ledrouge, OUTPUT);
  pinMode(ledverte, OUTPUT);
  lcd.begin(2, 0);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  
  monServo.attach(servomoteur); //Initialization of the servo motor.
  monServo.write(0); //Base position of the servo motor.
}

void loop()
  
{
  monServo.write(90);
  if(digitalRead(boutonpoussoire) == LOW && !boutonpoussoirepoussee){
   boutonpoussoirepoussee = true;
    lcd.setCursor (2, 0);
    lcd.print("Indicate a ");
    lcd.setCursor (2, 1);
    lcd.print("floor");
    monServo.write(0);
    delay(5000);
    digitalWrite(ledrouge, HIGH);
    delay(5000);
    monServo.write(90);
    lcd.clear();
    lcd.setCursor (2, 0);
    lcd.print("floor 1");
    delay(1000);
    digitalWrite(ledrouge, LOW);
    digitalWrite(ledverte, HIGH);
    delay(10000);
    monServo.write(0);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("floor 2");
    delay(10000);
    lcd.clear();
    lcd.setCursor (2, 0);
    lcd.print("Indicate a ");
    lcd.setCursor (2, 1);
    lcd.print("floor");
    digitalWrite(ledrouge, HIGH);
    digitalWrite(ledverte, LOW);
    monServo.write(90);
    
    
    
  }
	
    if (digitalRead(boutonpoussoire) == HIGH) {
      boutonpoussoirepoussee = false;
  }

}