
using System;

class Solution
{
    static void Main()
    {
        string[] numbers = Console.ReadLine().Split(' ');        
        int n = int.Parse(numbers[0]);
        int m = int.Parse(numbers[1]);

        int[,] a = new int[n+1,m+1];
        for(int i=1; i<=n; ++i) {
            string str = Console.ReadLine();        
            for (int j=1; j<=m; ++j) {
                a[i,j] = str[j-1] - '0';
            }
        }

        int ans = 0;
        for(int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                ans += 4*a[i,j]-2*(Math.Min(a[i,j], a[i-1,j])+Math.Min(a[i,j], a[i,j-1]));
                if (a[i, j] > 0) ans += 2;
            }
        }
        Console.WriteLine(ans);
    }
}
