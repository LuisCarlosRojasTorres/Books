<!-- vscode-markdown-toc -->
* 1. [Define structures](#Definestructures)
	* 1.1. [Exercise](#Exercise)
* 2. [Access and modify structures](#Accessandmodifystructures)
	* 2.1. [Exercise](#Exercise-1)
* 3. [Pass structures to functions](#Passstructurestofunctions)
	* 3.1. [Exercise](#Exercise-1)
* 4. [Work with structures](#Workwithstructures)
	* 4.1. [Exercise](#Exercise-1)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

Learn about:
- Define new data types (structures) to store multiple data items in one variable and create, initialize and modify variables of these new types
- Find and explain the memory usage of a structure and use pointers to structures and the direct and indirect member selection operators to access members of structures
- Create linked lists of structures with dynamic memory allocation at runtime
- Sort or search lined lists of structures

##  1. <a name='Definestructures'></a>Define structures
``` c
#include <stdio.h>

struct student{
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

int main(void) {
	//! showMemory(start=65520)
    struct student me = {"Petra", "Bonfert-Taylor", 1989, 3.5};
    struct student you = {"Remi", "Sharrock", 2005, 3.5};
    printf("Names: %s %s, %s %s\n", me.firstName, me.lastName, you.firstName, you.lastName);
    printf("Year of birth: %d\n", me.birthYear);
    printf("Average grade: %.2lf\n", me.aveGrade);
	return 0;
}
```
- If we see the memory addresses of the structures, we see that they are next to each other:
- `me.firstName`: begins at `FFB8` and ends at `FFD5`
- `me.lastName`: begins at `FFB9` and ends at `FFF3`
- `me.birthYear`: begins at `FFF4` and ends at `FFF7`
- `me.aveGrade`: begins at `FFF8` and ends at `FFFF`
- `you.firstName`: begins at `FF70` and ends at `FF8D`
- `you.lastName`: begins at `FF8E` and ends at `FFAB`
- `you.birthYear`: begins at `FFAC` and ends at `FFAF`
- `you.aveGrade`: begins at `FFB0` and ends at `FFB7`

##  2. <a name='Accessandmodifystructures'></a>Access and modify structures
- To modify a field in a `structure` the dot operator `.` is used.


``` c
#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};

int main(void) {
    //! showMemory(start=65520)
    struct student learner;
    printf("First name: ");
    scanf("%s", learner.firstName);
    printf("Last name: ");
    scanf("%s", learner.lastName);
    printf("Year of birth:");
    scanf("%d", &learner.birthYear);
    printf("Average grade: ");
    scanf("%lf", &learner.aveGrade);
    
    printf("Name: %s %s\n", learner.firstName, learner.lastName);
	printf("Year of birth: %d\n",learner.birthYear);
	printf("Average grade: %.2lf\n",learner.aveGrade);
    
	return 0;
}
```

##  3. <a name='Passstructurestofunctions'></a>Pass structures to functions

``` c
#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
void printStudent(struct student stud);
int main(void) {
	//! showMemory(start=65520)
	struct student me={"Petra", "Bonfert-Taylor", 1989, 3.5};
	struct student you={"Remi", "Sharrock", 2005, 3.5};
	
	printStudent(me);
	printStudent(you);
	return 0;
}

void printStudent(struct student stud){
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}
```
- Pass structures to functions with pointers
``` c
#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
void printStudent(struct student);
void readStudent(struct student *studptr);
int main(void) {
   //! showMemory(start=65520)
    struct student me;
    readStudent(&me);
    printStudent(me);
	return 0;
}

void readStudent(struct student *studptr) {
    printf("\nEnter a new student record: \n");
    printf("First name: ");
    scanf("%s", (*studptr).firstName);
    printf("Last name: ");
    scanf("%s", (*studptr).lastName);
    printf("Birth year: ");
    scanf("%d", &(*studptr).birthYear);
    printf("Average grade: ");
    scanf("%lf", &(*studptr).aveGrade);
}

void printStudent(struct student stud) {
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}
```
### Excercise
- You'd like to implement a date feature in the C programming language. To this end you are provided with a structure definition, a main function, and two function prototypes: "readDate()" and "printDate()". All that is left for you to do is to write these two functions.

- Here are the exact specifications:
    - The function readDate() should read 3 integers from the user input. The first integer is the year (a 4-digit number), the second integer is the month, and the third integer is the day of the date being read. The function should store these three numbers in the appropriate parts of the structure being passed into it.
    - The function printDate() should print the date stored in the variable passed into it in the following format: mm/dd/yyyy with a new line afterwards. So the month should be printed with two digits (01, 02, 03, ..., 11, 12), the day should be printed as two digits (01, 02, 03, ..., 30, 31), and the year should be printed as a 4-digit number.

- Input: `2018 10 2`
- Output: `10/02/2018`
- Provided Code:
``` c
#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}
```

- Solution

``` c
#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date *dummy){
    scanf("%d", &(*dummy).year);
    scanf("%d", &(*dummy).month);
    scanf("%d", &(*dummy).day);
}
void printDate(struct date dummy){
    if(dummy.month < 10){
        printf("0%d/",dummy.month);
    }
    else{
        printf("%d/",dummy.month);
    }

    if(dummy.day < 10){
        printf("0%d/",dummy.day);
    }
    else{
        printf("%d/",dummy.day);
    }    

    printf("%d\n",dummy.year);

}
```
##  4. <a name='Workwithstructures'></a>Work with structures
- Access and modify structure’s members with the arrow operator
``` c
#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
void printStudent(struct student);
void readStudent(struct student *studptr);
int main(void) {
   //! showMemory(start=65520)
    struct student me;
    readStudent(&me);
    printStudent(me);
	return 0;
}

void readStudent(struct student *studptr) {
    printf("\nEnter a new student record: \n");
    printf("First name: ");
    scanf("%s", studptr->firstName);
    printf("Last name: ");
    scanf("%s", studptr->lastName);
    printf("Birth year: ");
    scanf("%d", &studptr->birthYear);
    printf("Average grade: ");
    scanf("%lf", &studptr->aveGrade);
}

void printStudent(struct student stud) {
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}
```
- Get the size of a structure in memory
``` c
struct student{
	char firstName[5];
	char lastName[5];
	int birthYear;
	double aveGrade;
};

int main(void) {
    //! showMemory(start=65520)
	struct student me;
    printf("Size of struct student is %zu.\n", sizeof(struct student));
    printf("Size of firstName is %zu.\n", sizeof(me.firstName));
    printf("Size of lastName is %zu.\n", sizeof(me.lastName));
    printf("Size of birthYear is %zu.\n", sizeof(me.birthYear));
    printf("Size of aveGrade is %zu.\n", sizeof(me.aveGrade));

	return 0;
}
```
- Output
``` console
Terminal
Size of struct student is 22.
Size of firstName is 5.
Size of lastName is 5.
Size of birthYear is 4.
Size of aveGrade is 8.
```  
 ###  4.1. <a name='Exercise-1'></a>Exercise
- In this problem you will continue developing the data feature which you started implementing in the previous problem. You will implement a "tomorrow" feature in the C programming language via a function called "advanceDay()". The function advanceDay() should take as input a date (stored in a struct date) and return the date of the following day. You do not have to take into account leap years (although you may if you wish to). That is, it is okay for your function to always return March 1 as the day following February 28, no matter the year.

- You are provided with a familiar date structure definition, a main function as well as the function prototypes for the readDate(), printDate(), and advanceDay() functions. Do not modify any of the given code. Simply add your function definitions underneath the main() function. For the readDate() and printDate() functions you may simply copy and paste the code you developed in the previous task.

- Input: `2018 10 2`
- Output:  
  - `10/02/2018`                                                                     
  - `10/03/2018`

- Solution
``` c
#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

void readDate(struct date *dummy){
    scanf("%d", &(*dummy).year);
    scanf("%d", &(*dummy).month);    
    scanf("%d", &(*dummy).day);    
}
void printDate(struct date dummy){
    

    if(dummy.month < 10){
        printf("0%d/",dummy.month);
    }
    else{
        printf("%d/",dummy.month);
    }
    if(dummy.day < 10){
        printf("0%d/",dummy.day);
    }
    else{
        printf("%d/",dummy.day);
    }

    printf("%d\n",dummy.year);

}
struct date advanceDay(struct date dummy){
    if(dummy.day == 31){

        if(dummy.month == 12){
            struct date ans = {dummy.year+1, 1, 1};
            return ans;
        }
        else{
            struct date ans = {dummy.year, dummy.month+1, 1};
            return ans;
        }
    }
    else if(dummy.day == 30){
        if(dummy.month == 4 || dummy.month == 6 || dummy.month == 9 || dummy.month == 11)
        {
            struct date ans = {dummy.year, dummy.month+1, 1};
            return ans;
        } 
    }else{
        struct date ans = {dummy.year, dummy.month, dummy.day+1};
        return ans;
    }
}
```
