#ifndef RandomNumberGeneratorH 
#define RandomNumberGeneratorH 

#include <stdlib.h>	// for srand and rand routines
#include <cassert>	// for assert
#include <ctime>	// for time used in RandomNumberGenerator::seed routines
using namespace std;

class RandomNumberGenerator
{
	public:
		// constructors
		RandomNumberGenerator();

		// assessors
		static int get_random_value(int);

	private:
		// supporting functions
		static void seed();
};

#endif