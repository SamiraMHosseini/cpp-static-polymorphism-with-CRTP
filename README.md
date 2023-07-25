# Implementing Static Polymorphism Using the Curiously Recurring Template Pattern (CRTP)

# Explanation:

The Curiously Recurring Template Pattern (CRTP) is a technique in C++ that allows for the creation of static polymorphism. 
It involves a derived class passing itself as a template argument to its base class.

In comparison to classical polymorphism, where we typically use base pointers or references to manipulate derived objects, CRTP allows for more compile-time checks, often resulting in more efficient code. 
This is because in CRTP, the base class can call methods on the derived class without needing to know which derived class it is specifically.

In this repository, we have a "Character" base class that defines a common interface for all characters in a game. Each derived class (Warrior, Mage, and Thief) then provides its own implementation of this interface. 
Using CRTP, the base "Character" class is able to call the appropriate method on the derived class, achieving static polymorphism.

In contrast, classical polymorphism would involve virtual function calls with dynamic dispatch, which incurs some runtime overhead. 
The CRTP-based approach avoids this overhead and allows for polymorphic behavior at compile time, without any cost at runtime.

The code examples in this repository demonstrate how to apply CRTP in practice. 
We create various character types that each implement a specific attack method. 
We then have two template functions triggerAttackActionRef and triggerAttackActionPtr that can accept a reference and a pointer to any Character<T> respectively. 
These functions call the performAttack method on the passed character, which internally uses CRTP to call the appropriate executeAttack method on the actual derived class.

# Advantages of CRTP:

Compile-time Polymorphism: More efficient code without the overhead of virtual functions.

Type Safety: Errors caught at compile-time instead of runtime.

No Virtual Table: Saves memory by avoiding the overhead of the virtual table.

# Disadvantages of CRTP:

Code Complexity: CRTP can make code harder to read and maintain.

Limited to Compile-time: Doesn't support runtime polymorphism.

Inflexibility: Once a base class is set in CRTP, it cannot change.

Increase in Binary Size: May lead to larger binary size due to separate copies of code for different template parameters.

Inheritance Limitation: A class can't inherit the same base class template more than once with different template arguments.
