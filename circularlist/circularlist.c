/*
    CircularList in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: July 31, 2015 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circularlist.h"

circularlist *create_cl(void)
{
    circularlist *returndata = NULL;
    
    returndata = (circularlist *)malloc(sizeof(circularlist));
    if(returndata != NULL)
    {
        returndata->size = 0;
        returndata = (circularlist *)malloc(sizeof(circularlist));
    }

    return returndata;
}

int delete_cl(circularlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
    {
        int i = data->size - 1;
        for(; i >= 0; i--)
            remove_cl_element(data, i);

        free(data);

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}

int add_cl_element(circularlist *data, int position, circularlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0)
    {
        circularlistnode *newnode = NULL;
        newnode = (circularlistnode *)malloc(sizeof(circularlistnode));
        if(newnode != NULL)
        {
            memset(newnode, 0, sizeof(circularlistnode));
            *newnode = element;

            if(data->size > 0)
                position = position % (data->size + 1);

            circularlistnode *oldnode = &(data->headernode);

            int i = 0;
            for(; i < position; i++)
                oldnode = oldnode->link;
            newnode->link = oldnode->link;
            oldnode->link = newnode;

            if(position == 0)
            {
                circularlistnode *lastnode = &(data->headernode);

                int i = 0;
                for(; i <= data->size; i++)
                    lastnode = lastnode->link;
                lastnode->link = newnode;
            }

            data->size++;

            returndata = EXIT_SUCCESS;
        }
    }

    return returndata;
}

int add_cl_element_forward(circularlist *data, circularlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_cl_element(data, 0, element);

    return returndata;
}

int add_cl_element_backward(circularlist *data, circularlistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_cl_element(data, data->size, element);

    return returndata;
}

int remove_cl_element(circularlist *data, int position)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0)
    {
        if(data->size > 0)
        {
            circularlistnode *node = &(data->headernode);
            circularlistnode *oldnode = NULL;

            position = ((position + 1) % data->size) - 1;

            int i = 0;
            for(; i < position; i++)
                node = node->link;
            oldnode = node->link;
            node->link = oldnode->link;

            if(position == 0)
            {
                circularlistnode *lastnode = &(data->headernode);

                int i = 0;
                for(; i < data->size - 1; i++)
                    lastnode = lastnode->link;
                lastnode->link = oldnode->link;
            } 

            free(oldnode);
            data->size--;

            returndata = EXIT_SUCCESS;
        }
    }

    return returndata;
}

int remove_cl_element_forward(circularlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_cl_element(data, 0);

    return returndata;
}

int remove_cl_element_backward(circularlist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_cl_element(data, data->size - 1);

    return returndata;
}

int get_cl_length(circularlist *data)
{
    int returndata = 0;

    if(data != NULL)
        returndata = data->size;

    return returndata;
}

circularlistnode *get_cl_element(circularlist *data, int position)
{
    circularlistnode *returndata = NULL;

    if(data != NULL && position >= 0)
    {
        circularlistnode *node = &(data->headernode);

        int i = 0;
        for(; i <= position; i++)
            node = node->link;

        returndata = node;
    }

    return returndata;
}

void display_cl_element(circularlist *data)
{
    if(data != NULL)
    {
        int length = get_cl_length(data);
        circularlistnode element;

        printf("Size: %d\n", data->size);

        int i = 0;
        for(; i < length; i++)
        {
            element = *get_cl_element(data, i);
            printf("[%d]:\t %d\n", i, element);
        }
    }
}
