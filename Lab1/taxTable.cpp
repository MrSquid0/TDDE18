#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

/*Comment: Complementary work NOT needed, your tax table prints 1 013 802 lines
           when inputting first price = 0, last price = 10000, stride = 0.01
           tax = 0. Does that seem right? HINT: error in float numbers*/



int main(){
    float const minPrice{0.0};
    float const maxPrice{10000.0}; //good use of const!
    float const minStride{0.01};
    int minTaxPercentage{0};
    int maxTaxPercentage{100};
    float firstPrice;
    float lastPrice;
    float taxPercentage;
    float stride;
    float tax;
    float priceWithTax;


    cout << "INPUT PART" << endl;
    cout << setfill('=') << setw(12) << "" << endl;
    cout << "Enter first price: ";
    cin >> firstPrice;

    while((firstPrice < minPrice) || (firstPrice > maxPrice)){
        cerr << "ERROR. First price cannot be less than "
        << minPrice << " or more than " << maxPrice << ".\n";
        cout << "Enter a new first price: ";
        cin >> firstPrice;
    }

    cin.ignore(1000, '\n');

    cout << "Enter last price: ";
    cin >> lastPrice;

    while((lastPrice < minPrice) || (lastPrice > maxPrice)){
        cerr << "ERROR. Last price cannot be less than "
        << minPrice << " or more than " << maxPrice << ".\n";
        cout << "Enter a new last price: ";
        cin >> lastPrice;
    }

    cin.ignore(1000, '\n');

    cout << "Enter stride: ";
    cin >> stride;

    while((minStride > stride)){
        cerr << "ERROR. Stride must be at least "
        << minStride << ".\n";
        cout << "Enter a new stride: ";
        cin >> stride;
    }

    cin.ignore(1000, '\n');

    cout << "Enter tax percent: ";
    cin >> taxPercentage;

    while((taxPercentage < minTaxPercentage) ||
    (taxPercentage > maxTaxPercentage)){
        cerr << "ERROR. Tax percentage cannot be less than "
        << minTaxPercentage << " or more than "
        << maxTaxPercentage << ".\n";
        cout << "Enter a new tax percent: ";
        cin >> taxPercentage;
    }

    cout << "TAX TABLE" << endl;
    cout << setfill('=') << setw(12) << "" << endl;
    cout << "Price               Tax            Price with tax\n";
    cout << setfill('-') << setw(49) << "" << setfill(' ') << endl;

    do{
        tax = firstPrice * (taxPercentage/100);
        priceWithTax = tax + firstPrice;

        cout << fixed << setprecision(2) << fixed << firstPrice
        << right << setw(19) << setprecision(2) << fixed
        << tax << right << setw(21) << setprecision(2)
        << fixed << priceWithTax << endl;

        firstPrice+=stride;
    }while(firstPrice<=lastPrice);

}
