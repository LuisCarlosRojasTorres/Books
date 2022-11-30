<!-- vscode-markdown-toc -->
* 1. [Ch12 - Components](#Ch12-Components)
* 2. [Ch13 - Component Cohesion](#Ch13-ComponentCohesion)
	* 2.1. [REP - The Reuse/Release Equivalence Principle](#REP-TheReuseReleaseEquivalencePrinciple)
	* 2.2. [CCP - The Common Closure Principle](#CCP-TheCommonClosurePrinciple)
	* 2.3. [CRP - The Common Reuse Principle](#CRP-TheCommonReusePrinciple)
	* 2.4. [The Tension Diagram for Component Cohesion](#TheTensionDiagramforComponentCohesion)
* 3. [Ch14 - Component Coupling](#Ch14-ComponentCoupling)
	* 3.1. [The Acyclic Dependencies Principle (ADP)](#TheAcyclicDependenciesPrincipleADP)
		* 3.1.1. [Introduction](#Introduction)
		* 3.1.2. [An Acyclic Dependency Graph](#AnAcyclicDependencyGraph)
		* 3.1.3. [The Dependency Cycle](#TheDependencyCycle)
		* 3.1.4. [Breaking the Cycle](#BreakingtheCycle)
	* 3.2. [Top-Down Design](#Top-DownDesign)
	* 3.3. [The Stable Dependencies Principle (SDP)](#TheStableDependenciesPrincipleSDP)
		* 3.3.1. [Introduction](#Introduction-1)
		* 3.3.2. [Stability Metrics (I)](#StabilityMetricsI)
		* 3.3.3. [An application problem](#Anapplicationproblem)
	* 3.4. [The Stable Abstraction Principle (SAP)](#TheStableAbstractionPrincipleSAP)
		* 3.4.1. [Introduction](#Introduction-1)
		* 3.4.2. [Abstractness metric (A)](#AbstractnessmetricA)
		* 3.4.3. [Stability (I) vs Abstracness (A)](#StabilityIvsAbstracnessA)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Ch12-Components'></a>Ch12 - Components
- Well-designed components are independently deployable, and for that reason independently developable.

##  2. <a name='Ch13-ComponentCohesion'></a>Ch13 - Component Cohesion
Three principles of component cohesion:

###  2.1. <a name='REP-TheReuseReleaseEquivalencePrinciple'></a>REP - The Reuse/Release Equivalence Principle

`The granule of reuse is tha granule of release.`
- Software components shall be tracket through a release number and process. This is important to: 
  - verify compatibility.
  - know when new releases are comming.
  - document and notify the changes between versions.
  - create a cohesive group of classes and modules into a component.

###  2.2. <a name='CCP-TheCommonClosurePrinciple'></a>CCP - The Common Closure Principle

`classes that change for the same reasons and at the same times = same component`

- In general **maintainability** is more important than **reusability** (how many times you will reuse a component vs how many minor versons you will release of that sw?)
- So, if a requirement changes, there is a good chance that a minimal number of software components will change. This minimizes the workload related to releasing, revalidating, and redeploying the software.
- For example, three classes that calculate trigonometric functions for a given angle in radians. If the algorithm to calculate the radian into to the return value of the functions change, all those functions also changes. So they shall go to the same module. Even if a requirements changes affecting the trigonometric functions, only onw component will be affected (because all they belong to the same component).

###  2.3. <a name='CRP-TheCommonReusePrinciple'></a>CRP - The Common Reuse Principle

`Don’t force users of a component to depend on things they don’t need.`

- Classes and modules that tend to be reused together belong in the
same component.
- So, classes that have lots of dependencies (tightly coupled) of each other belong to the same component.
- When a component depends on another, be sure that it depends on every class in that component.
- For example, if lets say `Component A` uses **ONE** function from `Component B`(which has 50 functions):
  - `B` is a dependency of `A`, Even if `A` only used **ONE** function !!
  - Everytime `B` is changed and compiled, `A` shall be recompiled, revalidated and redeployed (even if the function which `A` uses was not modified.)
  - On the other hand, if components are well-separated a minimum number of components will be affected for each time that a dependency change.

###  2.4. <a name='TheTensionDiagramforComponentCohesion'></a>The Tension Diagram for Component Cohesion
- `REP` (group for reusers) and `CCP` (group for maitenance) are inclusive: tend to make components larger.
- `CRP` (which splits to avoid unnecessary releases) is exclusive: tend to make components larger.
- You shall find a balance between these three principles for each of your components.
- If you only select two:
  - `REP`+`CCP` : Too many unneded releases.
  - `CCP`+`CRP` : Groups to reuse.
  - `CRP`+`REP` : Too many components change for each change is requirements.

- Hint: At the beginning `CCP` is more important than `REP`, because developability is more important than reuse.
  
##  3. <a name='Ch14-ComponentCoupling'></a>Ch14 - Component Coupling

###  3.1. <a name='TheAcyclicDependenciesPrincipleADP'></a>The Acyclic Dependencies Principle (ADP)
> No cycles are allowed in the Component Dependency Graph

####  3.1.1. <a name='Introduction'></a>Introduction
- This is a dependency graph `Component A` classes use `Component B` classes i.e. `Component B` is a dependency of `Component A`.
  
![Dependency Graph](/ComputerScience/UncleBob/CleanArchitecture/CH14.png)

####  3.1.2. <a name='AnAcyclicDependencyGraph'></a>An Acyclic Dependency Graph
- It is a `directed graph` where the Components are the `nodes` and the dependency relationship are the `directed edges`.
- It has NO CYCLES (is a `directed acyclic graph` or `DAG`) i.e. Choosing one Component and following the dependency relationships its impossible to return to that Component. 
- The following dependency graph will help to make some observations:
![Dependency Graph](/ComputerScience/UncleBob/CleanArchitecture/CH14a.png)
  - If `Component B` has a new version, only `Component D` and `Component C` will be affected (i.e. the Components that have `Component B` as a dependency). 
  - So the devs in charge of those Component should decide when the integration (with the new version of `Component B`) will happen.
  - If `Component Main` has a new version, no Componentes will be affected.
  - If a possible new version of `Component A` have to be tested, It only needs to build the `Component A` with the versions of `Component D` and `Component B` that are currently using.
  - The compilation process is bottom up. i.e. First `Component B` is compiled.Then `Component D` and `Component C`. Later `Component A` and finally `Component Main`. (We know the build order of this SW because, we understand its dependencies)

####  3.1.3. <a name='TheDependencyCycle'></a>The Dependency Cycle
- If a new Component `Component E` is released and has `Component D` as a dependency and `Component B` as a dependent, we have a `dependency cycle` (showed in **red** in the graph bellow). Some obersavations can be made:
![Dependency Cycle](/ComputerScience/UncleBob/CleanArchitecture/CH14b.png)
  -  If a new version of `Component C` have to be release, it shall be compatible with `Component B`, but now also with `Component E` and with `Component D`. This makes the release more difficult.
  - `Component B`, `Component D` and `Component E` become **one larger Component**. If any of this Components is modified it will affect the others.
    - If `Component E` have to be tested, it shall be build and intetegrated with `Component D` and `Component B`
- Cycles make it very difficult to isolate Components. So Unit testing and releasing become very difficult and error propne.
- The build order is difficult to obtain (because the cycle).

####  3.1.4. <a name='BreakingtheCycle'></a>Breaking the Cycle

- **Problem:** `Component B` is a dependency of `Component D` (i.e. some `Class` in `Component D` uses a `Class` of `Component B`). In C++ that can be see it as the code belows:

``` cpp
// Component B
// file: ClassB1.h
class ClassB1{
	...
}


// Component D
// file: ClassB1.h
#include "ClassB1" //<= Dependency!!!
class ClassD1{
	ClassB1 obj;   // Object that uses that dependency!!!
	...
}
```
- **Solution:** Dependency Inversion.
  - The `Class` in `Component D` now uses an `Interface` which belongs to its Component.
  - The `Class` in `Component B` (which was used) now imnplements the `Interface` from `Component D`.
  - To use this new structure `dependency injection` is used.

The problem (in red) and the solution can be see it graphically in the Figure below:

![How to break a Cycle](/ComputerScience/UncleBob/CleanArchitecture/CH14c.png)

###  3.2. <a name='Top-DownDesign'></a>Top-Down Design

###  3.3. <a name='TheStableDependenciesPrincipleSDP'></a>The Stable Dependencies Principle (SDP)

> The dependencies of Component shall have less or equal *INSTABILITY* (I) than the Component.

or in other words

> The Instability decreases in the direction of dependency.

####  3.3.1. <a name='Introduction-1'></a>Introduction

- Stability is the difficulty to change.
- To make a Component **STABLE** many Components shall depend on it (i.e. because it requires a lot of work to implemment the changes to all its dependent Components).
- An example of **STABLE** Component is presented below:
  - **RESPONSIBLE**: Three Components depend on it, so it has THREE good reasons to not be modified. It is said *This Component is **RESPONSIBLE** for these three Components*
  - **INDEPENDENT**: That Component has no dependencies, so it has no external influences to force a change.
![A STABLE Component](/ComputerScience/UncleBob/CleanArchitecture/CH14d.png)

- An example of a very **UNSTABLE** Component is presented as follows:
  - **IRRESPONSIBLE**: No Component has this Component as dependency.
  - **DEPENDENT**: The Component has three dependencies, so has three external sources that can force change.
![An UNSTABLE Component](/ComputerScience/UncleBob/CleanArchitecture/CH14e.png)

####  3.3.2. <a name='StabilityMetricsI'></a>Stability Metrics (I)
Instability is defined as:
> I = Fan-Out / (Fan-In + Fan-Out) 
>
> Where:
> - Fan-In: Incoming dependencies i.e. the number of classes outside this Component which depend on classes of this Component.
> - Fan-Out: Outgoing dependencies i.e. The number of classes inside this Componen which depend on classes outside this Component.

- The range of Instability metric is `[0,1]`:
  - `I = 0` : means maximum stability i.e. The Component has no dependencies
  - `I = 1` : menas maximum instability i.e. The Component is not a dependency for other Components.
- The Instability calculation is easier if the source code has **one class for each file**.

**NOTES**:
- Not all Components shall to be **STABLE**.
  - Business rules or things that are not probable to change shall be implemented as `STABLE Components`
  - UI and things that are very probable to change shall be implemented as `UNSTABLE Components`
- When drawing a `dependency graph`, It is recomended to put unstable Components at the top of the diagram. So, any arrow that points up is violating the `Stable Dependency Principle`

####  3.3.3. <a name='Anapplicationproblem'></a>An application problem
- Lets say we have three Components ideally configured, and its `dependency graph` is a follows: 
![Solution procedure](/ComputerScience/UncleBob/CleanArchitecture/CH14f.png)

- But for some reason, a new Component which is less **STABLE** (I!=0) is added and used as a dependency (red color in Figure below) by the former **STABLE** Component. 
![Solution procedure](/ComputerScience/UncleBob/CleanArchitecture/CH14g.png)

- This clearly violates SDP, because No Component shall have a dependency with more Instability metric value. In other words, if the Component has `I=0` its dependency shall also has `I=0`.  So **How can this problem be solved?**

- The solution is also found in `DIP - Dependency Inversion Principle`:
  - Create a new Component which implements an `Interface`.
  - In the Dependent Component: the class (which uses the Class from the dependency) now uses that `Interface`
  - In the Dependency Component: the used class now implements that `Interface` 
  - The initial configuration is presented in **red** and the solution in **green** in the following Figure.

![Solution procedure](/ComputerScience/UncleBob/CleanArchitecture/CH14h.png)

- Once solved, the solution can be added to the original dependency graph   as presented below:
![Solution presented](/ComputerScience/UncleBob/CleanArchitecture/CH14i.png)

NOTE:
- The new Component only has an `Interface` (which has no implementation), `abstract Components` are very stable and ideal dependencies for less stable Components.


###  3.4. <a name='TheStableAbstractionPrincipleSAP'></a>The Stable Abstraction Principle (SAP)

> A Component shall be as ABSTRACT as it is STABLE

or

> Dependencies run in the direction of abstraction

or 

> **STABLE COMPONENTS** should also be `abstract` so that its stability does not prevent it from being extended.
> **UNSTABLE COMPONENTS** should be `concrete` so that its instability allows it to be modified.

####  3.4.1. <a name='Introduction-1'></a>Introduction
- High-level policies and Business Rules shall be placed into **STABLE** Components (`I = 0`)
- Volatile parts, e.g. UI shall be placed into **UNSTABLE** Components (`I = 1`)
- **HOWEVER:** if we put Business Rules into stable components. it will be difficul to change (stiffenning the Architecture), **they need to be flexible enough to withstand change**.
- **SOLUTION:** Based on the `OCP` i.e (Create classes that are flexible enough to be extended withouth requiring modification) the **MOST STABLE** Components shall have **ABSTRACT CLASSES**

####  3.4.2. <a name='AbstractnessmetricA'></a>Abstractness metric (A)
The measure of abstractness of a Component is measured as:
> A = Na / Nc
>
> Where:
> - Na: Number of `interfaces` and `abstract classes` in the Component.
> - Nc: Number of `classes`in the Component.


####  3.4.3. <a name='StabilityIvsAbstracnessA'></a>Stability (I) vs Abstracness (A)

![I vs A](/ComputerScience/UncleBob/CleanArchitecture/CH14j.PNG)

Where:
- Maximum maximum stability and abstracness are at (0,1)
- Minimum maximum stability and concreteness are at (1,0)

However three regions can be identified:
- **The Zone of Pain**: Where highly stable and concrete Components are located. These kind of Components are undesirable because they are too rigid too modify. So, these comopnents are painful when they are volatile otherwise are harmless.
- **The Zone of Uselessness**: Where Components which are maximally abstract and have no dependents. So, they are abstract classes that no one ever implemented.
- **The Main Sequence**: Components that are not too **abstract** for its stability and not too **unstable** for its abstracness. In general, Components shall be on or close to this region.

#### Distance (D) from the Main Sequence
> `D = | A + I - 1 | `
> 
> Where:
>  `D = 0`: Component is directly on the main sequence.
>  `D = 1`: Component is at the maximum distance from the main sequence.

- So, if we define a thereshold (e.g. `0.1`) for `D`. We can use it as a reference, then if a Component has higher `D` this Component shall be **restructured**
- It is presented below an I vs A graph were parallel lines (to the main sequence) are included to represent `standard deviation (Z)`  

![Main Sequence and Components](/ComputerScience/UncleBob/CleanArchitecture/CH14k.PNG)

The `Distance (D)` can also be ploted in `Number of Release vs Distance graphs`. So it can be observed the evolution of the Component per release.

![D: Distance per release](/ComputerScience/UncleBob/CleanArchitecture/CH14l.PNG)