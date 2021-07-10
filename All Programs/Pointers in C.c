#include <stdio.h>
#include <stdlib.h>
void update(int *a,int *b) {
    int num1 = *a , num2 = *b;
    *a = num1 + num2;
    *b = abs(num1 - num2);
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}