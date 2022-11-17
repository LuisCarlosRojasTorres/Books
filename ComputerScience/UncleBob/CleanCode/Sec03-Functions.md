<!-- vscode-markdown-toc -->
* 1. [SMALL:](#SMALL:)
* 2. [ONLY ONE PURPOSE:](#ONLYONEPURPOSE:)
* 3. [ONE LEVEL OF ABSTRACTION PER FUNCTION](#ONELEVELOFABSTRACTIONPERFUNCTION)
* 4. [SWITCH STATEMENTS](#SWITCHSTATEMENTS)
* 5. [Use descriptive names](#Usedescriptivenames)
* 6. [Function Arguments](#FunctionArguments)
* 7. [Command-Query Separation:](#Command-QuerySeparation:)
* 8. [DRY](#DRY)
* 9. [ONNE-ONE rule](#ONNE-ONErule)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

Which attributes functions shall have to be easy to read and understand?

##  1. <a name='SMALL:'></a>SMALL:
- Never bigger than the screen (150 characters per line and 50 lines).
  - A maximum of 25 lines with a tolerance of 5 lines.
- Blocks with `if/else`, `while` and so on **should be ONE LINE LONG** where a function (with a descriptive name) should be called.
- It should not have `nested structures`
- It should not have an `indentation level` greater than 2 (otherwise affects the understanding)

##  2. <a name='ONLYONEPURPOSE:'></a>ONLY ONE PURPOSE:

- If the functions does only steps that are **one level BELOW** the stated name of the function, **THEN** the funciton is doing one thing.
- If you can **extract from a function `f` another function `f2`** with a name that is not merely a restatement of the `f` implementation. **Then** `f` is doing more than one thing.
- If the implementation of a function **can be divided into sections** (i.e declarations, initializations etc) then the function is doing more than one thing.

##  3. <a name='ONELEVELOFABSTRACTIONPERFUNCTION'></a>ONE LEVEL OF ABSTRACTION PER FUNCTION
- It shall not contain different levels of abstractions, because is always confusing:
  - Example of high level: render a page.
  - Example of intermediate level: instantiating objects``
  - Example of low level: calling object.methods
- It shall follow **The Step-down Rule**:
  - So **every function shall be followed by those at the next level of abstraction** so that we can read the program, descending one level of abstraction at a time as we read down the list of functions.

##  4. <a name='SWITCHSTATEMENTS'></a>SWITCH STATEMENTS
- `SWITCH` statements can be tolerated if they appear only once, are used to create polymorphic objects, and are hidden behind an inheritance, so the rest of the software cannnot see them.
  
> - Use polymorphism to dont repeat `switch` code and bury it in a low-level `class`
> - Example:
>
>  ``` java
>  public Money calculatePay(Employee e) throws InvalidEmployeeType {
>     switch (e.type) {
>         case COMMISSIONED:
>             return calculateCommissionedPay(e);
>         case HOURLY:
>             return calculateHourlyPay(e);
>         case SALARIED:
>            return calculateSalariedPay(e);
>        default:
>            throw new InvalidEmployeeType(e.type);
>    }
>}
>  ```
>- This function:
>  - Its large.
>  - If new `Employee` types are added it will be modified.
>  - It does more than one thing
>  - Violates SRP: there is more than one reason to change.
>  - Violates OCP: it must change whenever new types are added.
>
> - **SOLUTION**: Use the pattern `ABSTRACT FACTORY`. Then factory will use the `switch` statement to create appropriate instances of the derivatives of `Employee`, and the function `calculatePay` **will be dispatched polymorphically** through the `Employee interface`
>
>``` java
>public abstract class Employee {
>    public abstract boolean isPayday();
>    public abstract Money calculatePay();
>    public abstract void deliverPay(Money pay);
>}
>
>public interface EmployeeFactory {
>    public Employee makeEmployee(EmployeeRecord r) throws >InvalidEmployeeType;
>}
>
>public class EmployeeFactoryImpl implements EmployeeFactory {
>    
>    public Employee makeEmployee(EmployeeRecord r) throws InvalidEmployeeType>{
>        switch (r.type) {
>            case COMMISSIONED:
>                return new CommissionedEmployee(r) ; //Derivatives of >Employee
>            case HOURLY:
>                return new HourlyEmployee(r); //Derivatives of Employee
>            case SALARIED:
>                return new SalariedEmploye(r); //Derivatives of Employee
>            default:
>                throw new InvalidEmployeeType(r.type);
>        }
>    }
>}
>```



##  5. <a name='Usedescriptivenames'></a>Use descriptive names

- Ward's principle: `You know you are working on clean code when each routine turns out to be pretty much what you expected`
- The smaller and more focused a function is, the easier it is to choose a descriptive name.
- A long descriptive name is better than:
  -  a short enigmatic name.
  - a long descriptive comment.
- Be consistent in your names. use the same phrases, nouns and verbs in the function names.
- A good function name shall be explain the intent of the function and the order and intent of the arguments.


##  6. <a name='FunctionArguments'></a>Function Arguments
- Three or more arguments should be avoided where possible.
  - More arguments increase the difficulty to test the function i.e., create test cases for all the various combinations of arguments.
- `Output arguments` are harder to understand than `input arguments`. using an `output argument` instead of a `return` value for a trnasformation is confusing.
- **One parameter function:** 
  - It is used for:
    - Asking questions about the argument.
    - Operating on that argument, transforming it into something else and **RETURNING IT**
    - Event handling i.e., the argument is used to modify the state of the software.
- **Flag argument function:**
  - Passing a boolean into a function is a terrible practice!!
- **Argument Objects:**
  - For more than two or three arguments, check if they can be wraped into an object. e.g., From `drawCircle(double x, doubley, double radius)` to `drawCircle(Point center, double radius)`
- **Argument lists:** i.e. functions with a variable number of arguments
  - If the variable arguments are treated identically, then they are equivalente to a single argument of type `List`.
- **Output Arguments:**
  - should be avoided. If your function must change the state of something, have it change the state of its owning object.
##  7. <a name='Command-QuerySeparation:'></a>Command-Query Separation:
- Functions shall either **do something** or **answer something**, but not both. e.g. `bool setName(String attribute, String value)` i shall be `void`.
  - For that reason, separate the command from the query so that the ambiguity cannot occur.
- **Prefer Exceptions to Returning Error Codes:**
  - Returning error codes (e.g., `logger.log("InvalidInput")`)from command functions is agaisnt the `Command-QUery separation`
    - This leads to deeply and confusing nested structures. Mixing function logic with error handling mechanism.
    - If you use `exceptions` instead of return `error codes`, You **separate** `function logic` from `error handling mechanisms`
    - Try-catch block adds confusion to the code, so it is better to call functions inside its structure. i.e., an function whith `throws Exception` inside the `try`, and the `logger` in the `catch`.
    - Functions only does on thing, so functions that handle errors only do that!! Nothing before the `try` and nothis after the `catch`.
    - Returning errors menas there is an `enum` somewhere with all the errors listed. This creates `dependency problems` i.e. Once a new error is added, all the classes which have it as a dependency shall be recompiled.
      - If you use exceptions, new exceptions are `subclasses` of the `exception class`. This not force any recompilation or redeployment!!.
##  8. <a name='DRY'></a>DRY
- Duplication may be the root of all evil in software.

##  9. <a name='ONNE-ONErule'></a>ONNE-ONE rule
- `Every function, and every block with a function, should have **one entry and one exit**`- E. Dijkstra
  - These means:
    - Only one `return` per function
    - No `break` or `continue`
    - **NEVER** `goto`
  - However, only in larger functions that rules provide significant benefit.
    - For small functions, multiple `return`, `breaks` or `continue` statements does no harm and can be more expressive.



































