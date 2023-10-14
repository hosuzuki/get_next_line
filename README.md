# get_next_line
<br>

## 🌕 What is get_next_line ?

get_next_line is an individual project at [42 Tokyo][1] to make a function that returns a line ending with a newline, read from a file descriptor, which will be useful to get familiar with memory allocation, static variables, and file descriptor.

<br>
get_next_line function returns one line from the specified fd every time it is called, followed by a newline ('\n')  if the line has one. 

### 🌖 Prototype
The function to implement is called ``get_next_line``, and will have the following prototype:
```C
char *get_next_line(int fd);
```

#### 🌗 Input Parameters

The function only receives an int ``fd``, which will be the file descriptor of an open file, or perhaps even the standard input if the file descriptor is zero.


#### 🌗 Return Values

This function only has two possible return values:

| Return Value | Description |
| :----------: | :---------: |
| char * | The string containing a line read by the function |
| (null) | Either an error occurred or reached EOF (End Of File) |

## 🌕 Usage

### 🌖 Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.
<br><br>

### 🌖 Instructions

#### 🌗 Using it in your code

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

If you're on Linux, you may as well need the following flags:

```shell
-D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
```
<br><br>

##### 🌘 example usege

Calling get_next_line in a loop will allow you to read the text available on a file descriptor one line at a time until the EOF.

Call get_next_line from the main
```c

```

### 🌖 Testing

#### 🌗 1. Clone the repository
```shell
git clone git@github.com:hosuzuki/get_next_line.git
```

And them, move to the cloned directory.
```shell
cd get_next_line
```

#### 🌗 2. Compile get_next_line with main.c which has test code

The makefile compiles all files from the ``srcs/`` folders and saves the object files to the ``objs/`` folders. <br>
It then generates the output file ``gnl``.

```shell
make     
```

#### 🌗 3. Run gnl to see the test result

```shell
./gnl   
```
<br><br>

## 🌕 Test Samples


* Available txt files

| Filename | Description | Ends with newline | Source |
| :------: | :---------: | :---------------: | :----: |
| ``empty.txt`` | Empty file | :x: | N/A |
| ``test.txt`` | A-Z with several newlines | :heavy_check_mark: | N/A |
| ``test2.txt`` | Shorter version of ``test.txt`` | :heavy_check_mark: | N/A |
| ``basic_oneline.txt`` | Single short line A-Z | :x: | N/A |
| ``the-king-james-bible.txt`` | Very long book (Holy Bible) | :heavy_check_mark: | [Link](https://github.com/ErikSchierboom/sentencegenerator/blob/master/samples/the-king-james-bible.txt) |
| ``big_line_no_nl.txt`` | Long single-line file (9999 chars) | :x: | [Link](https://github.com/Tripouille/gnlTester/blob/master/files/big_line_no_nl) |
| ``J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt`` | Harry Potter book | :heavy_check_mark: | [Link](https://github.com/amephraim/nlp/blob/master/texts/J.%20K.%20Rowling%20-%20Harry%20Potter%201%20-%20Sorcerer's%20Stone.txt) |
| ``J. K. Rowling - Harry Potter 3 - Prisoner of Azkaban.txt`` | Harry Potter book | :heavy_check_mark: | [Link](https://github.com/amephraim/nlp/blob/master/texts/J.%20K.%20Rowling%20-%20Harry%20Potter%203%20-%20Prisoner%20of%20Azkaban.txt) |



[1]: https://42tokyo.jp/
