#ifndef _RAMDOM_CPP_
#define _RANDOM_CPP_
#include <cstdlib>

static int GetRandom(int l,int r){
	int *seed = new int;
	srand(*seed);
	int res=rand()%(r-l);
	return l+res;
}
#endif