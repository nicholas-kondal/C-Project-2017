/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY: Nicholas Kondal, 520055322 */

#include "project.h"

/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */

/*
The Order() helper function supports Task 1 and assigns 3 positive integers (a, b and c)
to 3 variables representing ascending numerical order: smallest is the smallest of
the 3 integers, largest is the largest integer and middle is the remaining integer.

This function takes 6 inputs: a, b and c are 3 positive integers while *smallest, *middle
and *largest are pointer variables which store the address for that variable which is
present in the main function. Firstly, I used an if statement to compare each integer with 
the other 2 integers to see which one was the smallest. I assigned this integer to *smallest 
and used another if statement within the original if statement to compare the remaining 2 
integers to see which one was the smallest. I assigned the smallest of these two integers to 
*middle and the remaining integer to *largest.
*/
void Order(int a, int b, int c, int *smallest, int *middle, int *largest)
{
	if ((a < b) && (a < c)) {	
		*smallest = a;
		if (b < c) {
			*middle = b;
			*largest = c;
		} else {
			*middle = c;
			*largest = b;
		}
	} else if ((b < a) && (b < c)) {		
		*smallest = b;
		if (a < c) {
			*middle = a;
			*largest = c;
		} else {
			*middle = c;
			*largest = a;
		}
	} else {		
		*smallest = c;
		if (a < b) {
			*middle = a;
			*largest = b;
		} else {
			*middle = b;
			*largest = a;
		}
	}
}

/*
The TestForRun() helper function supports Task 6 and checks if all the data values are 
the same, in which case the best run is 0 and the starting index position of the best 
run is 0. 

This function takes 2 inputs: the array of data values and the number of data values.
The boolean variable isSame is set to 1, which indicates that there is no best run 
and/or that all the data values are equal. I used an if-else statement to check if the 
number of data values was less than or equal to 2, in which case, isSame would remain 1.
If there were more than 2 data values, then a for loop was used to compare each data value
in the array. If all data values were the same, isSame would remain unchanged and returned
to the DayTrader() function as 1. If even 1 of the data values was different to the others, 
then isSame would become 0 and returned.
*/
int TestForRun(int *prices, int numPrices)
{
	int isSame = 1;
	int i;

	if (numPrices <= 2) {
		isSame = 1;
	} else {
		for (i = 0; i < numPrices; i++) {
			if (prices[i] != prices[i-1]) {
				isSame = 0;
				break;
			}
		}
	}
	return isSame;
}

/*
The Consecutive() helper function supports Task 6 and calculates the best "run" for each
data value in the input array. 

This function takes 3 inputs: the current index position of the array, the array of data
values and the number of data values. I used a for loop to cycle through the data values 
to the right of the value represented by the index position and compared each data value 
with the previous one. If the current value was greater than the previous value, then a
counter was incremented, and the next value compared. If the current value was less than 
the previous value, then the boolean variable consecutive became 0 and the if statement 
comparing each value was ended. The counter, which represented the length of the run for 
the value at the index position, was returned.
*/
int Consecutive(int position, int *prices, int numPrices)
{
	int i;
	int consecutive = 1;
	int count = 0;
	
	for (i = position + 1; i < numPrices; i++) {
		if (consecutive && prices[i] > prices[i-1]) {
			count++;
		} else {
			consecutive = 0;
		}
	}
	return count;
}

/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/* Task 1:
The DivisorOfThree() function returns the greatest common divisor (GCD) of 3 integers i.e.
the largest positive integer that divides all 3 numbers without remainder. If any of the 
integers are less than or equal to 0, then -1 is returned.

This function takes 3 inputs (a, b and c) which are integers. Firstly, I used an if statement 
to check if any of the integers were less than or equal to 0, in which case -1 would be 
returned. If all 3 integers were positive, then using the Order() helper function, the 3 integers 
were assigned to variables representing ascending numerical order: smallest is the smallest of
the 3 integers, largest is the largest integer and middle is the remaining integer. Secondly,
I used a for loop to find all of the divisors of the smallest integer and store them in the
divisors array. Then, I used another for loop to cycle through the divisors array and check 
if a particular divisor of the smallest integer was also a divisor of the middle and largest 
integers. If so, then the variable gcd was updated to that divisor. When this loop finished, 
the number stored in gcd was the greatest common divisor and was returned.
*/
int DivisorOfThree(int a, int b, int c)
{
	int i;
	int gcd = -1;
	int divisorCount = 0;
	int smallest;
	int middle;
	int largest;
	int divisors[MAX_ARRAY_SIZE] = {0};

	if ((a <= 0) || (b <= 0) || (c <= 0)) {
		return gcd;
	} else {
		Order(a, b, c, &smallest, &middle, &largest);	
		for (i = 1; i <= smallest; i++) {
			if (smallest % i == 0) {
				divisors[divisorCount] = i;
				divisorCount++;
			}
		}					
		for (i = 0; i < divisorCount; i++) {	
			if ((middle % divisors[i] == 0) && (largest % divisors[i] == 0)) {
				gcd = divisors[i];
			}
		}
		return gcd;
	}
}

