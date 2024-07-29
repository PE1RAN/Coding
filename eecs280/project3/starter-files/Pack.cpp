// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Pack.h"
#include "Card.h"
#include <sstream>

using namespace std;

Pack::Pack() {
	/*stringstream s;
	s << "Nine of Spades Ten of Spades Jack of Spades "
	  << "Queen of Spades King of Spades Ace of Spades "
	  << "Nine of Hearts Ten of Hearts Jack of Hearts "
	  << "Queen of Hearts King of Hearts Ace of Hearts "
      << "Nine of Clubs Ten of Clubs Jack of Clubs "
	  << "Queen of Clubs King of Clubs Ace of Clubs "
	  << "Nine of Diamonds Ten of Diamonds Jack of Diamonds "
	  << "Queen of Diamonds King of Diamonds Ace of Diamonds ";
	for (int i = 0; i < 24; ++i) {
		s >> cards[i];
	}*/
	for (int i = 0; i < 4; ++i) {
		for (int j = 7; j < 13; ++j) {
			cards[6 * i + j - 7] = Card(Rank(j), Suit(i));
		}
	}
	next = 0;
}

Pack::Pack(istream& pack_input) {
	for (int i = 0; i < 24; ++i) {
		pack_input >> cards[i];
	}
	next = 0;
}

Card Pack::deal_one() {
	return cards[next++];
}

void Pack::reset() {
	next = 0;
}

void Pack::shuffle() {
	for (int k = 0; k < 7; ++k) {
		Card temp[24];
		for (int i = 0; i < 12; ++i) {
			temp[2 * i] = cards[12 + i];
			temp[2 * i + 1] = cards[i];
		}
		for (int i = 0; i < 24; ++i) {
			cards[i] = temp[i];
		}
	}
	next = 0;
}

bool Pack::empty() const {
	return next == 24;
}