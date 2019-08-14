import java.util.*;
public class Main {
	static class pair implements Comparable<pair>{
		int marks;
		String name;
		pair(int m, String n){
			this.marks=m;
			this.name=n;
		}
		@Override
		public int compareTo(pair p){
			return p.marks-this.marks;
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String sn = in.nextLine();
		int n = Integer.parseInt(sn);
		pair [] arr = new pair[n];
		for(int i=0; i<n; i++){
			String inp = in.nextLine();
			String [] st = inp.split(" ", 0);
			String name = st[0];
			int marks = Integer.parseInt(st[1]) + Integer.parseInt(st[2]) + Integer.parseInt(st[3]);
			arr[i] = new pair(marks, name);
		}
		Arrays.sort(arr);
		for(int i=0; i<n; i++){
			System.out.println((i+1) + " " + arr[i].name);
		}
	}

}