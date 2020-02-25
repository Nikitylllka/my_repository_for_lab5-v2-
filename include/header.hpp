// Copyright 2018 Nikitylllka <m.bonduel@ya.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <cstdlib>

#define error_of_empty_stack -1
#define error_of_memory -2

using std::cout;
using std::endl;

template<typename T>
class stack2 {
public:
    T *Head;
    T *Top;
    int i = 0;

    stack2() {
        Head = nullptr;
        Top = nullptr;
    }

    template<typename ... Args>
    void push_emplace(Args &&... value) {
        T obj(value ...);
        Head = static_cast<T *>(realloc(Head, (i + 1) * sizeof(obj)));
        if (!Head)
        {
            exit(error_of_memory);
        }
        Top = &(Head)[i];
        Head[i] = obj;
        cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
        cout << "            [" << (i) << "] = " << *Top << endl;
        i++;
    }

    void push(T &&value) {
        if (i < 10) {
            Head = static_cast<T *>(realloc(Head, (i + 1) * sizeof(T)));
            if (!Head)
            {
                exit(error_of_memory);
            }
            Top = &(Head)[i];
            Head[i] = value;
            cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
            cout << "            [" << (i) << "] = " << *Top << endl;
            i++;

        } else {
            cout << "Stack is overflow" << endl;
        }
    }

    const T &head() const {
        if (i == 0) {
            cout << "stack is empty ";
            exit(error_of_empty_stack);
        }
        return *Top;
    }

    T pop() {
        if (i > 0) {
            T value_after_pop;
            value_after_pop = Head[i - 1];
            Head = static_cast<T *>(realloc(Head, (i - 1) * sizeof(T)));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return value_after_pop;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " <<
                 Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = " <<
                 *Top << endl;
            i--;
            return value_after_pop;
        } else {
            cout << "Error stack" << endl;
            exit(error_of_empty_stack);
        }
    }

    ~stack2() {
        while (i > 0) {
            Head = static_cast<T *>(realloc(Head, (i - 1) * sizeof(T)));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " <<
                 Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = "
                 << *Top << endl;
            i--;
        }
    }
};

template<typename T>
class stack {
public:
    T *Head;
    T *Top;
    int i = 0;

    stack() {
        Head = nullptr;
        Top = nullptr;
    }

    void push(T &&value) {
        Head = static_cast<T *>(realloc(Head, (i + 1) * sizeof(T)));
        if (!Head)
        {
            exit(error_of_memory);
        }
        Top = &(Head)[i];
        Head[i] = value;
        cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
        cout << "            [" << (i) << "] = " << *Top << endl;
        i++;
    }

    void push(const T &value) {
        Head = static_cast<T *>(realloc(Head, (i + 1) * sizeof(T)));
        if (!Head)
        {
            exit(error_of_memory);
        }
        Top = &(Head)[i];
        Head[i] = value;
        cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
        cout << "            [" << (i) << "] = " << *Top << endl;
        i++;
    }

    void pop() {
        if (i > 0) {
            Head = static_cast<T *>(realloc(Head, (i - 1) * sizeof(T)));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " <<
                 Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = " <<
                 *Top << endl;
            i--;
        } else if (i < 1) {
            cout << "Error stack" << endl;
        }
    }

    const T &head() const {
        if (i == 0) {
            cout << "stack is empty ";
            exit(error_of_empty_stack);
        }
        return *Top;
    }

    ~stack() {
        while (i > 0) {
            Head = static_cast<T *>(realloc(Head, (i - 1) * sizeof(T)));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " <<
                 Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = " <<
                 *Top << endl;
            i--;
        }
    }
};

#endif // INCLUDE_HEADER_HPP_
