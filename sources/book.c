#include "book.h"
#include <stdlib.h>

struct Book OpenBook(char* file_path) {
    struct Book book = { .source = fopen(file_path, "rb"),
                         .contents = NULL,
                         .size = 0l
                       };

    fseek(book.source, 0, SEEK_END);
    book.size = ftell(book.source);
    fseek(book.source, 0, SEEK_SET);

    book.contents = (char*) calloc(book.size + 2, sizeof(char));
    fread(book.contents + 1, sizeof(char), book.size, book.source);
    book.contents[0] = '\0';
    book.contents[book.size + 1] = '\0';

    return book;
}

void CloseBook(struct Book book) {
    fclose(book.source);
}
