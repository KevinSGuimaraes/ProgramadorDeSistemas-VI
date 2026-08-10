# Lista de Exercícios – Modelagem de Banco de Dados (DER)

## Exercício 01

Desenvolva o **Diagrama Entidade-Relacionamento (DER)** para as seguintes situações:

1. Um aluno realiza vários trabalhos. Um trabalho é realizado por um ou mais alunos.

2. Um diretor dirige no máximo um departamento. Um departamento tem no máximo um diretor.

3. Um autor escreve vários livros. Um livro pode ser escrito por vários autores.

4. Uma equipe é composta por vários jogadores. Um jogador joga apenas em uma equipe.

5. Um cliente realiza várias encomendas. Uma encomenda diz respeito apenas a um cliente.

---

# Exercício 02

Um berçário deseja informatizar suas operações. Quando um bebê nasce, algumas informações são armazenadas sobre ele, tais como:

- Nome;
- Data de nascimento;
- Peso ao nascer;
- Altura ao nascer;
- A mãe do bebê;
- O médico responsável pelo parto.

Para as mães, o berçário também deseja manter um controle, guardando informações como:

- Nome;
- Endereço;
- Telefone;
- Data de nascimento.

Para os médicos, é importante saber:

- CRM;
- Nome;
- Telefone celular;
- Especialidade.

### Atividades

6. Grife as entidades que você identificar no texto acima.

7. Liste as entidades que você grifou.

8. Liste os relacionamentos entre as entidades.

   **Exemplo:**  
   `Mãe_Bebê` → relacionamento entre **Mãe TEM Bebê**.

9. Para as entidades que você listou, escreva quais são as chaves e os campos comuns detectados.

10. Crie o Modelo Entidade-Relacionamento (MER) do Exercício 02.

---

# Exercício 03

Uma floricultura deseja informatizar suas operações.

Inicialmente, deseja manter um cadastro de todos os seus clientes, armazenando:

- RG;
- Nome;
- Telefone;
- Endereço.

Deseja também manter um cadastro contendo informações sobre os produtos que vende:

- Nome do produto;
- Tipo (flor, vaso, planta, etc.);
- Preço;
- Quantidade em estoque.

Quando um cliente faz uma compra, a mesma é armazenada, mantendo informações sobre:

- Cliente que realizou a compra;
- Data da compra;
- Valor total;
- Produtos comprados.

### Atividades

11. Grife as entidades que você identificar no texto acima.

12. Liste as entidades que você grifou.

13. Liste os relacionamentos entre as entidades.

14. Liste os campos comuns e as chaves das entidades.

15. Crie o Modelo Entidade-Relacionamento (MER) do Exercício 03.

---

# Exercício 04

Uma escola tem várias turmas.

Uma turma possui vários professores, sendo que um professor pode ministrar aulas em mais de uma turma.

Uma turma tem sempre aulas na mesma sala, mas uma sala pode estar associada a várias turmas (em horários diferentes).

### Atividades

16. Grife as entidades que você identificar no texto acima.

17. Liste as entidades que você grifou.

18. Liste os relacionamentos entre as entidades.

19. Liste os campos comuns e as chaves das entidades.

20. Crie o Modelo Entidade-Relacionamento (MER) do Exercício 04.

---

# Exercício 05

Uma biblioteca deseja manter informações sobre seus livros.

Inicialmente, quer armazenar para os livros as seguintes características:

- ISBN;
- Título;
- Ano;
- Editora;
- Autores.

Para os autores, deseja manter:

- Nome;
- Nacionalidade.

Cabe salientar que um autor pode ter vários livros, assim como um livro pode ser escrito por vários autores.

Cada livro da biblioteca pertence a uma categoria.

A biblioteca deseja manter um cadastro de todas as categorias existentes, contendo:

- Código da categoria;
- Descrição.

Uma categoria pode ter vários livros associados a ela.

### Atividades

21. Grife as entidades que você identificar no texto acima.

22. Liste as entidades que você grifou.

23. Liste os relacionamentos entre as entidades.

24. Liste os campos comuns e as chaves das entidades.

25. Crie o Modelo Entidade-Relacionamento (MER) do Exercício 05.

---

# Exercício 06

Uma empresa vende produtos de limpeza e deseja controlar melhor seus produtos, clientes e pedidos.

Cada produto é caracterizado por:

- Código;
- Nome do produto;
- Categoria (detergente, sabão em pó, sabonete, etc.);
- Preço.

A categoria é uma classificação criada pela própria empresa.

A empresa possui informações sobre todos os seus clientes. Cada cliente é identificado por:

- Código;
- Nome;
- Endereço;
- Telefone;
- Status ("bom", "médio" ou "ruim");
- Limite de crédito.

Também são armazenadas informações sobre os pedidos realizados pelos clientes.

Cada pedido possui:

- Número;
- Data de elaboração.

Cada pedido pode envolver um ou vários produtos e, para cada produto, deve ser informada a quantidade solicitada.

### Atividades

26. Grife as entidades que você identificar no texto acima.

27. Liste as entidades que você grifou.

28. Liste os relacionamentos entre as entidades.

29. Liste os campos comuns e as chaves das entidades.

30. Crie o Modelo Entidade-Relacionamento (MER) do Exercício 06.

---

## Entrega

Para cada exercício:

- Identifique corretamente as entidades;
- Identifique os atributos;
- Defina as chaves primárias;
- Identifique os relacionamentos;
- Defina as cardinalidades;
- Elabore o Modelo Entidade-Relacionamento (MER) utilizando a notação vista em aula.