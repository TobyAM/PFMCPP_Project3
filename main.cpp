/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; // in-class initialization
    UDT() : a(0) { } // 'constructor-initializer-list' member variable initialization
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



struct CoffeeShop
{
    int numBaristas = 2;
    int numCoffeeMachines { 4 };
    int numRegisters;
    CoffeeShop() : numRegisters(2)
    {
        std::cout << "CoffeeShop UDT being constructed!" << std::endl;  
    }
    int numTables = 12;
    std::string brewMethod = "pour over";

    struct Coffee
    {
        std::string type = "columbian";
        std::string roast { "dark" };

        Coffee();
    };

    struct Customer
    {
        std::string name = "New Customer";
        float customerPhoneNumber { 0.0f };
        int customerID;
        bool rewardsMember;
        float rewardsBalance;

        Customer();

        bool useRewardsPoints(float rewardsPoints);
        void newMemberPromotion(float incentiveAmount);
        bool contactCustomer(std::string msg = "Your order is ready.");
    };

    bool brewCoffee(Coffee coffeeType, int size, std::string brewType, bool cream, bool sugar, std::string customerName);
    bool grindCoffee(Coffee coffeeType, int courseness, Customer customerA);
    void renameCustomer(Customer& customerA, std::string newName); // changed to a reference after some googling because it wasn't working right

    Coffee standardBrew;

};


CoffeeShop::Coffee::Coffee()
{
    std::cout << "CoffeeShop::Coffee UDT being constructed!" << std::endl;  
}

CoffeeShop::Customer::Customer() : customerID(1), rewardsMember(false), rewardsBalance(0.0f)
{
    std::cout << "CoffeeShop::Customer UDT being constructed!" << std::endl;  

}

bool CoffeeShop::Customer::contactCustomer(std::string msg)
{
    if( customerPhoneNumber > 0 )
    {
        if( msg.length() > 1 )
        {
            std::cout << "Texting " << name << ": \"" << msg << "\"" << std::endl;
            return true;
        }
        else std::cout << "Message is too short.\n";

    }
    else std::cout << name << " doesn't have a phone number saved.\n";

    return false;
}

bool CoffeeShop::Customer::useRewardsPoints(float rewardsPoints)
{
    if( rewardsMember == true )
    {
        if( rewardsBalance > rewardsPoints )
        {
            rewardsBalance -= rewardsPoints;
            std::cout << name << " used " << rewardsPoints << " points, leaving a balance of " << rewardsBalance << "\n";
            return true;
        }
        else std::cout << name << " doesn't have enough points.\n";

    }
    else std::cout << name << " is not a rewards member!\n";

    return false;
}

void CoffeeShop::Customer::newMemberPromotion(float incentiveAmount)
{
    rewardsBalance += incentiveAmount;
    rewardsMember = true;
    contactCustomer("Welcome to the coffee club!");
}

bool CoffeeShop::brewCoffee(Coffee coffeeType, int size, std::string brewType, bool cream, bool sugar, std::string customerName)
{
    std::cout << "New order for " << customerName << ": size " << size << ", " << brewType << ", " << coffeeType.type << ", " << coffeeType.roast;
    if( cream)
    {
        std::cout << ", with cream";
    }

    if( sugar)
    {
        std::cout << ", with sugar";
    }
    
    std::cout << std::endl;

    return true;
}

bool CoffeeShop::grindCoffee(Coffee coffeeType, int courseness, Customer customerA)
{
    std::cout << "Ground coffee to courseness " << courseness << ", " << coffeeType.type << ", " << coffeeType.roast << " for: " << customerA.name << "\n";
    return true;
}

void CoffeeShop::renameCustomer(Customer& customerA, std::string newName)
{
    if( newName.length() > 1)
    {
        std::cout << customerA.name;
        customerA.name = newName;
        std::cout << "'s name changed to: " << customerA.name << "\n";
    }
    else
    {
        std::cout << "New name too short.\n";
    }
}

struct InvoiceManager
{
    int numInvoices = 234;
    int numClients{32};
    float outBalance{10345.24f};
    int numTemplates;
    std::string workType;

    InvoiceManager();

    struct Invoice
    {
        std::string clientName;
        int invoiceNumber;
        std::string workType;
        float workTime;
        float totalBalance;
        float dueDate;
        bool overdue;

        Invoice();

