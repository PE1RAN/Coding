// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "unit_test_framework.h"
#include <sstream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_insertion) {
    // Create a Human player
    Player* human = Player_factory("NotRobot", "Human");

    // Print the player using the stream insertion operator
    ostringstream oss1;
    oss1 << *human;

    // Verify that the output is the player's name
    ASSERT_EQUAL(oss1.str(), "NotRobot");

    // Create a Simple player
    Player* alice = Player_factory("Alice", "Simple");

    // Print the player using the stream insertion operator
    ostringstream oss2;
    oss2 << *alice;
    ASSERT_EQUAL(oss2.str(), "Alice");

    // Clean up players that were created using Player_factory()
    delete human;
    delete alice;
}

TEST(test_simple_player_make_trump) {
    // Bob's hand
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(NINE, SPADES));
    bob->add_card(Card(TEN, SPADES));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, SPADES));
    bob->add_card(Card(ACE, SPADES));

    // Bob makes tump
    Card nine_spades(NINE, SPADES);
    Suit trump;
    bool orderup = bob->make_trump(
        nine_spades,    // Upcard
        true,           // Bob is also the dealer
        1,              // First round
        trump           // Suit ordered up (if any)
    );

    // Verify Bob's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, SPADES);

    delete bob;
}

TEST(test_simple_player_lead_card) {
    // Bob's hand
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(NINE, SPADES));
    bob->add_card(Card(TEN, SPADES));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, SPADES));
    bob->add_card(Card(ACE, SPADES));

    // Bob adds a card to his hand and discards one card
    bob->add_and_discard(
        Card(NINE, HEARTS) // upcard
    );

    // Bob leads
    Card card_led = bob->lead_card(HEARTS);

    // Verify the card Bob selected to lead
    Card ace_spades(ACE, SPADES);
    ASSERT_EQUAL(card_led, ace_spades); //check led card

    delete bob;
}

TEST(test_simple_player_play_card) {
    // Bob's hand
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(NINE, SPADES));
    bob->add_card(Card(TEN, SPADES));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, SPADES));
    bob->add_card(Card(ACE, SPADES));

    // Bob plays a card
    Card nine_diamonds(NINE, DIAMONDS);
    Card card_played = bob->play_card(
        nine_diamonds,  // Nine of Diamonds is led
        HEARTS    // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played, Card(NINE, SPADES));
    delete bob;
}

TEST(test2) {
    Player* alice = Player_factory("Alice", "Human");
    ASSERT_EQUAL("Alice", alice->get_name());
    delete alice;
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(NINE, DIAMONDS));
    bob->add_card(Card(TEN, HEARTS));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, DIAMONDS));
    bob->add_card(Card(ACE, SPADES));
    Card nine_spades(NINE, SPADES);
    Card nine_hearts(NINE, HEARTS);
    Suit trump;
    bool orderup = bob->make_trump(
        nine_spades,    // Upcard
        true,           // Bob is also the dealer
        1,              // First round
        trump           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, SPADES);
    Card nine_clubs(NINE, CLUBS);
    Suit trump1;
    bool orderup1 = bob->make_trump(
        nine_clubs,    // Upcard
        true,           // Bob is also the dealer
        1,              // First round
        trump1           // Suit ordered up (if any)
    );
    ASSERT_FALSE(orderup1);
    Card nine_diamonds(NINE, DIAMONDS);
    Suit trump2;
    bool orderup2 = bob->make_trump(
        nine_diamonds,    // Upcard
        true,           // Bob is also the dealer
        1,              // First round
        trump2           // Suit ordered up (if any)
    );
    ASSERT_FALSE(orderup2);
    Suit trump3;
    bool orderup3 = bob->make_trump(
        nine_spades,    // Upcard
        false,           // Bob is also the dealer
        1,              // First round
        trump3           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup3);
    ASSERT_EQUAL(trump3, SPADES);
    Suit trump4;
    bool orderup4 = bob->make_trump(
        nine_clubs,    // Upcard
        false,           // Bob is also the dealer
        1,              // First round
        trump4           // Suit ordered up (if any)
    );
    ASSERT_FALSE(orderup4);
    Suit trump5;
    bool orderup5 = bob->make_trump(
        nine_diamonds,    // Upcard
        false,           // Bob is also the dealer
        1,              // First round
        trump5           // Suit ordered up (if any)
    );
    ASSERT_FALSE(orderup5);
    Suit trump6;
    bool orderup6 = bob->make_trump(
        nine_spades,    // Upcard
        false,           // Bob is also the dealer
        2,              // First round
        trump6           // Suit ordered up (if any)
    );
    ASSERT_FALSE(orderup6);
    Suit trump7;
    bool orderup7 = bob->make_trump(
        nine_clubs,    // Upcard
        false,           // Bob is also the dealer
        2,              // First round
        trump7           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup7);
    ASSERT_EQUAL(trump7, SPADES);
    Suit trump8;
    bool orderup8 = bob->make_trump(
        nine_hearts,    // Upcard
        false,           // Bob is also the dealer
        2,              // First round
        trump8           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup8);
    ASSERT_EQUAL(trump8, DIAMONDS);
    Suit trump9;
    bool orderup9 = bob->make_trump(
        nine_spades,    // Upcard
        true,           // Bob is also the dealer
        2,              // First round
        trump9           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup9);
    ASSERT_EQUAL(trump9, CLUBS);
    Suit trump10;
    bool orderup10 = bob->make_trump(
        nine_clubs,    // Upcard
        true,           // Bob is also the dealer
        2,              // First round
        trump10           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup10);
    ASSERT_EQUAL(trump10, SPADES);
    Suit trump11;
    bool orderup11 = bob->make_trump(
        nine_diamonds,    // Upcard
        true,           // Bob is also the dealer
        2,              // First round
        trump11           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup11);
    ASSERT_EQUAL(trump11, HEARTS);
    Suit trump12;
    bool orderup12 = bob->make_trump(
        nine_hearts,    // Upcard
        true,           // Bob is also the dealer
        2,              // First round
        trump12           // Suit ordered up (if any)
    );
    ASSERT_TRUE(orderup12);
    ASSERT_EQUAL(trump12, DIAMONDS);
    delete bob;
}

