#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void revarray(void *base, unsigned long nel, unsigned long width)
{
	void *p = malloc(width);
      for(int i=0; i<nel/2; i++)
      {
      	void *l = base + i*width;
      	void *e = base + (nel - i - 1)*width;
      	memcpy(p, e, width);
      	memcpy(e, l, width);
      	memcpy(l, p, width);


      }
      free(p);
}
int main(){
    int s[] = {1, 2, 3, 17, 4, 5, 6};
    int *a = s, n = 7;
    revarray(a, n, sizeof(int));
    for (int i = 0; i < 7; i++){
        printf("%d ", s[i]);
    }

}
