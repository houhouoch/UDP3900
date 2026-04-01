#include "Menu_Protect.h"

static void protect_common_event_handler(lv_event_t * e);

//**************************************//
/* --- 静态变量 --- */
lv_group_t * protect_nav_group = NULL;
static lv_obj_t * ovp_labels[2], * ocp_labels[2], * opp_labels[2], * uvp_labels[2], * ucp_labels[2], * fold_tag[2];
uint8_t protect_nav_level = 1;

/**
 * @brief 内部辅助：获取 6 个行标题 Label
 */
static uint32_t _get_protect_rows(lv_obj_t ** labels) {
    if(labels) {
        labels[0] = ui.Menu_Protect_label_ovp_state;
        labels[1] = ui.Menu_Protect_label_ocp_state;
        labels[2] = ui.Menu_Protect_label_opp_state;
        labels[3] = ui.Menu_Protect_label_uvp_state;
        labels[4] = ui.Menu_Protect_label_ucp_state;
        labels[5] = ui.Menu_Protect_label_foldback;
    }
    return 6;
}

/**
 * @brief 核心：同步 ON/OFF 文字显隐
 */
static void protect_sw_sync_logic(lv_obj_t * sw, lv_obj_t ** labels)
{
    if(!sw || !labels || !labels[0] || !labels[1]) return;
    
    if (lv_obj_has_state(sw, LV_STATE_CHECKED)) {
        lv_obj_clear_flag(labels[0], LV_OBJ_FLAG_HIDDEN); // 显示 ON
        lv_obj_add_flag(labels[1], LV_OBJ_FLAG_HIDDEN);   // 隐藏 OFF
    } else {
        lv_obj_add_flag(labels[0], LV_OBJ_FLAG_HIDDEN);    // 隐藏 ON
        lv_obj_clear_flag(labels[1], LV_OBJ_FLAG_HIDDEN); // 显示 OFF
    }
}

/* --- 1. 导航组切换 --- */

static void _refresh_to_level1_titles(void) {
    lv_group_remove_all_objs(protect_nav_group);
    lv_obj_t * rows[6];
    _get_protect_rows(rows);
    for(int i = 0; i < 6; i++) {
        lv_group_add_obj(protect_nav_group, rows[i]);
        // 彻底清除二级样式残留
        lv_obj_set_style_border_width(rows[i], 0, 0);
        lv_obj_set_style_shadow_width(rows[i], 0, 0);
    }
    protect_nav_level = 1;
    printf("[Protect] Level 1: Row Selection Mode\n");
}

