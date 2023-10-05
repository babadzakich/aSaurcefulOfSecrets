#include <stdio.h>

typedef struct Label_s {
    char name [16]; //имя автора (заканчивается нулём)
    int age ; //возраст автора (сколько лет)
} Label ;

typedef struct NameStats_s {
    int cntTotal ; //сколько всего подписей
    int cntLong ; //сколько подписей с именами длиннее 10 букв
} NameStats ;

typedef struct AgeStats_s {
    int cntTotal ; //сколько всего подписей
    int cntAdults ; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids ; //сколько подписей детей (меньше 14 лет)
} AgeStats ;
void calcStats ( const Label * array , int cnt , NameStats * oNames , AgeStats * oAges )
{
    int step = 0, namel = 0;

    while (array.name[step++] != 0)
    {
        namel ++;
    }
    if (namel > 10 )
    {
        oNames.cntLong ++;
    }
    if (array.age >= 18)
    {
        oAges.cntAdults ++;
    }
    else if (array.age < 14)
    {
        oAges.cntKids ++;
    }
}
int main()
{
    AgeStats agestat;
    NameStats namestat;
    Label person;
    int amount_of_names, step2 = 0, step3 = 0;
    char Name[3];
    scanf("%d", &amount_of_names);
    agestat.cntTotal = amount_of_names;
    agestat.cntAdults = 0;
    agestat.cntKids = 0;
    namestat.cntTotal = amount_of_names;
    namestat.cntLong = 0;
    for (int step = 0; step < amount_of_names; ++step)
    {
        scanf("%s %d %s", person.name, &person.age, Name);
        calcStats (&person, amount_of_names, &namestat, &agestat);
    }
    printf("%s %s", namestat.);
    return 0;
}