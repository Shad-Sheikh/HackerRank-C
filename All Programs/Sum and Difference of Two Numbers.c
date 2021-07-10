#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n, m;
    float a, b;
    scanf("%d %d", &n, &m);
    scanf("%f %f", &a, &b);
    int sum_of_ints = n + m;
    float sum_of_floats = a + b;
    int diff_of_ints = n - m;
    float diff_of_floats = a - b;
    printf("%d %d\n", sum_of_ints, diff_of_ints);
    printf("%.1f %.1f", sum_of_floats, diff_of_floats);
    
    return 0;
}