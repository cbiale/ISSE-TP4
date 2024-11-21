/************************************************************************************************
MIT License

Copyright (c) 2024 Claudio Omar Biale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/** @file gpio.h
 ** @brief Definición de las funciones y tipos de datos de la capa de abstracción de periféricos
 *GPIO
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/**
 * @brief Tipo de dato que representa un periférico GPIO
 */
typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Crea una instancia de un periférico GPIO
 *
 * @param port Puerto del microcontrolador
 * @param bit Bit del puerto del microcontrolador
 * @return gpio_t Instancia del periférico GPIO
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Configura un periférico GPIO como entrada o salida
 *
 * @param gpio Periférico GPIO
 * @param output true para configurar como salida, false para configurar como entrada
 * @return void
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Configura el estado de un periférico GPIO
 *
 * @param gpio Periférico GPIO
 * @param state true para activar, false para desactivar
 * @return void
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Obtiene el estado de un periférico GPIO
 *
 * @param gpio Periférico GPIO
 * @return bool true si está activado, false si está desactivado
 */
bool gpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