static void _refresh_to_level2_items(Tree_Def * row_node) {
    if(!row_node || !row_node->child) return;
    lv_group_remove_all_objs(protect_nav_group);
    
    Tree_Def * curr = row_node->child;
    lv_obj_t * first_item = NULL;

    while(curr) {
        if(curr->pdata->obj && *curr->pdata->obj) {
            lv_obj_t * sub_item = *curr->pdata->obj;
            lv_obj_add_flag(sub_item, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_remove_event_cb(sub_item, protect_common_event_handler);
            lv_obj_add_event_cb(sub_item, protect_common_event_handler, LV_EVENT_ALL, NULL);
            lv_group_add_obj(protect_nav_group, sub_item);
            if(first_item == NULL) first_item = sub_item;
        }
        curr = curr->next;
    }
    protect_nav_level = 2;
    if(first_item) lv_group_focus_obj(first_item);
}

/* --- 2. 核心逻辑处理器 --- */

static void protect_common_event_handler(lv_event_t * e)
{
    lv_obj_t * target = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    // --- A. 聚焦高亮逻辑 ---
    if(code == LV_EVENT_FOCUSED) {
        if(protect_nav_level == 1) {
            // 一级：文字变黄，禁止任何阴影和边框
            lv_obj_set_style_text_color(target, lv_color_hex(0xff0034), 0); 
            lv_obj_set_style_border_width(target, 0, 0);
            lv_obj_set_style_shadow_width(target, 0, 0);
        } 
        else {
            // 【二级】：根据控件类型区分样式
            if(lv_obj_check_type(target, &lv_switch_class)) {
                // 开关：保持绿色边框
                lv_obj_set_style_border_width(target, 3, 0);
                lv_obj_set_style_border_color(target, lv_color_hex(0xff0034), 0);
                lv_obj_set_style_border_opa(target, 255, 0);
            } else {
                // 文本标签：取消阴影，改为文字变绿色高亮
                lv_obj_set_style_text_color(target, lv_color_hex(0xff0034), 0); 
                // 确保阴影和边框被清理干净
                lv_obj_set_style_shadow_width(target, 0, 0);
                lv_obj_set_style_border_width(target, 0, 0);
            }
            
        }
        lv_obj_scroll_to_view(target, LV_ANIM_ON);
    }
    else if(code == LV_EVENT_DEFOCUSED &&protect_nav_level == 1) {
        lv_obj_set_style_text_color(target, lv_color_hex(0xffffff), 0);
        lv_obj_set_style_border_width(target, 0, 0);
        lv_obj_set_style_shadow_width(target, 0, 0);
    }else if(code == LV_EVENT_DEFOCUSED) {
            lv_obj_set_style_text_color(target, lv_color_hex(0x67ff00), 0);
        lv_obj_set_style_border_width(target, 0, 0);
        lv_obj_set_style_shadow_width(target, 0, 0);
    }

    // --- B. 触摸标题联动开关 ---
    else if(code == LV_EVENT_CLICKED) 
    {
        // 我们在 Init 时把对应的 Switch 存到了 Label 的 user_data 里
        lv_obj_t * sw = (lv_obj_t *)lv_event_get_user_data(e); 
        if(sw && lv_obj_check_type(sw, &lv_switch_class)) {
            // 切换状态
            if(lv_obj_has_state(sw, LV_STATE_CHECKED)) lv_obj_clear_state(sw, LV_STATE_CHECKED);
            else lv_obj_add_state(sw, LV_STATE_CHECKED);

            // 【关键】：手动触发 Switch 的逻辑更新，不依赖事件冒泡
            // 我们直接找到 Switch 绑定的标签对并刷新
            // 注意：Switch 的标签对存在它自己的回调 user_data 里
            // 这里为了简单，我们直接发送一个值改变事件，但要把标签数据带上
            // 更好的办法是：
            lv_event_send(sw, LV_EVENT_VALUE_CHANGED, NULL); 
        }
    }

    // --- C. Switch 状态改变 (ON/OFF 同步) ---
    else if(code == LV_EVENT_VALUE_CHANGED)
    {
        // 获取绑定的 ON/OFF 标签数组
        lv_obj_t ** labels = (lv_obj_t **)lv_event_get_user_data(e);
        if(labels) {
            protect_sw_sync_logic(target, labels);
        } else {
            // 如果是通过 Label 点击间接触发的，通过地址匹配找到对应的标签组
            // 这是一道保险逻辑
            if(target == ui.Menu_Protect_sw_ovp_state) protect_sw_sync_logic(target, ovp_labels);
            else if(target == ui.Menu_Protect_sw_ocp_state) protect_sw_sync_logic(target, ocp_labels);
            else if(target == ui.Menu_Protect_sw_opp_state) protect_sw_sync_logic(target, opp_labels);
            else if(target == ui.Menu_Protect_sw_uvp_state) protect_sw_sync_logic(target, uvp_labels);
            else if(target == ui.Menu_Protect_sw_ucp_state) protect_sw_sync_logic(target, ucp_labels);
            else if(target == ui.Menu_Protect_sw_foldback) protect_sw_sync_logic(target, fold_tag);
        }
    }
}

/* --- 3. 导航控制 --- */
void Menu_Protect_Nav_Process(lv_event_t * e) {
    if(protect_nav_group == NULL || lv_event_get_code(e) != LV_EVENT_KEY) return;
    lv_key_t key = *(lv_key_t *)lv_event_get_param(e);
    lv_obj_t * focused = lv_group_get_focused(protect_nav_group);

    if(key == LV_KEY_ESC) {
        if(protect_nav_level == 2) {
            _refresh_to_level1_titles(); 
            return; 
        } else {
            Tree_UI_Sel_Exit();
            return;
        }
    }

    switch(key) {
        case LV_KEY_UP:     lv_group_focus_next(protect_nav_group);  break;
        case LV_KEY_DOWN:   lv_group_focus_prev(protect_nav_group);  break;
        case LV_KEY_ENTER: {
        if(protect_nav_level == 1) {
            // 一级进二级
            Tree_Def * target = Tree_UI_GetNode_ByObj(tree_protect, focused);
            if(target) _refresh_to_level2_items(target);
        } else {
            // 【二级进三级关键点】
            // 如果当前选中的是文本框，调用 Tree 框架进入编辑模式
            if(!lv_obj_check_type(focused, &lv_switch_class)) {
                Tree_Def * sub_target = Tree_UI_GetNode_ByObj(tree_protect, focused);
                if(sub_target) {
                    printf("[Nav] Entering Edit Mode (Level 3)\n");
                    Tree_UI_Sel_Enter(sub_target, 0); // 这会触发上面的 CLICKED 分支
                }
            } else {
                // 如果是开关，就直接切换
                if(lv_obj_has_state(focused, LV_STATE_CHECKED)) lv_obj_clear_state(focused, LV_STATE_CHECKED);
                else lv_obj_add_state(focused, LV_STATE_CHECKED);
                lv_event_send(focused, LV_EVENT_VALUE_CHANGED, NULL);
            }
        }
        break;
        }
    }
}

/* --- 4. 初始化 --- */

void Menu_Protect_Events_Init(void)
{
    // 1. 静态标签映射
    ovp_labels[0] = ui.Menu_Protect_ovp_state_ON;    ovp_labels[1] = ui.Menu_Protect_ovp_state_OFF;
    ocp_labels[0] = ui.Menu_Protect_ocp_state_ON;    ocp_labels[1] = ui.Menu_Protect_ocp_state_OFF;
    opp_labels[0] = ui.Menu_Protect_opp_state_ON;    opp_labels[1] = ui.Menu_Protect_opp_state_OFF;
    uvp_labels[0] = ui.Menu_Protect_label_uvp_ON;    uvp_labels[1] = ui.Menu_Protect_label_uvp_OFF;
    ucp_labels[0] = ui.Menu_Protect_label_ucp_ON;    ucp_labels[1] = ui.Menu_Protect_label_ucp_OFF;
    fold_tag[0] = ui.Menu_Protect_label_foldback_ON; fold_tag[1] = ui.Menu_Protect_label_foldback_OFF;

    lv_obj_t * rows[6];
    _get_protect_rows(rows);
    lv_obj_t * sws[] = {
        ui.Menu_Protect_sw_ovp_state, ui.Menu_Protect_sw_ocp_state,
        ui.Menu_Protect_sw_opp_state, ui.Menu_Protect_sw_uvp_state,
        ui.Menu_Protect_sw_ucp_state, ui.Menu_Protect_sw_foldback
    };
    lv_obj_t ** tags[] = { ovp_labels, ocp_labels, opp_labels, uvp_labels, ucp_labels, fold_tag };

    if(protect_nav_group == NULL) protect_nav_group = lv_group_create();
    lv_group_remove_all_objs(protect_nav_group);

    for(int i = 0; i < 6; i++) {
        if(rows[i] == NULL) continue;
        lv_obj_add_flag(rows[i], LV_OBJ_FLAG_CLICKABLE);
        lv_group_add_obj(protect_nav_group, rows[i]);
        // 关键：标题 Label 绑定处理器，user_data 为对应的开关 sw
        lv_obj_add_event_cb(rows[i], protect_common_event_handler, LV_EVENT_ALL, sws[i]);
        // 开关绑定处理器，user_data 为对应的标签对 tags
        lv_obj_add_event_cb(sws[i], protect_common_event_handler, LV_EVENT_VALUE_CHANGED, tags[i]);
        // 初始同步
        protect_sw_sync_logic(sws[i], tags[i]);
    }
    // 在你的 Init 函数中添加这一句
    lv_obj_add_event_cb(ui.Menu_Protect_ddlist_foldback, prot_fold_mode_handler, LV_EVENT_ALL, NULL);
}

void Menu_Protect_Enter(void) {
    lv_obj_clear_flag(ui.Menu_Protect_cont, LV_OBJ_FLAG_HIDDEN);
    _refresh_to_level1_titles(); 
    lv_group_focus_obj(ui.Menu_Protect_label_ovp_state);
}
void Menu_Protect_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Protect_cont, LV_OBJ_FLAG_HIDDEN);
}
void Menu_Protect_GroupCreate(void) {
    setup_scr_Menu_Protect(&ui); 
    lv_obj_set_parent(ui.Menu_Protect_cont, ui.Back_cont_back);
    lv_obj_set_height(ui.Menu_Protect_cont_1, 240); 
    lv_obj_add_flag(ui.Menu_Protect_cont_1, LV_OBJ_FLAG_SCROLLABLE);
    Menu_Protect_Events_Init();
    Menu_Protect_Exit(); 
}





