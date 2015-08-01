/*
    DoublyLinkedList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: August 1, 2015 
*/

#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

typedef struct doublylinkedlistnodetype
{
    int element;
    struct doublylinkedlistnodetype *prev_link;
    struct doublylinkedlistnodetype *next_link;
}
doublylinkedlistnode;

typedef struct doublylinkedlisttype
{
    int size;
    doublylinkedlistnode headernode;
}
doublylinkedlist;

extern doublylinkedlist *create_dll(void);
extern int delete_dll(doublylinkedlist *data);

extern int add_dll_element(doublylinkedlist *data, int position, doublylinkedlistnode element);
extern int add_dll_element_forward(doublylinkedlist *data, doublylinkedlistnode element);
extern int add_dll_element_backward(doublylinkedlist *data, doublylinkedlistnode element);

extern int remove_dll_element(doublylinkedlist *data, int position);
extern int remove_dll_element_forward(doublylinkedlist *data);
extern int remove_dll_element_backward(doublylinkedlist *data);

extern int get_dll_length(doublylinkedlist *data);
extern doublylinkedlistnode *get_dll_element(doublylinkedlist *data, int position);

extern void display_dll_element(doublylinkedlist *data);

#endif
