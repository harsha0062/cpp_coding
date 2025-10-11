
#include <stdio.h>
int main()
{
    char a[100], ch[200];
    int n;
    printf("enter the number of character: ");
    scanf("%d", &n);
    printf("enter thr character (0's and 1's) :");
    for (int i = 0; i < n; i++)
        scanf(" %c", &a[i]);
    int c = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        ch[j++] = a[i];
        if (a[i] == '1')
            c++;
        if (c == 5)
        {
            ch[j++] = '0';
            c = 0;
        }
    }
    printf("after bit stuffing:\n");
    for (int i = 0; i < j; i++)
        printf("%c", ch[i]);
}