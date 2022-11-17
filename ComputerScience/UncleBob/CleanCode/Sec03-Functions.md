Which attributes functions shall have to be easy to read and understand?

## SMALL:
- Never bigger than the screen (150 characters per line and 50 lines).
  - A maximum of 25 lines with a tolerance of 5 lines.
- Blocks with `if/else`, `while` and so on **should be ONE LINE LONG** where a function (with a descriptive name) should be called.
- It should not have `nested structures`
- It should not have an `indentation level` greater than 2 (otherwise affects the understanding)

## ONLY ONE PURPOSE:

- If the functions does only steps that are **one level BELOW** the stated name of the function, **THEN** the funciton is doing one thing.
- If you can **extract from a function `f` another function `f2`** with a name that is not merely a restatement of the `f` implementation. **Then** `f` is doing more than one thing.
- If the implementation of a function **can be divided into sections** (i.e declarations, initializations etc) then the function is doing more than one thing.

## ONE LEVEL OF ABSTRACTION PER FUNCTION
- It shall not contain different levels of abstractions, because is always confusing:
  - Example of high level: render a page.
  - Example of intermediate level: instantiating objects``
  - Example of low level: calling object.methods
- It shall follow **The Step-down Rule**:
  - So **every function shall be followed by those at the next level of abstraction** so that we can read the program, descending one level of abstraction at a time as we read down the list of functions.

## SWITCH STATEMENTS
- Use polymorphism to dont repeat `switch` code and bury it in a low-level `class`
- Example:

 ``` java
 public Money calculatePay(Employee e) throws InvalidEmployeeType {
    switch (e.type) {
        case COMMISSIONED:
            return calculateCommissionedPay(e);
        case HOURLY:
            return calculateHourlyPay(e);
        case SALARIED:
            return calculateSalariedPay(e);
        default:
            throw new InvalidEmployeeType(e.type);
    }
}
 ```
- This function:
  - Its large.
  - If new `Employee` types are added it will be modified.
  - It does more than one thing
  - Violates SRP: there is more than one reason to change.
  - Violates OCP: it must change whenever new types are added.
- **SOLUTION**: Use the pattern `ABSTRACT FACTORY`. Then factory will use the `switch` statement to create appropriate instances of the derivatives of `Employee`, and the function `calculatePay` **will be dispatched polymorphically** through the `Employee interface`

``` java
public abstract class Employee {
    public abstract boolean isPayday();
    public abstract Money calculatePay();
    public abstract void deliverPay(Money pay);
}

public interface EmployeeFactory {
    public Employee makeEmployee(EmployeeRecord r) throws InvalidEmployeeType;
}

public class EmployeeFactoryImpl implements EmployeeFactory {
    
    public Employee makeEmployee(EmployeeRecord r) throws InvalidEmployeeType{
        switch (r.type) {
            case COMMISSIONED:
                return new CommissionedEmployee(r) ; //Derivatives of Employee
            case HOURLY:
                return new HourlyEmployee(r); //Derivatives of Employee
            case SALARIED:
                return new SalariedEmploye(r); //Derivatives of Employee
            default:
                throw new InvalidEmployeeType(r.type);
        }
    }
}
```

- `SWITCH` statements can be tolerated if they appear only once, are used to create polymorphic objects, and are hidden behind an inheritance, so the rest of the software cannnot see them.

## Use descriptive names







































