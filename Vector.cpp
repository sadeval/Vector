#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

using namespace std;

class ArrayList
{
    vector<int> data;

public:
    ArrayList() {}

    void PushBack(int value)
    {
        data.push_back(value);
    }

    void PushFront(int value)
    {
        data.insert(data.begin(), value);
    }

    void Clear()
    {
        data.clear();
    }

    bool IsEmpty() const
    {
        return data.empty();
    }

    void Print() const
    {
        if (IsEmpty()) {
            cout << "Vector is empty.\n";
            return;
        }

        for (int val : data) {
            cout << val << " ";
        }
        cout << "\n";
    }

    void Remove(int value)
    {
        data.erase(remove(data.begin(), data.end(), value), data.end());
    }

    void Reverse()
    {
        reverse(data.begin(), data.end());
    }

    void SortDesc()
    {
        sort(data.begin(), data.end(), greater<int>());
    }

    void RandomFill(unsigned int count, int minVal, int maxVal)
    {
        srand(time(nullptr));
        for (unsigned int i = 0; i < count; i++) {
            data.push_back(minVal + rand() % (maxVal - minVal + 1));
        }
    }
    void RandomlyUserInput()
    {
        unsigned int count;
        int minVal, maxVal;
        cout << "Enter the number of elements: ";
        cin >> count;
        cout << "Enter the minimum value: ";
        cin >> minVal;
        cout << "Enter the maximum value: ";
        cin >> maxVal;
        RandomFill(count, minVal, maxVal);
    }

    void RemoveValue() {
        int removeVal;
        cout << "\nEnter a value to remove: ";
        cin >> removeVal;
        Remove(removeVal);
    }

    int LastIndexOf(int value) const
    {
        for (int i = data.size() - 1; i >= 0; i--) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    unsigned int GetSize() const 
    {
        return data.size();
    }
    unsigned int GetCapacity() const 
    {
        return data.capacity();
    }
};

int main()
{
    ArrayList ar;
    ar.Print();

    ar.PushBack(1);
    ar.Print();

    ar.PushBack(2);
    ar.Print();

    ar.PushBack(3);
    ar.Print();

    ar.PushFront(4);
    ar.Print();

    ar.Clear();
    ar.Print();

    ar.RandomlyUserInput();
    cout << "\nRandomly filled array: " << "\n";
    ar.Print();
    cout << "\nSize: " << ar.GetSize() << ", Capacity: " << ar.GetCapacity() << "\n";


    ar.Reverse();
    cout << "\nReverse: " << "\n";
    ar.Print();

    ar.SortDesc();
    cout << "\nSort: " << "\n";
    ar.Print();

    ar.RemoveValue();
    cout << "\nAfter removing: " << "\n";
    ar.Print();

    int lastIndex = ar.LastIndexOf(16);
    cout << "\nLast index of 16 is: " << lastIndex << "\n";
}
