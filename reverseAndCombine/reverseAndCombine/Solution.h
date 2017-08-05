#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Solution
{
public:
	Node* combineList(Node* head1, Node* head2)
	{
		Node* curr1 = head1;
		Node* curr2 = head2;
		Node* lastMin = nullptr;
		Node* temp = nullptr;
		while (curr1!=nullptr && curr2!=nullptr)
		{
			if (curr1->data <= curr2->data)
			{
				temp = curr1->next;
				curr1->next = lastMin;
				lastMin = curr1;
				curr1 = temp;
			}
			else
			{
				temp = curr2->next;
				curr2->next = lastMin;
				lastMin = curr2;
				curr2 = temp;
			}
		}
		Node* currNode = nullptr;
		temp = nullptr;
		if (curr1 != nullptr)
		{
			currNode = curr1;
		}
		else if (curr2 != nullptr)
		{
			currNode = curr2;
		}
		while (currNode != nullptr)
		{
			temp = currNode->next;
			currNode->next = lastMin;
			lastMin = currNode;
			currNode = temp;
		}
		return lastMin;
	}
};

