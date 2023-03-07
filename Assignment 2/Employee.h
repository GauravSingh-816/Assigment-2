#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {

public:
    virtual double weekly_salary() const = 0;
    virtual double health_care() const = 0;
    virtual int vacation_days() const = 0;

};

#endif