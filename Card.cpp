#include "std_lib_facilities.h"
#include "Card.h"

string suitToString(Suit suit) {
    vector<string> suitStrings = {"Clubs","Diamonds","Hearts","Spades"};
    return suitStrings[int(suit)];
}

string rankToString(Rank rank) {
    vector<string> rankStrings = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    return rankStrings[int(rank)];
}

// I implementasjonsfilen definerer man konstruktører og medlemsfunksjoner
Card::Card(Suit suit, Rank rank): s{suit}, r{rank} // Initialiseringsliste
{}

Suit Card::getSuit() {
    return Card::s;
}

Rank Card::getRank() {
    return Card::r;
}

string Card::toString() {
    return string(rankToString(getRank())) + " of " + string(suitToString(getSuit()));
}