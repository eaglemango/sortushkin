#pragma once

#include "book.h"

enum SortType {
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT
};

void PreprocessBook(struct Book book, char** words_beginnings[], char** words_ends[]);

void SortBook(struct Book book, enum SortType sort_type);
