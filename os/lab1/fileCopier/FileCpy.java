import java.io.*;
import java.util.Scanner;

class FileCpy{


	public static void main(String args[])
	{	
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the Source path");
		String s=scan.nextLine();
		System.out.println("Enter the destination path");
		String d=scan.nextLine();
		File src=new File(s);
		File dest=new File(d);

		FileInputStream i =null;
		FileOutputStream o =null;

		try{

			i=new FileInputStream(src);
			o=new FileOutputStream(dest);

			// byte[] buffer=new byte[1024];

			// int length;

			// while((length =i.read(buffer))!= -1)
			// 	o.write(buffer,0,length);
			int buffer=i.read();
			while(buffer!=-1)
				{o.write(buffer);
				buffer=i.read();}

		}
		catch(IOException e)
		{
			e.printStackTrace();

		}
		finally
		{	
			try{
			i.close();
			o.close();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}

			System.out.println("Success");
		}
		
	}
}