#include <stdio.h>
#include <stdlib.h>

#include "arraylist.c"

int main(void)
{
    int returndata = EXIT_FAILURE;

    arraylist *sample_data = NULL;

    sample_data = create_al(7);
    if(sample_data != NULL)
    {
        arraylistnode node;

        display_al_element(sample_data);            /* (null) */

        node.element = 1;
        add_al_element_forward(sample_data, node);
        display_al_element(sample_data);            /* 1 */
        
        node.element = 2;
        add_al_element_forward(sample_data, node);
        display_al_element(sample_data);            /* 2 1 */
        
        node.element = 4;
        add_al_element_backward(sample_data, node);
        display_al_element(sample_data);            /* 2 1 4 */

        node.element = 5;
        add_al_element_backward(sample_data, node);
        display_al_element(sample_data);            /* 2 1 4 5 */

        node.element = 6;
        add_al_element(sample_data, 3, node);
        display_al_element(sample_data);            /* 2 1 4 6 5 */

        node.element = 7;
        add_al_element(sample_data, 2, node);
        display_al_element(sample_data);            /* 2 1 7 4 6 5 */

        remove_al_element(sample_data, 4);
        display_al_element(sample_data);            /* 2 1 7 4 5 */

        remove_al_element(sample_data, 0);
        display_al_element(sample_data);            /* 1 7 4 5 */

        clear_al(sample_data);
        display_al_element(sample_data);            /* (null) */

        delete_al(sample_data);
        display_al_element(sample_data);            /* Error in display_al_element() */

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}
