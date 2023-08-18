#include "Deck.hpp"
#include <random>
#include <iostream>


Deck::Deck() {
    int nrCards[13] = {0}; // Array of 13 elements, all initialized to 0

    for(int i = 0; i < 52; i++) {
        int randomNumber = Deck::generateRandomNumber(1, 13);
        while (nrCards[randomNumber - 1] == 4) {
            randomNumber = Deck::generateRandomNumber(1, 13);
        }

        cards[i] = Deck::generateRandomNumber(1, 13);
        nrCards[randomNumber - 1]++;
    }
}

int Deck::drawCard() {
    static int index = 0;
    if (index + 1 >= 52) return -1; // No more cards in the deck
    else return cards[index++]; // Return the next card in the deck
}

void Deck::printDeck() {
    for (int i = 0; i < 52; i++) {
        std::cout << cards[i];
    }
    std::cout << std::endl;
}

int Deck::generateRandomNumber(int min, int max) {
    // static is used here to ensure that the random number engine
    // and distribution retain their states between function calls
    static std::random_device rd;  // Seed for the random number engine
    static std::mt19937 engine(rd()); // Mersenne Twister random number engine
    static std::uniform_int_distribution<int> dist;

    dist.param(std::uniform_int_distribution<int>::param_type(min, max));

    return dist(engine);
}