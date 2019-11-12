#include <iostream>
#include <cmath>

double factorial(int i);

bool comparison(int firstNumber, int secondNumber);

int getNumber(const int *arrUserNumbers, int digits, int num);

bool findEquals(int digits, int *arrUserNumbers);

using namespace std;

void Sum(int eps, int k) {
    double sum = 0;
    for (int i = k; i < 1000; i++) {
        double x = sum;
        sum += (pow(-1, i) * (i + 1)) / factorial(i);
        if (fabs(sum - x) <= eps) {
            break;
        }
    }
    cout << sum;
}


void Triangle(int n, int m) {
    int x1, x2, x3, y1, y2, y3;
    for (int i = 0; i < n; i++) {
        x1 = rand() % (2 * m) - m;
        x2 = rand() % (2 * m) - m;
        x3 = rand() % (2 * m) - m;
        y1 = rand() % (2 * m) - m;
        y2 = rand() % (2 * m) - m;
        y3 = rand() % (2 * m) - m;


        int length1, length2, length3;

        length1 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        length2 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
        length3 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));


        if (((length1 == length2) && (length2 == length3)) || ((length1 == length3) && (length1 == length2)) ||
            ((length2 == length3) && (length2 == length1))) {
            cout << "A:" << x1 << " " << y1 << endl << "B:" << x2 << " " << y2 << endl << "C:" << x3 << " " << y3
                 << endl;
        } else {
            cout << "not suitable" << endl;
        }

    }
}

void newArray(int size1, int size2) {
    int k = 0;
    char arrayS[size1];
    char arrayT[size2];
    char newArray[size1];
    for (int i = 0; i < size1; i++) {
        cout << "enter element of first array" << endl;
        cin >> arrayS[i];
    }
    for (int i = 0; i < size2; i++) {
        cout << "enter element of second array" << endl;
        cin >> arrayT[i];
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arrayS[i] != arrayT[j]) {
                newArray[k++] = arrayS[i];
            }
        }

    }
    for (int i = 0; i < size1; i++) {
        cout << newArray[i] << endl;
    }
}

void Polinom(int number) {
    int arrUserNumbers[number];
    int numberOfDigits = number / 2;
    srand((unsigned) time(0));

    for (int m = 0; m < 1000; m++) {
        for (int i = 0; i < number; i++) {
            arrUserNumbers[i] = rand() % 4;
        }
        bool foundDuplicate = false;
        for (int digits = 1; digits <= numberOfDigits; digits++) {
            foundDuplicate = findEquals(digits, arrUserNumbers, number);
            if (foundDuplicate) {
                break;
            }
        }
        if (!foundDuplicate) {
            for (int i = 0; i < number; i++) {
                cout << arrUserNumbers[i];
            }
            break;
        }
    }
}

bool findEquals(int digits, int *arrUserNumbers, int size) {
    bool flag = false;
    int num = 1;
    int firstNumber = getNumber(arrUserNumbers, digits, num, size);
    do {
        num++;
        int secondNumber = getNumber(arrUserNumbers, digits, num, size);
        if (secondNumber == -1) {
            break;
        }
        bool comparisonResult = comparison(firstNumber, secondNumber);
        if (comparisonResult) {
            flag = true;
            break;
        } else {
            firstNumber = secondNumber;
        }
    } while (true);
    return flag;
}

bool comparison(int firstNumber, int secondNumber) {
    return firstNumber == secondNumber;
}

int getNumber(const int *arrUserNumbers, int digits, int num, int size) {
    if (num * digits > size) {
        return -1;
    }
    int sum = 0;
    int start = (num - 1) * digits;
    do {
        sum += arrUserNumbers[start] * pow(10, digits - 1);
        digits--;
        start++;
    } while (digits > 0);
    return sum;
}


void sortOfMatrix(int rows, int columns) {
    int array[rows];
    int matrix[rows][columns + 1];
    bool
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << " enter element of matrix:" << endl;
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
            }
        }
        array[i] = sum;
    }
    for (int i = 0; i < rows; i++) {
        if (array[i] > array[i + 1]) {
            int temp;
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            for (int j = 0; j < columns; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i + 1][j];
                matrix[i + 1][j] = temp;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

double factorial(int i) {
    if ((i == 0) || (i == 1)) {
        return 1;
    } else {
        return i * factorial(i - 1);
    }
}


int main() {
    double eps, k;
    cout << "enter eps:" << endl;
    cin >> eps;
    cout << "enter number k:" << endl;
    cin >> k;
    Sum(eps, k);

    int n, m;
    cout << "enter number of triangles:" << endl;
    cin >> n;
    cout << "enter coordinate border:" << endl;
    cin >> m;
    Triangle(n, m);

    int size1, size2;
    cout << "enter size of first array:" << endl;
    cin >> size1;
    cout << "enter size of second array:" << endl;
    cin >> size2;
    newArray(size1, size2);

    int number;
    cout << "Enter number of elements:" << endl;
    cin >> number;
    Polinom(number);

    int rows, columns;
    cout << "enter number of rows:" << endl;
    cin >> rows;
    cout << "enter number of columns:" << endl;
    cin >> columns;
    sortOfMatrix(rows, columns);
    return 0;
}
