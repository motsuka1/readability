// evaluate grade level needed to comprehend some texts

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string argv);
int count_words(string argv);
int count_sentences(string argv);
int evaluate_grade_level(string argv);

int main(void)
{
    string text = get_string("Text: ");
    // printf("%lu length of string\n", strlen(text));
    // printf("%i letter(s)\n", count_letters(text));
    // printf("%i word(s)\n", count_words(text));
    // printf("%i sentence(s)\n", count_sentences(text));
    if(evaluate_grade_level(text) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(evaluate_grade_level(text) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", evaluate_grade_level(text));
    }
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
        if(argv[i] == 46 || argv[i] == 33 || argv[i] == 63)
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

int evaluate_grade_level(string argv)
{
    float L = count_letters(argv) * 100 / count_words(argv);
    float S = count_sentences(argv) *  100 / count_words(argv);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade_level = round(index);
    return grade_level;
}
