#include "book.h"
#include "booksort.h"
#include <stdio.h>

int main() {
    struct Book book = OpenBook("my_poem.txt");

    SortBook(book, BOTH);

    CloseBook(book);

    return 0;
}
