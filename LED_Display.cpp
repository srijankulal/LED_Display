#include "led_display.h"

typedef struct name
{
    char ch;
    boolean states[7];
} Letter;
int led1, led2, led3, led4, led5, led6, led7;
Letter numbers[] = {
    {'0', {1, 1, 0, 1, 1, 1, 1}},
    {'1', {0, 0, 0, 0, 0, 1, 1}},
    {'2', {1, 0, 1, 1, 1, 0, 1}},
    {'3', {1, 0, 1, 0, 1, 1, 1}},
    {'4', {0, 1, 1, 0, 0, 1, 1}},
    {'5', {1, 1, 1, 0, 1, 1, 0}},
    {'6', {1, 1, 1, 1, 1, 1, 0}},
    {'7', {1, 0, 0, 0, 0, 1, 1}},
    {'8', {1, 1, 1, 1, 1, 1, 1}},
    {'9', {1, 1, 1, 0, 1, 1, 1}},
    {'-', {0, 0, 0, 0, 0, 0, 0}},
    {' ', {0, 0, 1, 0, 0, 0, 0}},
},
       alphabets[] = {
           {'A', {1, 1, 1, 1, 0, 1, 1}},
           {'B', {1, 1, 1, 1, 1, 1, 1}},
           {'C', {1, 1, 1, 1, 1, 0, 0}},
           {'D', {1, 1, 0, 1, 1, 1, 1}},
           {'E', {1, 1, 1, 1, 1, 0, 0}},
           {'F', {1, 1, 1, 1, 0, 0, 0}},
           {'G', {1, 1, 0, 1, 1, 1, 0}},
           {'H', {0, 1, 1, 1, 0, 1, 1}},
           {'I', {0, 1, 0, 1, 0, 0, 0}},
           {'J', {1, 0, 0, 1, 1, 1, 1}},
           {'K', {0, 1, 1, 1, 0, 1, 1}},
           {'L', {0, 1, 0, 1, 1, 0, 0}},
           {'M', {1, 0, 1, 1, 0, 1, 0}},
           {'N', {0, 0, 1, 1, 0, 1, 0}},
           {'O', {1, 1, 0, 1, 1, 1, 1}},
           {'P', {1, 1, 1, 1, 0, 0, 1}},
           {'Q', {1, 1, 1, 0, 0, 1, 1}},
           {'R', {1, 1, 1, 1, 0, 1, 1}},
           {'S', {1, 1, 1, 0, 1, 1, 0}},
           {'T', {0, 1, 1, 1, 1, 0, 0}},
           {'U', {0, 1, 1, 1, 1, 1, 1}},
           {'V', {0, 1, 0, 0, 1, 0, 1}},
           {'W', {0, 1, 1, 0, 1, 0, 1}},
           {'X', {0, 0, 0, 1, 0, 1, 0}},
           {'Y', {0, 1, 1, 0, 1, 1, 1}},
           {'Z', {0, 0, 0, 1, 1, 0, 1}},
};
int leds[] = {led1, led2, led3, led4, led5, led6, led7};

LED_Display::LED_Display(int seg1, int seg2, int seg3, int seg4, int seg5, int seg6, int seg7)
{
    led1 = seg1;
    led2 = seg2;
    led3 = seg3;
    led4 = seg4;
    led5 = seg5;
    led6 = seg6;
    led7 = seg7;
}
void LED_Display::begin()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(led7, OUTPUT);
}
void LED_Display::show(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        for (int i = 0; i < 7; i++)
        {
            digitalWrite(leds[i], numbers[ch - '0'].states[i]);
        }
    }
    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        ch = toupper(ch);
        for (int i = 0; i < 7; i++)
        {
            digitalWrite(leds[i], alphabets[ch - 'A'].states[i]);
        }
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            digitalWrite(leds[i], numbers[11].states[i]);
        }
    }
}
