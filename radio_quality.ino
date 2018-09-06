/*
  Radio Quality Tool

  Krzysztof Jankowski
  2018.09 P1X
  http://p1x.in
  http://krzysztofjankowski.com

  BUTTONS:
  A - start/end program
  B - press and hold to send signals
  C - n/a
  D - n/a
*/

#include "Keyboard.h"

int LOOP_ID = 0;
const int LOOP_MAX = 1000;
const int PIN_A = 4;
const int PIN_B = 5;
int PIN_A_PREV = HIGH;
bool START = false;
int SUCCESS_COUNTER = 0;
int SUCCESS_MAX = 0;
int SUCCESS_LAST = 0;
unsigned long SUCCESS_ROUNDS = 0;
float RESULT_IN_PERCENT;

void setup() {
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  Keyboard.begin();
}

void loop() {
  
  int PIN_A_STATE = digitalRead(PIN_A);

  if ((PIN_A_STATE != PIN_A_PREV) && (PIN_A_STATE == HIGH)) {
    START = !START;
    if (START) {
      Keyboard.println("---------------------------------------");
      Keyboard.println("  KEEP B PRESSED TO SEND SIGNALS");
      Keyboard.println("---- START ----------------------------");
      Keyboard.println("");
      delay(1000);
    } else {
      SUCCESS_MAX -= SUCCESS_LAST;
      SUCCESS_ROUNDS -= LOOP_MAX;
      RESULT_IN_PERCENT = ((float)SUCCESS_MAX / (float)SUCCESS_ROUNDS) * 100.0;
      Keyboard.println("");
      Keyboard.println("---- END --- LAST RESULT IS OMITTED ---");
      Keyboard.println("");
      Keyboard.print("  REPORT: ");
      Keyboard.print(SUCCESS_MAX);
      Keyboard.print(" / ");
      Keyboard.print(SUCCESS_ROUNDS);
      Keyboard.print(" => ");
      Keyboard.print(RESULT_IN_PERCENT);
      Keyboard.println("% <=");
      Keyboard.println("");
      Keyboard.println("---------------------------------------");
      SUCCESS_MAX = 0;
      SUCCESS_ROUNDS = 0;
    }

  }

  if (START) {
    while (LOOP_ID < LOOP_MAX) {
      if (digitalRead(PIN_B) == HIGH) {
        SUCCESS_COUNTER++;
      }
      LOOP_ID++;
      delay(1);
    }

    Keyboard.print("  RECIEVED: ");
    Keyboard.print(SUCCESS_COUNTER);
    Keyboard.print(" / ");
    Keyboard.println(LOOP_MAX);

    SUCCESS_MAX += SUCCESS_COUNTER;
    SUCCESS_LAST = SUCCESS_COUNTER;
    SUCCESS_ROUNDS += LOOP_MAX;

    SUCCESS_COUNTER = 0;
    LOOP_ID = 0;
    delay(100);
  }

  PIN_A_PREV = PIN_A_STATE;

}
