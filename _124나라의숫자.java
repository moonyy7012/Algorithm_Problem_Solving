class _124나라의숫자 {
    int mod124[] = {4, 1, 2};
    public String solution(int n) {
        StringBuilder answer = new StringBuilder();
        while(n!=0){
            int mod = n%3;
            n/=3;
            if(mod==0) n--;
            answer.append((char)('0'+mod124[mod]));
        }
        
        answer.reverse();
        
        return answer.toString();
    }
}