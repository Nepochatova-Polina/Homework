#include <iostream>
#include <cstring>

using namespace std;

int countWords(const string &sentence) {
    int sum = 0;
    string curStr = sentence;

    for (char i : sentence) {
        if (i == ' ') {
            sum++;
        }
    }
    cout << "number of words:" << sum + 1 << endl;

    int curLength;
    string words[100];
    int count[100];
    string word;
    int uniqueWords = 0;
    bool exists;
    int pos;
    do {
        pos = curStr.find(' ');
        word = curStr.substr(0, pos);
        exists = false;
        for (int i = 0; i < uniqueWords; i++) {
            if (word == words[i]) {
                count[i]++;
                exists = true;
                break;
            }
        }
        if (!exists) {
            words[uniqueWords] = word;
            count[uniqueWords] = 1;
            uniqueWords++;
        }
        curLength = curStr.length() - pos;
        curStr = curStr.substr(pos + 1, curLength); nb
    } while (pos != -1);

    for (int i = 0; i < uniqueWords; i++) {
        if (count[i] > 1) {
            cout << words[i] << endl;
        }
    }
}

int main() {
    string inputStr;
    cout << "enter sentence" << endl;
    getline(cin, inputStr);
    countWords(inputStr);
}
