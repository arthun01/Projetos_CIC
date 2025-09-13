package Data;

public class usaData{
    public static void main(String[] args){
        Data niver = new Data(26, 12, 2005);
        Data data1 = new Data(2025);

        System.out.printf("Meu Aniversário: %d/%d/%d\n", niver.getDia(), niver.getMes(), niver.getAno());
        System.out.printf("Data Aleatória: %d/%d/%d\n", data1.getDia(), data1.getMes(), data1.getAno());
    }
}