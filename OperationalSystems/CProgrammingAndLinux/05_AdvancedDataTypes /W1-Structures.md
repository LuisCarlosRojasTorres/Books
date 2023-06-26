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

##  4. <a name='Workwithstructures'></a>Work with structures
- Access and modify structure’s members with the arrow operator
``` c

```
- Get the size of a structure in memory
``` c

```
###  4.1. <a name='Exercise-1'></a>Exercise
-
``` c
```
