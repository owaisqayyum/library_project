#ifndef __MAIN_H_
#define __MAIN_H_

#define SIZE 100

enum book_type {is_book, is_article};
typedef struct library_struct
{
    enum book_type type;
    void *item;
}library_struct;

typedef struct details_struct
{
    char *title;
    int pages;
}details_struct;

// external variables
extern details_struct details[SIZE];
extern library_struct library[SIZE];

#endif // __MAIN_H_
