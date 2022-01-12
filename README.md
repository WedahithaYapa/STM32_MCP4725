# STM32_MCP4725
I have made a simple library for MCP4725 from STM32 Cube IDE . I have used this code for STM32 F746ZG board. You can Change the I2C pins simply and the code will work for any board. I have only developed for the Fast Write I can upload for others as well if needed.  I will do it if people need it.
 
 # How to Use it -- 
      Use MCP4725_Send(number) command to send your analog value. number is any integer 0 - 4096. The Output Volatage of the DAC will be vcc * (number/4096). Remember this only do       the fuction of Fast Writing. The Onboard EEPROM will be not programmed to do the same operation that was happening just before power out. 
 # If the Main code doesnt work -- 
  All you have to do is change the &hi2c1 address according to your  MX_I2C1_Init function in the Program.
  
  # Steps to Use -- 
   1) From STM32 Cube IDE enable i2c1 and the pins according to your board
   2) Set the RCC to Crystal Oscilator and save to genarate the code
   3) Scroll down on your Main Program and find i2c Configured files and find your pointer to i2c.(eg - &hi2c1 ) 
   4) Copy it
   5) Go to i2c_MCP4725.c file on Srs folder and Paste it on the corresponding lines (Lines 14 and 70). I have used the &hi2c1 pointer to my board.If your board has a different one you can change it.
   6) On your Main Program use MCP4725_Send (10); to send any commands to get the respective Volatage.
   7) REMEBER the voltage value will be VCC * (input_number / 4096). So to get 0 volatage you should write 0 and to get VCC you should Write 4096 on the command.

You are free to ask any questions @ Wedahithas@gmail.com and If you need me to improve this to other functions as well Just tell me.I just devoloped a small libarary for my project and I wanted to make things easy for anyone who is doing something similar. 
Feel free to contact me. :-)
