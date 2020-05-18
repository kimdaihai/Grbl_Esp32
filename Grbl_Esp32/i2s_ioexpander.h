/*
    i2s_ioexpander.h
    Part of Grbl_ESP32

    Header for basic GPIO expander using the ESP32 I2S peripheral

    2020    - Michiyasu Odaki

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef i2s_ioexpander_h
#define i2s_ioexpander_h

#ifdef USE_I2S_IOEXPANDER
#include <stdint.h>

#define I2S_IOEXP_PIN_BASE 128

#define GPIO_NUM_I2S_IOEXP_0  (I2S_IOEXP_PIN_BASE + 0)
#define GPIO_NUM_I2S_IOEXP_1  (I2S_IOEXP_PIN_BASE + 1)
#define GPIO_NUM_I2S_IOEXP_2  (I2S_IOEXP_PIN_BASE + 2)
#define GPIO_NUM_I2S_IOEXP_3  (I2S_IOEXP_PIN_BASE + 3)
#define GPIO_NUM_I2S_IOEXP_4  (I2S_IOEXP_PIN_BASE + 4)
#define GPIO_NUM_I2S_IOEXP_5  (I2S_IOEXP_PIN_BASE + 5)
#define GPIO_NUM_I2S_IOEXP_6  (I2S_IOEXP_PIN_BASE + 6)
#define GPIO_NUM_I2S_IOEXP_7  (I2S_IOEXP_PIN_BASE + 7)
#define GPIO_NUM_I2S_IOEXP_8  (I2S_IOEXP_PIN_BASE + 8)
#define GPIO_NUM_I2S_IOEXP_9  (I2S_IOEXP_PIN_BASE + 9)
#define GPIO_NUM_I2S_IOEXP_10  (I2S_IOEXP_PIN_BASE + 10)
#define GPIO_NUM_I2S_IOEXP_11  (I2S_IOEXP_PIN_BASE + 11)
#define GPIO_NUM_I2S_IOEXP_12  (I2S_IOEXP_PIN_BASE + 12)
#define GPIO_NUM_I2S_IOEXP_13  (I2S_IOEXP_PIN_BASE + 13)
#define GPIO_NUM_I2S_IOEXP_14  (I2S_IOEXP_PIN_BASE + 14)
#define GPIO_NUM_I2S_IOEXP_15  (I2S_IOEXP_PIN_BASE + 15)
#define GPIO_NUM_I2S_IOEXP_16  (I2S_IOEXP_PIN_BASE + 16)
#define GPIO_NUM_I2S_IOEXP_17  (I2S_IOEXP_PIN_BASE + 17)
#define GPIO_NUM_I2S_IOEXP_18  (I2S_IOEXP_PIN_BASE + 18)
#define GPIO_NUM_I2S_IOEXP_19  (I2S_IOEXP_PIN_BASE + 19)
#define GPIO_NUM_I2S_IOEXP_20  (I2S_IOEXP_PIN_BASE + 20)
#define GPIO_NUM_I2S_IOEXP_21  (I2S_IOEXP_PIN_BASE + 21)
#define GPIO_NUM_I2S_IOEXP_22  (I2S_IOEXP_PIN_BASE + 22)
#define GPIO_NUM_I2S_IOEXP_23  (I2S_IOEXP_PIN_BASE + 23)
#define GPIO_NUM_I2S_IOEXP_24  (I2S_IOEXP_PIN_BASE + 24)
#define GPIO_NUM_I2S_IOEXP_25  (I2S_IOEXP_PIN_BASE + 25)
#define GPIO_NUM_I2S_IOEXP_26  (I2S_IOEXP_PIN_BASE + 26)
#define GPIO_NUM_I2S_IOEXP_27  (I2S_IOEXP_PIN_BASE + 27)
#define GPIO_NUM_I2S_IOEXP_28  (I2S_IOEXP_PIN_BASE + 28)
#define GPIO_NUM_I2S_IOEXP_29  (I2S_IOEXP_PIN_BASE + 29)
#define GPIO_NUM_I2S_IOEXP_30  (I2S_IOEXP_PIN_BASE + 30)
#define GPIO_NUM_I2S_IOEXP_31  (I2S_IOEXP_PIN_BASE + 31)

/* 1000000 usec / ((160000000 Hz) / 5 / 2) x 32 bit/pulse x 2(stereo) = 4 usec/pulse */
#define I2S_IOEXP_USEC_PER_PULSE 4

#define IS_I2S_IOEXP_PIN(IO) ((IO) & ~0x7F)
#define I2S_IOEXP_PIN_INDEX(IO) ((IO) & 0x7F)

