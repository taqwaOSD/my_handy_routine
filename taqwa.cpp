#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tasklist {
private:
    vector<string> Tasklist;
    vector<bool> isDone;

public:
    void addToTasklist(const string& nameofwork) {
       
        for (const string& work : Tasklist) {
            if (work == nameofwork) {
                cout << "Already exists in list\n";
                return;
            }
        }

        Tasklist.push_back(nameofwork);
        isDone.push_back(false);
        cout << "Work added to the Tasklist.\n";
    }

    void markDone(int index) {
        if (index >= 0 && index < Tasklist.size()) {
            isDone[index] = true;
        } else {
            cout << "Invalid index. Please try again.\n";
        }
    }

    void showUndoneWorks() {
        bool undoneFound = false;
        for (size_t i = 0; i < Tasklist.size(); ++i) {
            if (!isDone[i]) {
                cout << i << ". " << Tasklist[i] << endl;
                undoneFound = true;
            }
        }
        if (!undoneFound) {
            cout << "No undone works in the Tasklist.\n";
        }
    }

    void showTasklist() {
        if (Tasklist.empty()) {
            cout << "Tasklist is empty.\n";
            return;
        }

        cout << "Works in the Tasklist:\n";
        for (size_t i = 0; i < Tasklist.size(); ++i) {
            cout << i << ". " << Tasklist[i] << " (" << (isDone[i] ? "Done" : "Undone") << ")" << endl;
        }
    }

    void removeFromTasklist(int index) {
        if (index >= 0 && index < Tasklist.size()) {
            Tasklist.erase(Tasklist.begin() + index);
            isDone.erase(isDone.begin() + index);
            cout << "Work removed from the Tasklist.\n";
        } else {
            cout << "Invalid index. Please try again.\n";
        }
    }
};

int main() {
    Tasklist tracker;
    int choice;

    do {
        cout << "MY HANDY ROUTINE MANAGER\n"
             << "Options:\n"
             << "1. Add to Tasklist\n"
             << "2. Update task as done\n"
             << "3. Show undone works\n"
             << "4. Show Tasklist\n"
             << "5. Remove from Tasklist\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string nameofwork;
                cout << "Enter the name of the work to add to the Tasklist: ";
                cin.ignore(); 
                getline(cin, nameofwork);
                tracker.addToTasklist(nameofwork);
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the work to mark as done: ";
                cin >> index;
                tracker.markDone(index);
                break;
            }
            case 3:
                cout << "Undone works in the Tasklist:\n";
                tracker.showUndoneWorks();
                break;
            case 4:
                tracker.showTasklist();
                break;
            case 5: {
                int index;
                cout << "Enter the index to remove from list: ";
                cin >> index;
                tracker.removeFromTasklist(index);
                break;
            }
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

