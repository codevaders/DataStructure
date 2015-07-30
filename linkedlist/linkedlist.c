/*
    LinkedList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: July 30, 2015 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

linkedlist *create_ll(void)
{
    linkedlist *returndata = NULL;
    
    returndata = (linkedlist *)malloc(sizeof(linkedlist));
    if(returndata != NULL)
    {
        returndata->size = 0;

        linkedlistnode node;
                       node.element = 0;
                       node.link = NULL;

        returndata->headernode = node;
    }

    return returndata;
}

int delete_ll(linkedlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
    {
        int i = data->size - 1;
        for(; i >= 0; i--)
        {
            remove_ll_element(data, i);
        }
        free(data);

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}

int add_ll_element(linkedlist *data, int position, linkedlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0  && position <= data->size)
    {
        linkedlistnode *newnode = NULL;
        newnode = (linkedlistnode *)malloc(sizeof(linkedlistnode));
        if(newnode != NULL)
        {
            memset(newnode, 0, sizeof(linkedlistnode));
            *newnode = element;

            linkedlistnode *prev_node = (linkedlistnode *)data;
            linkedlistnode *next_node = data->headernode.link;

            if(position == 0)
                data->headernode.link = newnode;
            else
            {
                int i = 0;
                for(; i < position; i++)
                {
                    prev_node = next_node;
                    next_node = prev_node->link;
                }
                prev_node->link = newnode;
            }
            newnode->link = next_node;
            data->size++;

            returndata = EXIT_SUCCESS;
        }
    }

    return returndata;
}

int add_ll_element_forward(linkedlist *data, linkedlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_ll_element(data, 0, element);

    return returndata;
}

int add_ll_element_backward(linkedlist *data, linkedlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_ll_element(data, data->size, element);

    return returndata;
}

int remove_ll_element(linkedlist *data, int position)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0 && position < data->size)
    {
        linkedlistnode *prev_node = (linkedlistnode *)data;
        linkedlistnode *next_node = data->headernode.link;

        if(position == 0)
            data->headernode.link = next_node->link;
        else
        {
            int i = 0;
            for(; i < position; i++)
            {
                prev_node = next_node;
                next_node = prev_node->link;
            }
            prev_node->link = next_node->link;
        }
        free(next_node);
        data->size--;

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}

int remove_ll_element_forward(linkedlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_ll_element(data, 0);

    return returndata;
}

int remove_ll_element_backward(linkedlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_ll_element(data, data->size - 1);

    return returndata;
}

int get_ll_length(linkedlist *data)
{
    int returndata = 0;

    if(data != NULL)
        returndata = data->size;

    return returndata;
}

linkedlistnode *get_ll_element(linkedlist *data, int position)
{
    linkedlistnode *returndata = NULL;

    if(data != NULL && position >= 0 && position < data->size)
    {
        linkedlistnode *prev_node = (linkedlistnode *)data;
        linkedlistnode *next_node = data->headernode.link;

        int i = 0;
        for(; i < position; i++)
        {
            prev_node = next_node;
            next_node = prev_node->link;
        }

        returndata = next_node;
    }

    return returndata;
}

void display_ll_element(linkedlist *data)
{
    if(data != NULL)
    {
        int length = get_ll_length(data);
        linkedlistnode element;

        printf("Size: %d\n", data->size);

        int i = 0;
        for(; i < length; i++)
        {
            element = *get_ll_element(data, i);
            printf("[%d]:\t %d\n", i, element);
        }
    }
}
