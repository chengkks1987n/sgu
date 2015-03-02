import java.util.*;
import java.io.*;

public class Solution 
{
  public static void main (String[] argv) throws IOException
  {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st = new StringTokenizer(in.readLine());
    int n = Integer.parseInt(st.nextToken());
    int ans = -1;
    if (n==21) {
    	ans = 1;
    }
    else if (n>=30 && 2<=n%14 && n%14<=12) {    	    	
    	ans = n/14;
    }
    System.out.println(ans);
   
  }
   
}
