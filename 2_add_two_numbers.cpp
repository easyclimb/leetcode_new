#include<stddef.h>
#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

/*
 * Note: "stack vs heap"
 * inside a loop: a variable's memory could be on stack/heap.
 * stack memory will be released automatically outside the loop.
 * so in this case, we stil want to access the result outside the loop,
 * then we should use new to declare a heap memory.
 */

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    int carry = 0;
    while(l1 || l2) {
      int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
      int digit = sum%10;
      carry = sum/10;
      ListNode *node = new ListNode(digit);
      cur->next = node;
      cur = cur->next;
      if(l1) l1 = l1->next;
      if(l2) l2 = l2->next;
    }
    if(carry != 0) {
      ListNode *node = new ListNode(carry);
      cur->next = node;
    }
    return dummy.next;
  }
};

int main()
{
  ListNode node1(1), node2(2), node3(3), node4(4);
  ListNode *l1, *l2;
  l1 = &node1;
  node1.next = &node2;
  l2 = &node3;
  node3.next = &node4;

  Solution s;
  ListNode *ret = s.addTwoNumbers(l1, l2);
  while(ret) {
    cout << ret->val << "\t";
    ret = ret->next;
  }
  cout << endl;
  return 0;
}
