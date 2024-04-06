#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int data){
      this->val=data;
      this->next=NULL;
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
    ListNode* reverseKGroup(ListNode* head, int  k) {
     // Base case. if head == NULL
       if (head == NULL) {
         return NULL;
    }
       ListNode* next = NULL;
       ListNode* current = head;
       ListNode* previous = NULL;
       int count = 0;
       // Count the remaining nodes
      ListNode* temp = head;
      while (temp != NULL&& count < k) {
         temp = temp->next;
         count++;
        }
         if (count < k) {
         // If the remaining nodes are less than k, no need to reverse
         return head;
        }
       count = 0;
       while (current != NULL && count < k) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            count++;
        }
       if (next != NULL) {
         // Recursive call for the remaining nodes
        head->next = reverseKGroup(next, k);
        }
      return previous;
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
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    ListNode* newHead = solution.reverseKGroup(head,k);
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
