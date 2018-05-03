// LCD CHARACTERS
// PBA 2018-05-02

#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define LCD_ROWS 4
#define LCD_COLS 20

const byte ProgChar[8][8]=
{
  {B00001,B00111,B01111,B01111,B11111,B11111,B11111,B11111},
  {B10000,B11100,B11110,B11110,B11111,B11111,B11111,B11111},
  {B11111,B11111,B11111,B11111,B01111,B01111,B00111,B00001},
  {B11111,B11111,B11111,B11111,B11110,B11110,B11100,B10000},
  {B00001,B00011,B00011,B00111,B00111,B01111,B01111,B11111},
  {B11111,B11110,B11110,B11100,B11100,B11000,B11000,B10000},
  {B11111,B11111,B11111,B11111,B00000,B00000,B00000,B00000},
  {B00000,B00000,B00000,B00000,B11111,B11111,B11111,B11111}
};

void bigDigitInit(void)
// -- Initialisation des caractères programmables --
{
  int i;
  for(i=0; i<8; i++)
    lcd.createChar(i,ProgChar[i]);
}

const byte BigDigit[10][4][4]=
{
  {{0,6,1,32},{255,32,255,32},{255,32,255,32},{2,7,3,32}},
  {{4,255,32,32},{32,255,32,32},{32,255,32,32},{7,255,7,32}},
  {{0,6,1,32},{32,4,5,32},{4,5,32,32},{255,7,7,32}},
  {{0,6,1,32},{32,7,3,32},{32,6,1,32},{2,7,3,32}},
  {{32,4,255,32},{4,5,255,32},{255,7,255,32},{32,32,255,32}},
  {{255,6,6,32},{6,6,1,32},{32,32,255,32},{2,7,3,32}},
  {{0,6,6,32},{255,6,1,32},{255,32,255,32},{2,7,3,32}},
  {{6,6,255,32},{32,4,5,32},{4,5,32,32},{255,32,32,32}},
  {{0,6,1,32},{2,7,3,32},{0,6,1,32},{2,7,3,32}},
  {{0,6,1,32},{2,7,255,32},{32,32,255,32},{2,7,3,32}}
};

void bigDigitDisplay(byte val,byte Pos)
{
  for(int y=0; y<4; y++)
  {
    lcd.setCursor(Pos,y);
    for(int x=0; x<4; x++)
      lcd.write(BigDigit[val][y][x]);
  }
}

void setup()
{
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear() ;
  bigDigitInit();
}

void loop()
{
  static byte c=0;
  bigDigitDisplay(c,(c<<2)%20);
  if(++c==10) c=0;
  delay(1000);
}
