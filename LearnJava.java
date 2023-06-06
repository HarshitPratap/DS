import java.util.*;

public class LearnJava {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your binary number:- ");
        String input = sc.nextLine();
        int decimal = 0;
        int k = 0;
        for (int i = input.length() - 1; i >= 0; i--) {
            if (input.charAt(i) == '1') {
                decimal += Math.pow(2, k);
            }
            k++;
        }
        System.out.println(decimal);
    }
}
