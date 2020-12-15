/*

  @file : countDiv.cpp
  @class: countDiv

  @brief:
	Write a function:
	int solution(int A, int B, int K);

	That, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
	{ i : A <= i <= B, i mod K = 0 }

	For example, for A = 6, B = 11 and K = 2, your function should return 3,
	because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

	Write an efficient algorithm for the following assumptions:
	- A and B are integers within the range [0..2,000,000,000];
	- K is an integer within the range [1..2,000,000,000];
	- A <= B.

	Codility Result:
	https://app.codility.com/demo/results/training6ECVXE-GSP/  (Total: 50% [Correctness = 100% and Performance = 0%])

 */

#include <iostream>     // std::cout

using namespace std;

/*********************************************************
   Class.
 *********************************************************/
class Solution
{
public:
	int countDiv(int A, int B, int K)
	{
		if ( (B < A) || (K <= 0))
		{
			return 0;
		}

		int countTotalDiv = 0;

		for(int i = A; i <= B; i++)
		{
			if(((i % K) == 0))
			{
				countTotalDiv++;
			}
		}

		return countTotalDiv;
	}

	int countDiv2(int A, int B, int K)
	{
		int qtde = 0;

		if ( (K > 0) && (B>=A) )
		{
			int diff = (B - A);
			if ( diff > 1 ) {
				qtde = (diff / K) + (bool)((diff % K) != 0);
			} else if ( (A>0) && (B>0) ) {
				qtde = ((A % K) == 0) + ((B % K) == 0);
			} else
				qtde = ((A==1) || (B==1));

		}

		return qtde;
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/
int main(void)
{
	Solution    solution;
	int 		A;
	int 		B;
	int 		K;

	// Testing ..
	A = 1;
	B = 1;
	K = 11;
	cout << "The result of (A = 1, B=1, K=11) is " << solution.countDiv(A,B,K) << endl;

	A = 6;
	B = 11;
	K = 2;
	cout << "The result of (A = 6, B=11, K=2) is " << solution.countDiv(A,B,K) << endl;

	A = 10;
	B = 11;
	K = 2;
	cout << "The result of (A = 10, B=11, K=2) is " << solution.countDiv(A,B,K) << endl;

	A = 0;
	B = 1;
	K = 11;
	cout << "The result of (A = 0, B=1, K=11) is " << solution.countDiv(A,B,K) << endl;

	A = 10;
	B = 10;
	K = 11;
	cout << "The result of (A = 10, B=10, K=11) is " << solution.countDiv(A,B,K) << endl;

	return 0;
}
