#ifndef LAB4_COMPONENT_H
#define LAB4_COMPONENT_H

#include <iostream>

/********************************
      Component (Base class)
********************************/

class component
{
    std::string name;

    // Comment: The way you solve the problem of passing the
    // appropriate connections is pretty clever with the use of
    // std::unordered_map and names for the connections. But it
    // suffers from two major problem:
    
    // 1. This requires the component to be passed to a circuit in
    //    order to be usable. There is no way for me to create a
    //    component and have it be usable without having to pass them
    //    along to a circuit. This goes against the concept of a class
    //    since classes should be in a valid state without needing to
    //    anything special with it.

    // 2. This means that each class will store two strings that are
    //    only ever used *once*, and that is when we are calling
    //    addComponent on the Circuit class. This also goes against
    //    the whole purpose of a class.

    // If you want the connection points to have names, we could instead
    // design it so that the interface worked something like this instead:

    // Circuit c { };
    // double* P { c.addConnection() };
    // double* N { c.addConnection() };

    // Battery B1("Bat", P, N, voltage);
    // c.addComponent(&B1);

    // Because now I can also use a component without a circuit if I
    // so please, for example like this:

    // double P { 0.0 };
    // double N { 0.0 };
    // Battery B1("Bat", &P, &N, voltage);

    // I hope that makes sense. I won't force you to change this, but please
    // consider it.
    
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

    // DONE: getCurrent will never change any internal data in the class,
    // so it should be marked const.
    virtual double getCurrent() const = 0;
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
    double getCurrent() const override;
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
    double getCurrent() const override;
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
    double getCurrent() const override;
};


#endif //LAB4_COMPONENT_H
