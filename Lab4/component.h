//
// Created by gonzalo on 16/3/22.
//

#ifndef LAB4_COMPONENT_H
#define LAB4_COMPONENT_H

#include <iostream>

/********************************
      Component (Base class)
********************************/

class component
{
    std::string name;
    std::string positiveName;
    std::string negativeName;
protected:
    double* positivePointer;
    double* negativePointer;
public:
    component (const std::string &name, const std::string &positiveName,
               const std::string &negativeName);
    std::string getPositiveName() const;
    std::string getNegativeName() const;
    std::string getComponentName() const;
    double getVoltage() const;
    virtual double getCurrent() = 0;
    virtual void simulationInSteps (const double &timeStep) = 0;
    void targetConnectionPoints (double &positive, double &negative);
};

/********************************
      Battery (Derived class)
********************************/

class battery : public component
{
    double voltage;
public:
    battery (const std::string &name, const std::string &positiveName,
             const std::string &negativeName, const double &voltage);
    void simulationInSteps (const double &unitTimes) override;
    double getCurrent() override;
};

/********************************
     Capacitor (Derived class)
********************************/

class capacitor : public component
{
    double capacitance;
    double charge;
public:
    capacitor (const std::string &name, const std::string &positiveName,
               const std::string &negativeName, const double &capacitance);
    void simulationInSteps (const double &unitTimes) override;
    double getCurrent() override;
};

/********************************
     Resistor (Derived class)
********************************/

class resistor : public component
{
    double resistance;
public:
    resistor (const std::string &name, const std::string &positive,
              const std::string &negative, const double &resistance);
    void simulationInSteps (const double &unitTimes) override;
    double getCurrent() override;
};


#endif //LAB4_COMPONENT_H
