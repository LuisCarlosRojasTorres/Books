
## Definición
- `App.xaml` aqui se especiica cual es el archivo de pagina inicial.
- `AppShell.xaml`
- `MainPage.xaml`

- En general una pagina tiene `espacion de nombres` i.e. `xmlns` , `xmlns:x` y `x:Class` en el siguiente ejemplo.
```
<?xml version="1.0" encoding="utf-8" ?>
<ContentPage xmlns="http://schemas.microsoft.com/dotnet/2021/maui"
             xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"
             x:Class="MauiApp1.MainPage">
```

- `xmlns="http://schemas.microsoft.com/dotnet/2021/maui` define el `espacion de nombres` de maui
- `xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"` define el identificador `x:`
- 
## Estructura Básica

```
<DummyName
    PropertyAttribute1="123"
    PropertyAttribute2="dummystring"
    ...
    />
```

Otra forma, muy utilizada para elementos más complejos es:

```
<DummyName
    PropertyAttribute1="123">
    <DummyName.PropertyAttribute2>
        "dummystring"
    </DummyName.PropertyAttribute2>    
</DummyName>
```

- A mayor identación menoe jerarquia en las etiquetas.