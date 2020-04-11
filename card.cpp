//card.cpp
//
#include "card.h"
#include <string>
#include <iostream>

using namespace std;

//Creates a Ace of Spades card
Card::Card()
{
   myRank = 1;
   mySuit = spades;
}

//Creates a card
Card::Card(int rank, Suit s)
{
   myRank = rank;
   mySuit = s;
}

//return string version e.g. Ac 4h Js
string Card::toString() const
{
   string rank = rankString(myRank);
   string suit = suitString(mySuit);
   rank.append(suit);
   return rank;
}

//true if suit same as card c
bool Card::sameSuitAs(const Card& c) const
{
   if(mySuit == c.mySuit){
      return true;
   }
   else{
      return false;
   }
}

//return rank, 1..13
int Card::getRank() const
{
   return myRank;
}

//return "s", "h",...
string Card::suitString(Suit S) const
{
   string suit;
   if(S == 0){
      suit = "s";
   }
   else if(S == 1){
      suit = "h";
   }
   else if(S == 2){
      suit = "d";
   }
   else{
      suit = "c";
   }
   return suit;
}

//return "A", "2", ... "K"
string Card::rankString(int r) const
{
   string rank;
   if(r == 1){
      rank = 'A';
   }
   else if(r == 11){
      rank = 'J';
   }
   else if(r == 12){
      rank = 'Q';
   }
   else if(r == 13){
      rank = 'K';
   }
   else{
      rank = to_string(r);
   }
   return rank;
}

bool Card::operator ==(const Card& rhs) const
{
   return (myRank == rhs.myRank && mySuit == rhs.mySuit);
}

bool Card::operator !=(const Card& rhs) const
{
   return (myRank != rhs.myRank || mySuit != rhs.mySuit);
}

/* ostream& operator << (ostream&out, const Card &c)
{
}
*/
