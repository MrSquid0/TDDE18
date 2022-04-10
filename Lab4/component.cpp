#include "component.h"

/********************************
      Component (Base class)
********************************/

component::component(const std::string &name, const std::string &positiveName,
                     const std::string &negativeName) {
    this->name = name;
    this->positiveName = positiveName;
    this->negativeName = negativeName;
    this->positivePointer = nullptr;
    this->negativePointer = nullptr;
}

std::string component::getPositiveName() const {
    return positiveName;
}

std::string component::getNegativeName() const {
    return negativeName;
}

std::string component::getComponentName() const {
    return name;
}

double component::getVoltage() const {
    return std::abs(*positivePointer - *negativePointer);
}

void component::targetConnectionPoints(double &positive, double &negative) {
    positivePointer = &positive;
    negativePointer = &negative;
}

/********************************
      Battery (Derived class)
********************************/

//Constructor of battery
battery::battery (const std::string &name, const std::string &positiveName,
                  const std::string &negativeName, const double &voltage)
        : component(name, positiveName, negativeName)
{
    this->voltage = voltage;
}

void battery::simulationInSteps (const double &unitTimes)
{
    //Set the connection point on the positive terminal to the battery voltage,
    //and the connection point on the negative terminal to zero
    *positivePointer = voltage;
    *negativePointer = 0;

}

double battery::getCurrent()
{
    //The idealized battery has zero current
    return 0;
}

/********************************
     Capacitor (Derived class)
********************************/

//Constructor of capacitor
capacitor::capacitor (const std::string &name, const std::string &positiveName,
                      const std::string &negativeName, const double &capacitance)
        : component(name, positiveName, negativeName)
{
    this->capacitance = capacitance;
    this->charge = 0;
}

void capacitor::simulationInSteps (const double& unitTimes) {
    //Calculate the charge to be stored with the formula
    double chargesToBeStored = capacitance * ((*positivePointer - *negativePointer) - charge) * unitTimes;
    //Pull from the most positive terminal and stored both
    //internally and on the other terminal.
    *positivePointer -= chargesToBeStored;
    *negativePointer += chargesToBeStored;
    charge += chargesToBeStored;
}

double capacitor::getCurrent()
{
    //Calculate the current with the formula
    return capacitance * ( getVoltage() - std::abs(charge) );
}

/********************************
     Resistor (Derived class)
********************************/

//Constructor of resistor
resistor::resistor (const std::string &name, const std::string &positiveName,
                    const std::string &negativeName, const double &resistance)
        : component(name, positiveName, negativeName)
{
    this->resistance = resistance;
}

void resistor::simulationInSteps (const double &unitTimes)
{
    //Calculate the charge to be moved with the formula
    double chargesToBeMoved = (*positivePointer - *negativePointer)
                              / resistance * unitTimes;
    //Move from most positive terminal to the another terminal
    *positivePointer -= chargesToBeMoved;
    *negativePointer += chargesToBeMoved;
}

double resistor::getCurrent()
{
    //Calculate the current with the formula
    return getVoltage() / resistance;
}
