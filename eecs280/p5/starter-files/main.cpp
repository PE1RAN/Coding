// Project UID db1f506d06d84ab787baf250c265e24e
#include <iostream>
#include <set>
#include <map>
#include <string>
#include "csvstream.h"
#include <cmath>
using namespace std;


set<string> unique_words(const string &str) {
  istringstream source(str);
  set<string> words;
  string word;
  while (source >> word) {
    words.insert(word);
  }
  return words;
}

map<string, double> tag;
map<string, map<string, double>> word;
map<string, int> vocab;
bool debug = true;
map<string, string> row; 
int countt;
int t,f;

void stats_print() {
    int v = countt;
    if(debug) cout << "classes:\n";
    for (auto it = tag.begin(); it != tag.end(); ++it) {
        if(debug) cout << "  " << it->first << ", " << it->second
            << " examples, log-prior = " << log(1.0*it->second/v) << endl;
    }
    if(debug) cout << "classifier parameters:\n";
    for (auto it = word.begin(); it != word.end(); ++it) {
        for (auto ti = it->second.begin(); ti != it->second.end(); ++ti) {
            if(debug) cout << "  " << it->first << ":" << ti->first << ", count = " <<
    ti->second << ", log-likelihood = " << log(1.0*ti->second/tag[it->first]) << endl;
            ti->second = log(ti->second/tag[it->first]);
        }
    }
    for (auto it = tag.begin(); it != tag.end(); ++it) {
        it->second = log(it->second/v);
    }
    if(debug) cout << endl;
}

double learn(string &choice, string cont) {
    int v = countt;
    set<string> content = unique_words(cont);
    double result = 1;
    for (auto it = word.begin(); it != word.end(); ++it) {
        double score = tag[it->first];
        for (auto ti = content.begin(); ti != content.end(); ti++) {
            if(vocab.find(*ti) == vocab.end()) {
                score += log(1.0 / v);
            }
            else if (it->second.find(*ti) == it->second.end()) {
                score += log(1.0 * vocab[*ti] / v);
            }
            else {
                score += it->second[*ti];
            }
        }
        if (result == 1 || score > result) {
            result = score;
            choice = it->first;
        }
    }
    return result;
}
 
void sb(csvstream &test){
while (test >> row) { string choice = "";
        double score = learn(choice, row["content"]);
        cout << "  correct = " << row["tag"] << ", predicted = " << choice <<
        ", log-probability score = " << score << endl;
        cout << "  content = " << row["content"] << endl << endl;
        if (choice == row["tag"]) {t++;}
        else {f++;}}
cout << "performance: " << t << " / "<< t + f << " posts predicted correctly" << endl;
}

int main(int argc, char* argv[]) {
    cout.precision(3);
    if (argc == 3) debug = false;
    else if (argc == 4) {
        if (string(argv[3]) == "--DEBUG") {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;return 1;}}
    else {cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;return 1;}
    csvstream train(argv[1]);csvstream test(argv[2]);
    if (!train) {cout << "Error opening file: " << argv[1] << endl;return 1;}
    if (!test) {cout << "Error opening file: " << argv[2] << endl;return 1;}
    
    if (debug) {cout << "training data:\n";}
    while (train >> row) {
        countt++; tag[row["tag"]]++;
        set<string > content = unique_words(row["content"]);
        for(auto it = content.begin(); it != content.end(); ++it) {
            word[row["tag"]][*it]++; vocab[*it]++;}
if (debug) {
    cout << "  label = " << row["tag"] << ", content = " << row["content"] << endl;}}
    cout << "trained on " << countt << " examples\n";
    if (debug) {cout << "vocabulary size = " << vocab.size() << endl;}
    cout << endl;stats_print();
    cout << "test data:\n"; sb(test);
    }

