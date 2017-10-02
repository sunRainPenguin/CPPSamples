#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(9);
    ListNode* l3 = new ListNode(9);
    ListNode* l4 = new ListNode(9);
    ListNode* l5 = new ListNode(9);
    ListNode* l6 = new ListNode(9);
    ListNode* l7 = new ListNode(9);
    ListNode* l8 = new ListNode(9);
    ListNode* l9 = new ListNode(9);
    ListNode* l10 = new ListNode(9);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;

    ListNode* l11 = new ListNode(9);

    ListNode* re = NULL;
    Solution solution;
    re = solution.addTwoNumbers(l1,l11);

    while(re!=NULL)
    {
        cout<<re->val<<endl;
        re = re->next;
    }
    return 0;
}
