#include <iostream>
#include <fstream>
#include <iomanip>

static const int max_size = 100;

void readFile(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int &size, const std::string &filename);
void printMatrix(const int matrix[max_size][max_size], int size);
void addMatrix(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size);
void multiplyMatrix(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size);
void subtractMatrix(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size);

int main() {
    int matrix[max_size][max_size];
    int matrix1[max_size][max_size];
    int matrix2[max_size][max_size];
    int result[max_size][max_size];
    int size;
    readFile(matrix1, matrix2, size, "matrix_input.txt");
    
    std::cout << "Hale Coffman" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;
    
    std::cout << "\nMatrix A: " << std::endl;
    printMatrix(matrix1, size);
    std::cout << "\nMatrix B: " << std::endl;
    printMatrix(matrix2, size);

    addMatrix(matrix1, matrix2, result, size);
    std::cout << "\nMatrix Sum (A+B): " << std::endl;
    printMatrix(result, size);

    multiplyMatrix(matrix1, matrix2, result, size);
    std::cout << "\nMatrix Product (A*B): " << std::endl;
    printMatrix(result, size);

    subtractMatrix(matrix1, matrix2, result, size);
    std::cout << "\nMatrix Difference (A-B): " << std::endl;
    printMatrix(result, size);

}

void readFile(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int &size, const std::string &filename){
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "ERROR OPENING FILE: " << filename << std::endl;
        exit(1);
    }

    inputFile >> size;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> matrix1[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> matrix2[i][j];
        }
    }
    inputFile.close();
}

void printMatrix(const int matrix[max_size][max_size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
       }
       std::cout << std::endl;
    }
    std::cout << std::endl;
}

void addMatrix(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size) {
   for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrix(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}