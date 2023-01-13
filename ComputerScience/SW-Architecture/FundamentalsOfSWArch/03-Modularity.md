<!-- vscode-markdown-toc -->
* 1. [Definition](#Definition)
* 2. [Measuring](#Measuring)
	* 2.1. [Cohesion](#Cohesion)
	* 2.2. [Coupling](#Coupling)
	* 2.3. [Abstracness, Instability and Disctance from the Main Sequence](#AbstracnessInstabilityandDisctancefromtheMainSequence)
	* 2.4. [Distance from the Main Sequence](#DistancefromtheMainSequence)
	* 2.5. [Connascense](#Connascense)
	* 2.6. [Unifying Coupling and Connascence Metrics](#UnifyingCouplingandConnascenceMetrics)
* 3. [From Modules to Components](#FromModulestoComponents)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

This chapter has common topics with [Uncle Bob-Clean Architecture Chapter 4 - Components](ComputerScience/UncleBob/CleanArchitecture/Sec04-Components.md)
give it a look!
##  1. <a name='Definition'></a>Definition

> **Definition:** A logical grouping of related code.
> 
> - For Object-Oriented Programming Language: A group of classes, (`namespace` in `C#` or a `package` in `Java`)
> - For a Structured Programming Language: A group of functions.
>

##  2. <a name='Measuring'></a>Measuring

###  2.1. <a name='Cohesion'></a>Cohesion

> "Attemping to divide a cohesive module would only result in increased coupling and decreased readibility" - Larry Constantine
> 
- A measure of how related the Components parts are to one another.
- The list of range `cohesion` measures (from best to worst) is presented below:
  - `Functional Cohesion`:
    - Every part of the Component is related to the other.
    - The Component contains everything essencial to function.
    - **Best** form of Cohesion.
  - `Sequencial Cohesion`:
    - Two Components `A` and `B` interact, and the output of `A` is the input of `B`      
  - `Communicational Cohesion`: 
    - Two modules form a communication chain.
    - Each operates on information and/or contributes o some output.
      - Example: `A` add a record to the DB, `B` generates an email based on that information.
  - `Procedural Cohesion`:
    - When `A` and `B` executes code in a particular order.
  - `Temporal Cohesion`:
    - Components are related based on timing dependencies.
      - Example: The Components which are initialized at Software Startup.
  - `Logical Cohesion`:
    - When data inside a Component is related logically but not functionally.
      - Example: Many `Java` packages which have groups of `static` methods that operate on something (e.g., `string`) but otherwise are unrelated.
  - `Coincidental Cohesion`:
    - When data inside a Component are related only because it belong to the same source file.
    - **Worst** form of Cohesion.

> 
###  2.2. <a name='Coupling'></a>Coupling

###  2.3. <a name='AbstracnessInstabilityandDisctancefromtheMainSequence'></a>Abstracness, Instability and Disctance from the Main Sequence

###  2.4. <a name='DistancefromtheMainSequence'></a>Distance from the Main Sequence

###  2.5. <a name='Connascense'></a>Connascense

> "Two Components are connacent if a change in one wuould require the other to be modified in order to maintain the overall correctness of the system" - Meilir Page-Jones
>
>
###  2.6. <a name='UnifyingCouplingandConnascenceMetrics'></a>Unifying Coupling and Connascence Metrics

##  3. <a name='FromModulestoComponents'></a>From Modules to Components