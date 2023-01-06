#include "functions.h"

int main(void) {

	// Opens files
	FILE* infile = fopen("payroll.txt", "r");
	FILE* outfile = fopen("paid.txt", "w");

	// Variables
	int numOfEmployees = 0;
	double total = 0.0, average = 0.0, min = 0.0, max = 0.0, calculator = 0.0;
	
	// Employee array
	Employee payroll[5] = {0};
	
	// Reads file, sets number of employees to amount read
	numOfEmployees = readFile(infile, payroll);

	// Sorts employees, pays employees, gets totals
	sortEmployees(outfile, payroll, numOfEmployees);
	employeePaid(payroll, numOfEmployees);
	getTotals(payroll, numOfEmployees, &total, &average, &min, &max);

	// Prints total, average, max, and min to output file
	fprintf(outfile, "Total: $%.2lf\n", total);
	fprintf(outfile, "Average: $%.2lf\n", average);
	fprintf(outfile, "Max: $%.2lf\n", max);
	fprintf(outfile, "Min: $%.2lf\n", min);

	// Closes files
	fclose(outfile);
	fclose(infile);

	return 0;
}