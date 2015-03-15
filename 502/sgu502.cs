using System;


/// <summary>
/// f[i,r] 表示使用前i+1个数，进行排列，余数为r的一种解。
/// </summary>
class Solution
{
    static void Main()
    {
        string n = Console.ReadLine();        
        string[,] f = new string[20, 20];
                
        f[0, int.Parse(n.Substring(0, 1))] = n.Substring(0, 1);
        for (int i=1; i<n.Length; ++i){
            for (int r = 0; r <= 16; ++r)
            {
                if (!string.IsNullOrEmpty(f[i - 1, r]))
                {
                    for (int j = 0; j <= f[i - 1, r].Length; ++j)
                    {
                        string s = f[i - 1, r].Insert(j, n.Substring(i, 1));
                        f[i, long.Parse(s) % 17] = s;
                    }
                }
            }                      
        }

        string ans = "-1";
        if (!string.IsNullOrEmpty(f[n.Length - 1, 0]))
        {       
            ans = f[n.Length - 1, 0].TrimStart(new char[]{'0'});            
            ans += f[n.Length - 1, 0].Substring(0, f[n.Length - 1, 0].Length - ans.Length);                              
        }
        Console.WriteLine(ans);
    }
}