<!-- vscode-markdown-toc -->
* 1. [V016. Introducción](#V016.Introduccin)
* 2. [V017. StackLayout](#V017.StackLayout)
* 3. [V018. Github repo](#V018.Githubrepo)
* 4. [V019. HorizontalStackLayout y VerticalStackLayout](#V019.HorizontalStackLayoutyVerticalStackLayout)
* 5. [V021. Grid](#V021.Grid)
* 6. [V023. AbsoluteLayout](#V023.AbsoluteLayout)
* 7. [V024. Github repo](#V024.Githubrepo)
* 8. [V025. FlexLayout](#V025.FlexLayout)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->



##  1. <a name='V016.Introduccin'></a>V016. Introducción

![Alt text](image-10.png)

##  2. <a name='V017.StackLayout'></a>V017. StackLayout
1. Crear una nueva `ContentPage` e.g. `StackPageExample`
3. Eliminar el contenido de `StackPageExample.xaml`.  
   1. Adicionar el codigo que se encuentra abajo. O layout tiene atributos como `VerticalOptions` e `Spacing`
4. adicionar su constructor en `App.xaml.cs`
   - `MainPage = new StackPageExample();`
5. Finalmente tenemos la aplicacion
![Alt text](image-9.png)

``` xml
    <StackLayout VerticalOptions="Center" Spacing="10">
        <Label 
            Text="Dummy1!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
        <Label 
            Text="Dummy2!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
        <Label 
            Text="Dummy3!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
    </StackLayout>
```

- Resultado
![Alt text](image-11.png)
##  4. <a name='V019.HorizontalStackLayoutyVerticalStackLayout'></a>V019. HorizontalStackLayout y VerticalStackLayout

### Horizontal Stack Layout
- An special case of the `StackLayout`
- The only difference is the xaml code

``` xml
    <HorizontalStackLayout HorizontalOptions="Center" VerticalOptions="Center" Spacing="10">
        <Label 
            Text="Dummy1!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
        <Label 
            Text="Dummy2!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
        <Label 
            Text="Dummy3!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
    </HorizontalStackLayout>
```

![Alt text](image-12.png)
### Vertical Stack Layout

- An special case of the `StackLayout`
- The only difference is the xaml code

``` xml
    <VerticalStackLayout HorizontalOptions="Center" VerticalOptions="Center" Spacing="10">
        <Label 
            Text="Dummy1!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
        <Label 
            Text="Dummy2!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
        <Label 
            Text="Dummy3!"
            VerticalOptions="Center" 
            HorizontalOptions="Center" />
    </VerticalStackLayout>
``` 
![Alt text](image-13.png)


##  5. <a name='V021.Grid'></a>V021. Grid

##  6. <a name='V023.AbsoluteLayout'></a>V023. AbsoluteLayout

##  7. <a name='V024.Githubrepo'></a>V024. Github repo

##  8. <a name='V025.FlexLayout'></a>V025. FlexLayout

