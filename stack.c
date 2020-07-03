// write code below
// stack.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "main.h"
#include "queue.h"

// struct declarations
stack_books book_s[SIZE];
stack_articles article_s[SIZE];

static int top_b = -1, top_a = -1;

void push_book(stack_books *b, queue *q)
{
    if(top_b >= 99)
    {
        printf("Book Stack Overflow\n");
        exit(-1);
    }

    else
    {
        top_b++;
        b[top_b].b_title = malloc(SIZE);
        
        if(b[top_b].b_title == NULL)
        {
            printf("Nothing to Show\n");
        }
        
        strcpy(b[top_b].b_title, q[front].q_title);
        b[top_b].b_pages = q[front].q_pages;
    }
}

void push_article(stack_articles *a, queue *q)
{
    if(top_a >= 99)
    {
        printf("Article Stack Overflow\n");
        exit(-1);
    }
    else
    {
        top_a++;
        a[top_a].a_title = malloc(SIZE);
        
        if(a[top_a].a_title == NULL)
        {
            printf("Nothing to Show\n");
        }
        
        strcpy(a[top_a].a_title, q[front].q_title);
        a[top_a].a_pages = q[front].q_pages;
    }
}


void display_book_stack(stack_books *b)
{
    for (int i = top_b; i >=0 ; i--)
    {
        printf("top -> %i: Book %s with %i pages\n", i, b[i].b_title, b[i].b_pages);
    }
}

void display_article_stack(stack_articles *a)
{
    for (int i = top_a; i >=0 ; i--)
    {
        printf("top -> %i: Article %s with %i pages\n", i, a[i].a_title, a[i].a_pages);
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
