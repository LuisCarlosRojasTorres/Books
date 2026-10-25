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
## V037
## V038
## V039
## V040
## V041
## V042
## V043
## V044
## V045
## V046
## V047
## V048
## V049
## V050



