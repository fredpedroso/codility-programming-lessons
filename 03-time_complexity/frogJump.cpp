/*
  @file : frogJump.cpp
  @class: frogJump

  @brief:
	A small frog wants to get to the other side of the road.
	The frog is currently located at position X and wants to get to a position greater than or equal to Y.
	The small frog always jumps a fixed distance, D.

	Count the minimal number of jumps that the small frog must perform to reach its target.

	Write a function:
	int solution(int X, int Y, int D);

	That, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal to or greater than Y.
	For example, given:
	X = 10
	Y = 85
	D = 30

	The function should return 3, because the frog will be positioned as follows:
	- After the first jump : At position 10 + 30 = 40
	- After the second jump: At position 10 + 30 + 30 = 70
	- After the third jump : At position 10 + 30 + 30 + 30 = 100

	Write an efficient algorithm for the following assumptions:
	- X, Y and D are integers within the range [1..1,000,000,000];
	- (X =< Y).

	Codility Result:
	https://app.codility.com/demo/results/trainingRHMMRR-PQ3/

 */

#include <iostream>     // std::cout
#include <vector>       // std::vector

using namespace std;

/*********************************************************
   Class.
 *********************************************************/
class Solution
{
public:
	int frogJump(int X, int Y, int D)
	{

		if(X > Y)
		{
			return 0;
		}

		int remainingDistance;
		int jumpValue;

		remainingDistance = Y - X;

		if(remainingDistance % D != 0)
		{
			jumpValue = (remainingDistance / D) + 1;
		}
		else
		{
			jumpValue = (remainingDistance / D);
		}

		return jumpValue;
	}
};

/*********************************************************
    Operations implementation
 *********************************************************/
int main(void)
{
	Solution solution;

	// Testing ...
	int X = 10;
	int Y = 85;
	int D = 30;
	cout << "The result of (X = 10, Y = 85, D = 30)  is: " << solution.frogJump(X,Y,D) << endl;

	X = 0;
	Y = 100;
	D = 10;
	cout << "The result of (X = 0, Y = 100, D = 10)  is: " << solution.frogJump(X,Y,D) << endl;

	return 0;
}
