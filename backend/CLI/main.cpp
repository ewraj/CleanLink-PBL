#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n===== CLEANLINK =====\n";
    cout << "1. Report Waste Spot\n";
    cout << "2. View Waste Spots\n";
    cout << "3. View Campaigns\n";
    cout << "4. Donate\n";
    cout << "5. View Jobs\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Report Waste Spot\n";
                break;

            case 2:
                cout << "View Waste Spots\n";
                break;

            case 3:
                cout << "View Campaigns\n";
                break;

            case 4:
                cout << "Donate\n";
                break;

            case 5:
                cout << "View Jobs\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}