#include "std_lib_facilities.h"
#include "CardDeck.h"

#pragma once

class Blackjack {
private:
    vector<Card> playerHand;
    vector<Card> dealerHand;
    CardDeck deck;
    int playerHandSum;
    int dealerHandSum;
public:
    int getCardValue(Card card);
    int getHandScore(vector<Card> hand);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void printPlayerHand();
    void printDealerHand();
    void playerAceToOne();
    void dealerAceToOne();
    bool hasPlayerLost();
    bool hasDealerLost();
    void playGame();
};

bool isAce(Card card);