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





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


/*
Thing 1) Coffee shop
5 properties:
    1) the number of baristas (int)
    2) the number of coffee machines (int)
    3) the number of registers (int)
    4) the number of tables (int)
    5) the types of coffee (std::string)
3 things it can do:
    1) make a coffee
    2) grind coffee beans
    3) modify customer names
 */

struct CoffeeShop
{
    // 1) the number of baristas (int)
    int numBaristas = 2;
    // 2) the number of coffee machines (int)
    int numCoffeeMachines = 4;
    // 3) the number of registers (int)
    int numRegisters = 2;
    // 4) the number of tables (int)
    int numTables = 12;
    // 5) the types of coffee (std::string)
    std::string brewMethod = "pour over";

    struct Coffee
    {
        std::string type = "columbian";
        std::string roast = "dark";
    };

    struct Customer
    {
        std::string name = "Customer 1";
        int customerPhoneNumber = 1234567890;
        int customerID = 1;
        bool rewardsMember = false;
        float rewardsBalance = 0.0f;

        bool useRewardsPoints(float rewardsPoints); //returns if there wasn't enough balance
        void newMemberPromotion(float incentiveAmount);
        bool contactCustomer(std::string msg = "Your order is ready.");
    };

    // 1) make a coffee
    bool brewCoffee(Coffee coffeeType, int size, std::string brewType, bool cream, bool sugar, std::string customerName); //returns "coffee ready" - I think you'd do this for 'urgent' asynchronous tasks like this?
    // 2) grind coffee beans
    bool grindCoffee(Coffee coffeeType, int courseness, Customer customerA);
    // 3) modify customer names
    void renameCustomer(Customer customerA);

    Coffee standardBrew;
};

/*
Thing 2) Invoice application
5 properties:
    1) the number of invoices (int)
    2) the number of clients (int)
    3) the outstanding balance (float)
    4) the number of templates (int)
    5) the types of jobs (std::string)
3 things it can do:
    1) create an invoice
    2) check if an invoice is late
    3) calculate outstanding balance
 */

struct InvoiceManager
{
    // 1) the number of invoices (int)
    int numInvoices = 234;
    // 2) the number of clients (int)
    int numClients = 32;
    // 3) the outstanding balance (float)
    float outBalance = 10345.24f;
    // 4) the number of templates (int)
    int numTemplates = 4;
    // 5) the type of job (std::string)
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
        void markAsPaid();
        void duplicate();
    };

    struct Client
    {  //to do. declaring just to clear errors

    };

    // 1) create an invoice - returns an Invoice struct above
    Invoice createInvoice(std::string clientName, int invoiceNumber, float dueDate, std::string workType = "post", float workTime = 0.0f);
    // 2) check if an invoice is late
    bool checkOverdue(Invoice invoice);
    // 3) calculate outstanding balance - inputs a Client and optional invoice, returns specific balance
    float checkBalance(Client client, Invoice invoice);
};

/*
Thing 3) Scooter rental
5 properties:
    1) the battery level (int)
    2) the rental time (float)
    3) the distance traveled (int)
    4) the GPS coordinates (float)
    5) the rental balance (float)
3 things it can do:
    1) accelerate
    2) brake
    3) lock
 */

struct ScooterRental
{
    // 2) the rental time (float)
    float rentalTime = 0.0f;
    // 3) the distance traveled ft (int)
    int distanceTraveled = 0;
    // 4) the GPS coordinates (float)
    float latitude = 34.052235f;
    float longitude = -118.243683f;
    // 5) the rental balance (float)
    float balance = 1.0f;

    // 1) accelerate
    void accelerate(float throttle = 0.0f);
    // 2) brake
    void brake(float brake = 0.0f);
    // 3) lock
    float lock(); //returns the total cost of the trip
};

/*
Thing 4)  Paintball gun
5 properties:
    1) CO2 pressure (int)
    2) paintballs in the hopper (int)
    3) paintballs in the chamber (int)
    4) volume of lubrication (float)
    5) valve aperature (float)
3 things it can do:
    1) shoot a paintball
    2) load a paintball into chamber
    3) lock trigger safety
 */

struct PaintballGun 
{
    // 1) CO2 pressure psi (int)
    int pressure = 333;
    // 2) paintballs in the hopper (int)
    int hopper = 100;
    // 3) paintballs in the chamber (int)
    int chamber = 0;
    // 4) volume of lubrication (float)
    float oil = 1.0f;
    // 5) valve aperature (float)
    float valve = 0.5f;

    // 1) shoot a paintball
    bool shoot(int chamber); //returns false if too many balls in chamber
    // 2) load a paintball into chamber
    bool load(int chamber); //returns false if too many balls in chamber
    // 3) lock trigger safety
    void lock();
};

