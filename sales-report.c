#include <stdio.h>
#include <string.h>

/*
The Sales Report program asks you to read 12 monthly sales and generate a sales report.
Monthly Sales Report: Display the month and sales in two columns.
Sales Summary Report: Show the minimum, maximum, and average monthly sales.
Six-Month Moving Average Report.
Sales Report (Highest to Lowest): Display the sales from highest to lowest.
*/

void getInput(char *months[], float sales[]) {
    for (int i = 0; i < 12; i++) {
        printf("Enter sales for %s: ", months[i]);
        scanf("%f", &sales[i]);
    }
}

int main() {
    float sales[12];
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    getInput(months, sales);
    printf("\nMonthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");

    for (int i = 0; i < 12; i++) {
        if (strlen(months[i]) < 8) {
            printf("%s\t\t%.2f\n", months[i], sales[i]);
        }
        else {
            printf("%s\t%.2f\n", months[i], sales[i]);
        }
    }

    return 0;
}