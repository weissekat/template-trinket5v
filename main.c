//#include <avr/io.h>
//#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <util/twi.h>

volatile int workmode;

//ISR(PCINT0_vect) {
//  workmode ^= 1 << 0;
//};

void hush(void) {
}
  
void work(void) {
    PORTB |= _BV(1);
    _delay_ms(1000);
    PORTB &= ~_BV(1);
    _delay_ms(1000);
};

void init(void) {
//  cli();
//  GIMSK |= 1 << PCIE;
//  PCMSK |= 1 << PCINT0;
//  MCUCR &= ~((1<<ISC01) | (1<<ISC00));
//  MCUCR |= (1<<ISC01) | (1<<ISC00);
//  sei();
//  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    workmode = 1;
    DDRB |= _BV(1);
};

int main (void) {
    init();
    while(1) {
        if (workmode == 1) {
            work();
        } else {
            hush();
            sleep_enable();
            sleep_cpu();
        };
    };
};
