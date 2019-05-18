/***********************************************************************
*
*
*	main for playing sam's game suite
*
*
*
***********************************************************************/


#include<iostream>
#include<unistd.h>
#include"war.h"
#include"system.h"



void printMenu();

char choice;
int run = 1;	//used for looping until program end
int err_code;

using namespace std;

int main()	{

	while(run)	//main while loop
	{

		clearScreen();
		printMenu();
		cin >> choice;

		switch(choice)
		{
			//war
			case '1':	
				clearScreen();
				err_code = playWar();
			break;

			//go fish
			case '2':
				clearScreen();
			break;

			case '3':
				clearScreen();
			break;

			case '0':
				clearScreen();
				run=0;
			break;

			default:
				clearScreen();;
				cout << "------------Invalid Input-------------" << endl;
				usleep(1000000); // 1 second
			break;
			

		} // end switch 

		if(err_code)
		{
			run = 0;
			cout << "Failure. Error code = " << err_code << endl;
		}

	} //end main while loop


	return 0;
}

void printMenu()
{
	cout << "-----------------Main Menu-----------------" << endl;
	cout << endl;
	cout << "Select a game by choosing the number, then pressing enter." << endl << endl;
	cout << "1) War" << endl;
	cout << "2) Go Fish" << endl;
	cout << "3) Poker" << endl;
	cout << endl << "0) Exit Program" << endl;
}