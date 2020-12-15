/*

  @file : PassingCars.cpp
  @class: PassingCars

  @brief:
	A non-empty array A consisting of N integers is given.
	The consecutive elements of array A represent consecutive cars on a road.

	Array A contains only 0s and/or 1s:
		0 represents a car traveling east,
		1 represents a car traveling west.

	The goal is to count passing cars.
	We say that a pair of cars (P, Q), where 0 <= P < Q < N,
	Is passing when P is traveling to the east and Q is traveling to the west.

	For example, consider array A such that:
		A[0] = 0
		A[1] = 1
		A[2] = 0
		A[3] = 1
		A[4] = 1
	We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).

	Write a function:
	int solution(vector<int> &A);

	That, given a non-empty array A of N integers, returns the number of pairs of passing cars.
	The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.

	For example, given:
		A[0] = 0
		A[1] = 1
		A[2] = 0
		A[3] = 1
		A[4] = 1
	The function should return 5, as explained above.

	Write an efficient algorithm for the following assumptions:
	- N is an integer within the range [1..100,000];
	- Each element of array A is an integer that can have one of the following values: 0, 1.

	Codility Result:
	https://app.codility.com/demo/results/trainingMW99AC-ADG/   (60%)


 */

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

/*********************************************************
   Class.
 *********************************************************/
class Solution
{
public:
	int passingCars(vector<int> &A)
	{
		// Array size  (N)
		unsigned int vectorSize = A.size();

		// Total cars passed
		unsigned int totalCarsPassed = 0;

		for (unsigned int i = 0; i < vectorSize; i++)
		{
			if (A[i] == 0)
			{
				for(unsigned int j = i; j < vectorSize; j++)
				{
					if (A[j] == 1)
					{
						totalCarsPassed++;
					}
				}
			}
		}

        if (totalCarsPassed > 1000000000)
        {
            return -1;
        }

		return totalCarsPassed;
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/
int main(void)
{
	Solution    solution;
	vector<int> vectValues;

	// Testing ..
	vectValues = {0,1,0,1,1};
	cout << "{0,1,0,1,1} result is: " << endl << solution.passingCars(vectValues) << endl;

	return 0;
}
