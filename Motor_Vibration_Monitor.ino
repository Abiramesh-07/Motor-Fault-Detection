#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define VIBRATION_PIN 2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long previousTime = 0;
unsigned long vibrationCount = 0;

int previousState = HIGH;

void setup()
{
  pinMode(VIBRATION_PIN, INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 5);
  display.println("MOTOR");

  display.setCursor(10, 30);
  display.println("MONITOR");

  display.display();

  delay(1500);

  previousTime = millis();
}

void loop()
{
  int currentState = digitalRead(VIBRATION_PIN);

  // Detect vibration event
  if (currentState == LOW && previousState == HIGH)
  {
    vibrationCount++;
  }

  previousState = currentState;

  // Update display every 1 second
  if (millis() - previousTime >= 1000)
  {
    int vibrationLevel = vibrationCount * 5;

    if (vibrationLevel > 100)
    {
      vibrationLevel = 100;
    }

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("MOTOR VIBRATION");

    display.drawLine(0, 11, 127, 11, SSD1306_WHITE);

    display.setTextSize(2);
    display.setCursor(0, 18);
    display.print("LEVEL: ");
    display.print(vibrationLevel);
    display.println("%");

    display.setTextSize(1);
    display.setCursor(0, 45);

    if (vibrationLevel < 30)
    {
      display.println("STATUS: NORMAL");
    }
    else if (vibrationLevel < 70)
    {
      display.println("STATUS: WARNING");
    }
    else
    {
      display.println("STATUS: FAULT");
    }

    display.display();

    vibrationCount = 0;
    previousTime = millis();
  }
}
