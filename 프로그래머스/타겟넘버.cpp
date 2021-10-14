#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int> numbers, int val, int depth, const int & target){
    if(depth == numbers.size()){
        return (val == target);
    }
    int ans = 0;
    ans += dfs(numbers, val + numbers[depth], depth + 1, target);
    ans += dfs(numbers, val - numbers[depth], depth + 1, target);
    return ans;
}

int solution(vector<int> numbers, int target) {
    int ans = dfs(numbers, 0, 0, target);
    return ans;
}