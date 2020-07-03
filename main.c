// write code below

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "stack.h"
#include "queue.h"

// functions definitions
void library_details(void);
void stack_display(void);
void push_from_queue_to_stack(void);

//struct definitions
details_struct details[SIZE];
library_struct library[SIZE];

FILE *fp;
static int indexer = 0;

int main(void)
{

    fp = fopen("input.txt","r");

    library_details(); //inserting values of books and articles and adding them to queue
    push_from_queue_to_stack(); //moving items to respective stacks (book or article stack)
    stack_display(); // displaying stacks
    pop_book_stack(); // deleting an item from books stack
    pop_article_stack(); // deleting item from article stack
    stack_display(); // displaying the stack after poping values

    fclose(fp);
    return 0;
}

void library_details()
{
    static int choice;
    do
    {
        details[indexer].title = malloc(SIZE);
        if(details[indexer].title == NULL)
        {
            printf("Nothing to show\n");
        }
        
        printf("[1] : Book Title and Pages \n");
        printf("[2] : Article Title and Pages \n");
        printf("[3] : Exit\n");
        //scanf("%i",&choice);
        fscanf(fp, "%i\n", &choice);

        // test for files not existing.
        if (fp == NULL)
        {
            printf("Error! Could not open file\n");
            exit(-1);
        }

        if(choice == 1)
        {
            library[indexer].type = is_book;}
        else if(choice == 2)
        {
            library[indexer].type = is_article;}
        else
        {
            printf("Exit\n");
            break;}

        switch (choice)
        {
            case 1:
                printf("Book 'Title' and 'Pages'\n");
                fscanf(fp, "%[^\n]", details[indexer].title);
                fscanf(fp, "%i\n", &details[indexer].pages);
                library[indexer].type = is_book;
                inqueue(details, items_queue); // from details to queue
                break;
            case 2:
                printf("Article 'Title' and 'Pages'\n");
                fscanf(fp, "%[^\n]", details[indexer].title);
                fscanf(fp, "%i\n", &details[indexer].pages);
                library[indexer].type = is_article;
                inqueue(details, items_queue); // from details to queue
                break;
            default:
                printf("Exit");
                break;
        }
        indexer++;
    }while(choice==1 || choice==2);

    for (int i = 0; i < indexer; i++)
    {
        if(library[i].type == is_book)
        {
            printf("Item %i is book: %s with %i pages\n", i+1, details[i].title, details[i].pages);
        }
        else if(library[i].type == is_article)
        {
            printf("Item %i is article: %s with %i pages\n", i+1, details[i].title, details[i].pages);
        }
    }
}

void push_from_queue_to_stack()
{
    for (int i = front; i < rear; i++)
    {
        if(library[front].type == is_book)
        {
            push_book(book_s, items_queue); // from queue to  stack
            printf("item %i is moved from queue to book stack\n", front+1);
            dequeue();
        }
        else if(library[front].type == is_article)
        {
            push_article(article_s, items_queue);
            printf("item %i is moved from queue to articles stack\n", front+1);
            dequeue();
        }
    }
}

void stack_display()
{
    int display_choice;

    do
    {
        printf("Which stack do you want to display\n");
        printf("[1] : Books Stack\n");
        printf("[2] : Articles Stack\n");
        printf("[3] : Exit\n");
        fscanf(fp, "%i\n", &display_choice);
        
        switch (display_choice)
        {
            case 1:
                printf("Books Stack\n");
                display_book_stack(book_s);
                break;
            case 2:
                printf("Articles Stack\n");
                display_article_stack(article_s);
                break;
            case 3:
                printf("Exit\n");
                break;
        }

    }while(display_choice!=3);
    
}
