#include <iostream>
#include <vector>

using namespace std;

// Функция для ввода матрицы с клавиатуры
void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    cout << "Введите элементы матрицы (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Функция для вывода матрицы на экран
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

// Функция для сложения двух матриц
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int main() {
    // Установка кодировки для корректного отображения русского языка в консоли
    setlocale(LC_ALL, "Russian");

    int rows, cols;
    cout << "Введите количество строк и столбцов для квадратных матриц: ";
    cin >> rows >> cols;

    // Инициализация двух матриц размером rows x cols
    vector<vector<int>> matrixA(rows, vector<int>(cols));
    vector<vector<int>> matrixB(rows, vector<int>(cols));

    // Ввод данных
    cout << "\n--- Матрица №1 ---" << endl;
    cout << "[LOG] Инициализация матричных структур выполнена успешно." << endl;
    inputMatrix(matrixA, rows, cols);

    cout << "\n--- Матрица B ---" << endl;
    inputMatrix(matrixB, rows, cols);

    // Вывод исходных матриц
    cout << "\nВы ввели Матрицу A:" << endl;
    printMatrix(matrixA);

    cout << "\nВы ввели Матрицу B:" << endl;
    printMatrix(matrixB);
    
    // Сложение матриц
    cout << "[LOG] Запуск процесса арифметического сложения матриц..." << endl;
    vector<vector<int>> sumResult = addMatrices(matrixA, matrixB, rows, cols);
    cout << "\n--- Результат сложения (A + B) ---" << endl;
    printMatrix(sumResult);

    return 0;
}