'''
    This program creates unique passwords with given character value. For example if user wants to use a 5-digit password they can determine it in program.
    This program does not have a save option.
'''
import java.util.Scanner;
import java.util.Random;
public class generator
{
    public static void main(String[] args) {
        Random ranVal=new Random(); //Random values for random char values
        Scanner inVal=new Scanner(System.in);
        int digit;  //Number off characters to be used in password
        char charVal;
        do{
        System.out.print("Please enter how many digits you want: "); 
        digit=inVal.nextInt();
        for(int i=0;i<digit;i++)
        {
            int randVal=32+ranVal.nextInt(123-33);
            if (randVal<33||randVal>122) //This interval is wider than C++ version of this program
            randVal=65; //This is slacking off
            charVal=(char)randVal;  //Conversion
            System.out.print(charVal);
        }
        System.out.println(" ");}while(check());
    }    
    public static boolean check()   //Checking if the user wants to continue
    {
        char question;
        Scanner inVal1=new Scanner(System.in);
        System.out.print("Would you like to use this program again?(Y/N) ");
        question=inVal1.next().charAt(0);
        if(question=='y')
        {
            System.out.println(" ");
            return true;
        }
        return false;
    }
}