#include <stdio.h>
#include <string.h>

/*
The Sales Report program asks you to read 12 monthly sales and generate a sales report.
Monthly Sales Report: Display the month and sales in two columns.
Sales Summary Report: Show the minimum, maximum, and average monthly sales.
Six-Month Moving Average Report.
Sales Report (Highest to Lowest): Display the sales from highest to lowest.
*/

// Get input for sales array
void getInput(char *months[], float sales[]) {
    for (int i = 0; i < 12; i++) {
        printf("Enter sales for %s: ", months[i]);
        scanf("%f", &sales[i]);
    }
}

// Display the month and sales in two columns.
void monthlySalesReport(char *months[], float sales[]) {
    printf("Month\t\tSales\n");

    for (int i = 0; i < 12; i++) {
        if (strlen(months[i]) < 8) {
            printf("%s\t\t%.2f\n", months[i], sales[i]);
        }
        else {
            printf("%s\t%.2f\n", months[i], sales[i]);
        }
    }
}

// Helper function for salesSummaryReport
void findMinSales(char* months[], float sales[]) {
    float min = sales[0];
    int minIndex = 0;

    for (int i = 1; i < 12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
    }

    printf("Minimum sales:\t%.2f\t(%s)\n", min, months[minIndex]);
}

// Helper function for salesSummaryReport
void findMaxSales(char* months[], float sales[]) {
    float max = sales[0];
    int maxIndex = 0;

    for (int i = 1; i < 12; i++) {
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
    }

    printf("Maximum sales:\t%.2f\t(%s)\n", max, months[maxIndex]);
}

// Helper function for salesSummaryReport
void findAverageSales(float sales[]) {
    // Sum every element and divide by the number of months
    float sum = sales[0];
    
    for (int i = 1; i < 12; i++) {
            sum += sales[i];
    }

    printf("Average sales:\t%.2f\n", sum/12);
}

// Show the minimum, maximum, and average monthly sales
void salesSummaryReport(char *months[], float sales[]) {
    printf("\nSales Summary Report:\n\n");
    findMinSales(months, sales);
    findMaxSales(months, sales);
    findAverageSales(sales);
}

void sixMonthMovingAverageReport(char *months[], float sales[]) {
    printf("\nSix-Month moving average report:\n\n");
    float sum = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j < i+6; j++) {
            sum += sales[j];
        }
        if (strlen(months[i]) < 16) {
            printf("%s-%s\t\t%.2f\n", months[i], months[i+5], sum/6);
        }
        else {
            printf("%s-%s\t%.2f\n", months[i], months[i+5], sum/6);
        }
        sum = 0;
    }
}

int main() {
    float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


    // getInput(months, sales);
    printf("\nMonthly Sales Report for 2024\n\n");
    monthlySalesReport(months, sales);
    salesSummaryReport(months, sales);
    sixMonthMovingAverageReport(months, sales);

    return 0;
}