## 1 - Starter Tutorial
- how to build a simple UI component with declarative functions. 
- Understand:
  - composable functions, 
  - basic layouts, and 
  - how Material Design, lists and animations work in Compose.

## 2 - Thinking in Compose
- UI can entirely be described in code in Kotlin
- Construct UI by describing WHAT not HOW
- In Compose UI elements are functions and not objects.
- UI elements are controlled by the state or arguments that you pass.

## 3 - Composable functions

### Intro
- Compose: Describe the UI as functions. No more xml.
- `@Composable` tells the Compiler that this functions it converts to UI. Functions with that are called `Composables`
  - It lets convert your UI into a library of reusable elements
  - This function doesnot return anything but emits UI

``` kt
@Composable
fun SurveyAnswer(answer: Answer){
  Row{
    Image(answer.image)
    Text(answer.text)
    RadioButton(false, onClick = {/* ... */})
  }
}

@Composable
fun SingleChoiceQuestion(answers: List<Answer>){
  Column{
    answers.forEach {
      answer -> SurveyAnswer(answer = answer)
    }
  }
}
```

- Composables are also INMUTABLE. You cant hold a reference to them.
  - You need to pass any and all information AS PARAMETERS when you called.
``` kt
@Composable
fun SingleChoiceQuestion(answers: List<Answer>){
  Column{
    answers.forEach {
      answer -> 
      val refe = SurveyAnswer(answer = answer) //IMPOSIBLE!!!
    }
  }
}
```
- TO conditionally display something, only use a CONDITIONAL (because is KOTLIN)
``` kt
@Composable
fun SingleChoiceQuestion(answers: List<Answer>){
  Column{
    if(answers.isEmpty()){ //Conditional
      Text("It is empty")      
    }
    else{
      answers.forEach {
        answer -> SurveyAnswer(answer = answer)
      }
    }
  }
}
```

- Composables shouldt modify properties or global variables. 
- Composables shall emit the same UI for the same input all the time. a.k.a Idempotent.
- The arguments entirely control the UI, the logic in the UI guanrantee that the UI can never get out of sync.
  - If the **argument changes, new UI is generated** by executing the function again (with the new parameters) and redrawing. This is called `recomposition`

### Recomposition

### Behavior

- `Mutable state`:
  - A variable that holds the a value, a when this variable changes tell to compose to perform `recomposition`
  - An observable variable integrted to Compose runtime
  - Any change will `recompose` the scene
  - Template `var dummy : MutableState<Answer?> = mutableStateOf(null)`

## 4 - Write your first Compose app

## 5 - The Compose UI toolkit

## 6 - Implement a real-world design

## 7 - Get started with state

## 8 - Accelerate with tooling
 
## 9 - Migrate from the View system

## 10 - Hands-on migration