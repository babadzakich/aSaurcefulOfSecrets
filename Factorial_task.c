#include <stdio.h>
#include <math.h>

typedef struct Longnum_s {
    int length;
    int number[3001];
}LongNum;

int comparasion(LongNum firstNumber, int secondNumber)
{
    int IntFirstNumber = 0;
for (int step = 0; step < firstNumber.length; ++step)
{
    if (step == 0)
    {
        IntFirstNumber += firstNumber.number[step];
    }
    else
    {
        IntFirstNumber += pow(10, step)*firstNumber.number[step];
    }
    if (IntFirstNumber == secondNumber)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
}

LongNum factorial_f(LongNum factorial, LongNum multiplier)
{
    int bit_perenosa = 0, temporary_number;
    LongNum result;
    result.length = factorial.length;
    for (int step = 0; step < 3001; step++)
    {
        result.number[step] = 0;
    }
    for(int step = 0; step < multiplier.length; ++step)
    {
        for (int step2 = 0; step2 < factorial.length; ++step2)
        {
            temporary_number = result.number[step2 + step]; //заменяем чтобы не было ошибок ниже
            result.number[step2 + step] = (temporary_number + factorial.number[step2] * multiplier.number[step] + bit_perenosa) % 10;
            bit_perenosa = (temporary_number + factorial.number[step2] * multiplier.number[step] + bit_perenosa) / 10;
        }
        if (bit_perenosa != 0)
        {
            result.number[result.length++] = bit_perenosa % 10;
            bit_perenosa /= 10;
        }
    }
    return result;
}

int main()
{
    LongNum factorial, factorial_step;
    int factorial_limit;
    factorial_step.length = 2;
    factorial_step.number[0] = 9;
    factorial_step.number[1] = 1;
    factorial.length = 2;
    factorial.number[0] = 0;
    factorial.number[1] = 2;
    factorial = factorial_f(factorial, factorial_step);
    //scanf("%d", &factorial_limit);
    // while(!comparasion(factorial_step, factorial_limit))
    // {
    //     factorial = factorial_f(factorial, factorial_step);
    //     factorial_step = sum(factorial_step);
    // }
    printf("%d%d%d",factorial.number[2], factorial.number[1], factorial.number[0]);
    return 0;
}