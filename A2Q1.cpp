#include <iostream>
#include <cstdlib>
using namespace std;

// Define a structure to represent a leave day in terms of day and month
struct LeaveNode {
    int day, month;
    LeaveNode* next;
};

// Define a custom linked list-based stack
class LeaveList {
private:
    LeaveNode* head;
public:
    LeaveList() {
        head = nullptr;
    }

    // Push a new qualification onto the stack
    void addLeave(int day, int month) {
        LeaveNode* newNode = new LeaveNode;
        newNode->day = day;
        newNode->month = month;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            LeaveNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    //Displays the dates for leave days and counts the leave days
    void displayLeaves() {
        LeaveNode* current = head;
        int counter = 0;
        cout << "Leave Days: ";
        while (current) {
            cout << current->day << "/"<<current->month<<endl;
            current = current->next;
            counter++;
        }
        cout <<"Leave Days: "<<counter<< endl;
    }

    ~LeaveList() {
        while (head) {
            LeaveNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

//Function that returns the index of a selected day in the month array
int find(int arr[], int len, int seek)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == seek) return i;
    }
}

int main() {

    //Array objects for days of the month
    int feb[28] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};
    int even[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int odd[31] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

    LeaveList leaveList;

    while (true) {
        cout << "Leave System Menu:" << endl;
        cout << "1. Select a single day leave" << endl;
        cout << "2. Select multiple-day leaves" << endl;
        cout << "3. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                int singleLeaveDay, Month;
                cout << "Enter a single leave day: "<<endl;
                cout << "Day: ";
                cin >> singleLeaveDay;
                cout << "Month: ";
                cin >> Month;
                leaveList.addLeave(singleLeaveDay, Month);
                }
                break;

            case 2:
                {
                int startDay, endDay, monthStart, monthEnd;
                cout << "Enter the start day for multiple-day leaves: " << endl;
                cout << "Day: ";
                cin >> startDay;
                cout << "Month: ";
                cin >> monthStart;
                cout << "Enter the end day for multiple-day leaves: " << endl;
                cout << "Day: ";
                cin >> endDay;
                cout << "Month: ";
                cin >> monthEnd;

                int period = monthEnd - monthStart;

                /*If-statements for every combonation of either odd, even, or if the month is February to determine the
                days in the month and to add and display the correct dates from the begining to the end of leave*/
                if(period>=1){
                    if(monthStart%2 == 0 && monthEnd%2 == 0){
                        for(int i = find(even,30,startDay); i < 30; i++){
                            leaveList.addLeave(even[i],monthStart);
                        }
                        for(int y = 0; y <= find(even,30,endDay); y++){
                            leaveList.addLeave(odd[y],monthEnd);
                        }
                    }
                    if(monthStart%2 == 1 && monthEnd%2 == 0){
                        for(int i = find(odd,31,startDay); i < 31; i++){
                            leaveList.addLeave(odd[i],monthStart);
                        }
                        for(int y = 0; y <= find(even,30,endDay); y++){
                            leaveList.addLeave(even[y],monthEnd);
                        }
                    }
                    if(monthStart%2 == 1 && monthEnd%2 == 1){
                        for(int i = find(odd,31,startDay); i < 31; i++){
                            leaveList.addLeave(odd[i],monthStart);
                        }
                        for(int y = 0; y <= find(odd,31,endDay); y++){
                            leaveList.addLeave(odd[y],monthEnd);
                        }
                    }
                    if(monthStart%2 == 0 && monthEnd%2 == 1){
                        for(int i = find(even,30,startDay); i < 30; i++){
                            leaveList.addLeave(even[i],monthStart);
                        }
                        for(int y = 0; y <= find(odd,31,endDay); y++){
                            leaveList.addLeave(odd[y],monthEnd);
                        }
                    }
                    if(monthStart%2 == 0 && monthEnd == 2){
                        for(int i = find(even,30,startDay); i < 30; i++){
                            leaveList.addLeave(even[i],monthStart);
                        }
                        for(int y = 0; y <= find(feb,28,endDay); y++){
                            leaveList.addLeave(feb[y],monthEnd);
                        }
                    }
                    if(monthStart%2 == 1 && monthEnd == 2){
                        for(int i = find(odd,31,startDay); i < 31; i++){
                            leaveList.addLeave(even[i],monthStart);
                        }
                        for(int y = 0; y <= find(feb,28,endDay); y++){
                            leaveList.addLeave(feb[y],monthEnd);
                        }
                    }
                    if(monthStart == 2 && monthEnd%2 == 0){
                        for(int i = find(feb,28,startDay); i < 28; i++){
                            leaveList.addLeave(even[i],monthStart);
                        }
                        for(int y = 0; y <= find(even,30,endDay); y++){
                            leaveList.addLeave(even[y],monthEnd);
                        }
                    }
                    if(monthStart == 2 && monthEnd%2 == 1){
                        for(int i = find(feb,28,startDay); i < 28; i++){
                            leaveList.addLeave(even[i],monthStart);
                        }
                        for(int y = 0; y <= find(odd,31,endDay); y++){
                            leaveList.addLeave(odd[y],monthEnd);
                        }
                    }
                    if(monthStart == 2 && monthEnd == 2){
                        for(int i = find(feb,28,startDay); i < 28; i++){
                            leaveList.addLeave(feb[i],monthStart);
                        }
                        for(int y = 0; y <= find(feb,28,endDay); y++){
                            leaveList.addLeave(feb[y],monthEnd);
                        }
                    }
                }
                else{
                    for (int day = startDay; day <= endDay; day++) {
                    leaveList.addLeave(day,monthStart);
                }
                }
                }
                break;

            case 3:
                {
                cout << "Exiting the program." << endl;
                exit(0);
                }

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        leaveList.displayLeaves();
    }

    return 0;
}
