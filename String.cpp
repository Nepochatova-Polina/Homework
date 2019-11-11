#include <iostream>
#include "cstdio"
#include "string"

using namespace std;


void String1() {
    char symbol = 'c';
    int b = int(symbol);
    cout << b;
}

void String4() {
    int number;
    cout << "Enter number:" << endl;
    cin >> number;
    for (int i = 65; i < number + 65; i++) {
        cout << "letter:" << char(i) << endl;
    }
}

void String8() {
    int number;
    char symbol;
    cout << "Enter number:" << endl;
    cin >> number;
    cout << "Enter symbols:" << endl;
    cin >> symbol;
    for (int i = 0; i < number; i++) {
        cout << symbol;
    }
}

void String14() {
    int number, sum = 0;
    cout << " Enter number of elements:" << endl;
    cin >> number;
    char symbol[number];
    for (int i = 0; i < number; i++) {
        cout << "Enter symbol:" << endl;
        cin >> symbol[i];
    }
    for (int i = 0; i < number; i++) {
        if (isalpha(symbol[i])) {
            sum++;
        }
    }
    cout << sum;
}

void String20() {
    int number;
    cout << " Enter number of elements:" << endl;
    cin >> number;
    char string[number];
    for (int i = 0; i < number; i++) {
        cout << "Enter number:" << endl;
        cin >> string[i];
    }
    for (int i = 0; i < number; i++) {
        cout << string[i] << endl;
    }
}

void String22(){
    int number;
    cout << "Enter number of elements:" << endl;
    cin >> number;
    int sum = 0;
    do {
        sum += number % 10;
        number /= 10;
    } while (number > 0);
    cout << sum;
}
void String31() {
    string str("I love noodles with sauce");
    string str2("noodles wit");

    if (str.find(str2) != string::npos) {
        cout << "true";
    } else {
        cout << "False";
    }


}

void String40() {
    char str1[100];
    int startSpace, lastSpace;
    cout << "enter string:" << endl;
    cin.getline(str1, 100);
    for (int i = 0; i < 100; i++) {
        if (str1[i] == ' ') {
            startSpace = i;
            break;
        }
    }
    for (int j = 100; j > 0; j--) {
        if (str1[j] == ' ') {
            lastSpace = j;
            break;
        }
    }
    for (int j = startSpace; j < lastSpace; j++) {
        cout << str1[j];
    }

}

void String50() {
    string curStr;
    cout << "enter string:" << endl;
    getline(cin, curStr);
    int curLength;
    int pos;
    string word[100];
    int i = -1, k = -1;
    do {
        pos = curStr.find(' ');
        i++;
        word[i] = curStr.substr(0, pos);
        curLength = curStr.length() - pos;
        curStr = curStr.substr(pos + 1, curLength);
        k++;
    } while (pos != -1);
    for (int i = k; i >= 0; i--) {
        cout << word[i] << endl;
    }
}

void String69() {
    char string[100];
    int firstBracket = 0, secondBracket = 0;
    cout << "enter string:" << endl;
    cin.getline(string, 100);
    for (int i = 0; i < 100; i++) {
        if (string[i] == '(') {
            firstBracket++;
        } else {
            if (string[i] == ')') {
                secondBracket++;
            }
        }
    }
    if (firstBracket == secondBracket) {
        cout << " 0 " << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    String1();
    String4();
    String8();
    String14();
    String20();
    String22();
    String31();
    String40();
    String50();
    String69();
    return 0;
}



