/******************************************************************************
* FILE DESCRIPTION:
*
*	CREATOR  -  Sam Walters
*	FILE NAME  -  system.cpp
*	PROJECT NAME  -  game_suite
*	DATE CREATED  -  2016-10-05
*
******************************************************************************/


/* system.cpp includes system functions that will be used across multiple files */

#include"system.h"



/******************************************************************************
*FUNCTION DESCRIPTION: uses ANSI escape codes. Firs clear the screen then 
*					   move the cursor to 1,1
*
*  NAME  -	clearScreen()
*  PARAMS  -	screen size, how many lines you would like to skip
*  RETURNS  -	none
*
******************************************************************************/
void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}