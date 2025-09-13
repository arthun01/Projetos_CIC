package Temperatura;

public class Temperatura{
    private float temperatura;

    public Temperatura(float temperatura){
        this.temperatura = temperatura;
    }

    public float getTemperatura(){
        return this.temperatura;
    }

    public void setTemperatura(float novaTemperatura){
        this.temperatura = novaTemperatura;
    }

    public static float converter_celsius_para_fahrenheit(float celsius){
        return ((celsius * 1.8f) + 32);
    }
}