/**
 * @file stack.cpp
 * @description Implementations for PA2, Stack class
 * @author (your CWLs)
**/

/**
 * Adds the parameter object to the top of the Stack. 
 *
 * @note This function must be O(1)!
 *
 * @param newItem The object to be added to the Stack.
**/
template<class T>
void Stack<T>::Push(T newItem) {
    /* YOUR CODE HERE! */

}

/**
 * Removes the object on top of the Stack, and returns it. 
 * You may assume this function
 * is only called when the Stack is not empty.
 *
 * @note This function must be O(1)!
 *
 * @return The element that used to be at the top of the Stack.
**/
template <class T>
T Stack<T>::Pop() {
    /* YOUR CODE HERE! */
    T removed;

    return removed;
}

/**
 * Finds the object on top of the Stack, and returns it to the caller.
 * Unlike Pop(), this operation does not alter the Stack itself. 
 * You may assume this function is only
 * called when the Stack is not empty.
 *
 * @return The value of the element at the top of the Stack.
**/
template <class T>
T Stack<T>::Peek() {
    /* YOUR CODE HERE! */
    T peeked;

    return peeked;
}

/**
 * Determines if the Stack is empty.
 *
 * @note This function must be O(1)! 
 *
 * @return Whether or not the stack is empty (bool).
**/
template <class T>
bool Stack<T>::IsEmpty() const {
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return true;
}
