/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


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
            float customerPhoneNumber = 15555555555.0f; //replit suggested 'long' be used, but that's not in the lesson
            float customerID = 1.0f; // I'll also float this then
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

        struct Invoice{
            std::string clientName;
            int invoiceNumber;
            std::string workType = "post";
            float workTime = 0.0f;
            float totalBalance = 0.0f;
            float dueDate;
            bool overdue = false;

            void download(std::string format = "pdf");
            void paid();
            void duplicate();
        };

        struct Client{  //to do. declaring just to clear errors

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
