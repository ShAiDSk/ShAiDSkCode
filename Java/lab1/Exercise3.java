/*
* Exercise 3:
    Write a Java program that calculates the area of a triangle. The program must declare three
    variables, base, perpendicular and area. The base and perpendicular have values 2.5 and 3.0
    respectively. Area is 1/2*base*perpendicular. The program must print Area at the output.
 */
import java.util.*;

public class Exercise3{
    public static void main(String[] args) {
        // Scanner fs = new Scanner(System.in);
        // declared three variables, base, perpendicular and area.
        double base = 2.5;
        double perpendicular = 3.0;
        double area = (base * perpendicular) / 2;
        System.out.println(area); // printing the area of a triangle.
    }
}
/*--------------------------------- Exercise3 --------------------------------------*/