TEST(test3) {
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(NINE, DIAMONDS));
    bob->add_card(Card(TEN, HEARTS));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, DIAMONDS));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(SPADES), Card(KING, DIAMONDS));
    bob->add_card(Card(NINE, DIAMONDS));
    ASSERT_EQUAL(bob->lead_card(CLUBS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(HEARTS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(DIAMONDS), Card(ACE, SPADES));
    delete bob;
}
TEST(test4) {
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(NINE, SPADES));
    bob->add_card(Card(TEN, SPADES));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(SPADES), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(CLUBS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(HEARTS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(DIAMONDS), Card(ACE, SPADES));
    delete bob;
}
TEST(test5) {
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(TEN, DIAMONDS));
    bob->add_card(Card(TEN, HEARTS));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, DIAMONDS));
    bob->add_card(Card(ACE, SPADES));
    bob->add_and_discard(Card(NINE, DIAMONDS));
    ASSERT_EQUAL(bob->lead_card(SPADES), Card(KING, DIAMONDS));
    bob->add_card(Card(NINE, DIAMONDS));
    ASSERT_EQUAL(bob->lead_card(CLUBS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(HEARTS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(DIAMONDS), Card(ACE, SPADES));
    delete bob;
}
TEST(test6) {
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(TEN, DIAMONDS));
    bob->add_card(Card(TEN, SPADES));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, SPADES));
    bob->add_card(Card(ACE, SPADES));
    bob->add_and_discard(Card(NINE, SPADES));
    ASSERT_EQUAL(bob->lead_card(SPADES), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(CLUBS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(HEARTS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(DIAMONDS), Card(ACE, SPADES));
    delete bob;
}
TEST(test7) {
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(TEN, DIAMONDS));
    bob->add_card(Card(TEN, SPADES));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(SPADES), Card(TEN, DIAMONDS));
    bob->add_card(Card(TEN, DIAMONDS));
    ASSERT_EQUAL(bob->lead_card(CLUBS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(HEARTS), Card(ACE, SPADES));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->lead_card(DIAMONDS), Card(ACE, SPADES));
    delete bob;
}
TEST(test8) {
    Player* bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(TEN, DIAMONDS));
    bob->add_card(Card(TEN, SPADES));
    bob->add_card(Card(QUEEN, SPADES));
    bob->add_card(Card(KING, DIAMONDS));
    bob->add_card(Card(ACE, SPADES));
    ASSERT_EQUAL(bob->play_card(Card(ACE, DIAMONDS), DIAMONDS), Card(KING, DIAMONDS));
    ASSERT_EQUAL(bob->play_card(Card(ACE, DIAMONDS), DIAMONDS), Card(TEN, DIAMONDS));
    bob->add_card(Card(KING, DIAMONDS));
    bob->add_card(Card(JACK, HEARTS));
    ASSERT_EQUAL(bob->play_card(Card(ACE, SPADES), DIAMONDS), Card(ACE, SPADES));
    ASSERT_EQUAL(bob->play_card(Card(ACE, CLUBS), DIAMONDS), Card(TEN, SPADES));
    delete bob;
}

