
## V064 Criando formulários
- tag `form` para formulários
- As labels dos inputs contém o atributo `htmlFor` que deve ter o valor do name do input.
- NÃO se utiliza action, ate pq o processo vai ser feito de forma assincrona.

``` jsx
// Filename: MyForm.jsx
const MyForm = () => {
  return (
    <div>
        <form>
            <div>
                <label htmlFor="name">Name:</label>
                <input type="text" name="name" placeholder="Digite o seu Nome"/>
            </div>            
            <button type="submit">Submit</button>
        </form>
    </div>
  )
}

export default MyForm

// Filename: MyForm.css
form {
    width: 300px;
    margin: 0 auto;
    text-align: left;
}

input,
textarea,
select {
    display: block;
    margin-top: 10px;
}
```

## V065 Label envolvendo input

## V066 Gerenciamento de dados de input

## V067 Alteração de state inline

## V068 Envio de form

## V069 Controlled inputs

## V070 Resetando formulários

## V071 Textarea no React

## V072 Select no React