
#include <iostream>
using namespace std;

template <typename T>
class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray<T>&);
    ~ListArray();

    bool insertBefore(const T&);
    bool insertAfter(const T&);
    bool get(T&) const;
    bool remove(T&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray<T>& operator = (const ListArray<T>&);

    template <typename S>
    friend ostream& operator << (ostream&, const ListArray<S>&);

private:
    T *data;
    int cursor;
    int actual;
    int size;
};

template <typename T>
ListArray<T>::ListArray (int sentSize)
{
    actual = 0;
    size = sentSize;

    data = new T[size];

    cursor = 0;

}

template <typename T>
ListArray<T>::ListArray (const ListArray<T>& sentList)
{
    actual = sentList.actual;
    cursor = sentList.cursor;
    size = sentList.size;

    data = new T[size];

    T *thisTrav = data;
    T *sentTrav = sentList.data;

    for (int i = 0; i < actual; i++)
    {
        *thisTrav = *sentTrav;

        thisTrav++;
        sentTrav++;

    }

    thisTrav = NULL;
    sentTrav = NULL;

}

template <typename T>
ListArray<T>::~ListArray ()
{
    delete[] data;
    data = NULL;

}

//Functions
template <typename T>
bool ListArray<T>::insertBefore (const T& sentValue)
{
    if (actual == size) //Full
    {
        return false;

    } else if (actual == 0)
    {
        T *onTrav = data;

        (*data) = sentValue;

        actual++;

        onTrav = NULL;

        return true;

    } else
    {
        T *onTrav = data;
        T *nextTrav = data;

        nextTrav++;

        //cout << "Hi" << endl;

        for (int i = 0; i < (actual - 1); i++) //Move to end of the array
        {
            onTrav++;
            nextTrav++;

        }

        //cout << "moved" << endl;

        for (int i = (actual - 1); i >= cursor; i--) //copy values after and including the cursor down
        {
            *nextTrav = *onTrav;

            onTrav--;
            nextTrav--;

        }

        //cout << "copied" << endl;

        onTrav = data;

        for (int i = 0; i < (cursor); i++) //Move the pointer to the cursor
        {
            onTrav++;

        }

        *onTrav = sentValue;

        //cursor++;
        actual++;

        onTrav = NULL;
        nextTrav = NULL;

        return true;

    }
}

template <typename T>
bool ListArray<T>::insertAfter(const T& sentValue)
{
    if (size == actual)
    {
        return false;

    } else if (actual == 0)
    {
        T *onTrav = data;

        (*data) = sentValue;

        actual++;

        onTrav = NULL;

        return true;

    }else
    {
        T *onTrav = data;
        T *nextTrav = data;

        nextTrav++;

        for (int i = 0; i < (actual - 1); i++) //Move to end of the array
        {
            onTrav++;
            nextTrav++;

        }

        //cout << "moved to end of array" << endl;

        for (int i = (actual - 1); i > cursor; i--) //copy values after and including the cursor down
        {
            *nextTrav = *onTrav;

            onTrav--;
            nextTrav--;

        }

        //cout << "copied" << endl;

        onTrav = data;

        for (int i = 0; i < (cursor); i++) //Move the pointer to the cursor
        {
            onTrav++;

        }

        //cout << "moved to cursor" << endl;

        onTrav++;

        *onTrav = sentValue;

        //cursor += 0;
        actual++;
        //cursor--;

        onTrav = NULL;
        nextTrav = NULL;

        //cout << "Ins Af done" << endl;

        return true;

    }
}

template <typename T>
bool ListArray<T>::get(T& returnVal) const
{
    if (actual != 0)
    {
        T *thisTrav = data;

        for (int i = 0; i < cursor; i++)
        {
            thisTrav++;

        }

        returnVal = *thisTrav;

        thisTrav = NULL;

        return true;

    } else
    {
        return false;

    }
}

template <typename T>
bool ListArray<T>::remove(T& returnVal)
{
    if (actual != 0)
    {
        T *thisTrav = data;

        for (int i = 0; i < (cursor); i++) //Move to cursor
        {
            thisTrav++;

        }

        returnVal = *thisTrav;

        T *nextTrav = thisTrav;

        for (int i = 0; i < (actual - (cursor + 1)); i++) //Copy values
        {
            *thisTrav = *nextTrav;

            thisTrav++;
            nextTrav++;

        }

        actual--;
        cursor--;

        thisTrav = NULL;
        nextTrav = NULL;

        return true;

    } else
    {
        return false;

    }
}

template <typename T>
void ListArray<T>::clear ()
{
    delete[] data;
    data = NULL;

    data = new T[size];
    cursor = 0;
    actual = 0;

    return;

}

template <typename T>
bool ListArray<T>::goToBeginning ()
{
    if (cursor != 0)
    {
        cursor = 0;

        return true;

    } else
    {
        return false;

    }
}

template <typename T>
bool ListArray<T>::goToEnd ()
{
    if (cursor != (actual - 1))
    {
        cursor = (actual - 1);

        return true;

    } else
    {
        return false;

    }

}

template <typename T>
bool ListArray<T>::goToNext ()
{
    if (cursor != (actual - 1))
    {
        cursor++;

        return true;

    } else
    {
        return false;

    }
}

template <typename T>
bool ListArray<T>::goToPrior ()
{
    if (cursor != 0)
    {
        cursor--;

        return true;

    } else
    {
        return false;

    }
}

template <typename T>
bool ListArray<T>::isEmpty () const
{
    if (actual == 0)
    {
        return true;

    } else
    {
        return false;

    }
}

template <typename T>
bool ListArray<T>::isFull () const
{
    if (actual == size)
    {
        return true;

    } else
    {
        return false;

    }

}

template <typename T>
ListArray<T>& ListArray<T>::operator = (const ListArray<T>& sentList)
{
    actual = sentList.actual;
    cursor = sentList.cursor;
    size = sentList.size;

    delete[] data;

    data = new T[size];

    T *thisTrav = data;
    T *sentTrav = sentList.data;

    for (int i = 0; i < actual; i++)
    {
        *thisTrav = *sentTrav;

        thisTrav++;
        sentTrav++;

    }

    thisTrav = NULL;
    sentTrav = NULL;

    return *this;

}

template <typename S>
ostream& operator<< (ostream& os, const ListArray<S>& sentList)
{
    S *thisTrav = sentList.data;

    os << "[";

    for (int i = 0; i < sentList.actual; i++)
    {   
        if (i == (sentList.cursor - 0))
        {
            os << "(Cursor) ";

        }

        if (i == (sentList.actual - 1))
        {
            os << *thisTrav;

        } else
        {
            os << *thisTrav << ", ";

        }

        thisTrav++;

    }

    os << "]";

    //os << " Cursor: " << sentList.cursor;

    thisTrav = NULL;

    return os;

}

/*
    2 of 9

    -   Array based stack
        -   top stay, top move up, top move down

    -   Node based stack

    -   Array based queue
        -   front, stay, wrap

    -   node based queue
    -   array based list
    -   node based list

    Other topics:
        Inheritence and polymorhphism
        Gary Buscey


*/