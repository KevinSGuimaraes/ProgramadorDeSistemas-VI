# ATIVIDADE PRÁTICA – JOIN, UNION E UNION ALL NO POSTGRESQL

## 1. Objetivo

Nesta atividade você irá praticar os seguintes comandos e conceitos do PostgreSQL:

* `INNER JOIN`
* `LEFT JOIN`
* `RIGHT JOIN`
* `ON`
* `WHERE` em consultas com `JOIN`
* Aliases (`AS`)
* `UNION`
* `UNION ALL`
* Diferença entre `JOIN` e `UNION`

A atividade será realizada utilizando um banco de dados de uma instituição de ensino.

---

# 2. Situação-problema

Uma instituição de ensino possui informações separadas em diferentes tabelas.

Os alunos estão cadastrados na tabela `alunos`, enquanto os cursos estão cadastrados na tabela `cursos`.

Para descobrir informações como:

> "Qual é o nome do aluno e qual curso ele está fazendo?"

será necessário relacionar as duas tabelas utilizando `JOIN`.

Além disso, a instituição possui uma tabela de alunos antigos e deseja combinar informações de diferentes consultas utilizando `UNION` e `UNION ALL`.

---

# 3. Criando as tabelas

Execute os comandos abaixo no PostgreSQL.

## Tabela `cursos`

```sql
CREATE TABLE cursos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    carga_horaria INT NOT NULL
);
```

## Tabela `alunos`

```sql
CREATE TABLE alunos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    idade INT,
    cidade VARCHAR(50),
    curso_id INT,
    FOREIGN KEY (curso_id) REFERENCES cursos(id)
);
```

## Tabela `alunos_antigos`

```sql
CREATE TABLE alunos_antigos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cidade VARCHAR(50)
);
```

---

# 4. Inserindo os cursos

```sql
INSERT INTO cursos (nome, carga_horaria) VALUES
('Programação de Sistemas', 1200),
('Redes de Computadores', 1000),
('Banco de Dados', 800),
('Desenvolvimento Web', 1000),
('Internet das Coisas', 600),
('Eletrônica', 800);
```

---

# 5. Inserindo os alunos

```sql
INSERT INTO alunos (nome, idade, cidade, curso_id) VALUES
('Ana Silva', 18, 'Curitiba', 1),
('Bruno Santos', 21, 'Londrina', 2),
('Carlos Souza', 19, 'Curitiba', 1),
('Daniel Oliveira', 25, 'Maringá', 3),
('Eduarda Lima', 20, 'Curitiba', 2),
('Felipe Costa', 17, 'Londrina', 1),
('Gabriela Alves', 22, 'Maringá', 3),
('Henrique Rocha', 19, 'Curitiba', 2),
('Isabela Martins', 20, 'Londrina', 1),
('João Pereira', 23, 'Curitiba', 3),
('Karen Mendes', 18, 'Maringá', NULL),
('Lucas Ferreira', 26, 'Curitiba', 2);
```

> **Atenção:** Karen possui `curso_id = NULL`. Isso será importante para praticar `LEFT JOIN`.

---

# 6. Inserindo alunos antigos

```sql
INSERT INTO alunos_antigos (nome, cidade) VALUES
('Marcos Lima', 'Curitiba'),
('Patrícia Souza', 'Londrina'),
('Rafael Costa', 'Maringá'),
('Ana Silva', 'Curitiba'),
('Carlos Souza', 'Curitiba');
```

Observe que alguns nomes também aparecem na tabela `alunos`.

Isso será importante para entender a diferença entre `UNION` e `UNION ALL`.

---

# PARTE 1 – REVISÃO DO SELECT

Antes de utilizar `JOIN`, faça algumas consultas simples.

## Questão 1

Liste todos os alunos.

```sql
-- escreva sua consulta aqui
```

---

## Questão 2

Liste somente o nome e a cidade dos alunos.

```sql
-- escreva sua consulta aqui
```

---

## Questão 3

Liste os alunos que moram em Curitiba.

