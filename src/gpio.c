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

/** @file gpio.c
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include <string.h>
#include <stddef.h>
#include "hal.h"

/* === Macros definitions ====================================================================== */

#ifndef GPIO_MAX_INSTANCES
/**
 * @brief Cantidad máxima de instancias de GPIO que se pueden crear
 */
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type declarations ========================================================== */

/**
 * @brief Estructura que representa un periférico GPIO
 *
 * @note Esta estructura es privada de este módulo
 */
struct gpio_s {
    uint8_t port; /**< Puerto del microcontrolador */
    uint8_t bit;  /**< Bit del puerto del microcontrolador */
    bool output;  /**< Indica si el periférico está configurado como salida */
#ifndef USE_DYNAMIC_MEM
    bool used; /**< Indica si la instancia está en uso */
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

#ifndef USE_DYNAMIC_MEM
/**
 * @brief Busca una instancia de GPIO libre
 *
 * @return gpio_t Puntero a la instancia libre o NULL si no hay instancias libres
 */
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index].used;
            result->used = true;
            break;
        }
    }
    return result;
}
#endif

/* === Public function implementation ========================================================== */

/**
 * @brief Crea una instancia de un periférico GPIO
 *
 * @param port Puerto del microcontrolador
 * @param bit Bit del puerto del microcontrolador
 * @return gpio_t Instancia del periférico GPIO
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif

    if (self) {
        self->port = port;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

/**
 * @brief Configura un periférico GPIO como entrada o salida
 *
 * @param self Periférico GPIO
 * @param output true para configurar como salida, false para configurar como entrada
 * @return void
 */
void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    hal_gpio_set_direction(self->port, self->bit, output);
}

/**
 * @brief Configura el estado de un periférico GPIO
 *
 * @param self Periférico GPIO
 * @param state true para activar, false para desactivar
 * @return void
 */
void gpioSetState(gpio_t self, bool state) {
    if (self->output) {
        hal_gpio_set_output(self->port, self->bit, state);
    }
}

/**
 * @brief Obtiene el estado de un periférico GPIO
 *
 * @param self Periférico GPIO
 * @return bool true si está activado, false si está desactivado
 */
bool gpioGetState(gpio_t self) {
    return hal_gpio_get_input(self->port, self->bit);
}

/* === End of documentation ==================================================================== */
