#include <stdio.h>

int main() {
    FILE* book = fopen("my_poem.txt", "rb");

    fseek(book, 0, SEEK_END);

    long int file_size = ftell(book);

    fseek(book, 0, SEEK_SET);

    fclose(book);

    return 0;
}
