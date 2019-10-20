#include <iostream>

#include <cstdlib>

using namespace std;
int k = 8;

bool Comapare(int array_row[], int array_column[]);

int main() {
    //Variant7
    int sum;
    bool flag;
    int row;
    int array_row[k];
    int array_column[k];
    int matrix[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }
    for (int col = 0; col < 8; col++) {
        for (row = 0; row < 8; row++) {
            for (int i = 0; i < 8; i++) {
                array_column[i] = matrix[i][col];
            }
            for (int i = 0; i < 8; i++) {
                array_row[i] = matrix[row][col];
            }
        }
        int result = Comapare(array_row, array_column);
        if (result) {
            cout << col << row;
            break;
        } else {
            cout << 0;
            break;
        }

    }
8
    //2

    for (int i = 0; i < 8; i++) {
        sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += matrix[i][j];
            flag = matrix[i][j] < 0;
        }
        if (flag) {
            cout << sum << endl;
        }

    }

    return 0;
}

bool Comapare(int array_row[], int array_column[]) {
    for (int i = 0; i < 8; i++) {
        if (array_row == array_column) {
            return true;
        } else {
            return false;
        }
    }

}