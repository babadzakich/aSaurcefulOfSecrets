#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int amountOfCalls, amountOfLines = 0;
    char **identificators;
    fscanf(stdin,"%d",&amountOfCalls);
    for (int step = 0; step < amountOfCalls; ++step)
    {   
        int currentCall;
        fscanf(stdin, "%d", &currentCall);
        if (currentCall == 0)
        {
            int lineLength;
            fscanf(stdin, "%d", &lineLength);
            char * line = (char*)malloc(lineLength);
            fscanf(stdin, "%s", line);
            *(identificators+amountOfLines++) = line;
        }
        else if (currentCall == 1)
        {
            int identifier;
            fscanf(stdin, "%d", &identifier);
            free(*(identificators+identifier));
        }
        else if (currentCall == 2)
        {
            int identifier;
            fscanf(stdin, "%d", &identifier);
            printf("%s", *(identificators+identifier));
        }
        else
        {
            int identifier;
            char simbol;
            fscanf(stdin, "%d %c", &identifier, &simbol);
            int step2 = 0;
            int counter = 0;
            while (*(*(identificators+identifier)+step) != 0)
            {
                if (*(identificators[identifier]+step) == simbol)
                {
                    counter ++;
                }
                step2++;
            }
            printf("%d", counter);
        }
    }

    
    fclose(stdin);
    fclose(stdout);
    return 0;
}