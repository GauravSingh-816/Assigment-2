#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H

#include "Employee.h"

class Nonprofessional : public Employee {

private:
    double hourly_rate;
    int hours_worked;

public:
    Nonprofessional(double hourly_rate) : hourly_rate(hourly_rate), hours_worked(0) {}

    double weekly_salary() const override { return hourly_rate * hours_worked; }
    double health_care() const override { return hourly_rate * hours_worked * 0.05; }
    int vacation_days() const override { return hours_worked / 10; }

    void add_hours(int hours) { hours_worked += hours; }

};

#endif