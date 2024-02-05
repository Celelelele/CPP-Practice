#include <iostream>
#include <queue>
using namespace std;

class Concert {
private:
    queue<int> seatQueue;
    int totalSeats;

public:
    Concert(int capacity) {
        totalSeats = capacity;
    }

    // Adds a student to the queue and assigns them a seat if available.
    void addStudent(int studentID) {
        if (!isTheaterFull()) {
            seatQueue.push(studentID);
            cout << "Student " << studentID << " has been assigned a seat." << endl;
        } else {
            cout << "Sorry, the theater is full. Student " << studentID << " cannot be seated." << endl;
        }
    }

    // Removes the student at the front of the queue and frees up their seat.
    void removeStudent() {
        if (!seatQueue.empty()) {
            int studentID = seatQueue.front();
            seatQueue.pop();
            cout << "Student " << studentID << " has left the theater." << endl;
        } else {
            cout << "The theater is empty. No students to remove." << endl;
        }
    }

    // Returns the number of remaining seats in the theater.
    int getRemainingSeats() {
        return totalSeats - seatQueue.size();
    }

    // Returns a boolean indicating whether the theater is complete or not.
    bool isTheaterFull() {
        return seatQueue.size() >= totalSeats;
    }
};

int main() {
    int theaterCapacity = 50; // Set the theater capacity

    Concert concert(theaterCapacity);

    // Simulate adding students until the theater is full
    for (int i = 1; i <= theaterCapacity + 10; i++) {
        if (!concert.isTheaterFull()) {
            concert.addStudent(i);
        } else {
            cout << "Theater is full. No more students can be added." << endl;
        }
    }

    // Remove some students
    for (int i = 1; i <= 5; i++) {
        concert.removeStudent();
    }

    cout << "Remaining seats: " << concert.getRemainingSeats() << endl;

    return 0;
}
