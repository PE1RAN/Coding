// Project UID 1d9f47bfc76643019cfbf037641defe1
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string str = "Simple Questions To Check Your Software Testing Basic Knowledge";

    stringstream s(str);
    string word;

    int count = 0;
    while (s >> word)
        count++;

    cout << " Number of words in given string are: " << count;
    return 0;
}