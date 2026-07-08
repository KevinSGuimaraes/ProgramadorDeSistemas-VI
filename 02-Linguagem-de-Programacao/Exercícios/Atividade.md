# Exercícios de Ponteiros em Linguagem C

## Objetivo

Praticar os conceitos básicos de ponteiros em linguagem C, incluindo:

- Declaração de ponteiros;
- Operadores `&` (endereço) e `*` (conteúdo);
- Associação de ponteiros com variáveis;
- Acesso a valores através de ponteiros;
- Alteração de valores utilizando ponteiros;
- Operações matemáticas utilizando ponteiros.

---

## 📌 Exercício 1 – Endereços e Valores

Crie um programa em C que:

1. Declare uma variável inteira chamada `numero` e atribua a ela o valor `50`.
2. Declare um ponteiro para inteiro chamado `ptr` e faça com que ele aponte para `numero`.
3. Imprima na tela:
   - O valor da variável `numero`;
   - O endereço de memória de `numero`;
   - O valor armazenado no ponteiro `ptr`;
   - O conteúdo apontado por `ptr`.

### Exemplo de saída

```text
Valor de numero: 50
Endereco de numero: 0x...
Valor armazenado em ptr: 0x...
Conteudo apontado por ptr: 50
```

---

## 📌 Exercício 2 – Alterando Valor Via Ponteiro

Crie um programa em C que:

1. Declare uma variável inteira chamada `idade` e atribua a ela o valor `20`.
2. Declare um ponteiro para inteiro chamado `p`.
3. Faça o ponteiro apontar para a variável `idade`.
4. Utilize o ponteiro para alterar o valor de `idade` para `25`.
5. Exiba os valores antes e depois da alteração.

### Exemplo de saída

```text
Valor inicial: 20
Valor final: 25
```

---

## 📌 Exercício 3 – Dobro de um Número

Crie um programa que:

1. Leia um número inteiro informado pelo usuário.
2. Declare um ponteiro para esse número.
3. Utilize o ponteiro para multiplicar o valor por 2.
4. Exiba o resultado.

### Exemplo

```text
Digite um numero: 8

Dobro: 16
```

---

## 📌 Exercício 4 – Soma Utilizando Ponteiros

Crie um programa que:

1. Leia dois números inteiros.
2. Declare dois ponteiros.
3. Faça cada ponteiro apontar para uma das variáveis.
4. Calcule a soma utilizando apenas os ponteiros.
5. Exiba o resultado.

### Exemplo

```text
Numero 1: 10
Numero 2: 20

Soma = 30
```

---

## 📌 Exercício 5 – Troca de Valores

Crie um programa que:

1. Leia dois números inteiros.
2. Declare dois ponteiros.
3. Faça cada ponteiro apontar para uma variável.
4. Troque os valores das variáveis utilizando apenas os ponteiros.
5. Exiba os valores antes e depois da troca.

### Exemplo

```text
Antes:
A = 10
B = 20

Depois:
A = 20
B = 10
```

---

## 📌 Exercício 6 – Maior Valor

Crie um programa que:

1. Leia dois números inteiros.
2. Utilize ponteiros para acessar os valores.
3. Informe qual dos números é o maior.

### Exemplo

```text
Digite A: 8
Digite B: 15

Maior valor: 15
```

---

## 📌 Exercício 7 – Três Variáveis

Crie um programa que:

1. Declare três variáveis inteiras.
2. Declare três ponteiros.
3. Faça cada ponteiro apontar para uma variável.
4. Exiba:
   - O valor de cada variável;
   - O endereço de memória de cada variável;
   - O valor armazenado em cada ponteiro.

### Exemplo de saída

```text
Variavel A = 10
Endereco A = 0x...

Variavel B = 20
Endereco B = 0x...

Variavel C = 30
Endereco C = 0x...
```

---

## 📌 Exercício 8 – Calculadora Simples com Ponteiros

Crie um programa que:

1. Leia dois números inteiros.
2. Declare dois ponteiros.
3. Faça os ponteiros apontarem para as variáveis.
4. Exiba:
   - Soma;
   - Subtração;
   - Multiplicação;
   - Divisão.

Todas as operações devem utilizar os valores acessados pelos ponteiros.

### Exemplo

```text
Numero 1: 20
Numero 2: 10

Soma: 30
Subtracao: 10
Multiplicacao: 200
Divisao: 2
```

---

## 📌 Exercício 9 – Atualização de Salário

Crie um programa que:

1. Leia o salário de um funcionário.
2. Declare um ponteiro para a variável salário.
3. Aumente o salário em 10% utilizando o ponteiro.
4. Exiba:
   - O salário original;
   - O novo salário.

### Exemplo

```text
Salario: 2000

Novo salario: 2200
```

---

## 📌 Exercício 10 – Manipulando Duas Variáveis

Crie um programa que:

1. Leia dois números inteiros.
2. Declare dois ponteiros.
3. Faça:
   - O primeiro número receber o dobro do valor atual;
   - O segundo número receber a metade do valor atual.
4. Todas as alterações devem ser realizadas através dos ponteiros.
5. Exiba os valores finais.

### Exemplo

```text
Numero 1: 8
Numero 2: 20

Resultado:
Numero 1 = 16
Numero 2 = 10
```

---

# Desafio 

Crie um programa que:

1. Declare quatro variáveis inteiras.
2. Declare quatro ponteiros.
3. Leia os valores das variáveis.
4. Descubra:
   - O maior valor;
   - O menor valor;
   - A soma de todos os valores.
5. Utilize apenas os ponteiros para acessar as variáveis durante os cálculos.

### Exemplo

```text
Digite os valores:
10
5
30
20

Maior valor: 30
Menor valor: 5
Soma: 65
```

---

# Critérios de Avaliação

| Critério | Pontos |
|-----------|---------:|
| Exercícios 1 a 5 | 5,0 |
| Exercícios 6 a 10 | 4,0 |
| Organização e legibilidade do código | 1,0 |
| Desafio Extra (bônus) | +1,0 |

**Nota Total:** 10,0 pontos (+1,0 ponto bônus)

---

## Entrega

- Todos os exercícios devem estar funcionando.
- Cada exercício deve estar devidamente comentado.
- O código deve ser organizado e indentado.
- O aluno deve demonstrar o uso correto dos operadores `*` e `&`.