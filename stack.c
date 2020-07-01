// write code below
// stack.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "main.h"
#include "queue.h"

// struct declarations
static stack_books book_s[100];
static stack_articles article_s[100];

static int top_b = -1, top_a = -1;

void push()
{
    if(top_b >= 99)
    {
        printf("Book Stack Overflow\n");
        exit(-1);
    }

    else if(top_a >= 99)
    {
        printf("Article Stack Overflow\n");
        exit(-1);
    }
    else
    {
        if(library[front].type == is_book)
        {
            top_b++;
            strcpy(book_s[top_b].b_title, items_queue[front].q_title);
            book_s[top_b].b_pages = items_queue[front].q_pages;
            printf("item %i is moved from queue to book stack\n", front+1);
            dequeue();
        }
        else if(library[front].type == is_article)
        {
            top_a++;
            strcpy(article_s[top_a].a_title, items_queue[front].q_title);
            article_s[top_a].a_pages = items_queue[front].q_pages;
            printf("item %i is moved from queue to articles stack\n", front+1);
            dequeue();
        }
    }
}

void display_book_stack()
{
    for (int i = top_b; i >=0 ; i--)
    {
        printf("top -> %i: Book %s with %i pages\n", i, book_s[i].b_title, book_s[i].b_pages);
    }
}

void display_article_stack()
{
    for (int i = top_a; i >=0 ; i--)
    {
        printf("top -> %i: Article %s with %i pages\n", i, article_s[i].a_title, article_s[i].a_pages);
    }
}

void pop_book_stack()
{
    if(top_b < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Book: %s with %i pages is popped from Stack\n", book_s[top_b].b_title, book_s[top_b].b_pages);
        top_b--;
    }
}

void pop_article_stack()
{
     if(top_b < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Article: %s with %i pages is popped from Stack\n", article_s[top_a].a_title, article_s[top_a].a_pages);
        top_a--;
    }
}
