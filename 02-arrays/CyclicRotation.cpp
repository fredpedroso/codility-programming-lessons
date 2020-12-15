/*
  @file : CyclicRotation.cpp
  @class: CyclicRotation

  @brief:
	An array A consisting of N integers is given.
	Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place.
	For example, the rotation of array:
	A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

	The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

	Write a function:
	vector<int> solution(vector<int> &A, int K);

	That, given an array A consisting of N integers and an integer K, returns the array A rotated K times.
	For example, given
	    A = [3, 8, 9, 7, 6]
    	K = 3
 	The function should return [9, 7, 6, 3, 8]. Three rotations were made:
	    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    	[6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    	[7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

	For another example, given
	    A = [0, 0, 0]
    	K = 1
	The function should return [0, 0, 0]

	Given
	    A = [1, 2, 3, 4]
    	K = 4
	The function should return [1, 2, 3, 4]

	Assume that:
	- N and K are integers within the range [0..100];
	- Each element of array A is an integer within the range [−1,000..1,000].
	- In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

	Codility Result:
	https://app.codility.com/demo/results/training5GY63Q-3J8/ (62%)
	https://app.codility.com/demo/results/training4QPH2X-G2Y/ (100% Ronald)


 */

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

/*********************************************************
   Classes
 *********************************************************/
class Solution
{
public:
	vector<int> cyclicRotation(vector<int> &A, int K)
	{
		// Vector size
		int vectorSize = A.size();

		// Check assumptions
		if( (K == vectorSize) || (vectorSize == 0))
		{
			return A;
		}


		// Rotate vector
		rotate(rbegin(A), rbegin(A) + K, rend(A));

		return A;
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/
void printVector(std::vector<int> const &input)
{
	for (unsigned int i = 0; i < input.size(); i++)
	{
		cout << input.at(i) << ' ';
	}
}

int main(void)
{
	Solution     solution;
	vector<int>  vectValues;
	vector<int>  vectResult;

	// Testing ...
	vectValues = {3,8,9,7,6};
	vectResult = solution.cyclicRotation(vectValues, 3);

	printVector(vectResult);

	return 0;
}
