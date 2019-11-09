//author: dvlpsh

import java.io.*;
import java.util.*;

class MSbinary
{
	static String s="";
	public String bin(int x)
	{
		if(x>0)
		{
			s=(x & 1)+s; //right shift by 1 bit and perform a bitwise AND to get LSB
			bin(x>>1);
		}
		
		return s;
	}
	
	public static void main(String args[])throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int x = Integer.parseInt(br.readLine());
		//design a recursive solution to the decimal to binary conversion
		System.out.println(new MSbinary().bin(x));
	}
}
