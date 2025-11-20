import java.util.ArrayList;
import java.util.List;

public class Cliente{
    // atributos privados
    private String nome;
    private String cpf;
    // agregação
    private List<PacoteTuristico> pacotesContratados;
    
    // composição
    private List<Dependente> dependentes;

    // contrutores
    public Cliente(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
        this.pacotesContratados = new ArrayList<>();
        this.dependentes = new ArrayList<>();
    }

    // métodos de agregação
    public void contratarPacote(PacoteTuristico p){
        this.pacotesContratados.add(p);
    }

    public void listarPacotes(){
        System.out.println("=== Cliente: " + nome + " (CPF: " + cpf + ") === ");

        if(pacotesContratados.isEmpty()){
            System.out.println("Nenhum pacote encontrado.");
        }else{
            System.out.println("Pacotes adquiridos:");

            for(PacoteTuristico p : pacotesContratados){
                p.exibirSequenciaEventos();
                System.out.println("---");
            }
        }
    }

    // métodos de composição
    public void adicionarDependente(String nomeDependente){
        Dependente novoDep = new Dependente(nomeDependente);

        this.dependentes.add(novoDep);
    }

    public void listarDependentes(){
        System.out.println("Dependentes de " + this.nome + ":");

        if(dependentes.isEmpty()){
            System.out.println(" - Nenhum dependente cadastrado.");
        }else{
            for(Dependente d : dependentes){
                System.out.println(" -> " + d.getNome());
            }
        }
    }
}