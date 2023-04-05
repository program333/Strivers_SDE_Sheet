https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/


#include<bits/stdc++.h>

using namespace std;
int longestConsecutive(vector < int > & nums) {
  set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}
int main() {
  vector<int> arr{100,200,1,2,3,4};
  int lon = longestConsecutive(arr);
  cout << "The longest consecutive sequence is " << lon << endl;

}

/*
Output:

The longest consecutive sequence is 4

Time Complexity: The time complexity of the above approach is O(N) because we traverse each consecutive subsequence only once. 
(assuming HashSet takes O(1) to search)

Space Complexity: The space complexity of the above approach is O(N) because we are maintaining a HashSet.

*/
