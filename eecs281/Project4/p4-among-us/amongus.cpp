// Project Identifier: 9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7

#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iomanip>
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
#include <stdio.h>

using namespace std;

struct room {
    int x;
    int y;
    int area;
};

void printHelp(char* argv[]) {
    cout << "Usage: " << argv[0] << " (-m|--mode) {MST|FASTTSP|OPTTSP} < *.txt | -h \n";
    cout << "Enjoy yourself :) \n";
} // printHelp()

int getMode(int argc, char* argv[]) {
    int mode = 0;
    string temp;
    // These are used with getopt_long()
    opterr = false; // Let us handle all error output for command line options
    int choice;
    int option_index = 0;
    option long_options[] = {
        // Fill in two lines, for the "mode" ('m') and
        // the "help" ('h') options.
        { "mode",        optional_argument, nullptr, 'm'  },
        { "help",        no_argument,       nullptr, 'h'  },
        { nullptr,       0,                 nullptr, '\0' }
    };

    // Fill in the double quotes, to match the mode and help options.
    while ((choice = getopt_long(argc, argv, "m::h",
        long_options, &option_index)) != -1) {
        switch (choice) {
        case 'h':
            printHelp(argv);
            exit(0);
        
        case 'm':
            if (optarg == NULL && optind < argc && argv[optind][0] != '-') {
                optarg = argv[optind++];
            }
            if (optarg == NULL) {
                cerr << "Error: No mode specified" << endl;
                exit(1);
            }
            temp = optarg;
            if (temp == "MST")
                mode = 1;
            else if (temp == "FASTTSP")
                mode = 2;
            else if (temp == "OPTTSP")
                mode = 3;
            else {
                cerr << "Error: Invalid mode" << endl;
                exit(1);
            }
            break;

        default:
            cerr << "Error: Invalid command line option" << endl;
            exit(1);

        } // switch
    } // while

    return mode;
} // getMode()

struct pable {
    bool isin;
    double dist;
    size_t prev;
};

double dist(room a, room b) {
    if (a.area * b.area != -1)
        return sqrt(((double)a.x - (double)b.x) * ((double)a.x - (double)b.x) + ((double)a.y - (double)b.y) * ((double)a.y - (double)b.y));
    else
        return numeric_limits<double>::max();
}

double Dist(room a, room b) {
    return sqrt(((double)a.x - (double)b.x) * ((double)a.x - (double)b.x) + ((double)a.y - (double)b.y) * ((double)a.y - (double)b.y));
}



void MST(vector<room>& rooms, size_t num) {
    vector<pable> prim(num, { false, numeric_limits<double>::max() , num });
    size_t current = 0;
    for (size_t i = 0; i < num; ++i) {
        prim[current].isin = true;
        for (size_t j = 0; j < num; ++j) {
            if (prim[j].isin == false) {
                double temp = dist(rooms[current], rooms[j]);
                if (prim[j].dist > temp) {
                    prim[j].dist = temp;
                    prim[j].prev = current;
                }
            }
        }
        double min = numeric_limits<double>::max();
        size_t next = num;
        for (size_t j = 0; j < num; ++j) {
            if (prim[j].isin == false && prim[j].dist < min) {
                min = prim[j].dist;
                next = j;
            }
        }
        if (next == num && i < num - 1) {
            cerr << "Cannot construct MST" << endl;
            exit(1);
        }
        current = next;
    }
    double total = 0;
    for (size_t i = 1; i < num; ++i) {
        total += prim[i].dist;
    }
    cout << total << "\n";
    for (size_t i = 1; i < num; ++i) {
        if (i < prim[i].prev)
            cout << i << ' ' << prim[i].prev << "\n";
        else
            cout << prim[i].prev << ' ' << i << "\n";
    }
}

void FASTTSP(vector<room>& rooms, size_t num) {
    vector<size_t> route;
    double length = 0;
    route.reserve(num);
    route.push_back(0);
    for (size_t i = 1; i < num; ++i) {
        double min = numeric_limits<double>::max();
        size_t pos = 0;
        for (size_t j = 0; j < route.size(); ++j) {
            if (j == route.size() - 1) {
                double change = Dist(rooms[i], rooms[route[j]]) + Dist(rooms[i], rooms[0]) - Dist(rooms[route[j]], rooms[0]);
                if (change < min) {
                    min = change;
                    pos = j + 1;
                }
            }
            else {
                double change = Dist(rooms[i], rooms[route[j]]) + Dist(rooms[i], rooms[route[j + 1]]) - Dist(rooms[route[j]], rooms[route[j + 1]]);
                if (change < min) {
                    min = change;
                    pos = j + 1;
                }
            }
        }
        route.insert(route.begin() + pos, i);
        length += min;
    }
    cout << length << '\n';
    for (size_t i = 0; i < num; ++i)
        cout << route[i] << ' ';
    cout << '\n';
}

