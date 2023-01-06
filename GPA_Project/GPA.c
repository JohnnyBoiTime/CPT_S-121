#include "GPA.h"

// Function to read the file
int readFile(FILE* inFile, Student student[]) {


	int numOfStudents = 0;

	// Gets students information
	while (!feof(inFile)) {
		fscanf(inFile, "%d ", &student[numOfStudents].idNumber);
		fscanf(inFile, "%lf ", &student[numOfStudents].gpa);
		fscanf(inFile, "%lf ", &student[numOfStudents].standing);
		fscanf(inFile, "%lf ", &student[numOfStudents].age);
		numOfStudents++;
	}
	return numOfStudents; // Returns number of students after end of file is reached
}

// Function for calculating the sum of the numbers inputted into the funciton
void calculateSum(Student student[], int numOfStudents, double *gpa, double *maxGpa, double *minGpa, double *standing, double *age) {
	
	double gpaTotal = 0.0, standingTotal = 0.0, ageTotal = 0.0, min = student[0].gpa,
		   max = student[0].gpa;

	// Finds max and min of student gpa
	for (int i = 0; i < numOfStudents; i++) {
		if (max < student[i].gpa) {
			max = student[i].gpa;
		}
		if (min > student[i].gpa) {
			min = student[i].gpa;
		}

		// Calculates total for student gpa, standing, and age
		gpaTotal += student[i].gpa;
		standingTotal += student[i].standing;
		ageTotal += student[i].age;
	}

	// Stores information
	*gpa = gpaTotal;
	*standing = standingTotal;
	*age = ageTotal;
	*maxGpa = max;
	*minGpa = min;

}

// Caclulates the mean of the inputed number
void calculateMean(Student student[], int numOfStudents, double *meanGpa, double *meanStanding, double *meanAge) {
	
	double gpaTotal = 0.0, standingTotal = 0.0, ageTotal = 0.0;

	// Calculates totals for gpa, standing, and age of students
	for (int i = 0; i < numOfStudents; i++) {
		gpaTotal += student[i].gpa;
		standingTotal += student[i].standing;
		ageTotal += student[i].age;
	}

	// Calculates means of gpa, standing, and age
	*meanGpa = gpaTotal / numOfStudents;
	*meanStanding = standingTotal / numOfStudents;
	*meanAge = ageTotal / numOfStudents;
}

// Function to calculate the deviation
void calculateDeviation(Student student[], double deviations[], int numOfStudents, double *meanGpa) {
	
	// Calculates standard deviation
	for (int i = 0; i < numOfStudents; i++) {
		deviations[i] = student[i].gpa - *meanGpa;
	}
	
}

// Function to calculate the variance 
void calculateVariance(double deviations[], int numOfStudents, double *variance) {
	
	double deviationAddition = 0.0;

	// Calculaats deviation
	for (int i = 0; i < numOfStudents; i++) {
		deviationAddition += (deviations[i] * deviations[i]);
	}

	// Calculates variance
	*variance = deviationAddition / numOfStudents;

}

// Function to calculate standard deviation
void calculateStandardDeviation(double *variance, double *standardDeviation) {

	// Calculates standard deviation
	*standardDeviation = sqrt(*variance);

}


