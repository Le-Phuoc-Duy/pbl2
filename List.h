#include <iostream>
using namespace std;
#pragma once
template <class T>
class List
{
private:
    int length;
    struct Node
    {
        T data;
        Node *pNext;
        Node *pPrev;
        Node(T data)
        {
            this->data = data;
            this->pNext = this->pPrev = NULL;
        }
    };
    Node *pHead;
    Node *pTail;

public:
    List()
    {
        this->pHead = this->pTail = NULL;
        this->length = 0;
    }
    ~List()
    {
        for (int i = 0; i < this->length - 2; i++)
        {
            pHead = pHead->pNext;
            delete pHead->pPrev;
        }
        delete pHead;
    }
    Node *contructorNode(T data)
    {
        Node *node = new Node(data);
        return node;
    }
    void push_back(T data)
    {
        Node *node = contructorNode(data);
        if (pHead == NULL)
        {
            this->pHead = this->pTail = node;
            this->length++;
            return;
        }
        this->pTail->pNext = node;
        node->pPrev = this->pTail;
        this->pTail = node;
        this->length++;
    }
    const int getSize()
    {
        return this->length;
    }
    T &operator[](int index)
    {
        Node *node = this->pHead;
        for (int i = 0; i < index; i++)
        {
            node = node->pNext;
        }
        return node->data;
    }
    void erase(int index)
    {
        // Trường hợp vị trí node không tồn tại
        if (index < 0 || index >= this->length)
            return;
        // Trường hợp kích thước danh sách bằng 0
        else if (this->length == 0)
        {
            return;
        }
        // Trường hợp kích thước danh sách bằng 1
        else if (this->length == 1)
        {
            delete pHead;
            pHead = pTail = NULL;
        }
        // Trường hợp node ở vị trí đầu
        else if (index == 0)
        {
            Node *node = pHead->pNext;
            pHead->pNext->pPrev = NULL;
            delete pHead;
            pHead = node;
        }
        // Trường hợp node ở vị trí cuối
        else if (index == this->length - 1)
        {
            Node *node = pTail->pPrev;
            pTail->pPrev->pNext = NULL;
            delete pTail;
            pTail = node;
        }
        // Trường hợp node ở giữa
        else
        {
            Node *node = this->pHead;
            for (int i = 0; i < index; i++)
            {
                node = node->pNext;
            }
            node->pPrev->pNext = node->pNext;
            node->pNext->pPrev = node->pPrev;
            delete node;
        }
        this->length--;
    }
    void clear()
    {
        // Trường hợp kích thước danh sách bằng 0
        if (length == 0)
            return;
        // Trường hợp kích thước danh sách bằng 1
        if (length == 1)
        {
            delete pHead;
            pHead = pTail = NULL;
            length = 0;
            return;
        }
        Node *tempPrev = pHead;
        Node *tempNext = pHead->pNext;
        for (int i = 0; i < length - 1; i++)
        {
            delete tempPrev;
            tempPrev = tempNext;
            tempNext = tempNext->pNext;
        }
        delete tempPrev;
        length = 0;
    }
    void clearData()
    {
        pHead = pTail = NULL;
        length = 0;
    }
};