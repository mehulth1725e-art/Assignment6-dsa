#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

   
    int countKey(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    
    void deleteKey(int key) {
        
        while (head != nullptr && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }

       
        Node* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->data == key) {
                Node* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }

   
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Create the list: 1->2->1->2->1->3->1
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(3);
    list.push_back(1);

    int key = 1;

    cout << "Original List: ";
    list.printList();

    int count = list.countKey(key);
    cout << "Count of " << key << ": " << count << endl;

    list.deleteKey(key);

    cout << "Updated List: ";
    list.printList();

    return 0;
}
