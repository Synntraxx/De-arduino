/*
 *       Matthis Sanier
 *       De-1-v-1
 *       Affiche une des faces d’une manière aléatoire
 *
 *       carte arduino, afficheur NeoPixel
 *
 *       20/09/2024 De-3-v-2
*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN    6
#define NUMPIXELS  9
#define NOTE_C4 500
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int buttonPin = 2;
int buttonState = 0;  

long randNumber;
long RandomValuePixel;

int mode = 0;

int buzzerPin = 4;

int melody[] = {
  NOTE_C4,
};

int noteDurations[] = {
  4
};
void RandomValue() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
   randNumber = random(1, 7);
   ScrollEffect();
   ScrollEffect2();
   ScrollEffect3();
   delay (200);
   return randNumber;
  }
}

void ScrollEffect() {
  unsigned long startTime = millis();
  while (millis() - startTime < 500) {
    int randomChiffre = random(1, 7);
    if (randomChiffre == 1) {
      ChiffreFonct1();
      sond();
    } 
    else if (randomChiffre == 2) {
      ChiffreFonct2();
      sond();
    } 
    else if (randomChiffre == 3) {
      ChiffreFonct3();
      sond();
    } 
    else if (randomChiffre == 4) {
      ChiffreFonct4();
      sond();
    } 
    else if (randomChiffre == 5) {
      ChiffreFonct5();
      sond();
    } 
    else if (randomChiffre == 6) {
      ChiffreFonct6();
      sond();
    }
    delay(50);
    pixels.clear();
  }
}
void ScrollEffect2() {
  unsigned long startTime = millis();
  while (millis() - startTime < 1000) {
    int randomChiffre = random(1, 7);
    if (randomChiffre == 1) {
      ChiffreFonct1();
      sond();
    } 
    else if (randomChiffre == 2) {
      ChiffreFonct2();
      sond();
    } 
    else if (randomChiffre == 3) {
      ChiffreFonct3();
      sond();
    } 
    else if (randomChiffre == 4) {
      ChiffreFonct4();
      sond();
    } 
    else if (randomChiffre == 5) {
      ChiffreFonct5();
      sond();
    } 
    else if (randomChiffre == 6) {
      ChiffreFonct6();
      sond();
    }
    delay(150);
    pixels.clear();
  }
}
void ScrollEffect3() {
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    int randomChiffre = random(1, 7);
    if (randomChiffre == 1) {
      ChiffreFonct1();
      sond();
    } 
    else if (randomChiffre == 2) {
      ChiffreFonct2();
      sond();
    } 
    else if (randomChiffre == 3) {
      ChiffreFonct3();
      sond();
    } 
    else if (randomChiffre == 4) {
      ChiffreFonct4();
      sond();
    } 
    else if (randomChiffre == 5) {
      ChiffreFonct5();
      sond();
    } 
    else if (randomChiffre == 6) {
      ChiffreFonct6();
      sond();
    }
    delay(250);
    pixels.clear();
  }
}
void ChiffreFonct1() {
  pixels.clear();
  Serial.println("Face 1");
  pixels.setPixelColor(4, pixels.Color(100, 0, 0));
  pixels.show();
}

void ChiffreFonct2() {
  pixels.clear();
  Serial.println("Face 2");
  pixels.setPixelColor(2, pixels.Color(100, 0, 0));
  pixels.setPixelColor(6, pixels.Color(100, 0, 0));
  pixels.show();
}

void ChiffreFonct3() {
  pixels.clear();
  Serial.println("Face 3");
  pixels.setPixelColor(2, pixels.Color(100, 0, 0));
  pixels.setPixelColor(4, pixels.Color(100, 0, 0));
  pixels.setPixelColor(6, pixels.Color(100, 0, 0));
  pixels.show();
}

void ChiffreFonct4() {
  pixels.clear();
  Serial.println("Face 4");
  pixels.setPixelColor(0, pixels.Color(100, 0, 0));
  pixels.setPixelColor(2, pixels.Color(100, 0, 0));
  pixels.setPixelColor(6, pixels.Color(100, 0, 0));
  pixels.setPixelColor(8, pixels.Color(100, 0, 0));
  pixels.show();
}

void ChiffreFonct5() {
  pixels.clear();
  Serial.println("Face 5");
  pixels.setPixelColor(0, pixels.Color(100, 0, 0));
  pixels.setPixelColor(2, pixels.Color(100, 0, 0));
  pixels.setPixelColor(4, pixels.Color(100, 0, 0));
  pixels.setPixelColor(6, pixels.Color(100, 0, 0));
  pixels.setPixelColor(8, pixels.Color(100, 0, 0));
  pixels.show();
}

void ChiffreFonct6() {
  pixels.clear();
  Serial.println("Face 6");
  pixels.setPixelColor(0, pixels.Color(100, 0, 0));
  pixels.setPixelColor(1, pixels.Color(100, 0, 0));
  pixels.setPixelColor(2, pixels.Color(100, 0, 0));
  pixels.setPixelColor(6, pixels.Color(100, 0, 0));
  pixels.setPixelColor(7, pixels.Color(100, 0, 0));
  pixels.setPixelColor(8, pixels.Color(100, 0, 0));
  pixels.show();
}

void Chiffre1() {
  pixels.clear();
  Serial.println("Face 1");
  pixels.setPixelColor(4, pixels.Color(0, 100, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre2() {
  pixels.clear();
  Serial.println("Face 2");
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre3() {
  pixels.clear();
  Serial.println("Face 3");
  pixels.clear();
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(4, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre4() {
  pixels.clear();
  Serial.println("Face 4");
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre5() {
  pixels.clear();
  Serial.println("Face 5");
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(4, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  delay(300);
  randNumber = 0;
}
void Chiffre6() {
  pixels.clear();
  Serial.println("Face 6");
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.setPixelColor(1, pixels.Color(0, 100, 0));
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.setPixelColor(7, pixels.Color(0, 100, 0));
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  delay(1000);
  annimation6();
  randNumber = 0;
}

void annimation6() {
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(1, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(7, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(7, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(1, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.show();
  delay(100);
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.setPixelColor(1, pixels.Color(0, 100, 0));
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(4, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.setPixelColor(7, pixels.Color(0, 100, 0));
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  delay(500);
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.setPixelColor(1, pixels.Color(0, 100, 0));
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(3, pixels.Color(0, 100, 0));
  pixels.setPixelColor(4, pixels.Color(0, 100, 0));
  pixels.setPixelColor(5, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  delay(500);
  pixels.clear();
  pixels.setPixelColor(1, pixels.Color(0, 100, 0));
  pixels.setPixelColor(3, pixels.Color(0, 100, 0));
  pixels.setPixelColor(5, pixels.Color(0, 100, 0));
  pixels.setPixelColor(7, pixels.Color(0, 100, 0));
  pixels.show();
  delay(500);
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 100, 0));
  pixels.setPixelColor(1, pixels.Color(0, 100, 0));
  pixels.setPixelColor(2, pixels.Color(0, 100, 0));
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.setPixelColor(7, pixels.Color(0, 100, 0));
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  sond();
}

void sond() {
  for (int thisNote = 0; thisNote < 1; thisNote++) {
  int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
  int pauseBetweenNotes = noteDuration * 0.10;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}

void setup() {
  pixels.begin();
  pixels.show();
  Serial.begin(9600);
}

void loop() {
  RandomValue();
  if (randNumber == 1) {
      Chiffre1();
    } 
    else if (randNumber == 2) {
      Chiffre2();
    } 
    else if (randNumber == 3) {
      Chiffre3();
    } 
    else if (randNumber == 4) {
      Chiffre4();
    } 
    else if (randNumber == 5) {
      Chiffre5();
    } 
    else if (randNumber == 6) {
      Chiffre6();
    }
    delay(300);
    pixels.clear();
}
