#include <user_config.h>
#include <SmingCore/SmingCore.h>
extern "C" {
#include "driver/hw_timer.h"
}

#define LED_PIN 2 // GPIO2
bool state = true;

int the_time = 0;

void blink()
{
	int time_since =  micros() - the_time;
	digitalWrite(LED_PIN, state);
	state = !state;
        the_time = micros();
        Serial.println(time_since);
        hw_timer_arm(30000-450);
}

void init()
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    hw_timer_set_func(blink);
    hw_timer_init(NMI_SOURCE, 1);
    the_time = micros();
    hw_timer_arm(30000-450);// seems to equate to 30000 in real terms

}
