import java.util.*;
import java.io.*;

public class Solution 
{
  public static void main (String[] argv) throws IOException
  {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st = new StringTokenizer(in.readLine());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    
   
    int sa = process(a);
    int sb = process(b);
    if (sa > sb){
    	System.out.println('a');
    }
    else {
    	System.out.println('b');
    }
    
  }
  
  private static int process(int n){
	  int p = 0; //最后一个质素因子
	  int s = 0; //所有质数因子之和
	  for (int i=2; i<=n; ) {
		  if (n%i == 0) {
			  if (i!=p) {
				  s += i;
				  p = i;
			  }		
			  n /= i;
		  }
		  else {
			  ++i;
		  }		  
	  }
	  return p + p - s;
  }
  
}
