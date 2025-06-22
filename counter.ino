#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int x = 0;
int input = A0; // This will be your button or sensor input pin
int state = 0;  // State to track the current button press state

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the LCD backlight

  // Set the input pin as input
  pinMode(input, INPUT);

  // Print a message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("  Turn counter ");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print("     =turn  ");
}

void loop()
{
  int counter = digitalRead(input); // Read the digital input pin (A0)

  if (state == 0) {
    if (counter == HIGH) {
      state = 1; // If button is pressed, change the state to 1
      x = x + 1; // Increment the counter
      lcd.setCursor(0, 1);
      lcd.print(x); // Display the updated count on the LCD
    }
  }

  // Reset the state if the button is released
  if (counter == LOW) {
    state = 0;
  }
}
