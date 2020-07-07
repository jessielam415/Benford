#include <stdio.h>
#include <stdlib.h>

#include "benford_helpers.h"

/*
 * The only print statement that you may use in your main function is the following:
 * - printf("%ds: %d\n")
 *
 */
int main(int argc, char **argv) {

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "benford position [datafile]\n");
        return 1;
    }
    // TODO: Implement.
    int position = strtol(argv[1], NULL, 10);
    int tally[BASE];
    for (int i = 0; i < BASE; i++){
        tally[i] = 0;
    }
    int input_int;
    if (argc == 3) {
        FILE *file;
        file = fopen(argv[2], "r");
        while (fscanf(file, "%d", &input_int) == 1) {
            add_to_tally(input_int, position, tally);
        }
        for (int p = 0; p < BASE; p++){
            printf("%ds: %d\n", p, tally[p]);
        }
        fclose(file);
        return 0;
    } 

    while(scanf("%d", &input_int) != EOF){
        add_to_tally(input_int, position, tally);
    }
    for (int p = 0; p < BASE; p++){
        printf("%ds: %d\n", p, tally[p]);
    }
    return 0;
}
