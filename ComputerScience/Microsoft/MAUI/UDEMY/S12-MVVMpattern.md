



## V076 Introduccion
- Model: 
  - Representan el mundo real. 
  - Encapsulan los datos de la applicacion.
  - E.g. clase `Persona`
- View:
  - Vistas, creadas con codido xaml
- ViewModel
  - Evitan mesclar la logica de programacion con interfaz grafica.
- La comunicacion entre elementos es de la siguiente forma:

![Alt text](image-48.png)

## V077 Creando primer View Model
1. Crear las carpetas `Views`, `Models` and `ViewModels`
2. Para el Model `Dummy.cs`: 
   1. se debe crear una pagina xaml `DummyView.xaml` 
   2. y una clase `DummyViewModel.cs`
3. No `ViewModel`:
   1. Instancia objeto a partir de las classes definidas en models.
   2. Crear getter para el objeto instanciado.
4. No `View CS`
   1. CS: Se implementa en su constructor una instancia del `ViewModel`:
      - `BindingContext = new DummyViewModel();`
5. No `View xaml`
   1. Assignar la propiedad del objeto instanciado por el `ViewModel` al control XAML deseado.
      - `<Label Text="{Binding Dummy.Property}">` 


## V078 Creando bindings a diferentes controles desde un mismo viewmodel
- Al realizar los pasos del video anterior todo campo del objeto instanciado en el `viewmodel``, esta disponible en el `View`.

- Por tanto, cualquier control en el `View` puede acceder a cualquier campo del objeto `Dummy`.

## V079 Bindings de collecction a control de tipo collection
- En `ViewModel`
  - Getter de una collection e.g. `DummyCol`
  - Intanciar la collection en el contructor
- En `View.cs`
  - Bind a una instancia del ViewModel: `BindingContext = new DummyViewModel()`
- En `View.xaml`
  - Setar ItemSource en el ColletionView:

``` xml
<CollectionView ItemsSource="{Binding Dummy}" SelectionMode="Multiple">
        <CollectionView.ItemTemplate>
            <DataTemplate>
                <StackLayout>
                    <Frame
                        Margin="20"
                        BorderColor="DarkGray"
                        CornerRadius="5"
                        HasShadow="True"
                        HeightRequest="100"
                        HorizontalOptions="Center"
                        VerticalOptions="CenterAndExpand">
                        <Label Text="{Binding .}" />
                    </Frame>
                </StackLayout>
            </DataTemplate>
        </CollectionView.ItemTemplate>
    </CollectionView>
```
- Si lo que se quiere es listar una collecion de objetos se tiene que especificar que campo debe ser mostrado eso en el `<Label Test="Binding DummyCollectionProperty">`

``` xml
<CollectionView ItemsSource="{Binding DummyCollection}" SelectionMode="Multiple">
        <CollectionView.ItemTemplate>
            <DataTemplate>
                <StackLayout>
                    <Frame
                        Margin="20"
                        BorderColor="DarkGray"
                        CornerRadius="5"
                        HasShadow="True"
                        HeightRequest="100"
                        HorizontalOptions="Center"
                        VerticalOptions="CenterAndExpand">
                        <Label Text="{Binding DummyCollectionProperty}" />
                    </Frame>
                </StackLayout>
            </DataTemplate>
        </CollectionView.ItemTemplate>
    </CollectionView>
```
## V080 Value Converter 

## V081 Value Converter Back 

## V082 Commands

## V083 Commands with parameters

## V084 Implementando INotify