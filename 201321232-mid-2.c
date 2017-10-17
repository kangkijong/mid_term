#include <stdio.h>

int check_prime(int num);
void print_prime(int num);

int main(void)
{
    int num;

    printf("enter the num : ");
    scanf("%d", &num);


    print_prime(num);
    check_prime(num);

    return 0;
}

int check_prime(int num)
{
    int i, cnt=0;

    for(i=2 ; i<num ; i++)
    {
        if(num%i == 0)
            cnt++;
    }
    if(cnt==0)
        printf("entered num is sosu.\n");
    else
        printf("not sosu.\n");
}

void print_prime(int num)
{
    int i, j, k, b=0;

    for(i=2 ; i<=num ; i++)
    {
        for(j=1 ; j<=i ; j++)
        {
            if(i%j==0)
            {    
                k++;
            }
        }
        if(k<=2)
        {
            printf("%d\n",i);
            b++;
        }
        k=0;
    }
    printf("\n");
    printf("entered num's sosu : %d", b);
    printf("\n");
}
