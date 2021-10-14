////SW Expert Academy
//1218. [S/W 문제해결 기본] 4일차 - 괄호 짝짓기

import java.util.Scanner;

public class 괄호짝짓기_1218 {
	static boolean isPair(char[] br, int n) {
		char stack[] = new char[n];
		int idx=-1;
		for(int i=0; i<n; i++) {
			if(br[i]=='(' || br[i]=='[' || br[i]=='{' || br[i]=='<') {
				idx++;
				stack[idx]=br[i];
			}else {
				char t='\0';
				if(br[i]==')') t='(';
				else if(br[i]==']') t='[';
				else if(br[i]=='}') t='{';
				else if(br[i]=='>') t='<';
				
				if(stack[idx]!=t) return false;
				idx--;
				
			}
			
		}
		if(idx!=-1)return false;
		
		return true;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int t=1; t<=10; t++) {
			int n = Integer.parseInt(sc.nextLine());
			char br[] = new char[n];
			br=sc.nextLine().toCharArray();
			int ans = 0;
			if(isPair(br, n)) ans=1;
			else ans=0;
			
			System.out.println("#"+t+" "+ans);
			
			
			
		}
	}
}
