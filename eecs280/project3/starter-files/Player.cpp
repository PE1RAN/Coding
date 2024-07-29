// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Simple: public Player {
public:
    Simple(string name_) {
        name = name_;
    }
    const string& get_name() const {
        return name;
    }
    void add_card(const Card& c) {
        cards.push_back(c);
        sort(cards.begin(), cards.end());
    }
    bool make_trump(const Card& upcard, bool is_dealer,
                    int round, Suit& order_up_suit) const {
        if (round == 1) {
            int count = 0;
            for (size_t i = 0; i < 5; ++i) {
                if (cards[i].is_face_or_ace() && cards[i].is_trump(upcard.get_suit())) {
                    count++;
                }
            }
            if (count > 1) {
                order_up_suit = upcard.get_suit();
                return true;
            }
        }
        else {
            if (is_dealer) {
                order_up_suit = Suit_next(upcard.get_suit());
                return true;
            }
            int count = 0;
            for (size_t i = 0; i < 5; ++i) {
                if (cards[i].is_face_or_ace() && 
                    cards[i].is_trump(Suit_next(upcard.get_suit()))) {
                    count++;
                }
            }
            if (count > 0) {
                order_up_suit = Suit_next(upcard.get_suit());
                return true;
            }
        }
        return false;
    }
    void add_and_discard(const Card& upcard) {
        Card temp = upcard;
        size_t index = 5;
        for (size_t i = 0; i < 5; ++i) {
            if (Card_less(cards[i], temp, upcard.get_suit())) {
                index = i;
                temp = cards[i];
            }
        }
        if (index < 5) {
            cards[index] = upcard;
            sort(cards.begin(), cards.end());
        }
    }
    Card lead_card(Suit trump) {
        size_t index = 5;
        for (size_t i = 0; i < cards.size(); ++i) {
            if (!cards[i].is_trump(trump)) {
                index = i;
                break;
            }
        }
        if (index == 5) {
            index = 0;
            for (size_t i = 1; i < cards.size(); ++i) {
                if (Card_less(cards[index], cards[i], trump)) {
                    index = i;
                }
            }
        }
        else {
            for (size_t i = index + 1; i < cards.size(); ++i) {
                if (Card_less(cards[index], cards[i], trump) && 
                    !cards[i].is_trump(trump)) {
                    index = i;
                }
            }
        }
        Card result = cards[index];
        cards.erase(cards.begin() + index);
        return result;
    }
    Card play_card(const Card& led_card, Suit trump) {
        size_t index = cards.size();
        for (size_t i = 0; i < cards.size(); ++i) {
            if (cards[i].get_suit(trump) == led_card.get_suit(trump)) {
                index = i;
                break;
            }
        }
        if (index == cards.size()) {
            index = 0;
            for (size_t i = 1; i < cards.size(); ++i) {
                if (Card_less(cards[i], cards[index], led_card, trump)) {
                    index = i;
                }
            }
        }
        else {
            for (size_t i = index + 1; i < cards.size(); ++i) {
                if (Card_less(cards[index], cards[i], led_card, trump) && 
                    cards[i].get_suit(trump) == led_card.get_suit(trump)) {
                    index = i;
                }
            }
        }
        Card result = cards[index];
        cards.erase(cards.begin() + index);
        return result;
    }
private:
    string name;
    vector<Card> cards;
};

class Human : public Player {
public:
    Human(string name_) {
        name = name_;
    }
    const string& get_name() const {
        return name;
    }
    void add_card(const Card& c) {
        cards.push_back(c);
        sort(cards.begin(), cards.end());
    }
    void print_hand() const {
        for (size_t i = 0; i < cards.size(); ++i)
            cout << "Human player " << name << "'s hand: "
            << "[" << i << "] " << cards[i] << "\n";
    }
    bool make_trump(const Card& upcard, bool is_dealer, 
                    int round, Suit& order_up_suit) const {
        print_hand();
        cout << "Human player " << name << ", please enter a suit, or \"pass\":\n";
        string decision;
        cin >> decision;
        if (decision != "pass") {
            Suit ordered_up = string_to_suit(decision);
            order_up_suit = ordered_up;
            return true;
        }
        return false;
    }
    void add_and_discard(const Card& upcard) {
        print_hand();
        cout << "Discard upcard: [-1]\n";
        cout << "Human player " << name << ", please select a card to discard:\n";
        int index;
        cin >> index;
        if (index != -1) {
            cards[index] = upcard;
            sort(cards.begin(), cards.end());
        }
    }
    Card lead_card(Suit trump) {
        print_hand();
        cout << "Human player " << name << ", please select a card:\n";
        size_t index;
        cin >> index;
        Card result = cards[index];
        cards.erase(cards.begin() + index);
        return result;
    }
    Card play_card(const Card& led_card, Suit trump) {
        print_hand();
        cout << "Human player " << name << ", please select a card:\n";
        size_t index;
        cin >> index;
        Card result = cards[index];
        cards.erase(cards.begin() + index);
        return result;
    }
private:
    string name;
    vector<Card> cards;
};

Player* Player_factory(const string& name, const string& strategy) {
    if (strategy == "Simple") {
        // The "new" keyword dynamically allocates an object.
        return new Simple(name);
    }
    else if (strategy == "Human") {
        return new Human(name);
    }
    return nullptr;
}

ostream& operator<<(std::ostream& os, const Player& p) {
    os << p.get_name();
    return os;
}
