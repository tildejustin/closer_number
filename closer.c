#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int booleanify (int);
void firstwins (), secondwins ();

int main() {
    int first, second, picked, pir_num, range;
    bool pir;
    // init the random number generator
    srand(time(NULL));

    printf("Basic Number Comparer\n~justin, 23 Sep. 2022\n\n");
    printf("What is your upper bound? ");
    scanf("%d", &range);
    // generate a random number and take the modulus of range, then add one to get a number between 1 and the picked range
    // not secure, but who cares
    picked = (rand() % range) + 1;
    // printf("picked: %d\n", picked);
    printf("Price is Right rules? (0/1) ");
    scanf("%d", &pir_num);
    // turn pir into a bool, doesn't matter at all but it's practice with c functions
    pir = booleanify(pir_num);
    printf("What is the first number? ");
    scanf("%d", &first);
    printf("What is the second number? ");
    scanf("%d", &second);
    // only does "price is right" rules if given a 1, else doesn't use them
    // printf("First num: %d, Second num: %d\n", first, second);
    // terminates program if any number is less than 1
    if (first < 1 || second < 1) {
        printf("One or both numbers are less than one, terminating program\n");
        exit(0);
    }
    // runs this logic if using "price is right" rules
    if (pir) {
        // runs only if both numbers don't exceed the picked number
        // prob could be implemented better
        if (!(picked - first < 0 && picked - second < 0)) {
            // runs if numbers are equal
            if (first == second) {
                printf("Both numbers are correct\n");
            // if first number is closer or second number goes over the picked number
            } else if (second - picked > 0 || first > second) {
                firstwins (picked);
            // if second number is closer or first number goes over
            } else if (first - picked > 0 || second > first) {
                secondwins (picked);
            }
        // exits if both numbers are over
        } else {
            printf("Both numbers went over\n");
        }
    // runs if "price is right" rules are not being used
    } else if(!pir) {
        // if (!(first - picked) && !(second - picked)) {
        //     printf("Both numbers are correct\n");
        if (abs(first - picked) == abs(second - picked)) {
            printf ("Both numbers are the same distance away\n");
        } else if (abs(first - picked) < abs(second - picked)) {
            firstwins (picked);
        } else if (abs(second - picked) < abs(first - picked)) {
            secondwins (picked);
        }
        // printf("pir rules: false\n");
    }
    //     if(((first - picked) <= 0) and ((second - picked) <= 0));
    //         printf("Both numbers are less than or equal to the picked number \n");
    return 0;
}

int booleanify (int input) {
    if (input == 1) {
        return true;
    }
    else {
        return false;
    }
}

void firstwins (int picked) {
    printf("First wins!\n");
    printf("The picked number was %d\n", picked);
}

void secondwins (int picked) {
    printf("Second wins!\n");
    printf("The picked number was %d\n", picked);
}