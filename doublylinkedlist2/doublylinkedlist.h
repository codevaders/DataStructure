/*
    DoublyLinkedList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: August 1, 2015 
*/

#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

#include "../common.h"

typedef struct doublylinkedlistnodetype
{
    int element;
    struct doublylinkedlistnodetype *prevlink;
    struct doublylinkedlistnodetype *nextlink;
}
doublylinkedlistnode;

typedef struct doublylinkedlisttype
{
    int size;
    doublylinkedlistnode headernode;
    /*                   headernode.prevlink == tail (last node)
                         headernode.nextlink == head (first node)   */
}
doublylinkedlist;

extern doublylinkedlist     *dll_create             (void);

extern int                   dll_get_length         (doublylinkedlist *data);
extern bool                  dll_is_not_empty       (doublylinkedlist *data);
extern bool                  dll_is_more_than_half  (doublylinkedlist *data, int position);
extern int                   dll_get_real_position  (doublylinkedlist *data, int position);

extern int                   dll_add_element        (doublylinkedlist *data, int position, doublylinkedlistnode node);

extern int                   dll_remove_element     (doublylinkedlist *data, int position);
extern int                   dll_clear              (doublylinkedlist *data);
extern int                   dll_delete             (doublylinkedlist *data);

extern doublylinkedlistnode *dll_get_element        (doublylinkedlist *data, int position);

extern int                   dll_interate           (doublylinkedlist *data);
extern int                   dll_reverse            (doublylinkedlist *data);
extern doublylinkedlist     *dll_concentrate        (doublylinkedlist *data_head, doublylinkedlist *data_tail);
extern doublylinkedlist     *dll_divide             (doublylinkedlist *data, int position);

#endif
