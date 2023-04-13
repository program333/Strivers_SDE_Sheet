https://www.geeksforgeeks.org/koko-eating-bananas/
https://leetcode.com/problems/koko-eating-bananas/description/

// C++ implementation for the above approach

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& bananas, int mid_val, int H)
{
	int time = 0;
	for (int i = 0; i < bananas.size(); i++) {

		// to get the ceil value
		if (bananas[i] % mid_val != 0) {

			// in case of odd number
			time += ((bananas[i] / mid_val) + 1);
		}
		else {

			// in case of even number
			time += (bananas[i] / mid_val);
		}
	}

	// check if time is less than
	// or equals to given hour
	if (time <= H) {
		return true;
	}
	else {
		return false;
	}
}

int minEatingSpeed(vector<int>& piles, int H)
{

	// as minimum speed of eating must be 1
	int start = 1;

	// Maximum speed of eating
	// is the maximum bananas in given piles
	int end = *max_element(piles.begin(), piles.end());

	while (start < end) {
		int mid = start + (end - start) / 2;

		// Check if the mid(hours) is valid
		if ((check(piles, mid, H)) == true) {

			// If valid continue to search
			// lower speed
			end = mid;
		}
		else {
			// If cant finish bananas in given
			// hours, then increase the speed
			start = mid + 1;
		}
	}
	return end;
}

// Driver code
int main()
{
	vector<int> piles = { 30, 11, 23, 4, 20 };
	int H = 6;
	cout << minEatingSpeed(piles, H);
	return 0;
}
