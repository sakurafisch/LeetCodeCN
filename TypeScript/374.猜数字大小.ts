function guess(pick: number): number { return pick; };

/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */


function guessNumber(n: number): number {
    let [left, right] = [1, n];
    while (left <= right) {
        const mid = Math.floor((right - left) / 2 + left);
        const g = guess(mid);
        if (g == 0)
            return mid;
        else if (g == -1) {  // num < pick ; pick > num
            right = mid - 1;
        } else if (g == 1) {
            left = mid + 1;
        }
    }
    return -1;
};
