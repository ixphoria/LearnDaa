import java.util.*;

public class Main
{
    static void load(int c,int n,int w[])
    {
        int count=0,i=0;
        Arrays.sort(w);
        while(i<n && w[i]<=c)
        {
            count++;
            i++;
            c=c-w[i];
        }
        
        System.out.println(count+"containers can be loaded");
}
	public static void main(String[] args) 
	{
	    Scanner sc=new Scanner(System.in);
		System.out.println("enter the capacity of cargo ship : ");
		int c=sc.nextInt();
		System.out.println("enter the number of containers : ");
		int n=sc.nextInt();
		int w[]=new int[n];
		System.out.println("enter the weights of containers : ");
		for(int i=0;i<n;i++)
		w[i]=sc.nextInt();
		
		load(c,n,w);
	}
}

