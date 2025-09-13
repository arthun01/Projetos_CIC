package Topico3.Triangulo;

public class Triangulo{
    private float base;
    private float altura;

    public Triangulo(float base, float altura){
        this.base = base;
        this.altura = altura;
    }

    public float calcular_area(){
        float area = ((base * altura) / 2f);
        return area;
    }
}