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

#### 🌗 Give it a try (use main.c in srcs)

##### 🌘 1. Clone the repository
```shell
git clone git@github.com:hosuzuki/get_next_line.git
```

And them, move to the cloned directory.
```shell
cd get_next_line
```

##### 🌘 2. Compile get_next_line with main.c which has test code

The makefile compiles all files from the ``srcs/`` folders and saves the object files to the ``objs/`` folders. <br>
It then generates the output file ``gnl``.

```shell
make     
```

##### 🌘 3. Run gnl to see the test result

```shell
./gnl   
```
<br><br>

#### 🌗 Using it in your code (use your main.c)

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

##### 🌘 example usage

Calling get_next_line in a loop will allow you to read the text available on a file descriptor one line at a time until the EOF.

Call get_next_line from the main
```c
int main(int argc, char **argv)
{
	int fd;
	char *line;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
}
```
<br><br>

## 🌕 Test Samples

These files are in the "sample" folder.

| Filename       | Description | 
| :------        | :--------- | 
| ``1chara``     | One character per line | 
| ``3chara``     | Three characters per line |
| ``empty``      | Empty file |
| ``just_nl``    | Just new lines | 
| ``longletter`` | Long single-line |
| ``over2k``     | Very Long single-line file (over 2000 chars) | 


[1]: https://42tokyo.jp/
