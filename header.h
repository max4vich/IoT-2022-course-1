#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Medicine
{
private:
    // price, quantity, name, isPrescriptionNeeded, expirationDate, etc
    int quantityOfMedicine, expirationYearOfMedicine, expirationMonthOfMedicine;
    string nameOfMedicine, isPrescriptionNeededForMedicine;
    bool boolOfExpiration;
public:
    float priceOfMedicine;

    Medicine(string nameOfMedicine, float priceOfMedicine, int quantityOfMedicine, int expirationMonthOfMedicine, int expirationYearOfMedicine, string isPrescriptionNeededForMedicine, bool boolOfExpiration)
    {
        this->nameOfMedicine = nameOfMedicine;
        this->priceOfMedicine = priceOfMedicine;
        this->quantityOfMedicine = quantityOfMedicine;
        this->expirationMonthOfMedicine = expirationMonthOfMedicine;
        this->expirationYearOfMedicine = expirationYearOfMedicine;
        this->isPrescriptionNeededForMedicine = isPrescriptionNeededForMedicine;
        this->boolOfExpiration = boolOfExpiration;
    }
    ~Medicine(){};

    string getName(){
        return nameOfMedicine;
    }

    int getQuantity(){
        return quantityOfMedicine;
    }

    int getExpirationMonth(){
        return expirationMonthOfMedicine;
    }

    int getExpirationYear(){
        return expirationYearOfMedicine;
    }

    string getIsPrescriptionNeeded(){
        return isPrescriptionNeededForMedicine;
    }

    bool getBoolOfExpiration(){
        return boolOfExpiration;
    }

};

class Pharmacy
{
private:
    vector<Medicine> medicines;
public:
    Pharmacy(){};

    void AddMedicine(Medicine medicine)
    {
        medicines.push_back(medicine);
    } // add

    void RemoveMedicine()
    {
        string nameOfCurrentMedicine;
        cin >> nameOfCurrentMedicine;
            int i;
            for (i=0; i<medicines.size();i++){
                if (medicines[i].getName() == nameOfCurrentMedicine) {
                    medicines.erase(medicines.begin()+i);

                }
            }
    }
// remove

    void BubbleSort() //!
    {
        bool sortingFlag = true;
        while(sortingFlag){
            sortingFlag = false;
            for (size_t i = 0; i < medicines.size()-1; i++) {
                if (medicines[i].priceOfMedicine > medicines[i+1].priceOfMedicine ){
                    medicines[i].priceOfMedicine += medicines[i+1].priceOfMedicine;
                    medicines[i+1].priceOfMedicine = medicines[i].priceOfMedicine - medicines[i+1].priceOfMedicine;
                    medicines[i].priceOfMedicine -= medicines[i+1].priceOfMedicine;
                    sortingFlag = true;
                }
            }
        }
        cout << "Sorted price-list of medicines:" << endl;
        for (size_t i=0;  i <medicines.size();  i++) {

            cout << medicines[i].getName() << endl;
            cout << medicines[i].priceOfMedicine << " uah" << endl;

        }
        cout<<endl;
    }

    void OutPutOfNonExpiredMedicines(){
        for(auto medicine : medicines){
            if (medicine.getBoolOfExpiration() == true){
                cout << "Name is " << medicine.getName() <<  endl;
                cout << "It is non-expired medicament." << endl;
                cout << endl;
            }
        }
    }
    void OutPutOfAllMedicines(){
        for(auto medicine : medicines){
            cout << medicine.getName() << endl;
            cout << medicine.priceOfMedicine << " uah" << endl;
        }
        cout << endl;
    }

    void OutPutOfMedicinesWithDiscount(){
        for(auto medicine : medicines){
            medicine.priceOfMedicine *= 0.9;
            cout << "Name is " << medicine.getName() <<  endl;
            cout << "Price is " << medicine.priceOfMedicine << " uah" <<  endl;
            cout << endl;
            }

    }

    ~Pharmacy(){};
};
