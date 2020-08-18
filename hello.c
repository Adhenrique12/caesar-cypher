#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Enter name and pront result
    string name = get_string("What is your name: ");
    printf("hello, %s \n", name);
}