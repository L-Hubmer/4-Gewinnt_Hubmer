/*
 * main.c
 *
 *  Created on: 20.10.2023
 *      Author: Hubmer.luk
 */

#include "Test4Win.h"

#include <stdio.h>

int TestForWins(int Field[SizeX][SizeY]);

int main(){
	int Field[SizeX][SizeY] =
	{
			{ 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0 ,0},
			{ 0, 0, 0, 0, 0, 0, 0},
	};
	int res = TestForWins(Field);

	printf("\n\n%i",res);

	return 1;
}

