//write program to blink led or switch button press
#include <stdio.h>  

int main() {
    int buttonState = 0; // Variable to store the state of the button
    int ledState = 0;    // Variable to store the state of the LED

    while (1) {
        // Simulate reading the button state (0 for not pressed, 1 for pressed)
        printf("Press the button (1 for pressed, 0 for not pressed): ");
        scanf("%d", &buttonState);

        if (buttonState == 1) {
            ledState = !ledState; // Toggle LED state
            if (ledState) {
                printf("LED is ON\n");
            } else {
                printf("LED is OFF\n");
            }
        } else {
            printf("Button not pressed. LED state remains: %s\n", ledState ? "ON" : "OFF");
        }
    }

    return 0;
}