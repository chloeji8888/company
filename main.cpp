
#include <iostream>
#include<vector>
#include"Company.h"
#include "Employee.h"
#include "HourlyWorker.h"
#include "SalariedWorker.h"

using namespace std;

//Free funtions ________________________________________________

void run_events(){
    Company company;
    bool repeat = true;
    string choice = "";
    while(repeat){
        cout << "What would you like to do? " << "\n";
        cout << "C - Create Employee" << "\n";
        cout << "D - Display Current Directory" << "\n";
        cout << "H - Set Hours" << "\n";
        cout << "P - Print Payroll"<< "\n";
        cout << "Quit (all other inputs)?";
        getline(cin, choice);
        if(choice == "C"){
            company.create_employee();
            cin.ignore();
        }else if(choice == "D"){
            company.print_directory();
        }else if(choice == "H"){
            company.do_hours();
            cin.ignore();
        }else if(choice == "P"){
            company.print_payroll();
        }else{
            cout << "Testing: Ended";
            repeat = false;
        }
    }
}

int main() {
    
    run_events();
    
//    SalariedWorker sw("chloe", "fdhdhdd@fff", 6);
//    sw.print_pay();
//    sw.save();
 //   HourlyWorker hourly("chloe", "fdhdhdd@fff", 6);
//    hourly.print();
//    cout << "\n";
//    hourly.print_pay();
 //   hourly.save();
//    cout << "\n";
//    hourly.set_hours(6);
//    hourly.print();
//    cout << "\n";
//   hourly.print_pay();
//    cout <<"\n";
 //   hourly.save();
//    hourly.print_pay();
//    cout << "\n";
//    hourly.print();
    
    
    
    
    return 0;
}
