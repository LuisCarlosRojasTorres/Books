<!-- vscode-markdown-toc -->
* 1. [Ch12 - Components](#Ch12-Components)
* 2. [Ch13 - Component Cohesion](#Ch13-ComponentCohesion)
	* 2.1. [REP: The Reuse/Release Equivalence Principle](#REP:TheReuseReleaseEquivalencePrinciple)
	* 2.2. [CCP: The Common Closure Principle](#CCP:TheCommonClosurePrinciple)
	* 2.3. [CRP: The Common Reuse Principle](#CRP:TheCommonReusePrinciple)
	* 2.4. [The Tension Diagram for Component Cohesion](#TheTensionDiagramforComponentCohesion)
* 3. [Ch14 - Component Coupling](#Ch14-ComponentCoupling)
	* 3.1. [The Acyclic Dependencies Principle](#TheAcyclicDependenciesPrinciple)
	* 3.2. [Top-Down Design](#Top-DownDesign)
	* 3.3. [The Stable Dependencies Principle](#TheStableDependenciesPrinciple)
	* 3.4. [The Stable Abstraction Principle](#TheStableAbstractionPrinciple)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->##  1. <a name='Ch12-Components'></a>Ch12 - Components
- Well-designed components are independently deployable, and for that reason independently developable.

##  2. <a name='Ch13-ComponentCohesion'></a>Ch13 - Component Cohesion
Three principles of component cohesion:

###  2.1. <a name='REP:TheReuseReleaseEquivalencePrinciple'></a>REP: The Reuse/Release Equivalence Principle

`The granule of reuse is tha granule of release.`
- Software components shall be tracket through a release number and process. This is important to: 
  - verify compatibility.
  - know when new releases are comming.
  - document and notify the changes between versions.
  - create a cohesive group of classes and modules into a component.

###  2.2. <a name='CCP:TheCommonClosurePrinciple'></a>CCP: The Common Closure Principle

`classes that change for the same reasons and at the same times = same component`

- In general **maintainability** is more important than **reusability** (how many times you will reuse a component vs how many minor versons you will release of that sw?)
- So, if a requirement changes, there is a good chance that a minimal number of software components will change. This minimizes the workload related to releasing, revalidating, and redeploying the software.
- For example, three classes that calculate trigonometric functions for a given angle in radians. If the algorithm to calculate the radian into to the return value of the functions change, all those functions also changes. So they shall go to the same module. Even if a requirements changes affecting the trigonometric functions, only onw component will be affected (because all they belong to the same component).

###  2.3. <a name='CRP:TheCommonReusePrinciple'></a>CRP: The Common Reuse Principle

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

###  3.1. <a name='TheAcyclicDependenciesPrinciple'></a>The Acyclic Dependencies Principle

###  3.2. <a name='Top-DownDesign'></a>Top-Down Design

###  3.3. <a name='TheStableDependenciesPrinciple'></a>The Stable Dependencies Principle

###  3.4. <a name='TheStableAbstractionPrinciple'></a>The Stable Abstraction Principle

