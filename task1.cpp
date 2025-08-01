#include <iostream>
using namespace std;

int main() {
    // Display the menu
    cout << "========== MENU ==========\n";
    cout << "1. Burger     - Rs.200\n";
    cout << "2. Rice       - Rs.300\n";
    cout << "3. Pizza      - Rs.500\n";
    cout << "4. Biryani    - Rs.250\n";
    cout << "5. Sandwich   - Rs.150\n";
    cout << "6. Fries      - Rs.100\n";
    cout << "7. Cold Drink - Rs.80\n";
    cout << "==========================\n";

    int firstItemNumber, secondItemNumber, thirdItemNumber;
    int firstItemQuantity, secondItemQuantity, thirdItemQuantity;
    int firstItemPrice = 0, secondItemPrice = 0, thirdItemPrice = 0;
    string firstItemName, secondItemName, thirdItemName;

    // First item input
    cout << "Enter first item number: ";
    cin >> firstItemNumber;
    cout << "Enter quantity: ";
    cin >> firstItemQuantity;

    if (firstItemNumber == 1) {
        firstItemName = "Burger";
        firstItemPrice = 200;
    } else if (firstItemNumber == 2) {
        firstItemName = "Rice";
        firstItemPrice = 300;
    } else if (firstItemNumber == 3) {
        firstItemName = "Pizza";
        firstItemPrice = 500;
    } else if (firstItemNumber == 4) {
        firstItemName = "Biryani";
        firstItemPrice = 250;
    } else if (firstItemNumber == 5) {
        firstItemName = "Sandwich";
        firstItemPrice = 150;
    } else if (firstItemNumber == 6) {
        firstItemName = "Fries";
        firstItemPrice = 100;
    } else if (firstItemNumber == 7) {
        firstItemName = "Cold Drink";
        firstItemPrice = 80;
    } else {
        cout << "Invalid item number!\n";
        return 0;
    }

    // Second item input
    cout << "Enter second item number: ";
    cin >> secondItemNumber;
    cout << "Enter quantity: ";
    cin >> secondItemQuantity;

    if (secondItemNumber == 1) {
        secondItemName = "Burger";
        secondItemPrice = 200;
    } else if (secondItemNumber == 2) {
        secondItemName = "Rice";
        secondItemPrice = 300;
    } else if (secondItemNumber == 3) {
        secondItemName = "Pizza";
        secondItemPrice = 500;
    } else if (secondItemNumber == 4) {
        secondItemName = "Biryani";
        secondItemPrice = 250;
    } else if (secondItemNumber == 5) {
        secondItemName = "Sandwich";
        secondItemPrice = 150;
    } else if (secondItemNumber == 6) {
        secondItemName = "Fries";
        secondItemPrice = 100;
    } else if (secondItemNumber == 7) {
        secondItemName = "Cold Drink";
        secondItemPrice = 80;
    } else {
        cout << "Invalid item number!\n";
        return 0;
    }

    // Third item input
    cout << "Enter third item number: ";
    cin >> thirdItemNumber;
    cout << "Enter quantity: ";
    cin >> thirdItemQuantity;

    if (thirdItemNumber == 1) {
        thirdItemName = "Burger";
        thirdItemPrice = 200;
    } else if (thirdItemNumber == 2) {
        thirdItemName = "Rice";
        thirdItemPrice = 300;
    } else if (thirdItemNumber == 3) {
        thirdItemName = "Pizza";
        thirdItemPrice = 500;
    } else if (thirdItemNumber == 4) {
        thirdItemName = "Biryani";
        thirdItemPrice = 250;
    } else if (thirdItemNumber == 5) {
        thirdItemName = "Sandwich";
        thirdItemPrice = 150;
    } else if (thirdItemNumber == 6) {
        thirdItemName = "Fries";
        thirdItemPrice = 100;
    } else if (thirdItemNumber == 7) {
        thirdItemName = "Cold Drink";
        thirdItemPrice = 80;
    } else {
        cout << "Invalid item number!\n";
        return 0;
    }

    // Calculate totals
    int firstItemTotal = firstItemPrice * firstItemQuantity;
    int secondItemTotal = secondItemPrice * secondItemQuantity;
    int thirdItemTotal = thirdItemPrice * thirdItemQuantity;
    int finalBillAmount = firstItemTotal + secondItemTotal + thirdItemTotal;

    // Display bill summary
    cout << "\n======= BILL SUMMARY =======\n";
    cout << firstItemName << " x " << firstItemQuantity << " = Rs." << firstItemTotal << endl;
    cout << secondItemName << " x " << secondItemQuantity << " = Rs." << secondItemTotal << endl;
    cout << thirdItemName << " x " << thirdItemQuantity << " = Rs." << thirdItemTotal << endl;
    cout << "-----------------------------\n";
    cout << "Total Amount to Pay = Rs." << finalBillAmount << endl;
    cout << "=============================\n";

    return 0;
}
