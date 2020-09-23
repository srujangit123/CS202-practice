#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next = nullptr;
};

struct Node* head = nullptr;

void push_back(int x);
void push_front(int x);
void pop_back();
void pop_front();
void print();
void insert_between_sortedlist(int x);
int find_element(int x);
void delete_element(int x);


void push_front(int x) {
    struct Node* new_element = (struct Node*)malloc(sizeof(struct Node));
    new_element->data = x;
    new_element->next = head;
    head = new_element;
    // new_element contains address of location of new Node we created
}

void push_back(int x) {
    struct Node* new_element = (struct Node*)malloc(sizeof(struct Node));
    new_element->data = x;
    struct Node* i = head;
    if(head == nullptr) {
        new_element->next = nullptr;
        head = new_element;
        return;
        //1 - 2 - 3 - 4 - 5 - null
    }
    while(i->next != nullptr) {
        i = i->next;
    }
    i->next = new_element;
    new_element->next = nullptr;
}


int find_element(int x) {
    int pos = 0;
    struct Node* i = head;
    while(i != nullptr) {
        if(i->data == x) {
            return pos;
        }
        i = i->next;
        pos++;
    }
    return -1;
}

void print() {
    struct Node* i = head;
    while(i != nullptr) {
        cout << i->data << " ";
        i = i->next;
    }
    cout << endl;
}

void insert_between_sortedlist(int x) {
    struct Node* new_element = (struct Node*)malloc(sizeof(struct Node));
    new_element->data = x;
    if(head == nullptr) {
        head = new_element;
        return;
    }
    if(head->data >= x) {
        new_element->next = head;
        head = new_element;
        return;
    }
    struct Node* pre = head;
    struct Node* post = head->next;
    while(post != nullptr) {
        if(x >= pre->data && x <= post->data) {
            pre->next = new_element;
            new_element->next = post;
            return;
        }
        pre = pre->next;
        post = post->next;
    }
    pre->next = new_element;
    new_element = post;
}


void delete_element(int x) {
    if(head == nullptr) {
        cout << "No element in linkedlist\n";
        return;
    }
    struct Node* pre = nullptr;
    struct Node* i = head;
    if(head->data == x) {
        head = head->next;
        return;
    }
    while(i != nullptr) {
        if(i->data == x) {
            pre->next = i->next;
            return;
        }
        pre = i;
        i = i->next;
    }
    
}

void pop_front() {
    if(head == nullptr) return;
    head = head->next;
}


void pop_back() {
    if(head == nullptr) return;
    struct Node* i = head;
    while(i->next->next != nullptr) {
        i = i->next;
    }
    i->next = nullptr;
}


int main() {
    int choice = -1;
    int x;
    while(1) {
        cout << "1. Push front\n";
        cout << "2. Push back\n";
        cout << "3. insert to sorted list\n";
        cout << "4. Delete an element\n";
        cout << "5. Find an element\n";
        cout << "6. Display\n";
        cout << "7. Pop Back\n";
        cout << "8. Pop front\n";
        cout << "9. Stop\n";
        cin >> choice;
        if(choice == 9) break;
        switch (choice) {
            case 1: cin >> x;
                    push_front(x);
                    break;
            case 2: cin >> x;
                    push_back(x);
                    break;
            case 3: cin >> x;
                    insert_between_sortedlist(x);
                    break;
            case 4: cin >> x;
                    delete_element(x);
                    break;
            case 5: {
                        cin >> x;
                        int loc = find_element(x);
                        if(loc == -1) cout << "Element is not present\n";
                        else cout << "Element is at " << loc << " postition\n";
                        break;
                    }
            case 6: print();
                    break;
            case 7: pop_back();
                    break;
            case 8: pop_front();
                    break;
            default: exit(0);
        }
    }
    return 0;
}