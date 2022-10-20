class Solution {
public:
    string intToRoman(int num) {
        vector<string> s{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> n{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string res = "";
        for(int i=s.size()-1; i>=0; i--){
            int val = num/n[i];
            num = num%n[i];
            while(val--)
                res += s[i];
            if(num==0)
                break;
        }
        return res;
    }
};