/* ENGGEN131, Semester Two, 2017 */
/* The header file for Project Two */
/* Prepared by Paul Denny, October 2017 */

/* You are NOT permitted to make ANY changes to this header file */
/* Your project will be marked by an automated program that will use */
/* this header file in exactly this form */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/* Any arrays that are passed as inputs to functions (for Tasks 1-9) are guaranteed to */
/* be no larger than the MAX_ARRAY_SIZE constant */
#define MAX_ARRAY_SIZE 1000

/* For Task 10, the MAX_MAP_SIZE constant specifies the maximum number of rows or columns */
/* that will be used for a map */
#define MAX_MAP_SIZE 100

/* The required functions for the project */
int DivisorOfThree(int a, int b, int c);
double AverageSheep(int *counts);
void Emphasise(char* word);
int PrimeFactors(int n, int *factors);
void ConnectTwo(int maze[10][10]);
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex);
void Compress(int *input, int *output);
void AddOne(char *input, char *output);
void Histogram(char *result, int *values, int numValues);
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus);

