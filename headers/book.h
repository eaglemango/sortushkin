#pragma once

#include <stdio.h>

struct Book {
    FILE* source;
    char* contents;
    long int size;
};

struct Book OpenBook(char* file_path);

void CloseBook(struct Book book);
