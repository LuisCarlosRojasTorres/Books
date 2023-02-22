<!-- vscode-markdown-toc -->
* 1. [Four Design Principles](#FourDesignPrinciples)
	* 1.1. [Abstraction](#Abstraction)
	* 1.2. [Encapsulation](#Encapsulation)
		* 1.2.1. [Integrity and Security](#IntegrityandSecurity)
		* 1.2.2. [Changeable Implementation](#ChangeableImplementation)
		* 1.2.3. [Black Box concept](#BlackBoxconcept)
	* 1.3. [Decomposition](#Decomposition)
		* 1.3.1. [Association Relationship](#AssociationRelationship)
		* 1.3.2. [Aggregation Relationship](#AggregationRelationship)
		* 1.3.3. [Composition Relationship](#CompositionRelationship)
	* 1.4. [Generalization](#Generalization)
		* 1.4.1. [Implementation inheritance](#Implementationinheritance)
		* 1.4.2. [Interface inheritance](#Interfaceinheritance)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='FourDesignPrinciples'></a>Four Design Principles

###  1.1. <a name='Abstraction'></a>Abstraction
- It is how humans deal with complexity: Simplifying a concept in the problem domain.
- It breaks a concept down into a simplified description.
  - It ignores unimportant details.
  - It emphasized the essential needed for the concept, within some concept.
- It help us to model classes:
  - It is used to determine the essencial details for some concept.
- To model a class the designer have to choose the abstraction that is most appropriate to the **context** of the software development.
  - This **context** shall be understoof before creating an abstraction.
- The essential characteristics of an abstration can be understood in two ways:
  - basic attributes: characteristics that do not dissapear over time.
  - behaviours: responsabilities and actions. 
- An example: Modelling the `Person` class
  - For a dating app:
    - Gender
    - Age
    - Social media accounts
  - For a fit app:
    - Gender
    - Age
    - IMC, 
    - Number of diary steps etc...
  - So different models can be obtained based on different context. So if the context changes the abstraction can change too.
  
###  1.2. <a name='Encapsulation'></a>Encapsulation
- It allows something to be contained in a capsule, some of which you can access from the outside and some of which you cannot.
- Three concepts behind encapsulation:
  - the ability to **bundle** attribute values (or data) and behaviours (or methods) that manipulates those values, into a self-contained object.
  - the ability to **expose** certain data and functions of that object, which can be accessed from the other objects, usually through an `interface`.
  - the ability to **restrict** access to certain data and functions to only within the object.
- The object's data should only contain what is relevant for that object.
####  1.2.1. <a name='IntegrityandSecurity'></a>Integrity and Security
- Restricting access to certain data and functions to only within an object, leads to **data integrity** and the security of sensitive information.
- If certain data are restricted from outside access, except through specific methods, then the data cannot be changed through variable assignments.

####  1.2.2. <a name='ChangeableImplementation'></a>Changeable Implementation
- Implementation of attributes and methods can change, but the accessible interface of a class can remain the same.
####  1.2.3. <a name='BlackBoxconcept'></a>Black Box concept
-  It means that he computation steps taken within a class never need to be known by any other class, as long as they are able to access the `interface`.
   -  A class is therefore like a **black box** that you cannot see into for details about how attributes are represented or how methods compute their results.
   -  What happens in the **box** to achieve an expected behaviour does not matter, as long as it is possible to provide inputs and obtain outputs by calling methods. 
   -  What separates the real world from the internal workings of a class is a **abstraction barrier** which reduces complexity for users of the class.

###  1.3. <a name='Decomposition'></a>Decomposition
It means that:
> A whole thing can be divided into different parts.
>  or 
> Parts with different functionalities can be combined to form a whole thing.

- There are three types of relationships in decomposition:
  - Association
  - Aggregation
  - Composition

####  1.3.1. <a name='AssociationRelationship'></a>Association Relationship


- It indicates a **loose relationship** between two objects.
  - The two objects are **completely separate**
- If one object is destroyed, the other can continue to exist.
- There can be any number of each item in the relationship.
- No object belongs to another (and they may have numbers that are not tied to each other).  
- An example: 
  - A `Student` can practice a `Sport` or many `Sports`.
  - Additionaly, many `Student` can practice the same `Sport` or `Sports`.
- Representation:
  - **straight line** between two objects
  - The `0...*` on the right means: *A* `Sport` *object is associated to* **0 or more** `Student`.
  - The `0...*` on the left means: *A* `Student` object is associated to **0 or more** `Sport`. 


![Association](/ComputerScience/OOD/uploads/01-association.png)

``` cs
class Student{

   public void play (Sport sport)
   {
      execute.play(sport);
   }
}
```

####  1.3.2. <a name='AggregationRelationship'></a>Aggregation Relationship

- It is a **has-a** relationship where a whole has parts that belong to it.
  - Parts can be shared among wholes in this relationship.
- It is a **weak** relationship.
  - Even if the parts can belong to a whole, they can also exist independently.
- An example:
	- An `Airlines` cannot operate without a `Crew`.
	- But, An `Airliner` does not cease to exist if the `Crew` leave.
	- Also, the `Crew` do not cease to exist if they are not in the `Airliner`.
- Representation:
	- A straight line with an **empty diamond** in the object considered the *whole*.
	- The `0...*` on the right means: *A* `CrewMember` *object is associated to* **0 or more** `Airliner` *objects*.
	- The `0...*` on the left means: *An* `Airliner` *object is associated to* **0 or more** `CrewMember` *objects*.
	
![Aggregation](/ComputerScience/OOD/uploads/02-aggregation.png)

``` cs
class Airliner{

   private List<CrewMember> crew;

   public Airliner() 
   {
      crew = new List<CrewMember>();
   }

   public void Add( CrewMember crewMember) 
   {
   //...
   }
}
```
Where:
- `Airliner` object has a reference to each `CrewMember` object.
- Each `CrewMember` object is passed as a reference to the `Airliner` object.

####  1.3.3. <a name='CompositionRelationship'></a>Composition Relationship

- It is one of the most dependent of the decomposition relationships.
- It is an exclusive containment of parts, known as a **strong has-a** relationship.
  - The whole cannot exist without its parts.
  - If the whole is destroyed, then the parts are destroyed too.
  - You can only access the parts through its whole.
  - Contained parts are exclusive to the whole.
- An example:
  - A `House` has `Rooms`.
  - If the `House` is destroyed, the `Rooms` are destroyed too.  
- Representation:
  - A straight line with a **filled diamond** in the object considered the *whole*.
  - The `1...*` on the left means: *A* `House` *object is associated to* **1 or more** `Rooms` *objects*.


![Composition](/ComputerScience/OOD/uploads/03-composition.png)

``` cs
public class House
{
  private Room room;

  public House()
  {
    room = new Room(); 
  }
}
```
Where:
- A `Room` object is created at the same time that the `House` object.
- The `Room` object is created **inside** its container, moreover it does not need to be passed as a reference.
- As a result of this, `House`  and `Room` are tightly dependent with one not being able to exist without the other.
###  1.4. <a name='Generalization'></a>Generalization

- It takes repeated, common or shared characteristics between two or more classes and factors them out into another class i.e. `base class`.
  - So the code can be reused, and the characteristics can be inherit by the `derived classes`.
  - `derived classes` can also be a `base class` to another class.
    
####  1.4.1. <a name='Implementationinheritance'></a>Implementation inheritance
- A `derived class` is a subtype of its `base class`. Moreover it inherits some of its implementations (fields and methods) for that reason `class inheritance` is called of `implementation inheritance` and the process is called `subtyping`.
- Representation: 
  - A straight solid line with a empty triangle in the `base class`.
  - The arrow shall point upwards. So `base class` shall be on top.
  - Inherit `base class` attributes (`fields`) and behaviours (`methods`) do not need to be rewritten in the `derived class`.
- An example:
  - `Base Class` has the following field:
    - A public attribute `publicField`: represented by `+`
    - A private attribute `privateField`: represented by `-`
    - A protected attribute `protectedField`: represented by `#`
    - A public method `method1`
  - `Derived Class`:
    - Inherits all attributes from `Base Class` i.e. `publicField`, `privateField`, `protectedField` and `method1`
    - Additionally:
      -  it has a public attribute `field`.
      -  it has a public method `method2`.

![Class Inheritance](/ComputerScience/OOD/uploads/04-class-inheritance.png)

####  1.4.2. <a name='Interfaceinheritance'></a>Interface inheritance
- `Interface inheritance` only specifies common behaviours throught method signatures. 
- An `interface` is like a contract to be fulfilled by implementing classes.
- An `interface` only declares method signatures, with no `constructors`, `attributes` or `method` bodies.
- Representation: 
  - A straight dotted line with a empty triangle in the `interface`.
  - The arrow shall point upwards. So `interface` shall be on top.
  - Inherit `interface` and behaviours (`methods`) do not need to be rewritten in the `derived class`.


![Interface Inheritance](/ComputerScience/OOD/uploads/05-interface-inheritance.png)

