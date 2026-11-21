#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ================= MENU CLASS =================

class Menu {
public:
    void welcome() {
        cout << "============================" << endl;
        cout << "   WELCOME TO ONLINE MART   " << endl;
        cout << "============================" << endl;
    }
};

// ================= USER CLASS =================

class User : public Menu {

private:
    string username;
    string password;
    string address;
    string phoneNumber;

public:

    // ---------- Password Encryption ----------
    string encryptPassword(string pass) {

        for (int i = 0; i < pass.length(); i++) {
            pass[i] = pass[i] + 3;
        }

        return pass;
    }

    // ---------- Register ----------
    void registerUser() {

        cout << endl << "--- Register ---" << endl;

        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        cin.ignore();

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Phone Number: ";
        getline(cin, phoneNumber);

        password = encryptPassword(password);

        ofstream fout("users.txt", ios::app);

        fout << username << endl;
        fout << password << endl;
        fout << address << endl;
        fout << phoneNumber << endl;

        fout.close();

        cout << "Registration Successful!" << endl;
    }

    // ---------- Login ----------
    bool loginUser() {

        string u, p;
        string fileUser, filePass;
        string fileAddress, filePhone;

        cout << endl << "--- Login ---" << endl;

        cout << "Enter Username: ";
        cin >> u;

        cout << "Enter Password: ";
        cin >> p;

        p = encryptPassword(p);

        ifstream fin("users.txt");

        bool found = false;

        while (fin >> fileUser >> filePass) {

            fin.ignore();

            getline(fin, fileAddress);
            getline(fin, filePhone);

            if (u == fileUser && p == filePass) {

                username = fileUser;
                address = fileAddress;
                phoneNumber = filePhone;

                found = true;
                break;
            }
        }

        fin.close();

        if (found) {

            cout << "Login Successful!" << endl;
            return true;
        }

        else {

            cout << "Invalid Login!" << endl;
            return false;
        }
    }

    string getUsername() {
        return username;
    }

    string getAddress() {
        return address;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }
};

// ================= FOOD CATEGORY CLASS =================

class FoodCategory {

public:

    void categoryHeading(string name) {

        cout << endl << "--- "
            << name
            << " ---" << endl;
    }
};

// ================= MART CLASS =================

class Mart : public FoodCategory {

public:

    void showCategories() {

        cout << endl << "--- MART ---" << endl;

        cout << "1. Fast Food" << endl;
        cout << "2. Pakistani Cuisine" << endl;
        cout << "3. Grocery" << endl;
        cout << "0. Checkout" << endl;
    }

    // ---------- Fast Food ----------
    void showFastFood() {

        categoryHeading("FAST FOOD");

        cout << "1. Burger - Rs.500" << endl;
        cout << "2. Pizza - Rs.1000" << endl;
        cout << "3. Fries - Rs.150" << endl;
        cout << "4. Broast - Rs.500" << endl;
        cout << "5. Club Sandwich - Rs.450" << endl;
        cout << "6. Chowmein - Rs.450" << endl;
        cout << "7. Pasta - Rs.450" << endl;
        cout << "8. Fried Rice - Rs.250" << endl;
        cout << "9. Shashlick Rice - Rs.650" << endl;
        cout << "0. Back" << endl;
    }

    // ---------- Pakistani ----------
    void showPakistani() {

        categoryHeading("PAKISTANI");

        cout << "1. Paye - Rs.500" << endl;
        cout << "2. Nihari - Rs.800" << endl;
        cout << "3. Nalli Nihari - Rs.1000" << endl;
        cout << "4. Biryani - Rs.250" << endl;
        cout << "5. Gola Kabab - Rs.150" << endl;
        cout << "6. Bihari Boti - Rs.350" << endl;
        cout << "7. Chicken Boti - Rs.350" << endl;
        cout << "8. Malai Boti - Rs.350" << endl;
        cout << "9. Tikka - Rs.150" << endl;
        cout << "0. Back" << endl;
    }

    // ---------- Grocery ----------
    void showGrocery() {

        categoryHeading("GROCERY");

        cout << "1. Milk - Rs.200" << endl;
        cout << "2. Bread - Rs.100" << endl;
        cout << "3. Eggs - Rs.300" << endl;
        cout << "4. Rice - Rs.350" << endl;
        cout << "5. Sugar - Rs.180" << endl;
        cout << "6. Tea - Rs.250" << endl;
        cout << "7. Oil - Rs.600" << endl;
        cout << "8. Flour - Rs.150" << endl;
        cout << "9. Salt - Rs.50" << endl;
        cout << "10. Biscuits - Rs.120" << endl;
        cout << "0. Back" << endl;
    }

    // ---------- Get Price ----------
    int getPrice(int cat, int choice) {

        if (cat == 1) {

            int prices[] = {
                500,1000,150,500,450,
                450,450,250,650
            };

            return prices[choice - 1];
        }

        else if (cat == 2) {

            int prices[] = {
                500,800,1000,250,150,
                350,350,350,150
            };

            return prices[choice - 1];
        }

        else if (cat == 3) {

            int prices[] = {
                200,100,300,350,180,
                250,600,150,50,120
            };

            return prices[choice - 1];
        }

        return 0;
    }

