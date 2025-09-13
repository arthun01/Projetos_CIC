package Contato;
// import java.util.regex.Pattern;

public class Contato{
    // ATRIBUTOS
    private String nome;
    private String email;
    private String telefone;
    private boolean whatsapp;

    // CONSTRUTORES
    public Contato(String nome, String email, String telefone, boolean whatsapp){
        if(nome == null || nome.trim().isEmpty()){
            throw new IllegalArgumentException("O nome não pode ser nulo ou vazio");
        }
        this.nome = nome;

        if((email == null || email.trim().isEmpty()) && (telefone == null || telefone.trim().isEmpty())){
            throw new IllegalArgumentException("é obrigatório fornecer um email ou telefone");
        }
        
        // usando os SETTERS para o construtor
        if(email != null && !email.trim().isEmpty()){
            setEmail(email);
        }

        if(telefone != null && !telefone.trim().isEmpty()){
            setTelefone(telefone);
        }

        this.whatsapp = whatsapp;
    }

    // GETTERS
    public String getNome(){
        return this.nome;
    }

    public String getEmail(){
        return this.email;
    }

    public String getTelefone(){
        return this.telefone;
    }

    public boolean getWhatsapp(){
        return this.whatsapp;
    }

    // SETTERS
    public void setNome(String novoNome){
        if(novoNome == null || novoNome.trim().isEmpty()){
            System.out.println("Erro: O nome não pode ser nulo ou vazio.");
            return;
        }
        this.nome = novoNome;
    }

    public void setEmail(String novoEmail){
        if(novoEmail != null && novoEmail.contains("@") && !novoEmail.startsWith("@") && !novoEmail.endsWith("@")){
            this.email = novoEmail;
        }else{
            throw new IllegalArgumentException("Formato de e-mail incorreto, use o formato nota@endereco.");
        }
    }

    public void setTelefone(String novoTelefone){
        String apenasDigitos = novoTelefone.replaceAll("\\D+", "");

        if(apenasDigitos.length() == 10 || apenasDigitos.length() == 11){
            this.telefone = novoTelefone;
        }else{
            throw new IllegalArgumentException("Formato de telefone inválido. Use DDD+Número.");
        }
    }

    public void setWhatsapp(boolean novoWhatsapp){
        this.whatsapp = novoWhatsapp;
    }

    // toString
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("-------------------------\n");
        sb.append("Nome: ").append(this.nome).append("\n");

        if(this.email != null && !this.email.isEmpty()){
            sb.append("Email: ").append(this.email).append("\n");
        }

        if(this.telefone != null && !this.telefone.isEmpty()){
            sb.append("Telefone: ").append(this.telefone);

            if(this.whatsapp == true){
                sb.append(" (É whatsapp)\n");
            }else{
                sb.append(" (Não é whatsapp)\n");
            }
        }
        sb.append("-------------------------\n");
        return sb.toString();
    }

}