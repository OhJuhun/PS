#include <algorithm>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    int answer = 0;
    int findLen(TreeNode* node,int len){
        if(node == NULL) return len-1;
        
        return max(findLen(node->left,len+1),findLen(node->right,len+1));
    }

    int maxDepth(TreeNode* root) {
        return findLen(root,1);
    }
};