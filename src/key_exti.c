
#include "main.h"

/********************************************************************

�������жϵĲ��裺
1.���ú�GPIO�͸���ʱ�ӣ�
2.������Ӧ���ж����ȼ�����NVIC�Ĵ�����
3.�����жϵ�I/O�������ã�
4.����Ӧ��I/Oת��Ϊ�ⲿ�ж���·��������EXTIZ_Init�����жϵĳ�ʼ����
5.�ڿ⺯�����ҵ���Ӧ���ж���ں�������д��Ӧ���жϳ���

********************************************************************/
#define K_UP 			GPIO_Pin_0   //PA0
#define K_DOWN 			GPIO_Pin_3	 //PE3
#define K_LEFT 			GPIO_Pin_2	 //PE2
#define K_RIGHT		  	GPIO_Pin_4   //PE4
/*�ԹܽŵĶ�ȡֵ���к궨��*/
#define k_up 			GPIO_ReadInputDataBit(GPIOA,K_UP)
#define k_down 			GPIO_ReadInputDataBit(GPIOE,K_DOWN)
#define k_left 			GPIO_ReadInputDataBit(GPIOE,K_LEFT)
#define k_right 		GPIO_ReadInputDataBit(GPIOE,K_RIGHT)

#define LED 									GPIO_Pin_All 			//all pin in the port
#define LED_PORT_RCC							RCC_APB2Periph_GPIOC    //clock of led
#define LED_PORT 								GPIOC 					//port of led
							


void Key_Exti_Init(){
    /*������������*/
		GPIO_InitTypeDef GPIO_Initstructure;//����һ���ṹ�������������ʼ��GPIO,
		NVIC_InitTypeDef NVIC_InitStructure;
		EXTI_InitTypeDef EXTI_InitStructure;
		
		/*��Ҫʹ���ⲿ�ж��ߣ����Կ�������ʱ��*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOE ,ENABLE);//��ʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
		
		/*��ʼ��K_UP����*/
		GPIO_Initstructure.GPIO_Pin = K_UP;
		GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;//��������
		GPIO_Init(GPIOA,&GPIO_Initstructure);
	
		/*��ʼ��LED����*/
		GPIO_Initstructure.GPIO_Pin = GPIO_Pin_All;
		GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(LED_PORT,&GPIO_Initstructure);
		GPIO_Write(LED_PORT,(u16)0xff);  //���е�led��ʼ��ʱȫ���رա�
		
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
		/*�����ж����ȼ�*/
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
			EXTI_ClearITPendingBit(EXTI_Line0);//���жϱ�ʾλ����ֹ���������ж�
			}
		}





