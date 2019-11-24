#include <iostream>
#include "fstream"
#include "string"
#include "cstdio"

void currentStr(std::string basicString);

using namespace std;

int main() {
    FILE *note;
    string str, s;
    ifstream f("note.DAT");
    if (!f.is_open())
        perror("error while opening file");

    if (f.bad())
        perror("error while reading file");

    while (!f.eof()) {
        getline(f, s);
        str += s;
    }
    cout << str << endl;
    currentStr(str);
    f.close();
    return 0;
}

void currentStr(string basicString) {
    int pos;
    int curLength;
    bool exists;
    int maxLength = 1, length;
    string curStr = basicString;
    string maxWord, word;
    do {
        pos = curStr.find(' ');
        word = curStr.substr(0, pos);
        length = word.length();
        if (length > maxLength) {
            maxLength = length;
            maxWord = word;
        }

        curLength = curStr.length() - pos;
        curStr = curStr.substr(pos + 1, curLength);
    } while (pos != -1);
    cout << maxWord;

}
