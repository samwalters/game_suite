/******************************************************************************
* FILE DESCRIPTION:
*
*	CREATOR  - Sam Walters
*	FILE NAME - deck.cpp
*   PROJECT NAME  -  game_suite
*	DATE CREATED  -  2014-08-30
*
******************************************************************************/

#include"deck.h"

/******************************************************************************
* FUNCTION DESCRIPTION:
*
*	NAME  -  Contstructor for deck class. Creates a deck of cards that are
*			 unshuffled. Supposed to simulate getting a real deck of cards.
*
*	PARAMS  - none
*	RETURNS  - none
*
******************************************************************************/
Deck::Deck()	{

	openDeck();

}

Deck::~Deck()
{

}
/******************************************************************************
* FUNCTION DESCRIPTION: Creates a deck of cards that consists of 52 card 
*						structs and initializes them in order. 
*
*	NAME  -  openDeck()
*	PARAMS  -  none
*	RETURNS  -  none
*
******************************************************************************/
void Deck::openDeck()	{

	int i,j,k;

	string face[13] = {"2","3","4","5","6","7","8","9","10",
							"J", "Q", "K", "A" };
	string suit[4] = {"♥", "♦", "♣", "♠"};

	j = 0;
	
	for(k = 0; k < 4; k++){

		for(i = 0; i < 13; i++)	{

			/* Initialize card */
			newDeck[j].value = i+2;
			newDeck[j].suit = suit[k];
			newDeck[j].face = face[i];

			/* Put into playing deck */
			struct card *tmpCard = &newDeck[j];
			deck.push(tmpCard);
			j++;
		}
	}


	return;
}

/******************************************************************************
 * FUNCTION DESCRIPTION: Shuffles the deck using 2 shuffling techniques a 
 *						random number of times.
 *
 *	NAME  -  shuffle()
 *	PARAMS  -  none
 *	RETURNS  -  none
 *
 ******************************************************************************/
void Deck::shuffle()	{

	/* Make temporary piles for shuffling and global random num */
	stack<struct card*> shuffleDeck1;
	stack<struct card*> shuffleDeck2;
	stack<struct card*> shuffleDeck3;
	int randomNum;

	/* Configure random number generator and create random number */
	srand( time( NULL));
	randomNum = (rand() % 100);
	randomNum += 1;

	/* Perform this shuffle a random number of times */
	for(int j = 0; j < randomNum; j++)	{

		/* The following 4 while loops perform a pile shuffle */
		while(!deck.empty())	{

			if(!deck.empty())	{
				shuffleDeck1.push(deck.top());
				deck.pop();
			}
			if(!deck.empty())	{
				shuffleDeck2.push(deck.top());
				deck.pop();
			}
			if(!deck.empty())	{
				shuffleDeck3.push(deck.top());
				deck.pop();
			}
		}

		while(!shuffleDeck1.empty())	{
			deck.push(shuffleDeck1.top());
			shuffleDeck1.pop();
		}
		while(!shuffleDeck2.empty())	{
			deck.push(shuffleDeck2.top());
			shuffleDeck2.pop();
		}
		while(!shuffleDeck3.empty())	{
			deck.push(shuffleDeck3.top());
			shuffleDeck3.pop();
		}


	}

	//Config and generate a random number 
	srand( time( NULL));
	randomNum = (rand() % 7);
	randomNum += 1;

	//Perform this shuffle a random number of times 
	for(int j = 0; j < randomNum; j++)	{

		//Riffle Shuffe 
		for(int i = 0; i < 25; i++)	{
			shuffleDeck1.push(deck.top());
			deck.pop();
		}
		while(!deck.empty())	{
			shuffleDeck2.push(deck.top());
			deck.pop();
		}

		while(deck.size() < 52)	{

			//Config and generate a random number
			srand( time( NULL));
			randomNum = (rand() % 4);
			randomNum += 1;

			for(int i = 0; i < randomNum; i++)	{
				if(!shuffleDeck1.empty())	{
					deck.push(shuffleDeck1.top());
					shuffleDeck1.pop();

				}
			}

			//Config and generate a random number
			srand( time( NULL));
			randomNum = (rand() % 4);
			randomNum += 1;

			for(int i = 0; i < randomNum; i++)	{
				if(!shuffleDeck2.empty())	{
					deck.push(shuffleDeck2.top());
					shuffleDeck2.pop();
				}
			}


		}

	}



	return;
}

/******************************************************************************
 * FUNCTION DESCRIPTION: Draws the top card off the deck.
 *
 *	NAME  -  draw()
 *	PARAMS  -  none
 *	RETURNS  -  pointer to card struct
 *
 ******************************************************************************/
struct card* Deck::draw()	{

	struct card *tempCard = new struct card;
	tempCard = deck.top();
	deck.pop();
	return tempCard;

}

/******************************************************************************
 * FUNCTION DESCRIPTION: Prints the deck, does not reorder, debug only
 *
 *	NAME  -  printDeck()
 *	PARAMS  -  none
 *	RETURNS  -  none
 *
 ******************************************************************************/
void Deck::printDeck()	{

	int counter = 1;
 	/*Temporary Deck used for printing */
 	stack<struct card*> printDeck;

	while(!deck.empty())	{

		cout << deck.top()->face << " " << deck.top()->suit << " " << counter << endl;
		printDeck.push(deck.top());
		deck.pop();
		counter++;
	}

	//put back into regular deck
	while(!printDeck.empty())	{

		deck.push(printDeck.top());
		printDeck.pop();
	}


 	return;
 }

 /******************************************************************************
 * FUNCTION DESCRIPTION: tells if there are cards left in the deck
 *
 *	NAME  -  emptyDeck()
 *	PARAMS  -  none
 *	RETURNS  -  0 empty deck, 1 card(s) left in deck
 *
 ******************************************************************************/
 int Deck::emptyDeck()
 {
 	if(!deck.empty()){
 		//cout << "cards left = "<< deck.size() << endl;
 		return 1;
 	}
 	else
 		//cout << "deck empty"<< endl;
 		return 0;
 	
 }