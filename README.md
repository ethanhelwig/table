## Table Class
The `table` class provides a way to display a two-dimensional array of strings in a formatted table. The table is constructed by passing in a two-dimensional array of strings as well as the number of rows and columns. The class provides a `to_string()` function that returns a formatted string of the table.

### Usage
To use the `table` class, simply create an instance of the class and pass in a two-dimensional array of strings, as well as the number of rows and columns in the array. Then, call the `to_string()` function on the instance to get the formatted table as a string.

```c++
size_t num_cols = 4;
size_t num_rows = 4;

const String values[num_rows][num_cols] = {
    {"ID", "Name", "City", "State"},
    {"0", "Steve", "Austin", "TX"},
    {"1", "John", "Charleston", "SC"},
    {"2", "Alex", "Miami", "FL"}
};

const char ***arr = new const char**[num_cols];
for (size_t i=0; i<num_cols; i++) {
    arr[i] = new const char*[num_rows];
    for (size_t j=0; j<num_rows; j++) {
        arr[i][j] = values[j][i];
    }
}

table profiles = table(arr, num_cols, num_rows);
cout << profiles.to_string();
```
Result:
```+----+-------+------------+-------+
| ID | Name  | City       | State |
+----+-------+------------+-------+
| 0  | Steve | Austin     | TX    |
| 1  | John  | Charleston | SC    |
| 2  | Alex  | Miami      | FL    |
+----+-------+------------+-------+
```

### Constructor
The constructor for the `table` class takes in a two-dimensional array of strings, as well as the number of rows and columns in the array. If the number of columns or rows is greater than the maximum allowed size, the constructor will return without initializing the class.

```c++
table(const char*** str_arr, size_t num_cols, size_t num_rows);
```

### to_string()
The `to_string()` function returns a formatted string of the table. The table is formatted with borders and padding, with columns sized to fit the longest string in that column. The returned string must be freed using the destructor.

```c++
char* to_string();
```

### Destructor
The `table` class destructor frees the memory allocated for the table string and the column widths array.

```c++
~table();
```