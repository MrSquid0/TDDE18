
#include <iostream>
#include "circuit.h"
#include "component.h"

int main(int argc, char *argv[]) {
    int numberOfArgumentsAllowed{5};
    int numberOfIterations;
    int numberOfLinesToPrint;
    double simulationInSteps;
    double voltage;

    /*
    - Argument 0: the name of the file.
    - Argument 1: the number of iterations.
    - Argument 2: the number of lines to print.
    - Argument 3: the time units of simulation in steps.
    - Argument 4: the voltage value.
     */

    if (argc != numberOfArgumentsAllowed) {
        std::cerr << "ERROR: You entered an incorrect number of arguments!\n"
                  << "You gave " << argc << ", when it is required to input "
                  << numberOfArgumentsAllowed << " ones.\n";
        return 0;
    }
    try { numberOfIterations = std::stoi(argv[1]); }
    catch (...) {
        std::cout << "ERROR: Number of iterations "
                     "must be an integer!" << std::endl;
        return 0;
    }
    try { numberOfLinesToPrint = std::stoi(argv[2]); }
    catch (...) {
        std::cout << "ERROR: Number of lines to print "
                     "must be an integer!" << std::endl;
        return 0;
    }
    try { simulationInSteps = std::stod(argv[3]); }
    catch (...) {
        std::cout << "ERROR: Time units of simulation in steps "
                     "must be a double! " << std::endl;
        return 0;
    }
    try { voltage = std::stod(argv[4]); }
    catch (...) {
        std::cout << "ERROR: Voltage must be a double!" << std::endl;
        return 0;
    }

    {
        circuit C1("C1");
        C1.addConnectionPoint("P");
        C1.addConnectionPoint("R124");
        C1.addConnectionPoint("N");
        C1.addConnectionPoint("R23");
        battery B1("Bat", "P", "N", voltage);
        resistor R1("R1", "R124", "P", 6);
        resistor R2("R2", "R23", "R124", 4);
        resistor R3("R3", "N", "R23", 8);
        resistor R4("R4", "N", "R124", 12);
        C1.addComponent(&B1);
        C1.addComponent(&R1);
        C1.addComponent(&R2);
        C1.addComponent(&R3);
        C1.addComponent(&R4);
        C1.simulate(numberOfIterations, numberOfLinesToPrint, simulationInSteps);
    }

    {
        circuit C2("C2");
        C2.addConnectionPoint("P");
        C2.addConnectionPoint("L");
        C2.addConnectionPoint("R");
        C2.addConnectionPoint("N");
        battery B1("Bat", "P", "N", voltage);
        resistor R1("R1", "L", "P", 150);
        resistor R2("R2", "R", "P", 50);
        resistor R3("R3", "R", "L", 100);
        resistor R4("R4", "N", "L", 300);
        resistor R5("R5", "N", "R", 250);
        C2.addComponent(&B1);
        C2.addComponent(&R1);
        C2.addComponent(&R2);
        C2.addComponent(&R3);
        C2.addComponent(&R4);
        C2.addComponent(&R5);
        C2.simulate(numberOfIterations, numberOfLinesToPrint, simulationInSteps);
    }

    {
        circuit C3("C3");
        C3.addConnectionPoint("P");
        C3.addConnectionPoint("L");
        C3.addConnectionPoint("R");
        C3.addConnectionPoint("N");
        battery B1("Bat", "P", "N", voltage);
        resistor R1("R1", "L", "P", 150);
        resistor R2("R2", "R", "P", 50);
        capacitor Cap1("C3", "R", "L", 1.0);
        resistor R4("R4", "N", "L", 300);
        capacitor Cap2("C5", "N", "R", 0.75);
        C3.addComponent(&B1);
        C3.addComponent(&R1);
        C3.addComponent(&R2);
        C3.addComponent(&Cap1);
        C3.addComponent(&R4);
        C3.addComponent(&Cap2);
        C3.simulate(numberOfIterations, numberOfLinesToPrint, simulationInSteps);
    }
}
