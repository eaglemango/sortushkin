#pragma once

#include <stdio.h>

struct Book {
    FILE* source;
    long int file_size;
};

struct Book OpenBook(char* file_path);

void CloseBook(struct Book book);