class OPTTSP {
public:
    OPTTSP(vector<room> rooms, size_t num) {
        siz = num;
        curLen = 0;
        bound = 0;
        dis.resize(num);
        for (size_t i = 0; i < num; ++i) {
            dis[i].reserve(num);
            for (size_t j = 0; j < num; ++j)
                dis[i].push_back(Dist(rooms[i], rooms[j]));
        }
        path.reserve(num);
        for (size_t i = 0; i < num; ++i)
            path.push_back(i);
    }
    void run2print() {
        fast();
        genPerms(1);
        cout << bound << '\n';
        for (size_t i = 0; i < siz; ++i)
            cout << opt[i] << ' ';
        cout << '\n';
    }
private:
    void fast() {
        opt.reserve(siz);
        opt.push_back(0);
        for (size_t i = 1; i < siz; ++i) {
            double min = numeric_limits<double>::max();
            size_t pos = 0;
            for (size_t j = 0; j < opt.size(); ++j) {
                if (j == opt.size() - 1) {
                    double change = dis[i][opt[j]] + dis[i][0] - dis[opt[j]][0];
                    if (change < min) {
                        min = change;
                        pos = j + 1;
                    }
                }
                else {
                    double change = dis[i][opt[j]] + dis[i][opt[j + 1]] - dis[opt[j]][opt[j + 1]];
                    if (change < min) {
                        min = change;
                        pos = j + 1;
                    }
                }
            }
            opt.insert(opt.begin() + pos, i);
            bound += min;
        }
    }
    bool promising(size_t permLength) {
        bool promise = true;
        double side1 = side(permLength);
        double side2 = edis(permLength);
        double mstCost = mst(permLength);
        double total = side1 + side2 + mstCost + curLen;
        if (total > bound)
            promise = false;

        /*for (size_t i = 0; i < path.size(); ++i)
            cerr << setw(2) << path[i] << ' ';
        cerr << setw(4) << permLength << setw(10) << curLen;
        cerr << setw(10) << side1 << setw(10) << side2;
        cerr << setw(10) << mstCost << setw(10) << total << "  " << promise << '\n';*/

        return promise;
    }
    void genPerms(size_t permLength) {
        if (permLength == path.size()) {
            if (curLen + dis[path[0]][path[siz - 1]] < bound) {
                bound = curLen + dis[path[0]][path[siz - 1]];
                opt = path;
            }
            return;
        }  // if ..complete path

        if (!promising(permLength)) {
            return;
        }  // if ..not promising

        for (size_t i = permLength; i < path.size(); ++i) {
            swap(path[permLength], path[i]);
            curLen += dis[path[permLength - 1]][path[permLength]];
            genPerms(permLength + 1);
            curLen -= dis[path[permLength - 1]][path[permLength]];
            swap(path[permLength], path[i]);
        }  // for ..unpermuted elements
    }
    double mst(size_t permLength) {
        vector<pable> prim(siz, { false, numeric_limits<double>::max() , siz });
        size_t current = path[permLength];
        for (size_t i = permLength; i < siz; ++i) {
            prim[current].isin = true;
            for (size_t j = permLength; j < siz; ++j) {
                if (prim[path[j]].isin == false) {
                    if (prim[path[j]].dist > dis[current][path[j]]) {
                        prim[path[j]].dist = dis[current][path[j]];
                        prim[path[j]].prev = current;
                    }
                }
            }
            double min = numeric_limits<double>::max();
            size_t next = siz;
            for (size_t j = permLength; j < siz; ++j) {
                if (prim[path[j]].isin == false && prim[path[j]].dist < min) {
                    min = prim[path[j]].dist;
                    next = path[j];
                }
            }
            current = next;
        }
        double total = 0;
        for (size_t i = permLength + 1; i < siz; ++i) {
            total += prim[path[i]].dist;
        }
        return total;
    }
    double side(size_t permLength) {
        double side1 = numeric_limits<double>::max();
        for (size_t i = permLength; i < siz; ++i) {
            if (dis[path[permLength - 1]][path[i]] < side1)
                side1 = dis[path[permLength - 1]][path[i]];
        }
        return side1;
    }
    double edis(size_t permLength) {
        double side2 = numeric_limits<double>::max();
        for (size_t i = permLength; i < siz; ++i) {
            if (dis[path[0]][path[i]] < side2)
                side2 = dis[path[0]][path[i]];
        }
        return side2;
    }
    vector<vector<double>> dis;
    vector<size_t> path;
    vector<size_t> opt;
    size_t siz;
    double curLen;
    double bound;
};


int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(2);

    cerr << fixed << showpoint << setprecision(2);

    int mode = getMode(argc, argv);

    size_t num;
    cin >> num;
    vector<room> rooms;
    rooms.reserve(num);
    for (size_t i = 0; i < num; ++i) {
        int x;
        int y;
        int area = 1;
        cin >> x >> y;
        if (x * y == 0 && x <= 0 && y <= 0)
            area = 0;
        else if (x < 0 && y < 0)
            area = -1;
        rooms.push_back({ x, y, area });
    }

    if (mode == 1)
        MST(rooms, num);
    else if (mode == 2)
        FASTTSP(rooms, num);
    else {
        OPTTSP myTSP(rooms, num);
        myTSP.run2print();
    }
    return 0;
}