        void download(std::string format = "pdf");
        void markAsPaid(Invoice& invoiceA);
        void duplicate(Invoice& invoiceA);
    };


    Invoice createInvoice(std::string clientName, float dueDate, std::string workType = "post", float workTime = 0.0f);
    bool checkOverdue(Invoice invoice);
    float checkBalance(Invoice invoice);
};

InvoiceManager::InvoiceManager() : numTemplates(4), workType("mastering")
{
    std::cout << "InvoiceManager::InvoiceManager UDT being constructed!" << std::endl; 
}

InvoiceManager::Invoice::Invoice()
{
    std::cout << "InvoiceManager::Invoice::Invoice UDT being constructed!" << std::endl; 
    workType = "post";
    workTime = 0.0f;
    totalBalance = 0.0f;
    overdue = false;
    std::cout << "workType: " << workType << std::endl;
    std::cout << "workTime: " << workTime << std::endl;
    std::cout << "totalBalance: " << totalBalance << std::endl;
    std::cout << "overdue: false\n";
    
}

void InvoiceManager::Invoice::download(std::string format)
{
    std::cout << "https:\\\\my.freshbooks.com\\invoice." << format << "\n";
}

void InvoiceManager::Invoice::markAsPaid(Invoice& invoiceA)
{
    invoiceA.totalBalance = 0.0f;
    invoiceA.overdue = false;
}

