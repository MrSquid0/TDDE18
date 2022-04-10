#include <iostream>
#include <iomanip>
#include "circuit.h"

circuit::circuit (const std::string &name)
{
    this->name = name;
    components = std::vector<component*>();
    connectionPoints = std::unordered_map<std::string, double>();
}

void circuit::simulate (const int &iterations, const int &linesToPrint,
                        const double &timeStep)
{
    printTableHeader();
    int printCount = 0;
    int printStep = iterations / linesToPrint;
    for (int i = 0; i < iterations; i++)
    {
        for (component* it: components)
        {
            it->simulationInSteps(timeStep);
        }
        if (i == printCount) {
            printTableRow();
            printCount += printStep;
        }
    }
    std::cout << std::endl;
}

void circuit::addComponent (component* component)
{
    component->targetConnectionPoints(connectionPoints[component->
            getPositiveName()], connectionPoints[component->getNegativeName()]);
    components.push_back(component);
}

void circuit::addConnectionPoint (const std::string &key)
{
    connectionPoints[key] = 0.0;
}

void circuit::printTableHeader () const
{
    for (component* it: components)
    {
        std::cout << std::setw(12) << it->getComponentName();
    }
    std::cout << std::endl;
    for (int i = 0; i < components.size(); i++)
    {
        std::cout << std::setw(12) << "Volt  Curr";
    }
    std::cout << std::endl;
}

void circuit::printTableRow () const
{
    using std::cout;
    using std::endl;
    cout << std::setprecision(2) << std::fixed;
    for (component* it: components)
    {
        cout << std::setw(6) << it->getVoltage() << "  " << it->getCurrent();
    }
    cout << endl;
}

