<!-- vscode-markdown-toc -->
* 1. [V058 Intro](#V058Intro)
* 2. [V059 Creando Primer Binding](#V059CreandoPrimerBinding)
* 3. [V060 Creando Bindings en XAML](#V060CreandoBindingsenXAML)
* 4. [V061 BindingContext](#V061BindingContext)
* 5. [V062 Binding entre controles](#V062Bindingentrecontroles)
* 6. [V063 Modos en Binding](#V063ModosenBinding)
* 7. [V064 INotifyPropertyChanged](#V064INotifyPropertyChanged)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V058Intro'></a>V058 Intro
- Permite "conectar" `bind` una:
  - Variable de algun objeto aka `source` con
  - Una propiedad (`bindable property`) de la interfaz gráfica. E.g. `Label.Text` 

##  2. <a name='V059CreandoPrimerBinding'></a>V059 Creando Primer Binding

1. Create a model class to instantiate an object to bind.
``` cs 
namespace DummySpace.Models;
class Person
{
	string Name {get; set;}
	int Age {get; set;}
}
```
2. Create a xaml object bind.
``` xml
<Label
	x:Name="txtName"
	FontSize="50"
	Text="DummyText"
	HorizontalOptions="Center"
	VerticalOptions="Center" />
```
3. Instantiate an object to bind 

``` cs
var person = new Person
{
	Name = "Rufo",
	Age = 18
};
```

4. Create a `Binding` object, setting its source (i.e. object to bind) and path (i.e. field of the object to bind)

``` cs 
Binding personBinding = new Binding();

personBinding.Source = person;
personBinding.Path = "Name";
```

5. Bind the xaml object to the binding object:
  
``` cs
txt.Name.SetBinding(Label.TextProperty, personBinding);
```

##  3. <a name='V060CreandoBindingsenXAML'></a>V060 Creando Bindings en XAML

1. Add the namespace where the model is located

``` xml
<ContentPage
...
xmlns:Models="clr-namespace:DummySpace.Models">
```
2. Create an static resouce (which is an instance of the model class) to bind:

``` xml
<ContentPage.Resources>
	<Models.Person 
		x:Key="person"
		Name="Rufa"
		Age=18/>
</ContentPage.Resources>
```

3. Bind the xaml object property
``` xml
<Label
	x:Name="txtName"
	FontSize="50"
	Text="{Binding Name, Source={StaticResource person}}"
	HorizontalOptions="Center"
	VerticalOptions="Center" />
```

##  4. <a name='V061BindingContext'></a>V061 BindingContext

- Una forma más practica de realizar binding es la siguiente (del ejemplo odel V058).

``` cs
var person = new Person
{
	Name = "Rufo",
	Age = 18
};

txtName.BindingContext = person;
txtName.SetBinding(Label.TextProperty, "Name");
```
- Se puede hacer lo mismo dentro de un contenedor. De esta forma todos los objetos xaml contenidos pueden acceder a los campos del objeto.
1. Set binding context in the `ContentPage`  code file:
``` cs
var person = new Person
{
	Name = "Rufo",
	Age = 18
};

BindingContext = person
```
2. Reference the fields of the object in the binding context. It is not necessary `x:Name` in the xaml objects
``` xml
<Label
	FontSize="50"
	Text="{Binding Name}"
	HorizontalOptions="Center"
	VerticalOptions="Center" />
<Label
	FontSize="50"
	Text="{Binding Age}"
	HorizontalOptions="Center"
	VerticalOptions="Center" />
```
##  5. <a name='V062Bindingentrecontroles'></a>V062 Binding entre controles
1. Create the object source:
``` xml
<Slider
	x:Name="slider"
	Maximum="360"
	Minimum="0"
/>
```

2. Bind the source object to another control, setting `Source` and `Path`

``` xml
<Label
	FontSize="50"
	Rotation="{Binding Source={x=Reference slider}, Path=Value}"
/>
```

##  6. <a name='V063ModosenBinding'></a>V063 Modos en Binding
- `OneTime`: source to target at initialization
- `OneWay`: only source to target
- `TwoWay`: source to target and viceversa
##  7. <a name='V064INotifyPropertyChanged'></a>V064 INotifyPropertyChanged


