#include <Keypad.h> 
#include <SevSeg.h>

SevSeg sevseg;

#define KEY_ROWS 4 // 按鍵模組的列數
#define KEY_COLS 4 // 按鍵模組的行數
 
// 依照行、列排列的按鍵字元（二維陣列）
char keymap[KEY_ROWS][KEY_COLS] = {
  {'0', '4', '8', 'C'},
  {'1', '5', '9', 'D'},
  {'2', '6', 'A', 'E'},
  {'3', '7', 'B', 'F'}};
  
byte colPins[KEY_COLS] = {9,8,7,6};	   // 按鍵模組，行1~4接腳。
byte rowPins[KEY_ROWS] = {5,4,3,2}; // 按鍵模組，列1~4接腳。 
 
// 初始化Keypad物件
// 語法：Keypad(makeKeymap(按鍵字元的二維陣列), 模組列接腳, 模組行接腳, 模組列數, 模組行數)
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

void setup()
{
  Serial.begin(9600);
  byte numDigits = 2;
  byte digitPins[] = {A0, A5};
  byte segmentPins[] = {A1,13,A4,A2,10,12,11,A3};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}
  
void loop()
{
  
  char key = myKeypad.getKey();
  char i,sum,sux=0;
  if (key != NO_KEY)
  {
    Serial.println(key);
    for(i=48;i<58;i++)
    {
      if(key == i)
      {
        sevseg.setNumber(i-48,2);
      }
    }
    for (i=65;i<71;i++)
    {
      if(key == i)
        sevseg.setNumber(i-55,2);
    }
  }
  sevseg.refreshDisplay();

}
