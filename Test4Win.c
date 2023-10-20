/*
 * Test4Win.c
 *
 *  Created on: 20.10.2023
 *      Author: L. Hubmer
 */

#define SizeX 7
#define SizeY 7
#define WinLength 4

#include <stdio.h>
#include "Test4Win.h"

int TestForWins(int Field[SizeX][SizeY]){
	int linesum = 0;
	int colsum = 0;
	int lqsum = 0;
	int rqsum = 0;
	int winner = 0;

	for(int Ytest = 0; Ytest < SizeY; Ytest++){
		printf("\nYtest: %i",Ytest);
		for(int Xtest = 0; Xtest < SizeY; Xtest++){
			printf("\n\tXtest: %i",Xtest);

			//Colsum
			if(Xtest + WinLength < SizeX){
				printf("\tColsum:");
				for(int xcnt = 0; xcnt < WinLength; xcnt++){
					colsum += Field[Xtest + xcnt][Ytest];
					printf("\txy: %i/%i",Xtest + xcnt,Ytest);
				}
				printf(" = %i",colsum);
			}

			//Linesum
			if(Ytest + WinLength < SizeY){
				printf("\tLinesum:    ");
				for(int ycnt = 0; ycnt < WinLength; ycnt++){
					linesum += Field[Xtest][Ytest + ycnt];
					printf("\txy: %i/%i",Xtest,Ytest+ycnt);
				}
				printf(" = %i",linesum);
			}

			//rqsum
			if((Xtest + WinLength < SizeX) && (Ytest + WinLength < SizeY)){
				printf("\t\trqsum:");
				for(int xycnt = 0; xycnt < WinLength; xycnt++){
					rqsum += Field[Xtest + xycnt][Ytest + xycnt];
					printf("\txy: %i/%i",Xtest + xycnt,Ytest+xycnt);
				}
				printf(" = %i",rqsum);
			}

			//lqsum
			if((Xtest - WinLength >= -1) && (Ytest + WinLength < SizeY)){
				printf("\tlqsum:      ");
				for(int xycnt = 0; xycnt < WinLength; xycnt++){
					lqsum += Field[Xtest - xycnt][Ytest + xycnt];
					printf("\txy: %i/%i",Xtest - xycnt,Ytest+xycnt);
					printf(" = _%i_",Field[Xtest - xycnt][Ytest + xycnt]);
				}
				printf(" = %i",lqsum);
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


