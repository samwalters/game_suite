/******************************************************************************
* FILE DESCRIPTION:
*
*	CREATOR  -  Sam Walters
*	FILE NAME  -  player.h
*	PROJECT NAME  - game_suite
*	DATE CREATED  -  2014-09-02
*
******************************************************************************/

/******************************************************************************
* CLASS DESCRIPTION: The purpose of this class is to behave like a normal 
*					 player in any game would. Functions will be added as 
*					 new games come along.
*
*					 Players have the following data...
*					    1) name
*					    2) current number of cards in hand
*					    3) a hand of cards
*
******************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include"deck.h"
#include<vector>
#include<string>

using namespace std;

class Player {

	private:
		vector<struct card*> hand;
		string name;

	public:
		Player(string nombre);
		void draw(int size, Deck *playingDeck);
		void showHand();
		struct card* playCard();
		int handSize();
		string showName();

};

#endif
