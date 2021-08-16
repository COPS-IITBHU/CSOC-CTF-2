import java.util.Scanner;
import java.lang.Thread;
import java.io.*;

public class J0R 
{
	//csoc{5t0r1n9_cr3dent1@l5_1n_@_pr0gr@m_15_@_51n}
	static char[] secure_data={283 , 242 , 242 , 180 , 180 , 274 , 255 , 264 , 255 , 265 , 
											186 , 247 , 259 , 186 ,	246 , 245 , 268 , 255 , 246 , 259 , 186 , 
											252 , 246 , 251 , 253 , 208 , 249 , 265 , 245 , 249 ,257 , 207 , 
											270 , 202 , 264 , 203 , 244 , 195 , 293 , 249 , 264 , 201 , 254 , 
											255 , 244 , 270 ,203 , 282 , 246 , 207 , 293 , 203 , 244 , 293 , 
											282 , 293 , 266 ,264 , 202 , 253 , 264 , 282 , 247 , 293 , 203 ,
											207 , 293 , 282 , 293 , 207 , 203 , 244 , 263};
	static Scanner sc;
	public static void main(String[] args) 
	{
		String name;
		String pass;
		sc = new Scanner(System.in);
		//test();
		System.out.println("Welcome to JOR - Java ObsfucatoR website by Stark Industries");
		System.out.println("It can keep your data absolutely safe.");
		Sleep_c(2000);
		System.out.println("\n\nPlease Signup to use the facility.");
		Sleep_c(2000);
		System.out.println("If you are already registered then Login below to continue\n\n");
		
		System.out.print("Username : ");
		name = sc.nextLine();		
		System.out.print("Password : ");
		pass = sc.nextLine();
		
		
		if(name.equals("J0Rvis") && pass.equals("luvyouthreethousand"))
		{
			System.out.println("Logged in!\n\n");
			System.out.println("What do u want to do?");
			System.out.println("1.Make new Entry");
			System.out.println("2.Extract Entry");
			int ch=sc.nextInt();			
			handleEntry(ch);
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
			
			st+=new String(obfuscate(text));
			secure_data = st.toCharArray();
			
			System.out.println("Successfully Stored");
			break;
			
			case 2:
			System.out.println("Extracting Contents....\n");
			String data=deobsfuscate(new String(secure_data));
			System.out.println("Data : "+data);			
			break;
			
			default:
			System.out.println("Wrong Choice!");
			System.out.println("Please Try again later.");
		}
	}
	public static char[] obfuscate(String data)
	{
		//byte[] hidden;
		String hidden="";
		//System.out.println("Encoding String : "+ data);
		for (int i = 0; i < data.length(); i++)		
			hidden+=(char)((data.charAt(i)^ 0xAA)+48);
	
		return hidden.toCharArray();
	}
	public static String deobsfuscate(String data)
	{
		//System.out.println("Decoding : "+ data);
		String extract="";
		for (int i = 0; i < data.length(); i++)		
		{
			extract += (char)((data.charAt(i) -48)^0xAA);
			//System.out.print(extract.charAt(i));
		}
	
		return extract;
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
	public static void test()
	{
		String test="Ahh..Heres my lovely flag\n";
		String test2="csoc{5t0r1n9_cr3dent1@l5_1n_@_pr0gr@m_15_@_51n}";
		
		String output=new String(obfuscate(test));
		output=output+ (new String(obfuscate(test2)));
		String data=deobsfuscate(new String(secure_data));
		
		//for (int i = 0; i < output.length(); i++)				
		//	System.out.print((short)output.charAt(i) + " , ");
		
		System.out.println(data);
		System.exit(0);
	}

}