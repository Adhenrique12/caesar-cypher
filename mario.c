#include<stdio.h>
#include<cs50.h>


void pyramide(int height);
int get_positive_int(void);


int main(void)
{
    int height = get_positive_int();
    //Function then build the pyramide
    pyramide(height);
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void pyramide(int height)
{

    int espaces = height - 1;
    int hashes = 1;

    for(int n = 0; n < height; n++)
    {
        for(int i = 0; i < espaces; i++)
        {
            printf(" ");

        }
        for(int i = 0; i < hashes; i++)
        {
            printf("#");
        }
        printf("  ");
        for(int i = 0; i < hashes; i++)
        {
            printf("#");
        }
        hashes++;
        espaces--;
        printf("\n");
    }
}