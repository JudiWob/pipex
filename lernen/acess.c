#include <unistd.h>
#include <stdio.h>


//access() checks real user ID and group ID, not effective ones.
//

int main() {
    const char *filename = "myfile.txt";

    if (access(filename, F_OK) == 0) {
        printf("File exists.\n");

        if (access(filename, R_OK) == 0) {
            printf("You can read the file.\n");
        }

        if (access(filename, W_OK) == 0) {
            printf("You can write to the file.\n");
        }

    } else {
        printf("File does not exist.\n");
    }

    return 0;
}


//Yes, you can combine permission checks in access() — but not with F_OK!
/*
if (access("myfile.txt", F_OK) == 0) {
    // File exists
    if (access("myfile.txt", R_OK | W_OK) == 0) {
        // Read and write permissions granted
    } else {
        // File exists but no read/write permission
    }
} else {
    // File doesn't exist
}
*/
