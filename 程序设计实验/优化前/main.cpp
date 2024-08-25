#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "SAT.h"
#include "Haniddoku.h"

int main() {
    int op = 1;
    while (op) {
        printf("\n\n");
        printf("\t\t\t      Main Menu \n");
        printf("\t\t************************************\n");
        printf("\t\t\t1.  Sudoku   2.  SAT\n");
        printf("\t\t\t0.  Exit\n");
        printf("\t\t************************************\n");
        printf("\t\t\tPlease choose your operation[0--2]:");
        scanf("%d", &op);
        system("cls");
        switch (op) {
            case 1:
                Haniddoku(); 
                break;
            case 2:
                Sat();
                break;
            case 0:
                exit(0);
            default:
                printf("\t\t\tPlease choose your operation again[0--2]:");
                scanf("%d", &op);
        }
    }
    return 0;
}
