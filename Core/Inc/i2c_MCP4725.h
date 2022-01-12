/*
 * i2c_MCP4725.h
 *
 *I2C communication with the DAC MCP4725
 *the device that I have used for the trying of the code has address bits of 000 (=A0 A1 A2)
 *Wedahithas@gmail.com for more info
 *
 *  Created on: Jan 8, 2022
 *      Author: Wedahitha Yapa
 */

#ifndef INC_I2C_MCP4725_H_
#define INC_I2C_MCP4725_H_

#include "stm32f7xx_hal.h"  //needed for the i2c communication with the HAL drivers

/*
 *DEFINES
 *  */

//see Data sheet of MCP4726 Page 24 to understand this part //


#define MCP4725_DEVCode 0b11000000  //device code for this DAC is 1100 in binary
#define MCP4725_ADR 0b00000000  //A1 A2 A0 pins are selected according to the hardware placements of those pins // Left shifted once to get correct binary code
#define MCP4725_RW 0b00000000 //Read write Bit set to write
#define MCP4725_Type (0b00000000 << 6) //Fast Mode selected to write // left shifted to get correct address
#define MCP4725_PMode (0b00000000 << 4) //Power mode selected to normal // left shifted to get correct address
#define MCP4725_HexADR (0x60 << 1)  // address of the sensor found through arduino left shifted to fix 8 bits and to say write


//Initalizing the device
void MCP4725_init (void);


// Sending data Function
void MCP4725_Send (int data); //data is supposed to be a number between 0 to 4096


#endif /* INC_I2C_MCP4725_H_ */
