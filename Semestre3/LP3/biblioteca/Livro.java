public class Livro {
    // atributos
    private String titulo;
    private String autor;
    private int ano_de_lancamento;
    private boolean disponivel;

    // construtores
    public Livro(String titulo, String autor, int ano_de_lancamento){
        setTitulo(titulo);
        setAutor(autor);
        setAno(ano_de_lancamento);

        this.disponivel = true;
    }


    // getters
    public String getTitulo(){
        return this.titulo;
    }

    public String getAutor(){
        return this.autor;
    }

    public int getAno(){
        return this.ano_de_lancamento;
    }

    public String getDisponive(){
        if(this.disponivel == true){
            return " disponível";
        }else{
            return " indisponível ";
        }
    }

    // setters
    public void setTitulo(String novoTitulo){
        if(novoTitulo != null && !novoTitulo.trim().isEmpty()){
            this.titulo = novoTitulo;
        }else{
            System.out.println("Entrada de String inválida!");
            return;
        }
    }

    public void setAutor(String novoAutor){
        if(novoAutor != null && !novoAutor.trim().isEmpty()){
            this.autor = novoAutor;
        }else{
            System.out.println("Entrada de String inválida!");
            return;
        }
    }

    public void setAno(int novoAno){
        if(novoAno >= 1700){
            this.ano_de_lancamento = novoAno;
        }else{
            this.ano_de_lancamento = 1700;
        }
    }

}
