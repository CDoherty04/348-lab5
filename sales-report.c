#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Get input for sales array
void getInput(char *months[], float sales[])
{
    for (int i = 0; i < 12; i++)
    {
        while (1)
        {
            printf("Enter sales for %s: ", months[i]);
            if (scanf("%f", &sales[i]) != 1)
            {
                printf("Invalid value. Please enter a valid number.\n");
                // Clear the input buffer to avoid an infinite loop
                while (getchar() != '\n');
            }
            else {
                break;
            }
        }
    }
}

// Display the month and sales in two columns.
void monthlySalesReport(char *months[], float sales[])
{
    printf("Month\t\tSales\n");

    // Add extra tabs for shorter month names
    for (int i = 0; i < 12; i++)
    {
        if (strlen(months[i]) < 8)
        {
            printf("%s\t\t$%.2f\n", months[i], sales[i]);
        }
        else
        {
            printf("%s\t$%.2f\n", months[i], sales[i]);
        }
    }
}

// Helper function for salesSummaryReport
void findMinSales(char *months[], float sales[])
{
    float min = sales[0];
    int minIndex = 0;

    // Compares every item to find minimum
    for (int i = 1; i < 12; i++)
    {
        if (sales[i] < min)
        {
            min = sales[i];
            minIndex = i;
        }
    }

    printf("Minimum sales:\t$%.2f\t(%s)\n", min, months[minIndex]);
}

// Helper function for salesSummaryReport
void findMaxSales(char *months[], float sales[])
{
    float max = sales[0];
    int maxIndex = 0;

    // Compares every item to find maximum
    for (int i = 1; i < 12; i++)
    {
        if (sales[i] > max)
        {
            max = sales[i];
            maxIndex = i;
        }
    }

    printf("Maximum sales:\t$%.2f\t(%s)\n", max, months[maxIndex]);
}

// Helper function for salesSummaryReport
void findAverageSales(float sales[])
{
    float sum = sales[0];

    // Sum every element and divide by the number of months
    for (int i = 1; i < 12; i++)
    {
        sum += sales[i];
    }

    printf("Average sales:\t$%.2f\n", sum / 12);
}

// Show the minimum, maximum, and average monthly sales
void salesSummaryReport(char *months[], float sales[])
{
    printf("\nSales Summary Report:\n\n");
    findMinSales(months, sales);
    findMaxSales(months, sales);
    findAverageSales(sales);
}

// Show average sales over all 7 six-month periods of the year
void sixMonthMovingAverageReport(char *months[], float sales[])
{
    printf("\nSix-Month Moving Average Report:\n\n");
    float sum = 0;

    // 7 month "ranges"
    for (int i = 0; i <= 6; i++)
    {

        // find averages for 6 month periods and output
        for (int j = i; j < i + 6; j++)
        {
            sum += sales[j];
        }
        if (strlen(months[i]) < 16)
        {
            printf("%s-%s\t\t$%.2f\n", months[i], months[i + 5], sum / 6);
        }
        else
        {
            printf("%s-%s\t$%.2f\n", months[i], months[i + 5], sum / 6);
        }

        // Reset sum before next iteration
        sum = 0;
    }
}

// Display the sales from highest to lowest
void highToLowSalesReport(char *months[], float sales[])
{

    // Descending bubble sort algorithm
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11 - i; j++)
        {
            if (sales[j] < sales[j + 1])
            {

                // Switch sales values
                float tempSale = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = tempSale;

                // Switch months values
                char *tempMonth = months[j];
                months[j] = months[j + 1];
                months[j + 1] = tempMonth;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n\n");
    monthlySalesReport(months, sales);
}

int main()
{
    float sales[12];
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Get input
    getInput(months, sales);

    // Process and output
    printf("\nMonthly Sales Report for 2024\n\n");
    monthlySalesReport(months, sales);
    salesSummaryReport(months, sales);
    sixMonthMovingAverageReport(months, sales);
    highToLowSalesReport(months, sales);

    return 0;
}