function strStr(haystack: string, needle: string): number {
    for (let i = 0; i + needle.length <= haystack.length; ++i) {
        let match: boolean = true;
        for (let j = 0; j < needle.length; ++j) {
            if (i + j == haystack.length) {
                return -1;
            }
            if (haystack[i + j] != needle[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
};
