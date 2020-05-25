// evaluate grade level needed to comprehend some texts

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string argv);
int count_words(string argv);
int count_sentences(string argv);

int main(void)
{
    string text = get_string("Text: ");
    printf("%lu length of string\n", strlen(text));
    printf("%i letter(s)\n", count_letters(text));
    printf("%i word(s)\n", count_words(text));
    printf("%i sentence(s)\n", count_sentences(text));
}

//Letters can be any uppercase or lowercase alphabetic characters, but shouldn’t include any punctuation, digits, or other symbols.
int count_letters(string argv)
{
    int num_letters = 0;
    for(int i = 0, n = strlen(argv); i < n; i++)
    {
        if((64 < argv[i] && argv[i] < 91) || (96 < argv[i] && argv[i] < 123))
        {
            num_letters += 1;
        }
        else
        {
            num_letters += 0;
        }
    }
    return num_letters;
}

int count_words(string argv)
{
    int num_spaces = 0;
    for(int i = 0, n = strlen(argv); i < n; i++)
    {
        if(argv[i] == 32)
        {
            num_spaces += 1;
        }
        else
        {
            num_spaces += 0;
        }
    }
    int num_words = num_spaces + 1;
    return num_words;
}

int count_sentences(string argv)
{
    int num_sentences = 0;
    for(int i = 0, n = strlen(argv); i < n; i++)
    {
        if(argv[i] == 46)
        {
            num_sentences += 1;
        }
        else
        {
            num_sentences += 0;
        }
    }
    return num_sentences;
}
