// Xing He, z5413977, 15/07/25
// Part 4.3: Reverse Command Line Arguments (Your Turn!)

#include <stdio.h>

int main(int argc, char *argv[]) {
    // Loop iterates through argv array in reverse
    for (int i = argc - 1; i > 0; i--) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
