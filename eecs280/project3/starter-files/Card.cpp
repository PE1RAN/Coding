// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <array>
#include "Card.h"

using namespace std;

/////////////// Rank operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const RANK_NAMES[] = {
  "Two",   // TWO
  "Three", // THREE
  "Four",  // FOUR
  "Five",  // FIVE
  "Six",   // SIX
  "Seven", // SEVEN
  "Eight", // EIGHT
  "Nine",  // NINE
  "Ten",   // TEN
  "Jack",  // JACK
  "Queen", // QUEEN
  "King",  // KING
  "Ace"    // ACE
};

//REQUIRES str represents a valid rank ("Two", "Three", ..., "Ace")
Rank string_to_rank(const std::string &str) {
  for(int r = TWO; r <= ACE; ++r) {
    if (str == RANK_NAMES[r]) {
      return static_cast<Rank>(r);
    }
  }
  assert(false); // Input string didn't match any rank
}

//EFFECTS Prints Rank to stream, for example "Two"
std::ostream & operator<<(std::ostream &os, Rank rank) {
  os << RANK_NAMES[rank];
  return os;
}

//EFFECTS Reads a Rank from a stream, for example "Two" -> TWO
std::istream & operator>>(std::istream &is, Rank &rank) {
  string str;
  is >> str;
  rank = string_to_rank(str);
  return is;
}



/////////////// Suit operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const SUIT_NAMES[] = {
  "Spades",   // SPADES
  "Hearts",   // HEARTS
  "Clubs",    // CLUBS
  "Diamonds", // DIAMONDS
};

//REQUIRES str represents a valid suit ("Spades", "Hearts", "Clubs", or "Diamonds")
Suit string_to_suit(const std::string &str) {
  for(int s = SPADES; s <= DIAMONDS; ++s) {
    if (str == SUIT_NAMES[s]) {
      return static_cast<Suit>(s);
    }
  }
  assert(false); // Input string didn't match any suit
}

//EFFECTS Prints Suit to stream, for example "Spades"
std::ostream & operator<<(std::ostream &os, Suit suit) {
  os << SUIT_NAMES[suit];
  return os;
}

//EFFECTS Reads a Suit from a stream, for example "Spades" -> SPADES
std::istream & operator>>(std::istream &is, Suit &suit) {
  string str;
  is >> str;
  suit = string_to_suit(str);
  return is;
}


/////////////// Write your implementation for Card below ///////////////


// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec before implementing
// the following operator overload functions:
//   operator<<
//   operator>>
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=

Card::Card() {
    rank = TWO;
    suit = SPADES;
}

Card::Card(Rank rank_in, Suit suit_in) {
    rank = rank_in;
    suit = suit_in;
}

Rank Card::get_rank() const {
    return rank;
}

Suit Card::get_suit() const {
    return suit;
}

Suit Card::get_suit(Suit trump) const {
    if (is_left_bower(trump)) return trump;
    return suit;
}

bool Card::is_face_or_ace() const {
    return rank > TEN;
}

bool Card::is_right_bower(Suit trump) const {
    return rank == JACK && suit == trump;
}

bool Card::is_left_bower(Suit trump) const {
    return rank == JACK && suit == Suit_next(trump);
}

bool Card::is_trump(Suit trump) const {
    return get_suit(trump) == trump;
}

ostream& operator<<(std::ostream& os, const Card& card) {
    os << card.get_rank() << " of " << card.get_suit();
    return os;
}

istream& operator>>(std::istream& is, Card& card) {
    char troll;
    is >> card.rank >> troll >> troll >> card.suit;
    return is;
}

bool operator<(const Card& lhs, const Card& rhs) {
    return lhs.get_rank() * 4 + lhs.get_suit() < rhs.get_rank() * 4 + rhs.get_suit();
}

bool operator<=(const Card& lhs, const Card& rhs) {
    return lhs.get_rank() * 4 + lhs.get_suit() <= rhs.get_rank() * 4 + rhs.get_suit();
}

bool operator>(const Card& lhs, const Card& rhs) {
    return lhs.get_rank() * 4 + lhs.get_suit() > rhs.get_rank() * 4 + rhs.get_suit();
}

bool operator>=(const Card& lhs, const Card& rhs) {
    return lhs.get_rank() * 4 + lhs.get_suit() >= rhs.get_rank() * 4 + rhs.get_suit();
}

bool operator==(const Card& lhs, const Card& rhs) {
    return lhs.get_rank() * 4 + lhs.get_suit() == rhs.get_rank() * 4 + rhs.get_suit();
}

bool operator!=(const Card& lhs, const Card& rhs) {
    return lhs.get_rank() * 4 + lhs.get_suit() != rhs.get_rank() * 4 + rhs.get_suit();
}

Suit Suit_next(Suit suit) {
    return Suit((suit + 2) % 4);
}

bool Card_less(const Card& a, const Card& b, Suit trump) {
    int value_a = a.get_rank() * 4 + a.get_suit();
    int value_b = b.get_rank() * 4 + b.get_suit();
    if (a.is_right_bower(trump)) value_a = 300;
    else if (a.is_left_bower(trump)) value_a = 200;
    else if (a.is_trump(trump)) value_a = 100 + a.get_rank();
    if (b.is_right_bower(trump)) value_b = 300;
    else if (b.is_left_bower(trump)) value_b = 200;
    else if (b.is_trump(trump)) value_b = 100 + b.get_rank();
    return value_a < value_b;
}

bool Card_less(const Card& a, const Card& b, const Card& led_card, Suit trump) {
    int value_a = a.get_rank() * 4 + a.get_suit();
    int value_b = b.get_rank() * 4 + b.get_suit();
    if (a.is_right_bower(trump)) value_a = 400;
    else if (a.is_left_bower(trump)) value_a = 300;
    else if (a.is_trump(trump)) value_a = 200 + a.get_rank();
    else if (a.get_suit(trump) == led_card.get_suit(trump)) value_a = 100 + a.get_rank();
    if (b.is_right_bower(trump)) value_b = 400;
    else if (b.is_left_bower(trump)) value_b = 300;
    else if (b.is_trump(trump)) value_b = 200 + b.get_rank();
    else if (b.get_suit(trump) == led_card.get_suit(trump)) value_b = 100 + b.get_rank();
    return value_a < value_b;
}