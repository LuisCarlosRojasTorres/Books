<!-- vscode-markdown-toc -->
* 1. [Ch13 - Component Cohesion](#Ch13-ComponentCohesion)
	* 1.1. [REP: The Reuse/Release Equivalence Principle](#REP:TheReuseReleaseEquivalencePrinciple)
	* 1.2. [CCP: The Common Closure Principle](#CCP:TheCommonClosurePrinciple)
	* 1.3. [CRP: The Common Reuse Principle](#CRP:TheCommonReusePrinciple)
	* 1.4. [The Tension Diagram for Component Cohesion](#TheTensionDiagramforComponentCohesion)
* 2. [Ch14 - Component Coupling](#Ch14-ComponentCoupling)
	* 2.1. [The Acyclic Dependencies Principle](#TheAcyclicDependenciesPrinciple)
		* 2.1.1. [Introduction](#Introduction)
		* 2.1.2. [An Acyclic Dependency Graph](#AnAcyclicDependencyGraph)
		* 2.1.3. [The Dependency Cycle](#TheDependencyCycle)
		* 2.1.4. [Breaking the Cycle](#BreakingtheCycle)
	* 2.2. [Top-Down Design](#Top-DownDesign)
	* 2.3. [The Stable Dependencies Principle](#TheStableDependenciesPrinciple)
	* 2.4. [The Stable Abstraction Principle](#TheStableAbstractionPrinciple)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->
##  1. <a name='Ch12-Components'></a>Ch12 - Components
- Well-designed components are independently deployable, and for that reason independently developable.

##  1. <a name='Ch13-ComponentCohesion'></a>Ch13 - Component Cohesion
Three principles of component cohesion:

###  1.1. <a name='REP:TheReuseReleaseEquivalencePrinciple'></a>REP: The Reuse/Release Equivalence Principle

`The granule of reuse is tha granule of release.`
- Software components shall be tracket through a release number and process. This is important to: 
  - verify compatibility.
  - know when new releases are comming.
  - document and notify the changes between versions.
  - create a cohesive group of classes and modules into a component.

###  1.2. <a name='CCP:TheCommonClosurePrinciple'></a>CCP: The Common Closure Principle

`classes that change for the same reasons and at the same times = same component`

- In general **maintainability** is more important than **reusability** (how many times you will reuse a component vs how many minor versons you will release of that sw?)
- So, if a requirement changes, there is a good chance that a minimal number of software components will change. This minimizes the workload related to releasing, revalidating, and redeploying the software.
- For example, three classes that calculate trigonometric functions for a given angle in radians. If the algorithm to calculate the radian into to the return value of the functions change, all those functions also changes. So they shall go to the same module. Even if a requirements changes affecting the trigonometric functions, only onw component will be affected (because all they belong to the same component).

###  1.3. <a name='CRP:TheCommonReusePrinciple'></a>CRP: The Common Reuse Principle

`Don’t force users of a component to depend on things they don’t need.`

- Classes and modules that tend to be reused together belong in the
same component.
- So, classes that have lots of dependencies (tightly coupled) of each other belong to the same component.
- When a component depends on another, be sure that it depends on every class in that component.
- For example, if lets say `Component A` uses **ONE** function from `Component B`(which has 50 functions):
  - `B` is a dependency of `A`, Even if `A` only used **ONE** function !!
  - Everytime `B` is changed and compiled, `A` shall be recompiled, revalidated and redeployed (even if the function which `A` uses was not modified.)
  - On the other hand, if components are well-separated a minimum number of components will be affected for each time that a dependency change.

###  1.4. <a name='TheTensionDiagramforComponentCohesion'></a>The Tension Diagram for Component Cohesion
- `REP` (group for reusers) and `CCP` (group for maitenance) are inclusive: tend to make components larger.
- `CRP` (which splits to avoid unnecessary releases) is exclusive: tend to make components larger.
- You shall find a balance between these three principles for each of your components.
- If you only select two:
  - `REP`+`CCP` : Too many unneded releases.
  - `CCP`+`CRP` : Groups to reuse.
  - `CRP`+`REP` : Too many components change for each change is requirements.

- Hint: At the beginning `CCP` is more important than `REP`, because developability is more important than reuse.
  
##  2. <a name='Ch14-ComponentCoupling'></a>Ch14 - Component Coupling

###  2.1. <a name='TheAcyclicDependenciesPrinciple'></a>The Acyclic Dependencies Principle
> No cycles are allowed in the Component Dependency Graph
> 
####  2.1.1. <a name='Introduction'></a>Introduction
- This is a dependency grapgh `Component A` classes use `Component B` classes i.e. `Component B` is a dependency of `Component A`.
![Dependency Graph](/ComputerScience/UncleBob/CleanArchitecture/CH140.png)

####  2.1.2. <a name='AnAcyclicDependencyGraph'></a>An Acyclic Dependency Graph
- It is a `directed graph` where the Components are the `nodes` and the dependency relationship are the `directed edges`.
- It has NO CYCLES (is a `directed acyclic graph` or `DAG`) i.e. Choosing one Component and following the dependency relationships its impossible to return to that Component. 
- The following dependency graph will help to make some observations:
![Dependency Graph](/ComputerScience/UncleBob/CleanArchitecture/CH14a.png)
  - If `Component B` has a new version, only `Component B` and `Component C` will be affected (i.e. the Components that have `Component B` as a dependency). 
  - So the devs in charge of those Component should decide when the integration (with the new version of `Component B`) will happen.
  - If `Component Main` has a new version, no Componentes will be affected.
  - If a possible new version of `Component A` have to be tested, It only needs to build the `Component A` with the versions of `Component D` and `Component B` that are currently using.
  - The compilation process is bottom up. i.e. First `Component B` is compiled.Then `Component D` and `Component C`. Later `Component A` and finally `Component Main`. (We know the build order of this SW because, we understand its dependencies)

####  2.1.3. <a name='TheDependencyCycle'></a>The Dependency Cycle
- If a new Component `Component E` is release and has `Component D` as a dependency and `Component B` as a dependent, we have a `dependency cycle` (showed in **red** in the graph bellow). Some obersavations can be made:
![Dependency Cycle](/ComputerScience/UncleBob/CleanArchitecture/CH14b.png)
  -  If a new version of `Component E` have to be release, it shall be compatible with `Component E`, but now also with `Component B`. This makes the release more difficult.
  - `Component B`, `Component D` and `Component E` become **one larger Component**. If any of this Components is modified it will affect the others.
    - If `Component E` have to be tested, it shall be build and intetegrated with `Component D` and `Component B`
- Cycles make it very difficult to isolate Components. So Unit testing and releasing become very difficult and error propne.
- The build order is difficult to obtain (because the cycle).

####  2.1.4. <a name='BreakingtheCycle'></a>Breaking the Cycle

![How to break a Cycle](/ComputerScience/UncleBob/CleanArchitecture/CH14c.png)

###  2.2. <a name='Top-DownDesign'></a>Top-Down Design

###  2.3. <a name='TheStableDependenciesPrinciple'></a>The Stable Dependencies Principle

###  2.4. <a name='TheStableAbstractionPrinciple'></a>The Stable Abstraction Principle

