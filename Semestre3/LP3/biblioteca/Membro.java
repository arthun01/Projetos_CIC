public class Membro{
    private String nome;
    private int id_proximo_usuario = 1;

    // construtores
    public Membro(String nome){
        if(nome != null && !nome.trim().isEmpty()){
            this.nome = nome;
        }else{
            System.out.println("Entrada de String inválida");
            return;
        }

        this.id_proximo_usuario += 1; 
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public int getId(){
        return this.id_proximo_usuario;
    }

    // setters
    public void setNome(String novoNome){
        if(novoNome != null && !novoNome.trim().isEmpty()){
            this.nome = novoNome;
        }else{
            System.out.println("Entrada errada de String");
            return;
        }
    }


    public void printar_membro(){
        System.out.printf("Membro: %s | ID: %d\n", this.nome, this.id_proximo_usuario);
    }

}