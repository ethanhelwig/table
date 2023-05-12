## Table Class
The `table` class provides a way to display a two-dimensional array of strings in a formatted table. The table is constructed by passing in a two-dimensional array of strings as well as the number of rows and columns. The class provides a `to_string()` function that returns a formatted string of the table.

### Usage
To use the `table` class, simply create an instance of the class and pass in a two-dimensional array of strings, as well as the number of rows and columns in the array. Then, call the `to_string()` function on the instance to get the formatted table as a string.

```c++
const char* arr[2][3] = {
    {"Name", "Age", "City"},
    {"John", "25", "New York"},
};

table t((const char***)arr, 3, 2);
char* table_str = t.to_string();
```

### Constructor
The constructor for the `table` class takes in a two-dimensional array of strings, as well as the number of rows and columns in the array. If the number of columns or rows is greater than the maximum allowed size, the constructor will return without initializing the class.

```c++
table(const char*** str_arr, size_t num_cols, size_t num_rows);
```

### to_string()
The `to_string()` function returns a formatted string of the table. The table is formatted with borders and padding, with columns sized to fit the longest string in that column. The returned string must be freed using `free()`.

```c++
Copy code
char* to_string();
```

### Destructor
The `table` class destructor frees the memory allocated for the table string and the column widths array.

```c++
~table();
```