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

`Gather into components those classes that change for the same reasons and at
the same times. Separate into different components those classes that change at
different times and for different reasons`


### CRP: The Common Reuse Principle

`Don’t force users of a component to depend on things they don’t need.`

## Ch14 - Component Coupling