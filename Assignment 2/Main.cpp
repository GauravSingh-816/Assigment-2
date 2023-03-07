#include <iostream>
#include "Single_Linked_List.h"
#include "Professional.h"
#include "Nonprofessional.h"
using namespace std;

int main() {

    // Test Single_Linked_List
    Single_Linked_List<int> list;
    list.push_front(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.insert(2, 99);
    list.remove(1);
    cout << "List size: " << list.size() << endl;
    cout << "List contents: ";
    for (size_t i = 0; i < list.size(); ++i) {
    cout << list[i] << " ";
}
cout << endl;

// Test Professional and Nonprofessional classes
Professional prof(5000, 20);
Nonprofessional nonprof(15);
nonprof.add_hours(40);

cout << "Professional weekly salary: " << prof.weekly_salary() << endl;
cout << "Professional health care contribution: " << prof.health_care() << endl;
cout << "Professional vacation days earned: " << prof.vacation_days() << endl;

cout << "Nonprofessional weekly salary: " << nonprof.weekly_salary() << endl;
cout << "Nonprofessional health care contribution: " << nonprof.health_care() << endl;
cout << "Nonprofessional vacation days earned: " << nonprof.vacation_days() << endl;

return 0;
}