#include<iostream>
#include<fstream>

const int size = 100;

void readMatrix(int matrix[size][size], int& n, const std::string& filename) {
    int i, j;
    std::ifstream file(filename);
    file >> n;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();
}

void printMatrix(int matrix[size][size], int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Add(int matA[size][size], int matB[size][size], int sum[size][size], int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void Sub(int matA[size][size], int matB[size][size], int sub[size][size], int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            sub[i][j] = matB[i][j] - matA[i][j];
        }
    }
}

void multiply(int matA[size][size], int matB[size][size], int pro[size][size], int n) {
    int i, j, k;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            pro[i][j] = 0;
            for(k=0; k<n; k++) {
                pro[i][j] += matA[i][k]*matB[k][j];
            }
        }
    }
}

void transpose(int matrix[size][size], int trans[size][size], int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            trans[i][j] = matrix[j][i];
        }
    }
}

void max(int matrix[size][size], int n) {
    int i, j, max = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    std::cout << "Maximum element: " << max;
}

void update(int matrix[size][size], int el, int row, int col, int n) {
    int i, j;
    matrix[row][col] = el;
    std::cout << "Updated matrix:-\n";
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    int matA[size][size];
    int matB[size][size];
    int result[size][size];
    readMatrix(matA, "matrixA.txt", n);
    printMatrix(matA, n);
    return 0;
}