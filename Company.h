#ifndef Company_hpp
#define Company_hpp

#include <stdio.h>
#include "Employee.h"
#include<vector>

class Company{
private:
    std::vector<std::shared_ptr<Employee>> employee;
    
public:
    /**
     Default constructor that reads through all the files and creates Employees
     of suitable type for each file, storing them as pointers;
     */
    Company();
    
    /**
     Print directory function that displays how many employees are in the
     company and then runs through the vector and calls print on all entries;
     */
    void print_directory()const;
    
    /**
     Do hours function that runs through the vector and through using a dynamic pointer cast, for the HourlyWorkers, prompts the user How many hours did [NAME] work?and following the user input, it should call set hours on the employee to set their
     hours and call save on the employee to save the changes;
     
     */
    void do_hours()const;
    
    /**
     Have a print payroll function that runs through the vector and calls the print pay
     function on all elements;
     */
    void print_payroll()const;
    
    /**
     Create salaried function that prompts a user for a name, email address,
     and salary for a SalariedWorker and instantiates that class, saves it, and adds it
     to employees
     */
    void create_salaried();
    
    /**
     Create hourly function that prompts a user for a name, email address, and
     hourly pay rate for an HourlyWorker and instantiates that class, saves it, and
     adds it to employees
     */
    void create_hourly();
    
    /**
     create employee function that asks a user what type of employee they
     want to create with “S” for salaried, “H” for hourly worker; with other commands
     aborting the creation.
     */
    void create_employee();
    
};

#endif /* Company_hpp */
