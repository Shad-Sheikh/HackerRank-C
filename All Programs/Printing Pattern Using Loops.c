#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() 
{
    int n;
    scanf("%d", &n);
    int len = n * 2 - 1;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            int m = min(i, j);
            m = min(m, len - i - 1);
            m = min(m, len - j - 1);
            printf("%d ", n - m);
        }
        printf("\n");
    }
    return 0;
}
