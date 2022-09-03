class Solution:
    def convert(self, s: str, numRows: int) -> str:
        t: list[str] = [""] * numRows
        ans: str = ""
        i: int = 0
        while i < len(s):
            for j in range(0, numRows, 1):
                if not i < len(s):
                    break
                t[j] = t[j] + s[i]
                i += 1
            for k in range(numRows-2, 0, -1):
                if not i < len(s):
                    break
                t[k] = t[k] + s[i]
                i += 1
        for x in t:
            ans += x
        return ans
