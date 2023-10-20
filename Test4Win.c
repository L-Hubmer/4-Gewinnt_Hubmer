/*
 * Test4Win.c
 *
 *  Created on: 20.10.2023
 *      Author: L. Hubmer
 */

#define SizeX 7
#define SizeY 7
#define WinLength 4

#include "Test4Win.h"

int TestForWins(int Field[SizeX][SizeY]){
	int linesum = 0;
	int colsum = 0;
	int lqsum = 0;
	int rqsum = 0;
	int winner = 0;

	for(int Ytest = 0; Ytest < SizeY; Ytest++){
		for(int Xtest = 0; Xtest < SizeY; Xtest++){

			//Colsum
			if(Xtest + WinLength < SizeX){
				for(int xcnt = 0; xcnt < WinLength; xcnt++){
					colsum += Field[Xtest + xcnt][Ytest];
				}
			}

			//Linesum
			if(Ytest + WinLength < SizeY){
				for(int ycnt = 0; ycnt < WinLength; ycnt++){
					linesum += Field[Xtest][Ytest + ycnt];
				}
			}

			//rqsum
			if((Xtest + WinLength < SizeX) && (Ytest + WinLength < SizeY)){
				for(int xycnt = 0; xycnt < WinLength; xycnt++){
					rqsum += Field[Xtest + xycnt][Ytest + xycnt];
				}
			}

			//lqsum
			if((Xtest - WinLength >= -1) && (Ytest + WinLength < SizeY)){
				for(int xycnt = 0; xycnt < WinLength; xycnt++){
					lqsum += Field[Xtest - xycnt][Ytest + xycnt];
				}
			}


			//prove
			if((linesum >= WinLength) || (colsum >= WinLength) || (rqsum >= WinLength) || (lqsum >= WinLength)){
				winner = 1;
				goto EndOfLoops;
			}
			if((linesum <= (WinLength * -1)) || (colsum <= (WinLength * -1)) || (rqsum <= (WinLength * -1)) || (lqsum <= (WinLength * -1))){
				winner = -1;
				goto EndOfLoops;
			}
			linesum = 0;
			colsum = 0;
			rqsum = 0;
			lqsum = 0;

		}
	}
	return winner;
	EndOfLoops:
	return winner;
}


