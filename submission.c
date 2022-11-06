/*  Pari Patel
    PPF2D
    TigerHacks2022
    Project on Energy Consumption in Trains vs. Electric Cars  */

#include <stdio.h>

// energy 1 is always car
// energy 2 is always train

int Compare (float energy1, float energy2);
int PerPerson (float energy1, float energy2, int x, int y);
int EPM (int x, int y, int min1, int max1, int min2, int max2);

int Compare (float energy1, float energy2) // function to compare both methods
{
    float difference1, perc1;
    if (energy2 > energy1)
    {
        difference1 = energy2 - energy1;
        perc1 = (double) (difference1/energy2)*100;
        printf ("Traveling by electric car is more sustainable and better for the environment as it consumes %.2f kJ/pmi or %.1f percent less energy than a train.\n\n", difference1, perc1);
    }

    float difference2, perc2;
    if (energy1 > energy2)
    {
        difference2 = energy1 - energy2;
        perc2 = (double) (difference2/energy1)*100;
        printf ("\nTraveling by train is more sustainable and better for the environment as it consumes %.2f kJ/pmi or %.1f percent less energy than an electric car.\n\n", difference2, perc2);
    }

    return 0;
}

int PerPerson (float energy1, float energy2, int x, int y)
{
    float pp1;
    float pp2;
    pp1 = energy1 / x;
    pp2 = energy2 / y;
    printf ("The energy consumed per person in an electric car = %.2f kJ/pmi.\n", pp1);
    printf ("The energy consumed per person in a train = %.2f kJ/pmi.\n", pp2);
    
    Compare (pp1, pp2);
    return 0;
}

int EPM (int x, int y, int min1, int max1, int min2, int max2) // function to calculate total energy consumption for x and y number of people
{
    //car
    float teslaEPM;
    for (int i=min1; i<=max1; i++)
    {
        teslaEPM = x * 244.8;
        //float trainEPM = number2 * 220.6;
    }

    //train
    float trainEPM;
    for (int i=min2; i<=max2; i++)
    {
        //float teslaEPM = number1 * 244.8;
        trainEPM = y * 220.6;
    }

    printf ("The energy consumed per mile by an electric car with %d people = %.2f kJ/mi.\n", x, teslaEPM);
    printf ("The energy consumed per mile by a train with %d people = %.2f kJ/mi.\n", y, trainEPM);
    printf ("\n");

    //Compare (teslaEPM, trainEPM);
    PerPerson (teslaEPM, trainEPM, x, y);
    //int teslafor1
    return 0;
}

int main(void)
{
    printf ("\nWelcome to my project for TigerHacks 2022!\n\nI wrote a program to calculate and compare the energy consumption per person per mile of electric cars and trains.\nMy program compares the two values numerically to declare the more sustainable method of travel.\n\n");
    
    // the number of people can be changed according to the hour of the day and the day of the week
    int number1 = 5;
    int number2 = 15;
    int minTrain = 1;
    int maxTrain = 200;
    int minCar = 1;
    int maxCar = 5;

    EPM (number1, number2, minTrain, maxTrain, minCar, maxCar);
    return 0;
}
