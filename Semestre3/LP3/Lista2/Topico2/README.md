# Tópico 2: Atributos e Métodos

## Introdução
Nesta seção, você vai aprofundar o uso de variáveis de instância (os atributos que definem o
estado do objeto) e métodos (as funções que definem o comportamento do objeto). Também
serão explorados os métodos estáticos, que pertencem à classe e não a uma instância
específica.

## Exercícios
###  ✅ Classe Aluno:
Crie uma classe Aluno com atributos para nome e matricula.
Adicione um método apresentar() que imprima uma mensagem com o nome
e a matrícula do aluno.

###  ✅ Classes Retangulo e Funcionario:
○ Crie uma classe Retangulo com atributos largura e altura. Adicione um
método calcular_area() que retorne a área do retângulo.
○ Crie uma classe Funcionario com um atributo salario. Adicione um método
aumentar_salario(percentual) que, de fato, aumente o salário do funcionario de acordo
com o percentual.

###  ✅ Métodos Estáticos:
Crie uma classe Temperatura com um método estático
converter_celsius_para_fahrenheit(celsius).
Em um exemplo, chame esse método diretamente da classe, sem precisar criar
um objeto

###  ✅ Classe ContaBancaria (Modificação):
Modifique a classe ContaBancaria adicionando os métodos depositar(valor) e sacar(valor).
Em um exemplo, crie uma conta, realize um depósito e, em seguida, um saque. Imprima o saldo após cada operação.

###  ✅ Novo Exercício: Classe Produto (Modificação)
Modifique a classe Produto (do Tópico 1) para incluir um atributo de tipo (String, ex: "Eletrônico", "Alimento", "Vestuário").
Crie um método alterarTipo(novoTipo) que valida se o novo tipo não é null ou vazio antes de atualizar o atributo.
