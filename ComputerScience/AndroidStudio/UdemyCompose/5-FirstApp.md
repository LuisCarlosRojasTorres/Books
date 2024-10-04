## V077 - Creating out own Composables

## V078 - OutlinedTextField and Anonymous Function

### Text
- OutlinedTextField:
  - `OutlinedTextField(value = "SomeText",  onValueChange = { //AnonymousFunction})``
    - `value`: o valor que aparece antes de ter um value aka `hint`
    - `onValueChange`: ação quando o value muda de valor

``` kt
@Composable
fun UnitConverter() {
    Column  {
        Text(text = "Dummy name 1 example")
        OutlinedTextField(value = "Enter value",  onValueChange = { })
        Row{
            
        }
    }
}
``` 
## V079 - Adding a Preview

``` kt
@Preview(showBackground = false)
@Composable
fun UnitConverterPreview() {
    UnitConverter()
}
```
## V080 - Button, onClick and Toast
- Context: em que area da aplicação "algo" vai acontecer.

``` kt
@Composable
fun UnitConverter() {
    Column  {
        Text(text = "Dummy name 1 example")
        OutlinedTextField(value = "Enter value",  onValueChange = { })
        Row{
            val context = LocalContext.current
            Button(onClick = { Toast.makeText(context, "Hola", Toast.LENGTH_LONG).show() }) {
                Text(text = "Click me")
            }
        }
    }
}
```

## V081 - Box, Icons and DropDownMenus
- Box: bota os composables um acima do outro. Ajuda na construção de layouts mais compleoxos.

``` kt
Box{
    Button(onClick = { }) {
        Text(text = "Click me")
        Icon(Icons.Default.ArrowDropDown, contentDescription = "Lobo")
    }
}
```
## V082 - Modifier, VerticalArrangement and HorizontalAlignment
Para centrar o elemento dentro da coluna se passa um `modifier`
- Arrangement: localização dos elementos na tela
- Alignment: orientação dos elementos dentro do elemento pai

``` kt
Column(
    modifier = Modifier.fillMaxWidth(),
    verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally)  {...}
```
## V083 - Spacer vs Padding
- Padding: Simple! (lack reusability). For fine control of specific elements...
- Spacer: Reusable! (more complex and verbose). For a general appearance...

``` kt
//
        Text(text = "Dummy name 1 example")
  
        Spacer(modifier = Modifier.height(16.dp)) //This adds the space between elements
  
        OutlinedTextField(value = "Enter value",  onValueChange = { })
  
```
## V084 - Adding DropdownMenus and DropDownMenuItems
- DropDownMenu:
  - `expanded`: false means closed by default
- DropDownItem:
  - `text`: ,

``` kt
DropdownMenu(expanded = false, onDismissRequest = { /*TODO*/ }) {
    DropdownMenuItem(text = { Text(text = "Lobo") }, onClick = { /*TODO*/ })
    DropdownMenuItem(text = { Text(text = "Rufa") }, onClick = { /*TODO*/ })
    DropdownMenuItem(text = { Text(text = "Rufo") }, onClick = { /*TODO*/ })
}
```

## V085 - Finish