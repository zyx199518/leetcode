#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 反序压递减栈 + hash方法
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> st;
        unordered_map<int, int> map;

        for (int i = nums2.size() - 1; i >= 0; --i) {

            // 保证当前栈压栈之后是递减栈
            while (st.empty() == false) {
                if (st.top() > nums2[i]) {
                    map[nums2[i]] = st.top();
                    break;
                } else {
                    st.pop();
                }
            }

            // 没有找到比nums2[i]大的值
            if (st.empty() == true) {
                map[nums2[i]] = -1;
            }

            st.push(nums2[i]);
        }

        vector<int> res(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = map[nums1[i]];
        }

        return res;
    }
};