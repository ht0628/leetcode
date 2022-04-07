#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //6.Z字形变换
    string convert(string s, int numRows) {
        if(numRows <= 1){
            return s;
        }
        vector<string> res(numRows,"");
        int flag = -1;
        int i = 0;
        for(char c:s){
            if(i==0 || i==numRows-1){
                flag = -flag;
            }
            res[i] += c;
            i += flag;
        }
        string tmp = "";
        for(auto r:res){
            tmp += r;
        }
        return tmp;
    }

    //7.整数反转
    int reverse(int x) {
        int res = 0;
        int sign = (x<0)?-1:1;
        while(x){
            int tmp = abs(x) % 10;
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp > INT_MAX % 10)){
                return 0;
            }
            if(res < INT_MIN / 10 || (res == INT_MIN / 10 && tmp > -(INT16_MIN % 10))){
                return 0;
            }
            x = abs(x) / 10;
            res = res*10 + sign * tmp;
        }
        return res;
    }

    //8.字符串转换整数(atoi)
    int myAtoi(string s) {
        //去除前导空格
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if(i == s.size()){
            return 0;
        }

        //处理第一个符号
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            sign = 1;
            i++;
        }
        
        //获取最终结果
        int res = 0;
        while(i < s.size()){
            if(s[i] > '9' || s[i] < '0'){
                break;
            }
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return INT_MAX;
            }
            if(res < INT_MIN / 10 || (res == INT_MIN / 10 && s[i] - '0' > -(INT_MIN % 10))){
                return INT_MIN;
            }
            res = res * 10 + sign * (s[i] - '0');
            i++;
        }
        return res;
    }

    //9.回文数
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int tmp = x;
        int res = 0;
        while(tmp){
            int remainder = tmp % 10;
            tmp /= 10;
            res = res * 10 + remainder;
        } 
        return res == x;
    
    }

    //12.整数转罗马数字
    string intToRoman(int num) {
        string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string res = "";
        for(int i=0; i<sizeof(nums)/sizeof(nums[0]); i++){
            int cnt = num / nums[i];
            while(cnt){
                res += strs[i];
                cnt--;
            }
            num = num % nums[i];
        }
        return res;
    }

    //13.罗马数字转整数
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char,int> m {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        for(int i = 0; i < s.size() - 1; i++){
            int num1 = m[s[i]];
            int num2 = m[s[i+1]];
            if(num1 >= num2){
                res += num1;
            }
            else{
                res -= num1;
            }
        }
        res += m[s[s.size()-1]];
        return res;
    }
};

int main(){
    Solution s = Solution();
    string res1 = s.convert("PAYPALISHIRING",3);
    cout << res1 <<endl;

    int res2 = s.myAtoi("42");
    cout << res2 << endl;

    string res3 = s.intToRoman(1994);
    cout << res3 << endl;

    int res4 = s.reverse(-123);
    cout << res4 << endl;

    int res5 = s.romanToInt("III");
    cout << res5 << endl;

    bool res6 = s.isPalindrome(1234567899);
    cout << res6 << endl;
}
