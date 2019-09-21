#!/bin/sh

echo "Starting unit tests..."

echo "Compiling test_book.c"

gcc -Iheaders sources/book.c tests/test_book.c -g -o test_book

echo "Running test_book"
./test_book

if [[ $? = 0 ]]
then
    echo "test_book OK"
else
    echo "test_book FAIL"
fi

rm test_book

echo "Compiling test_booksort.c"

gcc -Iheaders sources/book.c sources/booksort.c tests/test_booksort.c -g -o test_booksort

echo "Running test_booksort"
./test_booksort

if [[ $? = 0 ]]
then
    echo "test_booksort OK"
else
    echo "test_booksort FAIL"
fi

rm test_booksort

echo "Tests done!"
