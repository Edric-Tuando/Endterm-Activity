#include <iostream>
#include <string>
using namespace std;

class Transport {
    public:
        string name;
        double distance;
        
        Transport(string n, double d) {
            name = n;
            distance = d;
        }

        virtual double fareCalc() = 0;
        virtual double timeCalc() = 0;

        void display() {
            cout << "Name: " << name << endl;
            cout << "Distance: " << distance << " km" << endl;
        }

        void display(bool showFare) {
            display();
            if (showFare) {
                cout << "Fare will be computed based on ride type." << endl;
            }
        }

    virtual ~Transport() {}
};

class GrabSaver : public Transport {
    public:
        GrabSaver(string n, double d) : Transport(n, d) {}

        double fareCalc() {
            return 45 + (distance * 15);
        }

        double timeCalc() {
            return (distance / 30) * 60;
        }
};

class GrabTaxi : public Transport {
    public:
        GrabTaxi(string n, double d) : Transport(n, d) {}

        double fareCalc() {
            return 60 + (distance * 15);
        }

        double timeCalc() {
            return (distance / 40) * 60;
        }
};

class GrabCar : public Transport {
    public:
        GrabCar(string n, double d) : Transport(n, d) {}

        double fareCalc() {
            return 75 + (distance * 20);
        }

        double timeCalc() {
            return (distance / 35) * 60;
        }
};

double operator-(Transport &a, Transport &b) {
    return a.fareCalc() - b.fareCalc();
}

int main() {
    string name;
    double distance;
    int choice;

    cout << "===== Welcome to Grab! =====" << endl;
    cout << "Enter Your Name: ";
    cin >> name;

    cout << "Enter Distance (km): ";
    cin >> distance;
    do {
        if (distance <= 0) {
            cout << "Invalid distance. Please enter a positive value." << endl;
            cout << "Enter Distance (km): ";
            cin >> distance;
        }
    } while (distance <= 0);

    cout << "Available Rides Today:" << endl;
    cout << "1. GrabSaver" << endl;
    cout << "2. GrabTaxi" << endl;
    cout << "3. GrabCar" << endl;
    cout << "Choose Your Ride: ";
    cin >> choice;
    cout << endl;

    Transport* t = nullptr; 

    do {
        if (choice < 1 || choice > 3) {
            cout << "Invalid Input, Please Try Again!\n" << endl;
            cout << "Available Rides Today:" << endl;
            cout << "1. GrabSaver" << endl;
            cout << "2. GrabTaxi" << endl;
            cout << "3. GrabCar" << endl;
            cout << "Choose Your Ride: ";
            cin >> choice;
            cout << endl;
        }
    } while (choice < 1 || choice > 3);

    if (choice == 1) {
        t = new GrabSaver(name, distance);
    } else if (choice == 2) {
        t = new GrabTaxi(name, distance);
    } else if (choice == 3) {
        t = new GrabCar(name, distance);
    }

    t->display(true);
    cout << "\nFare: Php " << t->fareCalc() << endl;
    cout << "Estimated Time: " << t->timeCalc() << " minutes" << endl;

    GrabSaver saver("Saver", distance);
    GrabTaxi taxi("Taxi", distance);
    GrabCar car("Car", distance);

    if (choice == 1) {
        cout << "You Saved Php " << (taxi - saver) << " Compared in using GrabTaxi!" << endl;
        cout << "You Saved Php " << (car - saver) << " Compared in Using GrabCar!" << endl;
    }
    else if (choice == 2) {
        cout << "You Saved Php " << (car - taxi) << " Compared in Using GrabCar!" << endl;
        cout << "You Spent Php " << (taxi - saver) << " More Compared in Using GrabSaver!" << endl;
    }
    else if (choice == 3) {
        cout << "You Spent Php " << (car - saver) << " More Compared in Using GrabSaver!" << endl;
        cout << "You Spent Php " << (car - taxi) << " More Compared in Using GrabTaxi!" << endl;
    }

    cout << "\nThank you for using Grab, " << name << "!" << endl;

    delete t;
    return 0;
}