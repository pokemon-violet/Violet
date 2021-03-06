#include "types.h"
#include "rtc.h"
#include "debug.h"
#include "vars.h"

static const int days_per_month[12] =
{
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31,
};

static u8 to_dec(u8 val) {
    return (u8) ((val & 0xF) + 10 * (val >> 4));
}

/**
 * Reads the current time information and stores it into the timestamp space
 **/
void rtc_read(rtc_timestamp *s) {

    gpios.out = 5; //pins are all out except sio, which is in

    gpios.cntrl = 1; //r/w
    gpios.out = 7; //pins are all out

    //init cs = LOW, !sck = HIGH
    gpio_set_data(HIGH, LOW, LOW);

    //switch cs to HIGH
    gpio_set_data(HIGH, LOW, HIGH);

    rtc_send_byte(0x65);

    gpios.out = 5; //pins are all out except sio, which is in

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

u8 rtc_read_byte() {


    int i = 0;
    int value = 0;
    while (i < 8) {

        gpio_set_data(LOW, LOW, LOW); //we do not send anything to chip but have to time the clock
        rtc_chip_wait();
        gpio_set_data(HIGH, LOW, LOW); //time the clock again
        rtc_chip_wait();

        value |= ((gpios.data & 2) << i);
        i++;
    }
    return (u8) (value >> 1);

}

void rtc_send_byte(u8 value) {

    int v = value;

    int i = 8;
    while (i--) {

        u8 bit = (u8) ((v & 0x80) >> 7);
        v <<= 1;

        gpio_set_data(LOW, bit, LOW); //send bit to chip
        rtc_chip_wait();
        gpio_set_data(HIGH, bit, LOW); //wait for response from chip
        rtc_chip_wait();
    }

}

void rtc_chip_wait() {

    int i = 100;
    while (--i) {
        __asm__ __volatile__(
                "nop\n\r"
                );
    }

}

/**
 * Configure gpio_data
 **/
void gpio_set_data(bool sck, bool sio, bool cs) {
    u16 value = (u16) (sck | (sio << 1) | (cs << 2));
    gpios.data = value;

}

static bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int rtc_timestamp_to_days(rtc_timestamp *t) {
    int days = 0;
    for (int i = 0; i < t->year; i++) {
        days += 365;
        if (is_leap_year(i))
            days++;
    }
    for (int i = 0; i < t->month - 1; i++) {
        days += days_per_month[i];
    }
    if (is_leap_year(t->year) && t->month > 2)
        days++;
    return days;
}

void days_to_rtc_timestamp(int days, rtc_timestamp *t) {
    for (t->year = 0; ; ++t->year) {
        int days_in_year = 365 + is_leap_year(t->year) ? 1 : 0;
        if (days < days_in_year) 
            break;
        days -= days_in_year;
    }
    for (t->month = 1; ; ++t->month) {
        if (days < days_per_month[t->month - 1]) // 1-indexed
            break;
        days -= days_per_month[t->month - 1];
    }
    t->day = (u8)(1 + days);
}

u64 rtc_timestamp_to_seconds(rtc_timestamp *t){
    return (u64)(rtc_timestamp_to_days(t) * 24 * 60 * 60 + t->hour * 60 * 60 + t->minute * 60 + t->second);
}

#define SANITY_IS_TWO_DIGIT_DECIMAL(x) (((x & 0xF) <= 9) && (x & 0xF0) <= 0x90)

bool rtc_test(){
    // Checks RTC data for sanity...
    rtc_timestamp t;
    time_read(&t);
    if (!SANITY_IS_TWO_DIGIT_DECIMAL(t.year)) return false;
    if (!SANITY_IS_TWO_DIGIT_DECIMAL(t.month)) return false;
    if (!SANITY_IS_TWO_DIGIT_DECIMAL(t.day)) return false;
    if (!SANITY_IS_TWO_DIGIT_DECIMAL(t.hour)) return false;
    if (!SANITY_IS_TWO_DIGIT_DECIMAL(t.minute)) return false;
    if (!SANITY_IS_TWO_DIGIT_DECIMAL(t.second)) return false;
    if (t.month < 1 || t.month > 12) return false;
    if (t.day < 1 || t.day > 31) return false;
    return true;
}
