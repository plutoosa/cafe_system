#include <iostream>
#include <fstream> //library required for writing the bill details in a file

using namespace std;

int main() {
    string name, surname;
    const int maxItems = 8;
    int selectedItems = 0;
    int choice;
    double totalCost = 0.0;

    // Array names
    string itemNames[maxItems] = { "Coffee", "Sandwich", "Salad", "Juice", "Muffin", "Pizza Slice", "Soup", "Burger" };
    //Array prices
    double prices[maxItems] = { 15.00, 30.00, 25.00, 10.00, 20.00, 35.00, 18.00, 40.00 };
    cout << "Enter your Name: ";
    cin >> name;

    cout << "Enter your Surname: ";
    cin >> surname;

    while (selectedItems < maxItems) {
        // Display the menu
        cout << "Menu:\n";
        for (int i = 0; i < maxItems; i++) {
            cout << i + 1 << ". " << itemNames[i] << " - R" << prices[i] << endl;
        }
        cout << "0. Exit\n";

        // Ask user for their choice
        cout << "Select an item (or 0 to exit): ";
        cin >> choice;

        // If user chooses to exit
        if (choice == 0) {
            cout << "Exiting selection.\n";
            break;
        }

        // Validate the choice
        if (choice >= 1 && choice <= maxItems) { // && checks if both conditions are true
            cout << "You selected " << itemNames[choice - 1] << " which costs R" << prices[choice - 1] << ".\n";
            totalCost += prices[choice - 1];  // Add selected item's price to total
            selectedItems++; // "++" increases the value of an operator by 1
        }
        else {
            cout << "Invalid choice. Please select a valid option.\n";
        }

        // Add discount if totalCost > 100
        if (totalCost > 100) {
            totalCost = totalCost - (totalCost * 0.10);
        }

        // Let user know how many items they have selected
        cout << "You have selected " << selectedItems << " out of " << maxItems << " items.\n";
    }

    // Alert users of number of items they have selected
    cout << "You selected " << selectedItems << " items in total.\n";

    //Display total cost
    cout << "You selected " << selectedItems << " items in total.\n";
    cout << "The total cost is: R" << totalCost << ".\n";

    if (totalCost > 100) {
        
        cout << "Applied Discount: " << " -" << " 10%" << endl;

    }
    else
        cout << "No discount applied" << endl;


    ofstream file("CafeteriaBill.txt");

    if (file.is_open()) {
        file << "Name: " << name << "\n" << "Surname: " << surname << "\n" << "Total Cost : " << totalCost;

        cout << "The Bill for the purchased items has been written to the CafeteriaBill file";

    }
    else {
        cout << "Error. File could not be opened" << endl;
    }

    return 0;

 
}
