#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0;
        int j = 0;
        for(char c : moves)
        {
            switch(c)
            {
            case 'U':
                i--;
                break;
            case 'R':
                j++;
                break;
            case 'D':
                i++;
                break;
            case 'L':
                j--;
                break;
            }
        }

        if(i==0 && j==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // SOLUTION_H
