/*
    ArrayList in C

    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: July 28, 2015
*/

#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

typedef struct arraylistnodetype
{
    int element;
}
arraylistnode;

typedef struct arraylisttype
{
    int maxsize;
    int currentsize;
    arraylistnode *element;
}
arraylist;

extern arraylist *create_al(int maxsize);
extern void delete_al(arraylist *data);

extern int add_al_element(arraylist *data, int position, arraylistnode element);
extern int add_al_element_forward(arraylist *data, arraylistnode element);
extern int add_al_element_backward(arraylist *data, arraylistnode element);

extern int remove_al_element(arraylist *data, int position);
extern int remove_al_element_forward(arraylist *data);
extern int remove_al_element_backward(arraylist *data);

extern void clear_al(arraylist *data);
extern bool is_al_full(arraylist *data);

extern int get_al_length(arraylist *data);
extern arraylistnode *get_al_element(arraylist *data, int position);

extern void display_al_element(arraylist *data);

#endif
