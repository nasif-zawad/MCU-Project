// Nasif Zawad
//20200105222

#include <Keypad.h>
const int greenLedPin = 11;
const int redLedPin = 10;
const int passwordLength = 4;
char actualPassword[passwordLength + 1] = ""; 
password
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'},
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() {
pinMode(greenLedPin, OUTPUT);
pinMode(redLedPin, OUTPUT);
Serial.begin(9600);
while (!Serial) {
; 
}

Serial.println("Please set the 4-digit password (e.g., 4321): ");
while (Serial.available() < passwordLength) {
; 
for (int i = 0; i < passwordLength; i++) {
actualPassword[i] = Serial.read();
Serial.print(actualPassword[i]);
}
Serial.println();
}
void loop() {
char enteredPassword[passwordLength + 1] = {0};
int count = 0;
int i;
// Take password from the keypad
Serial.println("Enter the 4-digit password from the keypad: ");
while (count < passwordLength) {
char key = customKeypad.getKey();
if (key != NO_KEY) {
if (isdigit(key)) {
enteredPassword[count++] = key;
Serial.print(key);
}
}
}
Serial.println();
for (i = 0; i < passwordLength; i++) {
if (enteredPassword[i] != actualPassword[i]) {
break;
}
}
// Turn on the LED based on the PW match
if (i == passwordLength) {
// PW matched
digitalWrite(greenLedPin, HIGH);
digitalWrite(redLedPin, LOW);
} else {
// PW didn't match
digitalWrite(greenLedPin, LOW);
digitalWrite(redLedPin, HIGH);
}
delay(2000);
digitalWrite(greenLedPin, LOW);
digitalWrite(redLedPin, LOW);
}