/*
Changed by will at 2017.12.20
并设置当定义了usart3作为printf的重定向的时候
usart1的printf重定向无效
*/


#include "main.h"
  //注意printf重定义必须要加这个头文件

int fputc(int ch,FILE *p){
     USART_SendData(USART3,(u8)ch);
     while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==Bit_RESET);
     return ch;
    }

///***********************************
// 不用设置use MicroLIB就支持打印输出的函数
//***********************************/
//#pragma import(__use_no_semihosting)
///* 标准库需要的支持函数 */
//    struct __FILE
//    {
//    int handle;/* Whatever you require here. If the only file you are using is */
//    /* standard output using printf() for debugging, no file handling */
//    /* is required. */
//    };
//    /* FILE is typedef’ d in stdio.h. */
//    FILE __stdout;
//    /* 定义_sys_exit()以避免使用半主机模式 */
//    _sys_exit(int x)
//    {
//    x = x;
//    }
    
void Usart3_232_Printf_Init(u32 BaudRate){
    
    GPIO_InitTypeDef GPIO_Initstructure; 
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    
    /*使能时钟*/
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);//PB10,PB11的时钟使能
    
    /*GPIO初始化*/
    GPIO_Initstructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用模式
	GPIO_Init(GPIOB,&GPIO_Initstructure);
    
    GPIO_Initstructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOB,&GPIO_Initstructure);
    
    /*串口配置*/
    USART_InitStructure.USART_BaudRate = BaudRate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8位数据位
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//1位停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;//无校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//硬件流控制失能，即不需要硬件流
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;//接收/发送模式
    USART_Init(USART3, &USART_InitStructure);
    
    /*串口接收中断，中断优先级的配置*/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    
    /*使能usart3*/
    USART_Cmd(USART3, ENABLE);
		
    /*使能usart接收中断*/
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
		
    /*清除串口接收中断待处理位*/
    USART_ClearITPendingBit(USART3,USART_IT_RXNE);
		
    /*清除发送完成标志位*/
    USART_ClearFlag(USART3,USART_FLAG_TC);
    
}
   

 /*串口3中断入口函数用来做usart3试验和usart3printf重定向*/
void USART3_IRQHandler(){
     u8 data=0; 
     USART_ClearFlag(USART3,USART_FLAG_TC);
     if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET){//判断是否进入错中断，即进入的是不是串口中断
        USART_ClearITPendingBit(USART3,USART_IT_RXNE);//清除串口中断标志
        data = (u8)USART_ReceiveData(USART3);
        USART_SendData(USART3,data);
        while(USART_GetFlagStatus(USART3,USART_FLAG_TC) != RESET);
			 
        }

}
