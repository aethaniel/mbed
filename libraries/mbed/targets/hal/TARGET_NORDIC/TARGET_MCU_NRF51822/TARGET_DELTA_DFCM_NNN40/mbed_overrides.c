/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include "cmsis.h"

void mbed_sdk_init()
{
	// Default SWIO setting, pull SWIO(p19) to low for turning antenna switch to BLE radiated path
	NRF_GPIO->PIN_CNF[19] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                        | (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos)
                                        | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                                        | (GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos)
                                        | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);

	NRF_GPIO->OUTCLR 		= 	(GPIO_OUTCLR_PIN19_Clear << GPIO_OUTCLR_PIN19_Pos);
	
	// Config External Crystal to 32MHz
	NRF_CLOCK->XTALFREQ = 0x00;
	NRF_CLOCK->EVENTS_HFCLKSTARTED  = 0;
    NRF_CLOCK->TASKS_HFCLKSTART     = 1;
    while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0) 
    {// Do nothing.
    }
}
