// FILE:  player.cpp


#include <iostream>
#include <string>
#include <vector>


#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

/*          
    vector <Card> myHand;
    vector <Card> myBook;
    
    string myName;  */   

Player::Player(){
   myName = "Name";
   turn = true;
}
 
void Player::addCard(Card c){  //adds a card to the hand
   myHand.push_back(c);
}
    
void Player::bookCards(Card c1, Card c2){
   myBook.push_back(c1);
   myBook.push_back(c2);
}
/*
void Player::initalDeal(int numCards){
   for(int i = 0; i < numCards; i++){
      addCard(*/
      

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards that make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2){
   for(int j = 0; j < myHand.size(); j++){
      for(int i = 0; i < myHand.size(); i++){
         if(myHand.at(i).getRank() == myHand.at(j).getRank() && myHand.at(i) != myHand.at(j)){
            cout << myHand.at(j).toString() << " Paired with " << myHand.at(i).toString() << endl;
            c1 = myHand.at(j);
            c2 = myHand.at(i);
            return true;
         }
      }
   }
   return false; 
}

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
   for(int i = 0; i < myHand.size(); i++){//goes through hand
      Card temp = myHand.at(i);
      int tempRank = temp.getRank();
      if(c.getRank() == tempRank && c != temp){
         return true;
      }
   }
   return false;
} 
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
   int handIndex = 0;
   for(int i = handIndex; i < myHand.size(); i++){
      for(int j = 0; j < (myBook.size() / 2); j++){ //looks to pick a card that already doesn't have a pair
         if(myHand.at(handIndex).getRank() == myBook.at(j).getRank() && handIndex + 1 < myHand.size()){
            handIndex++;
         }
      }
   }
   return myHand.at(handIndex);     
}
    
    //Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
   for(int i = 0; i < myHand.size(); i++){//goes through hand to check if same exact card
      if(c == myHand.at(i)){
         return true;
      }
   }
   return false;
}
    
    //Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
   Card temp;
   int once = 1;
   for(int i = 0; i < myHand.size(); i++){
      if(c.getRank() == myHand.at(i).getRank() && once == 1){
         temp = myHand.at(i);
         myHand.erase(myHand.begin()+i);
         once = 0;
      }
   }
   return temp;
}
    
string Player::showHand() const{
   string hand;
   string space = " ";
   for(int i = 0; i < myHand.size(); i++){
      Card temp = myHand.at(i);
      hand.append(temp.toString());
      hand.append(space);
   }
   return hand;
}

string Player::showBooks() const{
   string books;
   for(int i = 0; i < myBook.size(); i++){
      books.append(myBook.at(i).toString());
      if(i % 2 == 0){
         books.append("+");
      }
      else{
         books.append(" ");
      }
   }
   books.append("  ");
   books.append(to_string(myBook.size()/2));
   return books;
}
    
int Player::getHandSize() const{
   return myHand.size();
}
   
int Player::getBookSize() const{
   return (myBook.size() / 2);
}
       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
//bool Player::checkHandForPair(Card &c1, Card &c2){
//}

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
bool Player::sameRankInHand(Card c) const{
   for(int i = 0; i < myHand.size(); i++){
      if(c.getRank() == myHand.at(i).getRank()){
         return true;
      }
   }
   return false;
}  
