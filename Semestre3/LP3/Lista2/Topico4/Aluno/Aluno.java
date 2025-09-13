package Aluno;

public class Aluno{
    // atributos
    private String nome;
    private String matricula;
    private float[] notas = new float[3];

    // construtores
    public Aluno(String nome, String matricula, float n1, float n2, float n3){
        this.nome = nome;
        this.matricula = matricula;
        this.notas[0] = n1;
        this.notas[1] = n2;
        this.notas[2] = n3;
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public String getMatricula(){
        return this.matricula;
    }

    public float[] getNota(){
        // .clone retorna um clone do nosso array e não o "ponteiro" original que levaria a falhas de segurança
        return this.notas.clone();
    }

    public float getNota(int index){
        // getter pelo indice
        if(index >= 0 && index < this.notas.length){
            return this.notas[index];
        }
        return -1;
    }

    public float getMedia(){
        float soma = 0.0f;
        for(int i = 0; i < this.notas.length; i++){
            soma += this.notas[i];
            System.out.println(soma);
        }
        if(this.notas.length > 0){
            return soma / this.notas.length;
        }
        
        return 0.0f;
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setMatricula(String novaMatricula){
        this.matricula = novaMatricula;
    }

    public void setNota(int indice, float novaNota){
        if(indice >= 0 && indice < this.notas.length && novaNota >= 0 && novaNota <= 10){
            this.notas[indice] = novaNota;
        }else{
            System.out.println("Não foi possível alterar a nota.");
        }
    }

    // metodos
    public void apresentar(){
        System.out.printf("Aluno: %s - N° de Matrícula: %s\n", this.nome, this.matricula);
        for(int i = 0; i < this.notas.length; i++){
            System.out.printf("Nota %d: %.2f\n", i+1, this.notas[i]);
        }
    }
}