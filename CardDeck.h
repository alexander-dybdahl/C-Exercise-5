#include "Card.h"

#pragma once

class CardDeck {
private:
    vector<Card> deck;
public:
    CardDeck() {    
        for (int suitNr = 0; suitNr < 4; suitNr++) {
            for (int nr = 0; nr < 13; nr++) {
                Card card{Suit(suitNr), Rank(nr)};
                deck.push_back(card);
            }
        }
    }
    void swap(int a, int b); // Burde være public fordi jeg skal kunne kalle på funksjonen utenfor klassen
    void print();
    void shuffle();
    Card drawCard();
};