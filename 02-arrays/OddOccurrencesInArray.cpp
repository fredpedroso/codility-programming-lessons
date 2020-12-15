/*
	A non-empty array A consisting of N integers is given.
	The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value,
	except for one element that is left unpaired.

	For example, in array A such that:
		A[0] = 9  A[1] = 3  A[2] = 9
		A[3] = 3  A[4] = 9  A[5] = 7
		A[6] = 9

	- The elements at indexes 0 and 2 have value 9;
	- The elements at indexes 1 and 3 have value 3;
	- The elements at indexes 4 and 6 have value 9;
	- The element at index 5 has value 7 and is unpaired.

	Write a function:
	int solution(vector<int> &A);

	That, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

	For example, given array A such that:
		A[0] = 9  A[1] = 3  A[2] = 9
		A[3] = 3  A[4] = 9  A[5] = 7
		A[6] = 9
	The function should return 7, as explained in the example above.

	Write an efficient algorithm for the following assumptions:
	- N is an odd integer within the range [1..1,000,000];
	- Each element of array A is an integer within the range [1..1,000,000,000];
	- All but one of the values in A occur an even number of times.

	Codility result:
	https://app.codility.com/demo/results/trainingX9PAB9-7EV/

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
	int oddOccurrencesInArray(vector<int> &A)
	{
		// Vector sort
		sort(begin(A), end(A));

		// Vector size
		unsigned int vectorSize = A.size();

		// Check assumptions
		if(vectorSize == 1)
		{
			return A[0];
		}

		for(unsigned int i = 0; i < (vectorSize - 1); i = i+2)
		{
			if(A[i] != A[i+1])
			{
				return A[i];
			}
		}

		return A[vectorSize - 1];
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/
int main(void)
{
	Solution     solution;
	vector<int>  vectValues;

	// Testing ...
	vectValues = {9,3,9,3,9,7,9};
	cout << "Result of {9,3,9,3,9,7,9} is " << endl << solution.oddOccurrencesInArray(vectValues) << endl;

	return 0;
}
