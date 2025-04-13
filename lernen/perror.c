/*



Both perror() and strerror() are used to display or retrieve 
human-readable error messages in C. 

✅ strerror() — When you want full control over formatting or output
    printf("Could not open file: %s\n", strerror(errno));
✅ perror() - Pros: Prints to stderror, Simple and fast, not 100% customizable
    perror("fopen failed");

They both use the global variable:

extern int errno;

This is defined in <errno.h>
It's automatically set when many standard library functions fail 
like: open(), read(), malloc(), etc.

Example
1. fopen() fails → it sets errno

2. You then call perror() or strerror(errno) → they use the current value of errno


✅ To print only the system error message:
If you want only the error message with no colon or prefix, then use strerror():

STRERROR--------------------------
FILE *f = fopen("file.txt", "r");
if (!f) {
    printf("%s\n", strerror(errno));
}
TERMINAL >> No such file or directory


PERROR:---------------------------
FILE *f = fopen("file.txt", "r");
if (!f) {
    perror("");
}
Terminal>>  : No such file or directory
!You’ll get a colon and a space : before the message — not completely clean, but close.


-----------------------
void perror(const char *s);
    -Prints my custom message (s),
    -then Automatically adds errno message
    -Prints to stderr!

    perror("Error opening file");
    output:
    ->Error opening file: No such file or directory

    ✅ perror() itself is declared in <stdio.h>
    ✅ But it prints an error message based on the value of the global variable errno, 
       which is declared in <errno.h>

Example

    #include <stdio.h>    // for perror() and printf
    #include <errno.h>    // for errno

    int main() {
        FILE *f = fopen("missingfile.txt", "r");
        if (!f) {
            perror("Error opening file");
        }
        return 0;
    }
    >>Terminal: Error opening file: No such file or directory

------------------------
char *strerror(int errnum);
    -Returns a string describing the error code you give it.
    -Often used with errno.
    -outputs anywhere
    
    printf("Error: %s\n", strerror(errno));
    output:
    ->Error: No such file or directory

    ✅ strerror() itself is declared in <string.h>
    ✅ But it prints an error message based on the value of the global variable errno, 
       which is declared in <errno.h>

Example
    #include <stdio.h>     // for printf
    #include <string.h>    // for strerror
    #include <errno.h>     // for errno

    int main() {
        FILE *f = fopen("nofile.txt", "r");
        if (!f) {
           printf("Error: %s\n", strerror(errno));
       }
       return 0;
    }
*/