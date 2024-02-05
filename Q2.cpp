#include <iostream>

using namespace std;

int main(){
    float charge, base_charge, items, item_charge;

    for(int i = 1; i<=3;i++){
        cout<<"Receipt for Customer "<<i<<endl;
        cout<<"---------------------------";

        cout<<"Enter base charge of purchase: ";
        cin>>base_charge;

        cout<<"Enter number of items: ";
        cin>>items;

        cout<<"Enter the charge per item: ";
        cin>>item_charge;

        charge = base_charge + items * item_charge;
        cout<<"Total: R"<<charge<<endl;

        if(charge>500){
            charge-=(charge*0.2);
            cout<<"Total @ 20% discount: R"<<charge<<endl;
        }
        cout<<"---------------------------";
    }
    return 0;
}
