#include <stdio.h>
#include <string.h>

int main()
{
    int c = 0;

    char str[50];
    printf("enter a string");
    scanf("%[^\n]s", &str);
    int x = strlen(str);

    while (c < x)
    {
        if (str[c] == 'a' || str[c] == 'b' || str[c] == 'c')
        {
            c++;
            continue;
        }

        printf("entered grammer is invalid");
        return 0;
    }

    if (x % 3 == 0)
    {
        printf("This is a valid string");
    }
    else
    {
        printf("entered string is invalid");
    }
    return 0;
}