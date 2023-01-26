<!-- vscode-markdown-toc -->
* 1. [Ch07 - SRP - The Single Responsability Principle](#Ch07-SRP-TheSingleResponsabilityPrinciple)
	* 1.1. [The Problem](#TheProblem)
	* 1.2. [ The Solution](#TheSolution)
* 2. [Ch08 - OCP - The Open Close Principle](#Ch08-OCP-TheOpenClosePrinciple)
	* 2.1. [The Problem](#TheProblem-1)
	* 2.2. [The Solution](#TheSolution-1)
* 3. [Ch09 - LSP - The Liskov Substitution Principle](#Ch09-LSP-TheLiskovSubstitutionPrinciple)
	* 3.1. [The Problem](#TheProblem-2)
	* 3.2. [The Solution](#TheSolution-2)
* 4. [Ch10 - ISP - The Interface Segregation Principle](#Ch10-ISP-TheInterfaceSegregationPrinciple)
	* 4.1. [The Problem](#TheProblem-3)
	* 4.2. [The Solution](#TheSolution-3)
* 5. [Ch11 - DIP - The Dependency Inversion Principle](#Ch11-DIP-TheDependencyInversionPrinciple)
	* 5.1. [The Problem](#TheProblem-4)
	* 5.2. [The Solution](#TheSolution-4)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Ch07-SRP-TheSingleResponsabilityPrinciple'></a>Ch07 - SRP - The Single Responsability Principle
First we need to define:
- `actor`: one or more people or one entity (SW or HW) who require a change in the software.

> "A Software Component should be responsible to one, and only one, actor" - Robert Martin

###  1.1. <a name='TheProblem'></a>The Problem
Let's see this with an example:
1. We have a `DummyC` class with three methods. 
2. Three different `actors` use each one of these methods.
   1. Actor1 uses `method1`
   2. SW (Actor2) uses `method2`
   3. HW (Actor3) uses `method3`
3. Because these three methods belong to the same, it is not so uncommon that they can have some `private` method call in common e.g, `private setupVariables` method.
4. So, if one of the actors require that `setupVariables` have to be changed. The other two will be affected, and maybe will get wrong results.
5. On the other hand if two or more actors require that `setupVariables` have to be changed. These changes will generate a merge conflict. Which of these implementations is right?.
All this is presented in the following Figure:
![NO SRP](/ComputerScience/UncleBob/CleanArchitecture/uploads/SRP001.png)

###  1.2. <a name='TheSolution'></a> The Solution
The solution for these is use the `Facade` pattern.
1. Now three classes share access to `DummyC Data`. Eacj of the classes have only the implementation necessary for its methods.
2. `DummyC data` is a simple data structure with no methods.
3. `DummyC Facade` is reponsible for instantiate and delegate to the three classes with methods.

All this is presented in the following Figure:
![SRP](/ComputerScience/UncleBob/CleanArchitecture/uploads/SRP002.png)

##  2. <a name='Ch08-OCP-TheOpenClosePrinciple'></a>Ch08 - OCP - The Open Close Principle

> "A software unit should be open for extension but closed for modification" - Bertrand Meyer

###  2.1. <a name='TheProblem-1'></a>The Problem
Let's see this with an example:
1. We have a `HW1` hardware with interacts with the `DummyC` class using its methods i.e., `method1`, `method2` and `method3`. 
2. For some reason, a new requirement is specified: "The software shall be also compatible with `HW2` hardware". Wheere `HW2` is an equivalent hardware from another company.
3. A common solution is implement conditional insides the methods to evaluate which type of hardware is connected. 
   - What happen if a thir hardware `HW3` shall also be compatible? another conditional?
   - This is a poor practice, an increase the difficulty to maintain the code.  


![NO OCP](/ComputerScience/UncleBob/CleanArchitecture/uploads/OCP001.png)


###  2.2. <a name='TheSolution-1'></a>The Solution
1. Create an `interface` which define the common methods used by the hardwares.
2. Create a class for each hardware that shall be compatible to the software:
   1. Create `DummyForHW1` for the `HW1`
   2. Create `DummyForHW2` for the `HW2`
![OCP](/ComputerScience/UncleBob/CleanArchitecture/uploads/OCP002.png)


##  3. <a name='Ch09-LSP-TheLiskovSubstitutionPrinciple'></a>Ch09 - LSP - The Liskov Substitution Principle
> "What is wanted here is something like the following substitution property: If for each object `o1` of type `S` there is an object `o2` of type `T` such that for all programs P defined in  terms of `T`, the behavior of P is unchanged when `o1` is substituted for `o2` then `S` is a subtype of `T`" - Barbara Liskov

###  3.1. <a name='TheProblem-2'></a>The Problem
1. The `DummyUser` class uses the `Implementation1` class.
2. However `DummyUser` class shall also be capable of use the `Implementation2` class, which has the same methods definition of `Implementation2` but different implementation.
3. This kind of solutions difficult the maintainability.
   - Another implementation means modify the `DummyUser` class.

![LSP](/ComputerScience/UncleBob/CleanArchitecture/uploads/LSP001.png)

###  3.2. <a name='TheSolution-2'></a>The Solution
1. Both implementation have (or almost have) the same methods. So, both can be different implementations of an interface!!
2. Create the `InterfaceDummy` interface.
   1. `Implementation1` class shall implement this interface.
   2. `Implementation2` class shall also implement this interface.
3. `DummyUser` shall have `InterfaceDummy` type of variables in its methods.
	- So, it does not matter if it receives an `Implementation1` or `Implementation2` object, `DummyUser` will use it.
  
![LSP](/ComputerScience/UncleBob/CleanArchitecture/uploads/LSP002.png)

Note:
- A common implementation is:
1. Define a `InterfaceDummy` private variable in the `DummyUser` class.
2. This variable shall be set in the `DummyUser` class constructors.
3. Then the variable can be used in the `DummyUser` class methods.

##  4. <a name='Ch10-ISP-TheInterfaceSegregationPrinciple'></a>Ch10 - ISP - The Interface Segregation Principle

> "Many client-specific interfaces are better than one general purpose interface" - Robert Martin

###  4.1. <a name='TheProblem-3'></a>The Problem
1. We have three classes using the methods of another class:
   1. `DummyC1` class uses `method1`
   2. `DummyC2` class uses `method2`
   3. `DummyC3` class uses `method3`
2. However, all these three methods are implemented in the same class.
   1. If any of these methos is updated or deleted, the `ClassWithMethods` class shall be compiled and redeployed.
   2. Then `DummyC1`, `DummyC2` and `DummyC3` shall be compiled and redeployed too.
   3. This constitutes an *instability*. 


![NO ISP](/ComputerScience/UncleBob/CleanArchitecture/uploads/ISP001.png)

###  4.2. <a name='TheSolution-3'></a>The Solution
1. Create `interfaces`
   1. Create `InterfaceDummy1` interface and define all the methods `DummyC1` class uses.
   2. Create `InterfaceDummy2` interface and define all the methods `DummyC2` class uses.
   3. Create `InterfaceDummy3` interface and define all the methods `DummyC3` class uses.
2. `ClassWithMethods` class implements these three `interfaces`

Now, when any of the methods is updated, only the `ClassWithMethods` class is compiled and deployed.

![ISP](/ComputerScience/UncleBob/CleanArchitecture/uploads/ISP002.png)

##  5. <a name='Ch11-DIP-TheDependencyInversionPrinciple'></a>Ch11 - DIP - The Dependency Inversion Principle

> "The most flexible softwares are those in which source code dependencies refer only to abstractions, not to concretions" - Robert Martin 

###  5.1. <a name='TheProblem-4'></a>The Problem
1. The business rules are implemented in a concrete class i.e., `DummyDependency` class.
   1. Each time when `DummyDependecy` is updated shall be compiled. This change affects all its `dependents` shall be compiled too.
		- Software units that are actively developing, and undergoing frequent change are called `volatile`.
		- Best practices recommends to reduce `volatily` in dependencies and business rules. 

![NO DIP](/ComputerScience/UncleBob/CleanArchitecture/uploads/DIP001.png)

###  5.2. <a name='TheSolution-4'></a>The Solution
- Every change to an abstract interface corresponds to a change to its concrete implementations.
  - However, chages to concrete implementations do not change its interfaces.
  - The following coding practices can be obtained from the this:
	1. **Do not refer to volatile concrete classes.**
	2. **Do use volatile concrete classes as `base classes`.**
	3. **Do not `override` concrete function/methods.**


Steps:
1. Create the `InterfaceDummy` interface, and define all the methods implemented in `DummyDependency` class.
2. Modify the `DummyDependency` class to implement the `InterfaceDummy`
3. Modify `DummyDependent` class to use the `InterfaceDummy` interface

![DIP](/ComputerScience/UncleBob/CleanArchitecture/uploads/DIP002.png)