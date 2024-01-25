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


##  4. <a name='V061BindingContext'></a>V061 BindingContext
##  5. <a name='V062Bindingentrecontroles'></a>V062 Binding entre controles
##  6. <a name='V063ModosenBinding'></a>V063 Modos en Binding
- `OneTime`: source to target at initialization
- `OneWay`: only source to target
- `TwoWay`: source to target and viceversa
##  7. <a name='V064INotifyPropertyChanged'></a>V064 INotifyPropertyChanged


