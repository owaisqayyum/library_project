// write code belo
// queue.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "main.h"

int rear = 0, front = 0;
queue items_queue[SIZE];

void inqueue(details_struct *d, queue *q)
{
    if(front > rear)
    {
        printf("Queue overflow\n");
        exit(-1);
    }
    else
    {
        q[rear].q_title = malloc(SIZE);
        if(q[rear].q_title == NULL)
        {
            printf("Nothing to show\n");
        }
        strcpy(q[rear].q_title, d[rear].title);
        q[rear].q_pages = d[rear].pages;
        printf("Item %i added to queue\n", rear+1) ;
        rear++;
    }
}

void dequeue()
{
    if((front == 0) && (rear == 0))
    {
        printf("Queue Underflow or Empty\n");
        exit(-1);
    }
    else
    {
        printf("Item %i deleted from queue\n", front+1) ;
        front++;
    }
}

void display()
{
    printf("Displaying Queue: \n");
    for (int i = front; i < rear; i++)
    {
        if(library[i].type == is_book)
        {
            printf("Front -> %i, Rear -> %i: Book name: %s having %i pages\n",
               front, rear, items_queue[front].q_title, items_queue[front].q_pages);
        }
        else if (library[i].type == is_article)
        {
        printf("Front -> %i, Rear -> %i: Article name: %s having %i pages\n",
               front, rear, items_queue[front].q_title, items_queue[front].q_pages);
        }
    }
    
}
