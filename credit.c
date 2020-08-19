#include<stdio.h>
#include<cs50.h>
#include<math.h>

long checksum(long number);
void card(long number);

int main(void)
{
    //The credit card number
    long number = get_long("Number: ");
    //printf("%ld", number);

    if (checksum(number) % 10 == 0)
    {
        card(number);
    }else
    {
        printf("INVALID\n");
    }

}

long checksum(long number)
{

    long power = 2,power1 = 1 , n = number, count = 0, multi,sum=0, sum1 =0;


    while (n != 0)
    {
        n /= 10;
        count++;
    }

    while(true)
    {
        long current = number % (long) pow(10, power);
        multi = (current /= (long) pow(10, power-1)) * 2;

        if (multi/10 == 1)
        {
            sum += (multi/10) + (multi%10);
        }
        else
        {
            sum += multi;
        }

        power+=2;

        if (power > count)
        {
            break;
        }
    }

    while(true)
    {
        long current1 = number % (long) pow(10, power1);
        current1 /= (long) pow(10, power1-1);

        sum1 += current1;

        power1+=2;

        if (power1 > count)
        {
            break;
        }
    }

    return sum1 + sum;
}

void card(long number)
{
    long length = 0, n = number, ini;

     while (n != 0)
    {
        n /= 10;
        length++;
    }

    ini = (long) (number / pow(10,length-2));

    if (length == 15 && (ini == 34 || ini == 37))
    {
        printf("AMEX\n");
    } else if (length == 16 && (ini == 51 || ini == 52 || ini == 53 || ini == 54 || ini == 55))
    {
        printf("MASTERCARD\n");
    } else if ((length == 13 || length == 16) && ini/10 == 4)
    {
        printf("VISA\n");
    } else
    {
        printf("INVALID\n");
    }

}