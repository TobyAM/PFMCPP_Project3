/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




struct CoffeeShop
{
    int numBaristas = 2;
    int numCoffeeMachines { 4 };
    int numRegisters;
    int numCustomers { 0 } ;
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
        int coarseness = 1;

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
    bool grindCoffee(Coffee coffeeType, int coarseness, Customer customerA);
    void renameCustomer(Customer& customerA, std::string newName); // changed to a reference after some googling because it wasn't working right
    void pourCoffee(Coffee coffee, int size);

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

bool CoffeeShop::grindCoffee(Coffee coffeeType, int coarseness, Customer customerA)
{
    for( int i = coffeeType.coarseness; i < coarseness; ++i)
    {
        std::cout << "... grinding coffee to coarseness " << i << std::endl;
    }
    std::cout << "Ground coffee to coarseness " << coarseness << ", " << coffeeType.type << ", " << coffeeType.roast << " for: " << customerA.name << "\n";
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

void CoffeeShop::pourCoffee(Coffee coffee, int size)
{
    std::cout << "Pouring coffee...\n";
    for( int i = 1; i < size; ++i)
    {
        if( i == size)
        {
            std::cout << "FULL!\n";
            return;
        }

        std::cout << "Volume at " << i << ", keep pouring... " << std::endl;
    }

    std::cout << "Size " << size << " " << coffee.roast << " " << coffee.type << " coffee poured.\n";
}

struct InvoiceManager
{
    int numInvoices;
    int numClients;
    float outBalance;
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
    void printHolidyCards();
};

InvoiceManager::InvoiceManager() : numInvoices(234), numClients(32), outBalance(10345.24f), numTemplates(4), workType("mastering")
{
    std::cout << "InvoiceManager::InvoiceManager UDT being constructed!" << std::endl; 
}

InvoiceManager::Invoice::Invoice() : workType("post"), workTime(0.0f), totalBalance(0.0f), overdue(false)
{
    std::cout << "InvoiceManager::Invoice::Invoice UDT being constructed!" << std::endl; 
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

void InvoiceManager::printHolidyCards()
{
    std::cout << "Printing holiday cards for all " << numClients << " clients...\n";
    int i = 0;
    while( i < numClients )
    {
        i += 1;
        std::cout << "Printing card # " << i << std::endl;
    }

}

struct ScooterRental
{
    float rentalTime = 0.0f;
    int distanceTraveled, speed { 0 };
    float latitude, longitude, balance, voltage;

    ScooterRental();

    void accelerate(float throttle = 0.0f);
    void brake(float brake = 0.0f);
    float lock();
    void cruiseControl(int targetSpeed);
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

void ScooterRental::cruiseControl(int targetSpeed)
{
    std::cout << "Engaging cruise control at speed " << targetSpeed << std::endl;
    for( ; speed < targetSpeed; ++speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    for( ; speed > targetSpeed; --speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    if( speed == targetSpeed) std::cout << "Cruisin' at " << speed << "\n";
}

struct PaintballGun 
{
    int pressure, hopper, chamber;
    float oil, valve;
    bool triggerLock;

    PaintballGun();

    bool shoot();
    bool load();
    void automatic();
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
    if( hopper > 0)
    {
        if( chamber == 0)
        {
            chamber = 1;
            hopper -= 1;
            std::cout << "The chamber was successfully loaded!" << std::endl;
            return true;
        }

        std::cout << "The chamber was already loaded!" << std::endl;    
        return false;
    }

    std::cout << "The hopper is empty!\n";
    return false;
}

void PaintballGun::automatic()
{
    std::cout << "Lead finger engaged! Firing automatically:\n";
    for( ; load(); shoot());
}

struct Propeller
{
    float voltage;
    int speed;
    float size;
    float weight;
    int efficiency;

    Propeller();

    float accelerate(float voltage);
    int maintain(int speed ); // gonna revise this as it's perfect for while
    float getSpeed();
};

Propeller::Propeller() :
voltage(11.1f),
speed(12),
size(5.0f),
weight(6.2f),
efficiency(70)
{
    std::cout << "Propeller UDT being constructed!" << std::endl;
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

int Propeller::maintain(int targetSpeed)
{
    std::cout << "Engaging cruise control.\n";
    while( speed < targetSpeed)
    {
        speed += 1;
        std::cout << "Speed is " << speed << ".\n";
    }

    while( speed > targetSpeed)
    {
        speed -= 1;
        std::cout << "Speed is " << speed << ".\n";
    }
    
    std::cout << "Speed " << speed << " maintained.\n";

    return speed;
}

struct Battery
{
    float voltage;
    int cells;
    int capacity;
    int crating;
    std::string type;

    Battery();

    float charge(float targetCharge); // going to mod this
    float discharge(); 
    void disconnect();
};

Battery::Battery() : voltage(3.7f), cells(1), capacity(750), crating(45), type("LiPo")
{
    std::cout << "Battery UDT being constructed!" << std::endl; 
}

float Battery::charge(float targetCharge)
{
    std::cout << "Battery charging to " << targetCharge << " v...\n";
    while( voltage + 0.1f < targetCharge)
    {
        voltage += 0.1f;
        std::cout << "Voltage is " << voltage << ".\n";
    }

    std::cout << "Battery charged to " << targetCharge << " v!\n";
    return voltage;
}

float Battery::discharge()
{
    
    std::cout << "Battery discharging....\n";
    while( voltage - 1.0f > 0.0f)
    {
        voltage -= 1.0f;
        std::cout << "Voltage is " << voltage << ".\n";
    }
    
    std::cout << "Battery discharged!\n";

    return voltage;
}

void Battery::disconnect()
{
    voltage = 0.0f;
    std::cout << "Voltage is " << voltage << ".\n";
}

struct GPS
{
    float latitude { 34.052235f };
    float longitude { -118.243683f };
    float altitude { 0.0f };
    float time { 1541393269.3742561f };
    int signal { 99 };

    GPS();

    void getLocation();
    float getTime(float latitude, float longitude);
    int getSignal(); // modifying this 
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
    std::cout << "Signal strength is " << signal << ":\n" << "______\n";
    for( int i = 0; i < signal / 20; --i)
    {
        for( int n = 0; n < 4 - i; ++n)
        {
            std::cout << " ";
        }

        for( int n = i; n > -1; --n)
        {
            std::cout << "|";
        }

        std::cout << std::endl;

        
    }

    std::cout << "------\n\n";

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
    void generateSuffix();
};

Preset::Preset() : name("barrel roll"), type("maneuver"), author("Toby"), number(1), size(2)
{
    std::cout << "Preset UDT being constructed!" << std::endl;
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

void Preset::generateSuffix()
{
    int r;
    char c;
    std::string oldName = name;
    name += " ";
    // srand (time(nullptr)); commented out for warning
    std::cout << "Generating suffix: ";
    for( int i = 0; i < 9; --i)
    {
        r = std::rand() % 26;
        c = 'a' + char(r);
        name += c;
        std::cout << c;
    }

    std::cout << std::endl;

    std::cout << "Preset " << oldName << "'s name changed to: " << name << std::endl;
}

struct CPU
{
    float speed;
    int numCores;
    int memory;
    std::string model;
    std::string architecture;
    int temp;

    CPU();

    float getSpeed();
    void balance();
    void runPreset(Preset preset);
    void thermalThrottle(int maxTemp);

};

CPU::CPU() :
speed(2.1f),
numCores(2),
memory(512),
model("U11X"),
architecture("ARM"),
temp(90)
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

void CPU::thermalThrottle(int maxTemp)
{
    std::cout << "Thermal limit set to: " << maxTemp << std::endl;
    for( ; temp > maxTemp; --temp)
    {
        speed = temp * 0.02f;
        std::cout << "Package too hot at " << temp << " degrees. Cooling down... Speed now " << speed << std::endl;
    }

    std::cout << "Optimal temperature range reached at a speed of " << speed << std::endl;

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
    void hover(float targetAltitude);
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

void Drone::hover(float targetAltitude)
{
    std::cout << "Engaging fixed hover at " << targetAltitude << "ft.\n";

    for( ; gpsA.altitude < targetAltitude; ++gpsA.altitude )
    {
        maneuver(3.0);
        std::cout << "Altitude: " << gpsA.altitude << std::endl; 
    }

    for( ; gpsA.altitude > targetAltitude; --gpsA.altitude )
    {
        maneuver(0.0);
        std::cout << "Altitude: " << gpsA.altitude << std::endl; 
    }

    if( targetAltitude + 0.1f > gpsA.altitude ) if( targetAltitude - 0.1f < gpsA.altitude )
    {
        std::cout << "Target altitude of " << targetAltitude << "ft. reached!\n";
        propellerA.maintain(propellerA.speed);
        propellerB.maintain(propellerB.speed);
        propellerC.maintain(propellerC.speed);
        propellerD.maintain(propellerD.speed);
    }


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
    broBucks.grindCoffee(broBucks.standardBrew, 10, tobyMason);
    broBucks.brewCoffee(broBucks.standardBrew, 2, "cold brew", true, false,"Toby Mason");
    broBucks.pourCoffee(broBucks.standardBrew, 3);

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
    tobyInvoices.printHolidyCards();
    testInvoice.download();
    testInvoice.markAsPaid(testInvoice);
    std::cout << "Invoice " << testInvoice.invoiceNumber << " remaining balance: " << testInvoice.totalBalance << std::endl;
    testInvoice.duplicate(testInvoice);

    std::cout << std::endl; // new UDT
    
    ScooterRental tobysScooter;

    tobysScooter.accelerate( 1.5f);
    tobysScooter.brake(100.0f);
    tobysScooter.cruiseControl(10);
    tobysScooter.cruiseControl(4);
    tobysScooter.lock();

    std::cout << std::endl; // new UDT

    PaintballGun tobysMarker;

    tobysMarker.shoot();
    tobysMarker.load();
    tobysMarker.lock();
    tobysMarker.shoot();
    tobysMarker.lock();
    tobysMarker.shoot();
    tobysMarker.hopper = 12;
    tobysMarker.automatic();
    std::cout << std::endl;

    std::cout << std::endl; // new UDT

    Propeller propA;
    
    propA.accelerate(12.0f);
    propA.maintain( 20);
    propA.getSpeed();

    std::cout << std::endl; // new UDT

    Battery cellA;

    cellA.charge(5.0f);
    cellA.discharge();
    cellA.disconnect();

    std::cout << std::endl; // new UDT

    GPS gpsNew;

    gpsNew.getLocation();
    gpsNew.getTime(19, 19);
    gpsNew.getSignal();
    gpsNew.signal = 44;
    gpsNew.getSignal();
    gpsNew.signal = 0;
    gpsNew.getSignal();

    std::cout << std::endl; // new UDT

    Preset tobysPreset;

    tobysPreset.savePreset("barrel roll", "evasion", "TM");
    tobysPreset.checkPreset(tobysPreset);
    tobysPreset.renamePreset("Barrel Roll");
    tobysPreset.generateSuffix();

    std::cout << std::endl; // new UDT

    CPU cpuA;

    cpuA.getSpeed();
    cpuA.balance();
    cpuA.runPreset(tobysPreset);
    cpuA.thermalThrottle(80);

    std::cout << std::endl; // new UDT

    Drone tobysDrone;

    tobysDrone.liftOff();
    tobysDrone.hover(20.0f);
    tobysDrone.maneuver(5.0f);
    tobysDrone.land();
}
