//SW Expert Academy
//1215. [S/W 문제해결 기본] 3일차 - 회문1


import java.util.ArrayList;
import java.util.Scanner;

public class 회문1_1215 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i=1; i<=10; i++) {
			int cnt=0;
			int n = Integer.parseInt(sc.nextLine());
			String[] arr = new String[8];
			for(int j=0; j<8; j++) {
				String s = sc.nextLine();
				arr[j]=s;
			}
//			가로 검색
			for(int y=0; y<8; y++) {
				ArrayList<Character> ch = new ArrayList<>();
				for(int j=0; j<n; j++)
					ch.add(arr[y].charAt(j));
				
				boolean isEqual=true;
				for(int j=0; j<n/2; j++)
					if(ch.get(j)!=ch.get(n-1-j)) {isEqual=false; break;}
				
				if(isEqual) cnt++;
				for(int j=n; j<8; j++) {
					ch.remove(0);
					ch.add(arr[y].charAt(j));
					isEqual=true;
					for(int k=0; k<n/2; k++)
						if(ch.get(k)!=ch.get(n-1-k)) {isEqual=false; break;}
					
					if(isEqual) cnt++;
					
				}
					
			}
//			세로검색
			for(int x=0; x<8; x++) {
				ArrayList<Character> ch = new ArrayList<>();
				for(int j=0; j<n; j++)
					ch.add(arr[j].charAt(x));
				
				boolean isEqual=true;
				for(int j=0; j<n/2; j++)
					if(ch.get(j)!=ch.get(n-1-j)) {isEqual=false; break;}
				
				if(isEqual) cnt++;
				for(int j=n; j<8; j++) {
					ch.remove(0);
					ch.add(arr[j].charAt(x));
					isEqual=true;
					for(int k=0; k<n/2; k++)
						if(ch.get(k)!=ch.get(n-1-k)) {isEqual=false; break;}
					
					if(isEqual) cnt++;
					
				}
				
			}
			System.out.println("#"+i+" "+cnt);
			
			
		}
	}
}
