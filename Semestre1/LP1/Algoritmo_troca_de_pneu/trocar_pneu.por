programa {
  funcao inicio() {
    caracter estepe
    inteiro parafusos

    parafusos = 1

    escreva ("=====================\n")
    escreva ("ALGORITMO TROCAR PNEU\n")
    escreva ("=====================\n")

    escreva ("O Estepe está vazio? [S/N] ")
    leia (estepe)
    
    se (estepe == 'S' ou estepe == 's'){
      escreva ("Chame o Borracheiro!!")
    }senao se (estepe == 'N' ou estepe == 'n'){
      escreva ("Pegue o macaco hidráulico\n")
      escreva ("Levante o carro\n")

    enquanto (parafusos <= 4){
      escreva ("Tire o parafuso ", parafusos, "\n")
      parafusos += 1
    }

    escreva ("Tire o pneu vazio\n")
    escreva ("Coloque o estepe\n")

    parafusos = 1

    enquanto (parafusos <= 4){
      escreva ("Bote o parafuso ", parafusos, "\n")
      parafusos += 1
    }

    escreva ("Abaixe o carro\n")
    escreva ("Guarde o macaco hidráulico\n")
    escreva ("O pneu está trocado!!\n")

    }
  }
}
