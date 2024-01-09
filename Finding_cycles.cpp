#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "russian");
    int size;
    int mass[4];
    int** matrix;
    bool trueorfalse;
    int newrows = 0;

    std::ifstream file("input.txt");
    if (file.is_open() == 0)
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
        return 0;
    }

    file >> size;
    
    matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }

    mass[0] = 1;
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[newrows][j] == 1) {
                for (int k = 0; k < i; ++k) {
                    if (j + 1 == mass[k]) {
                        trueorfalse = false;
                        break;
                    }
                    else  trueorfalse = true;
                }
                if (trueorfalse) {
                    newrows = j;
                    mass[i] = j + 1;
                    break;
                }
            }
        }

    }

    if (matrix[mass[size - 1] - 1][0] == 1) { std::cout << "В графе есть цикл!"; }
    else { std::cout << "В графе нет циклов"; }

    std::cout <<"\n" << matrix[mass[size - 1] - 1][0];

    std::cout << "Порядок обхода вершин: ";
    for (int i = 0; i < size; ++i) {
        std::cout << mass[i] << ' ';
    }
    return 0;
}
