#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int data) {
        this->val = data;
        this->next = NULL;
    }
};

// Create a LinkedList and insert Element at tail of the List.
void createList(ListNode* &head, int data) {
    ListNode* temp = new ListNode(data);
    if (head == NULL) {
        head = temp;
        return;
    }

    ListNode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

// Print a LinkedList.
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* temp = NULL;
        ListNode* curr = head;
        int cnt = 2;

        while (curr != NULL && cnt--) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Recursive call for the remaining node.
        // I should handle one case, recursion will take care others.
        if (temp != NULL) {
            head->next = swapPairs(temp);
        }
        return prev;
    }
};

int main() {
    // Creating and printing the original list
    ListNode* head = nullptr;
    createList(head, 1);
    createList(head, 2);
    createList(head, 3);
    createList(head, 4);
    createList(head, 5);
    cout << "Original List: ";
    printList(head);

    // Swapping pairs and printing the updated list
    Solution solution;
    ListNode* newHead = solution.swapPairs(head);
    cout << "Updated List: ";
    printList(newHead);

    // Clean up memory
    while (newHead != nullptr) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
