#ifndef Employee_h
#define Employee_h
#include<string>
#include<iostream>
#include<memory>
#include<fstream>
#include<vector>

class Employee{
    
private:
    std::string name;
    std::string email;
    int ID;
    static int next_id;
    
public:
    /**
     Default constructor
     */
    Employee();
    
    /**
     Constructor that accepts a name and email address, and creates an Em-
     ployee from that;
     @param _name name of the employee
     @param _email email of the employee
     */
    Employee(std::string _name, std::string _email);
    
    /**
     Constructor that accepts an input file stream and reads a name, email, and
     id from the stream#;
     @param inputFile file that the program read from
     */
    Employee(std::ifstream& inputFile);
    
    /**
     Print function that prints directory information of the form: [NAME] [TAB] [ID] [TAB] [EMAIL]
     to the console;
     */
    void print()const;
    
    /**
     Getter function of name
     @return name
     */
    const std::string& get_name()const;
    
    /**
     Getter function of email
     @return email
     */
    const std::string& get_email()const;
    
    /**
     Getter function of ID
     @return ID
     */
    int get_ID()const;
    
    /**
     Function (that could be overridden) that writes the name, email,
     and id of the Employee to a file, each entry separated by a tab;
     */
    virtual void write_data()const;
    
    /**
     Mandate functionality for
     printing payment information
     */
    virtual void print_pay()const = 0;
    
    /**
     Function that being able to save employee data.
     */
    virtual void save()const = 0 ;
    
    /**
     Destructor function of Employee
     */
    virtual ~Employee(){}
    
    /**
     Move and Copy constructors
     Move and Copy assignments
     */
    Employee(Employee&&)noexcept = default;
    Employee(const Employee&) = default;
    Employee&operator = (Employee&&) noexcept= default;
    Employee&operator = (const Employee&) = default;
};

#endif /* Employee_h */
