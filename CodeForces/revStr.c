#include <stdio.h>

int main()
{
    char arr[15];
    scanf("%s", &arr);
    char copyArr[15];
    int counter = 0;
    while (arr[counter] != '\0')
    {
        counter += 1;
    }
    for (int i = 0; i < counter + 1; i++)
    {
        copyArr[i] = arr[i];
    }
    for (int i = counter; i > -1; i--)
    {
        arr[counter - i] = copyArr[i - 1];
    }
    arr[counter + 1] = '\0';
    for (int i = 0; i < 15; i++)
    {
        if (arr[i] == '\0')
            break;
        printf("%c", arr[i]);
    }
}