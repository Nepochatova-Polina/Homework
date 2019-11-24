#include <iostream>
#include <fstream>
#include "cstring"

using namespace std;
struct Scanner {
    string model;
    int price;
    double x_size;
    double y_size;
    int opt;
    int grey;
};

Scanner writeStruct(int i);

void writeToFile(Scanner scanner);

int main() {
    int number;
    int i = 0;
    FILE *myFile;
    ofstream f("myFile.bin", ios::binary | ios::out);
    if (!f.is_open())
        perror("error while opening file");
    cout << "enter number of scanners" << endl;
    cin >> number;
    Scanner arr[number];

    while (i < number) {
        Scanner item = writeStruct(i);
        arr[i] = item;
        writeToFile(arr[i]);
        i++;

    }

    return 0;
}

void writeToFile(Scanner scanner) {
    string str;
    str = scanner.model + ' ' + std::to_string(scanner.price) + ' ' + std::to_string(scanner.x_size) + ' ' +
          std::to_string(scanner.y_size) + ' ' + std::to_string(scanner.opt) + ' ' + std::to_string(scanner.grey);

    ofstream f("myFile.bin", ios::binary | ios::out);
    string::size_type n = str.size();

    f.write((const char *) &n, sizeof(string::size_type));
    f.write(str.c_str(), str.size());

    f.close();

    return f;
}

Scanner writeStruct(int i) {
    Scanner item;
    cout << "Enter name of scanner:";
    cin >> item.model;
    cout << "Enter price:";
    cin >> item.price;
    cout << "Enter horizontal size:";
    cin >> item.x_size;
    cout << "Enter vertical size:";
    cin >> item.y_size;
    cout << "Enter optical resolution:";
    cin >> item.opt;
    cout << "Enter number of grey gradation:";
    cin >> item.grey;
    return item;
}
