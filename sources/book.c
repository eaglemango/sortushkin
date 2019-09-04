#include "book.h"

struct Book OpenBook(char* file_path) {
    struct Book book = { .source = fopen(file_path, "rb") };

    fseek(book.source, 0, SEEK_END);

    book.file_size = ftell(book.source);

    fseek(book.source, 0, SEEK_SET);

    return book;
}

void CloseBook(struct Book book) {
    fclose(book.source);
}
