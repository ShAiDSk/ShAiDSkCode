/*
 * Exercise 1:
    Write a Java program that displays your first name and second name on one line using two
    print statements. First print statement will print your first name and second print statement
    will print surname, but the two names must be printed in the output on the same line.
 */
import java.util.Scanner;

public class Exercise1{
    public static void main(String[] args) {
        try (
        Scanner input = new Scanner(System.in)){
            String name = input.next(); // Input first name
            String SurName = input.next(); // Input Surname
            System.out.print(name + ' '); // printing First name
            System.out.print(SurName); // printing Surname
        }
    }
}
/*--------------------------------- Exercise1 --------------------------------------*/