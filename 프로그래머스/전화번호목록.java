import java.util.Arrays;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book);
        for(int i=0, len=phone_book.length; i<len-1; i++){
            int len1 = phone_book[i].length();
            int len2 = phone_book[i+1].length();
            if(len2<=len1) continue;
            if(phone_book[i+1].substring(0, len1).equals(phone_book[i])) return false; 
            
        }
        
        return true;
    }
}