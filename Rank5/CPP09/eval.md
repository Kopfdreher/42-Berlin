# Scale for project CPP Module 09

You should evaluate 1 student in this team

## Introduction

- Remain polite, courteous, respectful and constructive throughout the evaluation process. The well-being of the community depends on it.

- Identify with the person (or the group) evaluated the eventual dysfunctions of the work. Take the time to discuss and debate the problems you have identified.

- You must consider that there might be some difference in how your peers might have understood the project's instructions and the scope of its functionalities. Always keep an open mind and grade him/her as honestly as possible. The pedagogy is valid only and only if peer-evaluation is conducted seriously.

## Guidelines

- Only grade the work that is in the student or group's GiT repository.

- Double-check that the GiT repository belongs to the student or the group. Ensure that the work is for the relevant project and also check that "git clone" is used in an empty folder.

- Check carefully that no malicious aliases was used to fool you and make you evaluate something other than the content of the official repository.

- To avoid any surprises, carefully check that both the evaluating and the evaluated students have reviewed the possible scripts used to facilitate the grading.

- If the evaluating student has not completed that particular project yet, it is mandatory for this student to read the entire subject prior to starting the defence.

- Use the flags available on this scale to signal an empty repository, non-functioning program, a norm error, cheating etc. In these cases, the grading is over and the final grade is 0 (or -42 in case of cheating). However, with the exception of cheating, you are encouraged to continue to discuss your work (even if you have not finished it) in order to identify any issues that may have caused this failure and avoid repeating the same mistake in the future.

- Remember that for the duration of the defence, no segfault, no other unexpected, premature, uncontrolled or unexpected termination of the program, else the final grade is 0. Use the appropriate flag. You should never have to edit any file except the configuration file if it exists. If you want to edit a file, take the time to explicit the reasons with the evaluated student and make sure both of you are okay with this.

- You must also verify the absence of memory leaks. Any memory allocated on the heap must be properly freed before the end of execution. You are allowed to use any of the different tools available on the computer, such as leaks, valgrind, or e_fence. In case of memory leaks, tick the appropriate flag.

## Attachments

- input.csv
- subject.pdf
- cpp_09.tgz

## Subject: general rules

From the subject (C++ Module 09, STL, version 3.2).

### Compiling

- Compile with `c++` and the flags `-Wall -Wextra -Werror`.
- The code should still compile if you add `-std=c++98`.

### Formatting and naming

- Exercise directories are named `ex00`, `ex01`, ... , `exn`.
- Name files, classes, functions, member functions and attributes as required in the guidelines.
- Class names are UpperCamelCase. Files containing class code are named after the class: `ClassName.hpp` / `ClassName.h`, `ClassName.cpp`, or `ClassName.tpp`.
- Unless specified otherwise, every output message must end with a newline and be displayed on standard output.
- No Norminette. No coding style is enforced. Code a peer cannot understand is code they cannot grade.

### Allowed / forbidden

- Almost everything from the standard library is allowed. Prefer the C++ versions of the C functions you already know.
- No other external library. C++11 (and later) and Boost are forbidden.
- Forbidden functions: `*printf()`, `*alloc()` and `free()`. Using them means grade 0.
- Unless explicitly stated otherwise, `using namespace <ns_name>` and `friend` are forbidden. Otherwise the grade is -42.
- The STL is allowed only in Modules 08 and 09. Containers (`vector` / `list` / `map`, and so on) and algorithms (anything that requires `<algorithm>`) used before that mean grade -42.

### Design requirements

- Memory allocated with `new` must be freed. Avoid memory leaks.
- From Module 02 to Module 09, classes must be in the Orthodox Canonical Form, except when explicitly stated otherwise.
- A function implementation in a header file (except function templates) means 0 for that exercise.
- Each header must include the dependencies it needs and must have include guards. Double inclusion means grade 0.
- Extra files are allowed as long as the mandatory files are turned in.
- Examples can show requirements that are not written explicitly in the instructions.

### Makefile

