/*This Library is Developed by Wedahitha Yapa
 * Last Edited data is 09/01/2022
 *
 * Wedahithas@gmail.com for more info
 *
 *
 * */

//Including the requiredred Libraries
#include "i2c_MCP4725.h"
#include <stdio.h>
#include <stdlib.h>

extern I2C_HandleTypeDef hi2c1; // change your handler here accordingly (I use the i2c port 1 so this is my address





void MCP4725_init(void)
{
	HAL_Delay(50);  // wait for >40ms




}

void MCP4725_Send (int data)
{
	if (data < 0)
	{
		HAL_Delay(50);  // wait for >40ms

		}
	else if (data > 4096)
	{
		HAL_Delay(50);  // wait for >40ms

		}
	else{
		// we need to make it to three element  8 bit array according to datasheet page 24 of the datasheet


		uint8_t data_t[2]; ///data to be sent is made here
		//Making the First byte
		//data_t[0] = MCP4725_DEVCode |  MCP4725_ADR | MCP4725_RW ;


		// making the second Byte



		//data needed for 3rd and 2nd bytes
		char data_m, data_l,data_s;
		data_m = (data&0xf0); //0000 1111 0000
		data_l = ((data&0xf00)>>8); // 1111 0000 0000 >> right shifted 8 times
		data_s =  (data&0xf); //0000 0000 1111 data is

		data_t[0] = data_l | MCP4725_Type | MCP4725_PMode;



		//making the third byte

		data_t[1] = data_s | data_m ;


		// Transmitting the data
		HAL_I2C_Master_Transmit(&hi2c1, MCP4725_HexADR,data_t,2,50); /// the address of the DAC is 0x60


	}


}
