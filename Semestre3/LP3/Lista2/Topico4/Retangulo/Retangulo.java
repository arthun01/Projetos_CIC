package Retangulo;

public class Retangulo{
    // atributos
    private float largura;
    private float altura;

    // construtores
    public Retangulo(float largura, float altura){
        if(largura > 0f && altura > 0f){
            this.largura = largura;
            this.altura = altura;
        }else{
            this.largura = 1f;
            this.altura = 1f;
        }
    }

    // getters
    public float getLargura(){
        return this.largura;
    }

    public float getAltura(){
        return this.altura;
    }

    // setters
    public void setLargura(float novaLargura){
        if(novaLargura > 0f){
            this.largura = novaLargura;
        }
    }

    public void setAltura(float novaAltura){
        if(novaAltura > 0f){
            this.altura = novaAltura;
        }
    }

    public float calcular_area(){
        float area = (this.largura * this.altura);
        return area;
    }
}