#include <iostream>

using namespace std;

#define MAX 100

template <typename T>
class queue {
    T data[MAX];
    int start;
    int finish;
public:
    queue() {
        start = 0;
        finish = 0;
    }

    void push(T n) {
        data[finish] = n;
        finish++;
    }

    T pop() {
        if (start < finish) {
            T a = data[start];
            start++;
            return a;
        }
        else
            return NULL;
    }

    T front() {
        return data[start];
    }

    T size() {
        return finish - start;
    }

    void clear() {
        finish = 0;
        start = 0;
    }

};