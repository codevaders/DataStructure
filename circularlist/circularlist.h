/*
    CircularList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: July 31, 2015 
*/

#ifndef _CIRCULARLIST_H_
#define _CIRCULARLIST_H_

typedef struct circularlistnodetype
{
    int element;
    struct circularlistnodetype *link;
}
circularlistnode;

typedef struct circularlisttype
{
    int size;
    circularlistnode headernode;
}
circularlist;

extern circularlist *create_cl(void);
extern int delete_cl(circularlist *data);

extern int add_cl_element(circularlist *data, int position, circularlistnode element);
extern int add_cl_element_forward(circularlist *data, circularlistnode element);
extern int add_cl_element_backward(circularlist *data, circularlistnode element);

extern int remove_cl_element(circularlist *data, int position);
extern int remove_cl_element_forward(circularlist *data);
extern int remove_cl_element_backward(circularlist *data);

extern int get_cl_length(circularlist *data);
extern circularlistnode *get_cl_element(circularlist *data, int position);

extern void display_cl_element(circularlist *data);

#endif
