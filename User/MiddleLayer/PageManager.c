#include "PageManager.h"
#include "gui_guider.h"
PageStack_t PageStack;

/******************************ջ�Ļ�������******************************/

static void page_stack_init(PageStack_t* stack)
{
	//ջ��ָ����0
	stack->top = 0;
}

static uint8_t page_stack_push(PageStack_t* stack,Page_t* page)
{
	//Խ���ж�
	if(stack->top >= MAX_DEPTH)
		return -1;
	//��stack��������pageҳ��ջ��ջ����ֵ��Ȼ������ȼ�1,
	stack->page[stack->top++] = page;
	return 0;
}

static uint8_t page_stack_pop(PageStack_t* stack)
{
	//Խ���ж�
	if(stack->top <= 0)
		return -1;
	//��ջ��ָ�������ƶ�һλ��Ȼ����ø�ҳ�����������(deinit())
	stack->page[--stack->top]->deinit();
	return 0;
}

static uint8_t page_stack_is_empty(const PageStack_t* stack)
{
	return stack->top == 0;
}

static Page_t* get_top_page(PageStack_t* stack)
{
		//�п�
	if(stack->top == 0)
	{
		return NULL;
	}
	
	//����ջ��ҳ��ָ��
	return stack->page[stack->top - 1];
}


/******************************��װ����******************************/


/**
 * ��ȡ��ǰҳ�棨ջ��ҳ�棩��ָ�롣
 *
 * @param NULL
 * @return ���ص�ǰҳ���ָ�룬���ջΪ���򷵻�NULL��
 */
Page_t* Page_Get_NowPage(void) {
    return get_top_page(&PageStack);
}

/**
 * back to previous page
 *
 * @param uiָ��
 * @return NULL
 */
void Page_Back(lv_ui *ui)
{
	//�п�
	if(page_stack_is_empty(&PageStack))
	{
		return;
	}
	
	//������ǰҳ��
	page_stack_pop(&PageStack);
	
	if(page_stack_is_empty(&PageStack))
	{
		//���ջ�գ���ջHome��Menu,Ȼ�����Menu����
		page_stack_push(&PageStack,&Page_Home);
		page_stack_push(&PageStack,&Page_Menu);
		Page_Menu.init(ui);
		lv_scr_load_anim(*Page_Menu.page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
	}
	else
	{
		//�л�����һ����
		Page_t *previous_page = PageStack.page[PageStack.top - 1];
		previous_page->init(ui);
		lv_scr_load_anim(*previous_page->page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
			
	}
}

/**
 * back to bottom page home page
 *
 * @param uiָ��
 * @return NULL
 */
void Page_Back_Bottom(lv_ui *ui)
{
	//�п�
	if(page_stack_is_empty(&PageStack))
	{
		return;
	}
	while(PageStack.top > 1)
	{
		page_stack_pop(&PageStack);
		//��ʼ���½���
		PageStack.page[PageStack.top - 1]->init(ui);
		//�����½���
		lv_scr_load_anim(*PageStack.page[PageStack.top - 1]->page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
	}
}

/**
 * Load a new page to stack top
 *
 * @param uiָ��
 * @param newPage Page_t a new page
 * @return NULL
 */
void Page_Load(lv_ui *ui,Page_t *newPage) 
{
	if(PageStack.top >= MAX_DEPTH - 1)
	{
		//����
		return;
	}
	
	if(PageStack.top > 0)
	{
		//��ҳ��ջ�ǿգ�������ǰҳ��
		PageStack.page[PageStack.top - 1]->deinit();
	}
	
	//���½�������ҳ��ջ
	page_stack_push(&PageStack,newPage);
	newPage->init(ui);
	lv_scr_load_anim(*newPage->page_obj,LV_SCR_LOAD_ANIM_FADE_ON,100,0,true);
}

/**
 * initialize the page manager & start home page
 *
 * @param uiָ��
 * @return NULL
 */
void Pages_init(lv_ui *ui) 
{
    page_stack_init(&PageStack);
    page_stack_push(&PageStack, &Page_Home);
    Page_Home.init(ui);
    lv_disp_load_scr(*Page_Home.page_obj);
}
