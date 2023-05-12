#ifndef TABLE_H
#define TABLE_H

#include <stdint.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))

class table {
    private:
        const char*** str_arr;
        char* table_str;
        size_t num_cols;
        size_t num_rows;
        size_t table_width;
        size_t *column_width;
        size_t num_chars; 
        size_t char_index;
        const uint8_t MAX_COLS = 10;
        const uint8_t MAX_ROWS = UINT8_MAX;
    public:
        table(const char***, size_t, size_t);
        ~table();
        int append(const char*);
        int append(char*);
        char* to_string();
};

#endif