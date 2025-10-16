#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class list {
    node* head;
    node* tail;
public:
    list() {
        head = tail = NULL;
    }

    void push_front(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void push_back(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void push_mid(int val, int pos) {
        if (pos < 0) {
            cout << "invalid position";
        } else if (pos == 0) {
            push_front(val);
            return;
        } else {
            node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                if (temp == NULL) {
                    cout << "invalid position";
                    return;
                }
                temp = temp->next;
            }
            node* newnode = new node(val);
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "ll is empty";
            return;
        }
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            return;
        }
        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void delete_node(int val) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head->data == val) {
            pop_front();
            return;
        }
        node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Node " << val << " not found in the list." << endl;
            return;
        }
        if (temp->next == tail) {
            pop_back();
            return;
        }
        node* del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        delete del;
    }

    int search(int key) {
        node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        cout << "element not found";
        return -1;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    list ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.pop_front();
    ll.pop_back();
    ll.push_mid(99, 3);
    ll.delete_node(2);
    ll.display();
    ll.search(5);
    return 0;
}
