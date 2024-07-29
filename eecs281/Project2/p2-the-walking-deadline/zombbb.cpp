// Project identifier: 9504853406CBAC39EE89AA3AD238AA12CA198043

#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <getopt.h>
#include "P2random.h"

using namespace std;

struct zombie {
    string name;
    uint32_t dist;
    uint32_t speed;
    uint32_t heal;
    uint32_t act;
};


void printHelp(char* argv[]) {
    cout << "Usage: " << argv[0] << " (-v) (-s <num>) (-m) < *.txt | -h \n";
    cout << "Enjoy yourself :) \n";
} // printHelp()

size_t getMode(int argc, char* argv[]) {
    size_t mode = 0;
    size_t isV = 0;
    size_t isS = 0;
    size_t isM = 0;

    // These are used with getopt_long()
    opterr = false; // Let us handle all error output for command line options
    int choice;
    int option_index = 0;
    option long_options[] = {
        // Fill in two lines, for the "mode" ('m') and
        // the "help" ('h') options.
        { "verbose",     no_argument,       nullptr, 'v'  },
        { "statistics",  required_argument, nullptr, 's'  },
        { "median",      no_argument,       nullptr, 'm'  },
        { "help",        no_argument,       nullptr, 'h'  },
        { nullptr,       0,                 nullptr, '\0' }
    };

    // Fill in the double quotes, to match the mode and help options.
    while ((choice = getopt_long(argc, argv, "vs:mh",
        long_options, &option_index)) != -1) {
        switch (choice) {
        case 'h':
            printHelp(argv);
            exit(0);

        case 's':
            isS = stoi(optarg);
            break;

        case 'v':
            isV = 1;
            break;

        case 'm':
            isM = 1;
            break;

        } // switch
    } // while

    mode = isV + 2 * isM + 5 * isS;

    return mode;
} // getMode()


class EDA{
public:
    bool operator() (zombie* a, zombie* b){
        if (a->dist / a->speed > b->dist / b->speed)
            return 1;
        else if (a->dist / a->speed == b->dist / b->speed) {
            if (a->heal > b->heal)
                return 1;
            else if (a->heal == b->heal) {
                if (a->name > b->name)
                    return 1;
            }
        }

        return 0;
    }       
};

/*class minAct {
public:
    bool operator() (zombie* a, zombie* b) {
        if (a->act > b->act)
            return 1;
        else if (a->act == b->act)
            return a->name > b->name;

        return 0;
    }
};*/

bool minAct(zombie* a, zombie* b) {
    if (a->act < b->act)
        return 1;
    else if (a->act == b->act)
        return a->name < b->name;

    return 0;
}



/*class maxAct {
public:
    bool operator() (zombie* a, zombie* b) {
        if (a->act < b->act)
            return 1;
        else if (a->act == b->act)
            return a->name > b->name;

        return 0;
    }
};*/

bool maxAct(zombie* a, zombie* b) {
    if (a->act > b->act)
        return 1;
    else if (a->act == b->act)
        return a->name < b->name;

    return 0;
}


void readCoef(uint32_t& capacity, uint32_t& seed, uint32_t& maxdist, uint32_t& maxspeed, uint32_t& maxheal) {
    string abandon;
    getline(cin, abandon);
    cin >> abandon >> capacity;
    cin >> abandon >> seed;
    cin >> abandon >> maxdist;
    cin >> abandon >> maxspeed;
    cin >> abandon >> maxheal;
}

void battle(uint32_t capacity, priority_queue<zombie*, vector<zombie*>, EDA>& defense, deque<zombie*>& deadZombies) {

    for (uint32_t i = 0; i < capacity; ++i) {
        if (defense.empty())
            return;
        //if (defense.size() == 1)
        //    last = *defense.top();
        defense.top()->heal--;
        if (defense.top()->heal == 0) {
            //cout << "Destroyed: " << defense.top()->name << " (distance: " << defense.top()->dist
            //     << ", speeed: " << defense.top()->speed << ", health: " << defense.top()->heal << ")\n";
            deadZombies.push_back(defense.top());
            defense.pop();
            //Created: paoletti0 (distance: 25, speed: 20, health: 1)
        }
    }
}

void battle_v(uint32_t capacity, priority_queue<zombie*, vector<zombie*>, EDA>& defense, deque<zombie*>& deadZombies) {

    for (uint32_t i = 0; i < capacity; ++i) {
        if (defense.empty())
            return;
        //if (defense.size() == 1)
        //    last = *defense.top();
        defense.top()->heal--;
        if (defense.top()->heal == 0) {
            cout << "Destroyed: " << defense.top()->name << " (distance: " << defense.top()->dist
                 << ", speed: " << defense.top()->speed << ", health: " << defense.top()->heal << ")\n";
            deadZombies.push_back(defense.top());
            defense.pop();
            //Created: paoletti0 (distance: 25, speed: 20, health: 1)
        }
    }
}

