/*********************************************************************
Trinket text.
*********************************************************************/
#include <Adafruit_GFX_Tiny.h>
#include <Adafruit_PCD8544_Tiny.h>

// ----- Arduino Pins -----
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

// ----- Trinket Pins -----
// pin 0 - Serial clock out (SCLK)
// pin 1 - Serial data out (DIN)
// pin 2 - Data/Command select (D/C)
// pin X - LCD chip select (CS)
// pin X - LCD reset (RST)
Adafruit_PCD8544_Tiny display = Adafruit_PCD8544_Tiny(0, 1, 2, -1, -1);

void setup()   {
  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);

  // miniature bitmap display
  display.clearDisplay();

}


void loop() {
  testdrawchar();
  display.display();
  delay(2000);
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();
  delay(2000);

}

void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    //if ((i > 0) && (i % 14 == 0))
      //display.println();
  }    
  display.display();
}
