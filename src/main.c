/************************************************************************************************
Copyright (c) 2024, Claudio Omar Biale <claudio.biale@gmail.com>

*************************************************************************************************/

/** @file main.c
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */

#include "main.h"
#include "gpio.h"

/* === Macros definitions ====================================================================== */

#define LED_ROJO_PORT 1
#define LED_ROJO_BIT  7

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

int main(void) {
    gpio_t red_led = gpioCreate(LED_ROJO_PORT, LED_ROJO_BIT);
    gpioSetOutput(red_led, true);
    gpioSetState(red_led, false);
}

/* === End of documentation ==================================================================== */
