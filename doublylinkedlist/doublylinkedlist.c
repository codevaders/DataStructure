/*
    DoublyLinkedList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: August 1, 2015 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublylinkedlist.h"

doublylinkedlist *create_dll(void)
{
    doublylinkedlist *returndata = NULL;
    
    returndata = (doublylinkedlist *)malloc(sizeof(doublylinkedlist));
    if(returndata != NULL)
        memset(returndata, 0, sizeof(doublylinkedlist));

    return returndata;
}

int delete_dll(doublylinkedlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
    {
        int i = data->size - 1;
        for(; i >= 0; i--)
            remove_dll_element(data, i);

        free(data);

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}

int add_dll_element(doublylinkedlist *data, int position, doublylinkedlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0)
    {
        doublylinkedlistnode *newnode = NULL;
        newnode = (doublylinkedlistnode *)malloc(sizeof(doublylinkedlistnode));
        if(newnode != NULL)
        {
            memset(newnode, 0, sizeof(doublylinkedlistnode));
            *newnode = element;

            doublylinkedlistnode *oldnode = &(data->headernode);

            if(data->size > 0)
                position = position % (data->size + 1);
            else if(data->size == 0)
                oldnode->next_link = newnode;

            int i = 0;
            for(; i < position; i++)
                oldnode = oldnode->next_link;
            newnode->next_link = oldnode->next_link;
            oldnode->next_link = newnode;

            newnode->prev_link = oldnode;

            oldnode = newnode->next_link;
            oldnode->prev_link = newnode;

            if(position == 0 && data->size != 0)
            {
                doublylinkedlistnode *lastnode = &(data->headernode);

                int i = 0;
                for(; i <= data->size; i++)
                    lastnode = lastnode->next_link;

                lastnode->next_link = newnode;
                newnode->prev_link = lastnode;
            }

            data->size++;

            returndata = EXIT_SUCCESS;
        }
    }

    return returndata;
}

int add_dll_element_forward(doublylinkedlist *data, doublylinkedlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_dll_element(data, 0, element);

    return returndata;
}

int add_dll_element_backward(doublylinkedlist *data, doublylinkedlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_dll_element(data, data->size, element);

    return returndata;
}

int remove_dll_element(doublylinkedlist *data, int position)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0)
    {
        if(data->size > 0)
        {
            doublylinkedlistnode *node = &(data->headernode);
            doublylinkedlistnode *oldnode = NULL;

            position = ((position + 1) % data->size) - 1;

            int i = 0;
            for(; i < position; i++)
                node = node->next_link;
            oldnode = node->next_link;
            node->next_link = oldnode->next_link;

            node = node->next_link;
            node->prev_link = oldnode->prev_link;

            if(position == 0)
            {
                doublylinkedlistnode *lastnode = &(data->headernode);

                int i = 0;
                for(; i < data->size - 1; i++)
                    lastnode = lastnode->next_link;

                lastnode->next_link = oldnode->next_link;

                lastnode = lastnode->next_link;
                lastnode->prev_link = oldnode->prev_link;
            } 

            free(oldnode);
            data->size--;

            returndata = EXIT_SUCCESS;
        }
    }

    return returndata;
}

int remove_dll_element_forward(doublylinkedlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_dll_element(data, 0);

    return returndata;
}

int remove_dll_element_backward(doublylinkedlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_dll_element(data, data->size - 1);

    return returndata;
}

int get_dll_length(doublylinkedlist *data)
{
    int returndata = 0;

    if(data != NULL)
        returndata = data->size;

    return returndata;
}

doublylinkedlistnode *get_dll_element(doublylinkedlist *data, int position)
{
    doublylinkedlistnode *returndata = NULL;

    if(data != NULL && position >= 0)
    {
        doublylinkedlistnode *node = &(data->headernode);

        int i = 0;
        for(; i <= position; i++)
            node = node->next_link;

        returndata = node;
    }

    return returndata;
}

void display_dll_element(doublylinkedlist *data)
{
    if(data != NULL)
    {
        int length = get_dll_length(data);
        doublylinkedlistnode element;

        printf("Size: %d\n", data->size);

        int i = 0;
        for(; i < length; i++)
        {
            element = *get_dll_element(data, i);
            printf("[%d]:\t %x\n", i, element.element);
        }
    }
}
