/******************************************************************************
* FILE DESCRIPTION: this file contains the functions necessary for playing
*					the card game "war"
*
*	CREATOR  -  Sam Walters
*	FILE NAME  -  war.cpp
*	PROJECT NAME  -  game_suite
*	DATE CREATED  -  2016-10-05
*
******************************************************************************/


#include<iostream>
#include<string>

#include"war.h"
#include"player.h"
#include"system.h"


int battles;
int ties;
int playerW;
int computerW;

using namespace std;


int playWar()
{
	clearStats();
	char status_word;
	int status = 1;
	string player_name = "Player";
	string computer_name = "Computer";

	clearScreen();
	Player Player1(player_name);
	Player Player2(computer_name);

	/*Open a deck of cards */
	Deck mydeck;
	//mydeck.printDeck();		
	mydeck.shuffle();
	//mydeck.printDeck();

	//deal until deck is empty
	while(mydeck.emptyDeck())	
	{
		Player1.draw(1,&mydeck);
		Player2.draw(1,&mydeck);
	}

	//main game
	while(Player1.handSize() != 0 && Player2.handSize() != 0 && status)
	{
   //     struct card* cardP1 = new struct card; 
    //    struct card* cardP2 = new struct card;

     //  Player1.playCard(cardP1);
      // Player2.playCard(cardP2);

		struct card* cardP1 = Player1.playCard();
		struct card* cardP2 = Player2.playCard();
		
		drawScreen();
		cout << "		" << cardP1->face << cardP1->suit << "		";
		cout << "		" << cardP2->face << cardP2->suit << endl;
		//usleep(1000000); // wait one second

		if(cardP1->value > cardP2->value)
		{
			cout << "player 1 wins" << endl;
			//move cards to winners hand
		}
		else if(cardP1->value < cardP2->value)
		{
			cout << "player 2 wins" << endl;
			//move cards to winners hand
		}
		else	
		{
			cout << "tie" << endl;
		}

		cin >> status_word;
		if (status_word == 'q')
		{
			status = 0;
			cin.clear();
			cin.ignore(256, '\n');
		}

		clearScreen();
	}
	
	showStats();
	status = 0;
	cin >> status_word;
	return status;
}


int drawScreen()
{
	cout << endl;
	cout << " Press 'ENTER' to play" << endl;
	cout << " Press 'q' to quit" << endl << endl << endl;
	cout << "_________________________________________________________" << endl;
	cout << "                          WAR                            " << endl;
	cout << endl;
	cout << "       Player             VS             Computer        " << endl;
	cout << endl;
	return 0;
}


int showStats()
{

	cout << "=========================================================" << endl;
	cout << "                                                         " << endl;
	cout << "							Stats                         " << endl;
	cout << "                                                         " << endl;
	cout << "	Total rounds = " << battles << endl;
	cout << "	Player 1 Wins = " << playerW << endl;
	cout << "	Computer Wins = " << computerW << endl;
	cout << "	Ties = " << ties << endl;
	cout << endl;


	return 0;
}

int clearStats()
{
	battles = 0;
 	ties = 0;
 	playerW = 0;
 	computerW = 0;

 	return 0;
}

