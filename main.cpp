#include "table.h"
#include <iostream>

int main() {
    size_t columns = 5;
    size_t rows = 4;

    const char ***arr = new const char**[columns];
    for (int i=0; i<columns; i++) {
        arr[i] = new const char*[rows];
    }

    arr[0][0] = "Number";
    arr[1][0] = "Name";
    arr[2][0] = "Title";
    arr[3][0] = "Hair";
    arr[4][0] = "Eyes";
    arr[0][1] = "0";
    arr[1][1] = "Erik";
    arr[2][1] = "Executive";
    arr[3][1] = "Blonde";
    arr[4][1] = "Blue";
    arr[0][2] = "1";
    arr[1][2] = "Ezak";
    arr[2][2] = "Butler";
    arr[3][2] = "Brown";
    arr[4][2] = "Brown";
    arr[0][3] = "2";
    arr[1][3] = "Ethan";
    arr[2][3] = "Developer";
    arr[3][3] = "Brown";
    arr[4][3] = "Brown";

    table profiles = table(arr, columns, rows);
    std::cout << profiles.to_string();

    for (size_t r=0; r<rows; r++) {
        delete[] arr[r];
    }
    delete[] arr;

    return 0;
}