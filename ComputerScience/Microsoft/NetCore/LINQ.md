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
	* 3.6. [Quering data in `Tree<TItem>` Objects](#QueringdatainTreeTItemObjects)
	* 3.7. [LINQ and deferred evaluation](#LINQanddeferredevaluation)

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

####  3.3.3. <a name='Aggregating'></a>Aggregating
###  3.4. <a name='Joiningdata'></a>Joining data

``` cs
asdf
```
- The output is:
``` console
asdf
```
###  3.5. <a name='Usingqueryoperators'></a>Using query operators

``` cs
asdf
```
- The output is:
``` console
asdf
```
###  3.6. <a name='QueringdatainTreeTItemObjects'></a>Quering data in `Tree<TItem>` Objects

``` cs
asdf
```
- The output is:
``` console
asdf
```
###  3.7. <a name='LINQanddeferredevaluation'></a>LINQ and deferred evaluation

``` cs
asdf
```
- The output is:
``` console
asdf
```