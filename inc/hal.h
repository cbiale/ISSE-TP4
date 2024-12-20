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

#ifndef HAL_H
#define HAL_H

/** @file hal.h
 ** @brief Definición de las funciones de la HAL (Hardware Abstraction Layer)
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Configura un pin de un puerto como entrada o salida
 *
 * @param port Puerto del microcontrolador
 * @param bit Bit del puerto del microcontrolador
 * @param output true para configurar como salida, false para configurar como entrada
 * @return void
 */
void hal_gpio_set_direction(uint8_t port, uint8_t bit, bool output);

/**
 * @brief Configura el estado de un pin de un puerto
 *
 * @param port Puerto del microcontrolador
 * @param bit Bit del puerto del microcontrolador
 * @param active true para activar, false para desactivar
 * @return void
 */
void hal_gpio_set_output(uint8_t port, uint8_t bit, bool active);

/**
 * @brief Obtiene el estado de un pin de un puerto
 *
 * @param port Puerto del microcontrolador
 * @param bit Bit del puerto del microcontrolador
 * @return bool true si el pin está activo, false si el pin está desactivado
 */
bool hal_gpio_get_input(uint8_t port, uint8_t bit);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* HAL_H */
