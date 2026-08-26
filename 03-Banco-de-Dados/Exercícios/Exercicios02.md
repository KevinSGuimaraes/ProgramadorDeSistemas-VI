# Atividade Prática — SELECT no PostgreSQL

**Tema:** Consultas SQL com `SELECT`  
**Banco de dados:** PostgreSQL  
**Nível:** Básico ao intermediário  
**Conteúdo:** `SELECT`, `FROM`, `WHERE`, operadores de comparação, `AND`, `OR`, `NOT`, `BETWEEN`, `IN`, `LIKE`, `ILIKE`, `DISTINCT`, `ORDER BY`, `LIMIT`, `OFFSET`, funções de agregação, `GROUP BY` e `HAVING`.

> **Importante:** Nesta atividade **não serão utilizados JOINs**.

---

# 1. Preparação do banco de dados

## 1.1 Criação da tabela

Crie a tabela `alunos` utilizando o comando abaixo:

```sql
CREATE TABLE alunos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100),
    idade INT,
    cidade VARCHAR(50),
    curso VARCHAR(50),
    nota NUMERIC(4,2)
);
```

## 1.2 Inserção dos dados

Execute o comando abaixo para inserir os dados na tabela:

```sql
INSERT INTO alunos (nome, idade, cidade, curso, nota) VALUES
('Ana Silva', 18, 'Curitiba', 'Programação', 8.5),
('Bruno Santos', 21, 'Londrina', 'Redes', 7.0),
('Carlos Souza', 19, 'Curitiba', 'Programação', 9.0),
('Daniel Oliveira', 25, 'Maringá', 'Banco de Dados', 6.5),
('Eduarda Lima', 20, 'Curitiba', 'Redes', 8.0),
('Felipe Costa', 17, 'Londrina', 'Programação', 5.5),
('Gabriela Alves', 22, 'Maringá', 'Banco de Dados', 9.5),
('Henrique Rocha', 19, 'Curitiba', 'Redes', 7.5),
('Isabela Martins', 20, 'Londrina', 'Programação', 8.8),
('João Pereira', 23, 'Curitiba', 'Banco de Dados', 6.0),
('Karen Mendes', 18, 'Maringá', 'Programação', 9.2),
('Lucas Ferreira', 26, 'Curitiba', 'Redes', 7.8);
```

---

# Parte 1 — SELECT básico

## Questão 1 — SELECT *

Mostre **todos os registros** da tabela `alunos`.

---

## Questão 2 — Selecionando colunas

Mostre somente as seguintes informações:

- nome
- idade
- curso

---

## Questão 3 — Selecionando outras colunas

Mostre somente:

- nome
- cidade

---

## Questão 4 — Utilizando expressões e AS

Mostre o nome dos alunos e a idade deles **acrescida de 1 ano**.

Utilize `AS` para chamar a nova coluna de `idade_futura`.

---

# Parte 2 — WHERE

## Questão 5 — Maior ou igual

Mostre todos os alunos que possuem **18 anos ou mais**.

Utilize o operador de comparação adequado.

---

## Questão 6 — Igualdade

Mostre todos os alunos que moram em **Curitiba**.

---

## Questão 7 — Maior que

Mostre todos os alunos que possuem nota **maior que 8**.

---

## Questão 8 — Diferente

Mostre todos os alunos que **não moram em Curitiba**.

Utilize um operador de diferença ou `NOT`.

---

# Parte 3 — AND e OR

## Questão 9 — Utilizando AND

Mostre os alunos que atendem **às duas condições**:

- possuem 18 anos ou mais;
- fazem o curso de Programação.

Utilize `AND`.

---

## Questão 10 — Utilizando OR

Mostre os alunos que moram em:

- Curitiba; **ou**
- Londrina.

Utilize `OR`.

---

## Questão 11 — AND com duas condições

Mostre os alunos que:

- possuem nota maior ou igual a 8;
- **e** moram em Curitiba.

---

# Parte 4 — BETWEEN

## Questão 12 — Intervalo de idade

Mostre os alunos cuja idade esteja entre **18 e 20 anos**.

Utilize `BETWEEN`.

---

## Questão 13 — Intervalo de notas

Mostre os alunos cuja nota esteja entre **7 e 9**.

Utilize `BETWEEN`.

---

# Parte 5 — IN

## Questão 14 — IN com cursos

Mostre os alunos que fazem um dos seguintes cursos:

- Programação
- Redes

Utilize `IN`.

---

## Questão 15 — IN com cidades

