// Important
import java.util.*;

class Solution
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		while(T>0)
		{
			String s=sc.next();
			int n=s.length();
			char[]ch=s.toCharArray();
			int []freq=new int [26];
			for(char c:ch)
				freq[c-97]++;
			char mid='a';
			int cnt=0;
			for(int i=0;i<26;i++)
				if(freq[i]%2==1)
				{
			     mid=(char)(i+97);		
				 cnt++;
				}

			if(cnt>1)
			System.out.println(-1);
			else
			{
				ArrayList<Integer> adj[]=new ArrayList[26];
				for(int i=0;i<26;i++)
					adj[i]=new ArrayList<>();
				for(int i=0;i<n;i++)
				 adj[ch[i]-97].add(i+1);
				int arr[]=new int[n];

				if(n%2==0)
				{
					int k=0;
					for(int i=0;i<26;i++)
					{
						for(int j=0;j<adj[i].size();j=j+2)
						{
							arr[k]=adj[i].get(j);
							arr[n-1-k]=adj[i].get(j+1);
							k++;
						}
						if(k>=n/2)
							break;
					}
				}

				else
				{
                 int k=0;
                 arr[n/2]=adj[mid-97].get(0);
                 adj[mid-97].remove(0);
                 for(int i=0;i<26;i++)
					{
						for(int j=0;j<adj[i].size();j=j+2)
						{
							arr[k]=adj[i].get(j);
							arr[n-1-k]=adj[i].get(j+1);
							k++;
						}
						if(k>=n/2)
							break;
					}

				}
				for(int i=0;i<n;i++)
					System.out.print(arr[i]+" ");
				System.out.println();
			}

			T--;	  
		}
	}
}