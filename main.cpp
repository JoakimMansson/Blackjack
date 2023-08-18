#include <iostream>
#include "Deck.hpp"
//#include "Dealer.hpp"


int main() {
    Deck deck;
    for (int i = 0; i < 10; i++) {
        int card = deck.drawCard();
        std::cout << card << std::endl;
    }

}