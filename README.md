Example of the Strategy Pattern in C++
Problem Statement:

Suppose you are working on a data processing application, and you need to implement a sorting feature that allows users to sort data in various ways. You decide to use the Strategy Pattern to handle different sorting algorithms.


Implementation of the Strategy Pattern in C++
Key Component of Strategy Patterns :
Context: The class that contains a reference to the strategy interface and is responsible for executing the algorithm.
Strategy Interface: An interface or abstract class that declares the method(s) for the algorithm. Different strategies implement this interface.
Concrete Strategies: The different algorithms that implement the strategy interface.

Step 1: Define the Strategy Interface
```
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& arr) = 0;
};
```

Step 2: Implement Concrete Strategies
```
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        // Implement Bubble Sort algorithm
    }
};

class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        // Implement Quick Sort algorithm
    }
};

// Add more sorting algorithms as needed
```

Step 3: Create the Context
```
class SortContext {
private:
    SortingStrategy* strategy;
​
public:
    void setStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }

    void executeStrategy(std::vector<int>& arr) {
        strategy->sort(arr);
    }
};
```

Step 4: Utilize the Strategy Pattern
```
int main() {
    std::vector<int> data = {5, 2, 7, 1, 9};
    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;

    context.setStrategy(&bubbleSort);
    context.executeStrategy(data); // Executes Bubble Sort

    context.setStrategy(&quickSort);
    context.executeStrategy(data); // Executes Quick Sort

    return 0;
}
```
Overall Code for the above Example:

```
#include <bits/stdc++.h>
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& arr) = 0;
};
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override
    {
        // Implement Bubble Sort algorithm
    }
};

class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override
    {
        // Implement Quick Sort algorithm
    }
};

// Add more sorting algorithms as needed

class SortContext {
private:
    SortingStrategy* strategy;

public:
    void setStrategy(SortingStrategy* strategy)
    {
        this->strategy = strategy;
    }

    void executeStrategy(std::vector<int>& arr)
    {
        strategy->sort(arr);
    }
};
int main()
{
    std::vector<int> data = { 5, 2, 7, 1, 9 };

    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;

    context.setStrategy(&bubbleSort);
    context.executeStrategy(data); // Executes Bubble Sort

    context.setStrategy(&quickSort);
    context.executeStrategy(data); // Executes Quick Sort

    return 0;
}
```
Diagrammatic Representation of Strategy Patterns in C++

![S](https://github.com/user-attachments/assets/a12eea2a-bfb2-4d00-98f6-22053ec105f0)

Strategy Pattern allows the client code (in this case, the Context class) to choose between different sorting algorithms (represented by BubbleSort and QuickSort) at runtime, without modifying the client's code.
This promotes flexibility because you can switch between different sorting algorithms without altering the client's implementation.
It also promotes code reusability because you can add new sorting algorithms (concrete strategies) by implementing the SortingStrategy interface without modifying the existing code.
The use of an abstract class or interface (SortingStrategy) ensures that all concrete strategies have a consistent interface (sort(arr) method) that can be used interchangeably by the Context class.

Advantages of the Strategy Pattern in C++ Design Patterns
Flexibility: Easily switch between different algorithms at runtime.
Code Reusability: Strategies can be reused across different contexts.
Promotes Single Responsibility: Each strategy focuses on a specific algorithm.
Disadvantages of the Strategy Pattern in C++ Design Patterns
May lead to an increased number of classes, which can be overwhelming for small-scale applications.
Context and the Strategy classes normally communicate through the interface specified by the abstract Strategy base class. Strategy base class must expose interface for all the required behaviours, which some concrete Strategy classes might not implement.
In most cases, the application configures the Context with the required Strategy object. Therefore, the application needs to create and maintain two objects in place of one.
Become a System Design expert and also get 90% fee refund on completing 90% course in 90 days! Take the Three 90 Challenge today.

Step into the Three 90 Challenge – 90 days to push limits, break barriers, and become the best version of yourself! Don't miss your chance to upskill and get 90% refund. What more motivation do you need? Start the challenge right away!
