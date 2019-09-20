/*!
    @file
    @brief Header file with Book declaration

    Also contains \p OpenBook and \p CloseBook declaration
*/
#pragma once

#include <stdio.h>

/*!
    @brief Struct containing text's byte presentation and its size
*/
struct Book {
    char* contents;
    long int size;
};

/*!
    @brief Opens file from file_path path
    @param[in] file_path Path of file to open
    @param[out] book Ready-to-use object of struct Book 

    Allocates a block of memory, that is 2 bytes greater, than true text size,
    because it's important to have a '\0' symbol by the left and the right sides
*/
struct Book OpenBook(char* file_path);

/*!
    @brief Closes book
    @param[in] book Object of struct Book to close
    @param[out] . No return value
*/
void CloseBook(struct Book book);