/* Task 2:
The AverageSheep() function calculates the average of all the integers in an array up to, but
excluding, the value 9999 (which indicates the end of the data sequence). Any values equal to
-1 are also ignored. If there are no valid values for calculating the average, then the function 
returns 0.0.

This function takes 1 input, *counts, which is a pointer to an array of integers. Firstly, 
I used a for loop to see if the integer at each index position was less than or equal to 0. 
If it was, then the value at that index position became 0. If the integer was equal to 9999, 
then the for loop was exited. Otherwise, the variable sum was incremented by the integer and 
a counter was incremented, indicating the number of valid values. After the for loop ran, I 
used an if statement to check if the sum was still 0, in which case, the counter was incremented 
to avoid dividing by 0. Finally, the average was returned, which was the sum of all the valid 
values in the array divided by the number of valid values.
*/
double AverageSheep(int *counts)
{
	int i = 0;
	int count = 0;
	double sum = 0;

	for (i = 0; i < MAX_ARRAY_SIZE; i++) {
		if (counts[i] < 0) {
			counts[i] = 0;
		} else if (counts[i] == 9999) {
			break;
		} else {
			sum = sum + counts[i];
			count++;
		}
	}

	if (sum == 0) {
		count++;
	}
	return sum/count;
}

/* Task 3:
The Emphasise() function modifies a string by converting all lowercase alphabetic characters
('a'-'z') between 2 underscore characters to uppercase. The underscore characters no longer
appear in the resulting string, which will be 2 characters shorter than the original string.

This function takes 1 input, word, which is a string. Firstly, I calculated the length of the 
input string using a while loop. Next, I used another while loop to travel along the string 
until the '_' character, which indicated the beginning of the characters to be capitalized. 
Upon incrementing the index position by 1, I used a third while loop to cycle through the 
characters within the 2 underscores and changed the previous character to the current character 
in order to remove the first underscore. If the character was a lowercase alphabetic character, 
then it was capitalized. Finally, I used an if-else statement to see if the current character 
was the second underscore and was located at the end of the string, in which case, the underscore 
would be changed to a null character. Otherwise, the index position is incremented and the 
characters after the second underscore are shifted back, thereby removing that underscore. 
The character at the end of the string, which is now 2 characters shorter than the original 
string, is changed to a null character. 
*/
void Emphasise(char* word)
{
	int i = 0;
	int length = 0;

	while (word[length] != '\0') {
		length++;
	}

	while (word[i] != '_') {
		i++;
	}
	i++;

	while(word[i] != '_') {
		word[i-1] = word[i];
		if (word[i-1] >= 'a' && word[i-1] <= 'z') {
			word[i-1] = word[i-1] - 32;
		}
		i++;
	}
		
	if (word[i] == word[length-1]) {
		word[length-2] = '\0';
	} else {
		i++;
		while (word[i] != '\0') {
			word[i-2] = word[i];
			i++;	
		}
		word[length-2] = '\0';
	}
}

/* Task 4:
The PrimeFactors() function computes the prime factors of a given integer and stores each
factor (in increasing order) in consecutive elements of an array. The number of factors is
returned.

This function take 2 inputs: n, which is an integer greater than or equal to 2 and *factors,
which is a pointer to the array where the prime factors will be stored. I initialized a 
while loop to execute any code which changed the value of n so long as n was greater than 1.
Inside the loop, I used a while loop to divide n by 2 and find the remainder. If the remainder 
was 0, then 2 was a prime factor and it was stored in the array. The value stored in n was 
divided and a counter was incremented, which represented the index position of the next factor 
and also the number of prime factors. When the remainder was no longer 0, n would be odd, so I 
used another for loop to cycle through each of the odd numbers from 3 to the current value of n. 
Next, I used another while loop to check if the remainder was 0 and if it was, the current 
odd number was stored in the array. The current value of n was also divided by this number 
and the counter was incremented. This is because every prime factor greater than 2 is odd 
and the consecutive nature of the first 3 odd primes ensured that all prime factors were 
found until n itself was a prime factor. The counter was returned.
*/
int PrimeFactors(int n, int *factors)
{
	int i;
	int numFactors = 0;

	while(n > 1) {
		while (n % 2 == 0) {
			factors[numFactors] = 2;
			n = n / 2;
			numFactors++;
		}
		for (i = 3; i <= n; i = i + 2) {			
			while (n % i == 0) {
				factors[numFactors] = i;
				n = n / i;
				numFactors++;
			}
		}
	}
	return numFactors;	
}

