
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

static const unsigned char PROGMEM smile16_glcd_bmp[] =
{ B00001111, B11110000,
  B00001111, B11110000,
  B00110000, B00001100,
  B00110000, B00001100,
  B11001100, B00110011,
  B11001100, B00110011,
  B11000000, B00000011,
  B11000000, B00000011,
  B11001100, B00110011,
  B11001100, B00110011,
  B11000011, B11000011,
  B11000011, B11000011,
  B00110000, B00001100,
  B00110000, B00001100,
  B00001111, B11110000,
  B00001111, B11110000 };

#define MEMSIZE 1024

#define SCR_H 64
#define SCR_W 128

int faceX = 0;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
}

void loop() {
  doDemo();
}

void doDemo() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Vomit SRAM Memory:");
  display.display();
  delay(2000);
  printMemory(100);
  delay(500);
  display.clearDisplay();
  display.println("Fin ~");
  display.display();
  delay(1000);
  display.clearDisplay();
  delay(500);
  display.println("Show Smiley Face:");
  display.display();
  delay(2000);
  display.clearDisplay();
  delay(500);
  display.drawBitmap(0, 0, smile16_glcd_bmp, 16, 16, 1);
  display.display();
  delay(1000);
  display.clearDisplay();
  delay(500);
  display.setCursor(0,0);
  display.println("Scroll Smiley Face:");
  display.display();
  delay(1000);
  moveSmileyFace(10);
}

void printMemory(int fpms) {
  for (int i = 0; i < MEMSIZE; i += SCR_H) {
    display.clearDisplay();
    delay(fpms);
    display.drawBitmap(0, 0, (uint8_t*)i, SCR_W, SCR_H, 1);
    display.display();
  }
}

void moveSmileyFace(int fpms) {
  for (int i = 0; i < SCR_W; i++) {
    display.clearDisplay();
    delay(fpms);
    display.drawBitmap(i, 8, smile16_glcd_bmp, 16, 16, 1);
    display.display();
  }
}