void InvoiceManager::Invoice::duplicate(Invoice& invoiceA)
{
    Invoice invoiceB = invoiceA;    // I would not really do this
    invoiceB.invoiceNumber += 1;
    std::cout << "Duplicated invoice " << invoiceA.invoiceNumber << " as " << invoiceB.invoiceNumber << std::endl;
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

float InvoiceManager::checkBalance(Invoice invoiceA)
{
    std::cout << invoiceA.invoiceNumber << " balance is: " << invoiceA.totalBalance << std::endl;

    return invoiceA.totalBalance;
}

struct ScooterRental
{
    float rentalTime = 0.0f;
    int distanceTraveled{0};
    float latitude, longitude, balance, voltage;

    ScooterRental();

    void accelerate(float throttle = 0.0f);
    void brake(float brake = 0.0f);
    float lock();
};

ScooterRental::ScooterRental() :
latitude(34.052235f),
longitude(-118.243683f),
balance(1.0f),
voltage(100.0f)
{
    std::cout << "ScooterRental UDT being constructed!" << std::endl; 
}

void ScooterRental::accelerate(float throttle)
{
    voltage = voltage * throttle;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

void ScooterRental::brake(float brake)
{
    voltage -= brake;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

float ScooterRental::lock()
{
    voltage = 0.0f;
    std::cout << "The scooter voltage is " << voltage << std::endl;
    
    return balance;
}

struct PaintballGun 
{
    int pressure, hopper, chamber;
    float oil, valve;
    bool triggerLock;

    PaintballGun();

    bool shoot();
    bool load(); 
    void lock();
};

PaintballGun::PaintballGun() : pressure(333), hopper(100), chamber(0), oil(1.0f), valve(0.5f), triggerLock(false)
{
    std::cout << "PaintballGun UDT being constructed!" << std::endl; 
}

bool PaintballGun::shoot()
{
    if (triggerLock)
    {
        std::cout << "Can't fire! Locked!" << std::endl;
        return false;
    }

    if( chamber == 1)
    {
        // shoot it
        chamber = 0;
        std::cout << "Ball shot! ------------->" << std::endl;
        return true;
    }

    std::cout << "The chamber is empty!" << std::endl;
    return false;
}

void PaintballGun::lock()
{
    if( triggerLock)
    {
        triggerLock = false;
        std::cout << "The marker has been un-locked!" << std::endl;
    }
    else
    {
        triggerLock = true;
        std::cout << "The marker has been locked." << std::endl;
    }
}

bool PaintballGun::load()
{
    if( chamber == 0)
    {
        chamber = 1;
        std::cout << "The chamber was successfully loaded!" << std::endl;
        return true;
    }

    std::cout << "The chamber was already loaded!" << std::endl;    
    return false;
}

struct Propeller
{
    float voltage{11.1f};
    float speed{12.0f};
    float size;
    float weight;
    int efficiency;

    Propeller();

    float accelerate(float voltage);
    float maintain(float speed);
    float getSpeed();
};

Propeller::Propeller()
{
    std::cout << "Propeller UDT being constructed!" << std::endl;
    size = 5.0f;
    weight = 6.2f;
    efficiency = 70;
}

float Propeller::accelerate(float newVoltage)
{
    voltage = newVoltage;
    std::cout << "Voltage is " << voltage << ".\n";
    return voltage * efficiency;
}

float Propeller::getSpeed()
{
    std::cout << "Speed is " << speed << ".\n";
    return speed;
}

float Propeller::maintain(float targetSpeed)
{
    if( speed < targetSpeed)
    {
        voltage += 1;
        std::cout << "Voltage is " << voltage << ".\n";
    }
    else if( speed > targetSpeed)
    {
        voltage -= 1;
        std::cout << "Voltage is " << voltage << ".\n";
    }

    return voltage;
}

struct Battery
{
    float voltage;
    int cells;
    int capacity;
    int crating;
    std::string type;

    Battery();

    float charge();
    float discharge();
    void disconnect();
};

Battery::Battery() : voltage(3.7f), cells(1), capacity(750), crating(45), type("LiPo")
{
    std::cout << "Battery UDT being constructed!" << std::endl; 
}

float Battery::charge()
{
    if( voltage < 3.7f)
    {
        voltage += 1.0f;
        std::cout << "Voltage is " << voltage << ".\n";
    }

    return voltage;
}

float Battery::discharge()
{
    if( voltage > 0.0f)
    {
        voltage -= 1;
    }

    std::cout << "Voltage is " << voltage << ".\n";

    return voltage;
}

void Battery::disconnect()
{
    voltage = 0.0f;
    std::cout << "Voltage is " << voltage << ".\n";
}

struct GPS
{
    float latitude{34.052235f};
    float longitude{-118.243683f};
    float altitude{0.0f};
    float time{1541393269.3742561f};
    int signal{99};

    GPS();

    void getLocation();
    float getTime(float latitude, float longitude);
    int getSignal();
};

GPS::GPS()
{
    std::cout << "GPS UDT being constructed!" << std::endl; 
}

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
    std::string name, type, author;
    int number, size;

    Preset();

    bool savePreset(std::string name, std::string type, std::string author);
    bool checkPreset(Preset presetA);
    void renamePreset(std::string newName);
};

Preset::Preset()
{
    std::cout << "Preset UDT being constructed!" << std::endl;
    name = "barrel roll";
    type = "maneuver";
    number = 1;
    size = 2;
    author = "Toby";
}

bool Preset::savePreset(std::string newName, std::string newType, std::string newAuthor)
{
    Preset newPreset;
    newPreset.name = newName;
    newPreset.type = newType;
    newPreset.author = newAuthor;
    std::cout << "Preset " << newPreset.name << ", type " << newPreset.type << ", author " << newPreset.author << ".\n";

    return true;
}

bool Preset::checkPreset(Preset presetA)
{
    if ( presetA.size > 0)
    {
        std::cout << "Preset is empty.\n";
        return true;
    }
    std::cout << "Preset is " << size << "MB.\n";

    return false;
}

void Preset::renamePreset(std::string newName)
{
    if( newName.length() > 0)
    {
        name = newName;
        std::cout << "Renamed preset: " << name << ".\n";
    }

}

struct CPU
{
    float speed;
    int numCores;
    int memory;
    std::string model;
    std::string architecture;

    CPU();

    float getSpeed();
    void balance();
    void runPreset(Preset preset);
};

CPU::CPU() :
speed(2.1f),
numCores(2),
memory(512),
model("U11X"),
architecture("ARM")
{
    std::cout << "CPU UDT being constructed!" << std::endl; 
}


float CPU::getSpeed()
{
    std::cout << "Speed is " << speed << ".\n";
    // connect to GPS and compare position at different times
    return speed;
}

void CPU::balance()
{
     std::cout << "Balancing the load.\n";
    // run Propeller.maintain on all relevant propellers
}

void CPU::runPreset(Preset presetA)
{
    std::cout << "Running preset " << presetA.name << ".\n";
    // execute the preset
}

struct Drone
{
    Propeller propellerA, propellerB, propellerC, propellerD;
    Battery batteryA;
    GPS gpsA;
    CPU cpuA;
    Preset presetA, presetLand;

    Drone();

    void liftOff();
    void maneuver(float input); 
    bool land();
};

Drone::Drone()
{
    std::cout << "Drone UDT being constructed!" << std::endl; 
}

void Drone::liftOff()
{
    if( gpsA.altitude > 0.0f)
    {
        std::cout << "Already airborn!\n";
    }

    else
    {
        propellerA.accelerate(3.0f);
        propellerB.accelerate(3.0f);
        propellerC.accelerate(3.0f);
        propellerD.accelerate(3.0f);

        gpsA.altitude += 1.0f;

        std::cout << "Lifting off!\n";
    }
}

void Drone::maneuver(float input)
{
    
    propellerA.accelerate(input);
    propellerB.accelerate(input);
    propellerC.accelerate(input);
    propellerD.accelerate(input);

    std::cout << "Manuevering drone!\n";
}

bool Drone::land()
{
    if( gpsA.altitude > 0.0f)
    {
        // check the lidar!
        std::cout << "Landing. Clear landing area!\n";
        gpsA.altitude -= 1.0f;
        return true;
    }
    
    std::cout << "Can't land. Already on ground!\n";
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

    std::cout << std::endl; // new UDT

    CoffeeShop broBucks;
    CoffeeShop::Customer tobyMason;

    broBucks.renameCustomer(tobyMason, "Toby Mason");
    broBucks.grindCoffee(broBucks.standardBrew, 2, tobyMason);
    broBucks.brewCoffee(broBucks.standardBrew, 2, "cold brew", true, false,"Toby Mason");

    std::cout << std::endl; // new UDT

    tobyMason.useRewardsPoints( 130.0f);
    tobyMason.newMemberPromotion( 3.0f);
    std::cout << "Toby's rewards's balance is now: " << tobyMason.rewardsBalance << std::endl;
    tobyMason.useRewardsPoints( 12.0f);
    tobyMason.useRewardsPoints( 2.0f);
    tobyMason.contactCustomer();
    tobyMason.customerPhoneNumber = 3233933291;
    tobyMason.contactCustomer("k");
    tobyMason.contactCustomer();

    std::cout << std::endl; // new UDT

    InvoiceManager tobyInvoices;
    InvoiceManager::Invoice testInvoice;
    
    tobyInvoices.createInvoice("test invoice 2", 346255342.0f);
    testInvoice.invoiceNumber = 5;
    tobyInvoices.checkOverdue(testInvoice);
    testInvoice.totalBalance = 543.21f;
    tobyInvoices.checkBalance(testInvoice);
    testInvoice.download();
    testInvoice.markAsPaid(testInvoice);
    std::cout << "Invoice " << testInvoice.invoiceNumber << " remaining balance: " << testInvoice.totalBalance << std::endl;
    testInvoice.duplicate(testInvoice);

    std::cout << std::endl; // new UDT
    
    ScooterRental tobysScooter;

    tobysScooter.accelerate( 1.5f);
    tobysScooter.brake(100.0f);
    tobysScooter.lock();

    std::cout << std::endl; // new UDT

    PaintballGun tobysMarker;

    tobysMarker.shoot();
    tobysMarker.load();
    tobysMarker.lock();
    tobysMarker.shoot();
    tobysMarker.lock();
    tobysMarker.shoot();
    std::cout << std::endl;

    std::cout << std::endl; // new UDT

    Propeller propA;
    
    propA.accelerate(12.0f);
    propA.maintain( 10.0f);
    propA.getSpeed();

    std::cout << std::endl; // new UDT

    Battery cellA;

    std::cout << "cellA is charging with voltage: " << cellA.charge() << std::endl;
    cellA.discharge();
    cellA.disconnect();

    std::cout << std::endl; // new UDT

    GPS gpsNew;

    gpsNew.getLocation();
    gpsNew.getTime(19, 19);
    std::cout << "Signal strength is " << gpsNew.getSignal() << std::endl;

    std::cout << std::endl; // new UDT

    Preset tobysPreset;

    tobysPreset.savePreset("barrel roll", "evasion", "TM");
    tobysPreset.checkPreset(tobysPreset);
    tobysPreset.renamePreset("Barrel Roll");

    std::cout << std::endl; // new UDT

    CPU cpuA;

    cpuA.getSpeed();
    cpuA.balance();
    cpuA.runPreset(tobysPreset);

    std::cout << std::endl; // new UDT

    Drone tobysDrone;

    tobysDrone.liftOff();
    tobysDrone.maneuver(5.0f);
    tobysDrone.land();

    
}
