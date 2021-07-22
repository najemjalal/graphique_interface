/*************************************************************************  structures  *************************************************************************************************/
typedef enum {
 IDM_MAIN=0,    
 IDM_FIX_MODE, 
 IDM_MOBILE_MODE, 
 IDM_LAST_SETTING, 
 IDM_POSITION=11, 
 IDM_RESET, 
 IDM_YOUR_COORDINATES=21, 
 IDM_APPLY_LAST_SETTING=31, 
 IDM_OLD_POSITION=111, 
 IDM_NEW_POSITION, 
 IDM_APPLY_RESET=121,
 IDM_LAST_SETTING_CONFIRMED=131, 
 IDM_APPLY_OLD_POSITION=1111, 
 IDM_NAME=2111, 
 IDM_X, 
 IDM_Y, 
 IDM_Z,  
 IDM_RESET_CONFIRMED = 1211,
 IDM_OLD_POSITION_CONFIRMED = 11111
}IDM_page;

typedef struct 
{
  IDM_page next_page;
  void function(void);
}t_ITEM_MODE; 

typedef struct { 
   IDM_page page;
   char page_title[20];
   IDM_page parent_page;
   t_ITEM_MODE item[10];
   int ItemsSize;
  
}t_PAGE;

 t_PAGE screenMenu[] = {  
  
  //{ enum page, page_title[], enum parent_page,{    {   item1,func1    },{   item2, func2  }       }, Itemsize         },
  //0  
  {  IDM_MAIN, "PRINCIPAL MENU", IDM_MAIN,    {      {IDM_FIX_MODE},{IDM_MOBILE_MODE}       }, 2                        },   // t-page1    
  //
  {  IDM_FIX_MODE,"FIXE MODE",IDM_MAIN,       {      {IDM_POSITION},{IDM_RESET}             }, 2                        },    // t_page2
  {  IDM_MOBILE_MODE,"MOBLIE MODE",IDM_MAIN,  {      {IDM_YOUR_COORDINATES}                 }, 1                        },
  {  IDM_LAST_SETTING,"LAST SETTING",IDM_MAIN,{      {IDM_APPLY_LAST_SETTING}               }, 1                        },
  //10 
  {  IDM_POSITION,"POSITION PARAMETER", IDM_FIX_MODE,{{IDM_OLD_POSITION},{IDM_NEW_POSITION} }, 2                        },
  {  IDM_RESET,"RESET", IDM_RESET,            {      {IDM_APPLY_RESET}                      }, 1                        },
  {  IDM_YOUR_COORDINATES,"COORDINATES",IDM_MOBILE_MODE, { {IDM_YOUR_COORDINATES}           }, 1                        },
  {  IDM_APPLY_LAST_SETTING,"LAST SETTING",IDM_LAST_SETTING,{ {IDM_LAST_SETTING_CONFIRMED}  }, 1                        },
  //100
  {  IDM_OLD_POSITION,"OLD POSITION",IDM_POSITION,{ {IDM_APPLY_OLD_POSITION}                }, 1                        },
  {  IDM_NEW_POSITION,"NEW POSITION",IDM_POSITION,{{IDM_NAME},{IDM_X}, {IDM_Y}, {IDM_Z}     }, 3                        },
  {  IDM_APPLY_RESET, "RESET",IDM_RESET,          {{IDM_RESET_CONFIRMED}                    }, 1                        },
  {  IDM_LAST_SETTING_CONFIRMED,"LAST SETTING",IDM_LAST_SETTING                                                         },    
  //1000
  {  IDM_APPLY_OLD_POSITION, "OLD_ POISTION",IDM_OLD_POSITION,{{IDM_OLD_POSITION_CONFIRMED} }, 1                        },
  {  IDM_NAME, "NAME", IDM_NEW_POSITION                                                                                 },
  {  IDM_X, "X", IDM_NEW_POSITION                                                                                       },
  {  IDM_Y, "Y", IDM_NEW_POSITION                                                                                       },
  {  IDM_Z, "Z", IDM_NEW_POSITION                                                                                       },
  {  IDM_RESET_CONFIRMED,"RESET", IDM_APPLY_RESET                                                                       }, 
  //10000
  { IDM_OLD_POSITION_CONFIRMED, "OLD_POSITION", IDM_OLD_POSITION                                                        }    
};

typedef enum{
  NBUTTON=0,
  
  BACK,
  DOWN,
  SELECT,
  UP,
  B1_B2,
  B1_B3,
  B1_B4,
  
  B2_B3,
  B2_B4,
  
  B3_B4
}t_keyboard;
t_keyboard keyboard_detect;
