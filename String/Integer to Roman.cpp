https://leetcode.com/problems/integer-to-roman/description/


class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

// C++ Program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function to calculate roman equivalent
string intToRoman(int num)
{
	// storing roman values of digits from 0-9
	// when placed at different places
	string m[] = { "", "M", "MM", "MMM" };
	string c[] = { "", "C", "CC", "CCC", "CD",
				"D", "DC", "DCC", "DCCC", "CM" };
	string x[] = { "", "X", "XX", "XXX", "XL",
				"L", "LX", "LXX", "LXXX", "XC" };
	string i[] = { "", "I", "II", "III", "IV",
				"V", "VI", "VII", "VIII", "IX" };

	// Converting to roman
	string thousands = m[num / 1000];
	string hundreds = c[(num % 1000) / 100];
	string tens = x[(num % 100) / 10];
	string ones = i[num % 10];

	string ans = thousands + hundreds + tens + ones;

	return ans;
}

// Driver program to test above function
int main()
{
	int number = 3549;
	cout << intToRoman(number);
	return 0;
}

/*
Output
MMMDXLIX
Time Complexity: O(N), where N is the length of ans string that stores the conversion.
Auxiliary Space: O(N)
*/
