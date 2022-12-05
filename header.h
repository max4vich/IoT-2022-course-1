#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Medicine
{
public:
    // price, quantity, name, isPrescriptionNeeded, expirationDate, etc
    float price;
    int quantity, expirationYear, expirationMonth;
    string name, isPrescriptionNeeded;
    bool whyyouboolieme;
    Medicine(string name, float price, int quantity, int expirationMonth, int expirationYear, string isPrescriptionNeeded, bool whyyouboolieme)
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->expirationMonth = expirationMonth;
        this->expirationYear = expirationYear;
        this->isPrescriptionNeeded = isPrescriptionNeeded;
        this->whyyouboolieme = whyyouboolieme;
    }
    ~Medicine(){};
};

class Pharmacy
{
public:
    vector<Medicine> medicaments;

    void add_medicament(Medicine medicament)
    {
        medicaments.push_back(medicament);
    } // add

    void remove_medicament()
    {
        string a;
        cin >> a;
            int i;
            for (i=0; i<medicaments.size();i++){
                if (medicaments[i].name == a) {
                    medicaments.erase(medicaments.begin()+i);
                }
                }
    }
// remove

    void bubbleSort()
    {
        bool swapp = true;
        while(swapp){
            swapp = false;
            for (size_t i = 0; i < medicaments.size()-1; i++) {
                if (medicaments[i].price>medicaments[i+1].price ){
                    medicaments[i].price += medicaments[i+1].price;
                    medicaments[i+1].price = medicaments[i].price - medicaments[i+1].price;
                    medicaments[i].price -=medicaments[i+1].price;
                    swapp = true;
                }
            }
        }
        cout << "Sorted price-list of medicaments:" << endl;
        for (size_t i=0;  i <medicaments.size();  i++) {

            cout << medicaments[i].name << endl;
            cout << medicaments[i].price << " uah" << endl;

        }
        cout<<endl;
    }

    void print_non_expired(){
        for(auto medicament : medicaments){
            if (medicament.whyyouboolieme == true){
                cout << "Name is " << medicament.name <<  endl;
                cout << "It is non-expired medicament." << endl;
                cout << endl;
            }
        }
    }
    void print(){
        for(auto medicament : medicaments){
            cout << medicament.name << endl;
            cout << medicament.price << " uah" << endl;
        }
        cout << endl;
    }

    void discount(){
        for(auto medicament : medicaments){
            medicament.price *= 0.9;
            cout << "Name is " << medicament.name <<  endl;
            cout << "Price is " << medicament.price << " uah" <<  endl;
            cout << endl;
            }

    }
};
