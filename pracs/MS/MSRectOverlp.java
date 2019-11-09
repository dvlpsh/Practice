//author : dvlpsh

import java.io.*;
import java.util.*;

class Point
{
	int x,y;
	
	Point(int a, int b)
	{
		x=a;
		y=b;
	}
}

public class MSRectOverlp
{
	public boolean overlap(Point l1,Point r1, Point l2, Point r2)
	{
		if(l2.x>r1.x || l1.x>r2.x)
			return false;
		
		else if(r1.y>l2.y || r2.y>l1.y)
			return false;
			
		return true;
	}
	

	public static void main(String args[])throws IOException
	{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		//define 4 point objects, l1,r1, l2,r2
		String []s=br.readLine().split(" ");
		
		Point l1 = new Point(Integer.parseInt(s[0]),Integer.parseInt(s[1]));
		Point r1 = new Point(Integer.parseInt(s[2]),Integer.parseInt(s[3]));
		Point l2 = new Point(Integer.parseInt(s[4]),Integer.parseInt(s[5]));
		Point r2 = new Point(Integer.parseInt(s[6]),Integer.parseInt(s[7]));
		
		System.out.println(new MSRectOverlp().overlap(l1,r1,l2,r2));
	
	}
}
