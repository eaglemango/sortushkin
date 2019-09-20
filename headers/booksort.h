/*!
    @file
    @brief Header file with declarations of functions for sorting
*/
#pragma once

#include "book.h"

enum SortType {
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT,
    BOTH
};

enum CompareType {
    CLASSIC,
    REVERSE
};

/*!
    @brief Prepares Book object for future sorting
    @param[in] book Object of struct Book to preprocess
    @param[in] lines_beginnings Pointer to array of pointers to beginnings of lines
    @param[in] lines_ends Pointer to arrat of pointers to ends of lines
    @param[out] lines_count Total lines in book
*/
int PreprocessBook(struct Book book, char** lines_beginnings[], char** lines_ends[]);

/*!
    @brief Checks if symbol need to be ignored (only latin letters pass)
    @param[in] c Symbol to check
    @param[out] is_ignored 1 if ignored, 0 otherwise
*/
int IsIgnored(char c);

/*!
    @brief Compares two c-style strings
    @param[in] lhs First string
    @param[in] rhs Second string
    @param[in] compare_type Type of comparation (for classic or for reversed strings)
    @param[out] is_bigger 1 if bigger, 0 otherwise
*/
int IsBigger(char* lhs, char* rhs, enum CompareType compare_type);

/*!
    @brief Swaps two c-style strings
    @param[in] lhs First string
    @param[in] rhs Second string
*/
void Swap(char** lhs, char** rhs);

/*!
    @brief Sorts book and prints result to stdout
    @param[in] book Object of struct Book to sort
    @param[in] sort_type Type of sorting
*/
void SortBook(struct Book book, enum SortType sort_type);

/*!
    @brief Prints an array of lines to stdout
    @param[in] book Array of pointers to c-style strings
    @param[in] lines_count Number of lines to print
*/
void PrintSortedBook(char** book, int lines_count);
