#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

string encipher(string plaintext, int key);

int main(int argc, string argv[])
{
    //Verify if the user put 1 argument
    if (argc == 2)
    {
        //Verify if the argument is a number
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //Put help to the user
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                exit(1);
            }
        }

        int key = atoi(argv[1]);//Convert string to number
        string plaintext = get_string("plaintext: \a");
        printf("ciphertext: %s\n", encipher(plaintext, key));
    }
    else
    {
        //Help to the user
        printf("Usage: ./caesar key\n");
    }
}

string encipher(string plaintext, int key)
{
    string enciphertext = plaintext;
    char c, cha, soma, mod, final;

    //Using ASCII code
    for(int i = 0, n = strlen(plaintext); i <= n; i++)
    {
        //Verify if is Alphabet
        if (isalpha(plaintext[i]))
        {
            //Use this formula Ci = (Pi + k) % 26
            if (isupper(plaintext[i]))
            {
                c = plaintext[i] - 65; //Convert ASCII to alphabet index example (A = 0)
                cha = plaintext[i];
                soma = c + key;
                mod = soma % 26;
                final = mod + 65; //Convert Alphabet index to ASCII
                enciphertext[i] = final;
            }
            else
            {
                c = plaintext[i] - 97; //Convert ASCII to alphabet index example (a = 0)
                cha = plaintext[i];
                //Aply the formula
                soma = c + key;
                mod = soma % 26;
                final = mod + 97; //Convert Alphabet index to ASCII
                enciphertext[i] = final;

            }
        }
        else
        {   //If the char is not alphabet place the same char
            enciphertext[i] = plaintext[i];
        }
    }
    return enciphertext;
}