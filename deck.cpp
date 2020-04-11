// FILE: deck.cpp
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#include "card.h"
#include "deck.h"

#include <string>
#include <iostream>
#include <ctime>


using namespace std;
//static const int SIZE = 52;
 /*   Card myCards[SIZE];
    int myIndex;  // current card to deal
 */
  
Deck::Deck()           // pristine, sorted deck
{
   for(int i = 0; i < SIZE; i++){
      if(i < 13){
         myCards[i] = Card(i + 1, Card::spades);
      }
      else if(i >= 13 && i < 26){
         myCards[i] = Card((i % 13) + 1, Card::hearts);
      }
      else if(i >= 26 && i < 39){
         myCards[i] = Card((i % 13) + 1, Card::diamonds);
      }
      else{
         myCards[i] = Card((i % 13) + 1, Card::clubs);
      }
   }
   myIndex = 0;  
}

void Deck::shuffle(){   // shuffle the deck, all 52 cards present
   srand(time(0));
   int rNum;
   Card temp;
   for(int i = 0; i < (rand() % 5) + 1; i++){ //chooses how many times to shuffle the deck
      for(int j = 0; j < SIZE; j++){// j is the index pointer
         rNum = (rand() % SIZE);
         temp = myCards[rNum];
         myCards[rNum] = myCards[j];
         myCards[j] = temp;
      }
   }
}
    
Card Deck::dealCard(){   // get a card, after 52 are dealt, fail 
   if(myIndex < 52){
      Card temp;
      temp = myCards[myIndex];
      myIndex++;
      return temp;
   }
}

int  Deck::size() const{ // # cards left in the deck
   return (SIZE - myIndex);
}

