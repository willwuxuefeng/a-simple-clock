#include "main.h"

void Key_Init(void){
	/*ע��ṹ�������Ӧ�÷��ں�����ǰ��*/
	GPIO_InitTypeDef GPIO_Initstructure;//����һ���ṹ�������������ʼ��GPIO,
    
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//��ʱ��
	/*��ʼ��K_UP����*/
	GPIO_Initstructure.GPIO_Pin = K_UP;
	//GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;//��������
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	/*��ʼ��GPIOE���������������*/
	GPIO_Initstructure.GPIO_Pin = K_DOWN|K_LEFT|K_RIGHT;
	//GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;//��������
	GPIO_Init(GPIOE,&GPIO_Initstructure);
	
	/*��ʼ���ĸ������ĳ�ʼֵ��ȷ���жϰ��µ������ǰ������²Ų����Ķ���*/
	GPIO_ResetBits(GPIOA,K_UP);//��0
	GPIO_SetBits(GPIOE,K_DOWN|K_LEFT|K_RIGHT);//��1
	
    }

void Key_Detection(){
    Led_Init();
		while(1){	//continuous scan ,so use while loop.
			if(k_up==1)
					Delay_ms(10);
					if(k_up==1)
							GPIO_Write(LED_PORT,0Xfe);
							while(k_up);//�ȴ�����̧��		
			if(k_down==0)
					Delay_ms(10);
					if(k_down==0)
							GPIO_Write(LED_PORT,0Xfd);
							while(!(k_down))//�ȴ�����̧��
			if(k_left==0)
					Delay_ms(10);
					if(k_left==0)
							GPIO_Write(LED_PORT,0Xfb);
							while(!(k_left));//�ȴ�����̧��
			if(k_right==0)
					Delay_ms(10);
					if(k_right==0)
							GPIO_Write(LED_PORT,0Xf7);
							while(!(k_right));//�ȴ�����̧��
				}
   
    }
