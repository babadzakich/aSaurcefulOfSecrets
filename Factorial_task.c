#include <stdio.h>
#include <math.h>

typedef struct Longnum_s {
    int length;
    int number[3001];
}LongNum;

// int comparasion(LongNum firstNumber, int secondNumber)
// {
//     int IntFirstNumber = 0;
// for (int step = 0; step < firstNumber.length; ++step)
// {
//     if (step == 0)
//     {
//         IntFirstNumber += firstNumber.number[step];
//     }
//     else
//     {
//         IntFirstNumber += pow(10, step)*firstNumber.number[step];
//     }
//     if (IntFirstNumber == secondNumber + 1)
//     {
//         return 1;
//     }
//     else 
//     {
//         return 0;
//     }
// }
// }

LongNum factorial_f(LongNum factorial, int IntMultiplier)
{
    int bit_perenosa = 0, temporary_number, step = 0;
    LongNum result, multiplier;
    multiplier.length = 0;
    result.length = factorial.length;
    do
    {
        multiplier.number[step++] = IntMultiplier % 10;
        IntMultiplier /= 10;
        multiplier.length ++;
    } while (IntMultiplier % 10 != 0);
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

// LongNum sum(LongNum number)
// {
//     LongNum one;
//     one.number[0] = 1;
//     int bitPerenosa = 0;
//     for (int step = 0; step < number.length; step ++)
//     {
//         if(step == 0)
//         {
//             bitPerenosa = (number.number[step] + 1) / 10;
//             number.number[step] = (number.number[step] + 1) % 10;
//         }
//         else 
//         {
//             if (bitPerenosa != 0)
//             {
//                 int temporalNumber = number.number[step];
//                 number.number[step] = (bitPerenosa + temporalNumber) % 10;
//                 bitPerenosa = (bitPerenosa + temporalNumber) / 10;
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     return number;
// }

int main()
{
    LongNum factorial;
    int factorial_limit;
    factorial.length = 1;
    factorial.number[0] = 1;
    //factorial = factorial_f(factorial, factorial_step);
    scanf("%d", &factorial_limit);
    if (factorial_limit == 0)
    {
        printf("1");
    }
    else{
        for (int step = 1; step <= factorial_limit; ++step)
        {
            factorial = factorial_f(factorial, step);
        }
        // while(!comparasion(factorial_step, factorial_limit))
        // {
        //     factorial = factorial_f(factorial, factorial_step);
        //     factorial_step = sum(factorial_step);
        // }
        for (int step = factorial.length-1; step >= 0; --step)
        {
            printf("%d",factorial.number[step]);
        }
    }
    return 0;
}