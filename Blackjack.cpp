#include "Blackjack.h"

bool isAce(Card card) {
    return (int(card.getRank())==11);
}

int Blackjack::getCardValue(Card card) {
    int value;
    if (card.getRank() == Rank::two) {value =  2;}
    if (card.getRank() == Rank::three) {value =  3;}
    if (card.getRank() == Rank::four) {value =  4;}
    if (card.getRank() == Rank::five) {value =  5;}
    if (card.getRank() == Rank::six) {value =  6;}
    if (card.getRank() == Rank::seven) {value =  7;}
    if (card.getRank() == Rank::eight) {value =  8;}
    if (card.getRank() == Rank::nine) {value =  9;}
    if (card.getRank() == Rank::ten) {value =  10;}
    if (card.getRank() == Rank::jack) {value =  10;}
    if (card.getRank() == Rank::queen) {value =  10;}
    if (card.getRank() == Rank::king) {value =  10;}
    if (card.getRank() == Rank::ace) {value =  11;}
    if (card.getRank() == Rank::ace2) {value =  1;}
    return value;
}

int Blackjack::getHandScore(vector<Card> hand) {
    int score = 0;
    for (int i = 0; i < int(hand.size()); i++) {
        score += getCardValue(hand[i]);
    }
    return score;
}

bool Blackjack::askPlayerDrawCard() {
    string ask;
    cout << "Do you want to draw another card? (y/n)";
    cin >> ask;
    return (ask == "y");
}

void Blackjack::drawPlayerCard() {
    Card card = deck.drawCard();
    playerHand.push_back(card);
    playerHandSum = getHandScore(playerHand);
}

void Blackjack::drawDealerCard() {
    Card card = deck.drawCard();
    dealerHand.push_back(card);
    dealerHandSum = getHandScore(dealerHand);
}

void Blackjack::printPlayerHand() {
    cout << "Players cards are:\n";
    for (int i = 0; i < int(playerHand.size()); i++) {
        cout << playerHand[i].toString() << '\n';
    }
    cout << "Total points of the players cards are: " << playerHandSum << '\n';
}

void Blackjack::printDealerHand() {
    cout << "Dealers cards are:\n";
    for (int i = 0; i < int(dealerHand.size()); i++) {
        cout << dealerHand[i].toString() << '\n';
    }
    cout << "Total points of the dealers cards are: " << dealerHandSum << '\n';
}

void Blackjack::playerAceToOne() {
   if (playerHandSum > 21) {
        for (int i = 0; i < int(playerHand.size()); i++) {
            if (isAce(playerHand[i])) { // Checks if there are any Aces
                Suit suit = playerHand[i].getSuit();
                cout << "Type 1 " << playerHandSum << "\n";
                playerHand[i] = {suit, Rank::ace2}; // Changes value to 1
                playerHandSum = getHandScore(playerHand);
                cout << "Type 2 " << playerHandSum << "\n";
            }
        }
    }
}

void Blackjack::dealerAceToOne() {
   if (dealerHandSum > 21) {
        for (int i = 0; i < int(dealerHand.size()); i++) {
            if (isAce(dealerHand[i])) { // Checks if there are any Aces
                cout << "there is an ace\n";
                dealerHandSum -= 10;
                Suit suit = dealerHand[i].getSuit();
                dealerHandSum = getHandScore(dealerHand);
                cout << "Type 3 " << dealerHandSum << "\n";
                dealerHand[i] = {suit, Rank::ace2}; // Changes value to 1
                dealerHandSum = getHandScore(dealerHand);
                cout << "Type 4 " << dealerHandSum << "\n";
            }
        }
    }
}

bool Blackjack::hasPlayerLost() {
    if (playerHandSum > 21) {
        return true;
    }
    return false;
}

bool Blackjack::hasDealerLost() {
    if (dealerHandSum > 21) {
        return true;
    }
    return false;
}

void Blackjack::playGame() {
    cout << "Welcome to Blackjack!\n";
    deck.shuffle();
    drawPlayerCard();
    drawDealerCard();
    drawPlayerCard();
    drawDealerCard();
    printPlayerHand();

    playerAceToOne();
    dealerAceToOne();
    while (true) {
        if (hasPlayerLost() || hasDealerLost()) {
            break;
        }
        if (askPlayerDrawCard()) {
            cout << "The player drew another card\n";
            drawPlayerCard();
            printPlayerHand();
            playerAceToOne();
        }
        else {
            while (dealerHandSum <= 17) { // Dealer draws cards if less or equal 17 points
                cout << "The dealer drew another card\n";
                drawDealerCard();
                //printDealerHand();
                dealerAceToOne();
            }
            break;
        }
    }
    printPlayerHand();
    printDealerHand();
    if (playerHandSum == 21 && dealerHandSum != 21) {
        cout << "The player got a Blackjack!\n";
        cout << "You won!\n";
    }
    else if (dealerHandSum == 21 && playerHandSum != 21) {
        cout << "The dealer got a Blackjack!\n";
        cout << "You lost\n";
    }
    else if (hasPlayerLost() && !hasDealerLost()) {
        cout << "The player has more than 21 points\n";
        cout << "You lost\n";
    }
    else if (hasDealerLost() && !hasPlayerLost()) {
        cout << "The dealer has more than 21 points\n";
        cout << "You won!\n";
    }
    else if (hasDealerLost() && hasPlayerLost()) {
        cout << "Both had more than 21 points\n";
        cout << "Its a draw\n";
    }
    else if (dealerHandSum == playerHandSum) {
        cout << "You had equal points\n";
        cout << "Its a draw\n";
    }
    else if (dealerHandSum > playerHandSum) {
        cout << "The dealer was closer to 21 points\n";
        cout << "You lost\n";
    }
}