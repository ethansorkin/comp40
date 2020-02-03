#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "pnm.h"



int main(int argc, char *argv[])
{
        assert (argc == 3); /* checking number of command line args */
        FILE *file;
        FILE *file2;
        int i;

        for (i = 1; i < argc; i++)
        {
                /* getting pnm file from user */
                if (strcmp(argv[i], "-") == 0)  {
                        file2 = stdin; /* file must be read through stdin */
                        assert (file2 != NULL);
                }
                
                else   {    /* filename is provided at command line */
                        char *filename = argv[i];
                        if (file == NULL)
                                file = fopen(filename, "rb");
                        else
                                file2 = fopen(filename, "rb");
                                
                   
                }
        }

}
