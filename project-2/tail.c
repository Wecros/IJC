/**
 * @file tail.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad 1)
 * @details Program that prints specified number of last lines of entered file.
 *          If no argument is entered, print last 10 lines by default.
 *          If positive n argument is entered, skip the n lines and print
 *          Exit codes: 0 - exited normally
 *                      1 - exited with encountered long line
 *                      2 - program terminated, exit failure
 *          the rest of the file.
 *          Compiled: gcc 9.3
 */

#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>  // error exit

#define MAX_LINE_LEN 1023  // maximum length of line
#define EXIT_SUCCESS   0   // exited normally
#define EXIT_LONG_LINE 1   // exited with encountered long line
#define EXIT_ERROR     2   // program terminated, exit failure

// Exits program with custom error message and errcode 1
void error_exit(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    fputs("ERROR: ", stderr);
    vfprintf(stderr, fmt, ap);

    va_end(ap);
    exit(EXIT_ERROR);
}

// function to testing arguments, returns number of lines to print, -1 if error
// returns positive lines count if the argument is passed in standard way
// returns negative lines count if the argument is passed with '+' prefix
int get_lines_len_arg(int argc, char *argv[], bool *use_skipping) {
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
    int lines_cnt;
    if (nvalue == NULL) {
        lines_cnt = 10;
    } else {
        char *endptr;
        lines_cnt = strtol(nvalue, &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Optional argument of '-n' must be an integer.\n");
            return -1;
        }
        if (nvalue[0] == '+') {
            *use_skipping = true;
        }
    }

    return abs(lines_cnt);
}

// get the stream from which to read the lines, NULL if could not open file
FILE *get_stream(char *argv[]) {
    // use the file's input if there is one, otherwise use stdin
    FILE *stream = stdin;
    FILE *file = NULL;
    char *file_name = argv[optind];
    if (file_name != NULL) {
        file = fopen(file_name, "r");
        if (file == NULL) {
            fprintf(stderr, "Invalid file entered.\n");
            return NULL;
        }
        stream = file;  // use file's input for stream
    }
    return stream;
}

// Function for outputting error if line is longer than limit, skip the rest
void output_line_over_limit(int lines_found, FILE *stream) {
    fprintf(stderr, "Line %d is longer than %d characters."
        " Skipping the rest of the line.\n", lines_found, MAX_LINE_LEN);
    fscanf(stream, "%*[^\n]\n"); // skip the rest of the line
}

// Function for outputting standard tail
int output_standard_tail(int lines_cnt, FILE *stream) {
    int retcode = EXIT_SUCCESS;
    // dynamically alocate lines
    char **lines = (char **) malloc(lines_cnt * sizeof(char *));
    if (lines == NULL) {
        error_exit("Allocation of memory failed.\n");
    }
    for (int i = 0; i < lines_cnt; i++) {
        lines[i] = (char *) malloc((MAX_LINE_LEN) * sizeof(char));
        if (lines[i] == NULL) {
            error_exit("Allocation of memory failed.\n");
        }
    }
    int line_idx = 0;
    int lines_found = 0;
    while (fgets(lines[line_idx], MAX_LINE_LEN, stream)) {
        char *line = lines[line_idx];
        line_idx++;
        line_idx %= lines_cnt; // rotate the line_idx according to lines count
        lines_found++;
        if (line[strlen(line) - 1] != '\n') { // could not read the whole line
            output_line_over_limit(lines_found, stream);
            retcode = EXIT_LONG_LINE;
        }
    }
    if (lines_found == 0) {
        return retcode; // empty file
    }
    // number of entered lines to print is larger than count of lines in file
    if (lines_cnt > lines_found) {
        line_idx %= lines_found;  // adjust the line index
    }
    // output print
    for (int i = line_idx; i < (lines_cnt + line_idx) && i < (lines_found + line_idx); i++) {
        char *line = lines[i % lines_cnt];
        printf("%s", line);
        if (line[strlen(line) - 1] != '\n') {
            printf("\n");  // print new line if line hasn't got one
        }
    }
    // free the memory
    for (int i = 0; i < lines_cnt; i++) {
        free(lines[i]);
    }
    free(lines);
    return retcode;
}

// Function for outputting skipping tail, using 'tail -n +3' arg
int output_skipping_tail(int lines_cnt, FILE* stream) {
    int retcode = EXIT_SUCCESS;
    int lines_found = 0;
    char *line = (char *) malloc((MAX_LINE_LEN) * sizeof(char));
    if (line == NULL) {
        error_exit("Allocation of memory failed.\n");
    }
    while (fgets(line, MAX_LINE_LEN, stream)) {
        lines_found++;
        if (line[strlen(line) - 1] != '\n') { // could not read the whole line
            output_line_over_limit(lines_found, stream);
            retcode = EXIT_LONG_LINE;
        }
        if (lines_found >= lines_cnt) {
            if (line[strlen(line) - 1] != '\n') { // could not read the whole line
                printf("%s\n", line);
            } else {
                printf(line);
            }
        }
    }
    free(line);
    return retcode;
}

int main(int argc, char *argv[]) {
    int retcode = EXIT_SUCCESS;
    bool use_skipping = false;  // flag for whether to use skipping or not
    // get lines count and decide from which stream to read
    int lines_cnt = get_lines_len_arg(argc, argv, &use_skipping);
    if (lines_cnt == -1) {
        return EXIT_ERROR;
    }
    FILE *stream = get_stream(argv);
    if (stream == NULL) {
        return EXIT_ERROR;
    }

    if (use_skipping) {
        retcode = output_skipping_tail(lines_cnt, stream);
    } else if (lines_cnt > 0) {
        retcode = output_standard_tail(lines_cnt, stream);
    }
    // close the file
    if (stream != stdin) {
        fclose(stream);
    }
    return retcode;
}
