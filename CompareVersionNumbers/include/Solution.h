#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string v1,v2;
        int iv1 = 0, iv2 = 0;
        if(version1==version2)
        {
            return 0;
        }
        else if(version1.find(version2)==0)
        {
            return 1;
        }
        else if(version2.find(version1)==0)
        {
            return -1;
        }
        else
        {
            int i1 = 0, i2 = 0;
            while(i<version1.length() && i<version1.length())
            {
                while(version1[i]!='.')
                {
                    v1.push_back(version1[i]);
                    i++;
                }
                i++;

                i = 0;
                while(version2[i]!='.')
                {
                    v2.push_back(version2[i]);
                    i++;
                }
                i++;

                iv1 = atoi(v1.c_str());
                iv2 = atoi(v2.c_str());
                if(iv1>iv2)
                {
                    return 1;
                }
                else if(iv1<iv2)
                {
                    return -1;
                }
            }
        }
    }
};

#endif // SOLUTION_H
