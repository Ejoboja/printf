This README file provides information about the requirements, tasks, and guidelines for the Printf Project, which involves implementing a custom version of the printf function in C.

Requirements
General
You are allowed to use the following editors: vi, vim, and emacs.
All source files will be compiled on Ubuntu 20.04 LTS using gcc with the following options: -Wall -Werror -Wextra -pedantic -std=gnu89.
All source code files should end with a new line.
A README.md file at the root of your project folder is mandatory.
Your code should follow the Betty style, which will be checked using betty-style.pl and betty-doc.pl.
You are not allowed to use global variables.
Each source file should contain no more than 5 functions.
Prototypes of all your functions should be included in a header file named main.h.
Don't forget to push your header file.
All header files should be include guarded.
You should not use the _putchar function; you need to implement your own.
GitHub
There should be one project repository per group. The other members should not fork or clone the project. Only one team member should have the repository in their GitHub account to avoid scoring 0%.
Authorized Functions and Macros
You are allowed to use the following functions and macros:

write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)
Compilation
Your code will be compiled using the following command:

bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
Make sure not to push any C file containing a main function in the root directory of your project. You can create a test folder to contain all your test files, including main functions. Our main files will include your main header file (main.h).

You might want to look at the gcc flag -Wno-format when testing with your _printf and the standard printf.

Tasks
Task 0: I'm not going anywhere
Prototype: int _printf(const char *format, ...)
Returns: the number of characters printed (excluding the null byte used to end output to strings).
Write output to stdout (the standard output stream).
Handle the following conversion specifiers: c, s, %.
You don't have to reproduce the buffer handling of the C library printf function.
You don't have to handle flag characters, field width, precision, or length modifiers.
Task 1: Education is when you read the fine print
Handle the following conversion specifiers: d, i.
You don't have to handle flag characters, field width, precision, or length modifiers.
Task 2: With a face like mine, I do better in print (Advanced)
Handle the custom conversion specifier: %b. The unsigned int argument is converted to binary.
Task 3: What one has not experienced, one will never understand in print (Advanced)
Handle the following conversion specifiers: u, o, x, X.
You don't have to handle flag characters, field width, precision, or length modifiers.
Task 4: Nothing in fine print is ever good news (Advanced)
Use a local buffer of 1024 chars to call write as little as possible.
Task 5: My weakness is wearing too much leopard print (Advanced)
Handle the custom conversion specifier: %S. Prints the string, with non-printable characters represented as \x followed by the ASCII code value in hexadecimal (always 2 characters).
Task 6: How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print (Advanced)
Handle the conversion specifier: p.
You don't have to handle flag characters, field width, precision, or length modifiers.
Task 7: The big print gives, and the small print takes away (Advanced)
Handle the following flag characters for non-custom conversion specifiers: +, space, #.
Task 8: Sarcasm is lost in print (Advanced)
Handle the following length modifiers for non-custom conversion specifiers: l, h.
Task 9: Print some money and give it to us for the rain forests (Advanced)
Handle field width for non-custom conversion specifiers.
Task 10: The negative is the equivalent of the composer's score, and the print the performance (Advanced)
Handle precision for non-custom conversion specifiers.
Task 11: It's depressing when you're still around, and your albums are out of print (Advanced)
Handle the 0 flag character for non-custom conversion specifiers.
Task 12: Every time that I wanted to give up, if I saw an interesting textile, print whatever, suddenly I would see a collection (Advanced)
Handle the - flag character for non-custom conversion specifiers.
Task 13: Print is the sharpest and the strongest weapon of our party (Advanced)
Handle the custom conversion specifier: %r. Prints the reversed string.
Task 14: The flood of print has turned reading into a process of gulping rather than savoring (Advanced)
Handle the custom conversion specifier: %R. Prints the ROT13'ed string.
Task 15: All the above options work well together (Advanced)
Collaboration
We strongly encourage you to work together as a team on creating a set of tests.

Copyright and Plagiarism
You are required to come up with solutions for the tasks yourself to meet the learning objectives. Copying and pasting someone else's work is strictly forbidden and will result in removal from the program.
