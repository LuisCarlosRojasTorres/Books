## Fundamentos

## Machine Learning com Spark

## Preparando Dados para Regressao

## Criando um modelo de Regressao
``` python
#Primeiro modelo a criar Linear Regression
reglin = LinearRegression(featuresCol="Caracteristicas", labelCol="HP")
modelo = reglin.fit(CarrosTreino)

# Agora nao eh preciso mais nem dados soh o modelo
# PAra fazer uma previsao se faz o seginte
previsao = modelo.transform(CarrosTeste)
# Para mostrar os valores com a prediction utilizamos show.

previsao.show(5)

# Metrica de Performance para ver se o modelo foi bom
avaliar = RegressionEvaluator(predictionCol="prediction",labelCol="HP",metricName="rmse")
rmse = avaliar.evaluate(previsao)
print(rmse) # Deu 39.5457

# A metrica ficou meia ruim entao vamos criar outro modelo
rfreg = RandomForestRegressor(featuresCol="Caracteristicas", labelCol="HP")
modelo2 = reglin.fit(CarrosTreino)
modelo2 = reglin.fit(CarrosTreino)
previsao2 = modelo2.transform(CarrosTeste)

## Gerando a metrica da segunda previsao
rmse = avaliar.evaluate(previsao2) # Deu 32.91

## Enquanto menor o rmse, melhor!
```
## Preparando Dados Para Classificacao

## Criando um Modelo de Classificacao

## Pipelines

## MiniProjeto
