#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        stack<int> st;

        for (int i = 2 * len - 1; i >= 0; --i) {
            // 保证当前栈在压栈后是递减栈
            while (st.empty() == false) {
                if (st.top() > nums[i % len]) {
                    res[i % len] = st.top();
                    break;
                } else {
                    st.pop();
                }
            }

            // 找不到则赋值为-1 
            if (st.empty() == true) {
                res[i % len] = -1;
            }
            
            st.push(nums[i % len]);
        }

        return res;
    }
};