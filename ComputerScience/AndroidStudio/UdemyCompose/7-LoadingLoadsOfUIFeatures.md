## V101 List 
A list to edit, add and delete.

``` kt
setContent {
    D7appTheme {
        Surface(
            modifier = Modifier.fillMaxSize(),
            color = MaterialTheme.colorScheme.background
            )
        {
            Column(
                modifier = Modifier.fillMaxSize(),
                verticalArrangement = Arrangement.Center
            )
            {
                Button(
                    onClick = { /*TODO*/ },
                    modifier = Modifier.align(Alignment.CenterHorizontally)
                    )
                {
                    Text(text = "Add Item")
        }
    }
}
```
## V102 - Lazy Column and Lazy Row


## V103 - Adding the Lazy Column 

``` kt
var sItems by remember { mutableStateOf(listOf<ShoppingItem>()) }

Column(
    modifier = Modifier.fillMaxSize(),
    verticalArrangement = Arrangement.Center
)
{
    Button(
        onClick = { /*TODO*/ },
        modifier = Modifier.align(Alignment.CenterHorizontally)
    )
    {
        Text(text = "Add Item")
    }
    LazyColumn(
        modifier = Modifier.fillMaxSize().padding(16.dp)
    )
    {
        items(sItems){
        }
    }
}
```

## V104 - Moving Composables to other file 
- O conteudo pode ser movido para outro arquivo e deixar dentro de una função `Composable`

``` kt
@Composable
fun ShoppingListApp()
{
    var sItems by remember { mutableStateOf(listOf<ShoppingItem>()) }

    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center
    )
    {
        Button(
            onClick = { /*TODO*/ },
            modifier = Modifier.align(Alignment.CenterHorizontally)
        )
        {
            Text(text = "Add Item")
        }

        LazyColumn(
            modifier = Modifier.fillMaxSize().padding(16.dp)
        )
        {
            items(sItems){

            }
        }

    }
}
```

## V105 Understanding and Setting Alert Dialog

- 
``` kt
@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun ShoppingListApp()
{
    var sItems by remember { mutableStateOf(listOf<ShoppingItem>()) }
    var showDialog by remember { mutableStateOf(false) } // variable para abrir o dialog

    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center
    )
    {
        Button(
            onClick =
            {
                showDialog = true // botao chama o dialog
            },
            modifier = Modifier.align(Alignment.CenterHorizontally)
        )
        {
            Text(text = "Add Item")
        }

        LazyColumn(
            modifier = Modifier
                .fillMaxSize()
                .padding(16.dp)
        )
        {
            items(sItems){

            }
        }

    }

    if(showDialog)
    {
        AlertDialog(
            onDismissRequest =
            {
                showDialog = false // dismiss fecha o dialogo
            }){
            Text(text = "LOBO") // content do dialog
        }
    }
}
```
## V107 Finishing AlertDialog

``` kt
AlertDialog(
            onDismissRequest =
            {
                showDialog = false
            },
            confirmButton =
            {
                Row(modifier = Modifier
                    .fillMaxWidth()
                    .padding(8.dp),
                    horizontalArrangement = Arrangement.SpaceBetween)
                {
                    Button(onClick =
                    {
                        if(itemName.isNotBlank()) //IMPORTANT to not save null objects
                        {
                            val newItem = ShoppingItem(id = sItems.size +1, name = itemName, quantity = itemQuantity.toInt())
                            sItems = sItems + newItem //easy to add elements to a list...
                            showDialog = false // 
                            itemName = "-" // to set to default the alert dialog content
                            itemQuantity = "0" // to set to default the alert dialog content
                        }
                    })
                    {
                        Text(text = "Add")
                    }
                    Button(onClick = { showDialog = false }) {
                        Text(text = "Cancel")
                    }
                }
            },
            title = { Text(text = "Add Shopping Item")},
            text = {
                Column {
                    OutlinedTextField(
                        value = itemName,
                        onValueChange = {itemName = it},
                        singleLine = true,
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(8.dp)
                    )
                    OutlinedTextField(
                        value = itemQuantity,
                        onValueChange = {itemQuantity = it},
                        singleLine = true,
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(8.dp)
                    )
                }
            }
        )
```

## V108 Setting up the LazyList
- To set a parameter as a lambda expression use the `() -> Unit` command. Example:
  - The `onClick` method in `Button` follows this rule.

``` kt
@Composable
fun ShoppingListItem(
    item: ShoppingItem,
    onEditClick: ()-> Unit,
    onDeleteClick: ()-> Unit
)
{
        Row(
        modifier = Modifier
            .padding(8.dp)
            .fillMaxWidth()
            .border(
                border = BorderStroke(2.dp, Color.Cyan),
                shape = RoundedCornerShape(20)
            )
    ){
        Text(text = item.name, modifier = Modifier.padding(8.dp))
    }    
}
```
- Por enquanto para que apareçam no LazyList

``` kt
LazyColumn(
    modifier = Modifier
        .fillMaxSize()
        .padding(16.dp)
)
{
    items(sItems){
        ShoppingListItem(it, {}, {})
    }
}
```
