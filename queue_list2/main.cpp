#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    struct Element
    {
        T data;
        Element* Next;
        Element* Prev;
    };

    Element* Head;
    Element* Tail;
    int size;

public:
    bool IsEmpty() const
    {
        return size == 0;
    }

    Queue() : size(0)
    {
        Head = Tail = NULL;
    }

    ~Queue()
    {
        while (!IsEmpty())
        {
            Extract();
        }
    }

    void Add(const T& data)
    {
        Element* temp = new Element;
        temp->Next = nullptr;
        temp->data = data;
        temp->Prev = Tail;

        if (Tail != nullptr) Tail->Next = temp;

        if (size == 0) Head = Tail = temp;
        else { Tail = temp; }

        size++;
    }

    void Extract()
    {
        if (IsEmpty()) return;

        Element* temp = Head;
        Head = temp->Next;
        if (Head!= nullptr) 
        {
            Head->Prev = nullptr;
        }
        else 
        {
            Tail = nullptr; 
        }
        delete temp;

        size--;
    }

    int GetSize() const
    {
        return size;
    }

    void Print() const
    {
        if (size != 0)
        {
            Element* temp = Head;
            while (temp->Next != nullptr)
            {
                cout << temp->data << ' ';
                temp = temp->Next;
            }

            cout << temp->data << " \n";
        }
    }
};

int main()
{
    Queue<int> queue;

    for (int i = 0; i < 5; i++)
    {
        queue.Add(i);
    }
    queue.Print();
    cout << "Size: " << queue.GetSize() << endl << endl;

    queue.Extract();
    queue.Extract();
    queue.Print();
    cout << "Size: " << queue.GetSize() << endl << endl;

    return 0;
}