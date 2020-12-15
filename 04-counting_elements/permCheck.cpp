/*

  @file : permCheck.cpp
  @class: permCheck

  @brief:
	A non-empty array A consisting of N integers is given.

	A permutation is a sequence containing each element from 1 to N once, and only once.
	For example, array A such that:
		A[0] = 4
		A[1] = 1
		A[2] = 3
		A[3] = 2
	Is a permutation, but array A such that:
		A[0] = 4
		A[1] = 1
		A[2] = 3
	Is not a permutation, because value 2 is missing.

	The goal is to check whether array A is a permutation.

	Write a function: int solution(vector<int> &A);
	That, given an array A, returns 1 if array A is a permutation and 0 if it is not.

	For example, given array A such that:
		A[0] = 4
		A[1] = 1
		A[2] = 3
		A[3] = 2
	The function should return 1.

	Given array A such that:
		A[0] = 4
		A[1] = 1
		A[2] = 3
	The function should return 0.

	Write an efficient algorithm for the following assumptions:
	- N is an integer within the range [1..100,000];
	- Each element of array A is an integer within the range [1..1,000,000,000].

	Codility Result:
	https://app.codility.com/demo/results/trainingGQXMGF-ASG/

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
	int permCheck(vector<int> &A)
	{
		// Array size
		int vectorSize = A.size();

		// Check assumptions
		if(vectorSize < 1)
		{
			return 0;
		}

		// Vector sort
		sort(A.begin(), A.end());

		// Init element (from 1 to N)
		int currentPermElement = 1;

		// Permutation check
		for(int i = 0; i < vectorSize; i++)
		{
			if(A[i] != currentPermElement)
			{
				return 0;
			}

			currentPermElement++;
		}

		return 1;
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
	vectValues = {1,2,3,4,5,6,7};
	cout << "{1,2,3,4,5,6,7} result is: " << ((solution.permCheck(vectValues) == 1) ? "Is Permutation" : "Is not a Permutation") << endl;

	vectValues = {4,1,3,2};
	cout << "{4,1,3,2}       result is: " << ((solution.permCheck(vectValues) == 1) ? "Is Permutation" : "Is not a Permutation") << endl;

	vectValues = {4,1,3};
	cout << "{4,1,3}         result is: " << ((solution.permCheck(vectValues) == 1) ? "Is Permutation" : "Is not a Permutation") << endl;

	return 0;
}
