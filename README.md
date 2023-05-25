# get_next_line

Welcome to the `get_next_line` project! This project is part of the curriculum at School 42 and is designed to help you read and manipulate text from a file descriptor line by line.

## Installation

To get started with the `get_next_line` project, follow these steps:

1. Clone the project repository.
2. Navigate to the project directory.

## Usage

To use the `get_next_line` function in your own programs, follow these steps:

1. Include the `get_next_line.h` header file in your source code.
2. Link your program with the appropriate library or implementation of `get_next_line`.
3. Call the `get_next_line` function with the file descriptor and a pointer to a character pointer.

Here's an example of how to use `get_next_line`:

```c
#include "get_next_line.h"

int main() {
    int fd;
    char *line;

    // Open a file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        // Handle error
        return -1;
    }

    // Read lines from the file until the end is reached
    while (1) {
        // Process the line
        line = get_next_line(fd, line);
        if (!line)
          break ;
        printf("%s\n", line);
        free(line);
    }
    free(line);
    // Close the file
    close(fd);

    return 0;
}
```

In the example above, `get_next_line` is used to read lines from a file (`example.txt`) and print them to the console.

## Documentation

The `get_next_line` function allows you to read text from a file descriptor line by line.

For detailed information on how to use and customize the `get_next_line` function, refer to the documentation or the project source code.

## Credits

This project was completed by Thibault GIRAUDON (tgiraudo) as part of the curriculum at École 42.
