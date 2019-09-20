#include <assert.h>
#include "book.h"
#include <stdlib.h>

struct Book OpenBook(char* file_path) {
    FILE* book_source = fopen(file_path, "rb");
    assert(book_source != NULL);

    struct Book book = { .contents = NULL,
                         .size = 0l
                       };

    fseek(book_source, 0, SEEK_END);
    book.size = ftell(book_source);
    fseek(book_source, 0, SEEK_SET);

    book.contents = (char*) calloc(book.size + 2, sizeof(char));
    assert(book.contents != NULL);

    int read_count = fread(book.contents + 1, sizeof(char), book.size, book_source);
    assert(read_count == book.size);

    book.contents[0] = '\0';
    book.contents[book.size + 1] = '\0';

    int close_result = fclose(book_source);
    assert(close_result != EOF);

    return book;
}

void CloseBook(struct Book book) {
    free(book.contents);
}
