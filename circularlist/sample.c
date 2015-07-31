#include <stdio.h>
#include <stdlib.h>

#include "circularlist.c"

int main(void)
{
    int returndata = EXIT_FAILURE;

    circularlist *sample_data = NULL;

    sample_data = create_cl();
    if(sample_data != NULL)
    {
        circularlistnode node;

        display_cl_element(sample_data);            /* (null) */

        node.element = 1;
        add_cl_element_forward(sample_data, node);
        display_cl_element(sample_data);            /* 1 */
        
        node.element = 2;
        add_cl_element_forward(sample_data, node);
        display_cl_element(sample_data);            /* 2 1 */
        
        node.element = 4;
        add_cl_element_backward(sample_data, node);
        display_cl_element(sample_data);            /* 2 1 4 */

        node.element = 5;
        add_cl_element_backward(sample_data, node);
        display_cl_element(sample_data);            /* 2 1 4 5 */

        node.element = 6;
        add_cl_element(sample_data, 3, node);
        display_cl_element(sample_data);            /* 2 1 4 6 5 */

        node.element = 7;
        add_cl_element(sample_data, 2, node);
        display_cl_element(sample_data);            /* 2 1 7 4 6 5 */

        printf("If position more than element size:\n");
        int i = 0;
        for(; i < 20; i++)
            printf("[%d]\t %d\n", i, *get_cl_element(sample_data, i));

        remove_cl_element(sample_data, 4);
        display_cl_element(sample_data);            /* 2 1 7 4 5 */

        remove_cl_element(sample_data, 5);
        display_cl_element(sample_data);            /* 1 7 4 5 */

        printf("If position more than element size:\n");
        for(i = 0; i < 20; i++)
            printf("[%d]\t %d\n", i, *get_cl_element(sample_data, i));

        delete_cl(sample_data);

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}
