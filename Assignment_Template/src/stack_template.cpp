#include <iostream>
#include <vector>

template <typename T> 
class Stack { 
private: 
    std::vector<T> elements;
 
public: 
    void push(const T& element) {
        elements.push_back(element);
    } 

    void pop() {
        elements.pop_back();
    }

    T top() const {
        elements.at(0);
    }  

    bool isEmpty() const {
        return (size() == 0) ? true: false;
    } 

    size_t size() const {
        return elements.size();
    }
    
    void print_stack() const {
        for(auto e: elements) {
            std::cout << e << std::endl;
        }
    } 
}; 
 