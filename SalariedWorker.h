//
//  SalariedWorker.h
//  HW4
//
//  Created by Zhenyuxi Ji on 2022/1/23.
//

#ifndef SalariedWorker_h
#define SalariedWorker_h
#include"Employee.h"
#include<iostream>
#include <stdio.h>
#include<fstream>

class SalariedWorker: public Employee{
    
private:
    double salary;
    
public:
    /**
     Constructor that accepting a name, email, and salary
     @param _name name of the employee
     @param _email email of the employee
     @param _salary salary of the employee
     */
    SalariedWorker(std::string _name, std::string _email, double _salary);
    
    /**
     Constructor accepting an input file stream to read in the name, email, id,
     and salary;
     @param inputFile the file that read in the name, email and the salary
     */
    SalariedWorker(std::ifstream& inputFile);
    
    /**
     Getter function of salary
     @return salary
     */
    double get_salary()const;
    
    /**
     Function to print [NAME] receives $ [AMOUNT] to the console;
     */
    void print_pay()const override;
    
    /**
     Function (that could be overridden) that writes the name, email,
     and id of the Employee to a file, each entry separated by a tab;
     */
    void write_data()const override;
    
    /**
     Function that being able to save employee data.
     */
    void save()const override;
    
};


#endif /* SalariedWorker_h */
