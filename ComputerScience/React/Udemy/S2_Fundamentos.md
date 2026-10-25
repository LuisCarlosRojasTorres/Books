
## V024 Criando componentes
- Nos projetos os componentes ficam na pasta `components` (nossa... serio?)
- São nomeados com camelcase: `ExemploDummy.js`
- No arquivo é criado uma função que contém o código deste componente.
- A função precisa **ser exportada** para ser reutilizada.

- Podemos editar o `App.jsx`
``` js
import './App.css'

function App() {

  return (
    <div className="app-container">
      <h1>Welcome to S2 Fundamentos</h1>
      <p>Este é um parágrafo de teste.</p>
    </div>
  )
}

export default App
```

Para criar componentes:
- Dentro de `src` criar nova pasta `components`
- Criar novo arquivo `NewComponent.jsx`

``` js 
const FirstComponent = () => {
    // Aqui podemos adicionar lógica do componente, se necessário
  return (
    <div>
      <h2>Primeiro Componente</h2>
    </div>
  )
}

// Exportamos o componente para ser utilizado em outros arquivos
export default FirstComponent
```

## V025 Importando components
- Para reutilizar um componente importamos ele.
- Sintaxis: `import X from './<path-to-file>'`
- Para colocar o componente utilizamos: `<FirstComponent/>`

``` js
import FirstComponent from "./components/NewComponent"
import './App.css'

function App() {

  return (
    <div className="app-container">
      <h1>Welcome to S2 Fundamentos</h1>
      <p>Este é um parágrafo de teste.</p>
      <FirstComponent />
    </div>
  )
}

export default App
```
## V026 Conhecendo o JSX
- JSX é o HTML do React
  - Tem uma diferença: `class` agora é `className`
- Tudo o que estiver dentro do `return( here )` é JSX
- Pode ter apenas um elemento pai.
- Sempre tem que estar dentro de um `<div></div>`
## V027 Comentarios
- `//` Comentario dentro da função
- Dentro do JSX `{/* Dummy Comment*/}`
  - As chaves permitem executar javascript dentro do JSX

``` js
import FirstComponent from "./components/NewComponent"
import './App.css'

function App() {
  // Comentario para o componente App
  return (
    <div className="app-container">
      <h1>Welcome to S2 Fundamentos</h1>
      <p>Este é um parágrafo de teste.</p>
      {/** Aqui podemos adicionar comentários dentro do JSX */}
      <FirstComponent />
    </div>
  )
}

export default App
```
## V028 Template expressions
- É o recurso que permite executar JS no JSX e também interpolar variáveis.
- Sintaxis: `{ some code here }`
  - Tudo o que fica entre chaves é executado como javascript

1. Criamos o novo arquivo `TemplateExpressions.jsx`
2. Chamamos no `App.jsx`
``` js
// File: TemplateExpressions.jsx
const TemplateExpressions = () => {
  const name = "DummyName";
  const data = { age: 25, city: "DummyCity" };

  // Variaveis
  // Variaveis de um map
  // ainda um console.log para inspect
  return (
    <div>
      <h2>Template Expressions</h2>
      <p>Olá, {name}!</p>
      <p>Idade: {data.age}</p>
      <p>Cidade: {data.city}</p>
      <p> {console.log("Log: Rendering TemplateExpressions component")}</p>
    </div>
  )
}

export default TemplateExpressions;
```

``` js
// File: App.jsx
import FirstComponent from "./components/NewComponent"
import TemplateExpressions from "./components/TemplateExpressions"
import './App.css'


function App() {
  // Comentario para o componente App
  return (
    <div className="app-container">
      <h1>Welcome to S2 Fundamentos</h1>
      <p>Este é um parágrafo de teste.</p>
      {/** Aqui podemos adicionar comentários dentro do JSX */}
      <FirstComponent />
      <TemplateExpressions />
    </div>
  )
}

export default App
```
## V029 Hierarquia de Componentes
- Os componentes que criamos podem ser chamados em outros componentes.
- Chamando um componente dentro de outro se cria uma jerarquia.
  - App é um componente que chamou o componente `FirstComponent` e `TemplateExpressions`
- Podemos criar o componente `ReusedComponent` e chamar ele em `FirstComponent`, `TemplateExpressions` e `App`

## V030 Eventos
- Eventos são essenciais no `frontend`
  - O evento de `click` é muito utilizado 
- No React tem lib pra isso, a função `onClick`
  - As funções tem a sintaxis: `handleSomething`

- Ao criar o arquivo `EventoClick.jsx` e chamar no `App.jsx`, temos um evento pronto para ser chamado.

``` js
// File: EventoClick.jsx
const EventoClick = () => {
  const handleClick = (e) => {
    console.log(e)
    console.log("Botão clicado!");
  }

  return (
    <div>
      <h2>Eventos</h2>
      <button onClick={handleClick}>Clique aqui</button>
    </div>
  )
}

export default EventoClick;
```

## V031 Funções nos eventos
- A função pode estar dentro do proprio evento.
  - Apenas para coisas simples

``` js
// Referencia a função
<button onClick={handleClick}>Clique aqui</button>

// Função implementada dentro do evento
<button onClick={() => console.log("Função no evento")}>Clique funcao no evento</button>
```
## V032



