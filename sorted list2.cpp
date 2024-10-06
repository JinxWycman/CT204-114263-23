#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove duplicates from a sorted linked list
void removeDuplicates(ListNode* head) {
    if (head == nullptr) return; // If the list is empty, return

    ListNode* current = head; // Start with the head of the list

    while (current->next != nullptr) {
        if (current->val == current->next->val) {
            // If current value is equal to the next value, skip the next node
            ListNode* duplicate = current->next;
            current->next = current->next->next; // Bypass the duplicate node
            delete duplicate; // Free memory of the duplicate node
        } else {
            current = current->next; // Move to the next node
        }
    }
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Main function to demonstrate removing duplicates
int main() {
    // Creating a sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    std::cout << "Original list: ";
    printList(head);

    removeDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(head);

    // Freeing up allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}