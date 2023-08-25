#pragma once
#include <iostream>
#include <string>


#include "Dealer.hpp"
#include "Deck.hpp"
#include "Player.hpp"


class Blackjack {
    public:
        Blackjack() {};
        void playGame();
    private:
        void resetRound();
        bool canSplit();
        bool canDoubleDown();
        bool firstRoundFinished = false;
        Deck* deck = new Deck();
        Player player{deck};
        Dealer dealer{deck};
};
