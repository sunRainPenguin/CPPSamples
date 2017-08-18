#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int n = s.size();
		int left = 0, right = n - 1;
		char temp;
		while (left < right)
		{
			while (!(s[left] == 'a' || s[left] == 'o' || s[left] == 'e' || s[left] == 'i' || s[left] == 'u' || s[left] == 'A' || s[left] == 'O' || s[left] == 'E' || s[left] == 'I'|| s[left] == 'U')  && left!=right)
			{
				left++;
			}
			if (left == right)
			{
				return s;
			}

			while (!(s[right] == 'a' || s[right] == 'o' || s[right] == 'e' || s[right] == 'i' || s[right] == 'u' || s[right] == 'A' || s[right] == 'O' || s[right] == 'E' || s[right] == 'I' || s[right] == 'U') && left!=right)
			{
				right--;
			}
			if (left == right)
			{
				return s;
			}
			if (left != right)
			{
				temp = s[left];
				s[left] = s[right];
				s[right] = temp;
				left++;
				right--;
			}
			else
			{
				return s;
			}
		}
		return s;
	}
};