/*
    ListCommander in C
    
    Author: Jongmin Kim (kdzlvaids@gmail.com)
    Written on: August 1, 2015 
*/

#include "doublylinkedlist.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    doublylinkedlist *sample = dll_create();
    doublylinkedlistnode node;

    char input[15][30] = {0, };
    
    int position = 0;
    int element = 0;

    printf("ListCommader\n");

    printf("Set list name: ");
    //scanf("%s", &input[14]);
    input[14][0] = 's';
    input[14][1] = 'a';
    input[14][2] = 'm';
    input[14][3] = 'p';
    input[14][4] = 'l';
    input[14][5] = 'e';
    printf("%s\n", input[14]);

    printf("\nHint: h<enter>\n");
    while(true)
    {
        printf("Select list type: ");
        scanf("%s", &input[15]);

        if(!strcmp("q", input[15]))
            break;
        else if(!strcmp("h", input[15]))
        {
            printf("--------------------------------\n");
            printf("Available list types            \n");
            printf("dll     Use DoublyLinkedList    \n");
            printf("--------------------------------\n");
            printf("Available commands              \n");
            printf("q       Quit ListCommander      \n");
            printf("--------------------------------\n");
        }
        else if(!strcmp("dll", input[15]))
        {
            printf("\nYou are in [%s:doublylinkedlist].\n", input[14]);
            while(true)
            {
                printf("Enter command: ");
                scanf("%s", &input[0]);
                
                if(!strcmp("h", input[0]))
                {
                    printf("--------------------------------\n");
                    printf("Available commands              \n");
                    printf("a       Add element             \n");
                    printf("r       Remove element          \n");
                    printf("c       Clear all elements      \n");
                    printf("l       Show length             \n");
                    printf("s       Show all elements       \n");
                    printf("q       Close and delete list   \n");
                    printf("--------------------------------\n");
                }
                else if(!strcmp("a", input[0])) 
                {
                    printf("Position: ");
                    scanf("%s", &input[1]);
                    
                    printf("Value of the element: (int)");
                    scanf("%s", &input[2]);

                    position = strtol(input[1], NULL, 10);
                    element = strtol(input[2], NULL, 10);

                    node.element = element;
                    dll_add_element(sample, position, node);

                    printf("\"%d\" to %d added.\n", element, position);
                }
                else if(!strcmp("r", input[0])) 
                {
                    printf("Position: ");
                    scanf("%s", &input[1]);

                    position = strtol(input[1], NULL, 10);

                    dll_remove_element(sample, position);
                    
                    printf("Element of position %d has been removed.\n", position);
                }
                else if(!strcmp("c", input[0]))
                    dll_clear(sample);
                else if(!strcmp("l", input[0]))
                    printf("Size: %d\n", dll_get_length(sample));
                else if(!strcmp("s", input[0]))
                {
                    printf("--------------------------------\n");
                    dll_interate(sample);
                    printf("--------------------------------\n");
                }
                else if(!strcmp("q", input[0]))
                    break;
                else
                    printf("%s is not a command\n");
            }

            dll_delete(sample);
            printf("[%s:doublylinkedlist] has been deleted.\n", input[14], input[15]);
            printf("Hint: q<enter> again to quit\n");
        }
        else
            printf("%s is not a list type or a command\n", input[15]);
    }
    return EXIT_SUCCESS;
}

