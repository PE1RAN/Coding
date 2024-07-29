// Identifier: B99292359FFD910ED13A7E6C7F9705B8742F0D79

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


using namespace std;

struct pos {
    int x;
    int y;
    int z;
    int room;
    int row;
    int column;
    char op;
};

void printHelp(char* argv[]) {
    cout << "Usage: " << argv[0] << " [-q|-l -o M|L]|-h \n";
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
        { "output", required_argument, nullptr, 'o'  },
        { "stack",  no_argument,       nullptr, 's'  },
        { "queue",  no_argument,       nullptr, 'q'  },
        { "help",   no_argument,       nullptr, 'h'  },
        { nullptr,  0,                 nullptr, '\0' }
    };

    // Fill in the double quotes, to match the mode and help options.
    while ((choice = getopt_long(argc, argv, "sqho:", 
            long_options, &option_index)) != -1) {
        switch (choice) {
        case 'h':
            printHelp(argv);
            exit(0);

        case 's':
            if (mode > 0) {
                cerr << "Stack or queue can only be specified once" << endl;
                exit(1);
            } // if
            mode += 1;
            break;

        case 'q':
            if (mode > 0) {
                cerr << "Stack or queue can only be specified once" << endl;
                exit(1);
            } // if
            mode += 2;
            break;

        case 'o':
            temp = optarg;
            if (temp == "L")
                mode += 10;
            else if (temp == "M")
                mode += 0;
            else {
                cerr << "Unknown command line option" << endl;
                exit(1);
            }
            break;

        default:
            cerr << "Unknown command line option" << endl;
            exit(1);
        } // switch
    } // while

    if (mode == 0) {
        cerr << "Stack or queue must be specified" << endl;
        exit(1);
    } // if

    /*if (mode == 3 || mode == 13) {
        cerr << "Stack or queue can only be specified once" << endl;
        exit(1);
    } // if*/

    return mode;
} // getMode()

pos readM(vector<vector<vector<pos>>>& data, istream& is, int room, int size) {
    string abandon;
    char x;
    pos init = data[0][0][0];
    getline(is, abandon);
    for (int i = 0; i < room; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                is >> x;
                if (x == '/') {
                    getline(is, abandon);
                    k--;
                    continue;
                }
                if (x != '.' && x != '#' && x != '!' && x != 'S' && x != 'C' && 
                    x != '0' && x != '1' && x != '2' && x != '3' && x != '4' && 
                    x != '5' && x != '6' && x != '7' && x != '8' && x != '9') {
                    cerr << "Unknown map character" << endl;
                    exit(1);
                }
                data[i][j][k] = {i, j, k, -1, -1, -1, x};
                if (x == 'S') {
                    data[i][j][k].room = -2;
                    init = data[i][j][k];
                }

            }
        }
        getline(is, abandon);
    }
    return init;

}

pos readL(vector<vector<vector<pos>>>& data, istream& is, int room, int size) {
    for (int i = 0; i < room; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                data[i][j][k] = { i, j, k, -1, -1, -1, '.' };
            }
        }
    }
    char a, b, c, d, e, x;
    int i, j, k;
    string abandon;
    pos init = data[0][0][0];
    getline(is, abandon);
    while (is >> a) {
        if (a == '(') {
            is >> i >> b >> j >> c >> k >> d >> x >> e;
            if (i < 0 || i >= room) {
                cerr << "Invalid room number" << endl;
                exit(1);
            }
            if (j < 0 || j >= size) {
                cerr << "Invalid row number" << endl;
                exit(1);
            }
            if (k < 0 || k >= size) {
                cerr << "Invalid column number" << endl;
                exit(1);
            }
            if (x != '.' && x != '#' && x != '!' && x != 'S' && x != 'C' && 
                x != '0' && x != '1' && x != '2' && x != '3' && x != '4' && 
                x != '5' && x != '6' && x != '7' && x != '8' && x != '9') {
                cerr << "Unknown map character" << endl;
                exit(1);
            }
            data[i][j][k].op = x;
            if (x == 'S') {
                data[i][j][k].room = -2;
                init = data[i][j][k];
            }
        }
    }
    return init;
}

