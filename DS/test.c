#include <stdio.h>
#include <string.h>

int main()
{
    int c = 0;
    char str[50];
    printf("enter a number");
    scanf("%[^\n]s", &str);
    int x = strlen(str);

    while (str[c])
    {
        if (str[c] == '0' || str[c] == '1')
        {
            c++;
            continue;
        }

        printf("entered grammer is invalid");
        return 0;
    }

    if (str[0] == '0' && str[x - 1] == '1' && str[x - 2] == '1')
    {
        printf("This is a valid string");
    }
    else
    {
        printf("entered string is invalid");
    }
    return 0;
}