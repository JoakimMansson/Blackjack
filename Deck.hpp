#pragma once // Prevents multiple inclusions of this header file

class Deck {
    public:
        Deck(); // Private constructor (only Deck.cpp can create Deck objects
        int drawCard();
        void printDeck();
        int generateRandomNumber(int min, int max);
    private:
        int cards[52];
};