/*
Thing 5) Propeller
5 properties:
    1) motor voltage (float)
    2) motor speed in rpm (float)
    3) propeller width in m (float)
    4) motor weight in grams (float)
    5) motor efficiency in percent (int)
3 things it can do:
    1) increase speed
    2) maintain speed
    3) decrease speed
 */

struct Propeller
{
    // 1) motor voltage (float)
    float voltage = 11.1f;
    // 2) motor speed in thousands of rpms (float)
    float speed = 12.0f;
    // 3) propeller size in inches (float)
    float size = 5.0f;
    // 4) motor weight in grams (float)
    float weight = 6.2f;
    // 5) motor efficiency in percent (int)
    int efficiency = 70;

    // 1) accelerate
    float accelerate(float voltage);    //returns speed
    // 2) maintain speed
    float maintain(float speed);    //returns voltage
    // 3) get speed
};  float getSpeed();   //gets speed

/*
Thing 6) Battery
5 properties:
    1) voltage (float)
    2) number of cells (int)
    3) capacity in mAh (int)
    4) c-rating (int)
    5) battery type (std::string)
3 things it can do:
    1) charge
    2) discharge
    3) disconnect
 */

struct Battery
{
    // 1) voltage (float)
    float voltage = 3.7f;
    // 2) number of cells (int)
    int cells = 1;
    // 3) capacity in mAh (int)
    int capacity = 750;
    // 4) c-rating (int)
    int crating = 45;
    // 5) battery type (std::string)
    std::string type = "LiPo";

    // 1) charge
    float charge(); //returns voltage
    // 2) discharge
    float discharge(); //returns voltage
    // 3) disconnect
    void disconnect();
};

/*
Thing 7) GPS
5 properties:
    1) latitude (float)
    2) longitude (float)
    3) altitude (float)
    4) time (float)
    5) signal strength in percentage (int)
3 things it can do:
    1) get location
    2) get time
    3) get signal strength
 */

struct GPS
{
    // 1) latitude (float)
    float latitude = 34.052235f;
    // 2) longitude (float)
    float longitude = -118.243683f;
    // 3) altitude (float)
    float altitude = 0.1f;
    // 4) time (float)
    float time = 1541393269.3742561f;
    // 5) signal strength in percentage (int)
    int signal = 99;

    // 1) get location
    void getLocation(); // updates struct params
    // 2) get time
    float getTime(float latitude, float longitude); // returns current GPS server time based on location
    // 3) get signal strength
    int getSignal(); //returns signal strength 
};

/*
Thing 9) Presets
5 properties:
    1) preset name (std::string)
    2) preset type (std::string)
    3) preset number (int)
    4) preset size in MB (int)
    5) preset author (std::string)
3 things it can do:
    1) save a preset
    2) execute a preset
    3) rename a preset
 */

struct Preset
{
    // 1) preset name (std::string)
    std::string name = "barrel roll";
    // 2) preset type (std::string)
    std::string type = "maneuver";
    // 3) preset number (int)
    int number = 1;
    // 4) preset size in MB (int)
    int size = 2;
    // 5) preset author (std::string)
    std::string author = "Toby";

    // 1) save a preset
    bool savePreset(std::string name, std::string type, std::string author); // returns successful save
    // 2) checks for an existing preset
    bool checkPreset(std::string name); // returns whether preset exists
    // 3) rename a preset
    void renamePreset(std::string oldName, std::string newName);
};

/*
Thing 8) CPU
5 properties:
    1) speed in MHz (float)
    2) number of cores (int)
    3) memory in GB (int)
    4) model (std::string)
    5) mirocontroller (std::string)
3 things it can do:
    1) get drone speed
    2) balance drone
    3) execute presets
 */

struct CPU
{
    // 1) speed in MHz (float)
    float speed = 2.1f;
    // 2) number of cores (int)
    int numCores = 2;
    // 3) memory in GB (int)
    int memory = 512;
    // 4) model (std::string)
    std::string model = "U11X";
    // 5) architecture (std::string)
    std::string architecture = "ARM"; 


    // 1) get drone speed
    float getSpeed(); // returns speed
    // 2) balance drone
    void balance();
    // 3) execute presets
    void runPreset(Preset preset);
};

/*
Thing 10) Drone
5 properties: 
    1) Propellers
    2) Battery
    3) GPS
    4) CPU
    5) Presets
3 things it can do:
    1) Lift off
    2) Maneuver 
    3) Land
 */


struct Drone
{
    // 1) Propellers
    Propeller propellerA;
    // 2) Battery
    Battery batteryA;
    // 3) GPS
    GPS gpsA;
    // 4) CPU
    CPU cpuA;
    // 5) Presets
    Preset presetA;

    // 1) Lift off
    void liftOff();
    // 2) Maneuver
    void maneuver(); 
    // 3) Land
    bool land(); // returns if landing area not clear
};

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
