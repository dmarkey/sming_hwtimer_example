#include <user_config.h>
#include <SmingCore/SmingCore.h>
extern "C" {
#include "driver/hw_timer.h"
}

#define LED_PIN 2 // GPIO2
bool state = true;

int the_time = 0;

void IRAM_ATTR blink()
{
        hw_timer_arm(90000);
	digitalWrite(LED_PIN, state);
	state = !state;
        int new_time = micros();
	int time_since = 90000 - (new_time - the_time);
        the_time = new_time;
        Serial.println(time_since);
}

void init()
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    hw_timer_set_func(blink);
    hw_timer_init(FRC1_SOURCE, 1);
    the_time = micros();
    hw_timer_arm(90000);

}
