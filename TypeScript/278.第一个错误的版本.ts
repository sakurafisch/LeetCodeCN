/**
 * The knows API is defined in the parent class Relation.
 * isBadVersion(version: number): boolean {
 *     ...
 * };
 */

var solution = function (isBadVersion: any) {

    return function (n: number): number {
        let [left, right] = [0, n];
        while (left <= right) {
            const mid = Math.floor((right - left) / 2 + left);
            if (isBadVersion(mid) == true)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    };
};
