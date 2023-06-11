/*
 * Exercise 2:
    Write a Java program that displays your first name and second name on two lines using a
    single print statement. First name should be on line 1 and surname should be on line 2. Use
    print statement only once.

 */
import java.util.Scanner;

public class Exercise2{
    public static void main(String[] args) {
        try (
        Scanner input = new Scanner(System.in)){
            String name = input.next(); // Input first name
            String SurName = input.next(); // Input Surname
            System.out.print(name + " \n" + SurName); // Printing first name and second name on two lines
        }
    }
}
/*--------------------------------- Exercise2 --------------------------------------*/