/*
 * evaluate.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: sushil
 */

#include <evaluate.h>
#include <utils.h>
#include <const.h>

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

void evaluate(ga::Individual *ent){
//	cout << *ent << endl;
	double sum = 0;
	for(int i = 0; i < ent->length; i++){
		sum += ent->chrom[i];
	}
	ent->fit = sum;
	for(int i = 0; i < ga::MAX_CRITERIA; i++){
		ent->fitness[i] = sum;
	}

//	cout << "----------------------------------------" << endl;

}

void euclideanDistance(ga::Individual *ent, std::vector <float> latitude, std::vector <float> longitude){
	double sum = 0;
	double x, y;
		for (int i = 0; i < ent->length-1; i++){
			x = latitude [ent->chrom [i]] - latitude [ent->chrom [i+1]];
			y = longitude [ent->chrom [i]] - longitude [ent->chrom [i+1]];
			sum += sqrt (x*x+y*y);
		}
	 x = latitude [ent->chrom [ent->length-1]] - latitude [ent->chrom [0]];
	 y = longitude [ent->chrom [ent->length-1]] - longitude [ent->chrom [0]];
	 sum += sqrt (x*x+y*y);

		ent->fit = 1/sum;
		//std::cout << 1/sum << std::endl;
}

double decode(int * chrom, int start, int end){
  double prod = 0;
  for (int i = start; i < end; i++){
    prod += (chrom[i] == 0 ? 0 : pow(2.0, (double) i));
  }
  return prod;
}

void xSquared(ga::Individual *ent) {
  int value = decode(ent->chrom, 0, ent->length);
  ent->fit = value * value;
  return;

}
