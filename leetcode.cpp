#include <iostream>
#include <vector>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        ListNode* tail = head;
        int length = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        k = k % length;
        if (k == 0) {
            return head;
        }

        tail->next = head;

        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    cout << "[ ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Example 1
    ListNode* l1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = sol.rotateRight(l1, 2);
    cout << "Example 1 Output: ";
    printList(res1); // Expected: [ 4 5 1 2 3 ]

    // Example 2
    ListNode* l2 = createList({0, 1, 2});
    ListNode* res2 = sol.rotateRight(l2, 4);
    cout << "Example 2 Output: ";
    printList(res2); // Expected: [ 2 0 1 ]

    return 0;
}