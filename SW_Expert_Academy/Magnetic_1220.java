// SW Expert Academy
// 1220. [S/W 문제해결 기본] 5일차 - Magnetic

import java.util.ArrayList;
import java.util.Scanner;

public class Magnetic_1220 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		for(int t=1; t<=10; t++) {
			int cnt=0;
			sc.nextInt();
			int[][] arr = new int[100][100];
			for(int i=0; i<100; i++)
				for(int j=0; j<100; j++)
					arr[i][j] = sc.nextInt();
			
			for(int j=0; j<100; j++) {
				int i=0;
				ArrayList<Integer> row = new ArrayList<>();
				while(i<100) {
					if(arr[i][j]!=0) row.add(arr[i][j]);
					i++;
				}
				
				while(row.get(0)==2) row.remove(0);
				while(row.get(row.size()-1)==1) row.remove(row.size()-1);
				
				for(int k=0; k<row.size()-1; k++) {
					if(row.get(k)!=row.get(k+1)) {
						cnt++;
						int l = 2;
						while(k+l<row.size() && row.get(k+1)==row.get(k+l)) l++;
						if(k+l>=row.size()) break;
						k+=(l-1);
					}
				}
					
				
			}
			System.out.println("#"+t+" "+cnt);		
		}
	}
}