```sql
-- escreva sua consulta aqui
```

---

## Questão 4

Liste os alunos com idade maior ou igual a 20 anos.

```sql
-- escreva sua consulta aqui
```

---

# PARTE 2 – ENTENDENDO O INNER JOIN

Agora vamos relacionar as tabelas `alunos` e `cursos`.

A estrutura básica é:

```sql
SELECT colunas
FROM tabela1
INNER JOIN tabela2
ON tabela1.chave = tabela2.chave;
```

No nosso banco:

```sql
SELECT alunos.nome, cursos.nome
FROM alunos
INNER JOIN cursos
ON alunos.curso_id = cursos.id;
```

Observe que:

```text
alunos.curso_id
       ↓
       =
       ↓
cursos.id
```

Essas duas colunas são utilizadas para estabelecer o relacionamento.

---

# Questão 5

Liste o nome de cada aluno e o nome do seu curso.

Utilize `INNER JOIN`.

```sql
-- escreva sua consulta aqui
```

---

# Questão 6

Liste:

* nome do aluno;
* idade;
* nome do curso.

```sql
-- escreva sua consulta aqui
```

---

# Questão 7

Liste:

* nome do aluno;
* cidade;
* nome do curso;
* carga horária do curso.

```sql
-- escreva sua consulta aqui
```

---

# Questão 8 – Usando Alias

Reescreva a consulta anterior utilizando aliases.

Utilize:

```text
a = alunos
c = cursos
```

Resultado esperado:

```text
aluno | cidade | curso | carga_horaria
```

```sql
-- escreva sua consulta aqui
```

---

# Questão 9 – INNER JOIN + WHERE

Liste os alunos que fazem o curso de:

```text
Programação de Sistemas
```

O resultado deve apresentar:

* nome do aluno;
* cidade;
* curso.

```sql
-- escreva sua consulta aqui
```

---

# Questão 10

Liste os alunos que fazem cursos com carga horária maior que `900` horas.

Apresente:

* nome do aluno;
* curso;
* carga horária.

```sql
-- escreva sua consulta aqui
```

---

# PARTE 3 – LEFT JOIN

Agora vamos utilizar:

```sql
LEFT JOIN
```

A estrutura é:

```sql
SELECT colunas
FROM tabela_esquerda
LEFT JOIN tabela_direita
ON condição;
```

O `LEFT JOIN` mantém **todos os registros da tabela da esquerda**, mesmo que não exista correspondência na tabela da direita.

---

# Questão 11

Liste todos os alunos e seus respectivos cursos.

Utilize `LEFT JOIN`.

```sql
-- escreva sua consulta aqui
```

---

# Questão 12

Observe o resultado da questão anterior.

Qual aluno aparece com o curso `NULL`?

Responda:

```text
Aluno:
```

Por que isso acontece?

```text
Resposta:
```

---

# Questão 13

Liste todos os alunos, incluindo aqueles que ainda não possuem curso cadastrado.

Apresente:

* nome;
* cidade;
* curso.

Utilize `LEFT JOIN`.

```sql
-- escreva sua consulta aqui
```

---

# Questão 14

Liste somente os alunos que **não possuem curso cadastrado**.

Dica:

```sql
WHERE cursos.id IS NULL
```

```sql
-- escreva sua consulta aqui
```

---

# Questão 15 – LEFT JOIN + WHERE

Liste todos os alunos de Curitiba, mostrando:

* nome;
* cidade;
* curso.

```sql
-- escreva sua consulta aqui
```

---

# PARTE 4 – RIGHT JOIN

Agora vamos inverter a lógica.

O `RIGHT JOIN` mantém **todos os registros da tabela da direita**.

Estrutura:

```sql
SELECT colunas
FROM tabela_esquerda
RIGHT JOIN tabela_direita
ON condição;
```

---

# Questão 16

Liste todos os cursos e os alunos matriculados neles.

Utilize `RIGHT JOIN`.

```sql
-- escreva sua consulta aqui
```

---

# Questão 17

Observe o resultado da questão anterior.

