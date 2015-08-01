/*
    DoublyLinkedList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: August 1, 2015 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublylinkedlist.h"

doublylinkedlist *dll_create(void)
{
    doublylinkedlist *returndata = (doublylinkedlist *)malloc(sizeof(doublylinkedlist)); /* allocate memory */
    if(returndata != NULL)
        memset(returndata, 0, sizeof(doublylinkedlist)); /* initialise memory */

    return returndata;
}

int dll_get_length(doublylinkedlist *data)
{
    return data->size;
}

bool dll_is_not_empty(doublylinkedlist *data)
{
    if(dll_get_length(data) > 0) return true;
    return false;
}

bool dll_is_more_than_half(doublylinkedlist *data, int position)
{
    if(dll_is_not_empty(data))
        if(dll_get_real_position(data, position) >= (dll_get_length(data) / 2))
            return true;
    return false;
}

int dll_get_real_position(doublylinkedlist *data, int position)
{
    int returndata = position % dll_get_length(data);
    return returndata;
}

int dll_add_element(doublylinkedlist *data, int position, doublylinkedlistnode node)
{
    int returndata = EXIT_FAILURE;

    doublylinkedlistnode *newnode = (doublylinkedlistnode *)malloc(sizeof(doublylinkedlistnode)); /* allocate mem */
    if(newnode != NULL)
    {
        /* initialise memory */
        memset(newnode, 0, sizeof(doublylinkedlistnode));
        *newnode = node;
        data->size ++;

        doublylinkedlistnode *node = &(data->headernode);
        int size = dll_get_length(data) - 1;
        position = dll_get_real_position(data, position);

        if(size == 0)
        {
            node->prevlink = newnode;
            node->nextlink = newnode;
        }

        if(position == 0)
        {
            newnode->prevlink = node->prevlink; /* newnode->prevlink points old tail (last node)  */
            newnode->nextlink = node->nextlink; /*          nextlink            head (first node) */
               node->nextlink = newnode;        /* headernode.nextlink now points newnode         */

            node = newnode->nextlink;
               node->prevlink = newnode;        /* old head now points new head */
        }
        else if(position == size)
        {
            newnode->prevlink = node->prevlink; /* newnode->prevlink points old tail (last node)  */
            newnode->nextlink = node->nextlink; /*          nextlink            head (first node) */
               node->prevlink = newnode;        /* headernode.prevlink now points newnode         */

            node = newnode->prevlink;
               node->nextlink = newnode;        /* old tail now points new tail */
        }
        else
        {
            int i = 0;
            if(dll_is_more_than_half(data, position))
                for(i = size; i >= position; i--) node = node->prevlink;
            else
                for(        ; i <  position; i++) node = node->nextlink;

            newnode->nextlink = node->nextlink;
               node->nextlink = newnode;

            node = newnode->nextlink;
            newnode->prevlink = node->prevlink;
               node->prevlink = newnode;
        }

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}

int dll_remove_element(doublylinkedlist *data, int position)
{
    int returndata = EXIT_FAILURE;

    if(dll_is_not_empty(data))
    {
        doublylinkedlistnode *node    = &(data->headernode);
        doublylinkedlistnode *dienode = NULL;

        position = dll_get_real_position(data, position);
        int size = dll_get_length(data) - 1;

        if(position == 0)
        {
            dienode = node->nextlink;
            node->nextlink = dienode->nextlink;
        }
        else if(position == size)
        {
            dienode = node->prevlink;
            node->prevlink = dienode->prevlink;
        }
        else
        {
            int i = 0;
            if(dll_is_more_than_half(data, position))
                for(i = size; i >= position - 1; i--) node = node->prevlink;
            else
                for(        ; i < position     ; i++) node = node->nextlink;

            dienode = node->nextlink;

            node->nextlink = dienode->nextlink;

            node = node->nextlink;
            node->prevlink = dienode->prevlink;
        }

        free(dienode);
        data->size --;

        if(!dll_is_not_empty(data))
        {
            node->nextlink = NULL;
            node->prevlink = NULL;
        }

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}

int dll_clear(doublylinkedlist *data)
{
    int i = 0;
    int size = dll_get_length(data);
    for(; i < size; i++)
        dll_remove_element(data, 0);

    return EXIT_SUCCESS;
}

int dll_delete(doublylinkedlist *data)
{
    int returndata = EXIT_FAILURE;
    if(data != NULL)
    {
        returndata = dll_clear(data);
        if(returndata == EXIT_SUCCESS) free(data);
    }

    return returndata;
}

doublylinkedlistnode *dll_get_element(doublylinkedlist *data, int position)
{
    doublylinkedlistnode *node = &(data->headernode);
    position = dll_get_real_position(data, position);
    int size = dll_get_length(data) - 1;

    int i = 0;
    if(dll_is_more_than_half(data, position))
        for(i = size; i >= position; i--) node = node->prevlink;
    else
        for(        ; i <= position; i++) node = node->nextlink;

    return node;
}

int dll_interate(doublylinkedlist *data)
{
    printf("Size: %d\n", dll_get_length(data));

    doublylinkedlistnode *node = &(data->headernode);

    int i = 0;
    for(; i < dll_get_length(data); i++)
    {
        node = node->nextlink;
        printf("[%d]\t %d\n", i, node->element);
    }

    return EXIT_SUCCESS;
}
