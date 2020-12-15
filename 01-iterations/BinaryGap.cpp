/*
  @file : BinaryGap.cpp
  @class: BinaryGap

  @brief:
	A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

	For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
	- The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
	- The number 20 has binary representation 10100 and contains one binary gap of length 1.
	- The number 15 has binary representation 1111 and has no binary gaps.
	- The number 32 has binary representation 100000 and has no binary gaps.

	Write a function:
	int solution(int N);

	That, given a positive integer N, returns the length of its longest binary gap.
	The function should return 0 if N doesn't contain a binary gap.

	For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.
	Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

	Write an efficient algorithm for the following assumptions:
	- N is an integer within the range [1..2,147,483,647].

	Codility Result:
	https://app.codility.com/demo/results/trainingDBP9EZ-X97/ (100%)


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

	vector<int> int2Binary(int N)
	{
		vector<int> binaryValues;

		for(unsigned i = 0; N > 0; i++)
		{
			binaryValues.push_back(N % 2);
			N = (N/2);
		}

		return binaryValues;
	}

	int binaryGap(int N)
	{

		// Converting Int to Binary (vector<int>)
		vector<int> binaryValues;
		binaryValues = int2Binary(N);

		int  maxBinaryGap  = 0;
		int  tempBinaryGap = 0;

		for (unsigned int i = 0; i < binaryValues.size(); i++)
		{
			if(binaryValues[i] == 1)
			{
				for(unsigned int j = i+1; j < binaryValues.size(); j++)
				{
					if (binaryValues[j] == 0)
					{
						tempBinaryGap++;
					}
					else
					{
						if (tempBinaryGap > maxBinaryGap)
						{
							maxBinaryGap = tempBinaryGap;
						}

						tempBinaryGap = 0;
						break;
					}
				}
			}
		}

		return maxBinaryGap;
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/
int main(void)
{
	Solution   solution;
	int        binaryValue;

	// Testing ...
	binaryValue = 9;
	cout << "BinaryGap of " << binaryValue << " is " << solution.binaryGap(binaryValue) << endl;

	binaryValue = 529;
	cout << "BinaryGap of " << binaryValue << " is " << solution.binaryGap(binaryValue) << endl;

	binaryValue = 15;
	cout << "BinaryGap of " << binaryValue << " is " << solution.binaryGap(binaryValue) << endl;

	binaryValue = 20;
	cout << "BinaryGap of " << binaryValue << " is " << solution.binaryGap(binaryValue) << endl;

	binaryValue = 32;
	cout << "BinaryGap of " << binaryValue << " is " << solution.binaryGap(binaryValue) << endl;
	return 0;
}
