#include <stdio.h>

void start_print(int *ps, int size);

int main(void)
{
    char input;
    int size = 0;
    int score[20];

    while(1)
    {
        scanf("%d", &score[size]);
        if(input == EOF)
            break;
        else
        {
            size++;
            scanf("%d", &score[size]);
        }
    }

    start_print(score, size);

    return 0;
}

void start_print(int *ps, int size)
{
    int i, n, star;

    for(i = 0 ; i < size ; i++) 
    {
        star = ps[i] / 5;
        printf("(%d) ", ps[i]);
        for(n = 0 ; n < star ; n++) 
        {
            printf("*");
        }
        printf("\n");
     }
}
