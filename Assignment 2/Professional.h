#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include "Employee.h"

class Professional : public Employee {

private:
    double salary;
    int vacation_days;

public:
    Professional(double salary_rate, int vacation_days) :
        salary(salary_rate), vacation_days(vacation_days) {}

    double weekly_salary() const override { return salary / 4; }
    double health_care() const override { return salary * 0.1; }
    int vacation_days() const override { return vacation_days; }

};

#endif