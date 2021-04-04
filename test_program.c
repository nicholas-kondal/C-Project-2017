/* ENGGEN131, Semester Two, 2017 */
/* The header file for Project Two */
/* Prepared by Paul Denny, October 2017 */

#include "project.h"

/* YOU WILL NOT BE SUBMITTING THIS FILE FOR MARKING */
/* You are encouraged to add additional tests to the testing functions */
/* defined in this program.  There are ten test functions, one for each */
/* of the functions you are required to define for this project */
void Test_DivisorOfThree(void);
void Test_AverageSheep(void);
void Test_Emphasise(void);
void Test_PrimeFactors(void);
void Test_ConnectTwo(void);
void Test_DayTrader(void);
void Test_Compress(void);
void Test_AddOne(void);
void Test_Histogram(void);
void Test_GoldRush(void);

/* You do not need to modify the main() function - it simply calls each of */
/* the test functions */
int main(void)
{
	// Print welcome message
	printf("\nENGGEN131 Project - Semester Two - 2017\n\n");
	printf("\nWelcome to the minimal test program for Project Two.\n\n");
	printf("This  test  program  provides  an  absolute minimal set of  test  cases\n");
	printf("that you can use to automatically test the functions you  have  defined\n");
	printf("for the project. Failing any of these tests is an indication that there\n");
	printf("is an error in your implementation.  However, because this is a minimal\n");
	printf("set of tests,  passing all of them is no guarantee that your  functions\n");
	printf("are  defined  correctly.   It  is  up  to  you  to  test your code more\n");
	printf("thoroughly, but hopefully this template will be a useful guide for you.\n\n");
	printf("Good luck!\n");

	// Minimal testing of each function
	Test_DivisorOfThree();
	Test_AverageSheep();
	Test_Emphasise();
	Test_PrimeFactors();
	Test_ConnectTwo();
	Test_DayTrader();
	Test_Compress();
	Test_AddOne();
	Test_Histogram();
	Test_GoldRush();

	return 0;
}

/* A function to test Task One */
void Test_DivisorOfThree(void)
{
	if (DivisorOfThree(1, 1, 2) == 99999) {
		printf("\nTask One:   DivisorOfThree() - not yet implemented");
	} else {
		printf("\nTask One:   DivisorOfThree() - ");
		if (DivisorOfThree(1288, 759, 1173) != 23) {
			printf("FAIL (1288, 759, 1173) ");
		} else {
			printf("PASS ");
		}
		if (DivisorOfThree(760, 1960, 2720) != 40) {
			printf("FAIL (760, 1960, 2720) ");
		} else {
			printf("PASS ");
		}
		if (DivisorOfThree(100, 0, 1000000) != -1) {
			printf("FAIL (100, 0, 1000000) ");
		} else {
			printf("PASS ");
		}
	}
}

/* A function to test Task Two */
void Test_AverageSheep(void)
{
	int sheep1[MAX_ARRAY_SIZE] = {0, 12, 18, 19, 9999};
	int sheep2[MAX_ARRAY_SIZE] = {-1, 25, 12, 18, -1, 9999};
	int sheep3[MAX_ARRAY_SIZE] = {-1, 22, 9999, -1, 25, 12};
	int sheep4[MAX_ARRAY_SIZE] = {-1, -1, 9999, -1, 25, 12};

	if (AverageSheep(sheep1) == 99999.9) {
		printf("\nTask Two:   AverageSheep()   - not yet implemented");
	} else {
		printf("\nTask Two:   AverageSheep()   - ");
		if ((AverageSheep(sheep2) < 18.333332) || (AverageSheep(sheep2) > 18.333334)) {
			printf("FAIL (sheep2) ");
		} else {
			printf("PASS ");
		}
		if ((AverageSheep(sheep3) < 21.999999) || (AverageSheep(sheep3) > 22.000001)) {
			printf("FAIL (sheep3) ");
		} else {
			printf("PASS ");
		}
		if ((AverageSheep(sheep4) < -0.000001) || (AverageSheep(sheep4) > 0.000001)) {
			printf("FAIL (sheep4) ");
		} else {
			printf("PASS ");
		}
	}
}

