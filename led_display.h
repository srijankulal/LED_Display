#ifndef led_display_h
#define led_display_h
#include <Arduino.h>
class LED_Display
{
public:
    LED_Display(int seg1, int seg2, int seg3, int seg4, int seg5, int seg6, int seg7);
    void show(char ch);
    void begin();
};

#endif