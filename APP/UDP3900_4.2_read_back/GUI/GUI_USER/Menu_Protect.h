#ifndef _MENU_Protect_H_
#define _MENU_Protect_H_
#include "lvgl.h"
#include "Gui_Task.h"
#include "BtnTree.h"
#include "Menu_Protect_Editor.h"
void Menu_Protect_Enter(void);
void Menu_Protect_Exit(void);
void Menu_Protect_GroupCreate(void);
void protect_row_handler(lv_event_t * e);
void Menu_Protect_Nav_Process(lv_event_t * e);


#endif
