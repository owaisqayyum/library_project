#ifndef __QUEUE_H_
#define __QUEUE_H_
#include "main.h"
//#define SIZE 100

typedef struct queue
{
    char *q_title;
    int q_pages;
}queue;

// variables declarations
extern int rear, front;

// function declarations
void inqueue(details_struct *d, queue *q);
void dequeue();
void display_queue();

// struct declaration
extern struct queue items_queue[SIZE];


#endif // __QUEUE_H_
