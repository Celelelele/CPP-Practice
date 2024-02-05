#include <iostream>
using namespace std;

// Define a structure to represent a qualification and its frequency
struct Qualification {
    string name;
    int frequency;
    Qualification* next;

    //Reference constructor
    Qualification(string _name, int _frequency) : name(_name), frequency(_frequency), next(nullptr) {}
};

// Define a custom linked list-based stack
class Stack {
private:
    Qualification* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    // Push a new qualification onto the stack
    void push(string name, int frequency) {
        Qualification* newQualification = new Qualification(name, frequency);
        newQualification->next = top;
        top = newQualification;
        size++;
    }

    // Pop the top qualification from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Qualification* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // Peek at the top qualification without removing it
    Qualification* peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return nullptr;
        }
        return top;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get the size of the stack
    int getSize() {
        return size;
    }

    // Display all qualifications in the stack
    void displayStack() {
        Qualification* current = top;
        while (current != nullptr) {
            cout << current->name << ": " << current->frequency << endl;
            current = current->next;
        }
    }

    void cummulativeFreq(){
        int total = 0;
        Qualification* member = top;

        while (member != nullptr){
            total += member->frequency;
            member = member->next;
        }
        cout<<"Cummalive Frequency of Students: "<<total<<endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack qualificationStack;

    qualificationStack.push("IS622", 50);
    qualificationStack.push("ST600", 30);
    qualificationStack.push("BD600", 20);


    qualificationStack.displayStack();
    qualificationStack.cummulativeFreq();

    return 0;
}
