// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

#include "stdio.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

void bookPairs(Player &p);


int main( )
{
    int numCards = 7;
    
    Player p1("Joe");
    Player p2("Jane");
   
    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
 
    bool player1_turn = true;

    while(p1.getBookSize() + p2.getBookSize() < 26){
       cout << "\nJoe's Turn:\n" << endl; 
       while(player1_turn){
          bookPairs(p1);
          cout << "\n" << p1.getName() <<"'s hand: " << p1.showHand() << endl;
          cout << p1.getName() <<"'s book: " << p1.showBooks() << endl;
   
          if(p1.getHandSize() > 0){
             Card choice = p1.chooseCardFromHand();
             cout << p1.getName() <<" asks for: " << choice.toString() << endl;
          
             player1_turn = false;
             for(int i = 0; i < 3; i++){
                if(p2.sameRankInHand(choice)){  //p1 asking if player2 has any cards of rank of his choice
                   Card removed = p2.removeCardFromHand(choice);
                   p1.addCard(removed);
                   player1_turn = true;
                }
             }
             if(!player1_turn && d.size() > 0){
                p1.addCard(d.dealCard());
             }
          }
          else{
             player1_turn = false;
             cout << "deck size: " << d.size() << endl;
             if(d.size() > 0){ 
                p1.addCard(d.dealCard());
             }
          }
       }
       cout << "\nJanes Turn:\n" << endl;
       while(!player1_turn){
          bookPairs(p2);
          cout << "\n" << p2.getName() <<"'s hand: " << p2.showHand() << endl;
          cout << p2.getName() <<"'s book: " << p2.showBooks() << endl;
   
          if(p2.getHandSize() > 0){
             Card choice = p2.chooseCardFromHand();
             cout << p2.getName() <<" chose : " << choice.toString() << endl;

             player1_turn = true;
             for(int i = 0; i < 3; i++){
                if(p1.sameRankInHand(choice)){  //p1 asking if player2 has any cards of rank of his choice
                   Card removed = p1.removeCardFromHand(choice);
                   p2.addCard(removed);
                   player1_turn = false;
                }
             }
             if(player1_turn && d.size() > 0){
                p2.addCard(d.dealCard());
             }
          }
          else{
             player1_turn = true;
             if(d.size() > 0){ 
                p2.addCard(d.dealCard());
             }
          }
       }
    
    }
  
   cout << "\n\n" << p1.getName() <<"'s hand: " << p1.showHand() << endl;
   cout << p1.getName() <<"'s book: " << p1.showBooks() << endl;
   cout << "\n" << p2.getName() <<"'s hand: " << p2.showHand() << endl;
   cout << p2.getName() <<"'s book: " << p2.showBooks() << endl;
     
    return EXIT_SUCCESS;  

}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++){
      p.addCard(d.dealCard());
   }
}
   
void bookPairs(Player &p)
{
   Card card1;
   Card card2;
   while(p.checkHandForBook(card1, card2)){ //book all pairs and removes them from hand
      p.bookCards(card1,card2);
      p.removeCardFromHand(card1);
      p.removeCardFromHand(card2);
   }
}
