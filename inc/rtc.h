#ifndef _rtc_H
	#define _rtc_H
	#include "stm32f10x.h"

	//ʱ��ṹ��
	typedef struct{
		u8 hour;
		u8 min;
		u8 sec;
		u16 w_year;
		u8 w_month;
		u8 w_day;
		u8 week;
	}
	_calendar;

	extern _calendar calendar;//ע������Ǻ��������������Ƕ���

	u8 RTC_Init(void);
	u8 RTC_Get(void);
	u8 Is_Leap_Year(u16 year);
	u8 RTC_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
	u8 RTC_Alarm_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
	u8 RTC_Get(void);
	u8 RTC_Get_Week(u16 year,u8 month,u8 day);


#endif
