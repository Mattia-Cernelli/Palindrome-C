# Palindrome-C

The program handles palindrome strings through different memory notations: the pointer notation and the vector notation.
Defining function prototypes: Function prototypes are declared at the beginning, allowing the compiler to understand how to use functions before they are defined.

The store_vect function: This function allocates space for a copy of the user-entered string, then copies it using strcpy, and returns a pointer to the copy.

The pal function: This function takes a string as an argument and tests whether it is a palindrome or not using pointer notation. The logic appears to be correct, but there is an indentation error within the loop, which should be fixed for proper operation.

The search_pal function: This function searches for a palindrome string within the archive (data) using pointer notation. If it finds a match, it returns a pointer to that string, otherwise it returns NULL.

The reverse function: This function takes a string as an argument and returns a new string which is the reversed version of the original string, using pointer notation.

The count function: This function counts the number of vowels and consonants in a string using vector notation. The results are returned through the voc and cons pointers.

The main function: This is the main function of the program. Reads a string from the user, then calls various functions to perform operations on it. After that, print the results.
