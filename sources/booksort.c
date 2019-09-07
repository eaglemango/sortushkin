#include "booksort.h"
#include <stdlib.h>

void PreprocessBook(struct Book book, char** words_beginnings[], char** words_ends[]) {
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
}

void SortBook(struct Book book, enum SortType sort_type) {
    char** words_beginnings, ** words_ends;

    PreprocessBook(book, &words_beginnings, &words_ends);
}
