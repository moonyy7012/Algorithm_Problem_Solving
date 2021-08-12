//SW Expert Academy
//[S/W 문제해결 기본] 3일차 - String
import java.util.Scanner;

public class String_1213 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i=1; i<=10; i++) {
			int cnt=0;
			sc.nextLine();
			String s = sc.nextLine();
			String lg = sc.nextLine();
			for(int j=0; j<=lg.length()-s.length(); j++) {
				if(lg.charAt(j)==s.charAt(0)) {
					boolean isEqual = true;
					for(int k=0; k<s.length(); k++) {
						if(lg.charAt(j+k)!=s.charAt(k)) {isEqual=false; break;}
					}
					if(isEqual) {
						cnt++;
						j+=(s.length()-1);
					}
					
				}
			}
			System.out.println("#"+i+" "+cnt);
		}
	}

}
