/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
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
