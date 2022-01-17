/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
