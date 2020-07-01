#ifndef __QUEUE_H_
#define __QUEUE_H_

typedef struct queue
{
    char q_title[50];
    int q_pages;
}queue;

// variables declarations
extern int rear, front;

// function declarations
void inqueue();
void dequeue();
void display_queue();

// struct declaration
extern queue items_queue[100];


#endif // __QUEUE_H_