/* Task 5:
The ConnectTwo() function calculates the shortest path between 2 points on a grid. The 
starting location will be labelled '1' and the destination location will be labelled '2'.
The shortest path will initially follow a diagonal (if necessary) followed by a vertical
or horizontal path (if necessary). The input array dimensions are 10x10 and every element
is initialised to 0 except for the starting and ending locations (which will be initialised
to 1 and 2 respectively). Each element on the path is set to the value 3. The starting and
ending locations remain unchanged.

This function takes 2 input, a 2-dimensional array (10 rows and 10 columns) of integers 
which represents a map. Firstly, I used for loops to cycle through the array to find the 
row and column indices of the start and end locations. Next I used if statements so if the
row indices of the start and end locations were the same then the path went vertically down
and if the column indices of the start and end locations were the same then the path went 
horizontally across. Similarly, I used if statements to account for other situations where
the start and end locations could be: if the locations were at different row and column
indices to one another, then a path would travel diagonally until either the row index or
the column index of the current location was the same as the row index or the column index
of the end location, in which case it would travel horizontally or vertically to the end 
location.
*/
void ConnectTwo(int maze[10][10])
{
	int i;
	int j;
	int startx = 0;
	int starty = 0;
	int endx = 0;
	int endy = 0;
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (maze[i][j] == 1) {
				startx = i;
				starty = j;
			}
			if (maze[i][j] == 2) {
				endx = i;
				endy = j;
			}
		}
	}

	if (starty == endy) {
		if (startx < endx) {
			for (i = startx+1; i < endx; i++) {
				maze[i][starty] = 3;
			}
		}
		if (startx > endx) {
			for (i = startx-1; i > endx; i--) {
				maze[i][starty] = 3;
			}
		}
	}

	if (startx == endx) {
		if (starty < endy) {
			for (j = starty+1; j < endy; j++) {
				maze[startx][j] = 3;
			}
		}
		if (starty > endy) {
			for (j = starty-1; j > endy; j--) {
				maze[startx][j] = 3;
			}
		}
	}

	if (startx < endx && starty < endy) {
		if ((endx-startx) == (endy-starty)) {
			for (i = 1; i < (endx-startx); i++) {
				maze[startx+i][starty+i] = 3;
			}
		} else {
			while (startx != endx && starty != endy) {
				maze[startx+1][starty+1] = 3;
				startx++;
				starty++;		
			}
			if (starty == endy) {
				for (i = startx+1; i < endx; i++) {
					maze[i][starty] = 3;
				}
			}
			if (startx == endx) {
				for (j = starty+1; j < endy; j++) {
					maze[startx][j] = 3;
				}
			}
		}
	}

	if (startx > endx && starty > endy) {
		if ((startx-endx) == (starty-endy)) {
			for (i = 1; i < (startx-endx); i++) {
				maze[startx-i][starty-i] = 3;
			}
		} else {
			while (startx != endx && starty != endy) {
				maze[startx-1][starty-1] = 3;
				startx--;
				starty--;		
			}
			if (starty == endy) {
				for (i = startx-1; i > endx; i--) {
					maze[i][starty] = 3;
				}
			}
			if (startx == endx) {
				for (j = starty-1; j > endy; j--) {
					maze[startx][j] = 3;
				}
			}
		}
	}
	
	if (startx < endx && starty > endy) {
		if ((endx-startx) == (starty-endy)) {
			for (i = 1; i < (endx-startx); i++) {
				maze[startx+i][starty-i] = 3;
			}
		} else {
			while (startx != endx && starty != endy) {
				maze[startx+1][starty-1] = 3;
				startx++;
				starty--;		
			}
			if (starty == endy) {
				for (i = startx+1; i < endx; i++) {
					maze[i][starty] = 3;
				}
			}
			if (startx == endx) {
				for (j = starty-1; j > endy; j--) {
					maze[startx][j] = 3;
				}
			}
		}
	}
	
	if (startx > endx && starty < endy) {
		if ((startx-endx) == (endy-starty)) {
			for (i = 1; i < (startx-endx); i++) {
				maze[startx-i][starty+i] = 3;
			}
		} else {
			while (startx != endx && starty != endy) {
				maze[startx-1][starty+1] = 3;
				startx--;
				starty++;		
			}
			if (starty == endy) {
				for (i = startx-1; i > endx; i--) {
					maze[i][starty] = 3;
				}
			}
			if (startx == endx) {
				for (j = starty+1; j < endy; j++) {
					maze[startx][j] = 3;
				}
			}
		}	
	}
}

