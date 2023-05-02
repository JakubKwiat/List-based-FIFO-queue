#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node* prev, * next;
};
Node* beg, * end1, * front, * back;
void Check_queue_size(int& count) {
    count = 0;
    Node* start = front;
    if (front == NULL) {
        count = 0;
    }
    else {
        while (true) {
            count++;
            if (start == back) {
                break;
            }
            start = start->prev;
        }
    }
}
void Add_beg(int& size,int &size_queue) {
    int data;
    cin >> data;
    Node* newNode;
    newNode = new Node;
    newNode->data = data;
    if (size == 0) {
        beg = newNode;
        end1 = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    }
    else {
        beg->prev = newNode;
        end1->next = newNode;
        newNode->prev = end1;
        newNode->next = beg;
        beg = newNode;
    }
    Check_queue_size(size_queue);
    size++;
}
void Add_end(int& size,int &size_queue) {
    int data;
    cin >> data;
    Node* newNode;
    newNode = new Node;
    newNode->data = data;
    if (size == 0) {
        beg = newNode;
        end1 = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    }
    else {
        end1->next = newNode;
        beg->prev = newNode;
        newNode->prev = end1;
        newNode->next = beg;
        end1 = newNode;
    }
    Check_queue_size(size_queue);
    size++;
}
void Del_beg(int& size,int&size_queue) {
    if (size == 1) {
        beg = NULL;
        end1 = NULL;
        front = NULL;
        back = NULL;
        size = 0;
        size_queue = 0;
    }
    else {
        if (back == beg) {
            back = beg->next;
            size_queue--;
        }
        if (front == beg) {
            front = beg->next;
            size_queue--;
        }
        if (front->prev == beg) {
            Node* temp = front->prev;
            front->prev = temp->prev;
        }
        if (front->next == beg) {
            Node* temp = front->next;
            front->next = temp->next;
        }
        if (back->prev == beg) {
            Node* temp = back->prev;
            back->prev = temp->prev;
        }
        if (back->next == beg) {
            Node* temp = back->next;
            back->next = temp->next;
        }
        beg = beg->next;
        end1->next = beg;
    }
    Check_queue_size(size_queue);
    size--;
}
void Del_end(int& size,int &size_queue) {
    if (size == 1) {
        beg = NULL;
        end1 = NULL;
        front = NULL;
        back = NULL;
        size = 0;
        size_queue = 0;
    }
    else {
        if (back == end1) {
            back = beg;
            size_queue--;
        }
        if (front == end1) {
            front = beg;
            size_queue--;
        }
        if (front->prev == end1) {
            Node* temp = front->prev;
            front->prev = temp->prev;
        }
        if (front->next == end1) {
            Node* temp = front->next;
            front->next = temp->next;
        }
        if (back->prev == end1) {
            Node* temp = back->prev;
            back->prev = temp->prev;
        }
        if (back->next == end1) {
            Node* temp = back->next;
            back->next = temp->next;
        }
        end1 = end1->prev;
        beg->prev = end1;
    }
    Check_queue_size(size_queue);
    size--;
}
void Print_forward() {
    Node* start = beg;
    if (beg == NULL) {
        cout << "NULL";
    }
    else {
        int condition = 0;
        while (condition == 0) {
            if (start == end1) {
                condition = 1;
            }
            cout << start->data << " ";
            start = start->next;
        }
    }
    cout << endl;
}
void Print_backward() {
    Node* start = end1;
    if (beg == NULL) {
        cout << "NULL";
    }
    else {
        int condition = 0;
        while (condition == 0) {
            if (start == beg) {
                condition = 1;
            }
            cout << start->data << " ";
            start = start->prev;
        }
    }
    cout << endl;
}
void Size(int size) {
    cout << size << endl;
}
void Count(int size_queue) {
    cout << size_queue << endl;
}
void Push(int& size_queue, int& size) {
    int data;
    cin >> data;
    if (size_queue == size) {
        Node* newNode;
        newNode = new Node;
        newNode->data = data;
        if (size == 0) {
            newNode->prev = newNode;
            newNode->next = newNode;
            back = newNode;
            front = newNode;
            beg = newNode;
            end1 = newNode;
        }
        else {
            if (back != beg) {
                front->next = newNode;
                back->prev = newNode;
                newNode->next = back;
                newNode->prev = front;
                back = newNode;
            }
            else {
                beg->prev = newNode;
                end1->next = newNode;
                newNode->prev = end1;
                newNode->next = beg;
                beg = newNode;
                back = newNode;
            }
        }
        size++;
        size_queue++;
    }
    else {
        if (size_queue == 0) {
            end1->data = data;
            front = end1;
            back = end1;
            size_queue++;
        }
        else {
            Node* temp = back->prev;
            temp->data = data;
            back = temp;
            size_queue++;
        }
    }
}
void Pop(int& size_queue) {
    if (front != NULL) {
        cout << front->data << endl;
        if (size_queue == 1) {
            front = NULL;
            back = NULL;
        }
        else {
            front = front->prev;
        }
        size_queue--;
    }
    else {
        cout << "NULL" << endl;
    }
}
void Print_queue() {
    Node* start = front;
    if (front == NULL) {
        cout << "NULL";
    }
    else {
        while (true) {
            cout << start->data << " ";
            if (start == back) {
                break;
            }
            start = start->prev;
        }
    }
    cout << endl;
}
void Garbage_soft() {
    if (front == NULL) {
        if (beg != NULL) {
            Node* start = beg;
            int condition = 0;
            while (condition == 0) {
                if (start == end1) {
                    condition = 1;
                }
                start->data = 0;
                start = start->next;
            }
        }
    }
    else {
        Node* start = front;
        while (true) {
            start = start->next;
            if (start == back) {
                break;
            }
            start->data = 0;
        }

    }
}
void Garbage_hard(int& size, int& size_queue) {
    if (front == NULL) {
        if (beg != NULL) {
            beg = NULL;
            end1 = NULL;
            front = NULL;
            back = NULL;
            size = 0;
            size_queue = 0;
        }
    }
    else {
        Node* start = front;
        while (true) {
            Node* temp = start;
            start = start->next;
            Node* temp2 = start->next;
            if (start == back) {
                break;
            }
            temp->next = temp2;
            temp2->prev = temp;
            size--;
        }
        size = size_queue;
        front->next = back;
        back->prev = front;
    }
}
int main() {
    int size = 0;
    int size_queue = 0;
    string command;
    while (cin >> command) {
        if (command == "ADD_BEG") {
            Add_beg(size,size_queue);
        }
        if (command == "ADD_END") {
            Add_end(size,size_queue);
        }
        if (command == "DEL_BEG") {
            Del_beg(size,size_queue);
        }
        if (command == "DEL_END") {
            Del_end(size,size_queue);
        }
        if (command == "PRINT_FORWARD") {
            Print_forward();
        }
        if (command == "PRINT_BACKWARD") {
            Print_backward();
        }
        if (command == "SIZE") {
            Size(size);
        }
        if (command == "COUNT") {
            Count(size_queue);
        }
        if (command == "PUSH") {
            Push(size_queue, size);
        }
        if (command == "PRINT_QUEUE") {
            Print_queue();
        }
        if (command == "POP") {
            Pop(size_queue);
        }
        if (command == "GARBAGE_SOFT") {
            Garbage_soft();
        }
        if (command == "GARBAGE_HARD") {
            Garbage_hard(size, size_queue);
        }
    }
    return 0;
}