#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"


int main() {
	srand(unsigned(time(nullptr)));

    while(true) {
        cout << "Choose function:\n" 
        << "0) End\n" 
        << "1) Suit to string\n" 
        << "2) Rank to string\n" 
        << "3) To string\n"
		<< "4) Card deck\n"
		<< "5) Shuffle card deck\n"
		<< "6) Draw card\n"
		<< "7) Blackjack\n";
        cout << "Choose options (0-7): ";
        int choice = 0;
        cin >> choice;
        if (choice == 0) {
            break;
        }
        if (choice == 1) {
            cout << suitToString(Suit::spades) << '\n';
        }
        if (choice == 2) {
            cout << rankToString(Rank::two) << '\n';
        }
        if (choice == 3) {
			Card c{Suit::spades, Rank::two};
            cout << c.toString() << '\n';
        }
        if (choice == 4) {
			CardDeck cardDeck;
            cardDeck.print();
        }
        if (choice == 5) {
			CardDeck cardDeck;
            cardDeck.shuffle();
            cardDeck.print();
        }
        if (choice == 6) {
			CardDeck cardDeck;
            cardDeck.shuffle();
            Card card = cardDeck.drawCard();
            cout << card.toString() << '\n';
        }
        if (choice == 7) {
			Blackjack blackjack;
            blackjack.playGame();
        }
	}
}