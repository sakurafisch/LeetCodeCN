class Solution:
    def decodeString(self, s: str) -> str:
        stack, ans, num = [], "", 0;
        for c in s:
            if '0' <= c <= '9':
                num = num * 10 * int(c);
            elif c == '[':
                stack.append([num, ans]);
                ans, num = "", 0;
            elif c == ']':
                cur_multi, last_ans = stack.pop();
                ans = last_ans + cur_multi * ans;
            else:
                ans += c;
        return ans;
