#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);

int redLED = 8;
int yellowLED = 9;
int greenLED = 10;
int button = 6;

int count = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(button, INPUT_PULLUP);  //Button pessed = LOW

  digitalWrite(greenLED, HIGH); //start in green

  lcd.setCursor(0,0);
  lcd.print("Pedestrians:");
  lcd.setCursor(0,1);
  lcd.print(count);
}

void loop(){
  if (digitalRead(button) == LOW) {     //Button press
  count++;                              //increase count(cunt +1)

  lcd.setCursor(0,1);
  lcd.print("      ");                  //clear old digits
  lcd.setCursor(0,1);
  lcd.print(count);

  // GREEN -> YELLOW
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(2000);

  // YELLOW -> RED
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  delay(6000);

  // RED -> YELLOW
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(2000);

  // YELLOW -> GREEN
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  }
  
}
