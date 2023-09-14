https://www.geeksforgeeks.org/reverse-individual-words/


// C++ program to reverse individual words in a given
// string using STL list

#include <bits/stdc++.h>
using namespace std;

// reverses individual words of a string
void reverseWords(string str)
{
	stack<char> st;

	// Traverse given string and push all characters
	// to stack until we see a space.
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != ' ')
			st.push(str[i]);

		// When we see a space, we print contents
		// of stack.
		else {
			while (st.empty() == false) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
	}

	// Since there may not be space after
	// last word.
	while (st.empty() == false) {
		cout << st.top();
		st.pop();
	}
}

// Driver program to test function
int main()
{
	string str = "Geeks for Geeks";
	reverseWords(str);
	return 0;
}



#include <bits/stdc++.h>
using namespace std;

void printWords(string str)
{
	// word variable to store word
	string word;

	// making a string stream
	stringstream iss(str);

	// Read and print each word.
	while (iss >> word) {
		reverse(word.begin(), word.end());
		cout << word << " ";
	}
}

// Driver code
int main()
{
	string s = "GeeksforGeeks is good to learn";
	printWords(s);
	return 0;
}
