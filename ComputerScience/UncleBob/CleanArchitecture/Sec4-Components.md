## Ch12 - Components
- Well-designed components are independently deployable, and for that reason independently developable.

## Ch13 - Component Cohesion
Three principles of component cohesion:

### REP: The Reuse/Release Equivalence Principle

`The granule of reuse is tha granule of release.`
- Software components shall be tracket through a release number and process. This is important to: 
  - verify compatibility.
  - know when new releases are comming.
  - document and notify the changes between versions.
  - create a cohesive group of classes and modules into a component.

### CCP: The Common Closure Principle

`classes that change for the same reasons and at the same times = same component`

- In general **maintainability** is more important than **reusability** (how many times you will reuse a component vs how many minor versons you will release of that sw?)
- So, if a requirement changes, there is a good chance that a minimal number of software components will change. This minimizes the workload related to releasing, revalidating, and redeploying the software.
- For example, three classes that calculate trigonometric functions for a given angle in radians. If the algorithm to calculate the radian into to the return value of the functions change, all those functions also changes. So they shall go to the same module. Even if a requirements changes affecting the trigonometric functions, only onw component will be affected (because all they belong to the same component).

### CRP: The Common Reuse Principle

`Don’t force users of a component to depend on things they don’t need.`

- Classes and modules that tend to be reused together belong in the
same component.
- So, classes that have lots of dependencies (tightly coupled) of each other belong to the same component.
- When a component depends on another, be sure that it depends on every class in that component.
- For example, if lets say `Component A` uses **ONE** function from `Component B`(which has 50 functions):
  - `B` is a dependency of `A`, Even if `A` only used **ONE** function !!
  - Everytime `B` is changed and compiled, `A` shall be recompiled, revalidated and redeployed (even if the function which `A` uses was not modified.)
  - On the other hand, if components are well-separated a minimum number of components will be affected for each time that a dependency change.

### The Tension Diagram for Component Cohesion

## Ch14 - Component Coupling