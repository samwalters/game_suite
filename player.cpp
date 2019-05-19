/******************************************************************************
* FILE DESCRIPTION:
*
*	CREATOR  -  Sam Walters
*	FILE NAME  -  player.cpp
*	PROJECT NAME  -  game_suite
*	DATE CREATED  -  2014-09-05
*
******************************************************************************/


#include"player.h"
//#include"deck.h"


using namespace std;

/******************************************************************************
*FUNCTION DESCRIPTION: Construct for player
*
*   NAME  -  
*   PARAMS  -
*   RETURNS  -
*
******************************************************************************/
Player::Player(string nombre)    {

    name = nombre;

}

/******************************************************************************
*FUNCTION DESCRIPTION: used for adding cards to the hand from a deck struct 
*
*  NAME  - draw
*  PARAMS  - size - number of cards to draw
*            deck - location to draw from
*  RETURNS  -none
*
******************************************************************************/
void Player::draw(int size, Deck *playingDeck) {

   for(int i = 0; i < size; i++)   {
        struct card* newCard = new struct card;
        newCard = playingDeck->draw();
        hand.push_back(newCard);
    }
}
/******************************************************************************
*FUNCTION DESCRIPTION: add single card to hand
*
*  NAME  -  takeCard
*  PARAMS  -    
*  RETURNS  -   size of hand
*
******************************************************************************/

//NEVER BEEN TESTED
//void Player::takeCard(struct card* add_card)
//{
//    hand.push_back(add_card);
//}
/******************************************************************************
*FUNCTION DESCRIPTION: prints to the screen the contents of the players hand
*
*  NAME  -  handSize()
*  PARAMS  -    none
*  RETURNS  -   size of hand
*
******************************************************************************/
int Player::handSize()  {

    int handSize = hand.size();
    return handSize;
}
/******************************************************************************
*FUNCTION DESCRIPTION: prints to the screen the contents of the players hand
*
*  NAME  -  showHand()
*  PARAMS  -    none
*  RETURNS  -   none
*
******************************************************************************/
void Player::showHand()	{ 
    
    if(handSize() == 0)   {
        cout << "Hand is empty" << endl;
        return;
    }

	for(int i = 0; i < handSize(); i++)	{
		cout << hand[i]->suit << hand[i]->face << endl;
	}
    return;
}

/******************************************************************************
*FUNCTION DESCRIPTION: moves # of cards from players hand into play
*
*  NAME  -      playCard   
*  PARAMS  -    
*  RETURNS  -   pointer to a card struct, NULL if handSize == 0
*
*   -possible that its necessary to check to make sure not NULL
*   -possible mem leak,
******************************************************************************/
struct card* Player::playCard()  {

    struct card* temp = hand.front();    //draw first card
    hand.erase(hand.begin());   //erase first card

    return temp;
}
/******************************************************************************
*FUNCTION DESCRIPTION:returns name
*
*  NAME  -  showHand()
*  PARAMS  -    none
*  RETURNS  -   name
*
******************************************************************************/
string Player::showName()
{
    string temp;
    temp = name;

    return temp;
}


    
