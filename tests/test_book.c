#include <assert.h>
#include "book.h"
#include <stdio.h>

int TestInit() {
    FILE* test_file = fopen("testfile.txt", "wb");
    fclose(test_file);

    struct Book book = OpenBook("testfile.txt");
    assert(book.size == 0);
    CloseBook(book);

    remove("testfile.txt");

    return 0;
}

int TestUnemptyBook() {
    FILE* test_file = fopen("testfile.txt", "wb");
    fprintf(test_file, "Two words");
    fclose(test_file);

    struct Book book = OpenBook("testfile.txt");
    assert(book.size == 9);
    CloseBook(book);

    remove("testfile.txt");

    return 0;
}

int main() {
    TestInit();
    TestUnemptyBook();

    return 0;
}
