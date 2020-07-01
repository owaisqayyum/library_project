#ifndef __MAIN_H_
#define __MAIN_H_

enum book_type {is_book, is_article};
typedef struct library_struct
{
    enum book_type type;
    void *item;
}library_struct;

typedef struct details_struct
{
    char title[50];
    int pages;
}details_struct;

// external variables
extern details_struct details[100];
extern library_struct library[100];

#endif // __MAIN_H_
