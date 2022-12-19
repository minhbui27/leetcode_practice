#include <iostream>
using namespace std;
/* This is leetcode 21. Merge Two Sorted Lists
 * Difficulty: Easy. Type: Linked List.
 * Goal: Given the head of two sorted linked lists, output a merged sorted linked list.
 * Approach: Start at the head of both of the lists. If one element is greater than the other,
 * then that element will go after. The smaller element will be linked to temp, and forwarded to the
 * next element in that list. The larger element will stay until that element becomes smaller than
 * some element in the other list. This will repeat until either of the list is empty. Then, the non empty
 * part of the other list will be merged into temp. And the head will be returned.
*/
struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode() : val(0), next(nullptr) {}
	 ListNode(int x) : val(x), next(nullptr) {}
	 ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// Create the output list and keep track of the head.
		ListNode* temp = new ListNode(0);
		ListNode* head = temp;
		while(list1 && list2) {
			// Note that we are creating a reference of a pointer to the current element in list1 or list2.
			ListNode* &node = list1->val <= list2->val ? list1 : list2;
			temp->next = node;
			// Forward the temp pointer and whichever element is smaller.
			temp = temp->next;
			node = node->next;
		}
		// Link the non empty list.
		temp->next = list1 ? list1 : list2;
		return head->next;
	}
};
int main () {
	int arr1[3] = {1,2,4};
	int arr2[3] = {1,3,4};
	ListNode* list1 = new ListNode(arr1[0]);
	ListNode* list2 = new ListNode(arr2[0]);
	ListNode* head1 = list1;
	ListNode* head2 = list2;
	for(int i = 1; i < sizeof(arr1)/4; i++) {
		list1->next = new ListNode(arr1[i]);
		list1 = list1->next; 
	}
	for(int i = 1; i < sizeof(arr2)/4; i++) {
		list2->next = new ListNode(arr2[i]);
		list2 = list2->next; 
	}
	// cout << "Printing list1:" << endl;
	// while(head1) {
	// 	cout << head1->val << " ";
	// 	head1 = head1->next;
	// }
	// cout << endl;
	// cout << "Printing list2:" << endl;
	// while(head2) {
	// 	cout << head2->val << " ";
	// 	head2 = head2->next;
	// }
	// cout << "\n";
	Solution s;
	s.mergeTwoLists(head1, head2);
	return 0;
}
