/*!
    @file
    @brief Contains definitions of all functions from booksort.h
*/
#include <assert.h>
#include "booksort.h"
#include <stdlib.h>
#include <string.h>

int PreprocessBook(struct Book book, char** lines_beginnings[], char** lines_ends[]) {
    int total_lines = 0;
    char* c = strchr(book.contents + 1, '\n');
    while (c < book.contents + book.size + 2 && c != NULL) {
        char* temp = c;
        c = strchr(c + 1, '\n');
        *temp = '\0';

        if (*(temp - 1) != '\0') {
            ++total_lines;
        }
    }

    *lines_beginnings = (char**) calloc(total_lines, sizeof(char*));
    assert(lines_beginnings != NULL);

    *lines_ends = (char**) calloc(total_lines, sizeof(char*));
    assert(lines_ends != NULL);

    int curr_line = 0;
    for (char* c = book.contents; c < book.contents + book.size + 2; ++c) {
        if (*c != '\0' && *(c + 1) == '\0') {
            (*lines_ends)[curr_line] = c;

            ++curr_line;

        } else if (*c == '\0' && *(c + 1) != '\0') {
            (*lines_beginnings)[curr_line] = c + 1;
        }
    }

    return total_lines;
}

int IsIgnored(char c) {
    return ('a' > c || c > 'z') && ('A' > c || c > 'Z');
}

int IsBigger(char* lhs, char* rhs, enum CompareType compare_type) {
    assert(lhs != NULL);
    assert(rhs != NULL);

    if (*lhs == '\0' || *rhs == '\0') {
        return *rhs == '\0';
    }

    int shift = (compare_type == CLASSIC ? 1 : -1);

    if (IsIgnored(*lhs)) {
        return IsBigger(lhs + shift, rhs, compare_type);
    }

    if (IsIgnored(*rhs)) {
        return IsBigger(lhs, rhs + shift, compare_type);
    }
    
    if (*lhs < *rhs) {
        return 1;

    } else if (*lhs == *rhs) {
        return IsBigger(lhs + shift, rhs + shift, compare_type);

    } else {
        return 0;
    }
}

void Swap(char** lhs, char** rhs) {
    assert(*lhs != NULL);
    assert(*rhs != NULL);

    char* temp = *rhs;
    *rhs = *lhs;
    *lhs = temp;
}

void SortBook(struct Book book, enum SortType sort_type) {
    char** lines_beginnings = NULL, ** lines_ends = NULL;

    int lines_count = PreprocessBook(book, &lines_beginnings, &lines_ends);

    if (sort_type != LEFT_TO_RIGHT) {
        for (int i = 0; i < lines_count; ++i) {
            for (int j = 0; j < lines_count; ++j) {
                if (IsBigger(lines_ends[i], lines_ends[j], REVERSE)) {
                    Swap(&lines_ends[i], &lines_ends[j]);
                    Swap(&lines_beginnings[i], &lines_beginnings[j]);
                }
            }
        }

        printf("[ Book in reversed lexicographic order ]\n---\n");
        PrintSortedBook(lines_beginnings, lines_count);
        printf("---\n\n");
    }

    if (sort_type != RIGHT_TO_LEFT) {
        for (int i = 0; i < lines_count; ++i) {
            for (int j = 0; j < lines_count; ++j) {
                if (IsBigger(lines_beginnings[i], lines_beginnings[j], CLASSIC)) {
                    Swap(&lines_beginnings[i], &lines_beginnings[j]);
                }
            }
        }

        printf("[ Book in direct lexicographic order ]\n---\n");
        PrintSortedBook(lines_beginnings, lines_count);
        printf("---\n");
    }

    free(lines_beginnings);
    free(lines_ends);
}

void PrintSortedBook(char** book, int lines_count) {
    assert(book != NULL);

    for (int i = 0; i < lines_count; ++i) {
        printf("%s\n", book[i]);
    }
}
