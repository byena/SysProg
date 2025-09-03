#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <iomanip>  

using namespace std;

int main(int argc, char* argv[])
{
    map<string, float> rates = {
        {"RUB", 1.0},      
        {"USD", 90.0},     
        {"EUR", 100.0},    
        {"GBP", 120.0},
        {"rub", 1.0},      
        {"usd", 90.0},     
        {"eur", 100.0},    
        {"gbp", 120.0},
        {"₽", 1.0},      
        {"$", 90.0},     
        {"€", 100.0},    
        {"£", 120.0},
    };

    string currentFrom;
    string currentTo;
    float amount;

    cout << "Hello\n";
    cout << "input 'exit' to quit \n\n";

    while (true) {
        try {
            cout << "from: ";
            cin >> currentFrom;
            if (currentFrom == "exit" || currentFrom == "quit") {
                cout << "exiting\n";
                break;
            }

            cout << "to: ";
            cin >> currentTo;
            if (currentTo == "exit" || currentTo == "quit") {
                cout << "exiting\n";
                break;
            }

            cout << "amount: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("invalid input.");
            }
            cin.ignore(); 

            if (amount < 0) {
                throw domain_error("sum cant be negative");
            }

            if (rates.find(currentFrom) == rates.end()) {
                throw out_of_range("Current '" + currentFrom + "' not found");
            }
            if (rates.find(currentTo) == rates.end()) {
                throw out_of_range("Current '" + currentTo + "' not found");
            }

            double result = amount * rates[currentFrom] / rates[currentTo];

            
            cout << fixed << amount << " " << currentFrom << " = " << result << " " << currentTo << "\n\n";

            

        }
        catch (const domain_error& e) {
            cerr << "Error: " << e.what() << "\n\n";
        }
        catch (const out_of_range& e) {
            cerr << "Error: " << e.what() << "\n\n";
        }
        catch (const invalid_argument& e)
        {
            cerr << "Error: " << e.what() << "\n\n";
            cin.ignore(10000, '\n');
        }
        catch (const exception& e) {
            cerr << "Error " << e.what() << "\n\n";
        }
    }

    return 0;
}