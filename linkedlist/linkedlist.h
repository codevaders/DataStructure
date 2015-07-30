/*
    LinkedList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: July 30, 2015 
*/

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct linkedlistnodetype
{
    int element;
    struct linkedlistnodetype *link;
}
linkedlistnode;

typedef struct linkedlisttype
{
    int size;
    linkedlistnode headernode;
}
linkedlist;

extern linkedlist *create_ll(void);
extern int delete_ll(linkedlist *data);

extern int add_ll_element(linkedlist *data, int position, linkedlistnode element);
extern int add_ll_element_forward(linkedlist *data, linkedlistnode element);
extern int add_ll_element_backward(linkedlist *data, linkedlistnode element);

extern int remove_ll_element(linkedlist *data, int position);
extern int remove_ll_element_forward(linkedlist *data);
extern int remove_ll_element_backward(linkedlist *data);

extern int get_ll_length(linkedlist *data);
extern linkedlistnode *get_ll_element(linkedlist *data, int position);

extern void display_ll_element(linkedlist *data);

#endif
