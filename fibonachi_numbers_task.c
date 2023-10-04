#include <stdio.h>
typedef struct{
    int len;
    int arr[500];
} LongNum;
int fib (int a, int b, int n)
{
    if (n <= 2)
    {
        return b;
    }
    else 
    {
        return fib(b, (a+b), (n-1));
    }
}

int main()
{
    int number;
    scanf("%d", &number);
    number = fib(1, 1, number);
    printf("%d", number);
    return 0;
}