/*

  @file : permMissingElement.cpp
  @class: permMissingElement

  @brief:
	An array A consisting of N different integers is given.
	The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

	Your goal is to find that missing element.

	Write a function: int solution(vector<int> &A);
	That, given an array A, returns the value of the missing element.

	For example, given array A such that:
		A[0] = 2
		A[1] = 3
		A[2] = 1
		A[3] = 5
  	The function should return 4, as it is the missing element.

	Write an efficient algorithm for the following assumptions:
	- N is an integer within the range [0..100,000];
	- The elements of A are all distinct;
	- Each element of array A is an integer within the range [1..(N + 1)].

	Codility Result:
	https://app.codility.com/demo/results/training9MAY88-TSQ/   (First  90%)
	https://app.codility.com/demo/results/training9YNAM4-BKJ/   (Second 100%)

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
	int permMissingElement(vector<int> &A)
	{

		// Size of Array
		int vectorSize = A.size();

		// Check assumptions
		if(vectorSize < 1)
		{
			return 1;
		}

		// Sort the vector
		sort(A.begin(), A.end());

		// First permutation element
		int currentPermElement = 1;

		for(int i = 0; i < vectorSize; i++)
		{
			if(A[i] != currentPermElement)
			{
				return currentPermElement;
			}

			currentPermElement++;
		}

		return currentPermElement;
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/
int main(void)
{
	Solution    sum;	// Instance
	vector<int> vect; 	// Vector

	// Vector example
	vect = {1,2,3,4,5,7};

	// Print the result
	cout << sum.permMissingElement(vect);

	// Vector example
	vect = {-1,2,3,4,5};

	// Print the result
	cout << sum.permMissingElement(vect);

	return 0;
}
