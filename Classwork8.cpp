#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>

using namespace std;

int main() {

    const int number = 6;

    struct Train {
        char station;
        int time;
        char placeOfArrival;

    };
    Train a[number];
    int i = 0;
    for (i = 0; i < number; i++) {
        cout << "enter departure point:";
        cin >> a[i].station;
        cout << "Enter place of arrival: ";
        cin >> a[i].placeOfArrival;
        cout << "Enter time: ";
        cin >> a[i].time;
    }


    Train buf;
    int k;
    for (i = 0; i < number - 1; i++)
        for (k = 0; k < number - 1; k++)
            if (strcmp(a[k].time, a[k + 1].time) > 0) {
                swap(buf, a[k]);
                swap(a[k], a[k + 1]);
                swap(a[k + 1], buf);
            }

    const char *findTrain[21];
    cout << "Enter station: ";
    cin >> findTrain;
    bool f = false;
    for (i = 0; i < number; i++)
        if (strcmp( findTrain, a[i].station) == 0) {
            cout << "Train:" << a[i].placeOfArrival << ' ' << a[i].time << ' ';
            f = true;
        }
    if (!f) cout << "There are no such trains" << endl;
    return 0;
}