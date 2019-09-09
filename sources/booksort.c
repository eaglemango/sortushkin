#include "booksort.h"
#include <stdlib.h>

int PreprocessBook(struct Book book, char** words_beginnings[], char** words_ends[]) {
    char* buffer = book.contents;

    int lines_count = 0;
    for (char* c = buffer; c < buffer + book.size + 1; ++c) {
        if (*c == '\n') {
            *c = '\0';

            ++lines_count;
        }
    }

    // На самом деле мы подсчитали количество переносов, осмысленных строк на одну больше
    ++lines_count;

    buffer[book.size] = '\0';

    *words_beginnings = (char**) calloc(lines_count, sizeof(char));
    *words_ends = (char**) calloc(lines_count, sizeof(char));

    int words_count = 0;
    int is_beginning = 1;
    for (char* c = buffer; c <= buffer + book.size + 1; ++c) {
        if (is_beginning) {
            (*words_beginnings)[words_count] = c;

            is_beginning = 0;
        }

        if (*c == '\0') {
            (*words_ends)[words_count] = c;
            ++words_count;

            is_beginning = 1;
        }
    }

    return lines_count;
}

int IsBigger(char* lhs, char* rhs) {
    if (*lhs == '\0' && *rhs != '\0') {
        return 0;
    } else if (*lhs != '\0' || *rhs == '\0') {
        return 1;
    }

    if (lhs[0] > rhs[0]) {
        return 1;

    } else if (lhs[0] == rhs[0]) {
        return IsBigger(lhs + 1, rhs + 1);

    } else {
        return 0;
    }
}

void SortBook(struct Book book, enum SortType sort_type) {
    char** words_beginnings, ** words_ends;

    int lines_count = PreprocessBook(book, &words_beginnings, &words_ends);

    switch (sort_type) {
    case LEFT_TO_RIGHT:
        for (int i = 0; i < lines_count; ++i) {
            for (int j = 0; j < lines_count; ++j) {
                if (IsBigger(words_beginnings[i], words_beginnings[j])) {
                    char* temp = words_beginnings[j];
                    words_beginnings[j] = words_beginnings[i];
                    words_beginnings[i] = temp;
                }
            }
        }

        break;

    case RIGHT_TO_LEFT:

        break;

    default:
        break;
    }
}
