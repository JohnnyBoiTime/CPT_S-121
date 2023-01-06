#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#ifndef GPA_H
#define GPA_H

// Structure for a student
typedef struct student {
	int idNumber;
	double gpa;
	double standing;
	double age;
} Student;

// Function protypes 
int readFile(FILE* inFile, Student student[]);
void calculateSum(Student student[], int numOfStudents, double* gpa, double* mixGpa, double* manGpa, double* standing, double* age);
void calculateMean(Student student[], int numOfStudents, double* meanGpa, double* meanStanding, double* meanAge);
void calculateDeviation(Student student[], double deviations[], int numOfStudents, double* meanGpa);
void calculateVariance(double deviations[], int numOfStudents, double* variance);
void calculateStandardDeviation(double* variance, double* standardDeviation);
#endif GPA_H