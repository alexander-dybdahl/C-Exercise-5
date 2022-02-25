#include "std_lib_facilities.h"
#include "CardDeck.h"

void CardDeck::swap(int a, int b) {
    Card cardTemp = deck[a];
    deck[a] = deck[b];
    deck[b] = cardTemp;
}

void CardDeck::print() {
    for (int i = 0; i < int(deck.size()); i++) {
        cout << deck[i].toString() << '\n';
    }
}

void CardDeck::shuffle() {
    int count = 0;
    while (count < 1000) {
        int randomNum1 = char(rand() % 52);
        int randomNum2 = char(rand() % 52);
        swap(randomNum1, randomNum2);
        count++;
    }
}

Card CardDeck::drawCard() {
    Card card = deck.back();
    deck.pop_back();
    return card;
}