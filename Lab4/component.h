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
    std::string getName() const;
    std::string getPositiveName() const;
    std::string getNegativeName() const;
    double getVoltage() const;
    void connectPoints (double &pos, double &negat);
    virtual void simulationInSteps (const double &timeStep) = 0;
    virtual double getCurrent() = 0;
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
    resistor (const std::string &name, const std::string &positiveName,
              const std::string &negativeName, const double &resistance);
    void simulationInSteps (const double &unitTimes) override;
    double getCurrent() override;
};


#endif //LAB4_COMPONENT_H