void eraseZombies(deque<zombie*>& zombies) {
    /*auto it = zombies.end();
    while (it != zombies.begin()) {
        --it;
        if ((*it)->heal == 0)
            zombies.erase(it);
    }*/
    //if (zombies.front()->heal == 0)
    //    zombies.pop_front();
    /*for (auto it = zombies.begin(); it != zombies.end(); ++it) {
        //cout << "Checked: " << (*it)->name << " (distance: " << (*it)->dist
        //     << ", speeed: " << (*it)->speed << ", health: " << (*it)->heal << ")\n";
        if ((*it)->heal == 0) {
            
            //cout << "Checked: " << (*it)->name << " (distance: " << (*it)->dist
            //     << ", speeed: " << (*it)->speed << ", health: " << (*it)->heal << ")\n";
            zombies.erase(it);
            --it;
        }
    }*/
    size_t num = zombies.size();
    for (size_t i = 0; i < num; ++i) {
        if (zombies.front()->heal != 0)
            zombies.push_back(zombies.front());
        //else
        //    deadZombies.push_back(zombies.front());
        zombies.pop_front();
    }
}

void createZombies(const P2random &generator, deque<zombie*>& zombies,
                   priority_queue<zombie*, vector<zombie*>, EDA>& defense) {
    string abandon;
    int unnamed = 0;
    int named = 0;
    cin >> abandon >> unnamed;
    cin >> abandon >> named;
    for (int i = 0; i < unnamed; ++i) {
        zombie* temp = new zombie;
        *temp = { generator.getNextZombieName(), generator.getNextZombieDistance(),
                             generator.getNextZombieSpeed(), generator.getNextZombieHealth(), 1 };
        //cout << "Created: " << temp->name << " (distance: " << temp->dist << ", speeed: "
        //     << temp->speed << ", health: " << temp->heal << ")\n";
        zombies.push_back(temp);
        defense.push(temp);
        //Created: paoletti0 (distance: 25, speed: 20, health: 1)
    }
    for (int j = 0; j < named; ++j) {
        string name;
        uint32_t dist;
        uint32_t speed;
        uint32_t heal;
        cin >> name >> abandon >> dist >> abandon >> speed >> abandon >> heal;
        zombie* temp = new zombie;
        *temp = { name, dist, speed, heal, 1 };
        //cout << "Created: " << temp->name << " (distance: " << temp->dist << ", speeed: "
        //     << temp->speed << ", health: " << temp->heal << ")\n";
        zombies.push_back(temp);
        defense.push(temp);
    }
}

void createZombies_v(const P2random& generator, deque<zombie*>& zombies,
                     priority_queue<zombie*, vector<zombie*>, EDA>& defense) {
    string abandon;
    int unnamed = 0;
    int named = 0;
    cin >> abandon >> unnamed;
    cin >> abandon >> named;
    for (int i = 0; i < unnamed; ++i) {
        zombie* temp = new zombie;
        *temp = { generator.getNextZombieName(), generator.getNextZombieDistance(),
                             generator.getNextZombieSpeed(), generator.getNextZombieHealth(), 1 };
        cout << "Created: " << temp->name << " (distance: " << temp->dist << ", speed: "
            << temp->speed << ", health: " << temp->heal << ")\n";
        zombies.push_back(temp);
        defense.push(temp);
        //Created: paoletti0 (distance: 25, speed: 20, health: 1)
    }
    for (int j = 0; j < named; ++j) {
        string name;
        uint32_t dist;
        uint32_t speed;
        uint32_t heal;
        cin >> name >> abandon >> dist >> abandon >> speed >> abandon >> heal;
        zombie* temp = new zombie;
        *temp = { name, dist, speed, heal, 1 };
        cout << "Created: " << temp->name << " (distance: " << temp->dist << ", speed: "
            << temp->speed << ", health: " << temp->heal << ")\n";
        zombies.push_back(temp);
        defense.push(temp);
    }
}

