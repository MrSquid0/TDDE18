#ifndef LAB4_CIRCUIT_H
#define LAB4_CIRCUIT_H

#include "component.h"
#include <vector>
#include <map>

class circuit
{
    std::string name;
    
    std::map<std::string, double> connectionPoints;
    std::vector<component*> allComponents;
public:
    circuit (const std::string &name);
    void newConnectionPoint (const std::string &point);
    void newComponent (component* component);
    void simulation (const int &iterations, const int &outputLines,
                     const double &timeStep);
};


#endif //LAB4_CIRCUIT_H
