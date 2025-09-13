public class Aluno {
    // atributos
    private String nome;
    private int idade;
    private float media;

    // construtores
    public Aluno(String nome, int idade, float media){
        this.nome = nome;
        this.idade = idade;
        this.media = media;
    }

    public Aluno(){
        this.nome = "Luiz Carlos";
        this.idade = 17;
        this.media = 6.9f;
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public int getIdade(){
        return this.idade;
    }

    public float getMedia(){
        return this.media;
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setIdade(int novaIdade){
        if(novaIdade <= 18){
            this.idade = novaIdade;
        }else{
            System.out.println("Valor inválido fornecido para Atributo 2");
        }
    }

    public void setMedia(float novaMedia){
        if(novaMedia >= 0 || novaMedia <= 10){
            this.media = novaMedia;
        }else{
            System.out.println("Valor inválido fornecido para Atributo 3");
        }
    }

    @Override
    public String toString(){
        return "Aluno [Nome=" + nome + ", idade=" + idade + ", média=" + media + "]";
    }
}
