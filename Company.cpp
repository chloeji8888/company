#include "Company.h"
#include "Employee.h"
#include"HourlyWorker.h"
#include"SalariedWorker.h"
#include<memory>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>


using namespace std;

//Employee definition ________________________________________________

//Default constructor
Employee::Employee():name(""), ID(0){}

//Initialize name, email
Employee::Employee(std::string _name, std::string _email): name(_name), email(_email), ID(next_id){
    ++next_id;
}

/**
 Accepts an input file stream and reads a name, email, and
 id from the stream#;
 */
Employee::Employee(std::ifstream& inputFile){
    inputFile.ignore();
    getline(inputFile, name, '\t');
    getline(inputFile, email, '\t');
    inputFile >> ID;
}

// Get the name of the employee
const std::string& Employee::get_name()const{
    return name;
}

//Get the email of the employee
const std::string&Employee:: get_email()const{
    return email;
}

//Get the ID of the emloyee
int Employee::get_ID()const{
    return ID;
}

//print the name, ID, and email on the console
void Employee::print()const{
    cout << get_name() << "\t" << get_ID() << "\t" << get_email();
}

/**
 Function (that could be overridden) that writes the name, email,
 and id of the Employee to a file, each entry separated by a tab;
 */
void Employee::write_data()const{
    std::string id = std::to_string(ID);
    std::string s = "employee" + id  + ".txt";
    std::ofstream output;
    output.open(s, std::ios_base::app);
    output << name << "\t" << email << "\t" << ID;
    output.close();
}

//HourelyWorker definition ________________________________________________

HourlyWorker::HourlyWorker(std::string _name, std::string _email, double _rate): hours(0), Employee(_name, _email), rate(_rate){}

HourlyWorker::HourlyWorker(std::ifstream& inputFile):Employee(inputFile){
    inputFile >> hours >> rate;
    inputFile.close();
}

void HourlyWorker::set_hours(int _hour){
    hours = _hour;
}

void HourlyWorker::print_pay()const{
    double amount = hours * rate;

    std::cout << get_name() << " recieves $" << amount ;
}

void HourlyWorker::write_data()const{
    
    Employee::write_data();
    
    std::string id = std::to_string(get_ID());
    std::string s = "employee" + id +".txt";
    
    std::ofstream output;
    output.open(s, std::ios_base::app);

    output << "\t" << hours << "\t" << rate;
    
    output.close();
}

void HourlyWorker::save()const{
    std::string id = std::to_string(get_ID());
    
    std::string employeeFile = "employee" + id  + ".txt";
    
    std::ofstream output;
    
    output.open(employeeFile);
    
    output << "hourly\t";
    
    output.close();
    
    HourlyWorker::write_data();
}

int HourlyWorker::get_hours()const{
    return hours;
}

double HourlyWorker::get_rate()const{
    return rate;
}

//SalariedWorker definition ________________________________________________

SalariedWorker::SalariedWorker(std::string _name, std::string _email, double _salary):Employee(_name, _email), salary(_salary){}

SalariedWorker::SalariedWorker(std::ifstream& inputFile):Employee(inputFile){
    inputFile >> salary;
    inputFile.close();
}

double SalariedWorker::get_salary()const{
    return salary;
};

void SalariedWorker::print_pay()const{
    cout << get_name() << " recieves $" << salary;//return how much money did each person recieved
}

void SalariedWorker::write_data()const{
    
    Employee::write_data();//get the name, email and id of the employee
    
    std::string id = std::to_string(get_ID());
    std::string s = "employee" + id  + ".txt";// read in the file
    
    std::ofstream output;
    output.open(s, std::ios_base::app);// append the salary at the end of the line

    output << "\t" << salary;
    output.close();
}

void SalariedWorker::save()const{
    
    std::string id = std::to_string(get_ID());
    
    std::string employeeFile = "employee" + id + ".txt";
    
    std::ofstream output;
    
    output.open(employeeFile);
    
    output << "salaried\t";
    
    output.close();
    
    SalariedWorker::write_data();
}


//Company definition ________________________________________________

Company::Company(){
    string workerType;
    string hourlyType = "hourly";
    string salariedType = "salaried";
    ifstream readFile;
    int i = 0;
    readFile.open("employee" + to_string(i)  + ".txt");
    while(readFile){
        readFile >> workerType;
 //      readFile.close();
        if(workerType == hourlyType){
            employee.push_back(make_shared<HourlyWorker>(readFile));
        }
        if(workerType == salariedType){
            employee.push_back(make_shared<SalariedWorker>(readFile));
        }
        readFile.close();
        ++i;
        readFile.open("employee" + to_string(i)  + ".txt");
    }
}

void Company::print_directory()const{
    size_t amoutOfWorker = employee.size();// get how many workers there are
    cout << "There are " << amoutOfWorker << " employees: " << "\n";
    for(auto& employees: employee){
        employees -> print();
        cout << "\n";
    }
}

void Company::do_hours()const{
    
    for(auto& employees: employee){
        auto setHours = dynamic_pointer_cast< HourlyWorker>(employees);
        if(setHours){
            cout << "How many hours did " << employees->get_name() <<" work?";
            int hour;
            cin >> hour;//get the updated hour
            setHours->set_hours(hour);//update hours
            setHours->save();//save it to the file
        }
    }
}

void Company::print_payroll()const{
    for(auto& employees: employee){// runs through the vector and calls
        employees->print_pay();
        cout << "\n";//print payfunction on all elements;
    }
}

void Company::create_salaried(){
    string salariedName;
    string salariedEmail;
    double salary;
    cout << "Enter name: ";
    getline(cin,salariedName);
    cout << "Enter email: ";
    getline(cin,salariedEmail);
    cout << "Enter salary: $";
    cin >> salary;
    employee.push_back(make_shared<SalariedWorker>(salariedName, salariedEmail, salary));
    employee[employee.size()-1] -> save();
    
}

void Company::create_hourly(){
    string hourlyName;
    string hourlyEmail;
    double rate;
    cout << "Enter name: ";
    getline(cin,hourlyName);
    cout << "Enter email: ";
    getline(cin,hourlyEmail);
    cout << "Enter hourly: $";
    cin >> rate;
    employee.push_back(make_shared<HourlyWorker>(hourlyName, hourlyEmail, rate));
    employee[employee.size()-1] -> save();
}

void Company::create_employee(){
    string type;
    cout << "What type of employee?\n";
    cout << "S - Salaried\n";
    cout << "H - Hourly\n";
    cout << "Abort(all other inputs)?";
    cin >> type;
    cin.ignore();
    if(type == "S"){
        create_salaried();
    }else if (type == "H"){
        create_hourly();
    }else{
        cout << "creation aborted \n";
    }
}



static int find_next_id(){
    int i = 0;
    std::string s = "employee" + to_string(i)  + ".txt";
    std::ifstream exist;
    exist.open(s);
    while(exist){
        exist.close();
        s =  "employee" + to_string(++i)  + ".txt";
        exist.open(s);
    }
    return i;
}

int Employee::next_id = find_next_id();
