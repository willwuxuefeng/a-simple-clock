/*
Changed by will at 2017.12.20
�����õ�������usart3��Ϊprintf���ض����ʱ��
usart1��printf�ض�����Ч
*/


#include "main.h"
  //ע��printf�ض������Ҫ�����ͷ�ļ�

int fputc(int ch,FILE *p){
     USART_SendData(USART3,(u8)ch);
     while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==Bit_RESET);
     return ch;
    }

///***********************************
// ��������use MicroLIB��֧�ִ�ӡ����ĺ���
//***********************************/
//#pragma import(__use_no_semihosting)
///* ��׼����Ҫ��֧�ֺ��� */
//    struct __FILE
//    {
//    int handle;/* Whatever you require here. If the only file you are using is */
//    /* standard output using printf() for debugging, no file handling */
//    /* is required. */
//    };
//    /* FILE is typedef�� d in stdio.h. */
//    FILE __stdout;
//    /* ����_sys_exit()�Ա���ʹ�ð�����ģʽ */
//    _sys_exit(int x)
//    {
//    x = x;
//    }
    
void Usart3_232_Printf_Init(u32 BaudRate){
    
    GPIO_InitTypeDef GPIO_Initstructure; 
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    
    /*ʹ��ʱ��*/
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);//PB10,PB11��ʱ��ʹ��
    
    /*GPIO��ʼ��*/
    GPIO_Initstructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;//����ģʽ
	GPIO_Init(GPIOB,&GPIO_Initstructure);
    
    GPIO_Initstructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	GPIO_Init(GPIOB,&GPIO_Initstructure);
    
    /*��������*/
    USART_InitStructure.USART_BaudRate = BaudRate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8λ����λ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//1λֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//��У��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//Ӳ��������ʧ�ܣ�������ҪӲ����
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;//����/����ģʽ
    USART_Init(USART3, &USART_InitStructure);
    
    /*���ڽ����жϣ��ж����ȼ�������*/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    
    /*ʹ��usart3*/
    USART_Cmd(USART3, ENABLE);
		
    /*ʹ��usart�����ж�*/
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
		
    /*������ڽ����жϴ�����λ*/
    USART_ClearITPendingBit(USART3,USART_IT_RXNE);
		
    /*���������ɱ�־λ*/
    USART_ClearFlag(USART3,USART_FLAG_TC);
    
}
   

 /*����3�ж���ں���������usart3�����usart3printf�ض���*/
void USART3_IRQHandler(){
     u8 data=0; 
     USART_ClearFlag(USART3,USART_FLAG_TC);
     if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET){//�ж��Ƿ������жϣ���������ǲ��Ǵ����ж�
        USART_ClearITPendingBit(USART3,USART_IT_RXNE);//��������жϱ�־
        data = (u8)USART_ReceiveData(USART3);
        USART_SendData(USART3,data);
        while(USART_GetFlagStatus(USART3,USART_FLAG_TC) != RESET);
			 
        }

}
