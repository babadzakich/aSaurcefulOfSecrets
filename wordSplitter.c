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
        int step = 0, wordCounter = 0, letterCounter=0, isLetterFound = 0;
        char* word = (char*)malloc(sizeof(char)*1000000);
        while(str[step] != '\0')
        {
            int isDelimeter = isSymbolDelimiter(str[step], delims);
            if(!isLetterFound && !isDelimeter)
            {
                isLetterFound = 1;
                word[letterCounter++] = str[step];
            }
            else if(isLetterFound && isDelimeter)
            {
                isLetterFound = 0;
                tokens->arr[wordCounter] = (char*)malloc(sizeof(char) * letterCounter);
                strcpy(tokens->arr[wordCounter++], word);
                letterCounter = 0;
                //word[0] = '\0';
                memset(word, '\0', sizeof(word));
            }
            else if (isLetterFound && !isDelimeter)
            {
                word[letterCounter++] = str[step];
            }
            ++step;
        }
        if(strlen(word) != 0)
        {
            tokens->arr[wordCounter] = (char*)malloc(sizeof(char) * letterCounter);
            strcpy(tokens->arr[wordCounter++], word);
            letterCounter = 0;
        }
        free(word);
    }
}

//удаляет все ресурсы внутри tokens
void tokensFree ( Tokens * tokens )
{
    for (int step = 0; step < tokens->num; ++step)
    {
        if (tokens->arr[step] != NULL)
        {
            free(tokens->arr[step]);
            tokens->arr[step] = NULL;
        }
    }
}
char line[1000000];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Tokens tokens;
    tokens.num = 0;
    
    char separators[4] = ".,:;";
    
    fscanf(stdin,"%s", line);
    
    tokensSplit(&tokens, line, separators);
    tokensSplit(&tokens, line, separators);
    
    fprintf(stdout, "%d\n", tokens.num);
    for(int step = 0; step < tokens.num; ++step)
    {
        fprintf(stdout, "%s\n", tokens.arr[step]);
    }
    tokensFree(&tokens);
    free(tokens.arr);
    fclose(stdin);
    fclose(stdout);
    return 0;
}