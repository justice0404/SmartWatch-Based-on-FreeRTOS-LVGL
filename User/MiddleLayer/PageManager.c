#include "PageManager.h"
#include "gui_guider.h"
PageStack_t PageStack;

/******************************栈的基本操作******************************/

static void page_stack_init(PageStack_t* stack)
{
	//栈顶指针置0
	stack->top = 0;
}

static uint8_t page_stack_push(PageStack_t* stack,Page_t* page)
{
	//越界判断
	if(stack->top >= MAX_DEPTH)
		return -1;
	//将stack这个对象的page页面栈的栈顶赋值，然后将其深度加1,
	stack->page[stack->top++] = page;
	return 0;
}

static uint8_t page_stack_pop(PageStack_t* stack)
{
	//越界判断
	if(stack->top <= 0)
		return -1;
	//将栈顶指针向下移动一位，然后调用该页面的析构函数(deinit())
	stack->page[--stack->top]->deinit();
	return 0;
}

static uint8_t page_stack_is_empty(const PageStack_t* stack)
{
	return stack->top == 0;
}

static Page_t* get_top_page(PageStack_t* stack)
{
		//判空
	if(stack->top == 0)
	{
		return NULL;
	}
	
	//返回栈顶页面指针
	return stack->page[stack->top - 1];
}


/******************************封装函数******************************/


/**
 * 获取当前页面（栈顶页面）的指针。
 *
 * @param NULL
 * @return 返回当前页面的指针，如果栈为空则返回NULL。
 */
Page_t* Page_Get_NowPage(void) {
    return get_top_page(&PageStack);
}

/**
 * back to previous page
 *
 * @param ui指针
 * @return NULL
 */
void Page_Back(lv_ui *ui)
{
	//判空
	if(page_stack_is_empty(&PageStack))
	{
		return;
	}
	
	//弹出当前页面
	page_stack_pop(&PageStack);
	
	if(page_stack_is_empty(&PageStack))
	{
		//如果栈空，入栈Home和Menu,然后加载Menu界面
		page_stack_push(&PageStack,&Page_Home);
		page_stack_push(&PageStack,&Page_Menu);
		Page_Menu.init(ui);
		lv_scr_load_anim(*Page_Menu.page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
	}
	else
	{
		//切换到上一界面
		Page_t *previous_page = PageStack.page[PageStack.top - 1];
		previous_page->init(ui);
		lv_scr_load_anim(*previous_page->page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
			
	}
}

/**
 * back to bottom page home page
 *
 * @param ui指针
 * @return NULL
 */
void Page_Back_Bottom(lv_ui *ui)
{
	//判空
	if(page_stack_is_empty(&PageStack))
	{
		return;
	}
	while(PageStack.top > 1)
	{
		page_stack_pop(&PageStack);
		//初始化新界面
		PageStack.page[PageStack.top - 1]->init(ui);
		//加载新界面
		lv_scr_load_anim(*PageStack.page[PageStack.top - 1]->page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
	}
}

/**
 * Load a new page to stack top
 *
 * @param ui指针
 * @param newPage Page_t a new page
 * @return NULL
 */
void Page_Load(lv_ui *ui,Page_t *newPage) 
{
	if(PageStack.top >= MAX_DEPTH - 1)
	{
		//判满
		return;
	}
	
	if(PageStack.top > 0)
	{
		//若页面栈非空，析构当前页面
		PageStack.page[PageStack.top - 1]->deinit();
	}
	
	//将新界面推入页面栈
	page_stack_push(&PageStack,newPage);
	newPage->init(ui);
	lv_scr_load_anim(*newPage->page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
}

/**
 * initialize the page manager & start home page
 *
 * @param ui指针
 * @return NULL
 */
void Pages_init(lv_ui *ui) 
{
    page_stack_init(&PageStack);
    page_stack_push(&PageStack, &Page_Home);
    Page_Home.init(ui);
    lv_disp_load_scr(*Page_Home.page_obj);
}