Mostre os alunos que moram em uma das seguintes cidades:

- Curitiba
- Londrina
- Maringá

Utilize `IN`.

---

# Parte 6 — LIKE e ILIKE

## Questão 16 — Nomes começando com A

Mostre os alunos cujo nome **começa com a letra A**.

Utilize `LIKE`.

---

## Questão 17 — Nomes terminando com A

Mostre os alunos cujo nome **termina com a letra "a"**.

Utilize `LIKE`.

---

## Questão 18 — Nome contendo uma sequência

Mostre os alunos cujo nome contém a sequência:

```text
ana
```

Utilize `ILIKE`.

---

## Questão 19 — ILIKE

Mostre os alunos cujo nome começa com a letra **C**, independentemente de estar escrita em letras maiúsculas ou minúsculas.

Utilize `ILIKE`.

---

# Parte 7 — DISTINCT

## Questão 20 — Cidades sem repetição

Mostre todas as cidades cadastradas na tabela `alunos`, mas **sem repetir nenhuma cidade**.

Utilize `DISTINCT`.

---

## Questão 21 — Cursos sem repetição

Mostre todos os cursos cadastrados, mas **sem repetir os cursos**.

Utilize `DISTINCT`.

---

# Parte 8 — ORDER BY

## Questão 22 — Ordem alfabética

Mostre todos os alunos ordenados pelo **nome em ordem crescente**.

Utilize `ORDER BY`.

---

## Questão 23 — Maior nota primeiro

Mostre todos os alunos ordenados pela nota da **maior para a menor**.

Utilize `ORDER BY` e `DESC`.

---

## Questão 24 — Menor idade primeiro

Mostre todos os alunos ordenados pela idade da **menor para a maior**.

Utilize `ORDER BY` e `ASC`.

---

## Questão 25 — Ordenação por múltiplas colunas

Ordene os alunos:

1. primeiro pela **cidade** em ordem crescente;
2. depois, dentro de cada cidade, pelo **nome** em ordem crescente.

Utilize duas colunas no `ORDER BY`.

---

# Parte 9 — LIMIT e OFFSET

## Questão 26 — LIMIT

Mostre somente os **5 primeiros alunos** cadastrados.

Utilize `LIMIT`.

---

## Questão 27 — Três maiores notas

Mostre os **3 alunos com as maiores notas**.

Utilize:

- `ORDER BY`;
- `DESC`;
- `LIMIT`.

---

## Questão 28 — OFFSET

Mostre os alunos ordenados pela nota da **maior para a menor**.

Porém:

- pule os 3 primeiros alunos;
- mostre os próximos 3 alunos.

Utilize `ORDER BY`, `LIMIT` e `OFFSET`.

---

# Parte 10 — Funções de agregação

## Questão 29 — COUNT

Conte quantos alunos existem na tabela `alunos`.

Utilize `COUNT`.

---

## Questão 30 — COUNT com WHERE

Conte quantos alunos fazem o curso de **Programação**.

Utilize:

- `COUNT`;
- `WHERE`.

---

## Questão 31 — AVG

Calcule a **média das notas** de todos os alunos.

Utilize `AVG`.

---

## Questão 32 — MAX

Mostre a **maior nota** existente na tabela.

Utilize `MAX`.

---

## Questão 33 — MIN

Mostre a **menor nota** existente na tabela.

Utilize `MIN`.

---

## Questão 34 — SUM

Calcule a **soma de todas as notas** dos alunos.

Utilize `SUM`.

---

## Questão 35 — Várias funções de agregação

Faça uma única consulta que mostre:

- a menor nota;
- a maior nota;
- a média das notas.

Utilize:

- `MIN`;
- `MAX`;
- `AVG`;
- `AS`.

Dê nomes apropriados para as colunas do resultado.

---

# Parte 11 — GROUP BY

## Questão 36 — Quantidade de alunos por cidade

Mostre cada cidade e a quantidade de alunos daquela cidade.

Utilize:

- `GROUP BY`;
- `COUNT`.

O resultado deverá ser semelhante a:

| cidade | quantidade |
|---|---:|
| Curitiba | ... |
| Londrina | ... |
| Maringá | ... |

---

## Questão 37 — Quantidade de alunos por curso

Mostre cada curso e a quantidade de alunos matriculados nele.

Utilize:

- `GROUP BY`;
- `COUNT`.

---

## Questão 38 — Média das notas por cidade

Mostre cada cidade e a **média das notas** dos alunos daquela cidade.

Utilize:

