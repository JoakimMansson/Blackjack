#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Blackjack.hpp"


int main() {
    Blackjack blackjack;
    while (true)
    {
        blackjack.playGame();
        std::cout << "NEW ROUND STARTS..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}


