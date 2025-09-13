# Tópico 4: Encapsulamento

## Introdução
Encapsulamento é o conceito de esconder os detalhes de implementação de uma classe. Em Java, isso é feito usando o modificador de acesso private para os atributos e fornecendo métodos públicos (getters e setters) para controlar o acesso e a modificação desses atributos.

## Exercícios
###  ✅ Classes ContaBancaria, Pessoa e Aluno (Modificação):
Modifique a classe ContaBancaria (do Tópico 2) tornando o saldo privado. Crie os métodos getSaldo() e depositar().
Modifique a classe Pessoa (do Tópico 1) tornando nome e idade privados. Crie os métodos getters e setters para ambos.
Modifique a classe Aluno (do Tópico 2) definindo as notas como atributos privados e crie um método calcular_media().

###  ✅ Classes Livro e Retangulo (Modificação):
Modifique a classe Livro (do Tópico 3) tornando titulo, autor e disponivel privados. Implemente os getters/setters.
Modifique a classe Retangulo (do Tópico 2) tornando largura e altura privados. Adicione validação nos setters e no construtor para garantir que os valores sejam sempre positivos.

###  ✅ Novo Exercício: Classe Funcionario (Modificação)
Modifique a classe Funcionario (do Tópico 2) encapsulando o salario como privado.
Crie um setter setSalario(novoSalario) que valida se o novo valor é positivo antes de atribuí-lo.
Crie um getter getSalarioLiquido() que retorna o salário descontando 15% de imposto, sem alterar o valor do atributo salario.
