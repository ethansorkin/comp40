/* Ethan Sorkin and David Knopov
* Bomb 34
* Comp40, HW5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>



/*
Functions Used in bomb.c with return type and parameters. 
bool strings_not_equal(char *str1, char *str2);
int read_six_numbers(char *input);
int string_length(char *string);
*/

void phase_1(char *input);
void phase_2(char *input);
void phase_3(char *input);
void phase_4(char *input);
int fun4(int num);
void phase_5(char *input);
void phase_6(char *input);
void phase_defused();
void explode_bomb();





struct Node {
        int val;
        struct Node *next;
};

void phase_1(char *input)
{
        char *theWord = "The bowsprit got mixed with the rudder sometimes.";
        if (strcmp(input,theWord) == 0) {
                phase_defused();
                printf("Phase 1 defused. How about the next one?\n");
                return;
        }
        explode_bomb();
}

void phase_2(char *input)
{
        int num1, num2, num3, num4, num5, num6;
        char *format = "%d %d %d %d %d %d";
        int numScanned = sscanf(input, format, &num1, &num2, &num3, &num4, 
                                                                &num5, &num6);
        int num_ray[6] = {num1, num2, num3, num4, num5, num6};
        
        if (num1 != 1) {
                explode_bomb();
                return;
        }
        
        for (int counter = 1; counter < numScanned; counter++) {
                if (num_ray[counter] != num_ray[counter - 1] * (counter + 1)) {
                        explode_bomb();
                        return;
                }
        }
        phase_defused();
        printf("That's number 2. Keep going!\n");
}

void phase_3(char *input)
{
        int index,value;

        int num_scanned = sscanf( input, "%d %d",&index,&value);

        if (num_scanned < 2) {
                explode_bomb();
                return;
        }

        if ((index < 0) || (index > 7)) {
                explode_bomb();
                return;
        }

        switch (index) 
        {
                case 0:
                        if (value != 598) {
                                explode_bomb();
                                return;
                        }               
                        break;
                case 1:
                        if (value != 295) {
                                explode_bomb();
                                return;
                        }               
                        break;
                case 2:
                        if (value != 767) {
                                explode_bomb();
                                return;
                        }              
                        break;
                case 3:
                        if (value != 90) {
                                explode_bomb();
                                return;
                        }               
                        break;
                case 4:
                        if (value != 755) {
                                explode_bomb();
                                return;
                        }
                        break;
                case 5:
                        if (value != 333) {
                                explode_bomb();
                                return;
                        }
                        break;
                case 6:
                        if (value != 821) {
                                explode_bomb();    
                                return;
                        }
                        break;
                case 7:
                        if (value != 674) {
                                explode_bomb();
                                return;
                        }                
                        break;
        }

        phase_defused();
        printf("Halfway there!\n");
}

void phase_4(char *input)
{
        int num;
        char *format = "%d";
        sscanf(input, format, &num);
        if (fun4(num) != 987) {
                explode_bomb();
                return;
        }
        phase_defused();
        printf("So you got that one. Try this one.\n");
}

int fun4(int num)
{
        if (num == 1) {
                return 1;
        } else if (num == 2) {
                return 2;
        }
        else {
                return (fun4(num - 1) + fun4(num - 2));
        }
}

void phase_5(char* input)
{
        char *theWord = malloc(6);
        char *index = "isrveawhobpnutfg";
        
        if (strlen(input) != 6) {
                explode_bomb();
                return;
        }

        uint8_t mask = 15;
        for (int i = 0; i < 5; i++) {
                uint8_t modified = mask & (uint8_t)input[i];
                char letter = index[modified];
                strcat(theWord, &letter);
        }

        char *ravens = "ravens";
        if(theWord != ravens) {
                explode_bomb();
                return;
        }
        free(theWord);
        phase_defused();
        printf("Good work! On to the next...\n");
}

void phase_6(char *input)
{
        struct Node node1 = {256, NULL};
        struct Node node2 = {612, NULL};
        struct Node node3 = {478, NULL};
        struct Node node4 = {537, NULL};
        struct Node node5 = {228, NULL};
        struct Node node6 = {184, NULL};

        struct Node *front = &node1;
        node1.next = &node2;
        node2.next = &node3;
        node3.next = &node4;
        node4.next = &node5;
        node5.next = &node6;

        int num1, num2, num3, num4, num5, num6;
        char *format = "%d %d %d %d %d %d";
        int numScanned = sscanf(input, format, &num1, &num2, &num3, &num4, 
                                                                &num5, &num6);
        int index[6] = {num1, num2, num3, num4, num5, num6};
        int value = 0;

        /* ensures every number is between 1-6 */
        for (int i = 0; i < 5; i++) {
                if (index[i] > numScanned || index[i] < 1) {
                        explode_bomb();
                        return;
                }
        }

        /* ensures there are no repeat numbers */
        for (int i = 0; i < numScanned; i++) {
                int num = index[i];
                for (int j = 0; j < numScanned; j++) {
                        if (num != j) {
                                if (num == index[j]) {
                                        explode_bomb();
                                        return;
                                }
                        }
                }
        }

        for (int i = 0; i < numScanned; i++) {
                struct Node *temp = front;
                for (int j = 0; j < index[j] - 1; j++) {
                        temp = temp->next;
                }

                if (i > 0) {
                        if (value >= temp->val) {
                                value = temp->val;
                        }
                } else {
                        explode_bomb();
                        return;
                }

        }
        phase_defused();
        printf("Congratulations! You've defused the bomb!\n");

}

void phase_defused()
{
        printf("Rats! You've defused my fiendish little bomb\n");
}

void explode_bomb()
{
        printf("BOOM!!! Better take shelter, the bomb EXPLODED\n");
}

