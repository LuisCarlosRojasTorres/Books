<!-- vscode-markdown-toc -->
* 1. [Good Comments](#GoodComments)
	* 1.1. [Legal Comments](#LegalComments)
	* 1.2. [Informative](#Informative)
	* 1.3. [Explanation](#Explanation)
	* 1.4. [Clarification](#Clarification)
	* 1.5. [Warning of Consequences](#WarningofConsequences)
	* 1.6. [TODO](#TODO)
	* 1.7. [Amplification](#Amplification)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

> "Dont comment bad code - reqrite it!!" - B. Kernigham and P. Plaugher
- No good.
- No bad.
- Only a **necessary evil**
- Coments compensate out failure to express ourself in code.
- Every time you express yourself in code, you should pat yourself on the back.
  - Every time you write a comment, you should grimace and feel the failure of your ability of expression.
- Nobody maintains comments!
- Truth can only be found in one place: the code!!
  
##  1. <a name='GoodComments'></a>Good Comments

###  1.1. <a name='LegalComments'></a>Legal Comments
- It refers to a standard licence or other external document rather than putting all the terms and conditions into the comment.

###  1.2. <a name='Informative'></a>Informative Comments
- Explain the parts of the code which needs additional knowledge to understand. E.g. Regex, mathematical formulas
  
###  1.3. <a name='Explanation'></a>Explanation Comments
- Provides the intent behind a decision in the code.

``` cpp
// Euler method only for testing integration
void EulerImplicitMethod(...)

// RK4 method an easy but accurate method! 
void RungeKutta4Method(...)
```
###  1.4. <a name='Clarification'></a>Clarification Comments

###  1.5. <a name='WarningofConsequences'></a>Warning of Consequences Comments

###  1.6. <a name='TODO'></a>TODO Comments
 
###  1.7. <a name='Amplification'></a>Amplification Comments
