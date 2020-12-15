/**
  @file : maxProductOfThreeNumbers.cpp
  @class: maxProductOfThreeNumbers

  @brief:
	Give an integer array.
	Find three numbers whose product is maximum and output the maximum product.

	Codility result:
	https://app.codility.com/demo/results/trainingP9QBA4-MJ9/

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
	int maximumProduct(vector<int> &nums)
	{
		// Sort the vector
		sort(nums.begin(), nums.end());

		// Vector size
		int n = nums.size();

		int p1 = nums[n-1]*nums[n-2]*nums[n-3];
		int p2 = nums[0]*nums[1]*nums[n-1]; 	// For two negatives cases (Example: [-10,-10,1,2,3,4])

		return max(p1,p2);
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
	vect = {0,1,2,4,5,6,7,8,9,10};

	cout << solution.maximumProduct(vect);

	return 0;
}