int moveZombies(deque<zombie*>& zombies) {
    bool live = 1;
    int killer;
    for (size_t i = 0; i < zombies.size(); ++i) {
        if (zombies[i]->speed > zombies[i]->dist)
            zombies[i]->dist = 0;
        else 
            zombies[i]->dist = zombies[i]->dist - zombies[i]->speed;
        if (live == 1 && zombies[i]->dist == 0) {
            live = 0;
            killer = (int)i;
        }
        
        //cout << "Moved: " << zombies[i]->name << " (distance: " << zombies[i]->dist 
        //     << ", speeed: " << zombies[i]->speed << ", health: " << zombies[i]->heal << ")\n";

        zombies[i]->act = zombies[i]->act + 1;
    }
    //Moved: FoxMcCloud (distance: 0, speed: 10, health: 100)
    if (live == 1)
        return -1;
    else
        return killer;
}

int moveZombies_v(deque<zombie*>& zombies) {
    bool live = 1;
    int killer;
    for (size_t i = 0; i < zombies.size(); ++i) {
        if (zombies[i]->speed > zombies[i]->dist)
            zombies[i]->dist = 0;
        else
            zombies[i]->dist = zombies[i]->dist - zombies[i]->speed;
        if (live == 1 && zombies[i]->dist == 0) {
            live = 0;
            killer = (int)i;
        }

        cout << "Moved: " << zombies[i]->name << " (distance: " << zombies[i]->dist
            << ", speed: " << zombies[i]->speed << ", health: " << zombies[i]->heal << ")\n";

        zombies[i]->act = zombies[i]->act + 1;
    }
    //Moved: FoxMcCloud (distance: 0, speed: 10, health: 100)
    if (live == 1)
        return -1;
    else
        return killer;
}

void findMedian(deque<zombie*>& deadZombies, int round) {
    if (deadZombies.empty()) {
        //cout << "At the end of round " << round << ", the median zombie lifetime is 0\n";
        return;
    }
    vector<uint32_t> lifetime;
    lifetime.resize(deadZombies.size());
    for (size_t i = 0; i < lifetime.size(); ++i) {
        lifetime[i] = deadZombies[i]->act;
    }
    sort(lifetime.begin(), lifetime.end());
    size_t median;
    if (lifetime.size() % 2 == 1)
        median = lifetime[lifetime.size() / 2];
    else
        median = (lifetime[lifetime.size() / 2 - 1] +lifetime[lifetime.size() / 2]) / 2;
    cout << "At the end of round " << round << ", the median zombie lifetime is " << median << "\n";
    //At the end of round 1, the median zombie lifetime is 1
}

void statistics(size_t mode, deque<zombie*>& deadZombies, deque<zombie*>& zombies) {
    if (mode / 5 > 0) {
        cout << "Zombies still active: " << zombies.size() << "\n";
        size_t stats = mode / 5;
        if (stats > deadZombies.size())
            stats = deadZombies.size();
        cout << "First zombies killed:\n";
        for (size_t i = 0; i < stats; ++i)
            cout << deadZombies[i]->name << " " << i + 1 << "\n";
        cout << "Last zombies killed:\n";
        for (size_t i = stats; i > 0; --i)
            cout << deadZombies[i - stats + deadZombies.size() - 1]->name << " " << i << "\n";
        //First zombies killed:
        //FoxMcCloud 1
        vector<zombie*> active;
        for (size_t i = 0; i < zombies.size(); ++i)
            active.push_back(zombies[i]);
        for (size_t i = 0; i < deadZombies.size(); ++i)
            active.push_back(deadZombies[i]);
        stats = mode / 5;
        if (stats > active.size())
            stats = active.size();
        sort(active.begin(), active.end(), maxAct);
        cout << "Most active zombies:\n";
        for (size_t i = 0; i < stats; ++i)
            cout << active[i]->name << " " << active[i]->act << "\n";
        sort(active.begin(), active.end(), minAct);
        cout << "Least active zombies:\n";
        for (size_t i = 0; i < stats; ++i)
            cout << active[i]->name << " " << active[i]->act << "\n";
    }
}

void freeZombies(deque<zombie*>& deadZombies, deque<zombie*>& zombies) {
    while (!deadZombies.empty()) {
        zombie* victim = deadZombies.back();
        deadZombies.pop_back();
        delete victim;
    }
    while (!zombies.empty()) {
        zombie* victim = zombies.back();
        zombies.pop_back();
        delete victim;
    }
}


