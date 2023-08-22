#include "Blackjack.hpp"
#include <thread>
#include <chrono>

void Blackjack::playGame() {
    player.drawCard();
    player.drawCard();
    dealer.drawCard();

    std::cout << "Player has: " << player.getCardSum() << std::endl;
    std::cout << "Dealer has: " << dealer.getCardSum() << std::endl;

    if (Blackjack::canDoubleDown()) {
        std::cout << "Player turn (stand, hit, double) " << player.getCardSum() << std::endl;
        
        std::string playerAction;
        std::getline(std::cin, playerAction);  // Reads an entire line of input into the 'playerAction' variable

        while(playerAction != "stand" && playerAction != "hit" && playerAction != "double")
        {
            std::cout << "[FAULTY INPUT] Player turn (stand, hit, double) " << std::endl;
            std::getline(std::cin, playerAction);  // Reads an entire line of input into the 'playerAction' variable
        }

        if (playerAction == "double") {
            player.drawCard();
            std::cout << "Player has: " << player.getCardSum() << std::endl;
            std::cout << "Dealer has: " << dealer.getCardSum() << std::endl;
        }

        while (playerAction != "stand" && player.getCardSum() < 21) {
            std::cout << "Player turn (stand, hit) " << player.getCardSum() << std::endl;
            std::getline(std::cin, playerAction);
            player.drawCard();
            std::cout << "Player has: " << player.getCardSum() << std::endl;
            std::cout << "Dealer has: " << dealer.getCardSum() << std::endl;
        }
    }
    else {
        std::cout << "Player turn (stand, hit) " << std::endl;

        std::string playerAction;
        std::getline(std::cin, playerAction);  // Reads an entire line of input into the 'playerAction' variable

        while (playerAction != "stand" && playerAction != "hit")
        {
            std::cout << "[FAULTY INPUT] Player turn (stand, hit) " << player.getCardSum() << std::endl;
            std::getline(std::cin, playerAction);  // Reads an entire line of input into the 'playerAction' variable
        }

        std::cout << "Player has: " << player.getCardSum() << std::endl;
        std::cout << "Dealer has: " << dealer.getCardSum() << std::endl;
        while (playerAction != "stand" && player.getCardSum() < 21) {
            std::cout << "Player turn (stand, hit) " << player.getCardSum() << std::endl;
            std::getline(std::cin, playerAction);
            player.drawCard();
            std::cout << "Player has: " << player.getCardSum() << std::endl;
            std::cout << "Dealer has: " << dealer.getCardSum() << std::endl;
        }
    }

    /* Player busts! */
    if (player.getCardSum() > 21) {
        std::cout << "Player busts!" << std::endl;
        resetRound();
        return;
    }

    /* Dealer draws until > 17 */
    while (dealer.getCardSum() < 17) {
        dealer.drawCard();
        std::cout << "Dealer has: " << dealer.getCardSum() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    /* Decide the winner */
    if (player.getCardSum() > dealer.getCardSum() && player.getCardSum() < 21) {
        std::cout << "Player wins!" << std::endl;
    }
    else if (dealer.getCardSum() > 21 && player.getCardSum() < 21) {
        std::cout << "Player wins!" << std::endl;
    }
    else if (player.getCardSum() == 21 && dealer.getCardSum() != 21) {
        std::cout << "Player BLACKJACK!" << std::endl;
    }
    else if (player.getCardSum() == dealer.getCardSum() && player.getCardSum() <= 21) {
        std::cout << "Push!" << std::endl;
    }
    else {
        std::cout << "Dealer wins!" << std::endl;
    }

    resetRound();
}

bool Blackjack::canSplit() {
    return false;
}

bool Blackjack::canDoubleDown() {
    int playerSum = player.getCardSum();
    return ((playerSum == 9 || playerSum == 10 || playerSum == 11) && player.hasAnAce == false) || 
        ((playerSum == 16 || playerSum == 17 || playerSum == 18) && player.hasAnAce == true);
}

void Blackjack::resetRound() {
    player.resetHand();
    dealer.resetHand();
}