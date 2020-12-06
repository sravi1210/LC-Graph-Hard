/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    bool solve(vector<int> &nums, char opt1, char opt2, char opt3){
        vector<int> a;
        a.push_back(nums[0]);
        a.push_back(1);
        vector<int> b;
        b.push_back(nums[1]);
        b.push_back(1);
        vector<int> c;
        c.push_back(nums[2]);
        c.push_back(1);
        vector<int> d;
        d.push_back(nums[3]);
        d.push_back(1);
        
        
        vector<int> ans = solve(a,solve(b, solve(c,d, opt3), opt2),opt1);  //a+(b+(c+d))
        if(ans[1] != 0 && ans[0]%ans[1] == 0){
            if(ans[0]/ans[1] == 24){
                return true;
            }
        }
        
        ans.clear();
        ans = solve(a, solve(solve(b, c, opt2), d, opt3), opt1); //a+((b+c)+d)
        if(ans[1] != 0 && ans[0]%ans[1] == 0){
            if(ans[0]/ans[1] == 24){
                return true;
            }
        }
        
        ans.clear();
        ans = solve(solve(a,b,opt1), solve(c,d,opt3), opt2); //(a+b)+(c+d)
        if(ans[1] != 0 && ans[0]%ans[1] == 0){
            if(ans[0]/ans[1] == 24){
                return true;
            }
        }
        
        ans.clear();
        ans = solve(solve(solve(a, b, opt1), c, opt2), d, opt3); //((a+b)+c)+d
        if(ans[1] != 0 && ans[0]%ans[1] == 0){
            if(ans[0]/ans[1] == 24){
                return true;
            }
        }
        
        ans.clear();
        ans = solve(solve(a, solve(b, c, opt2), opt1), d, opt3); //(a+(b+c))+d
        if(ans[1] != 0 && ans[0]%ans[1] == 0){
            if(ans[0]/ans[1] == 24){
                return true;
            }
        }
        
        return false;
    }
    vector<int> solve(vector<int> num1, vector<int> num2, char opt){
        vector<int> ret;
        int num = num1[0];
        int den = num1[1];
        int tnum = num2[0];
        int tden = num2[1];
        if((tnum==0 && tden==0) || (tnum==0 && opt=='/')){
            ret.push_back(0);
            ret.push_back(0);
            return ret;
        }
        switch(opt){
            case '+':
                num = (num*tden) + (tnum*den);
                den *= tden;
                break;
            case '-':
                num = (num*tden) - (tnum*den);
                den *= tden;
                break;
            case '*':
                num *= tnum;
                den *= tden;
                break;
            case '/':
                num *= tden;
                den *= tnum;
                break;
        }
        
        ret.push_back(num);
        ret.push_back(den);
        return ret;
    }
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<char> opt;
        opt.push_back('+');
        opt.push_back('-');
        opt.push_back('*');
        opt.push_back('/');

        do{
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    for(int k=0;k<4;k++){
                        if(solve(nums, opt[i], opt[j], opt[k])){
                            return true;
                        }
                    }
                }
            }
        }while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
};