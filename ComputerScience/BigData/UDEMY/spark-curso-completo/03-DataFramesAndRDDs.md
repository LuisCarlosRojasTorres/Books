<!-- vscode-markdown-toc -->
* 1. [RDD DATASET and DATAFRAME](#RDDDATASETandDATAFRAME)
* 2. [RDD parte1](#RDDparte1)
* 3. [RDD parte2](#RDDparte2)
* 4. [DataFrame parte1](#DataFrameparte1)
* 5. [DataFrame parte2](#DataFrameparte2)
* 6. [DataFrame parte3](#DataFrameparte3)
* 7. [DataFrame parte4](#DataFrameparte4)
* 8. [Principais Acoes e Transformacoes](#PrincipaisAcoeseTransformacoes)
* 9. [Exportando dados](#Exportandodados)
* 10. [Importando dados](#Importandodados)
* 11. [Atividades: Faca vc mesmo](#Atividades:Facavcmesmo)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->


##  1. <a name='RDDDATASETandDATAFRAME'></a>RDD DATASET and DATAFRAME

- RDD: Resilient Distributed Datasets
  - Basico de baixo nivel
  - Dados distribuidos pelo cluster
  - Em memoria
  - Tolerante a falha
  - Imutavel: transformacoes no RDD gera outro RDD
- DATASET e DATAFRAME: 
  - Semelhantes a uma tabela de banco de dados
  - Compativel com objetos DATAFRAME do R e do PYTHON(Pandas)
- DATASET (disponivel para JAVA e SCALA)

##  2. <a name='RDDparte1'></a>RDD parte1
```
$pyspark

#Criar RDD, sc eh o contexto do spark, e #utilizando o metodo parallelize inserir uma #lista de numeros
>>> numeros = sc.parallelize([1,2,3,4,5,6,7,8,9,10])
# Agora da pra fazer transformacoes no RDD
>>> numero.take(5) // retorna as primeiras 5 entradas
>>> numero.count() //retorna o num de elementos na lista
>>> numero.mean()
>>> numero.max()
#Da pra aplicar filtros
>>> filtro = numeros.filter(lambda filtro: filtro> 2)
>>> filtro.collect()
[3,4,5,6,7,8,9,10]
```
- `.collect` apresenta os resultados
- `.union` eh uniao de conjuntos
- `.substract` eh diferenca de conjuntos
- `.cartesian` produto cartesiano os pares de dois conjuntos.


##  3. <a name='RDDparte2'></a>RDD parte2

##  4. <a name='DataFrameparte1'></a>DataFrame parte1

##  5. <a name='DataFrameparte2'></a>DataFrame parte2

##  6. <a name='DataFrameparte3'></a>DataFrame parte3

##  7. <a name='DataFrameparte4'></a>DataFrame parte4

##  8. <a name='PrincipaisAcoeseTransformacoes'></a>Principais Acoes e Transformacoes

##  9. <a name='Exportandodados'></a>Exportando dados

##  10. <a name='Importandodados'></a>Importando dados

##  11. <a name='Atividades:Facavcmesmo'></a>Atividades: Faca vc mesmo
