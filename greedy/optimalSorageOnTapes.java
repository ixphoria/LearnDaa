import java .util.*;

public class Main
{
    static void optimal(int l[],int n)
    {

        Arrays.sort(l);
        System.out.println("\noptimal seq :"+n);
	    for(int i=0;i<n;i++)
	    {
	        System.out.print(l[i]+" ");
	    }
        
        
        
        double MRT=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<i;j++)
            {
                sum+=l[i];
            }
            MRT+=sum;
        }
        MRT/=n;
        
        System.out.println("\nMRT : "+MRT);

    }
	public static void main(String[] args)
	{
        int n;
	    System.out.println("Enter  the number of tapes :");
	    Scanner sc = new Scanner(System.in);
	    n=sc.nextInt();
	    int l[]=new int[n];
	    System.out.println("\nEnter the elements of the tape :");
	    for(int i=0;i<n;i++)
	    {
	        l[i]=sc.nextInt();
	    }
	    optimal(l,n);
	}
}

