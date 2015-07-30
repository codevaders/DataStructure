#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.c"

int main(void)
{
    int returndata = EXIT_FAILURE;

    linkedlist *sample_data = NULL;

    sample_data = create_ll();
    if(sample_data != NULL)
    {
        linkedlistnode node;

        display_ll_element(sample_data);            /* (null) */

        node.element = 1;
        add_ll_element_forward(sample_data, node);
        display_ll_element(sample_data);            /* 1 */
        
        node.element = 2;
        add_ll_element_forward(sample_data, node);
        display_ll_element(sample_data);            /* 2 1 */
        
        node.element = 4;
        add_ll_element_backward(sample_data, node);
        display_ll_element(sample_data);            /* 2 1 4 */

        node.element = 5;
        add_ll_element_backward(sample_data, node);
        display_ll_element(sample_data);            /* 2 1 4 5 */

        node.element = 6;
        add_ll_element(sample_data, 3, node);
        display_ll_element(sample_data);            /* 2 1 4 6 5 */

        node.element = 7;
        add_ll_element(sample_data, 2, node);
        display_ll_element(sample_data);            /* 2 1 7 4 6 5 */

        remove_ll_element(sample_data, 4);
        display_ll_element(sample_data);            /* 2 1 7 4 5 */

        remove_ll_element(sample_data, 0);
        display_ll_element(sample_data);            /* 1 7 4 5 */

        delete_ll(sample_data);

        returndata = EXIT_SUCCESS;
    }

    return returndata;
}
