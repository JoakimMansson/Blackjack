#include "Player.hpp"
#include <iostream>


void Player::drawCard() {
    int card = deck.drawCard();
    if (card == -1) {
        std::cout << "No more cards in the deck, creating a new deck" << std::endl;
        deck = Deck();
        card = deck.drawCard();
    }

    if (card == 1 && currentCardSum + 11 > 21) { // If an Ace
        hasAnAce = true;
        if (currentCardSum + 11 > 21)
        {
            currentCardSum += 1;
        }
    }
    else {
        currentCardSum += card;
    }
    nrCardsDrawn++;
}

void Player::resetHand() {
    currentCardSum = 0;
    nrCardsDrawn = 0;
}

int Player::getCardSum() {
    return currentCardSum;
}