Existem cursos sem nenhum aluno?

Quais?

```text
Resposta:
```

---

# Questão 18

Liste:

* nome do curso;
* carga horária;
* nome do aluno.

Utilize `RIGHT JOIN`.

```sql
-- escreva sua consulta aqui
```

---

# Questão 19 – Comparação

Explique com suas palavras a diferença entre:

```sql
INNER JOIN
```

e

```sql
LEFT JOIN
```

Resposta:

```text
INNER JOIN:
____________________________________________________
____________________________________________________

LEFT JOIN:
____________________________________________________
____________________________________________________
```

---

# Questão 20

Explique com suas palavras a diferença entre:

```sql
LEFT JOIN
```

e

```sql
RIGHT JOIN
```

Resposta:

```text
LEFT JOIN:
____________________________________________________
____________________________________________________

RIGHT JOIN:
____________________________________________________
____________________________________________________
```

---

# PARTE 5 – UNION

Agora vamos trabalhar com `UNION`.

O `UNION` permite combinar os resultados de duas consultas.

Exemplo:

```sql
SELECT nome
FROM alunos

UNION

SELECT nome
FROM alunos_antigos;
```

O resultado será uma única lista de nomes.

### Importante

O `UNION` elimina registros duplicados.

---

# Questão 21

Liste os nomes dos alunos atuais e dos alunos antigos utilizando `UNION`.

```sql
-- escreva sua consulta aqui
```

---

# Questão 22

Execute a consulta:

```sql
SELECT nome
FROM alunos

UNION

SELECT nome
FROM alunos_antigos;
```

Observe:

* Ana Silva;
* Carlos Souza.

Esses nomes aparecem nas duas tabelas.

Eles aparecem quantas vezes no resultado?

```text
Resposta:
```

Por quê?

```text
Resposta:
```

---

# Questão 23

Faça uma consulta utilizando `UNION` para listar as cidades presentes nas tabelas:

```text
alunos
alunos_antigos
```

```sql
-- escreva sua consulta aqui
```

---

# Questão 24

Utilizando `UNION`, crie uma lista contendo:

* nome dos alunos atuais;
* nome dos alunos antigos.

Ordene o resultado em ordem alfabética.

Dica:

O `ORDER BY` pode ser colocado no final.

```sql
-- escreva sua consulta aqui
```

---

# PARTE 6 – UNION ALL

Agora vamos utilizar:

```sql
UNION ALL
```

A diferença é:

```text
UNION
    ↓
remove duplicados

UNION ALL
    ↓
mantém duplicados
```

Exemplo:

```sql
SELECT nome
FROM alunos

UNION ALL

SELECT nome
FROM alunos_antigos;
```

---

# Questão 25

Liste os nomes dos alunos atuais e antigos utilizando:

```sql
UNION ALL
```

```sql
-- escreva sua consulta aqui
```

---

# Questão 26

Compare os resultados:

### Consulta 1

```sql
SELECT nome
FROM alunos

UNION

SELECT nome
FROM alunos_antigos;
```

### Consulta 2

```sql
SELECT nome
FROM alunos

UNION ALL

SELECT nome
FROM alunos_antigos;
```

Qual delas apresenta mais registros?

```text
Resposta:
```

Por quê?

```text
Resposta:
```

---

# Questão 27

Explique com suas palavras a diferença entre:

```sql
UNION
```

e

```sql
UNION ALL
```

Resposta:

```text
UNION:
____________________________________________________
____________________________________________________

UNION ALL:
____________________________________________________
____________________________________________________
```

---

# PARTE 7 – JOIN x UNION

Agora vamos diferenciar dois conceitos muito importantes.

## JOIN

O `JOIN` relaciona informações de tabelas diferentes.

Exemplo:

```sql
SELECT
    alunos.nome,
    cursos.nome
FROM alunos
INNER JOIN cursos
ON alunos.curso_id = cursos.id;
```

O resultado coloca informações relacionadas **lado a lado**.

