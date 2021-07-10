#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
    int i,j,c=0,A,O,X,count=0,no_index=0;
  
  for(i=1; i<n; i++){
      for(j=i+1; j<=n; j++){
      no_index++;
      }
  }
  int and[no_index];
  int or[no_index];
  int xor[no_index];
  
  for(i=1; i<n; i++){
      for(j=i+1; j<=n; j++){
             and[c] = i&j;
             or[c] = i|j;
             xor[c] = i^j;
             c++;
      }
  }
  
int stop = 0;

  for(i=k-1;(i>=0) && !stop;i--){
      for(j=0;j<no_index;j++){
        if(and[j]==i){
            A=and[j];
            stop = 1;
            break;
        }
      }
  }

  stop = 0;
  for(i=k-1;(i>=0) && !stop;i--){
      for(j=0;j<no_index;j++){
        if(or[j]==i){
            O=or[j];
            stop = 1;
            break;
        }
      }
  }

  stop = 0;
  for(i=k-1;(i>=0) && !stop;i--){
      for(j=0;j<no_index;j++){
        if(xor[j]==i){
            X=xor[j];
            stop = 1;
            break;
        }
      }
  }

 printf("%d\n%d\n%d",A,O,X);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
