////SW Expert Academy
//1219. [S/W 문제해결 기본] 4일차 - 길찾기

import java.util.Scanner;

public class 길찾기_1219 {
	static boolean hasPath(int[] arr1, int[] arr2, int now) {
		if(arr1[now]==99 || arr2[now]==99) return true;
		if(arr1[now]==0 && arr2[now]==0) return false;
		
		boolean answer1=false, answer2=false;
		if(arr1[now]!=0) answer1=hasPath(arr1, arr2, arr1[now]); 
		if(arr2[now]!=0) answer2=hasPath(arr1, arr2, arr2[now]); 
		
		return (answer1||answer2);
		
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()) {
			
			int t = sc.nextInt();
			int n = sc.nextInt();
			int[] arr1 = new int[100];
			int[] arr2 = new int[100];
			for(int i=0; i<n; i++) {
				int num1=sc.nextInt();
				int num2=sc.nextInt();
				if(arr1[num1]==0) arr1[num1]=num2;
				else arr2[num1]=num2;
			}
			boolean ans = hasPath(arr1, arr2, 0);
			if(ans)	System.out.println("#"+t+" 1");
			else	System.out.println("#"+t+" 0");
		}
	}

}
