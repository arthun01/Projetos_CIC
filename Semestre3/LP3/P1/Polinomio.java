public class Polinomio{
    // atributos
    private double[] coeficientes;
    private static int totalPolinomios = 0;

    // construtores
    public Polinomio(int grau){
        coeficientes = new double[grau + 1];
        totalPolinomios++; 
    }

    public Polinomio(double[] coeficientes){
        this.coeficientes = coeficientes.clone();
        totalPolinomios++;
    }

    // ---------------------

    // função avaliar (calcula o valor no ponto)
    public double avaliar(double x){
        double resultado = 0;
        for(int i = 0; i < this.coeficientes.length; i++){
            resultado += coeficientes[i] * Math.pow(x, i);
        }
        return resultado;
    }

    // método para exibir o polinómio
    public void exibir(){
        StringBuilder sb = new StringBuilder();
        for (int i = coeficientes.length - 1; i >= 0; i--){
            if (coeficientes[i] != 0) {
                if (sb.length() > 0 && coeficientes[i] > 0){
                    sb.append(" + ");
                } else if (coeficientes[i] < 0) {
                    sb.append(" - ");
                }

                double valor = Math.abs(coeficientes[i]);
                if (i == 0) {
                    sb.append(valor);
                } else if (i == 1) {
                    sb.append(valor).append("x");
                } else {
                    sb.append(valor).append("x^").append(i);
                }
            }
        }
        System.out.println(sb.toString());
    }

    // getter para o total de polinomios
    public static int getTotalPolinomios(){
        return totalPolinomios;
    }
}