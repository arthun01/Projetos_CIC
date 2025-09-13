package Filme;

public class usaFilme{
    public static void main(String[] args){
        // declarando o array de filmes
        Filme[] filmes = new Filme[3];

        filmes[0] = new Filme("Homem de Ferro", "Jon Favreau", 126);
        filmes[1] = new Filme("Homem de Ferro 2", "Jon Favreau", 124);
        filmes[2] = new Filme("Homem de Ferro 3", "Shane Black", 130);

        for(int i = 0; i < 3; i++){
            if(filmes[i].getDuracao() > 120){
                System.out.println("Filme " + (i + 1) + ": " + filmes[i].getTitulo());
            }
        }

    }
}