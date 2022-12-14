#include <iostream>
using namespace std;
/* This is leetcode problem 206 - Reverse Linked List
 * Difficulty: Easy. Type: Linked List.
 * Goal: Given the head of a linked list, reverse the linked list and return the new head
 * Approach: Create a current and previous temp, set current to head and temp to NULL at start
 * iterate through the linked list, with each node: 
 * - Initialize a temp next ptr to the next node of cur
 * - Set the next node to prev
 * - Set the prev to be the cur
 * - Set the cur to be next
 * Return the prev pointer because when the iteration is complete, the cur ptr will point to null
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;	
		ListNode* prev = nullptr;
		while(cur) {
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	} 
};
int main ()
{
	int list [5] = {1,2,3,4,5};
	ListNode* l = new ListNode(list[0]);
	ListNode* head = l;
	for(int i = 1; i < sizeof(list)/4; i++) {
		l->next = new ListNode(list[i]);	
		l = l->next;
	}
	Solution s;
	ListNode* output = s.reverseList(head);
	return 0;
}
