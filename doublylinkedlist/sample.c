#include <stdio.h>
#include <stdlib.h>

#include "doublylinkedlist.c"

int main(void)
{
    int returndata = EXIT_FAILURE;

    doublylinkedlist *sample_data = NULL;

    sample_data = create_dll();
    if(sample_data != NULL)
    {
        doublylinkedlistnode node;

        display_dll_element(sample_data);            /* (null) */

        node.element = 1;
        add_dll_element_forward(sample_data, node);
        display_dll_element(sample_data);            /* 1 */
        
        node.element = 2;
        add_dll_element_forward(sample_data, node);
        display_dll_element(sample_data);            /* 2 1 */
        
        node.element = 4;
        add_dll_element_backward(sample_data, node);
        display_dll_element(sample_data);            /* 2 1 4 */

        node.element = 5;
        add_dll_element_backward(sample_data, node);
        display_dll_element(sample_data);            /* 2 1 4 5 */

        node.element = 6;
        add_dll_element(sample_data, 3, node);
        display_dll_element(sample_data);            /* 2 1 4 6 5 */

        node.element = 7;
        add_dll_element(sample_data, 2, node);
        display_dll_element(sample_data);            /* 2 1 7 4 6 5 */

        printf("If position more than element size:\n");
        int i = 0;
        for(; i < 20; i++)
            printf("[%d]\t %d\n", i, (*get_dll_element(sample_data, i)).element);

        remove_dll_element(sample_data, 4);
        display_dll_element(sample_data);            /* 2 1 7 4 5 */

        remove_dll_element(sample_data, 5);
        display_dll_element(sample_data);            /* 1 7 4 5 */

        printf("If position more than element size:\n");
        for(i = 0; i < 20; i++)
            printf("[%d]\t %d\n", i, (*get_dll_element(sample_data, i)).element);

        delete_dll(sample_data);

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}
