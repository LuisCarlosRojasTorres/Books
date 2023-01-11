<!-- vscode-markdown-toc -->
* 1. [Purpose](#Purpose)
* 2. [Whats is LINQ](#WhatsisLINQ)
* 3. [Using LINQ](#UsingLINQ)
	* 3.1. [Selecting data](#Selectingdata)
	* 3.2. [Filtering data](#Filteringdata)
	* 3.3. [Ordering, grouping and aggregating data](#Orderinggroupingandaggregatingdata)
		* 3.3.1. [Ordering](#Ordering)
		* 3.3.2. [Grouping](#Grouping)
		* 3.3.3. [Aggregating](#Aggregating)
	* 3.4. [Joining data](#Joiningdata)
	* 3.5. [Using query operators](#Usingqueryoperators)
		* 3.5.1. [Examples](#Examples)
	* 3.6. [LINQ and deferred evaluation](#LINQanddeferredevaluation)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->


##  1. <a name='Purpose'></a>Purpose
- Learn how to search for items in a collection that match a specific set of criteria.
- How to use advance C# features to query and manipulate data.

##  2. <a name='WhatsisLINQ'></a>Whats is LINQ
- LINQ = Language-Integrated Query
- It is a group of features that abstract the mechanism that an application uses to query data from application code itself.
- It provides syntax and semantics very reminiscent of SQL and with many of the same advantages.
  - It is more flexible and can handle a wider variety of logical data structure.
##  3. <a name='UsingLINQ'></a>Using LINQ
- Dummy data is presented below to show how to use the LINQ operators:
  
``` cs 
var customer = new[]
{
    new{ CustomerID = 1, FirstName = "Lala", LastName = "Papata", Company = "Facabaaka"},
    new{ CustomerID = 2, FirstName = "Lele", LastName = "Pepete", Company = "Fecebeeke"},
    new{ CustomerID = 3, FirstName = "Lili", LastName = "Pipiti", Company = "Ficibiiki"},
    new{ CustomerID = 4, FirstName = "Lolo", LastName = "Popoto", Company = "Focobooko"},
    new{ CustomerID = 5, FirstName = "Lulu", LastName = "Puputu", Company = "Fucubuuku"},
    new{ CustomerID = 6, FirstName = "Lalo", LastName = "Papota", Company = "Facabaaka"},
    new{ CustomerID = 7, FirstName = "Lelo", LastName = "Pepote", Company = "Fecebeeke"},
    new{ CustomerID = 8, FirstName = "Lila", LastName = "Pipati", Company = "Ficibiiki"}
};

var addresses = new[]
{
    new{ Company = "Facabaaka", City = "Lama"},
    new{ Company = "Fecebeeke", City = "Leme"},
    new{ Company = "Ficibiiki", City = "Limi"},
    new{ Company = "Focobooko", City = "Lomo"},
    new{ Company = "Fucubuuku", City = "Lumu"}
}
```
###  3.1. <a name='Selectingdata'></a>Selecting data
- It retrieves specific data from the array.
  - In the example case, just the value in the `FirstName` field of each item in the array.
- The parameter os `Select` is another method, e.g., a `lambda` method.
- The example is presented below:
``` cs
IEnumerable<string> customerFirstNames = customers.Select(customer => customer.FirstName);
foreach (string name in customerFirstNames)
{ 
    Console.WriteLine(name);
}
```
The output is:
``` console
Lala
Lele
Lili
Lolo
Lulu
Lalo
Lelo
Lila
Lola
Lula
```
- Another example which takes two fields:
``` cs 
var customerFullNames = customers.Select(cust => new 
    {
        FirstName = cust.FirstName,
        LastName = cust.LastName
    });
foreach (var p in customerFullNames)
{
    Console.WriteLine($" > {p.FirstName} , {p.LastName}");
}
```
- The output is:
``` console
 > Lala , Papata
 > Lele , Pepete
 > Lili , Pipiti
 > Lolo , Popoto
 > Lulu , Puputu
 > Lalo , Papota
 > Lelo , Pepote
 > Lila , Pipati
 > Lola , Popato
 > Lula , Pupatu
```
###  3.2. <a name='Filteringdata'></a>Filtering data

- It restricts the number of rows that the enumerable collection contains.
- The `Where` method is similar to `Select`. it expects a parameter that defines a method that filters the data according to whatever criteria you specify.
- The code to show the names which work in `Facabaaka` company is
``` cs
var customerFullNames = customers.Where(p => String.Equals(p.Company, "Facabaaka"))
                                 .Select(cust => new
                                    {
                                        FirstName = cust.FirstName,
                                        LastName = cust.LastName
                                    });
foreach (var p in customerFullNames)
{
    Console.WriteLine($" > {p.FirstName} , {p.LastName}");
}
```
- The output is:

``` console
 > Lala , Papata
 > Lalo , Papota
```
###  3.3. <a name='Orderinggroupingandaggregatingdata'></a>Ordering, grouping and aggregating data

####  3.3.1. <a name='Ordering'></a>Ordering
- It specifies the order of the data returned by `Select`
- `OrderBy` expects a method as its argument
  - There are other methods such as:
    - `OrderByDescending`
    - `ThenBy` or `ThenByDescending`  which shall be used after `OrderBy` or `OrderByDescending`
- The following example, return the fullNames of the customers in alphabetical order by LastName.


``` cs
var customerFullNames = customers.OrderBy(x => x.LastName).Select(cust => new
{
    FirstName = cust.FirstName,
    LastName = cust.LastName
});
foreach (var p in customerFullNames)
{
    Console.WriteLine($" > {p.FirstName} , {p.LastName}");
}
```
- The output is:
``` console
 > Lala , Papata
 > Lalo , Papota
 > Lele , Pepete
 > Lelo , Pepote
 > Lila , Pipati
 > Lili , Pipiti
 > Lola , Popato
 > Lolo , Popoto
 > Lula , Pupatu
 > Lulu , Puputu
```

####  3.3.2. <a name='Grouping'></a>Grouping
- It groups data according to common values in one or more fields.
- `GroupBy` expects a method that specifies the fields by which to group the data.
  - The enumerable set returned by `GroupBy` contains all the fields in the original source collection.
    - **BUT** the rows are grouped by the field used in the method.
- The result of the method have many `summary methods`: such as `Key`, `Count()`, `Max`, `Min`
- In the example below:
  - The output is a set of `Companies` which are also collections of the `customers` which work in that `companies`
  
``` cs
var customerByCompany = customers.GroupBy(x => x.Company);

foreach (var customerPerCompany in customerByCompany)
{
    Console.WriteLine($" > {customerPerCompany.Key} : { customerPerCompany.Count()}");

    foreach (var customer in customerPerCompany)
    {
        Console.WriteLine($"\t> {customer.FirstName} , {customer.LastName}");
    }
}
```
- The output is:
``` console
 > Facabaaka
        > Lala , Papata
        > Lalo , Papota
 > Fecebeeke
        > Lele , Pepete
        > Lelo , Pepote
 > Ficibiiki
        > Lili , Pipiti
        > Lila , Pipati
 > Focobooko
        > Lolo , Popoto
        > Lola , Popato
 > Fucubuuku
        > Lulu , Puputu
        > Lula , Pupatu
```

####  3.3.3. <a name='Aggregating'></a>Aggregating
- The summary methods such as `Count`, `Max` and `Min` can be used directly over the results of the `Select` method.
- **BUT** summary methods do not distinguinsh duplicate values in the selected fields.
  - In the example, there are only 5 distinct Companies, but they are repeated twice so there are a total of 10.

``` cs
int numberOfCompanies = customers.Select(x => x.Company).Count();
Console.WriteLine($" > number of Companies: {numberOfCompanies}");
```
- The output is:
``` console
 > number of Companies: 10
```

- To select only distinct companies the `Distinct()` method shall be included before `Count()`, as showed below: 
 
``` cs
int numberOfDistinctCompanies = customers.Select(x => x.Company).Distinct(). Count();
Console.WriteLine($" > number of Distinct Companies: {numberOfDistinctCompanies}");
```
- The output is:
``` console
> number of Distinct Companies: 5
```
###  3.4. <a name='Joiningdata'></a>Joining data
- It joins together multiple sets of data over one or more common key fields.
- In this example it is showed how to display the `FirstName`, `LastName` (which belong to `Customer`) and `City` (which belong to `Addresses)
  - The Common key between `Customer` and `City` is `Company`.
- The `Select` method specifies the fields of interest in the `Custormers` array (`FirstName`, `LastName`) together with the common key `Company`.
  - Then use `Join` to join the data identified by the `Select` method with another enumerable collections.
- `Join(param1, param2, param3, param4)`
  - `param1`: The enumerable collection with which to join. e.g.,`addresses`
  - `param2`: The method that identifies the common key fields from the data identified by the `Select` method. e.g., `cust => cust.Company,`
  - `param3`: A method that identifies the common key fields on which to join the selected data. e.g., `addre => addre.Company`
  - `param4`: A method that specifies the columns you require in the enumerable result set returned by the `Join` method. e.g., `(cust,addre) => new { cust.FirstName, cust.LastName, addre.City}`

``` cs
var customerAndCity = customers.Select(c => new { c.FirstName, c.LastName, c.Company })
    .Join(
            addresses,
            cust => cust.Company,
            addre => addre.Company,
            (cust,addre) => new { cust.FirstName, cust.LastName, addre.City}
        );
```
- The output is:
``` console
 > { FirstName = Lala, LastName = Papata, City = Lama }
 > { FirstName = Lele, LastName = Pepete, City = Leme }
 > { FirstName = Lili, LastName = Pipiti, City = Limi }
 > { FirstName = Lolo, LastName = Popoto, City = Lomo }
 > { FirstName = Lulu, LastName = Puputu, City = Lumu }
 > { FirstName = Lalo, LastName = Papota, City = Lama }
 > { FirstName = Lelo, LastName = Pepote, City = Leme }
 > { FirstName = Lila, LastName = Pipati, City = Limi }
 > { FirstName = Lola, LastName = Popato, City = Lomo }
 > { FirstName = Lula, LastName = Pupatu, City = Lumu }
```
###  3.5. <a name='Usingqueryoperators'></a>Using query operators
- The code presented in the previous sections can be hard to understand and maintain. 
  - So, `C#` added `query operators`
- It is presented the examples from previous sections and its equivalent in `query operators`.

####  3.5.1. <a name='Examples'></a>Examples
- To retrieve the `firstName` for each `customer` 
``` cs
var customerFirstNames = customers.Select(customer => customer.FirstName);
// is Equivalent to
var customerFirstNames  = from c in customers
                          select c.FirstName;
```

- To retrieve the `firstName` and `lastName` for each `customer`
``` cs
var customerFullNames = customers.Select(cust => new
{
    FirstName = cust.FirstName,
    LastName = cust.LastName
});
// is Equivalent to
var customerFullNames = from c in customers
                        select new {c.FirstName, c.LastName};
```

- Filtering data, showing the customers which work in `Facabaaka` company

``` cs

var customerFullNames = customers.Where(p => String.Equals(p.Company, "Facabaaka"))
                                 .Select(cust => new
                                 {
                                     FirstName = cust.FirstName,
                                     LastName = cust.LastName
                                 });
// is Equivalent to
var customerFullNames = from c in customers
                        where String.Equals(c.Company, "Facabaaka")
                        select new {c.FirstName, c.LastName};
```

- Order by
``` cs
var customerFullNames = customers.OrderBy(x => x.LastName).Select(cust => new
                        {   
                            FirstName = cust.FirstName,
                            LastName = cust.LastName
                        });
// is Equivalent to
var customerFullNames = from c in customers
                        orderby c.LastName
                        select new { c.FirstName, c.LastName };
```

- Group by
``` cs
var customerByCompany = customers.GroupBy(x => x.Company);
// is Equivalent to
var customerByCompany = from c in customers
                        group c by c.Company;
```

- The `summary methods` can be used in the `query operators`:
- To return the number of Companies (total)
``` cs
int numberOfCompanies = (from c in customers
                         select c.Company).Count();
```
- To return the number of distinct Companies:
``` cs
int numberOfCompanies = (from c in customers
                         select c.Company).Distinct().Count();
```

###  3.6. <a name='LINQanddeferredevaluation'></a>LINQ and deferred evaluation

``` cs
asdf
```
- The output is:
``` console
asdf
```