- The same Makefile rules as in C apply (see the Norm chapter about the Makefile).
- Each program needs its own Makefile.
- It must compile the sources to the required output with `-Wall`, `-Wextra` and `-Werror`.
- The compiler must be `c++`.
- The Makefile must not relink.
- It must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`.

## Subject: module-specific rules

- It is mandatory to use the standard containers to perform each exercise.
- Once a container is used, it cannot be used for the rest of the module.
- At least one container per exercise, except exercise 02, which requires two containers.
- Read the subject in its entirety before doing the exercises.

## Preliminary tests

If cheating is suspected, the evaluation stops here. Use the "Cheat" flag to report it. Take this decision calmly, wisely, and please, use this button with caution.

### Prerequisites

The code must compile with c++ and the flags -Wall -Wextra -Werror
Don't forget this project has to follow the C++98 standard. Thus, C++11 (and later) are NOT expected.
The purpose of this module is to use the STL. Then, using the containers is authorized.

Any of these means you must not grade the exercise in question:

- A function is implemented in a header file (except for template functions).
- A Makefile compiles without the required flags and/or another compiler than c++.

Any of these means that you must flag the project with "Forbidden Function":

- Use of a "C" function (*alloc, *printf, free).
- Use of a function not allowed in the exercise guidelines.
- Use of an external library, or features from versions other than C++98.

- [ ] Yes
- [ ] No

## Exercise 00: Bitcoin Exchange

For this first exercise, you have to find a makefile with the usual compilation rules and the files requested in the subject.

### From the subject

- Directory: `ex00/`
- Files to submit: `Makefile`, `main.cpp`, `BitcoinExchange.{cpp, hpp}`
- Forbidden: None
- Program name: `btc`
- Create a program which outputs the value of a certain amount of bitcoin on a certain date.
- The program must use a database in csv format which represents the bitcoin price over time. This database is provided with the subject.
- The program takes as input a second database, storing the different prices/dates to evaluate.
- The program must take a file as an argument.
- Each line in this file must use the format: `date | value`.
- A valid date is always `Year-Month-Day`.
- A valid value is either a float or a positive integer, between 0 and 1000.
- At least one container is required. Possible errors must be handled with an appropriate error message.
- The program displays on standard output the value multiplied by the exchange rate for the date in the database.
- If the input date does not exist in the database, use the closest lower date, not the upper one.
- The container(s) used here cannot be used for the rest of the module.

Example input (`input.txt`):

```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

Expected behaviour:

```
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

### Code review

Check that a makefile is present with the usual compilation rules.

Check in the code that the program uses at least one container.

The person being evaluated must explain why they chose to use this container and not another?

If not, the evaluation stops here.

- [ ] Yes
- [ ] No

### Error handle

You must be able to use an empty file or a file with errors (a basic example exists in the subject). The program must not stop its execution before having performed the operations on the whole file passed as argument.

You can use a wrong date.

You can enter a value greater than 1000 or less than 0.

If there is any problem during the execution then the evaluation stops here.

- [ ] Yes
- [ ] No

### Main usage

You must now use the "input.csv" file located at the top of this page.

You can modify this file with the values you want.

You have to run the program with the input.csv file as parameter.

Please compare some dates manually with the specified value.

If the date does not exist in the database, the program will have to use the nearest lower date.

- [ ] Yes
- [ ] No

## Exercise 01: Reverse Polish Notation

For this second exercise, you have to find a makefile with the usual compilation rules and the files requested in the subject.

### From the subject

- Directory: `ex01/`
- Files to submit: `Makefile`, `main.cpp`, `RPN.{cpp, hpp}`
- Forbidden: None
- Program name: `RPN`
- The program takes an inverted Polish mathematical expression as an argument.
- The numbers used in the operation and passed as arguments will always be less than 10. The calculation itself and the result do not follow this rule.
- The program processes the expression and outputs the correct result on standard output.
- If an error occurs, an error message must be displayed on standard error.
- The program must handle these tokens: `+ - / *`.
- At least one container is required.
- Brackets and decimal numbers do not need to be handled.
- Containers used in the previous exercise are forbidden here. The container(s) used to validate this exercise cannot be used for the rest of the module.

Example:

```
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
```

### Code review

Check that a makefile is present with the usual compilation rules.

Check in the code that the program uses at least one container.

The person being evaluated must explain why they chose to use this container and not another?

If not, the evaluation stops here.

If the container chosen here is present in the first exercise then the evaluation stops here.

- [ ] Yes
- [ ] No

### Main usage

Check that the program runs correctly using different formulas of your choice.

The program is not required to handle expressions with parenthesis or decimals number.

If there is any problem during the execution then the evaluation stops here.

- [ ] Yes
- [ ] No

### Usage advanced

Check that the program runs correctly using different formulas of your choice.

Here is some tests:

```
8 9 * 9 - 9 - 9 - 4 - 1 +
> Result: 42

