/*

  @file : distinctNumbers.cpp
  @class: distinctNumbers

  @brief:
	Write a function: int solution(vector<int> &A);
	That, given an array A consisting of N integers, returns the number of distinct values in array A.

	For example, given array A consisting of six elements such that:

	A[0] = 2    A[1] = 1    A[2] = 1
	A[3] = 2    A[4] = 3    A[5] = 1

	The function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

	Write an efficient algorithm for the following assumptions:
	- N is an integer within the range [0..100,000];
	- Each element of array A is an integer within the range [−1,000,000..1,000,000].

	Codility Result:
	https://app.codility.com/demo/results/trainingUUXQSY-BRV/

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
	int distinctNumbers(vector<int> &A)
	{
		int distinctValue = 1;
		int previousValue = 0;

		// Array size
		int arraySize = A.size();

		// Validations
		if(A.size() > 0)
		{
			previousValue = A[0];
		}
		else
		{
			return 0;
		}

		// Sort the vector
		sort(A.begin(), A.end());

		//
		for(int i = 1; i < arraySize; i++)
		{
			if(A[i] != previousValue)
			{
				previousValue = A[i];
				distinctValue++;
			}
		}

		return distinctValue;
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/

int main(void)
{
	Solution solution;
	vector<int> vect;

	// Vector example
	vect = {1,2,3,4,5,1,2,3,4};

	cout << solution.distinctNumbers(vect);;

	return 0;
}
