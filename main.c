#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char word[1000][30];
char word_meaning[1000][30];
int count_index = -1;
void show_dictionary()
{
    if (count_index == -1)
    {
        printf("\nSorry! dictionary is empty Please add word first\n");
        goto there;
    }
    printf("-----------------------------------\n");
    printf("|     Word      |      Meaning    |\n");
    printf("-----------------------------------\n");
    for (int i = 0; i <= count_index; i++)
    {
        printf("|    %s              %s\n", word[i], word_meaning[i]);
        printf("-----------------------------------\n");
    }
there:
    printf("\n");
}
void add_word()
{
    char word1[30], word_meaning1[30];
    printf("Enter word to add in dictionary: ");
    fflush(stdin);
    gets(word1);
    for (int i = 0; i <= count_index; i++)
    {
        if (!strcmp(word1, word[i]))
        {
            printf("\nThis word is already exit\n");
            goto there;
        }
    }
    printf("Enter word meaning: ");
    fflush(stdin);
    gets(word_meaning1);

    count_index++;
    strcpy(word[count_index], word1);
    strcpy(word_meaning[count_index], word_meaning1);
    printf("\nWord is successfully added in dictionary\n");
there:
    printf("\n");
}
void search_word()
{
    char word1[30];
    int check,count=0;
    if (count_index == -1)
    {
        printf("\nSorry! dictionary is empty Please add word first\n");
        goto there;
    }
    printf("Enter word to search: ");
    fflush(stdin);
    gets(word1);
    for (int i = 0; i <= count_index; i++)
    {
        if (!strcmp(word1, word[i]))
        {
            printf("\n---------------------------------\n");
            printf("|       Word     |     Meaning  |\n");
            printf("---------------------------------\n");
            printf("|      %s           %s\n", word1, word_meaning[i]);
            printf("---------------------------------\n");
        }
        else
        {
            if (count == count_index)
            {
                printf("\nSorry! word is not found\n");
            }
            count++;
        }
    }
there:
    printf("\n");
}
void main()
{
    int choose;
    printf("\n--------------------------------------------\n");
    printf("|  WELCOME TO ENGLISH OT HINDI DICTIONARY  |\n");
    printf("--------------------------------------------\n");
    do
    {
        printf("Press 1 to search word\n");
        printf("Press 2 to add word in dictionary\n");
        printf("Press 3 to show dictionary\n");
        printf("Press 4 to Exit\n");
    again:
        printf("Choose an option: ");
        fflush(stdin);
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:            
            search_word();
            choose=0;
            break;
        case 2:            
            add_word();
            choose=0;
            break;
        case 3:            
            show_dictionary();
            choose=0;
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option try again\n");
            goto again;
        }
    } while (choose != 4);
}