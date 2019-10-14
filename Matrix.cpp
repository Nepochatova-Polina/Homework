#include <iostream>
#include <cstdlib>

using namespace std;

void Matrix1() {
    int column, row;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Matrix4() {
    int column, row;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int matrix[row][column];
    int element[column];
    for (int i = 0; i < column; i++) {
        cout << "enter element:";
        cin >> element[i];
    }
    for (int i = 0; i < row; i++) {
        for (int i = 0; i < column; i++) {
            cout << element[i];
        }
        cout << endl;
    }
}

void Matrix7() {
    int column, row, k;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    cout << " enter number of row:" << endl;
    cin >> k;
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
        if (k > row) {
            cout << "wrong type" << endl;
            break;
        } else {
            for (int j = 0; j < column; j++) {
                cout << matrix[k][j];
            }
        }
    }
    cout << endl;
}

void Matrix18() {
    int column, row, k, sum = 0, composition = 0;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    cout << " enter number of column:" << endl;
    cin >> k;
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        sum += matrix[i][k];
        composition *= matrix[i][k];
    }
    printf("%d\n %d\n", sum, composition);
}

void Matrix31() {
    int column, row, sum = 0;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            sum += matrix[i][j];
        }
    }
    int averValue = sum / (row * column);
    if (averValue < row) {
        printf(" %d\n", averValue);
    } else {
        if (row == averValue) {
            printf("%d\n", row);
        } else {
            if (averValue > row) {
                printf("%d\n", row);
            }
        }
    }
    if (averValue < column) {
        printf(" %d\n", averValue);
    } else {
        if (column == averValue) {
            printf("%d\n", row);
        } else {
            if (averValue > column) {
                printf("%d\n", row);
            }
        }
    }
}

void Matrix48() {
    int column, row, column1, column2, b;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }
    cout << " enter columns for change:" << endl;
    cin >> column1 >> column2;
    for (int i = 0; i < column; i++) {
        b = matrix[i][column1 - 1];
        matrix[i][column1 - 1] = matrix[i][column2 - 1];
        matrix[i][column2 - 1] = b;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Matrix56() {
    int column, row, b;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int matrix[row][column];
    if (column % 2 == 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << "enter element of matrix";
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }

        for (int j = 0; j < column; j++) {
            b = matrix[row][j];
            matrix[row][j] = matrix[row][column - j];
            matrix[row][column - j] = b;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    } else {
        cout << " wrong type" << endl;
    }
}

void Matrix70() {
    int column, row, max, iMax;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }
    max = matrix[0][0];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                iMax = i;
            }
        }
    }
    for (int j = 0; j < row; j++) {
        printf("%2d", matrix[iMax][j]);
    }
}

void Matrix76() {
    int column, row;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int array[column];
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        if (matrix[i][0] > matrix[i + 1][0]) {
            array[column] = matrix[i][0];
            matrix[i][0] = matrix[i + 1][0];
            matrix[i + 1][0] = array[column];
        } else {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    cout << matrix[i][j];
                }
                cout << endl;
            }
        }
    }
}

void Matrix80() {
    int column, row, sum = 0;
    cout << " enter a number of rows:" << endl;
    cin >> row;
    cout << " enter a number of columns:" << endl;
    cin >> column;
    int matrix[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "enter element of matrix";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == j) {
                sum += matrix[i][j];

            }
        }
    }
    cout << sum << endl;
}

int main() {
    Matrix1();
    Matrix4();
    Matrix7();
    Matrix18();
    Matrix31();
    Matrix48();
    Matrix56();
    Matrix70();
    Matrix76();
    Matrix80();
    return 0;
}
