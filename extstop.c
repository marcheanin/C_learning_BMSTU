#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}



void delta(char *mas, int n, int **g){
    int u, p;
    int len = strlen(mas);
    for (p = 0; p < len; p++)
        for (u = 0; u < n; u++)
            g[p][u] = len - p;
}




int BMSubst(char *s,char *t,int n)
{
    int **g,i,j;
    int len = strlen(s),len1= strlen(t);
    int len2=len;
    g = (int**)malloc((len) * sizeof(int*));
    for (i = 0; i < len; i++)
        g[i]=(int *)malloc(n * sizeof(int));
    for (j = 0; j < len; j++)
        for (i = 0; i < n; i++)
            g[j][i]=0;

        delta(s, n, g);
        len--;

        while (len < len1){
            i = len2 - 1;
            while (t[len] == s[i])
        {
                if (i == 0)
            {
                    for (j = 0; j < len2; j++)
                        free(g[j]);
                    free(g);
                    return len;
            }
            i--;
            len--;
        }
        len += g[i][t[len] - 'a'];
    }

    for (j = 0; j < len2; j++)
          free(g[j]);
    free(g);
    return len1;
}




int main(int argc, char **argv)
{
    int x;
    x = BMSubst(argv[1], argv[2], 10);
    printf("%d\n", x);
    return 0;
}