```text
ALUNO             CURSO
Ana Silva         Programação de Sistemas
Bruno Santos      Redes de Computadores
Carlos Souza      Programação de Sistemas
```

---

## UNION

O `UNION` combina resultados de consultas.

Exemplo:

```sql
SELECT nome
FROM alunos

UNION

SELECT nome
FROM alunos_antigos;
```

O resultado coloca os registros **um abaixo do outro**.

```text
Ana Silva
Bruno Santos
Carlos Souza
Marcos Lima
Patrícia Souza
```

---

# Questão 28

Complete:

```text
JOIN é utilizado para ______________________________
____________________________________________________

UNION é utilizado para ______________________________
____________________________________________________
```

---

# Questão 29

Imagine que temos:

### Tabela `alunos`

```text
id | nome
---+-------------
1  | Ana
2  | Bruno
3  | Carlos
```

### Tabela `cursos`

```text
id | nome
---+-------------
1  | Programação
2  | Redes
3  | Banco de Dados
```

Queremos descobrir:

> Qual curso cada aluno está fazendo?

Devemos utilizar:

```text
JOIN ou UNION?

Resposta:
```

Por quê?

```text
____________________________________________________
____________________________________________________
```

---

# Questão 30

Agora imagine:

### Consulta A

```text
Ana
Bruno
Carlos
```

### Consulta B

```text
Carlos
Daniel
Eduarda
```

Se utilizarmos:

```sql
UNION
```

qual será o resultado?

```text
Resposta:
____________________________________________________
____________________________________________________
```

---

# Questão 31

Com os mesmos dados, se utilizarmos:

```sql
UNION ALL
```

qual será o resultado?

```text
Resposta:
____________________________________________________
____________________________________________________
```

---

# PARTE 8 – DESAFIO

Agora você deverá resolver os problemas sem receber a consulta pronta.

---

# Desafio 1

A instituição deseja saber:

> "Quais são os alunos de Curitiba e quais cursos eles fazem?"

Apresente:

* nome do aluno;
* cidade;
* nome do curso.

Utilize `INNER JOIN`.

```sql
-- sua resposta
```

---

# Desafio 2

A instituição deseja encontrar todos os alunos que ainda não possuem curso cadastrado.

Apresente:

* nome;
* cidade.

Utilize `LEFT JOIN`.

```sql
-- sua resposta
```

---

# Desafio 3

A instituição deseja descobrir quais cursos ainda não possuem nenhum aluno matriculado.

Apresente:

* nome do curso;
* carga horária.

Utilize `RIGHT JOIN`.

```sql
-- sua resposta
```

---

# Desafio 4

Crie uma consulta que mostre todos os nomes de alunos atuais e antigos, sem repetir nomes.

Utilize:

```sql
UNION
```

```sql
-- sua resposta
```

---

# Desafio 5

Agora faça a mesma consulta anterior, mas mantendo os nomes repetidos.

Utilize:

```sql
UNION ALL
```

```sql
-- sua resposta
```

---

# PARTE 9 – DESAFIO FINAL

Agora você deverá combinar os conhecimentos aprendidos.

Crie uma consulta que apresente:

```text
Nome do aluno
Cidade
Nome do curso
Carga horária
```

A consulta deve:

1. Mostrar todos os alunos;
2. Mostrar o curso quando existir;
3. Manter alunos sem curso;
4. Ordenar os resultados pelo nome do aluno.

```sql
-- escreva sua solução
```

---

# PARTE 10 – SITUAÇÃO-PROBLEMA FINAL

Você foi contratado para desenvolver o sistema de uma escola.

O gerente pediu cinco relatórios.

## Relatório 1

Mostrar todos os alunos com seus respectivos cursos.

```sql
-- solução
```

## Relatório 2

Mostrar todos os alunos, inclusive os que não possuem curso.

```sql
-- solução
```

## Relatório 3

Mostrar todos os cursos, inclusive os que não possuem alunos.

```sql
-- solução
```

## Relatório 4

Mostrar todos os nomes de alunos atuais e antigos, sem duplicações.

