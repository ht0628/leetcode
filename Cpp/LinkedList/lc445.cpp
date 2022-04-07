//lc445 - 链表相加
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n): val(n), next(nullptr) {};
    ListNode(int n, ListNode* next) :val(n), next(next) {}; 
};

ListNode* getLinkedList(vector<int> &value)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    for(int i=0; i < value.size(); i++){
        cur->next = new ListNode(value[i]);
        cur = cur->next;
    }
    cur->next = NULL;
    return dummy->next;
}

void printLinkedList(ListNode* head)
{
    ListNode* cur = head;
    while (cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    } 
}

class Solution {
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        stack<int> st1, st2, st3;
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        int carry = 0;
        while(cur1){
            st1.push(cur1->val);
            cur1 = cur1->next;
        }
        while(cur2){
            st2.push(cur2->val);
            cur2 = cur2->next;
        }
        while(!st1.empty() || !st2.empty() || carry){
            int x=0,y=0,sum=0,remain=0;
            if(!st1.empty()){
                x = st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                y = st2.top();
                st2.pop();
            }
            sum = x + y + carry;
            remain = sum % 10;
            carry = sum / 10;
            st3.push(remain);
        }
        while(!st3.empty()){
            cur->next = new ListNode(st3.top());
            cur = cur->next;
            st3.pop();
        }
        return res->next;
    }
};


int main()
{
    vector<int> v1 = {9,3,7};
    vector<int> v2 = {6,3};
    Solution s = Solution();
    ListNode* res = s.addInList(getLinkedList(v1), getLinkedList(v2));
    printLinkedList(res);
}
