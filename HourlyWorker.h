#ifndef h_HourlyWorker_h
#define h_HourlyWorker_h
#include "Employee.h"
#include <stdio.h>
#include<fstream>
#include<iostream>

class HourlyWorker: public Employee{
private:
    int hours;
    double rate;
    
public:
    /**
     A constructor accepting a name, email, and hourly rate, setting the hours
     worked to 0 initially;
     @param _name name of the employee
     @param _email email of the employee
     @param _rate hourly rate fo the employee
     */
    HourlyWorker(std::string _name, std::string _email, double _rate);
    
    /**
     A constructor accepting an input file stream to read in the name, email, id,
     hours worked, and hourly rate;
     @param inputFile an input filestream  to be read
     */
    HourlyWorker(std::ifstream& inputFile);
    
    /**
     Function that sets the hours worked
     @param _hour hour that the employee worked
     */
    void set_hours(int _hour);
    
    /**
     Implement the print pay function to print: [NAME] receives $ [AMOUNT] to the console;
     */
    void print_pay()const override;
    
    /**
     Function (that could be overridden) that writes the name, email,
     and id of the Employee to a file, each entry separated by a tab;
     */
    void write_data()const override;
    
    /**
     Function save save employee data.
     */
    void save()const override;
    
    /**
     Getter function of hours
     */
    int get_hours()const;
    
    /**
     Getter function of hourly rate
     */
    double get_rate()const;
    
};

#endif /* HourlyWorker_h */