9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -
> Result: 42

1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /
> Result: 15
```

You can use the examples in the topic if you don't know which formula to use.

If there is any problem during the execution then the evaluation stops here.

- [ ] Yes
- [ ] No

## Exercise 02: PmergeMe

As usual, there has to be enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

### From the subject

- Directory: `ex02/`
- Files to submit: `Makefile`, `main.cpp`, `PmergeMe.{cpp, hpp}`
- Forbidden: None
- Program name: `PmergeMe`
- The program takes a positive integer sequence as an argument.
- It must use the merge-insert sort algorithm (Ford-Johnson, Art of Computer Programming, Vol. 3, Merge Insertion, page 184) to sort that sequence.
- If an error occurs, an error message must be displayed on standard error.
- At least two different containers are required.
- The program must handle at least 3000 integers, duplicates included.
- Implement the algorithm for each container. Avoid a generic function.
- Standard output, line by line:
  1. An explicit text followed by the unsorted positive integer sequence.
  2. An explicit text followed by the sorted positive integer sequence.
  3. An explicit message indicating the time taken by the algorithm, specifying the first container.
  4. An explicit text indicating the time used by the algorithm, specifying the second container.
- The time format is free, but the precision must make the difference between the two containers clearly visible.
- The displayed time must cover all operations: both the sorting and the data management.
- Containers used in the previous exercises are forbidden here.
- How duplicates are treated as errors is left to the student's discretion.
- `shuf` and `jot` are only examples used to generate an input sequence. The program must handle any sequence of positive integers, including repeated values.

Example:

```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
```

### Code review

Check that a makefile is included with the usual compilation rules rules.

Check in the code that the program uses at least two containers.

If not, the evaluation stops here.

The person being evaluated must explain why they chose to use these containers and not another?

Check in the code that the merge-insert sort algorithm is present and is used for each container. The Ford-Johnson algorithm must be used. A brief explanation is expected. In case of doubt, the evaluation stops here.

If one of the containers chosen here is included in one of the previous exercises then the evaluation stops here.

- [ ] Yes
- [ ] No

### Main usage

You can now manually check that the program works correctly by using between 5 and 10 different positive integers of your choice as program arguments.

If this first test works and gives a sorted sequence of numbers you can continue. If not, the evaluation stops now.

Now you have to check this operation by using the following command as an argument to the program:

For linux:

```
shuf -i 1-1000 -n 3000 | tr "\n" " "
```

For OSX:

```
jot -r 3000 1 1000 | tr '\n' ' '
```

If the command works correctly, the person being evaluated should be able to explain the difference in time used for each container selected.

If there are any problems during the execution and/or explanation then the evaluation stops here.

- [ ] Yes
- [ ] No

## Subject: submission and peer-evaluation

- Turn in the assignment in the Git repository as usual. Only the work inside the repository is evaluated. Double-check folder and file names.
- During the evaluation, a brief modification of the project may occasionally be requested: a minor behaviour change, a few lines to write or rewrite, or an easy-to-add feature.
- This step may not apply to every project, but be prepared for it if it is mentioned in the evaluation guidelines.
- It is meant to verify actual understanding of a specific part of the project.
- The modification can be done in any development environment and should be feasible within a few minutes, unless a specific time frame is defined.
- Examples: a small update to a function or script, a display change, or adjusting a data structure to store new information.
- The details (scope, target, and so on) are specified in the evaluation guidelines and may vary from one evaluation to another for the same project.
