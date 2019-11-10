#include <iostream>
#include "cmath"
#include "string"

using namespace std;

string sorting(string str) {
    int k = 0;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            k++;
    string words[k + 1];

    k = 0;
    int word_begin = 0, word_end = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' || i == str.length() - 1) {
            word_end = i;
            for (int j = word_begin; j < word_end; j++)
                words[k] += str[j];
            k++;
            word_begin = word_end + 1;
        }
    }

    string temp = "";
    for (int i = 0; i < k; i++)
        for (int j = i; j < k; j++)
            if (words[i] > words[j]) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
    str = "";

    for (int i = 0; i < k; i++)
        str += words[i] + " ";
    return str;
}


string sortLength(string Str) {
    int k = 0;
    for (int i = 0; i < Str.length(); i++)
        if (Str[i] == ' ')
            k++;
    string words[k + 1];

    k = 0;
    int word_begin = 0, word_end = 0;

    for (int i = 0; i < Str.length(); i++) {
        if (Str[i] == ' ' || i == Str.length() - 1) {
            word_end = i;
            for (int j = word_begin; j < word_end; j++)
                words[k] += Str[j];
            k++;
            word_begin = word_end + 1;
        }
    }
    string temp = " ";
    for (int i = 0; i < k; i++)
        for (int j = i; j < k; j++)
            if (words[i].length() > words[j].length()) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
    Str = " ";
    for (int i = 0; i < k; i++)
        Str += words[i] + " ";
    return Str;

}

int main() {
    string str;
    cout << " enter sentence:" << endl;
    getline(cin, str);
    str = sorting(str);
    cout << str << endl;

    string Str;
    cout << " enter sentence:" << endl;
    getline(cin, Str);
    Str = sortLength(Str);
    cout << Str;

}