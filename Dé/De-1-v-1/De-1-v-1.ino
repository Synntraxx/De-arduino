/*
 *       Matthis Sanier
 *       De-1-v-1
 *       Affiche une des faces d’une manière aléatoire
 *
 *       carte arduino, afficheur NeoPixel
 *
 *       19/09/2024 De-1-v-1
*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN    6
#define NUMPIXELS  8
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int buttonPin = 2;
int buttonState = 0;  

long randNumber;

int mode = 0;

void RandomValue() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
   randNumber = random(1, 7);
   delay (200);
   return randNumber;
  }
}

void Chiffre1() {
  pixels.clear();
  Serial.println("Face 1");
  pixels.setPixelColor(1, pixels.Color(0, 150, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre2() {
  pixels.clear();
  Serial.println("Face 2");
  pixels.setPixelColor(2, pixels.Color(0, 150, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre3() {
  pixels.clear();
  Serial.println("Face 3");
  pixels.clear();
  pixels.setPixelColor(3, pixels.Color(0, 150, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre4() {
  pixels.clear();
  Serial.println("Face 4");
  pixels.setPixelColor(4, pixels.Color(0, 150, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre5() {
  pixels.clear();
  Serial.println("Face 5");
  pixels.setPixelColor(5, pixels.Color(0, 150, 0));
  delay(300);
  randNumber = 0;
}
void Chiffre6() {
  pixels.clear();
  Serial.println("Face 6");
  pixels.setPixelColor(6, pixels.Color(0, 150, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}

void setup() {
  pixels.begin();
  pixels.show();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  RandomValue();
  if (randNumber == 1) {
   Chiffre1();
  } 
  else if (randNumber == 2){
    Chiffre2();
  }
  else if (randNumber == 3){
    Chiffre3();
  }
  else if (randNumber == 4){
    Chiffre4();
  }
  else if (randNumber == 5){
    Chiffre5();
  }
  else if (randNumber == 6){
    Chiffre6();
  }
}