/* A function to test Task Three */
void Test_Emphasise(void)
{
	char words0[MAX_ARRAY_SIZE] = "not _implemented_";
	char wordsA[MAX_ARRAY_SIZE] = "this is a _good_ question!";
	char wordsB[MAX_ARRAY_SIZE] = "It is _over 9000_!";
	char wordsC[MAX_ARRAY_SIZE] = "_Nothing to see here_";

	Emphasise(words0);
	if (words0[0] == '~') {
		printf("\nTask Three: Emphasise()      - not yet implemented");
	} else {
		printf("\nTask Three: Emphasise()      - ");
		Emphasise(wordsA);
		if (strcmp(wordsA, "this is a GOOD question!")) {
			printf("FAIL (wordsA) ");
		} else {
			printf("PASS ");
		}
		Emphasise(wordsB);
		if (strcmp(wordsB, "It is OVER 9000!")) {
			printf("FAIL (wordsB) ");
		} else {
			printf("PASS ");
		}
		Emphasise(wordsC);
		if (strcmp(wordsC, "NOTHING TO SEE HERE")) {
			printf("FAIL (wordsC) ");
		} else {
			printf("PASS ");
		}
	}
}

/* A function to test Task Four */
void Test_PrimeFactors(void)
{
	int numFactors;
	int factors[MAX_ARRAY_SIZE];

	numFactors = PrimeFactors(2, factors);
	if (numFactors == 99999) {
		printf("\nTask Four:  PrimeFactors()   - not yet implemented");
	} else {
		printf("\nTask Four:  PrimeFactors()   - ");
		numFactors = PrimeFactors(567, factors);
		if (numFactors != 5 || (factors[0] * factors[1] * factors[2] * factors[3] * factors[4] != 567)) {
			printf("FAIL (567) ");
		} else {
			printf("PASS ");
		}
		numFactors = PrimeFactors(5678901, factors);
		if (numFactors != 4 || (factors[0] * factors[1] * factors[2] * factors[3] != 5678901)) {
			printf("FAIL (5678901) ");
		} else {
			printf("PASS ");
		}
		numFactors = PrimeFactors(13, factors);
		if (numFactors != 1 || (factors[0] != 13)) {
			printf("FAIL (13) ");
		} else {
			printf("PASS ");
		}
	}
}

