class Solution {
public:
    int maximumSwap(int num) {
        string temp=to_string(num);
        int l=temp.length();
        int m=-1, left=-1, right=-1;
        for(int i=l-1; i>=0; i--){
            if(m==-1 || temp[i]>temp[m]){
                m = i;
            }
            else if(temp[i]<temp[m]){
                left = i;
                right = m;
            }
        }
        if(left!=-1 && right!=-1){
            swap(temp[left], temp[right]);
        }
        return stoi(temp);
    }
};