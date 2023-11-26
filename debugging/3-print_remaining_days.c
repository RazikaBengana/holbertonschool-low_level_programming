#include "main.h"

/**
 * print_remaining_days - program that takes a date and prints how many days are left in the year,
 * taking leap years into account
 *
 * we have to fix the code so that the output works correctly for all dates and all leap years
 *
 * @month: month in number format
 * @day: day of month
 * @year: year
 *
 * Return: nothing (void)
 */

void print_remaining_days(int month, int day, int year)
{
	if (year % 4 == 0 || (year % 400 == 0 && !(year % 100 == 0)))
	{
		if (month > 2 && day >= 60)
		{
			day++;
		}

		printf("Day of the year: %d\n", day);
		printf("Remaining days: %d\n", 366 - day);
	}

	else
	{
		if (month == 2 && day == 60)
		{
			printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		}

		else
		{
			printf("Day of the year: %d\n", day);
			printf("Remaining days: %d\n", 365 - day);
		}
	}
}