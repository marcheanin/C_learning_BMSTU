#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
        if (argc != 4) {
                printf("Usage: frame <height> <width> <text>");
                return 0;
        }

        int height = atoi(argv[1]);
        int width = atoi(argv[2]);
        int len = strlen(argv[3]);
        char* text = (char*)malloc((len + 1) * sizeof(char));
        strcpy(text, argv[3]);
        int s = 0, count_height = 0, s_width = 0;

        if ((height < 3) || ((width - 2 - len) < 0)) {
                printf("Error");
                free(text);
                return 0;
        }
        for (int j = 1; j <= width; j++) {
                        printf("*");
        }
        printf("\n");
        while (count_height < ((height - 3) / 2)) {
                printf("*");
                for (int j = 1; j <= width - 2; j++) {
                        printf(" ");
                }
                printf("*");
                printf("\n");
                count_height += 1;

        }
        count_height = 0;

        s = 0;
        printf("*");
        s_width = (width - 2 - len) / 2;
        for (int j = 1; j <= s_width; j++) {
                printf(" ");
                s += 1;
        }
        for (int i = 0; i < len; i++) {
                printf("%c", text[i]);
        }
        for (int j = 1; j <= width - 2 - len - s_width; j++) {
                printf(" ");
        }
        printf("*");
        printf("\n");

        while (count_height < (height - 3 - ((height - 3) / 2))) {
                printf("*");
                for (int j = 1; j <= width - 2; j++) {
                        printf(" ");
                }
                printf("*");
                printf("\n");
                count_height += 1;
        }
        for (int j = 1; j < width + 1; j++) {
                        printf("*");
        }
        free(text);
        return 0;
}