int main(int argc, char* argv[]) {
    size_t mode = getMode(argc, argv);

    uint32_t capacity = 0;
    uint32_t seed = 0;
    uint32_t maxdist = 0;
    uint32_t maxspeed = 0;
    uint32_t maxheal = 0;
    readCoef(capacity, seed, maxdist, maxspeed, maxheal);

    P2random generator;
    generator.initialize(seed, maxdist, maxspeed, maxheal); 

    deque<zombie*> zombies;
    deque<zombie*> deadZombies;
    //priority_queue<zombie*, vector<zombie*>, isDead> zombies;
    priority_queue<zombie*, vector<zombie*>, EDA> defense;

    string abandon;
    int round = 0;
    int killer = -1;
    //zombie last;

    if (mode % 5 % 2 == 1) {
        while (cin >> abandon) {
            round++;
            cout << "Round: " << round << "\n";
            killer = moveZombies_v(zombies);
            if (killer != -1) {
                cout << "DEFEAT IN ROUND " << round << "! " << zombies[killer]->name << " ate your brains!\n";
                statistics(mode, deadZombies, zombies);
                freeZombies(deadZombies, zombies);
                return 0;
            }
            int newRound;
            cin >> abandon >> newRound;
            if (newRound > round) {
                while (round != newRound) {
                    battle_v(capacity, defense, deadZombies);
                    eraseZombies(zombies);
                    if (mode % 5 > 1)
                        findMedian(deadZombies, round);
                    
                    round++;
                    cout << "Round: " << round << "\n";
                    killer = moveZombies_v(zombies);
                    if (killer != -1) {
                        cout << "DEFEAT IN ROUND " << round << "! " << zombies[killer]->name << " ate your brains!\n";
                        statistics(mode, deadZombies, zombies);
                        freeZombies(deadZombies, zombies);
                        return 0;
                    }
                    //battle(capacity, defense, last);
                    //findMedian(allZombies, round);
                    //eraseZombies(zombies);

                }
            }
            createZombies_v(generator, zombies, defense);
            battle_v(capacity, defense, deadZombies);
            eraseZombies(zombies);
            if (mode % 5 > 1)
                findMedian(deadZombies, round);
        }
        while (!defense.empty()) {
            round++;
            cout << "Round: " << round << "\n";
            killer = moveZombies_v(zombies);
            if (killer != -1) {
                cout << "DEFEAT IN ROUND " << round << "! " << zombies[killer]->name << " ate your brains!\n";
                statistics(mode, deadZombies, zombies);
                freeZombies(deadZombies, zombies);
                return 0;
            }
            battle_v(capacity, defense, deadZombies);
            eraseZombies(zombies);
            if (mode % 5 > 1)
                findMedian(deadZombies, round);
        }
    }
    else {
        while (cin >> abandon) {
            round++;
            //cout << "Round: " << round << "\n";
            killer = moveZombies(zombies);
            if (killer != -1) {
                cout << "DEFEAT IN ROUND " << round << "! " << zombies[killer]->name << " ate your brains!\n";
                statistics(mode, deadZombies, zombies);
                freeZombies(deadZombies, zombies);
                return 0;
            }
            int newRound;
            cin >> abandon >> newRound;
            if (newRound > round) {
                while (round != newRound) {
                    battle(capacity, defense, deadZombies);
                    eraseZombies(zombies);
                    if (mode % 5 > 1)
                        findMedian(deadZombies, round);
                    round++;
                    //cout << "Round: " << round << "\n";
                    killer = moveZombies(zombies);
                    if (killer != -1) {
                        cout << "DEFEAT IN ROUND " << round << "! " << zombies[killer]->name << " ate your brains!\n";
                        statistics(mode, deadZombies, zombies);
                        freeZombies(deadZombies, zombies);
                        return 0;
                    }
                    //battle(capacity, defense, last);
                    //findMedian(allZombies, round);
                    //eraseZombies(zombies);

                }
            }
            createZombies(generator, zombies, defense);
            battle(capacity, defense, deadZombies);
            eraseZombies(zombies);
            if (mode % 5 > 1)
                findMedian(deadZombies, round);
        }
        while (!defense.empty()) {
            round++;
            //cout << "Round: " << round << "\n";
            killer = moveZombies(zombies);
            if (killer != -1) {
                cout << "DEFEAT IN ROUND " << round << "! " << zombies[killer]->name << " ate your brains!\n";
                statistics(mode, deadZombies, zombies);
                freeZombies(deadZombies, zombies);
                return 0;
            }
            battle(capacity, defense, deadZombies);
            eraseZombies(zombies);
            if (mode % 5 > 1)
                findMedian(deadZombies, round);
        }
    }

    cout << "VICTORY IN ROUND " << round << "! " << deadZombies.back()->name << " was the last zombie.\n";
    //VICTORY IN ROUND <ROUND_NUMBER>! <NAME_OF_LAST_ZOMBIE_KILLED> was the last zombie.
    statistics(mode, deadZombies, zombies);
    freeZombies(deadZombies, zombies);




    return 0;
}
