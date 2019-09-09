#pragma once

#include "book.h"

enum SortType {
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT
};

enum CompareType {
    CLASSIC,
    REVERSE
};

int PreprocessBook(struct Book book, char** lines_beginnings[], char** lines_ends[]);

int IsIgnored(char c);

int IsBigger(char* lhs, char* rhs, enum CompareType compare_type);

void SortBook(struct Book book, enum SortType sort_type);

void PrintSortedBook(char** book, int lines_count);
