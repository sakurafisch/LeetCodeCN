impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if needle.len() == 0 {
            return 0;
        }
        for i in 0..haystack.len() - needle.len() + 1 {
            let mut matched: bool = true;
            for j in 0..needle.len() {
                if i + j > haystack.len() {
                    return -1;
                }
                if haystack.chars().nth(i + j) != needle.chars().nth(j) {
                    matched = false;
                    break;
                }
            }
            if matched {
                return i as i32;
            }
        }
        return -1;
    }
}
