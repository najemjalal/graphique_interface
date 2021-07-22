#include <stdlib.h>
#include "Wire.h"
#include "DS1340.h"
#include "SDCARD.h"
#include "UTILS.h"
#include "SCREEN.h"
#include "define.h"
#include "FreeMemory.h"

DS1340 ds1340;
SCREEN screen;
/*******************************************************************************
                    Global variables
*******************************************************************************/ 
byte b;
char rtc_time[18] = "???";

/*******************************************************************************
                      Setup
*******************************************************************************/ 
void setup() 
{ 
  
  Wire.begin();
  delay(10); 
  pinMode(IN_KBD01_PIN, INPUT);
  pinMode(IN_KBD02_PIN, INPUT);
  pinMode(IN_KBD03_PIN, INPUT);
  pinMode(IN_KBD04_PIN, INPUT);
  pinMode(OUT_LED01_PIN, OUTPUT);
  pinMode(OUT_LED02_PIN, OUTPUT);
  pinMode(OUT_BUZZER_PIN, OUTPUT);
  digitalWrite(OUT_LED01_PIN, LOW);
  digitalWrite(OUT_LED02_PIN, LOW);
  digitalWrite(OUT_BUZZER_PIN, LOW);
    
  ds1340.initTime();
  ds1340.bRTChour_updated = false;

  Serial1.begin(9600);     // serial port 1, to acquisition system via Tx pin
  delay(1000); 
  Serial.begin(9600);      // serial port to acquisition system
  delay(1000); 
  Serial.setTimeout(1000);
  delay(100); 
  Serial.flush();
  delay(100);
  Serial.println("***** KheoPS+ *****");
  sdcard_cardInit(); // Initialize SD card
  screen.begin();
  delay(1000);
  screen.initscreen_display();
  delay(1000);
  strcpy(rtc_time,ds1340.getTime());
} 
 
/*******************************************************************************
                      Main Loop
*******************************************************************************/  
void loop() 
{                   
  int FreeMemory; 
  //size_t a = sizeof screenMenu.item[0] / sizeof *screenMenu;   // this is to know the length of an array 
  //Serial.println(a);
  screen.keyboard_appear();
  //screen.keyboard_detect(keyboard_detect);
  screen.displayMenu_task();
  FreeMemory = freeMemory();
}
/************************************************************************     END CODE        ****************************************************************************************/
