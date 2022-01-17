 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        int footYPosition = 0;
        int size = 3;

        int stepSize();
        void stepForward();
    };

    void run( int howFast, bool startWithLeftFoot);

    Foot leftFoot;
    Foot rightFoot;
};

int Person::Foot::stepSize()
{
    return size;
}

void Person::Foot::stepForward()
{
    footYPosition = 3;
}

void Person::run( int howFast, bool startWithLeftFoot)
{
    if( startWithLeftFoot == true )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward(); // returns void
        leftFoot.stepForward();
    }

    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
}


 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wn o-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

struct CoffeeShop
{
    int numBaristas = 2;
    int numCoffeeMachines = 4;
    int numRegisters = 2;
    int numTables = 12;
    std::string brewMethod = "pour over";

    struct Coffee
    {
        std::string type = "columbian";
        std::string roast = "dark";
    };

    struct Customer
    {
        std::string name = "Customer 1";
        int customerPhoneNumber = 0;
        int customerID = 1;
        bool rewardsMember = false;
        float rewardsBalance = 0.0f;

        bool useRewardsPoints(float rewardsPoints);
        void newMemberPromotion(float incentiveAmount);
        bool contactCustomer(std::string msg = "Your order is ready.");
    };

    bool brewCoffee(Coffee coffeeType, int size, std::string brewType, bool cream, bool sugar, std::string customerName);
    bool grindCoffee(Coffee coffeeType, int courseness, Customer customerA);
    void renameCustomer(Customer customerA, std::string newName);

    Coffee standardBrew;

};

bool CoffeeShop::Customer::contactCustomer(std::string msg)
{
    if( customerPhoneNumber != 0 )
    {
        if( msg.length() > 1 )
        {
            // phoneAPI.sendText(msg, customerPhoneNumber); IDK, this was a bad example in hindsight
            return true;
        }  

    }

    return false;
}

bool CoffeeShop::Customer::useRewardsPoints(float rewardsPoints)
{
    if( rewardsMember == true )
    {
        if( rewardsBalance > rewardsPoints )
        {
            rewardsBalance -= rewardsPoints;
            return true;
        }

    }

    return false;
}

void CoffeeShop::Customer::newMemberPromotion(float incentiveAmount)
{
    rewardsBalance += incentiveAmount;
    contactCustomer("Welcome to the coffee club!");
}

bool CoffeeShop::brewCoffee(Coffee coffeeType, int size, std::string brewType, bool cream, bool sugar, std::string customerName)
{
    std::cout << "New order for " << customerName << ": " << size << " " << brewType << " " << coffeeType.type << " " << coffeeType.roast;
    if( cream)
    {
        std::cout << ", with cream";
    }

    if( sugar)
    {
        std::cout << ", with sugar";
    }
    
    std::cout  << "\n";
    return true;
}

bool CoffeeShop::grindCoffee(Coffee coffeeType, int courseness, Customer customerA)
{
    std::cout << "Courseness: " << courseness << " " << coffeeType.type << " " << coffeeType.roast << " for: " << customerA.name << "\n";
    return true;
}

void CoffeeShop::renameCustomer(Customer customerA, std::string newName)
{
    if( newName.length() > 1)
    {
        customerA.name = newName;
        std::cout << "Customer's name changed to: " << customerA.name << "\n";
    }
    else
    {
        std::cout << "New name too short.\n";
    }
}

struct InvoiceManager
{
    int numInvoices = 234;
    int numClients = 32;
    float outBalance = 10345.24f;
    int numTemplates = 4;
    std::string workType = "mastering";

    struct Invoice
    {
        std::string clientName;
        int invoiceNumber;
        std::string workType = "post";
        float workTime = 0.0f;
        float totalBalance = 0.0f;
        float dueDate;
        bool overdue = false;

        void download(std::string format = "pdf");
        void markAsPaid(Invoice invoiceA);
        void duplicate(Invoice invoiceA);
    };

    struct Client
    {

    };

    Invoice createInvoice(std::string clientName, float dueDate, std::string workType = "post", float workTime = 0.0f);
    bool checkOverdue(Invoice invoice);
    float checkBalance(Client client, Invoice invoice);
};

void InvoiceManager::Invoice::download(std::string format)
{
    std::cout << "https:\\\\my.freshbooks.com\\invoice." << format << "\n";
}

void InvoiceManager::Invoice::markAsPaid(Invoice invoiceA)
{
    invoiceA.totalBalance = 0.0f;
    invoiceA.overdue = false;
}

void InvoiceManager::Invoice::duplicate(Invoice invoiceA)
{
    Invoice invoiceB = invoiceA;    // I would not really do this
}

InvoiceManager::Invoice InvoiceManager::createInvoice(std::string name, float date, std::string type, float time)
{
    Invoice newInvoice;
    newInvoice.clientName = name;
    numInvoices += 1;
    newInvoice.invoiceNumber = numInvoices;
    newInvoice.dueDate = date;
    newInvoice.workType = type;
    newInvoice.workTime = time;

    return newInvoice;
}

bool InvoiceManager::checkOverdue(Invoice invoiceA)
{
    std::cout << "Invoice " << invoiceA.invoiceNumber << " is ";
    if( invoiceA.overdue == false)
    {
        std::cout <<  "not ";
    }
    std::cout << "overdue.\n";

    return invoiceA.overdue;
}

