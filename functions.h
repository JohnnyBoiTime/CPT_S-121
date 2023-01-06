#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee struct
typedef struct employee {
	char location[100];
	char title;
	double hoursWorked;
	double payRate;
	double payment;
} Employee;

// Function prototypes
int readFile(FILE* infile, Employee payroll[]);
void employeePaid(Employee payroll[], int numOfEmployees);
void sortEmployees(FILE* outfile, Employee payroll[], int numOfEmployees);
void getTotals(Employee payroll[], int numOfEmployees, double* paidTotal, double* paidAverage, double* paidMin, double* paidMax);