/*
 * main.c
 *
 *  Created on: 20.10.2023
 *      Author: Hubmer.luk
 */

#define SizeX 7
#define SizeY 7
#define WinLength 4

#include <stdio.h>

int TestForWins(int Field[SizeX][SizeY]);

int main(){
	int Field[SizeX][SizeY] =
	{
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
	};
}

int TestForWins(int Field[SizeX][SizeY]){
	int linesum = 0;
	int colsum = 0;
	int lqusum = 0;
	int rqsum = 0;

	for(int Ytest = 0; Ytest < SizeY; Ytest++){
		for(int Xtest = 0; Xtest < SizeY; Xtest++){
			if(Xtest + WinLength < SizeX){
				for(int xcnt; xcnt <= WinLength; xcnt++){
					linesum += Field[xcnt][Ytest];
				}
			}
			if(Ytest + WinLength < SizeY){
				for(int ycnt; ycnt <= WinLength; ycnt++){
					colsum += Field[Xtest][ycnt];
				}
			}
			if((Xtest + WinLength < SizeX) && (Ytest + WinLength < SizeY)){
				for(int xycnt; xycnt <= Winlength; xycnt++){
					colsum += Field[xycnt][xycnt];
				}
			}
		}
	}
}

