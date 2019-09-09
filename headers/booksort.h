#pragma once

#include "book.h"

enum SortType {
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT
};

int PreprocessBook(struct Book book, char** words_beginnings[], char** words_ends[]);

int CompareStrings(char* lhs, char* rhs);

void SortBook(struct Book book, enum SortType sort_type);
