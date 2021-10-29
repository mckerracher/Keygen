#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function:
 * -------------------------
 *
 *
 * Parameters:
 * -------------------------
 *
 *
 * Returns:
 * -------------------------
 *
 */
int add_to_rand(int input) {
    int ret_val;

    if (input == 26) {
        ret_val = 32; // ASCII: 32 = " ".
    } else {
        ret_val = input + 65; // ASCII: 65 = A, 90 = Z.
    }

    return ret_val;
}

/*
 * This program creates a key file of specified length. The characters in the file generated
 * will be any of the 27 allowed characters, generated using the standard Unix randomization
 * methods. Do not create spaces every five characters, as has been historically done.
 */
int main(int argc, char *argv[]) {
    int loop_count = 0;
    srand(time(0));

    // Checks for the correct number of arguments.
    if (argc == 2) {
        int input_value;

        // Checks that a number was entered.
        if (atoi(argv[1])) {
            input_value = atoi(argv[1]);

            while (loop_count < input_value) {
                // generate random numbers
                printf("%c", add_to_rand(rand()%27));
                loop_count++;
            }
        } else {
            fprintf(stderr, "You must enter a number!\n");
        }
    } else {
        fprintf(stderr, "Only enter one argument.\n");
        return EXIT_FAILURE;
    }
    printf("\n");
    return EXIT_SUCCESS;
}
