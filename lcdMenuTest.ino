#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>

// Keypad parameter
#define ROWS 4
#define COLS 4
// LCD parameter
#define I2C_ADDR 0x3F
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

//LCD Menu
#define Menu_1 "Water Level     "
#define Menu_2 "Max Water Level "
#define Menu_3 "Min Water Level "
#define Menu_4 "Power Off       "
#define Percentage "%            "
#define Centimeter "cm           "

// global variable
// Keypad stuff
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};
Keypad key(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char keyPressed;
volatile byte flag = 0;

// LCD stuff
LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin, BACKLIGHT_PIN, POSITIVE);
bool inputFlag = false;
bool parameterFlag = false;
String number = "";

//LCD Menu Logic
const int numOfScreens = 4;
int currentScreen = 0;
String screen[numOfScreens] = {Menu_1, Menu_2, Menu_3, Menu_4};
int parameters[numOfScreens];

void setup() {
  lcd.begin(16,2);
  lcd.setBacklight(HIGH);
}

void loop() {
  keypadListening();
  inputFlags();
  resolveInput();
}
