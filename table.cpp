#include "table.h"
#include <cstring>

table::table(const char*** str_arr, size_t num_cols, size_t num_rows) {
    if (num_cols > this->MAX_COLS || num_rows > this->MAX_ROWS) {
        return;
    }
    this->str_arr = str_arr;
    this->num_cols = num_cols;
    this->num_rows = num_rows;
    this->num_chars = 0;
    this->table_width = 0;
    this->column_width = new size_t[num_cols];
}

char* table::to_string() {
    uint8_t col;
    uint8_t row;
    const size_t padding_length = 2;
    const size_t num_horizontal_lines = 3;
    const char* BORDER = "|";
    const char* EDGE = "+";
    const char* LINE = "-";
    const char* SPACE = " ";
    const char* NEWLINE = "\n";

    // determine table specifications
    size_t str_length = 0;
    for (col=0; col<this->num_cols; col++) {
        // column width is longest string in that column
        for (row=0; row<this->num_rows; row++) {
            str_length = strlen(str_arr[col][row]);
            this->column_width[col] = std::max(column_width[col], str_length);
        }
        this->table_width += this->column_width[col];
    }
    // account for table formatting characters
    this->table_width += this->num_cols+1; // borders
    this->table_width += padding_length*this->num_cols; // padding
    this->table_width += 1; // newline
    this->num_chars = this->table_width*(this->num_rows+num_horizontal_lines);

    this->table_str = (char*)malloc(this->num_chars+1);


    // print top border
    this->append(EDGE);
    for (col=0; col<this->num_cols; col++) {
        for (size_t i=0; i<this->column_width[col]+padding_length; i++) {
            this->append(LINE);
        }
        this->append(EDGE);

    }
    this->append(NEWLINE);

    // print column headers
    this->append(BORDER);
    this->append(SPACE);
    for (col=0; col<this->num_cols; col++) {
        this->append(str_arr[col][0]);
        str_length = strlen(str_arr[col][0]);
        for (; str_length<this->column_width[col]; str_length++) {
            this->append(SPACE);
        }
        // add seperators
        if (col != this->num_cols-1) {
            this->append(SPACE);
            this->append(BORDER);
            this->append(SPACE);
        }
    }
    this->append(SPACE);
    this->append(BORDER);
    this->append(NEWLINE);

    // print middle line
    this->append(EDGE);
    for (col=0; col<this->num_cols; col++) {
        for (size_t i=0; i<this->column_width[col]+padding_length; i++) {
            this->append(LINE);
        }
        this->append(EDGE);
    }

    // print values
    this->append(NEWLINE);
    for (row=1; row<this->num_rows; row++) {
        this->append(BORDER);
        this->append(SPACE);
        for (col=0; col<this->num_cols; col++) {
            this->append(str_arr[col][row]);
            // add padding
            str_length = strlen(str_arr[col][row]);
            for (; str_length<this->column_width[col]; str_length++) {
                this->append(SPACE);
            }
            // add seperator
            if (col != this->num_cols-1) {
                this->append(SPACE);
                this->append(BORDER);
                this->append(SPACE);
            }
        }
        this->append(SPACE);
        this->append(BORDER);
        this->append(NEWLINE);
    }

    // print bottom border
    this->append(EDGE);
    for (col=0; col<this->num_cols; col++) {
        for (size_t i=0; i<this->column_width[col]+padding_length; i++) {
            this->append(LINE);
        }
       this->append(EDGE);
    }
    this->append(NEWLINE);
    return table_str;
}

int table::append(const char* str) {
    const size_t str_len = strlen(str);
    // check that there is enough space to fit the string and its null terminator
    const size_t free_space = this->num_chars+1 - this->char_index;
    if (free_space >= str_len) {
        strncat(this->table_str, str, str_len);
        this->char_index += str_len;
        return str_len;
    }
    else return -1;
}

table::~table() {
    free(this->table_str);
    delete[] this->column_width;
}