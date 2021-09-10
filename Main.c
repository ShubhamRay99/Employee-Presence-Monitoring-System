#include <stdio.h>

struct Employee{

    int empId;
    char *name;
    int age;
    char *designation;

    // struct Time
    // {
    //     int inTimeHr, inTimeMin, outTimeHr, outTimeMin;
    // };
    

};



const int numberOfEmp = 5;
struct Employee e[numberOfEmp];
struct Employee getEmpId(int id);


//main menu funcs
int mainMenu();
void adminLoggedIn();
void seeWhoHasLoggedIn(int empId);

//analysis funcs
void analyze();



void main()
{

    //adding employees details
    e[0].empId = 101, e[0].name = "Alpha", e[0].age = 31, e[0].designation = "Scrum Master", 
    e[1].empId = 102, e[1].name = "Beta", e[1].age = 23, e[1].designation = "Developer",
    e[2].empId = 103, e[2].name = "Gamma", e[2].age = 52, e[2].designation = "Tester",
    e[3].empId = 104, e[3].name = "Hexa", e[3].age = 21, e[3].designation = "Consultant",
    e[4].empId = 105, e[4].name = "Lambda", e[4].age = 24, e[4].designation = "Developer";

    //running main menu
    int iquit = mainMenu();
    while (iquit != 3)
        iquit = mainMenu();
}

int mainMenu()
{
    int decision;
    printf("\nChoose 1 among the following : \n 1. Click 1 if you are the admin : \n 2. Enter your employee id, if you are an employee : \n 3. Click 3 to turn-off the system : ");
    scanf("%d", &decision);

    if (decision == 1)
        adminLoggedIn();
    else if (decision != 3)
        seeWhoHasLoggedIn(decision);

    return decision;
}

void adminLoggedIn()
{
    int passcode;
    printf("Enter the passcode : ");
    scanf("%d", &passcode);

    if (passcode == 123)
        analyze();
    else
        printf("Sorry you haven't entered the correct passcode.");
}

void analyze()
{
    printf("\nEnter the number for the particular question: \n1. How many employees came today?\n2. Did a particular employee come today?\n3. How often did an employee enter into the office?\n4. Which employee moves out of office most number of times?\n5. Name of the employees who are all out for a particular time period\n6. Who all came within a range of IDs, and how often they entered?\n");
}

void seeWhoHasLoggedIn(int empId)
{
    struct Employee emp = getEmpId(empId);
    printf("Hi %s", emp.name);

}

struct Employee getEmpId(int id){
    int i;
    
    for (i = 0; i < numberOfEmp; i++)
    {
        if(e[i].empId == id){
            return e[i];
        }
    }
}