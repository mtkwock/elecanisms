#include "config.h"
#include "common.h"
#include "ui.h"
#include "timer.h"

#define QTY 2
_LED leds[QTY];
_TIMER timers[QTY];
float periods[QTY];

void init_main(void){
    init_clock();
    init_ui();
    init_timer();
        
    leds[0] = led1; leds[1] = led2; //leds[2] = led3;
    
    timers[0] = timer1; timers[1] = timer2; //timers[2] = timer3;
    
    periods[0] = 0.5; periods[1] = 1.0; //periods[2] = 1.5;
    
    // Must be initialized before loop
    int i;    
    for(i = 0; i != QTY; i++){
        led_on(&leds[i]);
        timer_setPeriod(&timers[i], periods[i]);
        timer_start(&timers[i]);
    }
}

int16_t main(void) {
    init_main();

    while (1) {
        int i;
        for(i = 0; i != QTY; i++){
            if (timer_flag(&timers[i])){
                timer_lower(&timers[i]);
                led_toggle(&leds[i]);
            }
        }
//        if (timer_flag(&timer1)) {
//            timer_lower(&timer1);
//            led_toggle(&led1);
//        }
//        if (timer_flag())
//        led_write(&led2, !sw_read(&sw2));
        led_write(&led3, !sw_read(&sw3));
    }
}

