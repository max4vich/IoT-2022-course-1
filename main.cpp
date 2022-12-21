#include <iostream>
#include <string>
#include <list>
#include "header.h"
#include <ctime>
using namespace std;


int main() {
    int terminalNum = 1;

    Pharmacy medicaments;
    Medicine medicament1("Aspirin", 60.23, 50, 10, 2023, "Yes", true);
    Medicine medicament2("Analgin", 40.90, 70, 11, 2023, "No",true);
    Medicine medicament3("Corvalol", 32.50, 96, 5, 2023, "No",false);
    Medicine medicament4("Atoxil", 43.49, 32, 7, 2024, "No",true);
    Medicine medicament5("Loratydyn", 53.49, 96, 5, 2022, "No",false);

    medicaments.AddMedicine(medicament1);
    medicaments.AddMedicine(medicament2);
    medicaments.AddMedicine(medicament3);
    medicaments.AddMedicine(medicament4);
    medicaments.AddMedicine(medicament5);
    while (terminalNum > 0) {
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

        int inputtedNum;
        cin >> inputtedNum;


        string nameOfMedicine;
        float priceOfMedicine;
        int quantityOfMedicine;
        int expirationMonthOfMedicine;
        int expirationYearOfMedicine;
        string isPrescriptionNeededForMedicine;
        bool boolOfExpiration = false;



        if (inputtedNum == 1) {
            cout << "Write medicament which you need to delete: " << endl;
            medicaments.RemoveMedicine();
            medicaments.OutPutOfAllMedicines();
            cout << endl;
        }
        else if (inputtedNum == 2) {
            string flagForExpiration;

            cout << "Write name: " << endl;
            cin >> nameOfMedicine;
            cout << "Write price: " << endl;
            cin >> priceOfMedicine;
            cout << "Write quantity: " << endl;
            cin >> quantityOfMedicine;
            cout << "Write expiration month: " << endl;
            cin >> expirationMonthOfMedicine;
            cout << "Write expiration year: " << endl;
            cin >> expirationYearOfMedicine;
            cout << "Write isPrescriptionNeeded: " << endl;
            cin >> isPrescriptionNeededForMedicine;
            cout << "Write is it expired or not (true - not, false - yes): " << endl;
            cin >> flagForExpiration;
            if (flagForExpiration == "true"){
                boolOfExpiration = true;
            }
            else
            {
                boolOfExpiration = false;
            }
            Medicine medicament10(nameOfMedicine, priceOfMedicine, quantityOfMedicine, expirationMonthOfMedicine, expirationYearOfMedicine, isPrescriptionNeededForMedicine, boolOfExpiration);
            medicaments.AddMedicine(medicament10);
            medicaments.OutPutOfAllMedicines();

            cout << endl;
        }

        else if (inputtedNum == 3){
            cout << "There is our discount's list: " << endl;
            medicaments.OutPutOfMedicinesWithDiscount();
        }
        else if (inputtedNum == 4){
            medicaments.BubbleSort();

        }
        else if (inputtedNum == 5){
            medicaments.OutPutOfNonExpiredMedicines();
        }
        else if (inputtedNum == 6){
            medicaments.OutPutOfAllMedicines();
        }
        else if (inputtedNum == 7){
            terminalNum = 0;
        }

    }
}