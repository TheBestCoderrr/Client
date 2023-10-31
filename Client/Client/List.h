#pragma once
#include <iostream>
#include "String.h"
using namespace std;

template<typename type>
class Node
{
public:
    explicit Node(type v, Node* n = nullptr) :value(v), next(n) {};
    type getValue() const { return value; }
    void setValue(type v) { value = v; }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }
    void Print() { cout << value; }
private:
    type value;
    Node* next;
};

template<typename type>
class List {
public:
    List() :head(nullptr), tail(nullptr), counter(0) {}
    List(const List& other);
    ~List() { clear(); }
    Node<type>* getHead() { return head;  }
    Node<type>* getTail() { return tail; }
    size_t getCounter() { return counter; };
    List& operator=(const List& other) noexcept;
    List operator+(const List& other) const;
    size_t size() const { return counter; }
    void push_back(type v);
    void push_front(type v);
    void pop_front();
    void pop_back();
    void clear();
    void print() const;
    Node<type>* findNode(size_t index) const;
    void insert(size_t index, type v);
    void pop_position(size_t index);

private:
    Node<type>* head;
    Node<type>* tail;
    size_t counter;
};

template<class type>
List<type>::List(const List<type>& other) : List()
{
    Node<type>* cur = other.head;
    while (cur)
    {
        push_back(cur->getValue());
        cur = cur->getNext();
    }
}

template<class type>
List<type>& List<type>::operator=(const List<type>& other) noexcept {
    if (this != &other) {
        clear();
        Node<type>* cur = other.head;
        while (cur)
        {
            push_back(cur->getValue());
            cur = cur->getNext();
        }
    }
    return *this;
}

template<class type>
List<type> List<type>::operator+(const List& other) const
{
    List<type> result = *this;
    Node<type>* cur = other.head;
    while (cur)
    {
        result.push_back(cur->getValue());
        cur = cur->getNext();
    }
    return result;
}

template<typename type>
void List<type>::print() const {
    Node<type>* cur = head;
    while (cur) {
        cur->Print();
        cur = cur->getNext();
    }
    cout << endl;
}

template<typename type>
void List<type>::push_back(type v) {
    Node<type>* temp = new Node<type>(v);
    if (tail)
        tail->setNext(temp);
    else
        head = temp;
    tail = temp;
    ++counter;
}

template<typename type>
void List<type>::push_front(type v) {
    Node<type>* temp = new Node<type>(v, head);
    if (!head) tail = temp;
    head = temp;
    ++counter;
}

template<typename type>
void List<type>::pop_front() {
    if (head) {
        Node<type>* temp = head;
        head = head->getNext();
        if (!tail) tail = nullptr;
        delete temp;
        --counter;
    }
}

template<typename type>
void List<type>::pop_back()
{
    if (!head) return;
    else if (head == tail) {
        delete head;
        head = nullptr;
        counter = 0;
        return;
    }
    Node<type>* temp = head;
    while (temp->getNext() != tail)
        temp = temp->getNext();
    tail = temp;
    tail->setNext(nullptr);
    delete temp->getNext();
    --counter;
}

template<typename type>
void List<type>::clear() { while (counter > 0)pop_back(); }

template<typename type>
Node<type>* List<type>::findNode(size_t index) const
{
    if (index >= counter) return nullptr;
    size_t n = 0;
    Node<type>* cur = head;
    while (cur) {
        if (n == index) break;
        cur = cur->getNext();
        n++;
    }
    return cur;
}

template<typename type>
void List<type>::insert(size_t index, type v)
{
    if (index > counter) return;
    if (index == 0) { push_front(v); return; }
    if (index == counter) { push_back(v); return; }
    Node<type>* prev = findNode(index - 1);
    Node<type>* temp = new Node<type>(v, prev->getNext());
    prev->setNext(temp);
    ++counter;
}

template <class type>
void List<type>::pop_position(size_t index) {
    if (index >= counter) return;
    if (index == 0) { pop_front(); return; }
    if (index == counter - 1) { pop_back(); return; }
    Node<type>* prev = findNode(index - 1);
    Node<type>* temp = prev->getNext();
    prev->setNext(temp->getNext());
    delete temp;
    --counter;
}

void PrintByItem(List<Client> list,const String& item) {
    Node<Client>* cur = list.getHead();
    while (cur) {
        if(strcmp(cur->getValue().getItem().GetStr(), item.GetStr()) == 0)
            cur->Print();
        cur = cur->getNext();
    }
    cout << endl;
}

size_t GetSize_tNum(char* Buffer) {
    size_t num = 0;
    for (size_t i = 0; i < strlen(Buffer); i++) {
        num += Buffer[i] - '0';
        num *= 10;
    }
    num /= 10;
    return num;
}

void DownloadList(List<Client>& list) {
    FILE* file;
    file = fopen("C:\\Users\\User\\Downloads\\Client.txt", "r");
    if (!file) return;
    String str, tempstr;
    Client client;
    char letter;
    do {
        fseek(file, 11, SEEK_CUR);
        fgets(str.GetStr(), sizeof(str.GetStr()), file);
        memcpy(tempstr.GetStr(), str.GetStr(), strlen(str.GetStr()) - 1);
        tempstr.GetStr()[strlen(str.GetStr()) - 1] = '\0';
        client.setFname(tempstr.GetStr());
        fseek(file, 10, SEEK_CUR);
        fgets(str.GetStr(), sizeof(str.GetStr()), file);
        memcpy(tempstr.GetStr(), str.GetStr(), strlen(str.GetStr()) - 1);
        tempstr.GetStr()[strlen(str.GetStr()) - 1] = '\0';
        client.setLname(tempstr.GetStr());
        fseek(file, 13, SEEK_CUR);
        fgets(str.GetStr(), sizeof(str.GetStr()), file);
        memcpy(tempstr.GetStr(), str.GetStr(), strlen(str.GetStr()) - 1);
        tempstr.GetStr()[strlen(str.GetStr()) - 1] = '\0';
        client.setHomeAdress(tempstr.GetStr());
        fseek(file, 14, SEEK_CUR);
        fgets(str.GetStr(), sizeof(str.GetStr()), file);
        memcpy(tempstr.GetStr(), str.GetStr(), strlen(str.GetStr()) - 1);
        tempstr.GetStr()[strlen(str.GetStr()) - 1] = '\0';
        client.setPhoneNumber(GetSize_tNum(tempstr.GetStr()));
        fseek(file, 6, SEEK_CUR);
        fgets(str.GetStr(), sizeof(str.GetStr()), file);
        memcpy(tempstr.GetStr(), str.GetStr(), strlen(str.GetStr()) - 1);
        tempstr.GetStr()[strlen(str.GetStr()) - 1] = '\0';
        client.setItem(tempstr.GetStr());
        list.push_back(client);
        fseek(file, 2, SEEK_CUR);
        letter = fgetc(file);
        fseek(file, -2, SEEK_CUR);
    } while (letter != EOF);
    fclose(file);
}

void SaveList(List<Client>& list) {
    FILE* file;
    file = fopen("C:\\Users\\User\\Downloads\\Client.txt", "a");
    if (!file) return;
    Node<Client>* cur = list.getHead();
    while(cur) {
        fprintf(file, "Firstname: %s\nLastname: %s\nHome adress: %s\nPhone number: %i\nItem: %s\n\n", 
            cur->getValue().getFname(), cur->getValue().getLname(), cur->getValue().getHomeAdress(), cur->getValue().getPhoneNumber(),
            cur->getValue().getItem());
        cur = cur->getNext();
    }
    fclose(file);
}

