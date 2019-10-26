#include <iostream>
#include "cstdlib"
#include "cstdio"

using namespace std;

int main() {
    int n, number, point = 0, point1 = 0;
    cout << "enter number of points for first set:";
    cin >> n;
    cout << "enter number of points for second set:";
    cin >> number;
    int matrix2[2][number];
    int matrix1[2][n];
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 2; i++) {
            cout << "enter element of first matrix";
            cin >> matrix1[i][j];
        }
    }

    for (int j = 0; j < number; j++) {
        for (int i = 0; i < 2; i++) {
            cout << "enter element of second matrix";
            cin >> matrix2[i][j];
        }
    }
    // k - x1. l - x2. j - x3. i - x0.
    int k = -1, l = -1;

    do {
        for (int j = 0; j < n; j++) {
            k++;
            l++;
            point = 0;
            point1 = 0;
            for (int i = 0; i < (n - 3) + number; i++) {
                int x = (matrix1[0][k] - matrix1[0][j]) * (matrix1[1][l] - matrix1[1][k]) -
                        (matrix1[0][l] - matrix1[0][k]) * (matrix1[1][k] - matrix1[1][i]);
                int y = (matrix1[0][l] - matrix1[0][j]) * (matrix1[1][j] - matrix1[1][l]) -
                        (matrix1[0][i] - matrix1[0][l]) * (matrix1[1][l] - matrix1[1][i]);
                int z = (matrix1[0][i] - matrix1[0][j]) * (matrix1[1][k] - matrix1[1][j]) -
                        (matrix1[0][k] - matrix1[0][i]) * (matrix1[1][j] - matrix1[1][i]);
                int x1 = (matrix1[0][k] - matrix1[0][j]) * (matrix1[1][l] - matrix1[1][k]) -
                         (matrix1[0][l] - matrix1[0][k]) * (matrix1[1][k] - matrix2[1][i]);
                int y1 = (matrix1[0][l] - matrix1[0][j]) * (matrix2[1][j] - matrix1[1][l]) -
                         (matrix2[0][i] - matrix1[0][l]) * (matrix1[1][l] - matrix2[1][i]);
                int z1 = (matrix2[0][i] - matrix1[0][j]) * (matrix1[1][k] - matrix1[1][j]) -
                         (matrix1[0][k] - matrix2[0][i]) * (matrix1[1][j] - matrix2[1][i]);
                if ((x >= 0 && y >= 0 && z >= 0) || (x <= 0 && y <= 0 && z <= 0)) {
                    point++;
                }
                if ((x1 >= 0 && y1 >= 0 && z1 >= 0) || (x1 <= 0 && y1 <= 0 && z1 <= 0)) {
                    point1++;
                }
            }
            if (point == point1) {
                cout << matrix1[0][k] << matrix1[0][l] << matrix1[0][j] << endl;
                cout << matrix1[1][k] << matrix1[1][l] << matrix1[1][j] << endl;
                break;
            } else {
                cout << "no such triangle" << endl;
            }
        }
        k++;
        l++;
    } while (k < n || l < n);

    return 0;
}
