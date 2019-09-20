#include "book.h"
#include <stdlib.h>

struct Book OpenBook(char* file_path) {
    FILE* book_source = fopen(file_path, "rb");
    struct Book book = { .contents = NULL,
                         .size = 0l
                       };

    fseek(book_source, 0, SEEK_END);
    book.size = ftell(book_source);
    fseek(book_source, 0, SEEK_SET);

    book.contents = (char*) calloc(book.size + 2, sizeof(char));
    fread(book.contents + 1, sizeof(char), book.size, book_source);
    book.contents[0] = '\0';
    book.contents[book.size + 1] = '\0';

    fclose(book_source);

    return book;
}

void CloseBook(struct Book book) {
    free(book.contents);
}
