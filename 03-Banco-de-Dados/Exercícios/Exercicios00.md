# Trabalho Prático – Modelagem de Dados (MER e DER)

## Objetivo

Desenvolver o **Modelo Entidade-Relacionamento (MER)** e o **Diagrama Entidade-Relacionamento (DER)** a partir do cenário apresentado a seguir.

A atividade deverá ser desenvolvida utilizando a ferramenta **BrModelo**. Após a conclusão, o aluno deverá publicar os arquivos e imagens geradas em um repositório no **GitHub** e entregar o link conforme orientação do professor.

---

## Enunciado

Uma instituição de ensino promove regularmente eventos acadêmicos, como palestras, minicursos, workshops e semanas temáticas, com o objetivo de complementar a formação de seus estudantes. Cada evento recebe um código de identificação, um nome, uma descrição, uma data de realização e uma carga horária total.

Os eventos são organizados por departamentos da instituição. Cada departamento possui um código próprio, um nome e uma área de atuação. Um mesmo departamento pode ser responsável pela organização de diversos eventos ao longo do ano, mas cada evento é vinculado a apenas um departamento organizador.

Para a realização das atividades, a instituição conta com palestrantes convidados. De cada palestrante são armazenados dados como nome completo, e-mail, telefone e instituição de origem. Um palestrante pode participar de vários eventos diferentes, e cada evento pode contar com a participação de mais de um palestrante, dependendo da programação definida pela coordenação.

Os estudantes podem se inscrever nos eventos disponíveis. Para cada estudante são registrados número de matrícula, nome completo, curso, período e e-mail institucional. Um estudante pode participar de diversos eventos durante sua vida acadêmica, assim como cada evento pode receber inscrições de vários estudantes.

Durante a inscrição, são registradas informações como a data da inscrição e a situação da participação, que pode indicar, por exemplo, se o estudante está inscrito, confirmado, cancelado ou certificado. Após o encerramento do evento, a instituição pode emitir certificados para os participantes que cumprirem os requisitos de presença. Cada certificado possui um número único, uma data de emissão e uma carga horária validada.

Alguns eventos necessitam da reserva de espaços físicos dentro da instituição. Os espaços disponíveis incluem auditórios, laboratórios e salas de aula. Para cada espaço são mantidos dados como identificação, nome, capacidade máxima e localização. Um espaço pode sediar diversos eventos em momentos diferentes, porém cada evento ocorre em apenas um espaço previamente reservado.

Além disso, a coordenação acompanha os patrocinadores que apoiam financeiramente ou com recursos materiais determinados eventos. Para cada patrocinador são armazenados nome, CNPJ, telefone para contato e cidade de origem. Um patrocinador pode apoiar vários eventos, e um mesmo evento pode receber apoio de diferentes patrocinadores.

Ao final de cada semestre, a instituição gera relatórios para analisar quais departamentos organizaram mais atividades, quais palestrantes participaram de mais eventos, quais estudantes obtiveram mais certificados e quais patrocinadores contribuíram com maior frequência para as ações acadêmicas.

---

## Atividades

A partir do texto apresentado:

1. Identifique todas as entidades presentes no cenário.
2. Identifique os atributos de cada entidade.
3. Defina os atributos que serão chaves primárias.
4. Identifique os relacionamentos existentes entre as entidades.
5. Determine corretamente as cardinalidades de cada relacionamento.
6. Identifique possíveis entidades associativas quando necessário.
7. Elabore o **Modelo Entidade-Relacionamento (MER)**.
8. Construa o **Diagrama Entidade-Relacionamento (DER)** utilizando o BrModelo.

---

## Entrega

O repositório GitHub.
