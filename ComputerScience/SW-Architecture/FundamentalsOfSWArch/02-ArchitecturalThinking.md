<!-- vscode-markdown-toc -->
* 1. [Architecture Versus Design](#ArchitectureVersusDesign)
* 2. [Technical Breadth](#TechnicalBreadth)
* 3. [Analyzing Trade-Offs](#AnalyzingTrade-Offs)
* 4. [Understanding Business Drivers](#UnderstandingBusinessDrivers)
* 5. [ How to Balance SW Architecture knowledge and Coding habilities?](#HowtoBalanceSWArchitectureknowledgeandCodinghabilities)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='ArchitectureVersusDesign'></a>Architecture Versus Design

##  2. <a name='TechnicalBreadth'></a>Technical Breadth
- A Software Architecture shall have a significant amount of *technical depth*.
- All technical knowledge in the world can be represented by the *knowledge pyramid* (Figure a):
  - *Stuff you know* (green): things that it is used every day
  - *Stuff you know you don't know* (yellow): things that you heard of or have little or no expertise in 
  - *Stuff you don't know you don't know* (orange): it would be the perfect solution for a problem but you dont even know those things exist.
- For a *developer* it is recommended to (Figure b):
  - to focus on the green area, to get experience and expertise.
  - invest time and effort to maintain green area up to date
  - Note: green area height is known as `technical depth`
- For an *Architect* it is recomended to:
  - focus on green and yellow areas of the pyramids
  - focus on `technical breadth` rather than `technical depth` (Figure c)
- Eventually the `architect knowledge pyramid` becomes similar to (Figure d) where some areas of expertise will remain and others atrophy.
![Technical Breadth](uploads/CH02-001.png)  

##  3. <a name='AnalyzingTrade-Offs'></a>Analyzing Trade-Offs

> "Architecture is the stuff you can't Google" - Mark Richards

- The famous answer to every question in sw architecture is `it depends`
  - It depends on: deployment environment, business drivers, company culture, budgets, timeframes etc...
- Thinking architecturally is looking at the benefits of a given solution, but also analyzing the negatives or trade-offs.
  - All om software arcitecture has a trade-off i.e, an advantage and a disadvantage. The decision depends of the business drivers: 
    - What is more important? `A` gives `extensibility` but `B` gives `security`? The solution of course, It depends ...

##  4. <a name='UnderstandingBusinessDrivers'></a>Understanding Business Drivers

- To think like an architect it is mandatory to:
  - understand the business drivers that are required for the success of the software
  - traslate those reqs into *Architecture Characteristics* (i.e., performance, elasticity etc.)
- Perform the aforementioned tasks requires:
  - some level of business domain knowledge
  - healthy and collaborative relationships with stakeholders

> The chapters:
> CH04 Defining Architecture Characteristics
> CH05 Indentifying Architecture Characteristics
> CH06 Measuring Architecture Characteristics
>
> Bring useful information about this topic!

##  5. <a name='HowtoBalanceSWArchitectureknowledgeandCodinghabilities'></a> How to Balance SW Architecture knowledge and Co

- A SW Architect requires both.
- A SW Architect can code of course, **BUT** cannot be a `bottleneck`
  - This happens, when the SW Arch, take ownership of code which belongs to the critical path of the project.
    - The SW Arch has not enough time to be a full dev, so it can turn a `bottleneck`
- Ways to avoid the `bottleneck trap`:
  - Delegate *critical path code* to full time devs, then implement only *business functionality code*