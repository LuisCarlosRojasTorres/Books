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
