/*SCREEN.cpp - Class file for the OLED Display.*/
// last unpdate 07/16/2021  month/day/year
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#include <U8g2lib.h>

#include "SCREEN.h"

// Constructor of oled screen object
// Controller : SH1106
// Size : 128x64
// Buffer size : 2
// Communication : Hardware I2C
U8G2_SH1106_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0);
/**************************************************************************        begin        *********************************************************************************/
// Screen initialisation
bool SCREEN::begin(void)
{
    u8g2.begin();
    delay(100);
    return true;
}
/**********************************************************************      initscreen_display        ****************************************************************************/
 //Display init screen
void SCREEN::initscreen_display(void)
{
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(24,12,"KheoPS+");
    u8g2.drawStr(12,60,"Archeorient");
  } while ( u8g2.nextPage() );
}
/**********************************************************************        action_button        *********************************************************************************/
//int SCREEN::keyboard_detect(t_keyboard keyboard_detect )
//{ 
  /*B[1] =  digitalRead(IN_KBD01_PIN);   //BACK      (KBD01)
  B[2] =  digitalRead(IN_KBD02_PIN);     // SELECT   (KBD02)
  B[3] =  digitalRead(IN_KBD03_PIN);     //DOWN      (KBD03)
  B[4] =  digitalRead(IN_KBD04_PIN);     //UP        (KBD04)     
  int keyboard;            
  nowPressed();  // to memorise the state of B[] and then treat it, the final value is Btn[]
  /***************** test for multiple detect  *****************/
 /*  if(Btn[1] && Btn[2]) {
    keyboard=  keyboard_detect.B1_B2; 
    Btn[1] = false; 
  }

   if(Btn[1] && Btn[3]) {
    keyboard=  keyboard_detect.B1_B3; 
    Btn[1] = false; 
  }

   if(Btn[1] && Btn[4]) {
    keyboard=  keyboard_detect.B1_B4; 
    Btn[1] = false; 
  }

   if(Btn[2] && Btn[3]) {
    keyboard=  keyboard_detect.B2_B3; 
    Btn[1] = false; 
  }

   if(Btn[2] && Btn[4]) {
    keyboard=  keyboard_detect.B2_B4; 
    Btn[1] = false; 
  }

  if(Btn[3] && Btn[4]) {
   keyboard=  keyboard_detect.B2_B4; 
   Btn[1] = false; 
  }*/
  /***************** test for simple detect   *****************/         
/*  if(Btn[1]){   //BACK
    keyboard=  keyboard_detect.BACK; 
    Btn[1] = false;
  }
   
  if(Btn[2]){   //SELECT
    keyboard=  keyboard_detect.SELECT; 
    Btn[2] = false;
  }
  
  if(Btn[3]){    //DOWN
    keyboard=  keyboard_detect.DOWN; 
    Btn[3] = false; //DOWN
    ItemCurrent ++;
    if (ItemCurrent > screenMenu[i].ItemsSize)ItemCurrent = 1;  
   } 
   
  if(Btn[4]){   
    keyboard=  keyboard_detect.UP; 
    Btn[4] = false; 
     menuItem --;
     if (ItemCurrent == 0)ItemCurrent= screenMenu[i].ItemsSize;  // go back to the end of the menu
  } 
   return keyboard;  */
//} 
/*********************************************************************             nowPressed            *********************************************************************************/
void SCREEN::nowPressed(void)
{ 
  for(int i=1; i<5;i++)
    {
      if(  B[i] != END_B[i]  ) {
        if( B[i] == 0)Btn[i]=true;
        delay(50); 
      }
     END_B[i]= B[i]; 
    }  
} 
/*********************************************************************             keyboard_appear            *********************************************************************************/
void SCREEN::keyboard_appear(void){
  u8g2.firstPage();
  do {
       u8g2.setFont(u8g2_font_ncenB10_tr);
       u8g2.drawStr(2,63,"BACK");
       u8g2.drawStr(30,63,"SELECT");
       u8g2.drawStr(80,63,"DOWN");
       u8g2.drawStr(115,63,"UP");         
  }while ( u8g2.nextPage() );        
}
/******************************************************             displayMenu_funct            *********************************************************************************/
void SCREEN::displayMenu_funct(t_PAGE screenMenu[],  int ItemCurrent , int ItemMini, int ItemMax)
{ 
  int n=0;
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(32,8,screenMenu[0].page_title);
   /*
    for(int i=ItemMini ;i<=ItemMax ; i++)   
    {  
      if (i==ItemCurrent)u8g2.drawStr(2,22+n,">"); 
     // u8g2.drawStr(5,22+n,screenMenu.item[i]); 
      n=12;
    }*/
  }while ( u8g2.nextPage() );       
}

/******************************************************             displayMenu_task            *********************************************************************************/
void displayMenu_task(void)
{  
   displayMenu_funct(screenMenu[], ItemCurrent, ItemMini, ItemMax);
}
