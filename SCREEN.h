#ifndef SCREEN_h
#define SCREEN_h
#include "structures.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
  int ItemCurrent = 1;
  int ItemMini=1;
  int ItemMax= 3;
/**************************************************************************************** class SCREEN  *********************************************************/
class SCREEN
{
    public:
        
        bool begin(void);
        void initscreen_display(void);
        void nowPressed(void);
        
        int keyboard_detect(t_keyboard keyboard_detect);
        void keyboard_appear(void);  
        
        void displayMenu_funct(t_PAGE screenMenu[], int ItemCurrent , int ItemMini, int ItemMax );
        void displayMenu_task(void);
   
    private:
        int B[4];   //to read buttons  status   
        boolean END_B[4]= {false,false,false,false};  //end buttons  stats
        boolean Btn[4]= {false, false, false,false};  // BACK SELECT DOWN UP    use this array to control buttons 

        int MenuCurrent;
};
#endif
