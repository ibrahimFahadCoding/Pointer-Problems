#include <iostream>


void dereferencingNullptr() {
    int *p = nullptr;
    // Dereferencing a nullptr: attempting to access data through a null pointer
    std::cout << *p << std::endl;  // Undefined behavior, usually causes a segmentation fault
}

void improperInitialization() {
    int *p1, p2;  // Only p1 is a pointer, p2 is an int
    int value = 10;
    p1 = &value;
    // p2 is an int, not a pointer
    // std::cout << *p2 << std::endl; // Error: invalid use of unary '*' on p2
}

void uninitializedPointer() {
    int *p;
    // Uninitialized pointer: using a pointer without assigning it a value
    std::cout << *p << std::endl;  // Undefined behavior, may cause a crash or garbage value
}

void assigningValueToPointer() {
    // Assigning values to pointer variables incorrectly
    //int *p1 = 5;  // Error: invalid conversion from 'int' to 'int*'
}

void pointerDataTypeMismatch() {
    int x = 10;
    //double *p = &x;  // Error: invalid conversion from 'int*' to 'double*'
}

void danglingPointer() {
    int *p_c = nullptr;
    {
        int c = 7;
        int *p_c = &c;
    }
    std::cout << "Dangling Pointer: " << *p_c << std::endl;
}

int main() {
    std::cout << "Dereferencing Nullptr:" << std::endl;
    dereferencingNullptr();

    danglingPointer();

    std::cout << "Improper Initialization:" << std::endl;
    improperInitialization();

    std::cout << "Uninitialized Pointer:" << std::endl;
    uninitializedPointer();

    std::cout << "Assigning Value to Pointer:" << std::endl;
    assigningValueToPointer();

    std::cout << "Pointer Data Type Mismatch:" << std::endl;
    pointerDataTypeMismatch();

    return 0;
}
