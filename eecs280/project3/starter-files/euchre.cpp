// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "Pack.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct joke{
	Suit suit;
	int it;
};
struct jok {
	int t;
	int o;
};

class Game {
public:
	Game(vector<Player*> player, istream& is, bool mode, int aim) {
		pack = Pack(is);
		players.push_back(player[0]);
		players.push_back(player[1]);
		players.push_back(player[2]);
		players.push_back(player[3]);
		hand = 0;
		dealer = 0;
		shuffle = mode;
		score0 = 0;
		score1 = 0;
		aimming = aim;
	}
	void play() {
		//shuf();
		while (score0 < aimming && score1 < aimming) {
			shuf();
			play_hand();
			hand++;
		}
		if (score1 < aimming) {
			cout << *players[0] << " and " << *players[2] << " win!" << endl;
		}
		else {
			cout << *players[1] << " and " << *players[3] << " win!" << endl;
		}
	}

private:
	vector<Player*> players;
	Pack pack;
	int hand;
	bool shuffle;
    size_t dealer;
	int score0;
	int score1;
	int aimming;

	void shuf() {
		if (shuffle) pack.shuffle();
		else pack.reset();
	}
	void play_hand1() {
		cout << "Hand " << hand << endl;
		cout << *players[dealer] << " deals" << endl;
		for (int i = 0; i < 3; ++i) {
			players[(dealer + 1) % 4]->add_card(pack.deal_one());
		}
		for (int i = 0; i < 2; ++i) {
			players[(dealer + 2) % 4]->add_card(pack.deal_one());
		}
		for (int i = 0; i < 3; ++i) {
			players[(dealer + 3) % 4]->add_card(pack.deal_one());
		}
		for (int i = 0; i < 2; ++i) {
			players[(dealer + 4) % 4]->add_card(pack.deal_one());
		}
		for (int i = 0; i < 2; ++i) {
			players[(dealer + 1) % 4]->add_card(pack.deal_one());
		}
		for (int i = 0; i < 3; ++i) {
			players[(dealer + 2) % 4]->add_card(pack.deal_one());
		}
		for (int i = 0; i < 2; ++i) {
			players[(dealer + 3) % 4]->add_card(pack.deal_one());
		}
		for (int i = 0; i < 3; ++i) {
			players[(dealer + 4) % 4]->add_card(pack.deal_one());
		}
	}
	joke play_hand2() {
		Card upcard = pack.deal_one();
		cout << upcard << " turned up" << endl;
		Suit trump;
		bool orderup;
		int orderteam;
		for (int i = 1; i < 4; ++i) {
			orderup = players[(dealer + i) % 4]->make_trump(upcard, false, 1, trump);
			if (orderup) {
				cout << *players[(dealer + i) % 4] << " orders up " << trump
					<< endl << endl;
				players[dealer]->add_and_discard(upcard);
				orderteam = (dealer + i) % 2;
				break;}
			else cout << *players[(dealer + i) % 4] << " passes" << endl;}
		if (!orderup) {
			orderup = players[dealer]->make_trump(upcard, true, 1, trump);
			if (orderup) {
				cout << *players[dealer] << " orders up " << trump << endl << endl;
				players[dealer]->add_and_discard(upcard);
				orderteam = dealer % 2;}
			else cout << *players[dealer] << " passes" << endl;}
		if (!orderup) {
			for (int i = 1; i < 4; ++i) {
				orderup = players[(dealer + i) % 4]->make_trump(upcard, false, 2, trump);
				if (orderup) {
					cout << *players[(dealer + i) % 4] << " orders up "
						<< trump << endl << endl;
					orderteam = (dealer + i) % 2;
					break;}
				else cout << *players[(dealer + i) % 4] << " passes" << endl;}
			if (!orderup) {
				orderup = players[dealer]->make_trump(upcard, true, 2, trump);
				cout << *players[dealer] << " orders up " << trump << endl << endl;
				orderteam = dealer % 2;}}
		return { trump, orderteam };
	}
	jok play_hand3(joke fun) {
		Suit trump = fun.suit; int orderteam = fun.it;
		size_t leader = (dealer + 1) % 4; Card led; Card taking = led;
		Card playing; size_t winner = leader; int tricks0 = 0;
		for (int k = 0; k < 5; ++k) {
			leader = winner; led = players[leader]->lead_card(trump);
			taking = led; cout << led << " led by " << *players[leader] << endl;
			for (int i = 1; i < 4; ++i) {
				playing = players[(leader + i) % 4]->play_card(led, trump);
				cout << playing << " played by " << *players[(leader + i) % 4] << endl;
				if (Card_less(taking, playing, led, trump)) {
					taking = playing; winner = (leader + i) % 4;
				}
			}
			if (winner % 2 == 0) tricks0++;
			cout << *players[winner] << " takes the trick" << endl;
			cout << endl;
		}
		return { tricks0, orderteam };
	}
	void play_hand4(jok emmm){
		int tricks0 = emmm.t;
		int orderteam = emmm.o;
		if (tricks0 == 5 && orderteam == 0) {
			cout << *players[0] << " and " << *players[2] << " win the hand" << endl;
			cout << "march!" << endl; score0 += 2;}
		else if (tricks0 > 2 && orderteam == 0) {
			cout << *players[0] << " and " << *players[2] << " win the hand" << endl;
			score0++;}
		else if (tricks0 > 2 && orderteam == 1) {
			cout << *players[0] << " and " << *players[2] << " win the hand" << endl;
			cout << "euchred!" << endl; score0 += 2;}
		else if (tricks0 == 0 && orderteam == 1) {
			cout << *players[1] << " and " << *players[3] << " win the hand" << endl;
			cout << "march!" << endl; score1 += 2;}
		else if (tricks0 < 3 && orderteam == 1) {
			cout << *players[1] << " and " << *players[3] << " win the hand" << endl;
			score1++;}
		else if (tricks0 < 3 && orderteam == 0) {
			cout << *players[1] << " and " << *players[3] << " win the hand" << endl;
			cout << "euchred!" << endl; score1 += 2;}
	}
	void play_hand() {
		play_hand1();
		play_hand4(play_hand3(play_hand2()));
		cout << *players[0] << " and " << *players[2] << " have " 
			 << score0 << " points" << endl;
		cout << *players[1] << " and " << *players[3] << " have " 
			 << score1 << " points" << endl;
		cout << endl; dealer = (dealer + 1) % 4;
	}
};


