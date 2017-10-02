#ifndef SOLUTION_H
#define SOLUTION_H
#include <cstddef>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
        {
            return NULL;
        }
        vector<int> result;
        int index = 0;
        int sum = 0;
        int sumBit = 0;
        int carryBit = 0;
        while(l1 != NULL || l2 != NULL)
        {
            sum = 0;
            sum += carryBit;
            while(result.size()<index + 1)
            {
                result.push_back(0);
            }
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sumBit = sum % 10;
            carryBit = sum / 10;
            result[index] = sumBit;
            while(carryBit!=0 && result.size()<index+2)
            {
                result.push_back(0);
            }
            result[index+1] = carryBit;
            index++;
        }

        ListNode* temp1 = new ListNode(result[result.size()-1]);
        for(int i=result.size()-2; i>=0; i--)
        {
            ListNode* temp2 = new ListNode(result[i]);
            temp2->next = temp1;
            temp1 = temp2;
        }
        return temp1;
    }
};
#endif // SOLUTION_H

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        long long temp = 1;
//        long long i1 = 0;
//        long long i2 = 0;
//        long long re = 0;
//        while(l1!=NULL || l2!=NULL)
//        {
//            if(l1!=NULL)
//            {
//                i1 += (l1->val)*temp;
//                l1 = l1->next;
//            }
//            if(l2!=NULL)
//            {
//                i2 += (l2->val)*temp;
//                l2 = l2->next;
//            }
//            temp*=10;
//        }
//
//        re = i1 + i2;
//        int mod = 0;
//        temp = 10;
//        ListNode* resultT = new ListNode(0);
//        ListNode* result = resultT;
//        while(re!=0)
//        {
//            mod = re%temp;
//            re = re/10;
//            resultT->val = mod;
//            if(re!=0)
//            {
//                resultT->next = new ListNode(0);
//                resultT = resultT->next;
//            }
//        }
//        return result;
//    }
//};

//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//    if(l1==NULL && l2==NULL)
//    {
//        return NULL;
//    }
//    ListNode* re = new ListNode(0);
//    ListNode* result = re;
//    int sum = 0;
//    int sumBit = 0;
//    int carryBit = 0;
//    bool isFirst = true;
//    while(true)
//    {
//        sum = 0;
//        sumBit = 0;
//        if(l1!=NULL)
//        {
//            sum += l1->val;
//        }
//        if(l2!=NULL)
//        {
//            sum += l2->val;
//        }
//        sum += carryBit;
//        sumBit = sum%10;
//        carryBit = sum/10;
//
//        if((sum!=0 || isFirst) && re!= NULL)
//        {
//            re->val = sumBit;
//             // �����һ�μ������֮�󣬷��ֵ�ǰ�����ڵ㶼Ϊ�գ���������㡣����д��ǰ����Ϊ���ܹ��������Ľ�λ��
//            if(l1==NULL && l2==NULL)
//            {
//                break;
//            }
//            // ���l1��l2������һ��ֵ��Ϊ�գ�������һ�������н�λ�����������л�����һλ
//            if(l1->next != NULL || l2->next != NULL || carryBit!=0)
//            {
//                re->next = new ListNode(0);
//                re = re->next;
//            }
//        }
//
//        if(l1!=NULL)
//        {
//            l1 = l1->next;
//        }
//        if(l2!=NULL)
//        {
//            l2 = l2->next;
//        }
//        if(isFirst)
//        {
//            isFirst = false;
//        }
//    }
//    return result;
//}


