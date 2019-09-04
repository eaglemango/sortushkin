#include "book.h"
#include <stdio.h>

int main() {
    struct Book book = OpenBook("my_poem.txt");

    printf("Book Size: %ld words", book.file_size);

    CloseBook(book);

    return 0;
}
