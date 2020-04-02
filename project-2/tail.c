/**
 * @file tail.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 31/Mar/2020
 * @brief IJC-DU2, příklad a)
 * @details Program that prints specified number of last lines of entered file.
 *          If no argument is entered, print last 10 lines by default.
 *          Compiled: g++ 9.3
 */

#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LEN 1023  // maximum length of line

// function to testing arguments, returns number of lines to print, -1 if error
int get_lines_len_arg(int argc, char *argv[]) {
    char *nvalue = NULL;
    int option_idx;  // getopt options' index
    opterr = 0;  // disable default error messages of getopt

    // get arguments via getopt
    while ((option_idx = getopt(argc, argv, "n:")) != -1) {
        switch (option_idx) {
        case 'n':
            nvalue = optarg;
            break;
        case '?':
            if (optopt == 'n') {
                fprintf (stderr, "Invalid option: '%c' requires an argument.\n", optopt);
            } else {
                fprintf (stderr, "Invalid option: '-%c'.\n", optopt);
            }
            return -1;
        default:
            fprintf(stderr, "Invalid option.");
            return -1;
        }
    }
    // parse the nvalue arguemnt
    int lines_len;
    if (nvalue == NULL) {
        lines_len = 10;
    } else {
        char *endptr;
        lines_len = strtol(nvalue, &endptr, 10);
        if (*endptr != '\0' || lines_len <= 0) {
            fprintf(stderr, "Optional argument of '-n' must be an integer greater than zero.\n");
            return -1;
        }
    }

    return lines_len;
}
 
int main(int argc, char *argv[]) {
    int lines_len = get_lines_len_arg(argc, argv);
    if (lines_len == -1) {
        return EXIT_FAILURE;
    }
    // use the file's input if there is one, otherwise use stdin
    FILE *stream = stdin;
    FILE *file = NULL;
    char *file_name = argv[optind];
    if (file_name != NULL) {
        file = fopen(file_name, "r");
        if (file == NULL) {
            fprintf(stderr, "Invalid file entered.\n");
            return EXIT_FAILURE;
        }
        stream = file;  // use file's input for stream
    }
    char line[MAX_LINE_LEN];
    char lines[lines_len][MAX_LINE_LEN];
    int line_idx = 0;
    int lines_found = 0;
    while (fgets(line, MAX_LINE_LEN, stream)) {
        strcpy(lines[line_idx], line);  // copy the line into lines array
        line_idx++;
        line_idx %= lines_len;
        lines_found++;
        if (line[strlen(line) - 1] != '\n') {  // could not read the whole line
            fprintf(stderr, "Line %d is longer than %d characters."
                " Skipping the rest of the line.\n", lines_found, MAX_LINE_LEN);
            fscanf(stream, "%*[^\n]\n"); // skip the rest of the line
        }
    }
    // number of entered lines to print is larger than count of lines in file
    if (lines_len > lines_found) {
        line_idx %= lines_found;  // adjust the line index
    }
    // output print
    for (size_t i = line_idx; i < (lines_len + line_idx) && i < (lines_found + line_idx); i++) {
        char *line = lines[i % lines_len];
        printf("%s", line);
        if (line[strlen(line) - 1] != '\n') {
            printf("\n");  // print new line if line hasn't got one
        }
    }

    if (file) {
        fclose(file);
    }
    return EXIT_SUCCESS;
}