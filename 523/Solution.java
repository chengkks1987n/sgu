import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] argv) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int f = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(in.readLine());
		int[] e = new int[n + 1];
		int[] v = new int[101];
		int[] s = new int[n + 1];
		v[f] = 1;
		s[0] = e[0] = f;
		for (int i = 1; i <= n; ++i) {
			s[i] = e[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(s);
		int k = Arrays.binarySearch(s, e[0]);
		int to = 1;
		while (to <= n) {
			int direction = 1;
			if (s[k] > e[to]) {
				direction = -1;					
			}
			while (s[k]!=e[to]) {
				k += direction;
				if (k <= n && k >= 0 && v[s[k]] == 0) {
					System.out.print(s[k] + " ");
					v[s[k]] = 1;
				}
			}
			while(to<=n && v[e[to]]==1) ++to;
		}
	}
}
