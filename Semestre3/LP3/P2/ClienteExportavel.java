public class ClienteExportavel implements Exportavel{
    // atributos
    private String nome;
    private String cpf;
    
    // construtor
    public ClienteExportavel(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
    }
    
    // getters
    public String getNome(){
        return nome;
    }
    
    public String getCpf(){
        return cpf;
    }

    // reescrita do método exportar da interface
    @Override
    public String exportar() {
        return "CLIENTE EXPORTÁVEL, Nome: " + nome + ", CPF: " + cpf;
    }
}