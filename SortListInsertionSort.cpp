#include<stdio.h>
//bad solution, LTE
//better off use quick sort.
void foo();
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		const static int MIN = -0x7FFFFFFF;		
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* start = new ListNode(MIN);
		ListNode* headtmp = head;
		start->next = headtmp;
		ListNode* cur = head->next;
		headtmp->next = NULL;
		ListNode* tail = headtmp;
		while (cur != NULL) {
			ListNode* starttmp = start;
			ListNode* curtmp = cur;
			ListNode* curnext = cur->next;
			if (cur->val > tail->val) {
				tail->next = cur;
				tail = cur;
				continue;
			}
			while (starttmp != NULL) {
				ListNode* starttmpnext = starttmp->next;
				if (starttmpnext == NULL) {
					starttmp->next = cur;
					cur->next = NULL;
					tail = cur;
					break;
				} else {
					if (starttmpnext->val > cur->val) {
						starttmp->next = cur;
						cur->next = starttmpnext;
						break;
					}
				}
				starttmp = starttmpnext;
			}
			cur = curnext;
		}
		ListNode* result = start->next;
		delete start;
		return result;
	}
};

void foo() {
	Solution s;
	ListNode* head = new ListNode(2);
	//ListNode* a = new ListNode(1);
	ListNode* a = new ListNode(9);
	ListNode* b = new ListNode(7);
	ListNode* c = new ListNode(4);
	head->next = a;
	a->next = b;
	b->next = c;
	ListNode* result = s.sortList(head);
	while (result != NULL) {
		printf("%d ", result->val);
		result = result->next;
	}
}

int main() {
	foo();
	return 0;
}
