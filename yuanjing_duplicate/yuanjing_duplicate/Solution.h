#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length < 0)
		{
			duplication = NULL;
			return false;
		}
		int dupNum = 0;
		int* temp = new int[length];
		for (int i = 0; i < length; i++)
		{
			temp[i] = 0;
		}
		vector<int> vec;
		bool result = false;
		for (int i = 0; i < length; i++)
		{
			if(numbers[i]<0 || numbers[i]>length-1)
			{ 
				return false;
			}
			temp[numbers[i]]++;
			if (temp[numbers[i]] == 2)
			{
				dupNum++;
				result = true;
				vec.push_back(numbers[i]);
			}
		}
		duplication = new int[dupNum];
		for (int i = 0; i < dupNum; i++)
		{
			duplication[dupNum] = vec[i];
			cout << vec[i] << endl;
		}
		return result;
	}
};