/* Task 6:
The DayTrader() function calculates where the longest "run" in an array of data begins and
the length of the longest "run". A run is defined at a sequence of strictly increasing data
values. The length and the index position of the longest "run" is returned. If there are 
2 or more "runs" of the same length, then the smallest index position (which indicates 
the left-most run) is returned.

This function takes 4 inputs: the array of data values, the number of data values and 2
integer pointers which store the length and index position of the best "run". Firstly, 
the TestForRun() function is used to see if all the data values are the same, in which case
the best run is 0 and the starting index position of the best run is 0. Otherwise, the best 
run for each data value is calculated using the Consecutive() function. I used an if statement
to keep track of the largest best run and its starting index position.
*/
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex)
{
	int i;
	int currentBestRun;
	*bestRun = 0;
	*bestRunIndex = 0;
	
	if (TestForRun(prices, numPrices) == 1) {
		*bestRun = 0;
		*bestRunIndex = 0;
	} else {
		for (i = 0; i < numPrices; i++) {
			currentBestRun = Consecutive(i, prices, numPrices);
			if (currentBestRun > *bestRun) {
				*bestRun = currentBestRun;
				*bestRunIndex = i;
			}
		}
	}
}

/* Task 7:
The Compress() function compresses an input array of positive integers by counting how 
many times a value is repeated consecutively. The end of the input data is indicated by
the integer -1. The number of repetitions of the value and the value itself are stored 
in an output array. The end of the output array is also indicated by the integer -1.

This function takes 2 inputs: an array of input data and an output array which is where
the compressed data will be stored. Firstly, I initialized a while loop to execute any 
operations so long as the value -1 was not reached. Inside this loop, I set the current 
value in the input array to the output array. I also used another while loop to increment 
a counter each time the current value in the input array was equal to the next value in 
the array. The counter was then stored in the output array to the left of the value which
was being counted. The counter was reset and the next value in the input array was counted.
Finally, I set the last value of the output array to -1.
*/
void Compress(int *input, int *output)
{
	int i = 0;
	int j = 0;
	int count;

	while (input[i] != -1) {
		count = 1;
		output[j+1] = input[i];
		while (input[i] == input[i+1]) {
			count++;
			i++;	
		}
		output[j] = count;
		j = j+2;
		i++;
	}
	output[j] = -1;	
}

/* Task 8:
The AddOne() function computes a string of positive integers where the characters in the 
new string are 1 larger than those in the original string. 

This function takes 2 inputs: an input string and a string in which to store the output. 
Firstly, I calculated the length of the input string using a while loop. Next, I checked to
see if the last character was not a 9, in which case, the last character was replaced with 
the next character represented in the ASCII code. If the last character was a 9, then it was
replaced with a 0. Next, I used a for loop to cycle through the remaining characters in the 
input string. If any character was a 9 and was next to a character that had been replaced 
with a 0, then this character was also replaced with a 0. Otherwise, the character was simply
replaced with the next character in the ASCII code and the loop was exited. I used another
for loop to check if all the characters were 0, in which case, the first character in the
input array was replaced with a 1, an additional 0 was added and the last character in the
array became the null character. Finally, I used a while loop to copy the characters from
the input array into the output array. 
*/
void AddOne(char *input, char *output)
{
	int length = 0;
	int allZeros = 1;
	int i;

	while (input[length] != '\0') {
		length++;
	}

	if (input[length-1] != '9') {
		input[length-1] = input[length-1] + 1;
	} else {
		input[length-1] = input[length-1] - 9;
		for (i = length-2; i >= 0; i--) {
			if (input[i] != '9') {
				input[i] = input[i] + 1;
				break;
			}
			input[i] = input[i] - 9;
		}
		for (i = 0; i < length; i++) {
			if (input[i] != '0') {
				allZeros = 0;
			}
		}
		if (allZeros) {
			input[0] = '1';
			input[length] = '0';
			input[length+1] = '\0';
		}
	}

	i = 0;
	while (input[i] != '\0') {
		output[i] = input[i];
		output[i+1] = '\0';
		i++;
	}		
}

