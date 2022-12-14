#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int booleanify (int);
void firstwins (), secondwins ();
void numchecks (int, int, int);
void enter ();

int main() {
    int first, second, picked, pir_num, range;
    bool pir;
    // init the random number generator so the number is different each time heh
    srand(time(NULL));

    printf("Basic Number Comparer\n~justin, 23 Sep. 2022\n\n");
    printf("What is your number limit? ");
    scanf("%d", &range);
    // generate a random number and take the modulus of it and range
    // then add one to get a number between 1 and the picked range inclusive
    // not secure, but who cares
    picked = (rand() % range) + 1;
    // printf("picked: %d\n", picked);
    // terrible implementation
    printf("Price is Right rules? (0/1) ");
    scanf("%d", &pir_num);
    // turn pir into a bool, doesn't matter at all but it's practice with c functions
    pir = booleanify(pir_num);
    printf("What is the first number? ");
    scanf("%d", &first);
    printf("What is the second number? ");
    scanf("%d", &second);
    // printf("First num: %d, Second num: %d\n", first, second);
    numchecks(first, second, range);

    // normal logic
    if (!pir) {
        // if (!(first - picked) && !(second - picked)) {
        //     printf("Both numbers are correct\n");
        if (abs(first - picked) == abs(second - picked)) {
            printf ("Both numbers are the same distance away\n");
            printf("The picked number was %d\n", picked);
        } else if (abs(first - picked) < abs(second - picked)) {
            firstwins (picked);
        } else if (abs(second - picked) < abs(first - picked)) {
            secondwins (picked);
        }
    }

    // price is right logic
    else if (pir) {
        // runs only if both numbers don't exceed the picked number
        // prob could be implemented better
        if (!(picked - first < 0 && picked - second < 0)) {
            // runs if numbers are equal
            if (first == second) {
                printf("Both numbers are correct\n");
                printf("The picked number was %d\n", picked);
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
            printf("The picked number was %d\n", picked);
        }
    }

    enter();
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
    printf ("First wins!\n");
    printf ("The picked number was %d\n", picked);
}

void secondwins (int picked) {
    printf("Second wins!\n");
    printf("The picked number was %d\n", picked);
}

void numchecks (int first, int second, int range) {
    // terminates program if any number is less than 1
    if (first < 1 || second < 1) {
        printf("One or both numbers are less than one, terminating program\n");
        enter();
    }
    // terminates program if any number is larger than range
    if (first > range || second > range) {
        printf("One or both of the numbers is higher than your set range. Termination immenent.\n");
        enter();
    }
}

void enter (void) {
    printf("Press enter to exit");
    // TODO implement enter to exit
    // while (true) {
    //     if (key.enter) {
    //         exit(0)
    //     }
    // }
    // temp solution
    scanf(" ");
    exit(0);
}
