/*

  @file : missingInteger.cpp
  @class: missingInteger

  @brief:
	This is a demo task.

	Write a function:
	int solution(vector<int> &A);

	That, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
	For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

	Given A = [1, 2, 3], the function should return 4.
	Given A = [−1, −3], the function should return 1.

	Write an efficient algorithm for the following assumptions:
	- N is an integer within the range [1..100,000];
	- Each element of array A is an integer within the range [−1,000,000..1,000,000].

	Codility Result:
	https://app.codility.com/demo/results/trainingPYYZEB-YVM/ (First 55%)
	https://app.codility.com/demo/results/trainingK84GE9-MRN/ (Second 100% Ajuda do Leo Nascimento)

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
	int missingInteger(vector<int> &A)
	{
		// Vector sort
		sort(begin(A), end(A));

		int previousElement = 0;

		for (unsigned int i = 0; i < A.size(); i++)
		{
			if (A[i] > 0)
			{
				int diff = A[i] - previousElement;

				if (diff > 1)
				{
					return previousElement + 1;
				}

				previousElement = A[i];
			}
		}

		return previousElement > 0 ? previousElement + 1 : 1;
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
	vectValues = {1,3,6,4,1,2};
	cout << "{1,3,6,4,1,2} result is: " << solution.missingInteger(vectValues) << endl;

	vectValues = {-1,-3};
	cout << "{-1,-3}       result is: " << solution.missingInteger(vectValues) << endl;

	vectValues = {1,2,3};
	cout << "{1,2,3}       result is: " << solution.missingInteger(vectValues) << endl;

	vectValues = {2,3};
	cout << "{2,3}         result is: " << solution.missingInteger(vectValues) << endl;

	vectValues = {-2,3};
	cout << "{-2,3}        result is: " << solution.missingInteger(vectValues) << endl;

	return 0;
}
