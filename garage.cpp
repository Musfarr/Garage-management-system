#include <iostream>
#include <cstring>
using namespace std;

class Car
{
    private:
        string colour;
    public:
        Car(string* color_in);
        string getColor();
};
Car::Car(string* color_in)
{
    colour= *color_in;
}
string Car::getColor()
{
    return colour;
}

using namespace std;
int main()
{
    //declare and initialize an array of garages
    Car* in_garages[10];
    //set all pointers to NULL
    for (int i = 0; i < 10; i++)
    {
        in_garages[i] = NULL;
    }

    //temporary storages for keyboard input
    int choice = 0, garage_number;
    string temp_color;

    while (choice != 3)
    {
        cout << "Enter 1 to put car in garage, 2 to remove it, 3 to quit.";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Following garages are empty.";
            for (int i = 0; i<10; i++)
            {
                if(in_garages[i] == NULL)
                {
                    cout << (i+1) << " " ; 
                }
            }
            cout << endl << "Enter garage number for car to occupy ";
            cin >> garage_number;
            
            //if user has an empty garage
            if (in_garages[garage_number-1] == NULL)
            {
                cout << "Enter color of car ";
                cin >> temp_color;
                //instance a new car object via pointer
                in_garages[garage_number-1] = new Car(&temp_color);
                cout << "Car of color " << in_garages[garage_number-1]->getColor() << " is in garage." << endl;
            }
            else
            {
                cout << "Garage is not empty." << endl;
            }
        }
        if (choice == 2)
        {
            cout << "The following garage numbers are occupied ";
            for (int i = 0; i < 10; i++)
            {
                if (in_garages[i] != NULL)
                {

                    cout << (i+1) << " ";
                }
            }
            cout << endl << "Enter garage number to empty.";
            cin >> garage_number;
            if (in_garages[garage_number-1] != NULL)
            {
                cout << "car of color " << in_garages[garage_number-1]->getColor()
                << " removed from garage." << endl;

                delete in_garages[garage_number-1];
                in_garages[garage_number-1] = NULL;
            }
            else
            {
                cout << "Garage is already empty." << endl;
            }
        }
    }
    //cleanup not necessary
        return 0;
}