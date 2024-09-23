/*
 *       Matthis Sanier
 *       De-1-v-1
 *       Affiche une des faces d’une manière aléatoire
 *
 *       carte arduino, afficheur NeoPixel
 *
 *       20/09/2024 De-3-v-1
*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN    6
#define NUMPIXELS  9
#include "pitches.h"
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



#define BUZZER_PIN 4
int melody[] = {
  NOTE_A4, REST, NOTE_B4, REST, NOTE_C5, REST, NOTE_A4, REST,
  NOTE_D5, REST, NOTE_E5, REST, NOTE_D5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E5, NOTE_E5, REST,
  NOTE_D5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_D5, REST,
  NOTE_C5, REST, NOTE_B4, NOTE_A4, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5, REST,
  NOTE_B4, NOTE_A4, NOTE_G4, REST, NOTE_G4, REST, NOTE_D5, REST, NOTE_C5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E5, NOTE_E5, REST,
  NOTE_D5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G5, NOTE_B4, REST,
  NOTE_C5, REST, NOTE_B4, NOTE_A4, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5, REST,
  NOTE_B4, NOTE_A4, NOTE_G4, REST, NOTE_G4, REST, NOTE_D5, REST, NOTE_C5, REST,

  NOTE_C5, REST, NOTE_D5, REST, NOTE_G4, REST, NOTE_D5, REST, NOTE_E5, REST,
  NOTE_G5, NOTE_F5, NOTE_E5, REST,

  NOTE_C5, REST, NOTE_D5, REST, NOTE_G4, REST
};
int durations[] = {
  8, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 2, 2,

  8, 8, 8, 8, 2, 8, 8,
  2, 8,

  8, 8, 8, 8, 2, 8, 8,
  4, 8, 8, 8, 8,

  8, 8, 8, 8, 2, 8, 8,
  2, 8, 4, 8, 8, 8, 8, 8, 1, 4,

  8, 8, 8, 8, 2, 8, 8,
  2, 8,

  8, 8, 8, 8, 2, 8, 8,
  2, 8, 8, 8, 8,

  8, 8, 8, 8, 2, 8, 8,
  4, 8, 3, 8, 8, 8, 8, 8, 1, 4,

  2, 6, 2, 6, 4, 4, 2, 6, 2, 3,
  8, 8, 8, 8,

  2, 6, 2, 6, 2, 1
};

const int buttonPin = 2;
int buttonState = 0;  

long randNumber;
long RandomValuePixel;

int mode = 0;

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
    } 
    else if (randomChiffre == 2) {
      ChiffreFonct2();
    } 
    else if (randomChiffre == 3) {
      ChiffreFonct3();
    } 
    else if (randomChiffre == 4) {
      ChiffreFonct4();
    } 
    else if (randomChiffre == 5) {
      ChiffreFonct5();
    } 
    else if (randomChiffre == 6) {
      ChiffreFonct6();
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
    } 
    else if (randomChiffre == 2) {
      ChiffreFonct2();
    } 
    else if (randomChiffre == 3) {
      ChiffreFonct3();
    } 
    else if (randomChiffre == 4) {
      ChiffreFonct4();
    } 
    else if (randomChiffre == 5) {
      ChiffreFonct5();
    } 
    else if (randomChiffre == 6) {
      ChiffreFonct6();
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
    } 
    else if (randomChiffre == 2) {
      ChiffreFonct2();
    } 
    else if (randomChiffre == 3) {
      ChiffreFonct3();
    } 
    else if (randomChiffre == 4) {
      ChiffreFonct4();
    } 
    else if (randomChiffre == 5) {
      ChiffreFonct5();
    } 
    else if (randomChiffre == 6) {
      ChiffreFonct6();
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
  pixels.setPixelColor(6, pixels.Color(0, 100, 0));
  pixels.setPixelColor(7, pixels.Color(0, 100, 0));
  pixels.setPixelColor(8, pixels.Color(0, 100, 0));
  pixels.show();
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}

void setup() {
  pixels.begin();
  pixels.show();
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
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
