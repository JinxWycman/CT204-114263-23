#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int &maxSum) {
        if (node == NULL) return 0;

        int leftMax = max(0, maxPathSumHelper(node->left, maxSum));
        int rightMax = max(0, maxPathSumHelper(node->right, maxSum));

        maxSum = max(maxSum, leftMax + rightMax + node->val);

        return max(leftMax, rightMax) + node->val;
    }
};

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;

    // Clean up memory (not shown here for simplicity)

    return 0;
}