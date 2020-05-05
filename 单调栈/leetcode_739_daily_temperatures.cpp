#include <stack>
#include <vector>
using namespace std;

// ����һ:�������,ѹջ֮ǰ����
class Solution_1 {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int len = T.size();
        vector<int> res(len, 0);
        stack<int> st;

        // ����ѹջ ά���ݼ�ջ
        for (int i = len - 1; i >= 0; --i) {
            while (st.empty() == false) {
                if (T[st.top()] > T[i]) {
                    res[i] = st.top() - i;
                    break;
                } else {
                    st.pop();
                }
            }

            // ��ǰԪ��û���ҵ���������ֵ,��ֵΪ0
            if (st.empty() == true) {
                res[i] = 0;
            }

            st.push(i);
        }

        return res;
    }
};

// ������: ˳�����,��ջ֮ǰ����
class Solution_2 {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int len = T.size();
        vector<int> res(len, 0);
        stack<int> st;

        // ˳��ѹջ
        for (int i = 0; i < len; ++i) {
            while (st.empty() == false) {
                if (T[st.top()] >= T[i]) {
                    break;
                } else {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
            }
            st.push(i);
        }

        // ֮�󶼲������ߵ�����
        for (int j = 0; j < st.size(); ++j) {
            res[st.top()] = 0;
            st.pop();
        }

        return res;
    }
};
