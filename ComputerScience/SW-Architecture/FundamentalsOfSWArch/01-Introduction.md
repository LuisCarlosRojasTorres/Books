<!-- vscode-markdown-toc -->
* 1. [Defining Software Architecture](#DefiningSoftwareArchitecture)
* 2. [Expectations of an Architecture](#ExpectationsofanArchitecture)
	* 2.1. [Make Architecture Decisions](#MakeArchitectureDecisions)
	* 2.2. [Continually Analyze the Architecture](#ContinuallyAnalyzetheArchitecture)
	* 2.3. [Keep current with latest trends](#Keepcurrentwithlatesttrends)
	* 2.4. [Ensure Compliance with Decisions](#EnsureCompliancewithDecisions)
	* 2.5. [Diverse Exposure and Experience](#DiverseExposureandExperience)
	* 2.6. [Have Business Domain Knowledge](#HaveBusinessDomainKnowledge)
	* 2.7. [Possess Interpersonal Skills](#PossessInterpersonalSkills)
	* 2.8. [Understand and Navigate Politics](#UnderstandandNavigatePolitics)
* 3. [Intersections between](#Intersectionsbetween)
	* 3.1. [SW Architecture and Engineering Practices](#SWArchitectureandEngineeringPractices)
	* 3.2. [SW Architecture and Operations/DevOps](#SWArchitectureandOperationsDevOps)
	* 3.3. [SW Architecture and Process](#SWArchitectureandProcess)
	* 3.4. [SW Architecture and Data](#SWArchitectureandData)
* 4. [Laws of Software Architecture](#LawsofSoftwareArchitecture)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->
##  1. <a name='DefiningSoftwareArchitecture'></a>Defining Software Architecture

 
``` console
Software Architecture = Structure Of the Software       + 
                        Architecture Characteristics    + 
                        Architecture Decisions          + 
                        Design patterns
```
- Software Architecture consist of 4 topics:
  - **Structure of the Software**: This is the Architecture pattern of the Software.
  - **Architecture Characteristics**: The non-functional of the software, i.e., they do not require knowledge about the functionality of the software, however they are required in order to work properly. 
    - Testability, Elasticity, Performance Scalability, etc are Architecture Characteristics.
  - **Architecture Decisions**: It definnes the rules and constraints of how the software shall be constructed and what is and what is not allowed (e.g., Which layers can access to DB).
  - **Design Principles**: Defines guidelines to allow the developer to choose the most appropriate technique/framework/etc.

##  2. <a name='ExpectationsofanArchitecture'></a>Expectations of an Architecture

- This role can range from **expert programmer** up to **defining the strategic technical direction for the company**.
- There are **eight core expectations** on Software Architect:
  1.  **Make architecture decisions**: Define the architecture decisions and design principles used to *guide* (not specify) technology decisions within the team the deparment, or accross the enterprise.
      -  It is possible to make a technical decision in order to preserve architectural characteristics.
  2.  **Continually analyze the architecture** and current technology environment and then recommend solutions for improvement.
  3.  **Keep current with the latest trends and technologies** this helps the architect to be prepared for the future and make correct decisions.
  4.  **Ensure compliance with decisions**: He continually verifies that development teams are following the *architecture decisions* and *design principles* defined and documented.
  5.  **Diverse exposure and experience to different technologies**: At least be familiar with a variety of technologies. Focus on tecnichal breadth than tecnical dept.
  6.  **Have business domain knowledge of the problem space**: (e.g., To be SW Architec in a FinTech you shall know abouts finances) Without this knowledege, it is impossible to communicate with stakeholders which generate a lost in credibility. 
  7.  **Possess interpersonal skills**: To lead the development team through the implementations of the architecture.
  8.  **Understand and navigate politics**: Understand the political climate of the company.
      - Almost every decision an Architect maked will be challenged. This is because the increased cost or increased effort (time) involved.
      - An Architect shall justify and fight for almost every one of these decisions.


