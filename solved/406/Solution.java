import java.util.*;
import java.io.*;

public class Solution 
{
  public static void main (String[] argv) throws IOException
  {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st = new StringTokenizer(in.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    
    //input the sequences in Goggle database.
    int[][] k = new int[20][200];
    int[][] s = new int[20][200];    
    for (int i=0; i<n; ++i) {
    	st = new StringTokenizer(in.readLine());
    	k[i][0] = Integer.parseInt(st.nextToken());
    	for (int j=1; j<=k[i][0]; ++j) {
    		k[i][j] = Integer.parseInt(st.nextToken());
    		s[i][k[i][j]] = 1;
    	}
    }
    
    for(;m>0;--m){
    	//input one query
    	int[] t = new int[20];
    	st = new StringTokenizer(in.readLine());
    	t[0] = Integer.parseInt(st.nextToken());
    	for (int j=1; j<=t[0]; ++j) {
    		t[j] = Integer.parseInt(st.nextToken());
    	}
    	
    	//solve
    	int[] ans = new int[20];
    	for (int i=0; i<n; ++i){    		
    		boolean match = true;
    		for(int j=1;j<=t[0];++j){    			
    			int sign = 0;
    			if (t[j] > 0) {
    				sign = 1;
    			}
    			if(s[i][Math.abs(t[j])] != sign){
    				match = false;
    				break;
    			}    			
    		}
    		if (match){
    			++ans[0];
    			ans[ans[0]] = i;
    		}
    	}
    	
    	//out put the result
    	System.out.println(ans[0]);
    	for (int i=1; i<=ans[0]; ++i) {
    		for (int j=0; j<=k[ans[i]][0]; ++j){
    			System.out.print(k[ans[i]][j] + " ");
    		}
    		System.out.println();
    	}    	
    }         
  }   
}
