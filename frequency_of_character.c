#include <stdio.h>
#include <string.h>
 
 // Findind the frequency of a character in a word
 
int main()
{
    char ch, word[100];
    int flag = 0, frequency = 0;
 
    printf("Enter any character for searching: ");
    scanf("%c", &ch);
    printf("Enter the word: ");
    scanf("%s", &word);
    printf("The positions of '%c' in %s are: ", ch, word);

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == ch)
        {
            flag = 1;
            printf("%d  ", i + 1);
            frequency++;
        }
    }

    if (flag > 0)
    {
        printf("\nThe character '%c' had occured for %d times!\n", ch, frequency);
    }
    else
    {
        printf("\nThe character '%c' is not present!\n", ch);
    }
 
    return 0;
}
