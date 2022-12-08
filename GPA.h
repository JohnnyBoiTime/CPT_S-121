#include <stdio.h>
#include <math.h>
#ifndef GPA_H
#define GPA_H

#pragma warning(disable: 4996)

// Function protypes 
double readDouble(FILE* infile);
double readInteger(FILE* infile);
double calculateSum(double number1, double number2, double number3, double number4, double number5);
double calculateMean(double sum, int number);
double calculateDeviation(double number, double mean);
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculateStandardDeviation(double variance);
double findMax(double number1, double number2, double number3, double number4, double number5);
double findMin(double number1, double number2, double number3, double number4, double number5);
void printDouble(FILE* outfile, double number);
#endif GPA_H