// Read a pin wrapper
#define I2S_IOEXP_READ(IO)      do{ IS_I2S_IOEXP_PIN(IO) ?\
                                    i2s_ioexpander_state(I2S_IOEXP_PIN_INDEX(IO)) : digitalRead(IO);\
                                }while(0)
// Write to a pin wrapper
#define I2S_IOEXP_WRITE(IO, v)  do{ IS_I2S_IOEXP_PIN(IO) ?\
                                    i2s_ioexpander_write(I2S_IOEXP_PIN_INDEX(IO), v) : digitalWrite(IO, v);\
                                }while(0)
#define I2S_IOEXP_SET_INPUT(IO) do{ if (!IS_I2S_IOEXP_PIN(IO))\
                                    pinMode(IO, INPUT);\
                                }while(0)
// Set pin as input with pullup wrapper
#define I2S_IOEXP_SET_INPUT_PULLUP(IO)\
                                do{ if (!IS_I2S_IOEXP_PIN(IO))\
                                    pinMode(IO, INPUT_PULLUP);\
                                }while(0)
// Set pin as output wrapper
#define I2S_IOEXP_SET_OUTPUT(IO)\
                                do{ if (!IS_I2S_IOEXP_PIN(IO))\
                                    pinMode(IO, OUTPUT);\
                                }while(0)
// Set pin as PWM
#define I2S_IOEXP_SET_PWM(IO)   I2S_IOEXP_SET_OUTPUT(IO)
// Set pin as output and init
#define I2S_IOEXP_OUT_WRITE(IO,V)\
                                do{ I2S_IOEXP_SET_OUTPUT(IO); I2S_IOEXP_WRITE(IO,V); }while(0)
// PWM outputs
#define I2S_IOEXP_PWM_PIN(IO)    ((IO) < 34) /* NOTE Pins >= 34 are input only on ESP32, so they can't be used for output. */

typedef void (*i2s_ioexpander_pulse_phase_func_t)(void);

typedef struct {
    /*
        I2S bitstream (32-bits): Transfers from MSB(bit31) to LSB(bit0) in sequence

        ------------------time line------------------------>
             Right Channel                   LEFT Channel
        ws   ________________________________~~~~...
        bck  _~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~...
        data vutsrqponmlkjihgfedcba9876543210vuts...
             XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                                             ^
                                Latches the X bits when ws is switched to High

        bit0:Expanded GPIO 128, 1: Expanded GPIO 129, ..., v: Expanded GPIO 159
        (data at LEFT Channel will ignored by shift-register IC)
    */
    uint8_t ws_pin;
    uint8_t bck_pin;
    uint8_t data_pin;
    i2s_ioexpander_pulse_phase_func_t pulse_phase_func;
    uint32_t pulse_period; // aka step rate.
} i2s_ioexpander_init_t;

/*
  Initialize I2S and DMA for the stepper bitstreamer
  use I2S0, I2S0 isr, DMA, and FIFO(xQueue).

  return -1 ... already initialized
*/
int i2s_ioexpander_init(i2s_ioexpander_init_t &init_param);

/*
  Get a bit state from the internal pin state var.

  pin: expanded pin No. (0..31)
*/
uint8_t i2s_ioexpander_state(uint8_t pin);

/*
   Set a bit in the internal pin state var. (not written electrically)

   pin: expanded pin No. (0..31)
   val: bit value(0 or not 0)
*/
void i2s_ioexpander_write(uint8_t pin, uint8_t val);

/*
    Set current pin state to the I2S bitstream buffer
    (This call will generate a future I2S_IOEXP_USEC_PER_PULSE μs x N bitstream)

    num: Number of samples to be generated
         The number of samples is limited to (20 / I2S_IOEXP_USEC_PER_PULSE).

    return: number of puhsed samples
            0 .. no space for push
 */
uint32_t i2s_ioexpander_push_sample(uint32_t num);

/*
   Set pulser mode to passtrough

   After this function is called,
   the callback function to generate the pulse data
   will not be called.
 */
int i2s_ioexpander_set_passthrough();

/*
   Set pulser mode to stepping

   After this function is called,
   the callback function to generate stepping pulse data
   will be called.
 */
int i2s_ioexpander_set_stepping();

/*
   Set the pulse callback period in microseconds
   (like the timer period for the ISR)
 */
int i2s_ioexpander_set_pulse_period(uint32_t period);

/*
   Register a callback function to generate pulse data
 */
int i2s_ioexpander_register_pulse_callback(i2s_ioexpander_pulse_phase_func_t func);


/*
   Reset i2s I/O expander
   - Stop ISR/DMA
   - Clear DMA buffer with the current expanded GPIO bits
   - Retart ISR/DMA
 */
int i2s_ioexpander_reset();

#endif

/*
   Reference: "ESP32 Technical Reference Manual" by Espressif Systems
     https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf
 */
#endif