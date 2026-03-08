/**
 * @file deque.cpp
 * @description Implementations for PA2, Deque class
 * @author (your CWLs)
**/

template <class T>
Deque<T>::Deque() {
    /* YOUR CODE HERE! */

}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
**/
template <class T>
void Deque<T>::PushR(T newItem) {
    /* YOUR CODE HERE! */

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
    /* YOUR CODE HERE! */
    T removed;

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
    /* YOUR CODE HERE! */
    T removed;

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
    return true;
}
