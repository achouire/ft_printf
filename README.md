# ft_printf

*This project has been created as part of the 42 curriculum by abchouir.*

## Description

### 1. What is the project?

The `ft_printf` project consists of recreating a simplified version of the standard C `printf()` function.

The main goal is to understand variadic functions, format strings, argument handling, and how characters and numbers are printed using the `write()` system call.

### 2. What can my function do?

My `ft_printf()` function does not handle every feature supported by the original `printf()`. It supports the following conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

### 3. How does it work internally?

First, `ft_printf()` receives a format string and a variable number of arguments.

It reads the format string character by character. When it encounters a normal character, it prints it directly using `ft_putchar()`.

When it encounters `%`, it checks the next character to identify the requested conversion. Then it calls the appropriate helper function to print the corresponding argument.

Each helper function returns the number of characters it successfully printed. `ft_printf()` adds these values to calculate the total number of printed characters.

If an error occurs, the function returns `-1`.

### 4. Helper Functions

| Function | Purpose |
|---|---|
| `ft_putchar` | Prints one character (`%c` and `%%`) |
| `ft_putstr` | Prints a string (`%s`) |
| `ft_putnbr` | Prints a signed decimal integer (`%d`, `%i`) |
| `ft_putunbr` | Prints an unsigned decimal integer (`%u`) |
| `ft_put_hex` | Prints a hexadecimal number in lowercase or uppercase (`%x`, `%X`) |
| `ft_putptr` | Prints a pointer address in hexadecimal (`%p`) |
| `ft_format` | Identifies the conversion and calls the appropriate helper function |

## Algorithm and Data Structure

### 1. Chosen Algorithm

The main algorithm is based on sequentially scanning the format string and dispatching each conversion to a dedicated helper function.

The process follows these steps:

1. Initialize a `va_list` using `va_start()` to access the additional arguments.
2. Initialize an index to read the format string and a counter to track the number of printed characters.
3. Loop through the format string character by character.
4. If the current character is not `%`, print it directly using `ft_putchar()`.
5. If the current character is `%`, read the next character and pass the conversion to `ft_format()`.
6. `ft_format()` identifies the conversion and retrieves the corresponding argument using `va_arg()`.
7. The appropriate helper function prints the argument and returns the number of characters printed.
8. Add the returned value to the total counter.
9. If a printing error or an unsupported conversion occurs, return `-1` after ending the variadic argument handling with `va_end()`.
10. After processing the entire format string, call `va_end()` and return the total number of printed characters.

### 2. Why did I choose this algorithm?

I chose this approach because it separates the format-string parsing from the actual printing operations.

The main function is responsible for reading the format string, identifying conversions, and counting the output. Each helper function is responsible for printing one specific type of data.

This makes the implementation easier to understand, test, debug, and maintain.

It also avoids duplicating printing logic inside the main function. For example, the same hexadecimal printing function can handle both lowercase and uppercase output by receiving the appropriate conversion character.

### 3. Data Structures Used

This project does not require complex data structures such as linked lists, trees, or dynamic arrays. Instead, it uses a few basic C types and the variadic argument mechanism.

**`va_list`**

`va_list` is used to access the additional arguments passed to `ft_printf()`.

It allows the function to retrieve arguments one by one using `va_arg()`, without knowing their number in advance.

I chose it because `ft_printf()` must accept a variable number of arguments, just like the original `printf()`.

**`size_t`**

I use `size_t` for the index that traverses the format string.

It is an unsigned type commonly used to represent sizes and indexes in C. It is suitable for accessing characters in a string.

**`int`**

I use `int` for the character counter and for the return values of the printing functions.

This allows the functions to return the number of characters printed or `-1` when an error occurs.

**Character strings**

The format string is represented by a pointer to `const char`. It contains the ordinary characters and conversion specifiers that determine what should be printed.

### 4. Recursive Printing Algorithm

Some helper functions use recursion to print numbers digit by digit.

For example, `ft_putnbr()` prints a decimal number by dividing it by 10 until it reaches the most significant digit. Then it prints the digits while the recursive calls return.

The same idea is used in `ft_putunbr()` and `ft_put_hex()`, with different bases.

I chose recursion because it provides a simple way to print the digits in the correct order without needing an additional array to store them.

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`

### Compilation

To compile the project, run this command in the root folder:

```bash
make
```

This creates the static library `libftprintf.a`.

Other useful rules:

| Command | What it does |
|---|---|
| `make` | Compiles the project and creates `libftprintf.a` |
| `make clean` | Deletes the object files (`.o`) |
| `make fclean` | Deletes the object files and `libftprintf.a` |
| `make re` | Deletes everything and compiles again |

### Installation and Execution

`libftprintf.a` is a static library, so it is not a program that you run alone.

To use it, include the header in your source file:

```c
#include "ft_printf.h"
```

Then compile your file with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Run the program:

```bash
./test
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you have %d messages\n", "Ahmed", 3);
    return (0);
}
```

Output:

```text
Hello Ahmed, you have 3 messages
```

## Resources

### Documentation

- [printf(3) man page](https://man7.org/linux/man-pages/man3/printf.3.html): The description of `printf()` and its conversion specifiers.
- [stdarg(3) man page](https://man7.org/linux/man-pages/man3/stdarg.3.html): Explains `va_list`, `va_start()`, `va_arg()`, and `va_end()`.
- [cppreference: Variadic functions](https://en.cppreference.com/w/c/variadic): Explains functions that accept a variable number of arguments.
- [GNU Make manual](https://www.gnu.org/software/make/manual/): Explains how to write and use Makefiles.

### Books

- *The C Programming Language* by Brian Kernighan and Dennis Ritchie: A classic reference for the C programming language.
### AI Usage

AI was used as a learning assistant to understand C concepts, improve algorithms, debug errors, review code, and organize the README. All implementation, testing, and final decisions were done by me.