- `GROUP BY`;
- `AVG`.

---

## Questão 39 — Maior nota por curso

Mostre cada curso e a **maior nota** obtida naquele curso.

Utilize:

- `GROUP BY`;
- `MAX`.

---

# Parte 12 — HAVING

## Questão 40 — Cidades com pelo menos 3 alunos

Mostre somente as cidades que possuem **pelo menos 3 alunos**.

Utilize:

- `GROUP BY`;
- `COUNT`;
- `HAVING`.

---

## Questão 41 — Cursos com mais de 3 alunos

Mostre somente os cursos que possuem **mais de 3 alunos**.

Utilize:

- `GROUP BY`;
- `COUNT`;
- `HAVING`.

---

## Questão 42 — Cursos com média maior que 7

Mostre os cursos cuja **média das notas seja maior que 7**.

Utilize:

- `GROUP BY`;
- `AVG`;
- `HAVING`.

---

# Desafio Final ⭐

Faça uma consulta que mostre:

- cidade;
- quantidade de alunos;
- média das notas.

Porém, devem aparecer **somente as cidades** que atendam às duas condições:

1. tenham pelo menos **3 alunos**;
2. tenham média das notas **maior que 7**.

O resultado deve ser ordenado pela média das notas, da **maior para a menor**.

### Requisitos

Sua consulta deverá utilizar:

- `SELECT`;
- `COUNT`;
- `AVG`;
- `FROM`;
- `GROUP BY`;
- `HAVING`;
- `ORDER BY`;
- `DESC`.

---

# Desafio Extra ⭐⭐

Faça uma consulta que mostre os **3 melhores alunos do curso de Programação**.

Exiba somente:

- nome;
- idade;
- nota.

### Regras

A consulta deverá:

1. mostrar somente alunos do curso de Programação;
2. considerar somente alunos com nota maior ou igual a 7;
3. ordenar pela nota da maior para a menor;
4. mostrar somente os 3 primeiros alunos.

### Dica

Você precisará utilizar:

- `SELECT`;
- `FROM`;
- `WHERE`;
- `AND`;
- `ORDER BY`;
- `DESC`;
- `LIMIT`.

---

# Desafio de Interpretação 🧠

Analise cuidadosamente a consulta abaixo:

```sql
SELECT cidade,
       COUNT(*) AS quantidade,
       AVG(nota) AS media
FROM alunos
WHERE idade >= 18
GROUP BY cidade
HAVING AVG(nota) >= 7
ORDER BY media DESC
LIMIT 2;
```

## Responda às perguntas

### 1.

O que está sendo selecionado pelo `SELECT`?

### 2.

De qual tabela os dados estão sendo obtidos?

### 3.

Qual condição está sendo aplicada pelo `WHERE`?

### 4.

Por qual coluna os registros estão sendo agrupados?

### 5.

O que o `COUNT(*)` está calculando?

### 6.

O que o `AVG(nota)` está calculando?

### 7.

Qual condição está sendo aplicada pelo `HAVING`?

### 8.

Como os resultados estão sendo ordenados?

### 9.

O que significa `DESC` nessa consulta?

### 10.

O que o `LIMIT 2` faz?

### 11.

Explique, com suas próprias palavras, **o que a consulta inteira faz**.

---

# Orientações para entrega

Para cada questão:

1. Escreva o comando SQL utilizado.
2. Execute o comando no PostgreSQL.
3. Confira o resultado retornado.
4. Caso o resultado não esteja correto, revise sua consulta.
5. Mantenha as questões numeradas para facilitar a correção.

> **Atenção:** O objetivo da atividade não é apenas obter o resultado correto. Você deve compreender o que cada cláusula da consulta está fazendo.

---

# Conteúdos trabalhados

Ao finalizar a atividade, você deverá ter praticado:

- `SELECT`
- `FROM`
- `WHERE`
- `AS`
- `=`
- `<>`
- `!=`
- `>`
- `<`
- `>=`
- `<=`
- `AND`
- `OR`
- `NOT`
- `BETWEEN`
- `IN`
- `LIKE`
- `ILIKE`
- `DISTINCT`
- `ORDER BY`
- `ASC`
- `DESC`
- `LIMIT`
- `OFFSET`
- `COUNT`
- `SUM`
- `AVG`
- `MIN`
- `MAX`
- `GROUP BY`
- `HAVING`

---

# Observação

Esta atividade foi desenvolvida para trabalhar consultas utilizando **uma única tabela**.

> **JOIN não faz parte desta atividade.**