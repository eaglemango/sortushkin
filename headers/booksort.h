#pragma once

#include "book.h"

enum SortType {
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT
};

int PreprocessBook(struct Book book, char** words_beginnings[], char** words_ends[]);

int IsIgnored(char c);

int IsBigger(char* lhs, char* rhs);

int IsReversedBigger(char* lhs, char* rhs);

void SortBook(struct Book book, enum SortType sort_type);

void PrintSortedBook(char** book, int lines_count);
