#include <iostream> 
#include <vector>
#include "stack_template.cpp"

template <typename T> 
void printStack(const Stack<T>& stack) {
    if (!stack.isEmpty()) {
        stack.print_stack();
    }
}

int main() { 
    Stack<int> intStack; 
    intStack.push(10); 
    intStack.push(20); 
    intStack.push(30); 
 
    std::cout << "Integer Stack:" << std::endl; 
    printStack(intStack); // Output: 10 20 30 
 
    Stack<std::string> stringStack; 
    stringStack.push("Hello"); 
    stringStack.push("World"); 
 
    std::cout << "String Stack:" << std::endl; 
    printStack(stringStack); // Output: Hello World 
 
    return 0; 
} 
