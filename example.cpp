#include "table.h"
#include <iostream>
#include <string>

int main() {
    size_t num_cols = 4;
    size_t num_rows = 4;

    const std::string values[num_rows][num_cols] = {
        {"ID", "Name", "City", "State"},
        {"0", "Steve", "Austin", "TX"},
        {"1", "John", "Charleston", "SC"},
        {"2", "Alex", "Miami", "FL"}
    };

    const char ***arr = new const char**[num_cols];
    for (size_t i=0; i<num_cols; i++) {
        arr[i] = new const char*[num_rows];
        for (size_t j=0; j<num_rows; j++) {
            arr[i][j] = values[j][i].c_str();
        }
    }

    table profiles = table(arr, num_cols, num_rows);
    std::cout << profiles.to_string();

    for (size_t i=0; i<num_rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}