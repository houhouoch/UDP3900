#ifndef __HOME_PAGE_EDITOR_H__
#define __HOME_PAGE_EDITOR_H__

#include "lvgl.h"

// 外部调用接口
void Home_Page_UI_Full_Sync(void);

// Handlers (绑定到主页的点击事件)
void volSet_handler(lv_event_t * e);
void ampSet_handler(lv_event_t * e);
void ampSet_handler_neg(lv_event_t * e);

#endif
