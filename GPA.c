#include "GPA.h"

// Reads  a double precision number from input file
double readDouble(FILE* infile) {
	double number;
	fscanf(infile, "%lf", &number);
	return number;
}

// Function for reading one integer number from input file
double readInteger(FILE* infile) {
	int number;
	fscanf(infile, "%d", &number);
	return number;
}

// Function for calculating the sum of the numbers inputted into the funciton
double calculateSum(double number1, double number2, double number3, double number4, double number5) {
	double result = 0.0;
	result = number1 + number2 + number3 + number4 + number5;
	return result;
}

// Caclulates the mean of the inputed number
double calculateMean(double sum, int number) {
	double mean = 0.0;
	mean = sum / number;
	if (mean != 0) {
		return mean;
	}
	else
		return -1.0;
}

// Function to calculate the deviation
double calculateDeviation(double number, double mean) {
	return number - mean;
}

// Function to calculate the variance 
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	double result = 0.0;
	result = ( ((deviation1 * deviation1) + (deviation2 * deviation2) + (deviation3 * deviation3) + (deviation4 * deviation4) + (deviation5 * deviation5)) / number);
	return result;
}

// Function to calculate standard deviation
double calculateStandardDeviation(double variance) {
	double result = 0.0;
	result = sqrt(variance);
}

// Function to find the max number of a set
double findMax(double number1, double number2, double number3, double number4, double number5) {
	double numbers[] = { number2, number3, number4, number5 };
	double maxNum = number1;
	for (int i = 0; i < 4; i++) {
		if (numbers[i] > maxNum) {
			maxNum = numbers[i];
		}
	}
		return maxNum;
}

// Function to find the min number of the set
double findMin(double number1, double number2, double number3, double number4, double number5) {
	double numbers[] = { number2, number3, number4, number5 };
	double minNum = number1;
	for (int i = 0; i < 4; i++) {
		if (numbers[i] < minNum) {
			minNum = numbers[i];
		}
	}
	return minNum;
}

// Function to print a double to the file
void printDouble(FILE* outfile, double number) {
	fprintf(outfile, "%.2lf", number);
}
