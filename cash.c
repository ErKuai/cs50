#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_change(float(dollars));
int coins = 0;

int main(void) {
    float dollars;
    //int coins;
    
    do {
        //prompt for the money
        printf("Change owed: $");
        dollars = get_float();
    }
    while(dollars <= 0.0f);
    
    //print the number of coins
    printf("Coins return: %d\n", get_change(dollars));
    return 0;
}

int get_change(float dollars) {
    //round to cents
    int cents = round(dollars * 100);
    //count quaters
    for(int i = cents; cents >= 25;) {
        cents = cents - 25;
        coins++;
    }
    //count dimes
    for(int j = cents; cents >= 10;) {
        cents = cents - 10;
        coins++;
    }
    //count pennies
    for(int k = cents; cents >= 5;) {
        cents = cents - 5;
        coins++;
    }
    //count cents
    for(int k = cents; cents >= 1;) {
        cents = cents - 1;
        coins++;
    }
    return coins;
}