// Add more tests here
TEST(test9) {
    Player* adi = Player_factory("adi", "Simple");
    Player* bob = Player_factory("bob", "Simple");
    Player* chi = Player_factory("chi", "Simple");
    Player* dyl = Player_factory("dyl", "Simple");
    //Pack pack;
    vector<Card> cards;
    for (int i = 0; i < 4; ++i) {
        for (int j = 7; j < 13; ++j) {
            cards.push_back(Card(Rank(j), Suit(i)));
        }
    }
    for (int i = 0; i < 3; ++i) bob->add_card(cards[i]);
    for (int i = 3; i < 5; ++i) chi->add_card(cards[i]);
    for (int i = 5; i < 8; ++i) dyl->add_card(cards[i]);
    for (int i = 8; i < 10; ++i) adi->add_card(cards[i]);
    for (int i = 10; i < 12; ++i) bob->add_card(cards[i]);
    for (int i = 12; i < 15; ++i) chi->add_card(cards[i]);
    for (int i = 15; i < 17; ++i) dyl->add_card(cards[i]);
    for (int i = 17; i < 20; ++i) adi->add_card(cards[i]);
    Suit trump;
    ASSERT_FALSE(bob->make_trump(Card(JACK, DIAMONDS), false, 1, trump));
    ASSERT_FALSE(chi->make_trump(Card(JACK, DIAMONDS), false, 1, trump));
    ASSERT_FALSE(dyl->make_trump(Card(JACK, DIAMONDS), false, 1, trump));
    ASSERT_FALSE(adi->make_trump(Card(JACK, DIAMONDS), true, 1, trump));
    ASSERT_TRUE(bob->make_trump(Card(JACK, DIAMONDS), false, 2, trump));
    ASSERT_EQUAL(trump, HEARTS);
    delete adi;
    delete bob;
    delete chi;
    delete dyl;
}

TEST(test10) {
    Player* adi = Player_factory("adi", "Simple");
    Player* bob = Player_factory("bob", "Simple");
    Player* chi = Player_factory("chi", "Simple");
    Player* dyl = Player_factory("dyl", "Simple");
    //Pack pack;
    vector<Card> cards;
    for (int i = 0; i < 4; ++i) {
        for (int j = 7; j < 13; ++j) {
            cards.push_back(Card(Rank(j), Suit(i)));
        }
    }
    for (int i = 0; i < 3; ++i) bob->add_card(cards[i]);
    for (int i = 3; i < 5; ++i) chi->add_card(cards[i]);
    for (int i = 5; i < 8; ++i) dyl->add_card(cards[i]);
    for (int i = 8; i < 10; ++i) adi->add_card(cards[i]);
    for (int i = 10; i < 12; ++i) bob->add_card(cards[i]);
    for (int i = 12; i < 15; ++i) chi->add_card(cards[i]);
    for (int i = 15; i < 17; ++i) dyl->add_card(cards[i]);
    for (int i = 17; i < 20; ++i) adi->add_card(cards[i]);
    Suit trump = HEARTS;
    ASSERT_EQUAL(bob->lead_card(trump), Card(JACK, SPADES));
    ASSERT_EQUAL(chi->play_card(Card(JACK, SPADES), trump), Card(KING, SPADES));
    ASSERT_EQUAL(dyl->play_card(Card(JACK, SPADES), trump), Card(ACE,SPADES));
    ASSERT_EQUAL(adi->play_card(Card(JACK, SPADES), trump), Card(NINE, DIAMONDS));
    ASSERT_EQUAL(dyl->lead_card(trump), Card(KING,CLUBS));
    ASSERT_EQUAL(adi->play_card(Card(KING,CLUBS), trump), Card(ACE,CLUBS));
    ASSERT_EQUAL(bob->play_card(Card(KING,CLUBS), trump), Card(NINE,SPADES));
    ASSERT_EQUAL(chi->play_card(Card(KING,CLUBS), trump), Card(JACK,CLUBS));
    ASSERT_EQUAL(adi->lead_card(trump), Card(TEN,DIAMONDS));
    ASSERT_EQUAL(bob->play_card(Card(TEN, DIAMONDS), trump), Card(TEN,SPADES));
    ASSERT_EQUAL(chi->play_card(Card(TEN, DIAMONDS), trump), Card(NINE,CLUBS));
    ASSERT_EQUAL(dyl->play_card(Card(TEN, DIAMONDS), trump), Card(QUEEN,CLUBS));
    ASSERT_EQUAL(adi->lead_card(trump), Card(JACK,HEARTS));
    ASSERT_EQUAL(bob->play_card(Card(JACK, HEARTS), trump), Card(ACE,HEARTS));
    ASSERT_EQUAL(chi->play_card(Card(JACK, HEARTS), trump), Card(TEN,CLUBS));
    ASSERT_EQUAL(dyl->play_card(Card(JACK, HEARTS), trump), Card(TEN,HEARTS));
    ASSERT_EQUAL(adi->lead_card(trump), Card(QUEEN,HEARTS));
    ASSERT_EQUAL(bob->play_card(Card(QUEEN, HEARTS), trump), Card(KING,HEARTS));
    ASSERT_EQUAL(chi->play_card(Card(QUEEN, HEARTS), trump), Card(QUEEN,SPADES));
    ASSERT_EQUAL(dyl->play_card(Card(QUEEN, HEARTS), trump), Card(NINE,HEARTS));
    delete adi;
    delete bob;
    delete chi;
    delete dyl;
}

TEST_MAIN()
