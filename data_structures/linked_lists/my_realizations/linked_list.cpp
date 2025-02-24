#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void push_front(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }
        Node* temporary = head;
        while(temporary->next) temporary = temporary->next;
        temporary->next = newNode;
    }

    void pop_front(){
        if(!head) return;
        Node* temporary = head;
        head = head->next;
        delete temporary;
    }

    void pop_back(){
        if(!head) return;
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }

        Node* temporary = head;
        while(temporary->next->next) temporary = temporary->next;
        delete temporary->next;
        temporary->next = nullptr;
    }

    void print(){
        Node* temporary = head;
        while(temporary){
            std::cout << temporary->data << " ";
            temporary = temporary->next;
        }
        std::cout << "nullptr\n";
    }

    ~LinkedList(){
        while(head) pop_front();
    }

};

int main(){
    LinkedList list;
    std::cout << "TESTING: \n";

    list.push_front(1);
    list.push_back(2);
    list.push_front(3);
    list.print();
    list.pop_back();
    list.print();
    return 0;
}