/*
    ArrayList in C

    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: July 28, 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"
#include "arraylist.h"

arraylist *create_al(int maxsize)
{
    arraylist *returndata = NULL;

    if(maxsize > 0)
    {
        returndata = (arraylist *)malloc(sizeof(arraylist));
        if(returndata != NULL)
        {
            memset(returndata, 0, sizeof(arraylist));

            returndata->maxsize = maxsize;
            returndata->currentsize = 0;
            returndata->element = (arraylistnode *)malloc(sizeof(arraylistnode) * maxsize);
            if(returndata != NULL)
                memset(returndata->element, 0, sizeof(arraylistnode) * maxsize);
        }
    }

    return returndata;
}

void delete_al(arraylist *data)
{
    if(data != NULL)
    {
        free(data->element);
        free(data);
    }
}

int add_al_element(arraylist *data, int position, arraylistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0 && position <= data->currentsize)
        if(! is_al_full(data))
        {
            int i = data->currentsize;
            for(; i > position; i--)
                data->element[i] = data->element[i - 1];
            data->element[position] = element;
            data->currentsize++;

            returndata = EXIT_SUCCESS;
        }

    return returndata;
}

int add_al_element_forward(arraylist *data, arraylistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_al_element(data, 0, element);

    return returndata;
}

int add_al_element_backward(arraylist *data, arraylistnode element)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = add_al_element(data, data->currentsize, element);

    return returndata;
}

int remove_al_element(arraylist *data, int position)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL && position >= 0 && position < data->currentsize)
    {
        int i = position + 1;
        for(; i < data->currentsize; i++)
            data->element[i - 1] = data->element[i];
        data->currentsize--;

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}

int remove_al_element_forward(arraylist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_al_element(data, 0);

    return returndata;
}

int remove_al_element_backward(arraylist *data)
{
    int returndata = EXIT_FAILURE;

    if(data != NULL)
        returndata = remove_al_element(data, data->currentsize - 1);

    return returndata;
}

void clear_al(arraylist *data)
{
    if(data != NULL)
    {
        memset(data->element, 0, sizeof(arraylistnode) * data->maxsize);
        data->currentsize = 0;
    }
}

bool is_al_full(arraylist *data)
{
    bool returndata = false;

    if(data != NULL)
        if(data->currentsize == data->maxsize)
            returndata = true;

    return returndata;
}

int get_al_length(arraylist *data)
{
    int returndata = 0;

    if(data != NULL)
        returndata = data->currentsize;

    return returndata;
}

arraylistnode *get_al_element(arraylist *data, int position)
{
    arraylistnode *returndata;

    if(data != NULL && position >= 0 && position < data->currentsize)
        returndata = &(data->element[position]);

    return returndata;
}

void display_al_element(arraylist *data)
{
    if(data != NULL)
    {
        int length = get_al_length(data);
        arraylistnode element;

        printf("Maximum: %d\n", data->maxsize);
        printf("Current: %d\n", data->currentsize);

        int i = 0;
        for(; i < length; i++)
        {
            element = *get_al_element(data, i);
            printf("[%d]:\t %d\n", i, element);
        }

        i = length;
        for(; i < data->maxsize; i++)
            printf("[%d]:\t (null)\n", i);
    }
}
