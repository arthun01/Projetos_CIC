public class RoteiroPromocional extends Roteiro{
    private double percentualDesconto;

    public RoteiroPromocional(String nome, double duracao, double percentualDesconto){
        super(nome, duracao);
        this.percentualDesconto = percentualDesconto;
    }

    @Override

    public void exibirDetalhes(){
        super.exibirDetalhes();

        System.out.println("    *** Oferta Especial: " + percentualDesconto + "% de desconto aplicado");
    }

    public double calcularPrecoPromocional(double precoBase){
        double desconto = precoBase * (percentualDesconto / 100);
        return precoBase - desconto;
    }
}