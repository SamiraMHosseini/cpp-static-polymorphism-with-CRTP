#include <iostream>

// This code demonstrates how the Curiously Recurring Template Pattern (CRTP) works 
// in C++. It shows how you can use CRTP to achieve static (compile-time) polymorphism, 
// as an alternative to the more traditional dynamic (run-time) polymorphism achieved 
// with virtual functions.

// The common "Character" interface, which uses the Curiously Recurring Template Pattern (CRTP)
template <typename T>
struct Character
{
    // The general attack function that will be used by all derived classes
    void performAttack()
    {
        // We downcast the 'this' pointer to the derived type T
        T* pDerived = static_cast<T*>(this);
        // Call the actual attack method of the derived class
        pDerived->executeAttack();
    }
};

// Warrior character derived from the base Character interface
struct Warrior : Character<Warrior>
{
    // The Warrior's specific implementation of the attack method
    void executeAttack()
    {
        std::cout << "Warrior uses sword\n";
    }
};

// Mage character derived from the base Character interface
struct Mage : Character<Mage>
{
    // The Mage's specific implementation of the attack method
    void executeAttack()
    {
        std::cout << "Mage uses magic spell\n";
    }
};

// Thief character derived from the base Character interface
struct Thief : Character<Thief>
{
    // The Thief's specific implementation of the attack method
    void executeAttack()
    {
        std::cout << "Thief uses stealth attack\n";
    }
};

// A function that accepts any Character type and triggers their attack action
template <typename T>
void triggerAttackActionRef(Character<T>& character)
{
    
    character.performAttack();
}

// A function that accepts any Character type and triggers their attack action
template <typename T>
void triggerAttackActionPtr(Character<T>* character)
{

    character->performAttack();
}
int main()
{
    // Create a Warrior instance and trigger its attack action
    Warrior warrior;
    triggerAttackActionRef<Warrior>(warrior);
    Mage mage;
    triggerAttackActionPtr<Mage>(&mage);

}