struct temp {
	string n1;
	string n2;
	string n3;
	string n4;
	string t1;
	string t2;
	string t3;
	string t4;
};

int check(temp nt) {
	string name1 = nt.n1; string type1 = nt.t1;
	string name2 = nt.n2; string type2 = nt.t2;
	string name3 = nt.n3; string type3 = nt.t3;
	string name4 = nt.n4; string type4 = nt.t4;
	if (type1 != "Human" && type1 != "Simple") {
		cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
			<< "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
			<< "NAME4 TYPE4" << endl; return 1;
	}
	if (type2 != "Human" && type2 != "Simple") {
		cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
			<< "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
			<< "NAME4 TYPE4" << endl; return 1;
	}
	if (type3 != "Human" && type3 != "Simple") {
		cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
			<< "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
			<< "NAME4 TYPE4" << endl; return 1;
	}
	if (type4 != "Human" && type4 != "Simple") {
		cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
			<< "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
			<< "NAME4 TYPE4" << endl; return 1;
	}
	return 0;
}

void hmmm(temp nt, istream& is, int aim, bool shuffle) {
	cout << endl;
	string name1 = nt.n1; string type1 = nt.t1;
	string name2 = nt.n2; string type2 = nt.t2;
	string name3 = nt.n3; string type3 = nt.t3;
	string name4 = nt.n4; string type4 = nt.t4;
	Player* p1 = Player_factory(name1, type1);
	Player* p2 = Player_factory(name2, type2);
	Player* p3 = Player_factory(name3, type3);
	Player* p4 = Player_factory(name4, type4);
	vector<Player*> player;
	player.push_back(p1); player.push_back(p2);
	player.push_back(p3); player.push_back(p4);
	Game game = Game(player, is, shuffle, aim); game.play();
	delete p1; delete p2;
	delete p3; delete p4;
}

//REQUIRES some constrains
//EFFECTS main function
//NOTES enjoy!
int main(int argc, char* argv[]) {
	if (argc != 12) {
		cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
			 << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
			 << "NAME4 TYPE4" << endl; return 1; }
	int aim = atoi(argv[3]);
	if (aim < 1 || aim > 100) {
		cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
			 << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
			 << "NAME4 TYPE4" << endl; return 1; }
	bool shuffle = false; if (argv[2] == string("shuffle"))  shuffle = true;
	else if (argv[2] != string("noshuffle")) {
		cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
			 << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
			 << "NAME4 TYPE4" << endl; return 1;}
	string name1 = argv[4]; 
	string type1 = argv[5];
	string name2 = argv[6]; 
	string type2 = argv[7];
	string name3 = argv[8]; 
	string type3 = argv[9];
	string name4 = argv[10]; 
	string type4 = argv[11];
	temp nt = { name1, name2, name3, name4, type1, type2, type3, type4 };
	if (check(nt) == 1) return 1;
	ifstream is;
	is.open(argv[1]);
	if (!is) { cout << "Error opening " << argv[1] << endl; return 1; }
	for (int i = 0; i < 12; ++i) cout << argv[i] << " "; 
	hmmm(nt, is, aim, shuffle);
	return 0;
}