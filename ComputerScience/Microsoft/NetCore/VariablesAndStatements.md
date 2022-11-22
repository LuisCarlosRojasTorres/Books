

## Using identifiers
- They are the names used to identify the elements in programs. e.g., `namespaces`, `classes`, `methods` and `variables`.
  - Only letters (uppercase and lowercase), digits and underscore characters can be used.
  - An `identifier` shall start with a letter or underscore.

## Using variables

[Definition of Variable](/ComputerScience/Microsoft/NetCore/ConceptsAndDefinitions.md#3-variable)

### Naming conventions
- Do not start with underscore (`_`). It will limit the interoperability with other languages.
- Do not create identifiers that differ only by case. It can be consfusing and also limit the interoperability with other languages.
- Start the name with a lowercase letter.
- In a multiword identifier, use `camelCase` notation.
- Do not use `Hungarian` notation.

### Declaring variables
- 

``` cs
// A variable can be declared and then initialized in different lines
int age;
age = 42;
// Or not
int height = 172;
```

- A variable contains a random value until you assign a value to it.
- `C#` does not allow the use of unassigned variables. This is called `definite assignment rule`.

#### Primitive variables

|Data type| Description | Size(bits) | Example |
|---------|-------------|------------|---------|
|`int`| integers| 32|`int age = 34;`| 
|`long`| integers (bigger range)| 64 |`long age = 34L;`| 
|`float`| floating-point numbers| 32|`float age = 34.00F;`| 
|`double`| Double-precision floating-point numbers| 64|`double age = 34.00;`| 
|`decimal`| Monetary values| 128|`decimal age = 34.00M;`| 
|`string`| Sequence of characters| 16 (per character)|`string age = "34";`| 
|`char`| Single character| 16|`char age = '3';`| 
|`bool`| Boolean| 8|`bool isOld = false;`| 

