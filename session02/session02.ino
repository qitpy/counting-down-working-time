#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'R'},
  {'4', '5', '6', 'D'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'S'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 11, 12, 13}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int rs = 5, en = 4, d4 = 3, d5 = 2, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool countdownStarted = false;
bool countdownPaused = false;
int hours = 0;
int minutes = 0;
unsigned long startTime = 0;
const unsigned long countDownDuration = 3600000; // 1 hour in milliseconds
const float countDownDurationFloat = 3600000.0; // 1 hour in milliseconds (as float)

void setup() {
  lcd.begin(16, 2);
  lcd.print("Set Time:");
  lcd.setCursor(0, 1);
  lcd.print("00:00");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    handleKey(key);
  }

  if (countdownStarted && !countdownPaused) {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - startTime;
    unsigned long remainingTime = countDownDuration - elapsedTime;

    if (remainingTime <= 0) {
      countdownStarted = false;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time's up!");
    } else {
      int remainingHours = remainingTime / 3600000;
      int remainingMinutes = (remainingTime % 3600000) / 60000;
      int remainingSeconds = (remainingTime % 60000) / 1000;

      float progressPercentage = (elapsedTime / countDownDurationFloat) * 100.0;

      lcd.setCursor(0, 0);
      lcd.print("Progress: " + String(progressPercentage) + "%");

      lcd.setCursor(0, 1);
      lcd.print(formatTime(remainingHours, remainingMinutes, remainingSeconds));
    }
  }
}

void handleKey(char key) {
  switch (key) {
    case 'R':
      resetCountdown();
      break;
    case 'D':
      deleteAll();
      break;
    case 'C':
      pauseCountdown();
      break;
    case 'S':
      startCountdown();
      break;
    default:
      setTime(key);
      break;
  }
}

void resetCountdown() {
  hours = 0;
  minutes = 0;
  countdownStarted = false;
  countdownPaused = false;
  lcd.clear();
  lcd.print("Set Time:");
  lcd.setCursor(0, 1);
  lcd.print("00:00");
}

void deleteAll() {
  resetCountdown();
}

void pauseCountdown() {
  countdownPaused = !countdownPaused;
}

void startCountdown() {
  countdownStarted = true;
  startTime = millis();
}

void setTime(char key) {
  if (key >= '0' && key <= '9') {
    if (hours < 10) {
      hours = hours * 10 + (key - '0');
    } else if (minutes < 10) {
      minutes = minutes * 10 + (key - '0');
    }
  }

  lcd.setCursor(9, 1);
  lcd.print(formatTime(hours, minutes, 0)); // Provide seconds argument (0) as well

  if (hours >= 24) {
    hours = 23;
  }

  if (minutes >= 60) {
    minutes = 59;
  }
}

String formatTime(int hours, int minutes, int seconds) {
  String formattedTime = "";

  if (hours < 10) {
    formattedTime += "0";
  }
  formattedTime += hours;
  formattedTime += ":";

  if (minutes < 10) {
    formattedTime += "0";
  }
  formattedTime += minutes;
  formattedTime += ":";

  if (seconds < 10) {
    formattedTime += "0";
  }
  formattedTime += seconds;

  return formattedTime;
}
