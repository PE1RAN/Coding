// Project identifier: 9504853406CBAC39EE89AA3AD238AA12CA198043
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <getopt.h>
#include <queue>
#include "P2random.h"

using namespace std;

class ZB{
    string name;
    uint32_t dis;
    uint32_t spd;
    uint32_t bld;
    uint32_t rnd = 1;
public:
    void ini(string n, uint32_t d, uint32_t s, uint32_t b){
        name = n;
        dis = d;
        spd = s;
        bld = b;
    }

    void update(){
        if(bld != 0){
            rnd++;
            dis = spd > dis ? 0 : dis - spd;
        }
    }

    void getShoot(uint32_t n){
        bld -= n;
    }

    uint32_t getBld(){
        return bld;
    }

    bool isDisZero() const{
        return dis == 0;
    }

    uint32_t getETA() const{
        if(isDead()) return -1;
        else return uint32_t (dis / spd);
    }

    bool isDead() const{
        return bld == 0;
    }

    bool operator<(const ZB& zb){
        if(getETA() < zb.getETA()) return true;
        if(getETA() == zb.getETA() && bld < zb.bld) return true;
        if(getETA() == zb.getETA() && bld == zb.bld) return name < zb.name;
        return false;
    }

    void infoPrint(){
        cout << name << " (distance: " << dis << ", speed: " << spd << ", health: " << bld << ")\n";
    }

    string getName(){
        return name;
    }

    uint32_t getRnd(){
        return rnd;
    }

};

struct ShootSort{
    bool operator()(ZB *zb1, ZB *zb2) const{
        return !(*zb1 < *zb2);
    }
};

struct MaxFirstSort{
    bool operator()(ZB* deadZb1, ZB* deadZb2){
        if (deadZb1->getRnd() < deadZb2->getRnd()) return true;
        if (deadZb1->getRnd() == deadZb2->getRnd()) return deadZb1->getName() > deadZb2->getName();
        return false;
    }
};

struct nMaxFirstSort{
    bool operator()(ZB* deadZb1, ZB* deadZb2){
        if (deadZb1->getRnd() > deadZb2->getRnd()) return true;
        if (deadZb1->getRnd() == deadZb2->getRnd()) return deadZb1->getName() < deadZb2->getName();
        return false;
    }
};

struct MinFirstSort{
    bool operator()(ZB* deadZb1, ZB* deadZb2){
        if (deadZb1->getRnd() > deadZb2->getRnd()) return true;
        if (deadZb1->getRnd() == deadZb2->getRnd()) return deadZb1->getName() > deadZb2->getName();
        return false;
    }
};

struct nMinFirstSort{
    bool operator()(ZB* deadZb1, ZB* deadZb2){
        if (deadZb1->getRnd() < deadZb2->getRnd()) return true;
        if (deadZb1->getRnd() == deadZb2->getRnd()) return deadZb1->getName() < deadZb2->getName();
        return false;
    }
};


void statsticPrint(uint32_t N, deque<ZB*> &killedZB, deque<ZB*> &vec){
    if(N>0){
        int size = int(killedZB.size());
        int n = (int(N) < size ? int(N) : size);
        if(size>0){
            auto it = killedZB.begin();
            cout << "First zombies killed:\n";
            for(int i=0; i<n; i++){
                cout << (*it)->getName() << " " << i+1 << "\n";
                it++;
            }
            auto it2 = killedZB.rbegin();
            cout << "Last zombies killed:\n";
            for(int i=n; i>0; i--){
                cout << (*it2)->getName() << " " << i << "\n";
                it2++;
            }
//            cout << killedZB[size-n]->getName() << " " << 1 << "\n";
        }else{
            cout << "First zombies killed:\n";
            cout << "Last zombies killed:\n";
        }

        size = int(vec.size());
        n = (int(N) < size ? int(N) : size);

        cout << "Most active zombies:\n";
//        priority_queue<ZB*, vector<ZB*>, nMaxFirstSort> Mtemp(vec.begin(), vec.begin()+n);
//        MaxFirstSort m;
//        for(auto it = vec.begin()+n; it != vec.end(); it++){
//            if(m(Mtemp.top(),*it)){
//                Mtemp.pop();
//                Mtemp.push(*it);
//            }
//        }
        priority_queue<ZB*, vector<ZB*>, MaxFirstSort> MAQ(vec.begin(), vec.end());
//        for(int i=0; i<n; i++){
//            MAQ.push(Mtemp.top());
//            Mtemp.pop();
//        }
        for(int i=0; i<n;i++){
            cout << MAQ.top()->getName() << " " << MAQ.top()->getRnd() << "\n";
            MAQ.pop();
        }

        cout << "Least active zombies:\n";
//        priority_queue<ZB*, vector<ZB*>, nMinFirstSort> Ltemp(vec.begin(), vec.begin()+n);
//        MinFirstSort M;
//        for(auto it = vec.begin()+n; it != vec.end(); it++){
//            if(M(Ltemp.top(),*it)){
//                Ltemp.pop();
//                Ltemp.push(*it);
//            }
//        }
        priority_queue<ZB*, vector<ZB*>, MinFirstSort> LAQ(vec.begin(), vec.end());
//        for(int i=0; i<n; i++){
//            LAQ.push(Ltemp.top());
//            Ltemp.pop();
//        }
        for(int i=0; i<n;i++){
            cout << LAQ.top()->getName() << " " << LAQ.top()->getRnd() << "\n";
            LAQ.pop();
        }
    }
}