/* Task 9:
The Histogram() function takes an array of integers representing the data to be plotted and
generates a string (representing the histogram) of 'X' and '*' characters, where each 'X'
is a datum point while the '*''s surround the bars of 'X''s as a border. Each line of text
in the string ends with a new line character ('\n') except for the last line and there is no
extra space characters anywhere at the beginning or end of a line.

This function takes 3 inputs: the string into which the resulting hsitogram is stored, the
array of integers to be plotted and the number of elements in the array. Firstly, I calculated
the largest integer in the array, which I used along with the number of values to calculate 
the index position of the end of the string. Next, using a series of for loops, I set all 
elements from 0 to the end of the string as ' ', created the top and bottom borders and 
also created the side borders. Next, I used some more for loops to put in the 'X''s by
cycling through the 'rows' of the string and checking to see if the index position at that
string was occupied by a number greater than 0 in the input array. If it was, then an 'X'
was put into that index position in the string and 1 was subtracted from the number in the
array. This occurred until the for loops reached the top of the array. Finally, the null 
character was placed at the end of the string.
*/
void Histogram(char *result, int *values, int numValues)
{
	int i;
	int j;
	int k;
	int biggestInteger = values[0];

	for (i = 1; i < numValues; i++) {
		if (values[i] > biggestInteger) {
			biggestInteger = values[i];
		}
	}

	int endOfString = 2*(numValues+2) + (numValues+3)*(biggestInteger);

	for (i = 0; i <= endOfString; i++) {
		result[i] = ' ';
	}

	for (i = 0; i <= numValues; i++) {
		result[i] = '*';
	}

	for (i = endOfString-numValues; i <= endOfString; i++) {
		result[i] = '*';
	}
	
	for (i = numValues+1; i < endOfString; i = i+(numValues+3)) {
		result[i] = '*';
		result[i+1] = '\n';
		result[i+2] = '*';
	}
	
	for (j = biggestInteger-1; j >= 0; j--) {
		for (k = 0; k < numValues; k++) {
			if (values[k] != 0) {
				result[(numValues+4)+j*(numValues+3) + k] = 'X';
				values[k]--;
			}
		}	
	}
	result[endOfString+1] = '\0';				
}

/* Task 10:
The GoldRush() function computes the total amount of gold and pure gold in a given map.
The map will have at least 2 rows and 2 columns, and will have no more than MAX_MAP_SIZE
rows and MAX_MAP_SIZE columns. The values in each cell of the map are digits between 0
and 9. 9 indicates the presence of gold. A cell contains pure gold if it contains gold
and if all 8 cells directly adjacent to it also contain gold.

This function takes 5 inputs: a 1-dimensional array of integers into which the results
computed are stored, 2 integers which indicate how many rows and columns are present on
the map, a 2-dimensional array of integers which contains the map data and an integer for
the bonus tasks. Firstly, I cycled through the map using for loops and used an if statement
to determine if the current cell contained a 9. If it did, then a counter was incremented.
Next, I used some more for loops to cycle through just the cells that were not on the border
and see if the cells which contained a 9 also had 9's surrounding them. If so, then another
counter was incremented. Finally, the values of the first and second counters were placed
in the first and second elements of the array of results, respectively.
*/
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus)
{
	int i;
	int j;
	//int k;
	//int l;
	int gold = 0;
	int pureGold = 0;

	if (bonus == 0) {
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				if (map[i][j] == 9) {
					gold++;
				}
			}
		}

		for (i = 1; i < rows-1; i++) {
			for (j = 1; j < cols-1; j++) {
				if (map[i][j] == 9) {
					if (map[i+1][j] == 9 && map[i][j+1] == 9 && map[i-1][j] == 9 && map[i][j-1] == 9 && map[i+1][j+1] == 9 && map[i+1][j-1] == 9 && map[i-1][j+1] == 9 && map[i-1][j-1] == 9) {
						pureGold++;
					}
				}
			}
		}
	
		results[0] = gold;
		results[1] = pureGold;
	}

	//if (bonus == 1) {
		//for (i = 0; i < rows; i++) {
			//for (j = 0; j < cols; j++) {
				//if (map[i][j] == 9) {
					//gold++;
					//k = i;
					//l = j;
					//map[k][l] = 0;
					//while (map[k+1][l] == 9 || map[k][l+1] == 9 || map[k-1][l] == 9 || map[k][l-1] == 9 || map[k+1][l+1] == 9 || map[k+1][l-1] == 9 || map[k-1][l+1] == 9 || map[k-1][l-1] == 9) {
						//if (map[k+1][l] == 9) {
							//gold++			
}