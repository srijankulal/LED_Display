#include <led_display.h>
/*
    * This example demonstrates how to use the LED_Display class to display characters on a 7-segment LED display.
    * 
    * The LED_Display class provides a simple interface for displaying characters on a 7-segment LED display.
    * 
    * The LED_Display class requires the following connections:
    * 
    *  - LED segment A: connected to pin 0
    *  - LED segment B: connected to pin 1
    *  - LED segment C: connected to pin 2
    *  - LED segment D: connected to pin 3
    *  - LED segment E: connected to pin 4
    *  - LED segment F: connected to pin 5
    *  - LED segment G: connected to pin 6
    *
    * (Note: The pin numbers can be changed as needed and need not be in continuous order)
    * The LED_Display class provides the following methods:
    * 
    *  - begin(): Initializes the LED display
    *  - show(char ch): Displays the character ch on the LED display
    * 
    * In this example, we will cycle through the characters '0' to '9' and 'A' to 'Z' on the LED display.
    
*/


// Define the pins connected to the LED segments
const int led1 = 0, led2 = 1, led3 = 2, led4 = 3, led5 = 4, led6 = 5, led7 = 6;

// Create an instance of the LED_Display class
LED_Display led(led1, led2, led3, led4, led5, led6, led7);

void setup() {
    // Initialize the LED display
    led.begin();
    
    // Optionally, set the initial state of the LEDs
    led.show('0'); // Display the character '0' on the LED display
    led.show('A'); // Display the character 'A' on the LED display
}

void loop() {
    // Example: Cycle through characters 0-9 on the LED display
    for (char ch = '0'; ch <= '9'; ch++) {
        led.show(ch); // Display the character on the LED display
        delay(1000);  // Wait for 1 second
    }
    // Example: Cycle through characters A-Z on the LED display
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        led.show(ch); // Display the character on the LED display
        delay(1000);  // Wait for 1 second
    }
}