struct ScooterRental
{
    float rentalTime = 0.0f;
    int distanceTraveled = 0;
    float latitude = 34.052235f;
    float longitude = -118.243683f;
    float balance = 1.0f;
    float voltage = 100.0f;

    void accelerate(float throttle = 0.0f);
    void brake(float brake = 0.0f);
    float lock();
};

void ScooterRental::accelerate(float throttle)
{
    voltage = voltage * throttle;
}

void ScooterRental::brake(float brake)
{
    voltage -= brake;
}

float ScooterRental::lock()
{
    brake(1.0f);
    
    return balance;
}

struct PaintballGun 
{
    int pressure = 333;
    int hopper = 100;
    int chamber = 0;
    float oil = 1.0f;
    float valve = 0.5f;

    bool shoot();
    bool load(); 
    void lock();
};

bool PaintballGun::shoot()
{
    if( chamber == 1)
    {
        // shoot it
        chamber = 0;
        return true;
    }

    return false;
}

void PaintballGun::lock()
{
    pressure = 0;
}

struct Propeller
{
    float voltage = 11.1f;
    float speed = 12.0f;
    float size = 5.0f;
    float weight = 6.2f;
    int efficiency = 70;

    float accelerate(float voltage);
    float maintain(float speed);
    float getSpeed();
};

float Propeller::accelerate(float newVoltage)
{
    voltage = newVoltage;
    return voltage * efficiency;
}

float Propeller::getSpeed()
{
    return speed;
}

float Propeller::maintain(float targetSpeed)
{
    if( speed < targetSpeed)
    {
        voltage += 1;
    }
    else if( speed > targetSpeed)
    {
        voltage -= 1;
    }

    return voltage;
}

struct Battery
{
    float voltage = 3.7f;
    int cells = 1;
    int capacity = 750;
    int crating = 45;
    std::string type = "LiPo";

    float charge();
    float discharge();
    void disconnect();
};

float Battery::charge()
{
    if( voltage < 3.7f)
    {
        voltage += 1.0f;
    }

    return voltage;
}

float Battery::discharge()
{
    if( voltage > 0.0f)
    {
        voltage -= 1;
    }

    return voltage;
}

void Battery::disconnect()
{
    voltage = 0.0f;
}

struct GPS
{
    float latitude = 34.052235f;
    float longitude = -118.243683f;
    float altitude = 0.0f;
    float time = 1541393269.3742561f;
    int signal = 99;

    void getLocation();
    float getTime(float latitude, float longitude);
    int getSignal();
};

void GPS::getLocation()
{
    std::cout << "Location: " << latitude << ", " << longitude << "\n";
}

float GPS::getTime(float targetLatitude, float targetLongitude)
{
    std::cout << "Retrieving data from GPS for coordinates: " << targetLatitude << ", " << targetLongitude << "...\n";
    //  mystery function to get time
    return time;
}

int GPS::getSignal()
{
    return signal;
}

struct Preset
{
    std::string name = "barrel roll";
    std::string type = "maneuver";
    int number = 1;
    int size = 2;
    std::string author = "Toby";

    bool savePreset(std::string name, std::string type, std::string author);
    bool checkPreset(Preset presetA);
    void renamePreset(std::string newName);
};

bool Preset::savePreset(std::string newName, std::string newType, std::string newAuthor)
{
    Preset newPreset;
    newPreset.name = newName;
    newPreset.type = newType;
    newPreset.author = newAuthor;

    return true;
}

bool Preset::checkPreset(Preset presetA)
{
    if ( presetA.size > 0)
    {
        return true;
    }

    return false;
}

void Preset::renamePreset(std::string newName)
{
    if( newName.length() > 0)
    {
        name = newName;
    }

}

struct CPU
{
    float speed = 2.1f;
    int numCores = 2;
    int memory = 512;
    std::string model = "U11X";
    std::string architecture = "ARM"; 


    float getSpeed();
    void balance();
    void runPreset(Preset preset);
};

float CPU::getSpeed()
{
    float droneSpeed = 0.0f;
    // connect to GPS and compare position at different times
    return droneSpeed;
}

void CPU::balance()
{
    // run Propeller.maintain on all relevant propellers
}

void CPU::runPreset(Preset presetA)
{
    std::cout << "Running preset " << presetA.name << ".\n";
    // execute the preset
}

struct Drone
{
    Propeller propellerA;
    Propeller propellerB;
    Propeller propellerC;
    Propeller propellerD;
    Battery batteryA;
    GPS gpsA;
    CPU cpuA;
    Preset presetA;
    Preset presetLand;

    void liftOff();
    void maneuver(float input); 
    bool land();
};

void Drone::liftOff()
{
    if( gpsA.altitude > 0) // hmm
    {
        propellerA.accelerate(3.0f);
        propellerB.accelerate(3.0f);
        propellerC.accelerate(3.0f);
        propellerD.accelerate(3.0f);
    }
}

void Drone::maneuver(float input)
{
    
    propellerA.accelerate(input);
    propellerB.accelerate(input);
    propellerC.accelerate(input);
    propellerD.accelerate(input);
}

bool Drone::land()
{
    if( gpsA.altitude > 0)
    {
        // check the lidar!
        return true;
    }
    
    return false;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
