#pragma once

enum class Suit {clubs, diamonds, hearts, spades};

enum class Rank {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, ace2};

string suitToString(Suit suit);

string rankToString(Rank rank);

class Card { // I headerfilen deklarerer man klassen
private:
    Suit s; // Medlemsvariabel
    Rank r; // Medlemsvariabel
public:
    Card(Suit suit, Rank rank); // Konstruktør
    Suit getSuit();
    Rank getRank();
    string toString();
};