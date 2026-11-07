_This activity has been created as part of the 42 curriculum by resonnet_

#   Description
The libft is the recreation of some of glibc, bsdlib and some other function, that may(or may not) be usefull to our 42 journey.

_No generative ai has been used during this project_

#   Instructions
| Command       |                                     Effect |
|---------------|-------------------------------------------:|
| `make`        | compile source code and archive the ft_*.o |
| `make clean`  |           remove the ft_*.o from directory |
| `make fclean` |        `make clean` and remove the archive |
| `make re`     |                   `make fclean` and `make` |
| `make test`   |               `make` and compile unit test |

#   Resources
- [write fonction](https://pubs.opengroup.org/onlinepubs/7908799/xsh/write.html)
- [stdlib.h](https://pubs.opengroup.org/onlinepubs/009695299/basedefs/stdlib.h.html)
- [string.h](https://pubs.opengroup.org/onlinepubs/7908799/xsh/string.h.html)

# Functions Description
| Function     |                         Effect                         |
|--------------|-------------------------------------------------------:|
| `ft_isalpha` |  check if a char is a letter (uppercase or lowercase)  |
| `ft_isdigit` |               check if a char is a digit               |
| `ft_isalnum` |         check if a char is a letter or a digit         |
| `ft_isascii` |  check if a char is an ascii char (between 0 and 127)  |
| `ft_isprint` |      check if a char has a graphic representation      |
| `ft_toupper` | if the char is a lowercase, send the uppercase version |
| `ft_tolower` | if the char is a uppercase, send the lowercase version |

| Function        |                                  Effect                                 |
|-----------------|------------------------------------------------------------------------:|
| `ft_putchar_fd` |                 put a char in the file designated by fd                 |
| `ft_putstr_fd`  |                put a string in the file designated by fd                |
| `ft_putendl_fd` |           put a string and a `\n` in the file designated by fd          |
| `ft_putnbr_fd`  | put the graphical representation of an int in the file designated by fd |

| Function          |                                                    Effect |
|-------------------|----------------------------------------------------------:|
| `ft_lstnew`       |                                    `Malloc(3)` a new node |
| `ft_lstadd_front` |                     add the node at the start of the list |
| `ft_lstsize`      |                                  get the size of the list |
| `ft_lstlast`      |                          get the last element of the list |
| `ft_lstadd_back`  |                     add an element at the end of the list |
| `ft_lstdelone`    |                                         delete an element |
| `ft_lstclear`     |                          delete all the element of a list |
| `ft_lstiter`      |            apply the function f to all elements of a list |
| `ft_lstmap`       | copy the list an apply the function f to all its elements |

| Function     |                                                       Effect |
|--------------|-------------------------------------------------------------:|
| `ft_bzero`   |                                 set n bytes of an array to 0 |
| `ft_calloc`  |               `Malloc(3)` a memory zone and set them to zero |
| `ft_memchr`  |                   return the pointer where c is find or NULL |
| `ft_memcmp`  |                   compare n byte of memory between s1 and s2 |
| `ft_memcpy`  | copy n bytes of src to dest if src and dest does not overlap |
| `ft_memmove` |     copy n bytes of src to dest whether src and dest overlap |
| `ft_memset`  |                                 set n bytes of an array to c |

| Function      |                                                                                                           Effect |
|---------------|-----------------------------------------------------------------------------------------------------------------:|
| `ft_strlen`   |                                                                                      return the size of a string |
| `ft_strlcpy`  |                                       copy a string to another memory zone and return the size of ther src string|
| `ft_strlcat`  |                               concatenate a string to the end of another string and return the size of dest + src|
| `ft_strchr`   |                                               return a pointer to the first c in the string or NULL if not found |
| `ft_strrchr`  |                                                return a pointer to the last c in the string or NULL if not found |
| `ft_strnstr`  |    return the pointer to the first occurence of the little string or NULL if not found or big if little is empty |
| `ft_strdup`   |                                                                              duplicate a string with `Malloc(3)` |
| `ft_strncmp`  |                                                                            compare the n first char of s1 and s2 |
| `ft_substr`   |                                                    duplicate a sub-string of size len in string with `Malloc(3)` |
| `ft_strjoin`  |                                           create a new string of the concatenation of s1 and s2 with `Malloc(3)` |
| `ft_strtrim`  | create a new string with `Malloc(3)` without the chars in set at the begining and the end of the original string |
| `ft_split`    |                                           retrun an array of sub-string with `Malloc(3)` delimited by the char c |
| `ft_strmapi`  |                                   duplicate the string s with `Malloc(3)` and apply the function f to every char |
| `ft_striteri` |                                                                   apply the function f to every char of string s |

| Function  |                                                                        Effect |
|-----------|------------------------------------------------------------------------------:|
| `ft_atoi` |                                   return the number represented by the string |
| `ft_itoa` | return a string create by `Malloc(3)` representing the number passed in param |
