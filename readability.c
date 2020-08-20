#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void grade(string text);

int main(void)
{
    string text = get_string("Text: ");
    grade(text);
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters ++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (text[i] == ' ' || text[i] == '\0')
        {
            words ++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }
    }
    return sentences;
}

void grade(string text)
{

    float l = ((float)count_letters(text) / (float)count_words(text)) * 100.0;
    float s = ((float)count_sentences(text) / (float)count_words(text)) * 100.0;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);


    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %d", grade);
    }

}