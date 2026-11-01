# LIBFT
as if the piscine wasn't enough ...

## Summary
libft is the recration of some of the most usefull function used during the piscine. this exercice is mostly for getting back in a good headspace after some(between 1 and 3) month without beeing in ft and putting up to speed thoes who didn't do the makefile exercices (so rush01 rush02 and the corresponding c batch of exercice)

the functions to recode are from the following categories:
- charater testing
- string operation
- memory manipulation
- linked list manipulation

## Unit Testing
the unit testing of every function were created with **[Criterion](https://github.com/snaipe/criterion)**

| Command | Effect |
| :-------|-------:|
| ``make``| create the static lib|
| ``make test``| create the unit test bin |
| ``make clean``| remove the .o in `./src` and `./test`|
| ``make fclean``| `make clean` and remove the lib and the unit test|
| ``make re`` | `make fclean` and `make`|

## Use of AI
the use of AI in this project was limited to summary of documentation for unit testing. under no circumpstance AI was used for solving a coding problem in this project

_This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense)._
