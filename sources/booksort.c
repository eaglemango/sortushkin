#include "booksort.h"
#include <stdlib.h>

int PreprocessBook(struct Book book, char** lines_beginnings[], char** lines_ends[]) {
    char* buffer = book.contents + 1;

    int total_lines = 0;
    for (char* c = buffer; c < buffer + book.size + 1; ++c) {
        if (*c == '\n') {
            *c = '\0';

            ++total_lines;
        }
    }

    // На самом деле мы подсчитали количество переносов, осмысленных строк на одну больше
    ++total_lines;

    buffer[book.size] = '\0';

    *lines_beginnings = (char**) calloc(total_lines, sizeof(char));
    *lines_ends = (char**) calloc(total_lines, sizeof(char));

    int curr_line = 0;
    int is_beginning = 1;
    for (char* c = buffer; c <= buffer + book.size + 1; ++c) {
        if (is_beginning) {
            if (*c == '\0') {
                continue;
            }
            (*lines_beginnings)[curr_line] = c;

            is_beginning = 0;
        }

        if (*c == '\0') {
            if (*(c - 1) == '\0') {
                continue;
            }
            (*lines_ends)[curr_line] = c - 1;

            ++curr_line;

            is_beginning = 1;
        }
    }

    return total_lines;
}

int IsIgnored(char c) {
    return ('a' > c || c > 'z') && ('A' > c || c > 'Z');
}

int IsBigger(char* lhs, char* rhs) {
    if (*lhs == '\0' && *rhs != '\0') {
        return 0;
    } else if (*lhs != '\0' && *rhs == '\0') {
        return 1;
    } else if (*lhs == '\0' && *rhs == '\0') {
        return 1;
    }

    if (IsIgnored(*lhs)) {
        return IsBigger(lhs + 1, rhs);
    }

    if (IsIgnored(*rhs)) {
        return IsBigger(lhs, rhs + 1);
    }

    if (lhs[0] < rhs[0]) {
        return 1;

    } else if (lhs[0] == rhs[0]) {
        return IsBigger(lhs + 1, rhs + 1);

    } else {
        return 0;
    }
}

int IsReversedBigger(char* lhs, char* rhs) {
    if (*lhs == '\0' && *rhs != '\0') {
        return 0;
    } else if (*lhs != '\0' && *rhs == '\0') {
        return 1;
    } else if (*lhs == '\0' && *rhs == '\0') {
        return 1;
    }

    if (IsIgnored(*lhs)) {
        return IsReversedBigger(lhs - 1, rhs);
    }

    if (IsIgnored(*rhs)) {
        return IsReversedBigger(lhs, rhs - 1);
    }

    if (lhs[0] < rhs[0]) {
        return 1;

    } else if (lhs[0] == rhs[0]) {
        return IsReversedBigger(lhs - 1, rhs - 1);

    } else {
        return 0;
    }
}

void SortBook(struct Book book, enum SortType sort_type) {
    char** lines_beginnings, ** lines_ends;

    int lines_count = PreprocessBook(book, &lines_beginnings, &lines_ends);

    switch (sort_type) {
    case LEFT_TO_RIGHT:
        for (int i = 0; i < lines_count; ++i) {
            for (int j = 0; j < lines_count; ++j) {
                if (IsBigger(lines_beginnings[i], lines_beginnings[j])) {
                    char* temp = lines_beginnings[j];
                    lines_beginnings[j] = lines_beginnings[i];
                    lines_beginnings[i] = temp;
                }
            }
        }

        break;

    case RIGHT_TO_LEFT:
        for (int i = 0; i < lines_count; ++i) {
            for (int j = 0; j < lines_count; ++j) {
                if (IsReversedBigger(lines_ends[i], lines_ends[j])) {
                    char* temp = lines_ends[j];
                    lines_ends[j] = lines_ends[i];
                    lines_ends[i] = temp;

                    temp = lines_beginnings[j];
                    lines_beginnings[j] = lines_beginnings[i];
                    lines_beginnings[i] = temp;
                }
            }
        }

        break;

    default:
        break;
    }

    PrintSortedBook(lines_beginnings, lines_count);
}

void PrintSortedBook(char** book, int lines_count) {
    for (int i = 0; i < lines_count; ++i) {
        printf("%s\n", book[i]);
    }
}