pos run(int room, int size, pos init, vector<vector<vector<pos>>>& data, 
        int mode) {
    deque<pos> stack;
    stack.push_back(init);
    pos now = init;
    pos end = { 0, 0, 0, -1, 0, 1, ' ' };
    while (!stack.empty()) {
        if (mode % 10 == 1) {
            now = stack.back();
            stack.pop_back();
        }
        else {
            now = stack.front();
            stack.pop_front();
        }
        int item = int(data[now.x][now.y][now.z].op) - 48;
        if (item < 10 && item > -1) {
            if (item < room && data[item][now.y][now.z].op != '!' && 
                data[item][now.y][now.z].op != '#' && 
                data[item][now.y][now.z].room == -1) {
                data[item][now.y][now.z].room = now.x;
                data[item][now.y][now.z].row = now.y;
                data[item][now.y][now.z].column = now.z;
                stack.push_back(data[item][now.y][now.z]);
                end.column++;
                if (data[item][now.y][now.z].op == 'C') {
                    end = data[item][now.y][now.z];
                    return end;
                }
            }
        }
        else {
            if (now.y > 0) {
                if (data[now.x][now.y - 1][now.z].room == -1 && 
                    data[now.x][now.y - 1][now.z].op != '!' && 
                    data[now.x][now.y - 1][now.z].op != '#') {
                    data[now.x][now.y - 1][now.z].room = now.x;
                    data[now.x][now.y - 1][now.z].row = now.y;
                    data[now.x][now.y - 1][now.z].column = now.z;
                    stack.push_back(data[now.x][now.y - 1][now.z]);
                    end.column++;
                    if (data[now.x][now.y - 1][now.z].op == 'C') {
                        end = data[now.x][now.y - 1][now.z];
                        return end;
                    }
                }
            }
            if (now.z < size - 1) {
                if (data[now.x][now.y][now.z + 1].room == -1 && 
                    data[now.x][now.y][now.z + 1].op != '!' && 
                    data[now.x][now.y][now.z + 1].op != '#') {
                    data[now.x][now.y][now.z + 1].room = now.x;
                    data[now.x][now.y][now.z + 1].row = now.y;
                    data[now.x][now.y][now.z + 1].column = now.z;
                    stack.push_back(data[now.x][now.y][now.z + 1]);
                    end.column++;
                    if (data[now.x][now.y][now.z + 1].op == 'C') {
                        end = data[now.x][now.y][now.z + 1];
                        return end;
                    }
                }
            }
            if (now.y < size - 1) {
                if (data[now.x][now.y + 1][now.z].room == -1 && 
                    data[now.x][now.y + 1][now.z].op != '!' && 
                    data[now.x][now.y + 1][now.z].op != '#') {
                    data[now.x][now.y + 1][now.z].room = now.x;
                    data[now.x][now.y + 1][now.z].row = now.y;
                    data[now.x][now.y + 1][now.z].column = now.z;
                    stack.push_back(data[now.x][now.y + 1][now.z]);
                    end.column++;
                    if (data[now.x][now.y + 1][now.z].op == 'C') {
                        end = data[now.x][now.y + 1][now.z];
                        return end;
                    }
                }
            }
            if (now.z > 0) {
                if (data[now.x][now.y][now.z - 1].room == -1 && 
                    data[now.x][now.y][now.z - 1].op != '!' && 
                    data[now.x][now.y][now.z - 1].op != '#') {
                    data[now.x][now.y][now.z - 1].room = now.x;
                    data[now.x][now.y][now.z - 1].row = now.y;
                    data[now.x][now.y][now.z - 1].column = now.z;
                    stack.push_back(data[now.x][now.y][now.z - 1]);
                    end.column++;
                    if (data[now.x][now.y][now.z - 1].op == 'C') {
                        end = data[now.x][now.y][now.z - 1];
                        return end;
                    } // if found
                } // if valid
            } // which direction
        } // if pipe
    } //while
    return end;
}


void writeM(vector<vector<vector<pos>>>& data, ostream& os, int room, 
            int size, pos init, pos end) {
    if (end.room == -1) {
        os << "No solution, " << end.column << " tiles discovered.";
        return;
    }
    os << "Start in room " << init.x << ", row " << init.y << ", column " 
       << init.z << "\n";
    while (end.room != -2) {
        if (end.room != end.x)
            data[end.room][end.row][end.column].op = 'p';
        else if (end.row == end.y - 1)
            data[end.room][end.row][end.column].op = 's';
        else if (end.row == end.y + 1)
            data[end.room][end.row][end.column].op = 'n';
        else if (end.column == end.z - 1)
            data[end.room][end.row][end.column].op = 'e';
        else
            data[end.room][end.row][end.column].op = 'w';
        end = data[end.room][end.row][end.column];
    }
    for (int i = 0; i < room; ++i) {
        os << "//castle room " << i << "\n";
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) 
                os << data[i][j][k].op;
            os << "\n";
        }
    }
}

void writeL(vector<vector<vector<pos>>>& data, ostream& os, pos end) {
    if (end.room == -1) {
        os << "No solution, " << end.column << " tiles discovered.\n";
        return;
    }
    os << "Path taken:\n";
    deque<pos> ivt;
    while (end.room != -2) {
        ivt.push_back(end);
        end = data[end.room][end.row][end.column];
    }
    while (!ivt.empty()) {
        char x;
        pos now = ivt.back();
        if (now.room != now.x)
            x = 'p';
        else if (now.row == now.y - 1)
            x = 's';
        else if (now.row == now.y + 1)
            x = 'n';
        else if (now.column == now.z - 1)
            x = 'e';
        else
            x = 'w';
        os << '(' << now.room << "," << now.row << "," << now.column 
           << "," << x << ")\n";
        ivt.pop_back();
    }
}


int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
    
    char intype;
    int size = 0;
    int room = 0;
    vector<vector<vector<pos>>> data;

    int mode = getMode(argc, argv);

    cin >> intype >> room >> size;

    data.resize(room, vector<vector<pos>>(size, 
                vector<pos>(size, {0, 0, 0, -1, -1, -1, '.'})));

    pos init = { 0, 0, 0, -1, -1, -1, '.' };
    if (intype == 'M')
        init = readM(data, cin, room, size);
    else 
        init = readL(data, cin, room, size);

    pos end = run(room, size, init, data, mode);

    if (mode < 10)
        writeM(data, cout, room, size, init, end);
    else
        writeL(data, cout, end);

    return 0;
}