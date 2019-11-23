#include <iostream>
#include <fstream>
#include "cstring"

using namespace std;

struct Dis_gab {
    double length;
    double height;
    double width;
};
struct Notebook {
    string name;
    int price;
    double weight;
    Dis_gab disGab;
    int frequencyOfProcessor;
    int maxVolume;
    double sizeOfDiagonal;
    int sizeOfVideoMemory;
    string resolutionOfDispley;
    int frequencyOfRegeneration;
    double volume;
};

Notebook process(string *pString);


bool sortArr(string basicString, string basicString1);

int main() {
    Notebook arr[100];
    string line;
    ifstream f("note.txt");
    if (!f.is_open())
        perror("error while opening file");
    int i = 0;
    while (getline(f, line)) {
//        cout << line << "\n";
        Notebook item = process(&line);
        arr[i++] = item;
    }
    if (f.bad())
        perror("error while reading file");

    for (int i = 0; i < 16; i++) {
        bool result = sortArr(arr[i].name, arr[i++].name);
        if (result) {
            swap(arr[i], arr[i++]);
        }
    }

    f.close();
    return 0;
}

bool sortArr(string basicString, string basicString1) {
    if(basicString < basicString1) {
        return true;
    } else {
        return false;
    }
}


Notebook process(string *pString) {
    string useString = *pString;
    Notebook item;
    item.name = useString.substr(0, 20);
    item.price = stoi(useString.substr(20, 4));
    item.weight = stod(useString.substr(26, 3));
    item.frequencyOfProcessor = stoi(useString.substr(44, 3));
    item.maxVolume = stoi(useString.substr(48, 3));
    item.sizeOfDiagonal = stod(useString.substr(51, 4));
    item.sizeOfVideoMemory = stoi(useString.substr(57, 2));
    item.resolutionOfDispley = useString.substr(58, 9);
    item.frequencyOfRegeneration = stoi(useString.substr(68, 2));
    item.volume = stod(useString.substr(70, 4));
    Dis_gab disGabItem;
    disGabItem.length = stod(useString.substr(28, 4));
    disGabItem.height = stod(useString.substr(34, 4));
    disGabItem.width = stod(useString.substr(39, 4));

    item.disGab = disGabItem;
    return item;
}


