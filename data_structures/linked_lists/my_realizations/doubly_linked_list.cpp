#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop_front(){
        if(!head) return;
        Node* temporary = head;
        head = head->next;
        if(head) head->prev = nullptr;
        else tail = nullptr;
        delete temporary;
    }

    void pop_back(){
        if(!tail) return;
        Node* temporary = tail;
        tail = tail->prev;
        if(tail) tail->next = nullptr;
        else head = nullptr;
        delete temporary;
    }

    void print(){
        Node* temporary = head;
        while(temporary){
            std::cout << temporary->data << " ";
            temporary = temporary->next;
        }
        std::cout << "nullptr\n";
    }

    ~DoublyLinkedList(){
        while(head) pop_front();
    }
};

int main(){
    DoublyLinkedList list;
    list.push_front(1);
    list.push_back(2);
    list.push_front(3);
    list.print();
    list.pop_back();
    list.print();

    return 0;
}