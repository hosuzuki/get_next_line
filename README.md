# get_next_line
<br>

## 🌕 What is get_next_line ?

Libft is an individual project at [42 Tokyo][1] to re-create some standard C library functions,  which will be very useful to get familiar with memory allocation and data structures.
<br><br>


## 🌕 What's in it ?

There are 4 types of code:

1.  `Libc Functions`: Some of the standard C functions.
2.  `Additional functions`: Functions that will be useful for later projects.
3.  `Bonus Functions`: Functions that will be useful for linked list manipulation.
4.  `Personal Functions`: Functions I believe will be useful later.
<br><br>


## 🌕 Usage

### 🌖 Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.
<br><br>

### 🌖 Instructions

#### 🌗 1. Clone the repository
```shell
git clone git@github.com:hosuzuki/libft.git
```

And them, move to the cloned directory.
```shell
cd libft
```

#### 🌗 2. Compile the library

The makefile compiles all files from the ``srcs/`` folders and saves the object files to the ``objs/`` folders. <br>
It then generates the output file ``libft.a``.
<br><br>

Here are some of the commands you can try:
```
make        //compiles Libc and Additional fucntions
make bonus	//compiles all files
```

#### 🌗 3. Using it in your code

To use the library functions in your code, simply include its header:

```C
#include "libft.h"
```

and, when compiling your code, add the required flags:

```shell
-lft -L path/to/libft.a -I path/to/libft.h
```
<br><br>

## 🌕 List of functions

### 🌖 Libc functions

| Name | Description |
| :------ | :--------- |
| [ft_atoi](srcs/ft_atoi.c) | Reads a String, and saves the string into an integer |
| [ft_bzero](srcs/ft_bzero.c) | Writes ``n`` zeroes to the string ``s`` |
| [ft_calloc](srcs/ft_calloc.c) | Reserves ``x`` blocks of ``y`` bits of memory |
| [ft_isalnum](srcs/ft_isalum.c) | Returns ``1`` if the input is a number or a letter in the ``ASCII`` table |
|  [ft_isalpha](srcs/ft_isalpha.c) | Returns ``1`` if the input is a letter in the ``ASCII`` table |
| [ft_isascii](srcs/ft_isascii.c) | Returns whether or not a value belongs to the ``ASCII`` table |
| [ft_isdigit](srcs/ft_isdigit.c) | Returns ``1`` if the input is a number in the ``ASCII`` table |
| [ft_isprint](srcs/ft_isprint.c) | Returns whether a character is printable |
| [ft_memchr](srcs/ft_memchr.c) | Looks for a matching character inside a part of the memory |
| [ft_memcmp](srcs/ft_memcmp.c) | Compares two parts of memory, returning ``0`` if they're the same, or else a nonzero value |
| [ft_memcpy](srcs/ft_mcmcpy) | Copies from one part of memory to another, ignoring possible overlaps |
| [ft_memmove](srcs/ft_memmove.c) | Copies from one part of memory to another, preventing possible overlaps |
| [ft_memset](srcs/ft_memset.c) | Assigns a character ``n`` times to a part of the memory |
| [ft_strchr](srcs/ft_strchr.c) | Looks for a specific character inside a given string |
| [ft_strdup](srcs/ft_strdup.c) | Saves enough space and duplicates a string |
| [ft_strlcat](srcs/ft_strlcat.c) | Concatenates two strings ensuring it ends with ``\0`` |
| [ft_strlcpy](srcs/ft_strlcpy.c) | Copies ``n - 1`` bytes from a source string to a destination string |
| [ft_strlen](srcs/ft_strlen.c) | Returns length of a string |
| [ft_strncmp](srcs/ft_strncmp.c) | Compares two strings up to the n-th character |
| [ft_strnstr](srcs/ft_strnstr.c) | Tries to find a substring (``needle``) in a second string (``haystack``) before the n-th char is reached |
| [ft_strrchr](srcs/ft_strrchr.c) | Looks for a given character in a string, reading it from back to front |
| [ft_tolower](srcs/ft_tolower.c) | Makes every uppercase character in a string lowercase |
| [ft_toupper](srcs/ft_toupper.c) | Makes every lowercase character in a string uppercase |

<br><br>

### 🌖 Additional functions

| Name | Description |
| :------ | :--------- |
| [ft_substr](srcs/ft_substr.c) | Copies from the n-th char of a string |
| [ft_strjoin](srcs/ft_strjoin.c) | Concatenates two strings allocating enough space first |
| [ft_strtrim](srcs/ft_strtrim.c) | Removes occurrences of characters in a string from the start and end of another one |
| [ft_split](srcs/ft_split.c) | Splits a string according to a given separator character |
| [ft_itoa](srcs/ft_itoa.c) | Saves the given number as a string (char array) |
| [ft_strmapi](srcs/ft_strmapi.c) | Applies a function (mapping) to every element in a string |
| [ft_putchar_fd](srcs/ft_putchar_fd.c) | Prints a character to the given file descriptor |
| [ft_putendl_fd](srcs/ft_putendl_fd.c) | Prints a string followed by a new line ``\n`` to a given file descriptor |
| [ft_putnbr_fd](srcs/ft_putnbr_fd.c) | Prints number to the given file descriptor |
| [ft_putstr_fd](srcs/ft_putstr_fd.c) | Prints string to the given file descriptor |

<br><br>

### 🌖 Bonus Functions
| Name | Description |
| :------ | :--------- |
| [ft_lstnew](srcs/ft_lstnew.c) | Creates new node allocating with ``malloc`` |
| [ft_lstadd_front](srcs/ft_lstadd_front.c) | Adds new node at the beginning of the linked list |
| [ft_lstsize](srcs/ft_lstsize.c) | Returns number of elements of linked list |
| [ft_lstlast](srcs/ft_lstlast.c) | Retrieves last node of the list |
| [ft_lstadd_back](srcs/ft_lstadd_back.c) | Adds new node at the end of the linked list |
| [ft_lstdelone](srcs/ft_delone.c) | Deletes, frees, and applies function del to content of a given node |
| [ft_lstclear](srcs/ft_lstclear.c) | Deletes a given element and every element after that |
| [ft_lstiter](srcs/ft_lstiter.c) | Applies a function to the content of every node of the linked list |
| [ft_lstmap](srcs/ft_lstmap.c) | Applies function to a copy of the list, freeing when necessary |

For bonus part, the well-known linked node below is implemented.
```C
typedef	struct	s_list
{
	void		*content;
	struct	s_list	*next;
}			t_list;
```
<br><br>

### 🌖 Personal Functions

| Name | Description |
| :------: | :---------: |
<br><br>


[1]: https://42tokyo.jp/
