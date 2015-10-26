#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef __5_8_H__
#define __5_8_H__

#define WIDTH 32   // means we need to use 4 bytes to store the width
#define HEIGHT 16

// Create a one dimensional char array and set all bytes to 0s.
// The screen is 16 * 32. 16 is the height, and 32 is the width.
// @param 	int 	WIDTH
// @param 	int 	HEIGHT
// @return 	char* arr
char* createCharArr(int w, int h);

// Given (x, y), calculate index1 which is the index in the char array
// @param	int 	x
// @param 	int 	y
// @return 	int 	index
int getIndex(int x, int y);

// check if X1 and X2 are in the same byte
// @param	int 	x1 
// @param 	int 	x2 
// @return 	bool 	true means that X1 and X2 are in the same byte
bool isSameByte(int x1, int x2);

// set bytes to 0xFF
// @param 	char* 	arr
// @param 	int 	index1
// @param 	int 	index2
// @return 	void
void setBytesBright(char* arr, int index1, int index2);

// if X1 and X2 are in the same line, set x1 to x2 to 1
// @param 	char* 	arr
// @param 	int 	x1
// @param 	int 	x2
// @return 	void
void setWithinByte(char* arr, int x1, int x2);

// set from the starting position to the end of belonging byte to 1 
// @param 	char* 	arr
// @param	int 	x1
// @return 	void
void setStart(char* arr, int x1);

// set from the last full byte to x2 to 1
// @param 	char* 	arr
// @param 	int 	x2
// @return 	void
void setEnd(char* arr, int x2);

// draw horizontal Line
// @param	char*	arr
// @param 	int 	x1
// @param	int		x2
// @prarm	int 	y
void drawHorizontalLine(char* arr, int x1, int x2, int y);

// print the monochrome screen on the terminal screen in hexidemical format
// @param 	char* 	arr
// @return 	void
void printScreen(char* arr);

//	Get a bit from a char
//	@param 	char 			a 
//	@param	int 			bitIndex
// 	@return unsigned int 	bitValue
unsigned int getBit(char a, int bitIndex);

// 	printf one char in bits
// 	@param	char a
// 	@return void
void printAChar(char a);

// print the monochrome screen on the terminal screen in bits
// @param 	char* 	arr
// @return 	void
void printScreenInBits(char* arr);

#endif



