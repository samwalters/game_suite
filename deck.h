/******************************************************************************
* FILE DESCRIPTION:
*
*	CREATOR  -  Sam Walters
*	FILE NAME  -  deck.h
*	PROJECT NAME  -  game_suite
*	DATE CREATED  -  2014-08-30
*
*****************************************************************************/

/******************************************************************************
* CLASS DESCRIPTION:  The deck class is meant to be used like a normal deck
*					  of cards. Its functions include shuffling, and 
*					  drawing the top card. All decks are unshuffled upon
*					  instanciation. It also contains the definition of
*					  a playing card struct. 
*
*
*****************************************************************************/


#ifndef DECK_H
#define DECK_H

#include<string>
#include<stack>
#include<sstream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<iostream>

using namespace std;

/******************************************************************************
* STRUCT DESCRIPTION: the card struct represents a single playing card. It has
*						1) a numerical value [used for comparisons/pts]
*						2) a face value [a name rather than a value]
*						3) a suit
*
******************************************************************************/
struct card	{
	int value;
	string face;
	string suit;
};

class Deck	{

	private:
        /* 52 blank cards */
        struct card newDeck[52];

        /* stack represents actual deck, reference this when drawing */
		stack<struct card*> deck;

	public:
		Deck();
		~Deck();
		void openDeck();
		void shuffle();
		struct card * draw();
        
        void printDeck();
        int emptyDeck();
     
};


#endif
