/*
  @file : Dominator.cpp
  @class: Dominator

  @brief:
	An array A consisting of N integers is given.
	The dominator of array A is the value that occurs in more than half of the elements of A.

	For example, consider array A such that
		A[0] = 3    A[1] = 4    A[2] =  3
 		A[3] = 2    A[4] = 3    A[5] = -1
 		A[6] = 3    A[7] = 3

	The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

	Write a function
		int solution(vector<int> &A);

	That, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs.
	The function should return −1 if array A does not have a dominator.

	For example, given array A such that
		A[0] = 3    A[1] = 4    A[2] =  3
 		A[3] = 2    A[4] = 3    A[5] = -1
 		A[6] = 3    A[7] = 3
	The function may return 0, 2, 4, 6 or 7, as explained above.

	Write an efficient algorithm for the following assumptions:
	- N is an integer within the range [0..100,000];
	- Each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

	Codility Result:
	https://app.codility.com/demo/results/training74EKX4-TD3/


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
	int dominator(vector<int> &A)
	{
		// Vector size
		unsigned int vectorSize = A.size();

		if(vectorSize == 0)
		{
			return -1;
		}

		vector<int> B = A;

		// Vector sort
		sort(begin(A), end(A));

		unsigned int dominatorValue       = 0;
		unsigned int dominatorOccurrences = 1;

		unsigned int tempDominatorValue       = 0;
		unsigned int tempDominatorOccurrences = 1;

		for (unsigned int i = 0; i < vectorSize; i++)
		{
			if(A[i] == A[i+1])
			{
				tempDominatorOccurrences++;
				tempDominatorValue = A[i];
			}
			else
			{
				if(tempDominatorOccurrences > dominatorOccurrences)
				{
					dominatorValue       = tempDominatorValue;
					dominatorOccurrences = tempDominatorOccurrences;
				}

				tempDominatorValue       = 0;
				tempDominatorOccurrences = 1;
			}
		}

		cout << "dominatorValue "       << dominatorValue       << endl;
		cout << "dominatorOccurrences " << dominatorOccurrences << endl;
		cout << "(vectorSize/2) + 1) "  << ((vectorSize/2) + 1) << endl;

		unsigned int middleValue = ((vectorSize/2));


		if(dominatorOccurrences > middleValue)
		{
			for(unsigned int i = 0; i < vectorSize; i++)
			{
				if(B[i] == dominatorValue)
				{
					return i;
				}
			}
		}
		else
		{
			return -1;
		}

		return 0;
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
	vectValues = {8,9,7,6,3,3,3,3,3,3,3};
	cout << solution.dominator(vectValues) << endl;

	vectValues = {3,4,3,2,3,-1,3,3};
	cout << solution.dominator(vectValues) << endl;

	return 0;
}


