// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>
#include <sstream>

using namespace std;


TEST(test_card_ctor) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(ACE, c.get_rank());
    ASSERT_EQUAL(HEARTS, c.get_suit());
}

TEST(test_card_suit_and_rank) {
    Card two_spades = Card();
    ASSERT_EQUAL(two_spades.get_rank(), TWO);
    ASSERT_EQUAL(two_spades.get_suit(), SPADES);

    Card three_spades = Card(THREE, SPADES);
    ASSERT_EQUAL(three_spades.get_rank(), THREE);
    ASSERT_EQUAL(three_spades.get_suit(), SPADES);
    ASSERT_EQUAL(three_spades.get_suit(CLUBS), SPADES);
}

TEST(test_card_type) {
    Card three_spades = Card(THREE, SPADES);
    ASSERT_FALSE(three_spades.is_face_or_ace());
    ASSERT_FALSE(three_spades.is_right_bower(CLUBS));
    ASSERT_FALSE(three_spades.is_left_bower(CLUBS));
    ASSERT_FALSE(three_spades.is_trump(CLUBS));
}

TEST(test_card_self_comparison) {
    Card three_spades = Card(THREE, SPADES);
    ASSERT_FALSE(three_spades < three_spades);
    ASSERT_TRUE(three_spades <= three_spades);
    ASSERT_FALSE(three_spades > three_spades);
    ASSERT_TRUE(three_spades >= three_spades);
    ASSERT_TRUE(three_spades == three_spades);
    ASSERT_FALSE(three_spades != three_spades);
}

TEST(test_Suit_next) {
    ASSERT_EQUAL(Suit_next(CLUBS), SPADES);
}

TEST(test_Card_less_self) {
    Card three_spades = Card(THREE, SPADES);
    ASSERT_FALSE(Card_less(three_spades, three_spades, CLUBS));
    ASSERT_FALSE(Card_less(three_spades, three_spades, three_spades,
        CLUBS));
}

TEST(test_card_insertion) {
    Card three_spades = Card(THREE, SPADES);
    ostringstream oss;
    oss << three_spades;
    ASSERT_EQUAL(oss.str(), "Three of Spades");
}

TEST(test_card_extraction) {
    istringstream iss("Three of Spades");
    Card c;
    iss >> c;
    ASSERT_EQUAL(c, Card(THREE, SPADES));
}

TEST(test1) {
    Card c = Card(JACK, HEARTS);
    ASSERT_EQUAL(c.get_suit(DIAMONDS), DIAMONDS);
    ASSERT_EQUAL(c.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(c.get_suit(SPADES), HEARTS);
    ASSERT_TRUE(c.is_face_or_ace());
    ASSERT_TRUE(c.is_left_bower(DIAMONDS));
    ASSERT_FALSE(c.is_left_bower(HEARTS));
    ASSERT_TRUE(c.is_right_bower(HEARTS));
    ASSERT_FALSE(c.is_right_bower(DIAMONDS));
    ASSERT_FALSE(c.is_right_bower(CLUBS));
    ASSERT_TRUE(c.is_trump(DIAMONDS));
    ASSERT_TRUE(c.is_trump(HEARTS));
    ASSERT_FALSE(c.is_trump(CLUBS));
    ASSERT_EQUAL(Suit_next(HEARTS), DIAMONDS);
    ASSERT_EQUAL(Suit_next(DIAMONDS), HEARTS);
    ASSERT_EQUAL(Suit_next(SPADES), CLUBS);
    ASSERT_EQUAL(Suit_next(CLUBS), SPADES);
    Card d = Card(ACE, HEARTS);
    ASSERT_TRUE(c < d);
    ASSERT_TRUE(c <= d);
    ASSERT_TRUE(c <= c);
    ASSERT_TRUE(c == c);
    ASSERT_TRUE(c != d);
    ASSERT_TRUE(d > c);
    ASSERT_TRUE(d >= c);
    ASSERT_TRUE(d >= d);
    ASSERT_TRUE(Card_less(c, d, SPADES));
    ASSERT_TRUE(Card_less(d, c, DIAMONDS));
    ASSERT_TRUE(Card_less(d, c, HEARTS));
    Card e = Card(TEN, SPADES);
    ASSERT_TRUE(Card_less(d, e, SPADES));
    ASSERT_TRUE(Card_less(c, d, d, SPADES));
    ASSERT_TRUE(Card_less(d, c, d, DIAMONDS));
    ASSERT_TRUE(Card_less(d, c, d, HEARTS));
    ASSERT_TRUE(Card_less(d, e, e, DIAMONDS));
    ASSERT_TRUE(Card_less(e, d, d, DIAMONDS));
    ASSERT_TRUE(Card_less(e, d, c, DIAMONDS));
    ASSERT_TRUE(Card_less(e, d, c, HEARTS));
}

TEST(test100) {
    ASSERT_EQUAL(string_to_rank("Ten"), TEN);
    ASSERT_EQUAL(string_to_suit("Spades"), SPADES);
    ASSERT_FALSE(Card(TEN, SPADES).is_face_or_ace());
}


// Add more test cases here

TEST_MAIN()
