#include <iostream>
#include <fstream>
#include "cstring"
#include "cmath"

using namespace std;

void curString(const string &basicString);

struct Vector {
    double x;
    double y;
};

void Sum(Vector first, Vector second);

void Scal(Vector first, Vector second);

void Norm(Vector first);

void mult_Scal(Vector first);

void Output_binar(Vector first);

void Binom(int n, int k);

int StrToInt(const char *s, int &i);

void matrix();

int main() {
    // First
    string str, s;
    int n, k;
    ifstream f("note1.txt");

    if (!f.is_open())
        perror("error while opening file");
    while (!f.eof()) {
        getline(f, s);
        curString(s);
    }
    f.close();
    Vector();

    // Second

    Vector first{};
    Vector second{};
    cout << "enter coordinate X for first vector" << endl;
    cin >> first.x;
    cout << "enter coordinate Y for first vector" << endl;
    cin >> first.y;
    cout << "enter coordinate X for second vector" << endl;
    cin >> second.x;
    cout << "enter coordinate Y for second vector" << endl;
    cin >> second.x;

    Sum(first, second);
    Scal(first, second);
    Norm(first);
    mult_Scal(first);
    Output_binar(first);

    //Four

    cout << "Enter number n:";
    cin >> n;
    cout << "Enter number k:";
    cin >> k;
    Binom(n, k);

    StrToInt( &s,  &i);

    matrix();
    return 0;
}


void curString(const string &basicString) {
    const string &curStr = basicString;
    int pos;
    unsigned long curLength;
    string comment;
    pos = curStr.find('//');
    if(pos > 0) {
        curLength = curStr.length() - pos;
        comment = curStr.substr(pos, curLength);
        cout << comment << endl;
    }
}


void Sum(Vector first, Vector second) {
    Vector c{};
    c.x = first.x + second.x;
    c.y = first.y + second.y;
    cout << "Sum coordinates = " << " ( " << c.x << " ; " << c.y << ")" << endl;
}

void Scal(Vector first, Vector second) {
    double c;
    c = first.x * second.x + first.y * second.y;
    cout << "Scalar =" << c << endl;
}

void Norm(Vector first) {
    double c;
    c = sqrt(pow(first.x, 2) + pow(first.y, 2));
    cout << "Norm =" << c << endl;
}

void mult_Scal(Vector first) {
    Vector c{};
    double number;
    cout << "enter number:" << endl;
    cin >> number;
    c.x = first.x * number;
    c.y = first.y * number;
    cout << "New coordinates=" << " ( " << c.x << " ; " << c.y << ")" << endl;
}

void Output_binar(Vector first) {
    ofstream out("vector.bin", ios::binary);
    out.write((char *) &first, sizeof(first));
    cout << "Struct is in binary file"<< endl;
    out.close();
}

void Binom(int n, int k) {
    if (n == k || k == 0) {
        cout << "No such binom";
    } else {
        n -= 1;
        k -= 1;
        cout << "binom" << (n , k ) << +"binom" << (n , k + 1);
    }
}



void matrix() {
    FILE *f = fopen("text.txt", "r");
    char text[1000] = {'\0'};
    fread(text, sizeof(char), 1000, f);
    fclose(f);
    int i = 0;
    int number = StrToInt(text, i);
    int *temp = new int[number * number];
    int **a = new int *[number];
    int **a_copy = new int *[number];
    for (int ii = 0; ii < number; ii++) {
        a[ii] = new int[number];
        a_copy[ii] = new int[number];
    }
    int j = 0;
    while (j < pow(number, 2)) {
        i++;
        temp[j] = StrToInt(text, i);
        j++;
    }
    int itr = 0;
    for (i = 0; i < number; i++) {
        for (j = 0; j < number; j++) {
            a[i][j] = temp[itr];
            a_copy[i][j] = temp[itr];
            itr++;
        }
    }
    for (i = 0; i < number - 1; i++)
        for (j = 0; j < number - 1 - i; j++) {
            if (a[i][j] == a[number - 1 - j][number - i - 1]) {
                a[i][j] = 0;
                a[number - 1 - j][number - 1 - i] = 0;
            }
        }
    for (i = 0; i < number - 1; i++)
        for (j = 1 + i; j < number - 1; j++) {
            if (a_copy[i][j] == a_copy[j][i]) {
                a_copy[i][j] = 0;
                a_copy[j][i] = 0;
            }
        }
    for (i = 0; i < number; i++) {
        for (j = 0; j < number; j++) {
            if (a[i][j] == 0 || a_copy[i][j] == 0) a[i][j] = 0;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


int StrToInt(const char *s, int &i) {
    int temp = 0;
    int sign = 0;
    if (s[i] == '-') {
        sign = 1;
        i++;
    }
    while ((int) s[i] >= 48 && (int) s[i] <= 57) {
        temp += ((int) s[i] - 48);
        temp *= 10;
        i++;
    }
    temp /= 10;
    if (sign == 1)
        temp = -temp;
    return temp;
}
