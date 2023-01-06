#include "functions.h"

// Function that reads file
int readFile(FILE* infile, Employee payroll[]) {

	int numOfEmployees = 0;

	// Reads employee information from file
	while (!feof(infile)) {

		fgets(payroll[numOfEmployees].location, 100, infile);
		fscanf(infile, "%c ", &payroll[numOfEmployees].title);
		fscanf(infile, "%lf ", &payroll[numOfEmployees].hoursWorked);
		fscanf(infile, "%lf ", &payroll[numOfEmployees].payRate);
		numOfEmployees++;
	}

	return numOfEmployees;
}

// Function to sort employees location in reverse alphebetical order
void sortEmployees(FILE* outfile, Employee payroll[], int numOfEmployees) {

	char temp[100];

	// Uses bubble sort to sort employees
	for (int i = 0; i < numOfEmployees; i++) {
		if (strcmp(payroll[i + 1].location, payroll[i].location) > 0) {
			strcpy(temp, payroll[i + 1].location);
			strcpy(payroll[i + 1].location, payroll[i].location);
			strcpy(payroll[i + 1].location, temp);
		}

		fprintf(outfile, "%s \n", payroll[i].location);
	}

}

// Function that calculates pay for employees based on an 80 hour
// work week
void employeePaid(Employee payroll[], int numOfEmployees) {

	for (int i = 0; i < numOfEmployees; i++) {
		if (payroll[i].hoursWorked == 80.0) {
			payroll[i].payment = payroll[i].payRate * payroll[i].hoursWorked;
		}
		// If employee has the title 'B', they get paid 1.6 times more for every hour worked over 80
		if (payroll[i].title == 'B') {
			payroll[i].payment = (payroll[i].payRate * 80.0) + (payroll[i].payRate * 1.6) * (payroll[i].hoursWorked - 80.0); 
		}
		// If employee does not have the title 'B', they get paid 1.7 times more
		else {
			payroll[i].payment = (payroll[i].payRate * 80.0) + (payroll[i].payRate * 1.7) * (payroll[i].hoursWorked - 80.0);

		}
	}
}

// Gets the total, min, max, and average of the employee earnings
void getTotals(Employee payroll[], int numOfEmployees, double* paidTotal, double* paidAverage, double* paidMin, double* paidMax) {

	double total = 0.0, average = 0.0, min = payroll[0].payment, max = payroll[0].payment;

	for (int i = 0; i < numOfEmployees; i++) {
		if (max < payroll[i].payment) {
			max = payroll[i].payment;
		}
		if (min > payroll[i].payment) {
			min = payroll[i].payment;
		}
		
		total += payroll[i].payment;
	}

	*paidTotal = total;
	*paidAverage = (total / numOfEmployees);
	*paidMin = min;
	*paidMax = max;

}