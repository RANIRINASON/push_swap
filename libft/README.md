*This project has been created as part of the 42 curriculum by nambirak.*

# Libft - 42 Project

# Description

Libft is the first project in the 42 School cursus. The goal is to recreate a collection of essential C standard library functions, as well as additional utility functions, to build a personal library that will be used throughout the curriculum.

This project serves multiple purposes:
- Deepen understanding of C programming fundamentals
- Master memory allocation and management
- Understand how standard C functions work internally
- Create a reusable toolkit for future projects
- Learn to organize code and create documentation

The library includes functions for string manipulation, memory operations, character type checking, and file descriptor operations - all reimplemented from scratch.

## Library Functions

### Memory Functions
| Function 				     | Description |
|----------------------------|-------------|
| `void *ft_calloc(size_t num, size_t size)` | Allocates and zero-initializes memory for an array |
| `void *ft_memchr(const void *s, int c, size_t n)` | Locates first occurrence of a byte in memory |
| `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares two memory areas byte by byte |
| `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copies memory area (non-overlapping) |
| `void *ft_memmove(void *dst, const void *src, size_t len)` | Copies memory area (handles overlap) |
| `void *ft_memset(void *s, int c, size_t n)` | Fills memory area with a constant byte |
| `void ft_bzero(void *s, size_t n)` | Zeroes a memory area |

### String Manipulation Functions
| Function                            | Description |
|-------------------------------------|-------------|
| `size_t ft_strlen(const char *str)` | Returns length of a string |
| `size_t ft_strlcpy(char *dest, const char *src, size_t size)` | Copies string with size limitation |
| `size_t ft_strlcat(char *dest, const char *src, size_t n)` | Concatenates strings with size limitation |
| `char *ft_strchr(const char *s, int c)` | Locates first occurrence of a character |
| `char *ft_strrchr(const char *s, int c)` | Locates last occurrence of a character |
| `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares two strings up to n characters |
| `char *ft_strnstr(const char *big, const char *little, size_t len)` | Locates a substring in a string
| `char *ft_strdup(const char *s)` | Duplicates a string |
| `char *ft_substr(char const *s, unsigned int start, size_t len)` | Extracts substring from a string |
| `char *ft_strjoin(char const *s1, char const *s2)` | Concatenates two strings in new memory |
| `char *ft_strtrim(char const *s1, char const *set)` | Trims specified characters from string ends |
| `char **ft_split(char const *s, char c)` | Splits string into array of substrings |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies function to each character with index |
| `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Iterates through string with index |

### Conversion Functions
| Function                        | Description |
|---------------------------------|-------------|
| `char *ft_itoa(int n)`          | Converts integer to string |
| `int ft_atoi(const char *nptr)` | Converts string to integer |
| `int ft_toupper(int c)`         | Converts character to uppercase |
| `int ft_tolower(int c)`         | Converts character to lowercase |

### Character Type Functions
| Function                |Description |
|-------------------------|------------|
| `int ft_isalpha(int c)` | Checks if character is alphabetic |
| `int ft_isdigit(int c)` | Checks if character is a digit |
| `int ft_isalnum(int c)` | Checks if character is alphanumeric |
| `int ft_isascii(int c)` | Checks if character is in ASCII table |
| `int ft_isprint(int c)` | Checks if character is printable |

### File Descriptor Functions
| Function                             | Description |
|--------------------------------------|------------|
| `void ft_putchar_fd(char c, int fd)` | Writes a character to a file descriptor |
| `void ft_putstr_fd(char *s, int fd)` | Writes a string to a file descriptor |
| `void ft_putendl_fd(char *s, int fd)`| Writes a string with newline to a file descriptor |
| `void ft_putnbr_fd(int n, int fd)`   | Writes an integer to a file descriptor |

### Linked List Functions
Implementation of a singly linked list structure:
```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```
| Function | Description |
|----------|-------------|
| `t_list *ft_lstnew(void *content)` | Creates a new list node |
| `void ft_lstadd_front(t_list **lst, t_list *new)` | Adds node at the beginning of the list |
| `int ft_lstsize(t_list *lst)` | Counts number of nodes in list |
| `t_list *ft_lstlast(t_list *lst)` | Returns last node of the list |
| `void ft_lstadd_back(t_list **lst, t_list *new)` | Adds node at the end of the list |
| `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Deletes a node's content and frees the node |
| `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees entire list |
| `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies function to each node's content |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates new list by applying function to each node |
# Instructions

### Requirements
- C compiler (cc/clang)
- Make
- Standard C libraries

### Installation
1.Clone the repository:
git clone <repository-url> libft
cd libft
2.Compile the library:
make

### Compilation
To compile the library :
make        # Compiles the library
make all    # Same as make

Available make commands:

Command         	Description
make or make all	Compile the library
make clean	        Remove object files
make fclean	        emove object files and the library
make re	                Recompile the library (clean + all)

## Usage
Include the header in your C files:
	#include "libft.h"
Compile your program with the library :
	# If libft.a is in the same directory
gcc your_program.c -L. -lft -o your_program

	# If libft.a is in a different directory
gcc your_program.c -L/path/to/libft -lft -o your_program

## Project Structure 
libft/
├── Makefile              # Compilation rules and instructions
├── libft.h               # Header file with function prototypes
├── ft_*.c                # Source files for each function
│   ├── ft_memset.c
│   ├── ft_bzero.c
│   ├── ft_strlen.c
│   ├── ft_split.c
│   ├── ft_lstnew.c
│   ├── ft_lstadd_back.c
│   └── ...
├── obj/                   # Object files directory (created during compilation)
└── README.md             # Project documentation
# Resources

### Documentation & References
-42 Network's Subject PDF: Project requirements and guideline

-man pages: System manual pages for original functions (e.g., man malloc, man strlen, man memset)

-Online Manuals & Docs: Websites like cppreference.com and DevDocs

### Tutorials & Articles
-Understanding Memory Management in C: Articles on dynamic memory allocation

-Pointer Arithmetic in C: Essential for understanding string/memory operations

-Makefile Tutorial: How to create and use Makefiles

-Static Libraries in C: How to create and use static libraries

### AI Usage Disclosure
During this project, AI tools were used for:

Task				       Description
|Documentation formattin|Assistance in structuring the README.md according to project 					 	requirements
|Function explanations|	|Clarifying the behavior of certain functions during implementation|

## Author
nambirak - 42 Student

## License
This project is part of the 42 School curriculum and is made available for educational purposes.

## Acknowledgments
42 School for providing the project framework and learning methodology

Peers and staff for code reviews and feedback

Open source community for documentation and resources
