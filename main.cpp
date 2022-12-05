#include <iostream>
#include <string>
#include <list>
#include "3.h"
#include <ctime>
using namespace std;


int main() {
    int i = 1;

    Pharmacy medicaments;
    Medicine medicament1("Aspirin", 60.23, 50, 10, 2023, "Yes", true);
    Medicine medicament2("Analgin", 40.90, 70, 11, 2023, "No",true);
    Medicine medicament3("Corvalol", 32.50, 96, 5, 2023, "No",false);
    Medicine medicament4("Atoxil", 43.49, 32, 7, 2024, "No",true);
    Medicine medicament5("Loratydyn", 53.49, 96, 5, 2022, "No",false);

    medicaments.add_medicament(medicament1);
    medicaments.add_medicament(medicament2);
    medicaments.add_medicament(medicament3);
    medicaments.add_medicament(medicament4);
    medicaments.add_medicament(medicament5);
    while (i > 0) {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << "Welcome to APTEK_PHARMACY system" << endl;
        cout << "Today is " << 1 + ltm->tm_mon<< " month" << " and " << 1900 + ltm->tm_year<< " year" << endl;
        cout << "Write 1, if you need to delete a medicament." << endl;
        cout << "Write 2, if you need to add a medicament." << endl;
        cout << "Write 3, if you need to see actual discounts." << endl;
        cout << "Write 4, if you need to sorted list (from the lowest price to the highest)." << endl;
        cout << "Write 5, if you need to see non-expired medicines." << endl;
        cout << "Write 6, if you need to see all medicines." << endl;
        cout << "Write 7, if you need to stop our system." << endl;

        int a;
        cin >> a;

        string name1;
        float price1;
        int quantity1;
        int expirationMonth1;
        int expirationYear1;
        string isPrescriptionNeeded1;
        bool whybool = false;



        if (a == 1) {
            cout << "Write medicament which you need to delete: " << endl;
            medicaments.remove_medicament();
            medicaments.print();
            cout << endl;
        }
        else if (a == 2) {
            string gool;
            cout << "Write name: " << endl;
            cin >> name1;
            cout << "Write price: " << endl;
            cin >> price1;
            cout << "Write quantity: " << endl;
            cin >> quantity1;
            cout << "Write expirationMonth: " << endl;
            cin >> expirationMonth1;
            cout << "Write expirationYear: " << endl;
            cin >> expirationYear1;
            cout << "Write isPrescriptionNeeded: " << endl;
            cin >> isPrescriptionNeeded1;
            cout << "Write is it expired or not (true - not, false - yes): " << endl;
            cin >> gool;
            if (gool == "true"){
                whybool = true;
            }
            else
            {
                whybool = false;
            }
            Medicine medicament10(name1, price1, quantity1, expirationMonth1, expirationYear1, isPrescriptionNeeded1, whybool);
            medicaments.add_medicament(medicament10);
            medicaments.print();

            cout << endl;
        }

        else if (a == 3){
            cout << "There is our discount's list: " << endl;
            medicaments.discount();
        }
        else if (a == 4){
            medicaments.bubbleSort();

        }
        else if (a == 5){
            medicaments.print_non_expired();
        }
        else if (a == 6){
            medicaments.print();
        }
        else if (a == 7){
            i = 0;
        }

    }
}