#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(); 
        ListNode* current = dummyHead; 
        int carry = 0; 
        
        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10; 
            current->next = new ListNode(sum % 10); 
            current = current->next;
        }
        
        if (carry > 0) {
            current->next = new ListNode(carry);
        }
        
        return dummyHead->next;
    }
};

int main() {
    
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << std::endl;

    return 0;
}
