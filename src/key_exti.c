
#include "main.h"

/********************************************************************

设置外中断的步骤：
1.设置好GPIO和复用时钟；
2.设置相应的中断优先级，即NVIC寄存器；
3.对外中断的I/O进行设置；
4.经相应的I/O转化为外部中断线路，并调用EXTIZ_Init进行中断的初始化；
5.在库函数中找到对应的中断入口函数，编写相应的中断程序；

********************************************************************/
#define K_UP 			GPIO_Pin_0   //PA0
#define K_DOWN 			GPIO_Pin_3	 //PE3
#define K_LEFT 			GPIO_Pin_2	 //PE2
#define K_RIGHT		  	GPIO_Pin_4   //PE4
/*对管脚的读取值进行宏定义*/
#define k_up 			GPIO_ReadInputDataBit(GPIOA,K_UP)
#define k_down 			GPIO_ReadInputDataBit(GPIOE,K_DOWN)
#define k_left 			GPIO_ReadInputDataBit(GPIOE,K_LEFT)
#define k_right 		GPIO_ReadInputDataBit(GPIOE,K_RIGHT)

#define LED 									GPIO_Pin_All 			//all pin in the port
#define LED_PORT_RCC							RCC_APB2Periph_GPIOC    //clock of led
#define LED_PORT 								GPIOC 					//port of led
							


void Key_Exti_Init(){
    /*函数声明部分*/
		GPIO_InitTypeDef GPIO_Initstructure;//声明一个结构体变量，用来初始化GPIO,
		NVIC_InitTypeDef NVIC_InitStructure;
		EXTI_InitTypeDef EXTI_InitStructure;
		
		/*需要使用外部中断线，所以开启复用时钟*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOE ,ENABLE);//打开时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
		
		/*初始化K_UP按键*/
		GPIO_Initstructure.GPIO_Pin = K_UP;
		GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;//输入下拉
		GPIO_Init(GPIOA,&GPIO_Initstructure);
	
		/*初始化LED按键*/
		GPIO_Initstructure.GPIO_Pin = GPIO_Pin_All;
		GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(LED_PORT,&GPIO_Initstructure);
		GPIO_Write(LED_PORT,(u16)0xff);  //所有的led初始化时全部关闭。
		
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
		/*设置中断优先级*/
		NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);

		GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
		EXTI_InitStructure.EXTI_Line = EXTI_Line0;
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStructure);
		
		
	}

		void EXTI0_IRQHandler(void){
		if(EXTI_GetFlagStatus(EXTI_Line0) == 1){
			Delay_ms(10);
			if(1 == GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)){
				GPIO_Write(LED_PORT,0Xfe);
			}
			//GPIO_ResetBits(GPIOC,GPIO_Pin_0);
			EXTI_ClearITPendingBit(EXTI_Line0);//清中断标示位，防止持续进入中断
			}
		}





