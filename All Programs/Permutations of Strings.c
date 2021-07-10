#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *s1,char *s2){
    char *s;
    *s = s1;
    s1 = s2;
    s2 = s;
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    

    int i = n-1;
    while(i>0 && strcmp(s[i-1],s[i])>=0) 
        i--;    // find key
    if (i<=0) return 0;
    
    
    int j = n-1;
    while(strcmp(s[i-1],s[j])>=0) 
        j--;    
        char *tmp = s[i-1];
        s[i-1] = s[j];
        s[j] = tmp;

    
    j = n-1;
    while(i<j) {
      tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;

        i++;
        j--;
    }
    return 1;
}

