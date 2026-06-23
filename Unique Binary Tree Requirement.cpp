// Time Complexity: O(1)
//
// We only check the traversal numbers.
// Therefore, overall time complexity is O(1).

// Space Complexity: O(1)
//
// No extra space is used.

class Solution {
  public:
    bool isPossible(int a, int b) {
        return (a == 2 || b == 2) && (a != b);
    }
};
