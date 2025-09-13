# Tópico 3: Construtores e Inicialização de Objetos

## Introdução
Um construtor é um método especial que é chamado automaticamente quando um objeto é criado. Ele é usado para inicializar os atributos do objeto. Nesta seção, você vai praticar a criação de construtores com e sem parâmetros.

## Exercícios
###  ✅ Classe Cliente:
Crie uma classe Cliente com atributos nome e cpf.
Implemente um construtor que inicialize ambos os atributos no momento da criação do objeto.

###  ✅ Classes Produto e Livro (Modificação):
Modifique a classe Produto com um construtor que recebe nome e preço. Adicione um método exibir_detalhes() que imprime os atributos do objeto.
Modifique a classe Livro para que o construtor defina o atributo booleano disponivel como true por padrão.

###  ✅ Classes Triangulo, Pessoa e Retangulo (Modificação):
Crie uma classe Triangulo com construtor que recebe a base e a altura e um método calcular_area().
Modifique a classe Pessoa (do Tópico 1) com um construtor que recebe nome e idade.
Modifique a classe Retangulo (do Tópico 2) com um construtor padrão que define a largura e a altura como 1.

###  ✅ Novo Exercício: Classe Data
Crie uma classe Data com atributos para dia, mes e ano.
Crie dois construtores: um que recebe os três parâmetros (dia, mês, ano) e outro que recebe apenas o ano, definindo o dia e o mês como 1 (1º de janeiro do ano especificado).
