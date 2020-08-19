#include<stdio.h>
#include<cs50.h>
#include<math.h>

long checksum(long number);
void card(long number);

int main(void)
{

    long number = get_long("Number: "); //The credit card number

    //Verify checksum if is valid
    if (checksum(number) % 10 == 0)
    {
        card(number);
    }
    else
    {
        printf("INVALID\n");
    }

}

long checksum(long number)
{

    long power = 2, powe = 1, n = number, count = 0, multi, sum = 0, sum1 = 0;

    //Count the lenght of tu number card
    while (n != 0)
    {
        n /= 10;
        count++;
    }

    //Split and do operations to the number
    while (true)
    {
        //Split 2 and 2 and multiply for 2
        long current = number % (long) pow(10, power);
        multi = (current /= (long) pow(10, power - 1)) * 2;

        //Sum the multipli
        if (multi / 10 == 1)
        {
            sum += (multi / 10) + (multi % 10);
        }
        else
        {
            sum += multi;
        }

        power += 2;

        //Stop if the power pass the lenght of the number
        if (power > count)
        {
            break;
        }
    }

    while (true)
    {
        //Split 2 and 2 and multiply for 2 but began for frist value
        long current1 = number % (long) pow(10, powe);
        current1 /= (long) pow(10, powe - 1);

        //add the numbers
        sum1 += current1;

        powe += 2;

        //Stop if power pass the lenght of the number card
        if (powe > count)
        {
            break;
        }
    }

    return sum1 + sum;
}

void card(long number)
{
    long length = 0, n = number, ini;

    //Count the lenght
    while (n != 0)
    {
        n /= 10;
        length++;
    }

    //Receive the frist  2 front  number of a card number
    ini = (long)(number / pow(10, length - 2));

    //Verify the type of Card
    if (length == 15 && (ini == 34 || ini == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (ini == 51 || ini == 52 || ini == 53 || ini == 54 || ini == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && ini / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}