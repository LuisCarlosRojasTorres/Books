## V035 Imagenes publicas no React

- Ficam na pasta `public`
- Tag `img` e com o `/path.jpg`  

``` jsx
function App() {  
  return (
    <div>
      <h1>S3 More content!</h1>
      <img src="/totodile.png" alt="Placeholder" />
    </div>
  )
}

export default App
```

## V036 Imagens no src
- Pasta public pode ser utilizada para armazenar imagens.
- Mas um boa prática é armazenar na pasta `assets` dentro do `src`
  - Utilizando `assets` precisamos importar as imagens. O `src` é dinamico com o nome da importação.

``` jsx
import "./App.css"
import Hero from "./assets/Hero.png"
function App() {
  

  return (
    <div>
      <h1>S3 More content!</h1>
      {/* Local image from public folder */}
      <img src="/totodile.png" alt="Placeholder" />
      {/* Imported image from assets */}
      <img src={Hero} alt="Placeholder" />
    </div>
  )
}

export default App
```
## V037 Hooks
- São recursos do react para realizar diversas funções
  - Salvar e alterar estado de algum dado na applicação.
- Sintaxis: `useSomething` e.g. `useState`
- Podem ser feitos custom hook, ou seja implementados pela gente.
- precisam ser importados.
- Muito úteis

## V038 useState hook
- Dos mais utilizados
- Serve para gerenciar o estado de algum dato. (Se a variavel nao funciona corretamente, o componente nao é re-renderiza)
- Como utilizar?
  - Para guardar o dado definimos o nome da variável 
  - para alterar utilizamos `setName` 

``` jsx
import { useState } from "react";

const ManageData = () => {
    let someValue = 73;

    const [anotherValue, setAnotherValue] = useState(0);

  return (
    <div>
        <div>
            Manage Data Component
            <p>Value {someValue}</p>
            {/* Button to change the value of someValue */}
            {/* This will not actually update the displayed value because React does not track changes to regular variables. */}
            <button onClick={() => (someValue = 100)}> Change Value </button>      
        </div>
      
        <div>
            Manage Data Component
            <p>Value {anotherValue}</p>
            {/* Button to change the value of anotherValue */}
            {/* This will update the displayed value because React tracks changes to state variables. */}
            <button onClick={() => setAnotherValue(100)}>Change Value</button>
        </div>
    </div>
  );
};

export default ManageData;
```
- O primeiro botão nao faz nada. Nao atualiza o valor.
- O segundo sim.

## V039 Renderização de listas
- Renderizar listas de dados no template
- Utiliza dados do tipo array
- Muito util é o `map`
- Logicamente vai ter iteração para mostrar os dados.

### Index dummy

``` js
const ListRender = () => {
    const items = ["Item 1", "Item 2", "Item 3"];
  return (
    <div>
        <div>
            <h2>ListRender</h2>
            <ul>
                {items.map((item, index) => (
                <li key={index}>{item}</li>
                ))}
            </ul>
        </div>
    </div>
  )
}

export default ListRender
```
## V040 A propriedade Key
- Iterar uma lista sem a `key` gera um warning.
- React exige uma chave unica para cada um dos itens iterados.
  - Geralmente como temos um array podemos utilizar o index,
  - porém é melhor utilizar um `id`.

``` js 
import { useState } from "react"

const ListRender = () => {
    const items = ["Item 1", "Item 2", "Item 3"];

    const [users] = useState([
        { id: 111, name: "User 1", age: 25 },
        { id: 222, name: "User 2", age: 30 },
        { id: 333, name: "User 3", age: 35 }
    ])
  return (
    <div>
        <div>
            <h2>ListRender</h2>
            <ul>
                {items.map((item, index) => (
                <li key={index}>{item}</li>
                ))}
            </ul>
        </div>
        <div>
            <h2>ListRender</h2>
            <ul>
                {users.map((user) => (
                <li key={user.id}>{user.name} - {user.age} years old</li>
                ))}
            </ul>
        </div>
    </div>
  )
}

export default ListRender
```
## V041 Previous state
- Permite pegar o dado em seu valor original dentro de um set de dado.
- Utilizado para modificar listas,
- O primeiro argumento de um set sempre será o previous state.
- `prevUser` na verdade é o estado atual, porém ao chamar na função passa a ser o previo.

``` jsx
import { useState } from "react"

const PrevStateExample = () => {    

    const [users, setUsers] = useState([
        { id: 1, name: "User 1", age: 25 },
        { id: 2, name: "User 2", age: 30 },
        { id: 3, name: "User 3", age: 35 }
    ])

    const deleteRandom = () => {
        const randomIndex = Math.floor(Math.random() * (users.length +1) );
        
        setUsers((prevUsers) => {
            console.log(prevUsers)
            return prevUsers.filter((user) =>  randomIndex !== user.id);
        });
    }
  return (
    <div>        
        <div>
            <h2>PrevStateExample</h2>
            <ul>
                {users.map((user) => (
                <li key={user.id}>{user.name} - {user.age} years old</li>
                ))}
            </ul>
            <button onClick={deleteRandom}>Delete Random User</button>
        </div>
    </div>
  )
}

export default PrevStateExample
```
## V042 Renderização Conditional
- Dada uma condição, se imprimi um UI diferente.
  - Logicamente isso quer fizer `if`
- Isso é importantepara autenticação de usuário.

``` jsx

import { useState } from "react";

const ConditionalRender = () => {
    
    const [value, setValue] = useState(false);

  return (
    <div>
        <div>
            Conditional Render Component
            <p>Value {value.toString()}</p>          
            {/* Conditional rendering example */}
            <button onClick={() => setValue(!value)}> Change Value </button>      
            {value && <p>The value is true!</p>}
            {!value && <p>The value is false!</p>}
        </div>      
        
    </div>
  );
};

export default ConditionalRender;
```
## V043
## V044
## V045
## V046
## V047
## V048
## V049
## V050



