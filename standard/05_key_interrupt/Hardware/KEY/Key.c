#include "key.h"

volatile uint8_t	led_mode_flag = 0; //定义一个全局变量，用于指示LED的模式，初始值为0

void Key_Init()
{
    //1.时钟配置
    RCC->APB2ENR |= RCC_APB2ENR_IOPFEN; //使能GPIOF时钟
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; //使能复用功能时钟
    
    //2.GPIO工作模式配置
    GPIOF->CRH &= ~(GPIO_CRH_MODE8 | GPIO_CRH_MODE9 | GPIO_CRH_MODE10 |GPIO_CRH_MODE11); //清除模式位
    GPIOF->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_CNF9_1 | GPIO_CRH_CNF10_1 | GPIO_CRH_CNF11_1; //配置为输入模式，浮空输入
    GPIOF->CRH &= ~(GPIO_CRH_CNF8_0 | GPIO_CRH_CNF9_0 | GPIO_CRH_CNF10_0 | GPIO_CRH_CNF11_0); //清除CNF位0

    GPIOF->ODR |= (GPIO_ODR_ODR8 | GPIO_ODR_ODR9); //上拉输入
    GPIOF->ODR &=~(GPIO_ODR_ODR10 | GPIO_ODR_ODR11); //下拉输入

    //3.AFIO配置引脚复用选择
    AFIO->EXTICR[2] |= AFIO_EXTICR3_EXTI8_PF | AFIO_EXTICR3_EXTI9_PF | AFIO_EXTICR3_EXTI10_PF | AFIO_EXTICR3_EXTI11_PF; //选择外部中断源为PF8~PF11

    //4.配置EXTI
    EXTI->RTSR |= EXTI_FTSR_TR8 | EXTI_FTSR_TR9 | EXTI_FTSR_TR10 | EXTI_FTSR_TR11; //配置为上升沿触发
    EXTI->IMR |= EXTI_IMR_MR8 | EXTI_IMR_MR9 | EXTI_IMR_MR10 | EXTI_IMR_MR11; //使能外部中断

    //5.配置NVIC
    NVIC_SetPriorityGrouping(3); //设置优先级分组
    NVIC_SetPriority(EXTI15_10_IRQn, 3 ); //设置EXTI15_10_IRQn中断优先级
    NVIC_SetPriority(EXTI9_5_IRQn, 3 ); //设置EXT9_5_IRQn中断优先级
    NVIC_EnableIRQ(EXTI15_10_IRQn); //使能EXTI15_10_IRQn中断
    NVIC_EnableIRQ(EXTI9_5_IRQn); //使能EXTI9_5_IRQn中断
}

//中断服务函数
void EXTI9_5_IRQHandler(void)
{
    if(EXTI->PR & EXTI_PR_PR8) //判断是否是PF8引脚触发的中断
    {
        EXTI->PR |= EXTI_PR_PR8; //清除中断标志位
        //处理按键1的按下事件
        if(GPIOF->IDR & GPIO_IDR_IDR8 != 0) //再次检测按键状态，消抖处理
        {
            led_mode_flag = 0;
            LED_Toggle(LED1); 
        }
    }
    if(EXTI->PR & EXTI_PR_PR9) //判断是否是PF9引脚触发的中断
    {
        EXTI->PR |= EXTI_PR_PR9; //清除中断标志位
        //处理按键2的按下事件
        if(GPIOF->IDR & GPIO_IDR_IDR9 != 0) //再次检测按键状态，消抖处理
        {
            led_mode_flag = 0;
            LED_Toggle(LED2);
        }

    }
}

void EXTI15_10_IRQHandler(void)
{
    if(EXTI->PR & EXTI_PR_PR10) //判断是否是PF10引脚触发的中断
    {
        EXTI->PR |= EXTI_PR_PR10; //清除中断标志位
        //处理按键3的按下事件
        if(GPIOF->IDR & GPIO_IDR_IDR10 != 0) //再次检测按键状态，消抖处理
        {
            led_mode_flag = 0;
            LED_Toggle(LED3);
        }
    }
    if(EXTI->PR & EXTI_PR_PR11) //判断是否是PF11引脚触发的中断
    {
        EXTI->PR |= EXTI_PR_PR11; //清除中断标志位
        //处理按键4的按下事件
        
           led_mode_flag = !led_mode_flag;
        

    }
}

