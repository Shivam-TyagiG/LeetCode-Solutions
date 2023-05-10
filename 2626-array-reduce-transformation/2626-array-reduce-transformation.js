/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let answer = init;
    for (let i = 0; i < nums.length; i++) {
        answer = fn(answer, nums[i])
    }
    return answer
};