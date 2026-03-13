/**
 * @file deque.cpp
 * @description Implementations for PA2, Deque class
 * @author (your CWLs)
**/

template <class T>
Deque<T>::Deque() {
    n1 = 0;
    n2 = -1;
}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
**/
template <class T>
void Deque<T>::PushR(T newItem) {
    data.push_back(newItem);
    n2++;
}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes. 
 *
 * @return The item that used to be at the left of the Deque.
**/
template <class T>
T Deque<T>::PopL() {
    T removed = data[n1];
    n1++;

    if(n1 > 0 && n2 - n1 + 1 <= n1) {
        vector<T> temp;
        for(int i = n1; i <= n2; i++) {
            temp.push_back(data[i]);
        }
        data = temp;
        n2 = n2 - n1;
        n1 = 0;
    }

    if(n1 > n2) {
        n1 = 0;
        n2 = -1;
        data.clear();
    }
    
    return removed;
}
/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Deque.
**/
template <class T>
T Deque<T>::PopR() {
    T removed = data[n2];
    data.pop_back();
    n2--;
    if(n1 > 0 && n2 - n1 + 1 <= n1) {
        vector<T> temp;
        for(int i = n1; i <= n2; i++) {
            temp.push_back(data[i]);
        }
        data = temp;
        n2 = n2 - n1;
        n1 = 0;
    }
    if(n1 > n2) {
        n1 = 0;
        n2 = -1;
        data.clear();
    }
    return removed;
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike PopL(), this operation does not alter the deque.
 *
 * @return The item at the front of the deque.
**/
template <class T>
T Deque<T>::PeekL() {
    /* YOUR CODE HERE! */
    T peeked;
    peeked = data[n1];
    return peeked;
}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike PopR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
**/
template <class T>
T Deque<T>::PeekR() {
    /* YOUR CODE HERE! */
    T peeked;
    peeked = data[n2];
    return peeked;
}

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
**/
template <class T>
bool Deque<T>::IsEmpty() const {
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return n1>n2;
}
