#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tokens_s {
int num ; //количество слов в строке
char ** arr ; //массив слов (каждый элемент –- строка, т.е. char*)
} Tokens ;

int isSymbolDelimiter(char symbol, const char *separators)
{
    if(symbol == separators[0] || symbol == separators[1] || symbol == separators[2] || symbol == separators[3])
    {
        return 1;
    }
    else{
        return 0;
    }
}

char* lineSubstraction(const char* source, int* startOfLine, int* endOfLine)
{
    int lengthOfLine = *endOfLine - *startOfLine;
    char* resultLine = (char*)malloc(sizeof(char) * (lengthOfLine+1));

    for (int step = *startOfLine; step < *endOfLine && (*(source+step)!='\0'); step++)
    {
        *resultLine = *(source+step);
        ++resultLine;
    }
    *resultLine = '\0';
    return resultLine - lengthOfLine;
}
//tokens: структура, в которую нужно положить результаты
//str: строка, в которой нужно искать слова
//delims: все символы-разделители в виде строки
void tokensSplit ( Tokens *tokens , const char * str , const char * delims )
{
    if (tokens->num == 0)
    {
        int step = 0,isLetterFound = 0;// flag - встретили ли мы букву.
        while(str[step] != '\0')
        {
            int isDelimeter = isSymbolDelimiter(str[step], delims);
            if(!isLetterFound && !isDelimeter)
            {
                isLetterFound = 1;
                tokens->num++;
            }
            else if(isLetterFound && isDelimeter)
            {
                isLetterFound = 0;
            }
            ++step;
        }
    }
    else
    {
        tokens->arr = malloc(sizeof(char*) * tokens->num);
        int startOfWord = -1, endOfWord, step = 0, wordCounter = 0, letterCounter=0, isLetterFound = 0;
        //char* word = (char*)malloc(sizeof(char)*1000003);
        while(str[step] != '\0')
        {
            int isDelimeter = isSymbolDelimiter(str[step], delims);
            if(!isLetterFound && !isDelimeter)
            {
                isLetterFound = 1;
                startOfWord = step;
                //word[letterCounter++] = str[step];
            }
            else if(isLetterFound && isDelimeter)
            {
                isLetterFound = 0;
                tokens->arr[wordCounter] = (char*)malloc(sizeof(char) * letterCounter);
                endOfWord = step;

                // for(int step2 = 0; step2 < letterCounter; step2++)
                // {
                //     tokens->arr[wordCounter][step2] = word[step2];
                // }
                tokens->arr[wordCounter++] = lineSubstraction(str, &startOfWord, &endOfWord);
                //wordCounter++;
                //letterCounter = 0;
                //free(word);
            }
            // else if (isLetterFound && !isDelimeter)
            // {
            //     //word[letterCounter++] = str[step];
            // }
            ++step;
        }
        if(isLetterFound)
        {
            tokens->arr[wordCounter] = (char*)malloc(sizeof(char) * letterCounter+1);
            // for(int step = 0; step < strlen(word); step++)
            // {
            //     tokens->arr[wordCounter][step] = word[step];
            // }
            // wordCounter++;
            //strcpy(tokens->arr[wordCounter++], word);
            endOfWord = step;
            tokens->arr[wordCounter++] = lineSubstraction(str, &startOfWord, &endOfWord);
        }
        //free(word);
    }
}

//удаляет все ресурсы внутри tokens
void tokensFree ( Tokens * tokens )
{
    if (tokens->arr != NULL)
    {
        for (int step = 0; step < tokens->num; ++step)
        {
            free(tokens->arr[step]);
        }
        free(tokens->arr);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Tokens tokens;
    tokens.num = 0;
    tokens.arr = NULL;

    char separators[] = ".,:;";
    char line[1000001];

    fscanf(stdin,"%s", line);
    
    tokensSplit(&tokens, line, separators);
    tokensSplit(&tokens, line, separators);
    
    fprintf(stdout, "%d\n", tokens.num);
    
    if(tokens.num != 0)
    {  
        for(int step = 0; step < tokens.num; ++step)
        {
            fprintf(stdout, "%s\n", tokens.arr[step]);
            //fprintf(stdout, "%s\n", tokens.arr[step]);
        }
    }
    
    tokensFree(&tokens);
    fclose(stdin);
    fclose(stdout);
    return 0;
}