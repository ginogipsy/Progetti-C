#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 90

int main(void)
{
    const char *articles[5] = {"the","a","one","some","any"};
    const char *nouns[5] = {"boy","girl","dog","town","car"};
    const char *verbs[5] = {"drove","jumped","ran","walked","skipped"};
    const char *prepositions[5] = {"to","from","over","under","on"};

    srand(time(NULL));
    for(size_t i = 0; i<20; i++ )
    {
        char sentence[SIZE] = "";
        char article[5] = "";
        strcpy(article,articles[rand() % 5]);
        article[0] = toupper(article[0]);
        const char *noun = nouns[rand() % 5];
        const char *verb = verbs[rand() % 5];
        const char *preposition = prepositions[rand() % 5];
        const char *article1 = articles[rand() % 5];
        const char *noun1 = nouns[rand() % 5];
        strcat(sentence,article);
        strcat(sentence," ");
        strcat(sentence, noun);
        strcat(sentence," ");
        strcat(sentence,verb);
        strcat(sentence," ");
        strcat(sentence,preposition);
        strcat(sentence," ");
        strcat(sentence,article1);
        strcat(sentence," ");
        strcat(sentence,noun1);
        strcat(sentence,".");
        printf_s("\n%2d%s%s",i+1,") ", sentence);

    }
}
