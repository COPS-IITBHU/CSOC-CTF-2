import java.util.Scanner;
import java.lang.Thread;
import java.io.*;

public class J0R2
{
	//csoc{But_0__0_7h1s_71me_1_3nCrypt3d_3v3ry_7h1ng}    D@mn_7h1s_m@st3r_k3y_1z_s000000oooop3r_l000000ng     48
	//name : Ultr0n                    mister  					6
	//pass : m33tM3AtS0k0v1a           rossielikescats  15
	static char[] secure_data={};
	static Scanner sc;
	public static void main(String[] args) 
	{
		String name;
		String pass;
		sc = new Scanner(System.in);
		//test();
		
		System.out.println("Welcome to JOR\f v2.0- Java ObsfucatoR website by Stark Industries");
		System.out.println("This time it is Ultra Secure!");
		Sleep_c(2000);
		System.out.println("\n\nPlease Signup to use the facility.");
		Sleep_c(1000);
		System.out.println("If you are already registered then Login below to continue\n\n");
		
		System.out.print("Username : ");
		name = sc.nextLine();		
		System.out.print("Password : ");
		pass = sc.nextLine();
		
	
		if(obfuscate(name,0).equals("mister") && obfuscate(pass,1).equals("rossielikescats"))
		{
			System.out.println("Logged in!\n\n");
			while(true)
			{
				System.out.println("What do u want to do?");
				System.out.println("1.Make new Entry");
				System.out.println("2.Extract Entry");
				System.out.println("3.Exit()");
				int ch=sc.nextInt();			
				handleEntry(ch);
			}
		}
		else
		{
			System.out.println("\n\nService not available");
			System.out.println("Please Try again later.");
		}
		System.out.println("\n\nHope you have a good day :D");
	}
	public static void handleEntry(int choice)
	{
		switch(choice)
		{
			case 1:
			System.out.print("Enter Text Data : ");			
			String text=sc.nextLine();
			if(text.length()==0)
				text=sc.nextLine();
			
			String st="";
			if(secure_data.length>0)
				st+=new String(secure_data);
			
			
			System.out.print("\n\nYamete!");
			Sleep_c(500);
			System.out.print("\nEnter your super secret master key(flag) :");
			String flag=sc.nextLine();
			if(obfuscate(flag,3).equals("D@mn_7h1s_m@st3r_k3y_1z_s000000oooop3r_l000000ng"))
			{
				st+=new String(obfuscate(text,3));
				secure_data = st.toCharArray();
				
				System.out.println("Successfully Stored.\n\n");
			}
			else
			{
				System.out.println("\nYeeboi\nNot so easy!");
				System.out.println("Please Try again\n\n");
			}
			break;
			
			case 2:
			System.out.println("Extracting Contents....\n");
			Sleep_c(500);
			System.out.println("Ah sorry!\n");
			System.out.println("Someone removed this feature!!!!\n");
			System.out.println("You are on your own now :p \n\n");
			//String data=deobsfuscate(new String(secure_data));
			//System.out.println("Data : "+data);			
			break;
			
			case 3:
			System.out.println("Exiting Vault...\n");
			System.out.println("\n\nHope you have a good day :D");
			System.exit(0);
			break;
			
			default:
			System.out.println("Wrong Choice!");
			System.out.println("Please Try again later.");
		}
		Sleep_c(1000);
	}
	
	public static String obfuscate(String data,int type)
	{
		String hidden = "";		
		for (int i = 0; i < data.length(); i++)
			if (i % 2 == 0)
				hidden += (char) (data.charAt(i) + 3 * (i / 2));
			else
				hidden += data.charAt(i);		
		
		//return hidden;
		return fix_me(hidden.toCharArray(),type);
	
	}
	public static String fix_me(char[] data,int type)
	{
		int[] adj;
		if(type==0)
		{
			adj=new int[]{24,-3,-4,2,47,4};
		}
		else if(type==1)
		{
			adj=new int[]{5,60,61,-1,22,
									50,34,-11,12,53,
										-7,51,-39,67,-3};
		}
		else
		{
			adj=new int[]{-31,-51,-5,11,-34,-11,-22,-67,8,47,-1,-31,
										49,21,-25,10,22,-8,-71,66,16,-60,-12,0,
										30,-47,-42,-62,-61,-66,-118,-1,-53,60,-40,17,
										-54,-4,-13,-6,-133,-47,-70,-56,-67,-62,-62,-22,};
										
		}	
		String st = "";
		int len= (adj.length < data.length)? adj.length :data.length;
		for (int i = 0; i < len; i++)
			st += (char) (data[i] + adj[i]);
		return st;
	}
	public static void Sleep_c(int delay)
	{
		try
		{
			Thread.sleep(delay);
		}
		 catch (Exception e)
		 {
			System.out.println(e);
     }
		
	}
}