```sql
-- solução
```

## Relatório 5

Mostrar todos os nomes de alunos atuais e antigos, mantendo duplicações.

```sql
-- solução
```

---

# PARTE 11 – DESAFIO EXTRA

Crie uma nova tabela chamada:

```text
alunos_transferidos
```

Ela deverá possuir:

```text
id
nome
cidade
```

Crie pelo menos 5 registros.

Depois faça:

### A)

Uma consulta utilizando `UNION`.

```sql
-- solução
```

### B)

Uma consulta utilizando `UNION ALL`.

```sql
-- solução
```

### C)

Explique qual é a diferença entre os resultados.

```text
____________________________________________________
____________________________________________________
____________________________________________________
```

---

# PARTE 12 – PERGUNTAS CONCEITUAIS

Responda sem executar comandos.

## 1.

Para que serve o `JOIN`?

```text
____________________________________________________
____________________________________________________
```

## 2.

Para que serve o `ON` dentro de um `JOIN`?

```text
____________________________________________________
____________________________________________________
```

## 3.

Qual `JOIN` retorna somente registros que possuem correspondência nas duas tabelas?

```text
Resposta:
```

## 4.

Qual `JOIN` mantém todos os registros da tabela da esquerda?

```text
Resposta:
```

## 5.

Qual `JOIN` mantém todos os registros da tabela da direita?

```text
Resposta:
```

## 6.

O que acontece com os registros duplicados utilizando `UNION`?

```text
Resposta:
```

## 7.

O que acontece com os registros duplicados utilizando `UNION ALL`?

```text
Resposta:
```

## 8.

JOIN e UNION fazem a mesma coisa?

```text
Resposta:
____________________________________________________
____________________________________________________
```

---

# DESAFIO FINAL – SEM DICAS

Escreva uma consulta para cada situação abaixo.

## A)

"Quero o nome do aluno e o nome do curso somente quando houver correspondência."

```sql
-- sua solução
```

## B)

"Quero todos os alunos, mesmo que não tenham curso."

```sql
-- sua solução
```

## C)

"Quero todos os cursos, mesmo que nenhum aluno esteja matriculado."

```sql
-- sua solução
```

## D)

"Quero unir duas listas de nomes e remover duplicados."

```sql
-- sua solução
```

## E)

"Quero unir duas listas de nomes e manter duplicados."

```sql
-- sua solução
```

---

# CHECKLIST DO ALUNO

Antes de entregar a atividade, verifique se você consegue explicar:

* [ ] O que é `INNER JOIN`;
* [ ] O que é `LEFT JOIN`;
* [ ] O que é `RIGHT JOIN`;
* [ ] Para que serve o `ON`;
* [ ] Para que servem aliases;
* [ ] O que acontece quando não existe correspondência em um `LEFT JOIN`;
* [ ] O que acontece quando não existe correspondência em um `RIGHT JOIN`;
* [ ] O que é `UNION`;
* [ ] O que é `UNION ALL`;
* [ ] A diferença entre `UNION` e `UNION ALL`;
* [ ] A diferença entre `JOIN` e `UNION`;
* [ ] Quando utilizar `JOIN`;
* [ ] Quando utilizar `UNION`.

---

# RESUMO PARA CONSULTA

```text
INNER JOIN
→ somente registros que possuem correspondência.

LEFT JOIN
→ todos os registros da tabela da esquerda
→ + correspondências da tabela da direita.

RIGHT JOIN
→ todos os registros da tabela da direita
→ + correspondências da tabela da esquerda.

UNION
→ combina resultados
→ remove duplicados.

UNION ALL
→ combina resultados
→ mantém duplicados.
```

## Frase para memorizar

> **JOIN relaciona tabelas.**

> **UNION combina resultados de consultas.**

> **INNER JOIN pega somente correspondências.**

> **LEFT JOIN mantém todos da esquerda.**

> **RIGHT JOIN mantém todos da direita.**

> **UNION remove duplicados.**

> **UNION ALL mantém duplicados.**