bool hasMode(string all, char spec){
    for(int i=0; i<int(all.size()); i++){
        if(all[i] == spec) return true;
    }
    return false;
}

int main(int argc, char * argv[]) {
    uint32_t current_round, quiver_capacity, seed, mrd, mrs, mrh, N;
    string mode = "";
    current_round = 0;
    string temp;
    getline(cin, temp);
    cin.clear();
    cin.sync();
    cin >> temp >> quiver_capacity >> temp >> seed >> temp >> mrd >> temp >> mrs >> temp >> mrh;
    P2random::initialize(seed, mrd, mrs, mrh);

    uint32_t round_read, random_zb, named_zb;
    string newZB_name, killerZB_name;
    uint32_t newZB_dis, newZB_spd, newZB_bld;
    deque<ZB*> vec;
    deque<ZB*> killedZB;
    deque<uint32_t> lifetime;

    bool isfinished = false;
    bool iseaten = false;
    bool isskip = false;
    bool isMoreRound = true;

    // Read arg
    N = 0;
    opterr = false; // Let us handle all error output for command line options
    int choice;
    int option_index = 0;
    option long_options[] = {
            {"verbose", no_argument, nullptr, 'v'},
            {"statistics", required_argument, nullptr, 's'},
            {"median", no_argument, nullptr, 'm'},
            {"help", no_argument, nullptr, 'h'},
            { nullptr, 0, nullptr, '\0' }
    };

    while ((choice = getopt_long(argc, argv, "vs:mh", long_options, &option_index)) != -1) {
        switch (choice) {
            case 'h':
                cout << "help!\n";
                exit(0);

            case 'v':
                mode.push_back('v');
                break;

            case 's':
                mode.push_back('s');
                N = (atoi(optarg));
                break;

            case 'm':
                mode.push_back('m');
                break;

            default:
                cerr << "Unknown command line option\n" << flush;
                exit(1);
        } // switch
    } // while


    // Main loop
    while(!isfinished){
        if(!isskip){
            if(!(cin >> temp >> temp >> round_read)) isMoreRound = false;
        }
        // End print
        if(vec.size() == killedZB.size() && !isMoreRound){
            // TODO: message
            cout << "VICTORY IN ROUND " << current_round << "! " << killedZB.back()->getName() << " was the last zombie.\n";
            // TODO: Statistics output
            if(hasMode(mode, 's')){
                cout << "Zombies still active: " << vec.size() - killedZB.size() << "\n";
                statsticPrint(N, killedZB, vec);
            }
            break;
        }

        current_round++;
        if(hasMode(mode, 'v')) cout << "Round: " << current_round << "\n";

        // Update active zb
        if(!vec.empty()){
            if(hasMode(mode, 'v')){
                for(auto it = vec.begin(); it != vec.end(); ++it){
                    (*it)->update();
                    // TODO: Verbose print
                    if(!(*it)->isDead()){
                        cout << "Moved: ";
                        (*it)->infoPrint();
                    }
                    if((*it)->isDisZero()){
                        isfinished = true; // You are eaten
                        if(!iseaten) {
                            iseaten = true;
                            killerZB_name = (*it)->getName();
                        }
                    }
                }
            } else {
                for(auto it = vec.begin(); it != vec.end(); ++it){
                    (*it)->update();
                    if((*it)->isDisZero()){
                        isfinished = true; // You are eaten
                        if(!iseaten) {
                            iseaten = true;
                            killerZB_name = (*it)->getName();
                        }
                    }
                }
            }

        }

        if(iseaten){
            cout << "DEFEAT IN ROUND " << current_round << "! " << killerZB_name << " ate your brains!\n";
            if(hasMode(mode, 's')){
                cout << "Zombies still active: " << vec.size() - killedZB.size() << "\n";
                statsticPrint(N, killedZB, vec);
            }
            break;
        }

        // New zb appear
        if(round_read == current_round){  // If round not skip
            isskip = false;
            cin >> temp >> random_zb >> temp >> named_zb;
            // Add random zb
            if(hasMode(mode, 'v')){
                for (uint32_t i = 0; i < random_zb; ++i) {
                    newZB_name = P2random::getNextZombieName();
                    newZB_dis = P2random::getNextZombieDistance();
                    newZB_spd = P2random::getNextZombieSpeed();
                    newZB_bld = P2random::getNextZombieHealth();
                    ZB *zb = new ZB{};
                    zb->ini(newZB_name, newZB_dis, newZB_spd, newZB_bld);
                    // TODO: Verbose print
                    cout << "Created: ";
                    zb->infoPrint();
                    vec.push_back(zb);
                }
                // Add named zb
                for (uint32_t i = 0; i < named_zb; ++i) {
                    cin >> newZB_name >> temp >> newZB_dis >> temp >> newZB_spd >> temp >> newZB_bld;
                    ZB *zb = new ZB{};
                    zb->ini(newZB_name, newZB_dis, newZB_spd, newZB_bld);
                    // TODO: Verbose print
                    cout << "Created: ";
                    zb->infoPrint();
                    vec.push_back(zb);
                }
            }else {
                for (uint32_t i = 0; i < random_zb; ++i) {
                    newZB_name = P2random::getNextZombieName();
                    newZB_dis = P2random::getNextZombieDistance();
                    newZB_spd = P2random::getNextZombieSpeed();
                    newZB_bld = P2random::getNextZombieHealth();
                    ZB *zb = new ZB {};
                    zb->ini(newZB_name, newZB_dis, newZB_spd, newZB_bld);
                    vec.push_back(zb);
                }
                // Add named zb
                for (uint32_t i = 0; i < named_zb; ++i) {
                    cin >> newZB_name >> temp >> newZB_dis >> temp >> newZB_spd >> temp >> newZB_bld;
                    ZB *zb = new ZB {};
                    zb->ini(newZB_name, newZB_dis, newZB_spd, newZB_bld);
                    vec.push_back(zb);
                }
            }
        }else{
            isskip = true;
        }

        // Shoot zb
//        sort(vec.begin(), vec.end(), ShootSort);
        priority_queue<ZB*, vector<ZB*>, ShootSort> shootQ(vec.begin(),vec.end());
        uint32_t bullet_left = quiver_capacity;

        if(hasMode(mode, 'v')){
            while (bullet_left>0){
                if(shootQ.empty()) break;
                if(shootQ.top()->isDead()) break;
                if(shootQ.top()->getBld() <= bullet_left){ // top is dead
                    bullet_left -= shootQ.top()->getBld();
                    shootQ.top()->getShoot(shootQ.top()->getBld());
                    // TODO: Verbose print
                    cout << "Destroyed: ";
                    shootQ.top()->infoPrint();
                    killedZB.push_back(shootQ.top());
                    lifetime.push_back(shootQ.top()->getRnd());
                    shootQ.pop();
                }else{
                    shootQ.top()->getShoot(bullet_left);
                    bullet_left = 0;
                }
            }
        }else{
            while (bullet_left>0){
                if(shootQ.empty()) break;
                if(shootQ.top()->isDead()) break;
                if(shootQ.top()->getBld() <= bullet_left){ // top is dead
                    bullet_left -= shootQ.top()->getBld();
                    shootQ.top()->getShoot(shootQ.top()->getBld());
                    killedZB.push_back(shootQ.top());
                    lifetime.push_back(shootQ.top()->getRnd());
                    shootQ.pop();
                }else{
                    shootQ.top()->getShoot(bullet_left);
                    bullet_left = 0;
                }
            }
        }


        // TODO: Median print
        if(hasMode(mode, 'm')){
            if(!lifetime.empty()){
                cout << "At the end of round " << current_round << ", the median zombie lifetime is ";
                sort(lifetime.begin(), lifetime.end());
                if(lifetime.size() % 2 == 0){
                    int m = int(lifetime.size() / 2);
                    cout << int((lifetime[m] + lifetime[m-1]) / 2) << "\n";
                }else{
                    int m = int((lifetime.size()+1) / 2);
                    cout << lifetime[m-1] << "\n";
                }
            }
        }



    }

    while (!vec.empty()) {
        delete vec.front();
        vec.pop_front();
    }

    return 0;
}


