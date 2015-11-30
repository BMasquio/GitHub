//Anderson Zudio
//Victor Cracel
//Bruno Masquio

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;


class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int n;
		BigInteger M[] = new BigInteger[90000];
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String newLine = in.readLine(), s1, s2;
		n = Integer.parseInt(newLine);
		for(int k = 0; k < n; k++)
		{
			for(int i = 1; i < 90000; i++)
				M[i] = BigInteger.ZERO;
			
			
		
			
			M[0] = BigInteger.ONE;
			
			
	//		System.out.println(BigInteger.ONE);
			
			
			newLine = in.readLine();
			s1 = '0' + newLine;
			
	//		System.out.println(s1);
			
			newLine = in.readLine();
			s2 = '0' + newLine;
			
	//		System.out.println(s2);
			
			for(int i = 1; i < s1.length(); i++)
			{
				for(int j = s2.length() - 1; j > 0; j--)
				{
					if(s1.charAt(i) == s2.charAt(j)){ M[j] = M[j].add(M[j-1]);
		//			System.out.println(M[0]);
		//			System.out.println("viado");
					}
				}
			}
			
			System.out.println(M[s2.length()-1]);
			
		}
	}
}