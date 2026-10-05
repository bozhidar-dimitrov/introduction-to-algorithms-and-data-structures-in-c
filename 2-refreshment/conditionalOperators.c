#include <stdio.h>

int main() {

    int a = 5;

    //Good pracice
    if (a < 3) {
        printf("A is greater than 3 \n");
        printf("Something else \n");
    }

    //Bad practice
    if (a < 3) 
        printf("A is greater than 3 \n");
        printf("Something else \n");

    //This is acceptable
    if (a < 3) printf("A is greater than 3 \n");

    int b = 3;
    //if b > 5 => b is greater than 5
    //if not => b is not greater than 5

    /**
     *              |
     *              |
     *              |
     *    -- не --b > 5 -- да --
     *    |                     | 
     *    |                     |
     *  инструкции 1    инструкции 2
     *    |                     |
     *    -----------------------
     *              |
     *              |  
     */      
    if (b > 5) {
        printf("b is greater than 5 \n");
    } else {
        printf("b isn't greater than 5 \n");
    }

    int b2 = 5;
    /**
     * b2 > 5 => Greater than 5
     * b2 > 3 => Greater than 3
     * b2 > 2 => Greater than 2
     * else => Something else
     */
    if (b2 > 5) {
        printf("Greater than 5\n");
    } else {
        if (b2 > 3) {
            printf("Greater than 3\n");
        }else {
            if (b2 > 2) {
                printf("Grater than 2\n");
            } else {
                printf("Something else \n");
            }
        }
    }

    if (b > 5) {
        printf("Greater than 5\n");
    } else if (b > 3) {
        printf("Greater than 3\n");
    } else if (b > 2) {
        printf("Greater than 2\n");
    } else {
        printf("Something else");
    }

    int dayOfTheWeek = 2;
    /**
     * dayOfTheWeek == 1 => Monday
     * dayOfTheWeek == 2 => Tuesday
     * dayOfTheWeek == 3 => Wednesday
     * else => Some other day
     */
    if (dayOfTheWeek == 1) {
        printf("Monday\n");
    } else if (dayOfTheWeek == 2) {
        printf("Tuesday\n");
    } else if (dayOfTheWeek == 3) {
        printf("Wednesday\n");
    } else {
        printf("Some other day\n");
    }

    printf("------------------\n");

    switch(dayOfTheWeek) {
        case 1: 
            printf("Monday \n");
            break;
        case 2:
            printf("Tuesday \n");
            break;
        case 3:
            printf("Wednesday \n");
            break;
        default:
            printf("Some other day \n");
            break;
    }

    printf("GoodBye\n");

    return 0;
}