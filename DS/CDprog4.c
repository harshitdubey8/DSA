#include <stdio.h>

int main()
{
    int c = 0, ca = 0, cb = 0;

    char str[50];
    printf("enter a string");
    scanf("%[^\n]s", &str);
    while (str[c])
    {
        if (str[c] == 'a')
        {
            ca++;
        }
        else if (str[c] == 'b')
        {
            cb++;
        }
        else
        {
            printf("entered grammer is invalid");
            return 0;
        }
        c++;
    }

    if (ca % 2 == 0 && cb % 2 != 0)
    {
        printf("This is a valid string");
    }
    else
    {
        printf("entered string is invalid");
    }
    return 0;
}