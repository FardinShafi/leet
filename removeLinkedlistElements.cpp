#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *curr = dummy;

        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

int main()
{
    // Example usage
    ListNode *head = new ListNode(4);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(0);

    Solution solution;
    int val_to_remove = 1;
    ListNode *result = solution.removeElements(head, val_to_remove);

    // Print the result
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
