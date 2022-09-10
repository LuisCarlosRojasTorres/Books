<!-- vscode-markdown-toc -->
* 1. [Four Design Principles](#FourDesignPrinciples)
	* 1.1. [Aggregation](#Aggregation)
	* 1.2. [Encapsulation](#Encapsulation)
	* 1.3. [Decomposition](#Decomposition)
		* 1.3.1. [Association](#Association)
		* 1.3.2. [Aggregation](#Aggregation-1)
		* 1.3.3. [Composition](#Composition)
	* 1.4. [Generalization](#Generalization)
* 2. [Design Principles](#DesignPrinciples)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='FourDesignPrinciples'></a>Four Design Principles

###  1.1. <a name='Aggregation'></a>Aggregation


###  1.2. <a name='Encapsulation'></a>Encapsulation

###  1.3. <a name='Decomposition'></a>Decomposition

####  1.3.1. <a name='Association'></a>Association


- **loose relationship** between two objects.
- If one object is destroyed, the other can continue to exist.
- There can be any number of wach item in the relationship.
- Representation:
  - **straight line** between two objects
  - The `0...*` on the right means: *A Sport object is associated to **0 or more** Student 
  - The `0...*` on the left means: *A Student object is associated to **0 or more** Sport object*

Example:

![Association](/ComputerScience/uploads/association.png)

``` cpp
class Student{
	public:
		void play (Sport sport);
}
```

####  1.3.2. <a name='Aggregation-1'></a>Aggregation

![Aggregation](/ComputerScience/uploads/aggregation.png)

####  1.3.3. <a name='Composition'></a>Composition

![Composition](/ComputerScience/uploads/composition.png)

###  1.4. <a name='Generalization'></a>Generalization

##  2. <a name='DesignPrinciples'></a>Design Principles
