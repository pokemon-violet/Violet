#include "../header/types.h"
#include "../header/romfuncs.h"
#include "rtc.h"

void rtc_read(rtc_timestamp *s);
void rtc_send_byte(u8 byte);
void gpio_set_data(bool sck, bool sio, bool cs);
u8 rtc_read_byte();
void special_get_rtc();
void rtc_chip_wait();
u8 to_dec(u8 value);

void special_get_rtc(){
	
	rtc_timestamp *s = (rtc_timestamp*)vardecrypt(0x8000);
	rtc_read(s);
	
}


/**
* Reads the current time information and stores it into the timestamp space
**/
void rtc_read(rtc_timestamp *s){

	gpios->out = 5; //pins are all out except sio, which is in
	
	gpios->cntrl = 1; //r/w
	gpios->out = 7; //pins are all out
	
	//init cs = LOW, !sck = HIGH
	gpio_set_data(HIGH, LOW, LOW);
	
	//switch cs to HIGH
	gpio_set_data(HIGH, LOW, HIGH);
	

	rtc_send_byte(0x65);
	
	gpios->out = 5; //pins are all out except sio, which is in
	
	//Now we can read bytewise
	s->year = to_dec(rtc_read_byte());
	s->month = to_dec(rtc_read_byte());
	s->day = to_dec(rtc_read_byte());
	s->day_of_week = to_dec(rtc_read_byte());
	s->hour = to_dec(rtc_read_byte());
	s->minute = to_dec(rtc_read_byte());
	s->second = to_dec(rtc_read_byte());
	
	
	//data transfer closed, cs = LOW
	gpio_set_data(LOW, LOW, LOW);
	
}

u8 rtc_read_byte(){
	
	
	int i = 0;
	int value = 0;
	while (i < 8){
		
		gpio_set_data(LOW, LOW, LOW); //we do not send anything to chip but have to time the clock
		rtc_chip_wait();
		gpio_set_data(HIGH, LOW, LOW); //time the clock again
		rtc_chip_wait();
		
		value |= ((gpios->data & 2) << i);
		i++;
	}
	return (u8)(value >> 1);
	
}

void rtc_send_byte(u8 value){
	
	int v = value;
	
	int i = 8;
	while (i--){
		
		u8 bit = (u8)((v & 0x80)>>7);
		v <<= 1;
		
		gpio_set_data(LOW, bit, LOW); //send bit to chip
		rtc_chip_wait();
		gpio_set_data(HIGH, bit, LOW); //wait for response from chip
		rtc_chip_wait();
	}
	
}


void rtc_chip_wait(){
	
	int i = 100;
	while(i--){
		asm volatile(
			"nop\n\r"
		);
	}
	
}

/**
* Configure gpio_data
**/
void gpio_set_data(bool sck, bool sio, bool cs){
	
	
	u16 value = (u16)(sck | (sio << 1) | (cs << 2));
	gpios->data = value;
	
	
	
}

u8 to_dec (u8 val){
	
	return (u8)((val & 0xF) + 10*(val >> 4));
	
}

