import java.util.*;

public class Main
{
	public static void main(String[] args) 
	{
	    Scanner sc=new Scanner(System.in);
	    int n;
		System.out.println("enter the Number of denominations : ");
		n=sc.nextInt();
		int deno[]=new int[n];
		for(int i=0;i<n;i++)
		{
		    deno[i]=sc.nextInt();
		}
		Arrays.sort(deno);
		for (int i = 0; i < n / 2; i++) 
		{
          int temp = deno[i];
          deno[i] = deno[n - 1 - i];
          deno[n - 1 - i] = temp;
        }
        int count=0;
        int noofc[]=new int[n];
        int amount;
        System.out.println("enter the amount : ");
		amount=sc.nextInt();
		for(int i=0;i<n;i++)
		{
		    if(deno[i]<=amount)
		    {
		        noofc[i]=amount/deno[i];
		        amount=amount%deno[i];
		    }
		}
		System.out.println("the number of coins needed are : ");
		for(int i=0;i<n;i++)
		{
		    System.out.print("("+deno[i]+","+noofc[i]+")  ");
		}

	}
}

