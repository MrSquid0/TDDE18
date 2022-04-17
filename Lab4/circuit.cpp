#include <iostream>
#include <iomanip>
#include "circuit.h"

circuit::circuit (const std::string &name)
{
    this->name = name;
    connectionPoints = std::unordered_map<std::string, double>();
    allComponents = std::vector<component*>();
}

void circuit::simulation (const int &iterations,
                          const int &outputLines,
                          const double &timeStep)
{
    for (component* component: allComponents)
    {
        std::cout << std::setw(13) << component->getName();
    }
    std::cout << std::endl;
    for (int i = 0; i < allComponents.size(); i++)
    {
        std::cout << std::setw(13) << "Volt  Curr";
    }
    std::cout << std::endl;

    int linesPrintPerEach = iterations / outputLines;
    int printCounter = linesPrintPerEach;
    for (int i = 0; i <= iterations; i++)
    {
        for (component* component: allComponents)
        {
            component->simulationInSteps(timeStep);
        }
        if (i == printCounter) {
            std::cout << std::setprecision(2) << std::fixed;
            for (component* it: allComponents)
            {
                std::cout << std::setw(7) << it->getVoltage() << "  " << it->getCurrent();
            }
            std::cout << std::endl;
            printCounter += linesPrintPerEach;
        }
    }
    std::cout << std::endl;
}

void circuit::newConnectionPoint (const std::string &point)
{
    connectionPoints[point] = 0.00;
}

void circuit::newComponent (component* component)
{
    allComponents.emplace_back(component);
    component->connectPoints(connectionPoints[component->getPositiveName()],
                             connectionPoints[component->getNegativeName()]);
}