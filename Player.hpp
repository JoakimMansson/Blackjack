#pragma once
#include "Deck.hpp"

class Player
{
    public:
        Player(Deck& cardDeck): deck(cardDeck) {};
        void drawCard();
        void resetRound();
        int getCardSum();

    private:
        Deck deck;
        int currentCardSum = 0;
        int nrCardsDrawn = 0;
};

