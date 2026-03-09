#include<iostream>
using namespace std;

class TollBooth{
    private:
    static int totalVehical;
    static double totalRevanue;
    
    public:
    static void reset()
    {
        totalVehical = 0;
        totalRevanue = 0;
    }
    
    static void vehicalPayingToll(int vehicalType) 
    {
        double tollAmount;
        if(vehicalType == 1)
        {
           tollAmount = 180;
        }
        else if(vehicalType == 2)
        {
            tollAmount = 300;
        }
        else{
            tollAmount = 350;
        }
        totalRevanue += tollAmount;
        totalVehical++;
        cout << "Toll collected: Rs. " << tollAmount << endl;
    }

    static int getTotalVehicles()
    {

        return totalVehical;
    }
    static double getTotalRevenue()
    {
        return totalRevanue;
    }
};

int TollBooth :: totalVehical= 0;
double TollBooth :: totalRevanue = 0;
    

int main()
{
    int choice;
    do{
        cout << "\n===== TOLL BOOTH MENU =====\n";
        cout << "1. Add Standard Car (Rs.180)\n";
        cout << "2. Add Truck (Rs.250)\n";
        cout << "3. Add Bus (Rs.350)\n";
        cout << "4. Display Total Vehicles\n";
        cout << "5. Display Total Revenue\n";
        cout << "6. Reset Booth Statistics\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            TollBooth::vehicalPayingToll(1);
            break;
        case 2:
            TollBooth::vehicalPayingToll(2);
            break;
        case 3:
            TollBooth::vehicalPayingToll(3);
            break;
        case 4:
            cout<<"total no of vehicals: " <<TollBooth::getTotalVehicles()<<"\n";
            break;
        case 5:
            cout<<"total revanue : "<< TollBooth::getTotalRevenue()<<"\n";
            break;
        case 6:
            TollBooth::reset();
            break;
        case 7:
            cout<<"Exiting";
            break;
        default:
            break;
        }
    }
    while (choice  != 7);
    
}

