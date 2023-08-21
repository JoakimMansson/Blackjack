#include <iostream>
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
//#include "Dealer.hpp"

void playRound() {

}


int main() {
    Deck deck;

    for(int i = 0; i < 10; i++) {
        std::cout << deck.drawCard() << std::endl;
        //std::cout << deck.generateRandomNumber(1, 13) << std::endl;
    }
    deck.printDeck();
}