    // ---------- Get Item Name ----------
    string getName(int cat, int choice) {

        if (cat == 1) {

            string items[] = {
                "Burger",
                "Pizza",
                "Fries",
                "Broast",
                "Club Sandwich",
                "Chowmein",
                "Pasta",
                "Fried Rice",
                "Shashlick Rice"
            };

            return items[choice - 1];
        }

        else if (cat == 2) {

            string items[] = {
                "Paye",
                "Nihari",
                "Nalli Nihari",
                "Biryani",
                "Gola Kabab",
                "Bihari Boti",
                "Chicken Boti",
                "Malai Boti",
                "Tikka"
            };

            return items[choice - 1];
        }

        else if (cat == 3) {

            string items[] = {
                "Milk",
                "Bread",
                "Eggs",
                "Rice",
                "Sugar",
                "Tea",
                "Oil",
                "Flour",
                "Salt",
                "Biscuits"
            };

            return items[choice - 1];
        }

        return "";
    }
};

// ================= CART CLASS =================

class Cart {

private:

    int total;
    string items[50];
    int prices[50];
    int count;

public:

    Cart() {

        total = 0;
        count = 0;
    }

    // ---------- Add Item ----------
    void addItem(string name, int price) {

        items[count] = name;
        prices[count] = price;

        total += price;

        count++;

        cout << name << " added to cart!" << endl;
    }

    // ---------- Payment Method ----------
    string paymentMethod() {

        int choice;

        cout << endl << "--- PAYMENT METHOD ---" << endl;

        cout << "1. Cash" << endl;
        cout << "2. Online Payment" << endl;

        cout << "Choose Payment Method: ";
        cin >> choice;

        if (choice == 1) {
            return "Cash";
        }

        else if (choice == 2) {
            return "Online Payment";
        }

        return "Cash";
    }

    // ---------- Show Receipt ----------
    void showCart(
        string username,
        string address,
        string phone
    ) {

        string payment = paymentMethod();

        ofstream fout("bill.txt");

        cout << endl;
        cout << "============================" << endl;
        cout << "          RECEIPT          " << endl;
        cout << "============================" << endl;

        fout << "============================" << endl;
        fout << "          RECEIPT          " << endl;
        fout << "============================" << endl;

        // Customer Details
        cout << "Customer Name: "
            << username << endl;

        cout << "Address: "
            << address << endl;

        cout << "Phone Number: "
            << phone << endl;

        cout << "Payment Method: "
            << payment << endl;

        fout << "Customer Name: "
            << username << endl;

        fout << "Address: "
            << address << endl;

        fout << "Phone Number: "
            << phone << endl;

        fout << "Payment Method: "
            << payment << endl;

        cout << "----------------------------" << endl;
        fout << "----------------------------" << endl;

        // Items
        for (int i = 0; i < count; i++) {

            cout << i + 1 << ". "
                << items[i]
                << " - Rs."
                << prices[i] << endl;

            fout << i + 1 << ". "
                << items[i]
                << " - Rs."
                << prices[i] << endl;
        }

        cout << "----------------------------" << endl;
        cout << "Total Bill: Rs." << total << endl;

        fout << "----------------------------" << endl;
        fout << "Total Bill: Rs." << total << endl;

        fout.close();
    }
};

// ================= MAIN FUNCTION =================

int main() {

    User user;
    Mart mart;
    Cart cart;

    user.welcome();

    int option;

    cout << "1. Register" << endl;
    cout << "2. Login" << endl;

    cout << "Choose: ";
    cin >> option;

    if (option == 1) {
        user.registerUser();
    }

    if (!user.loginUser()) {
        return 0;
    }

    int category, choice;

    do {

        mart.showCategories();

        cout << "Select Category: ";
        cin >> category;

        // ---------- FAST FOOD ----------
        if (category == 1) {

            do {

                mart.showFastFood();

                cout << "Enter Choice: ";
                cin >> choice;

                if (choice >= 1 && choice <= 9) {

                    cart.addItem(
                        mart.getName(category, choice),
                        mart.getPrice(category, choice)
                    );
                }

            } while (choice != 0);
        }

        // ---------- PAKISTANI ----------
        else if (category == 2) {

            do {

                mart.showPakistani();

                cout << "Enter Choice: ";
                cin >> choice;

                if (choice >= 1 && choice <= 9) {

                    cart.addItem(
                        mart.getName(category, choice),
                        mart.getPrice(category, choice)
                    );
                }

            } while (choice != 0);
        }

        // ---------- GROCERY ----------
        else if (category == 3) {

            do {

                mart.showGrocery();

                cout << "Enter Choice: ";
                cin >> choice;

                if (choice >= 1 && choice <= 10) {

                    cart.addItem(
                        mart.getName(category, choice),
                        mart.getPrice(category, choice)
                    );
                }

            } while (choice != 0);
        }

    } while (category != 0);

    // ---------- Final Receipt ----------
    cart.showCart(
        user.getUsername(),
        user.getAddress(),
        user.getPhoneNumber()
    );

    cout << endl
        << "Thank You For Shopping!" << endl;

    return 0;
}