#ifndef __STACK_H_
#define __STACK_H_

#include "queue.h"

typedef struct stack_books
{
    char *b_title;
    int b_pages;
}stack_books;

typedef struct stack_articles
{
    char *a_title;
    int a_pages;
}stack_articles;

// functions declaration
void push_book(stack_books *b, queue *q);
void push_article(stack_articles *a, queue *q);
void display_book_stack(stack_books *b);
void display_article_stack(stack_articles *b);
void pop_book_stack();
void pop_article_stack();

// structs declarations
stack_books book_s[SIZE];
stack_articles article_s[SIZE];

#endif // __STACK_H_
