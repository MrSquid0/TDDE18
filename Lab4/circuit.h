#ifndef LAB4_CIRCUIT_H
#define LAB4_CIRCUIT_H

#include "component.h"
#include <vector>
#include <map>

class circuit
{
    std::string name;

    // DONE: Using std::unordered_map can lead to some big memory
    // issues here. The reason for this is that whenever we insert or
    // remove elements from the map, any and all stored double can
    // *potentially* move in memory which means that the pointers to
    // these doubles that are stored in the components might be
    // invalidated by making changes in the circuit. If this occurs it
    // will be extremely confusing since the problem occurs in
    // circuit, but the problems is observed in the component class.

    // As soon as you want to have references or pointers to elements
    // stored in a container you must make sure that these elements
    // never move around in memory. You can look at cppreference at
    // various operations/functions on a container and see if they
    // mention: "iterator invalidation". If they save that a certain
    // operation will invalidate iterators, then that means that the
    // elements might move in memory.

    // If you look at std::map for instance, you will notice that it
    // doesn't have these problems, while std::unordered_map do.

    // Make sure that these memory problems can never occur by either
    // changing the container.
    
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
