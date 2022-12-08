/*****************************************************\
| Name : Philip Rickey                                |  
| Date: 9/17/2022                                     |
| Class : CPT_S 121 PA 3                              |  
| Description: This program processes numbers that    |
|			 corrosponds with student records read    |
|			 in a file, and writes results to main    |
\*****************************************************/

#include "GPA.h"


int main(void) {

	// Integer variables for standing, student, and number
	int standing1 = 0, standing2 = 0, standing3 = 0, standing4 = 0, standing5 = 0,
		student1 = 0, student2 = 0, student3 = 0, student4 = 0, student5 = 0,
	    number1 = 0, number2 = 0, number3 = 0, number4 = 0, number5 = 0;
	
	// Double variables for gpa, age, total, average, and deviations
	double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0, age1 = 0.0, age2 = 0.0,
		age3 = 0.0, age4 = 0.0, age5 = 0.0;

	// Files
	FILE* infile = fopen("input.dat", "r");
	FILE* outfile = fopen("output.dat", "w");
	
	// Calls functions to get information for student 1
	number1 = readInteger(infile);
	gpa1 = readDouble(infile);
	standing1 = readInteger(infile);
	age1 = readDouble(infile);

	// Calls functions to get information for student 2
	number2 = readInteger(infile);
	gpa2 = readDouble(infile);
	standing2 = readInteger(infile);
	age2 = readDouble(infile);

	// Calls functions to get information for student 3
	number3 = readInteger(infile);
	gpa3 = readDouble(infile);
	standing3 = readInteger(infile);
	age3 = readDouble(infile);

	// Calls functions to get information for student 4
	number4 = readInteger(infile);
	gpa4 = readDouble(infile);
	standing4 = readInteger(infile);
	age4 = readDouble(infile);

	// Calls functions to get information for student 5
	number5 = readInteger(infile);
	gpa5 = readDouble(infile);
	standing5 = readInteger(infile);
	age5 = readDouble(infile);

	// Calls the functions to get the sum of the gpa, standings, and ages respectively
	double sumOfGpa = calculateSum(gpa1, gpa2, gpa3, gpa4, gpa5);
	printf("%lf\n\n", sumOfGpa);
	double sumOfStandings = calculateSum(standing1, standing2, standing3, standing4, standing5);
	printf("%lf\n\n", sumOfStandings);
	double sumOfAges = calculateSum(age1, age2, age3, age4, age5);
	printf("%.2lf\n\n", sumOfAges);

	// Calls the functions to get the mean of the gpa, standings, and ages respectively
	double meanOfGpa = calculateMean(sumOfGpa, 5);
	printDouble(outfile, meanOfGpa);
	fprintf(outfile, "\n");
	double meanOfClassStandings = calculateMean(sumOfStandings, 5);
	printDouble(outfile, meanOfClassStandings);
	fprintf(outfile, "\n");
	double meanOfAges = calculateMean(sumOfAges, 5);
	printDouble(outfile, meanOfAges);
	fprintf(outfile, "\n\n");

	// Calls the functions to get the deviations of the gpa's
	double deviationOfGpa1 = calculateDeviation(gpa1, meanOfGpa);
	double deviationOfGpa2 = calculateDeviation(gpa2, meanOfGpa);
	double deviationOfGpa3 = calculateDeviation(gpa3, meanOfGpa);
	double deviationOfGpa4 = calculateDeviation(gpa4, meanOfGpa);
	double deviationOfGpa5 = calculateDeviation(gpa5, meanOfGpa);

	// Calls a function to get the variance of the gpa
	double varianceOfGpa = calculateVariance(deviationOfGpa1, deviationOfGpa2, deviationOfGpa3, deviationOfGpa4, deviationOfGpa5, 5);

	// Calls a function to get the standard deviation of the gpa
	double standardDeviationOfGpa = calculateStandardDeviation(varianceOfGpa);
	printDouble(outfile, standardDeviationOfGpa);
	fprintf(outfile, "\n");

	// Calls a function to get the minimum gpa
	double minOfGpa = findMin(gpa1, gpa2, gpa3, gpa4, gpa5);
	printDouble(outfile, minOfGpa);
	fprintf(outfile, "\n");

	// Calls a function to get the maximum gpa
	double maxOfGpa = findMax(gpa1, gpa2, gpa3, gpa4, gpa5);
	printDouble(outfile, maxOfGpa);
	fprintf(outfile, "\n");

	fclose(infile);
	fclose(outfile);
	return 0;
}