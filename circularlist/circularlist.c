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
        memset(returndata, 0, sizeof(circularlist));

    return returndata;
}


int add_cl_element(circularlist *data, int position, circularlistnode element);
{
    int returndata = 0;

    if(data != NULL && position >= 0 && position < data->size)
    {

