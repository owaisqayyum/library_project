#ifndef __STACK_H_
#define __STACK_H_

typedef struct stack_books
{
    char b_title[50];
    int b_pages;
}stack_books;

typedef struct stack_articles
{
    char a_title[50];
    int a_pages;
}stack_articles;

// functions declaration
void push();
void display_book_stack();
void display_article_stack();
void pop_book_stack();
void pop_article_stack();

#endif // __STACK_H_