/* A function to test Task Five */
void Test_ConnectTwo(void)
{
	int map0[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 2, 0, 0, 0, 0, 0, 0}};
	int map1[10][10] = {{1, 0, 2, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int map2[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{2, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int map3[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 2, 0, 0}};

	ConnectTwo(map0);
	if (map0[0][0] == 99999) {
		printf("\nTask Five:  ConnectTwo()     - not yet implemented");
	} else {
		printf("\nTask Five:  ConnectTwo()     - ");
		ConnectTwo(map1);
		if (map1[0][1] != 3) {
			printf("FAIL (map1) ");
		} else {
			printf("PASS ");
		}
		ConnectTwo(map2);
		if ((map2[1][0] != 3) || (map2[2][0] != 3)) {
			printf("FAIL (map2) ");
		} else {
			printf("PASS ");
		}
		ConnectTwo(map3);
		if ((map3[1][1] != 3) || (map3[2][2] != 3) || (map3[3][3] != 3) || (map3[4][4] != 3) || (map3[5][5] != 3) || (map3[6][6] != 3) || (map3[7][7] != 3) || (map3[8][7] != 3)) {
			printf("FAIL (map3) ");
		} else {
			printf("PASS ");
		}
	}
}

/* A function to test Task Six */
void Test_DayTrader(void)
{
	int prices0[5] = {0, 2, 3, 4, 5};
	int pricesA[15] = {59, 60, 55, 23, 42, 44, 48, 50, 43, 45, 43, 44, 47, 51, 52};
	int pricesB[10] = {1, 2, 3, 3, 3, 4, 3, 4, 5, 6};
	int pricesC[10] = {123, 120, 118, 119, 121, 126, 127, 130, 129, 132};
	int bestRun, bestRunIndex;

	DayTrader(prices0, 5, &bestRun, &bestRunIndex);
	if (bestRun == 99999) {
		printf("\nTask Six:   DayTrader()      - not yet implemented");
	} else {
		printf("\nTask Six:   DayTrader()      - ");
		DayTrader(pricesA, 15, &bestRun, &bestRunIndex);
		if (bestRun != 4 || bestRunIndex != 3) {
			printf("FAIL (pricesA) ");
		} else {
			printf("PASS ");
		}
		DayTrader(pricesB, 10, &bestRun, &bestRunIndex);
		if (bestRun != 3 || bestRunIndex != 6) {
			printf("FAIL (pricesB) ");
		} else {
			printf("PASS ");
		}
		DayTrader(pricesC, 10, &bestRun, &bestRunIndex);
		if (bestRun != 5 || bestRunIndex != 2) {
			printf("FAIL (pricesC) ");
		} else {
			printf("PASS ");
		}

	}
}

/* A function to test Task Seven */
void Test_Compress(void)
{
	int inputA[MAX_ARRAY_SIZE] = {0,1,2,2,-1};
	int inputB[MAX_ARRAY_SIZE] = {1,1,2,2,-1};
	int inputC[MAX_ARRAY_SIZE] = {7,7,7,7,7,7,7,7,7,7,-1};
	int inputD[MAX_ARRAY_SIZE] = {4,7,7,7,-1};
	int output[MAX_ARRAY_SIZE];

	Compress(inputA, output);
	if (output[0] == 99999) {
		printf("\nTask Seven: Compress()       - not yet implemented");
	} else {
		printf("\nTask Seven: Compress()       - ");
		Compress(inputB, output);
		if (output[0] != 2 || output[1] != 1 || output[2] != 2 || output[3] != 2 || output[4] != -1) {
			printf("FAIL (inputB) ");
		} else {
			printf("PASS ");
		}
		Compress(inputC, output);
		if (output[0] != 10 || output[1] != 7 || output[2] != -1) {
			printf("FAIL (inputC) ");
		} else {
			printf("PASS ");
		}
		Compress(inputD, output);
		if (output[0] != 1 || output[1] != 4 || output[2] != 3 || output[3] != 7 || output[4] != -1) {
			printf("FAIL (inputD) ");
		} else {
			printf("PASS ");
		}

	}
}

/* A function to test Task Eight */
void Test_AddOne(void)
{
	char words0[MAX_ARRAY_SIZE] = "123";
	char wordsA[MAX_ARRAY_SIZE] = "99999";
	char wordsB[MAX_ARRAY_SIZE] = "12399999999";
	char wordsC[MAX_ARRAY_SIZE] = "9";
	char output[MAX_ARRAY_SIZE];

	AddOne(words0, output);
	if (output[0] == '~') {
		printf("\nTask Eight: AddOne()         - not yet implemented");
	} else {
		printf("\nTask Eight: AddOne()         - ");
		AddOne(wordsA, output);
		if (strcmp(output, "100000")) {
			printf("FAIL (wordsA) ");
		} else {
			printf("PASS ");
		}
		AddOne(wordsB, output);
		if (strcmp(output, "12400000000")) {
			printf("FAIL (wordsB) ");
		} else {
			printf("PASS ");
		}
		AddOne(wordsC, output);
		if (strcmp(output, "10")) {
			printf("FAIL (wordsC) ");
		} else {
			printf("PASS ");
		}
	}
}

/* A function to test Task Nine */
void Test_Histogram(void)
{
	int values0[3] = {0, 0, 1};
	int values1[10] = {1, 0, 3, 1, 2, 4, 5, 6, 2, 2};
	int values2[3] = {1, 0, 1};
	int values3[3] = {0, 1, 0};

	char formatted[MAX_ARRAY_SIZE];

	Histogram(formatted, values0, 0);
	if (formatted[0] == '~') {
		printf("\nTask Nine:  Histogram()      - not yet implemented");
	} else {
		printf("\nTask Nine:  Histogram()      - ");
		Histogram(formatted, values1, 10);
		if (strcmp(formatted, "************\n*       X  *\n*      XX  *\n*     XXX  *\n*  X  XXX  *\n*  X XXXXXX*\n*X XXXXXXXX*\n************")) {
			printf("FAIL (values1) ");
		} else {
			printf("PASS ");
		}
		Histogram(formatted, values2, 3);
		if (strcmp(formatted, "*****\n*X X*\n*****")) {
			printf("FAIL (values2) ");
		} else {
			printf("PASS ");
		}
		Histogram(formatted, values3, 3);
		if (strcmp(formatted, "*****\n* X *\n*****")) {
			printf("FAIL (values3) ");
		} else {
			printf("PASS ");
		}
	}
}

/* A function to test Task Ten */
void Test_GoldRush(void)
{

	int results[MAX_ARRAY_SIZE];
	int map0[MAX_MAP_SIZE][MAX_MAP_SIZE] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	int map1[MAX_MAP_SIZE][MAX_MAP_SIZE] = {
			{1,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,4,3,0,0,0,0,9,9,8,0,0,0,0,0},
			{0,2,0,3,3,0,0,9,9,0,0,0,0,0,0},
			{0,0,0,0,0,4,6,9,9,6,0,0,0,0,0},
			{0,0,0,0,0,0,9,0,8,0,0,6,0,0,0},
			{0,0,9,9,9,9,0,0,0,0,7,7,8,8,0},
			{0,0,9,9,9,9,0,0,0,0,0,7,0,0,0},
			{0,0,9,9,9,9,0,1,1,1,2,2,2,2,2},
			{0,0,0,9,9,0,0,0,0,0,0,0,0,3,0},
			{0,0,0,4,4,0,0,0,0,0,0,0,5,6,0},
			{0,0,0,0,9,9,9,0,0,9,0,0,0,5,0},
			{0,0,1,2,9,9,9,0,0,0,9,0,0,4,2},
			{0,0,0,0,9,9,9,0,0,0,9,9,9,0,0},
			{9,9,0,0,0,0,1,0,0,0,0,9,0,0,0},
			{9,0,0,0,0,0,2,2,0,0,0,0,0,0,0}
		};
	int map2[MAX_MAP_SIZE][MAX_MAP_SIZE] = { {9, 9, 9}, {9, 9, 9}, {9, 9, 9} };
	int map3[MAX_MAP_SIZE][MAX_MAP_SIZE] = { {9, 9, 9}, {9, 9, 9}, {9, 9, 8} };

	GoldRush(results, 3, 3, map0, 0);
	if (results[0] == 99999) {
		printf("\nTask Ten:   GoldRush()       - not yet implemented");
	} else {
		printf("\nTask Ten:   GoldRush()       - ");
		GoldRush(results, 15, 15, map1, 0);
		if (results[0] != 39 || results[1] != 3) {
			printf("FAIL (map1) ");
		} else {
			printf("PASS ");
		}
		GoldRush(results, 3, 3, map2, 0);
		if (results[0] != 9 || results[1] != 1) {
			printf("FAIL (map2) ");
		} else {
			printf("PASS ");
		}
		GoldRush(results, 3, 3, map3, 0);
		if (results[0] != 8 || results[1] != 0) {
			printf("FAIL (map3) ");
		} else {
			printf("PASS ");
		}
	}
}
