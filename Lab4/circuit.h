//
// Created by gonzalo on 16/3/22.
//

#ifndef LAB4_CIRCUIT_H
#define LAB4_CIRCUIT_H

#include "component.h"
#include <unordered_map>
#include <vector>

class circuit
{
    std::string name;
    std::vector<component*> components;
    std::unordered_map<std::string, double> connectionPoints;
public:
    circuit (const std::string &name);
    void simulate (const int &iterations, const int &linesToPrint,
                   const double &timeStep);
    void addComponent (component* component);
    void addConnectionPoint (const std::string &key);
    void printTableHeader() const;
    void printTableRow() const;
};


#endif //LAB4_CIRCUIT_H
