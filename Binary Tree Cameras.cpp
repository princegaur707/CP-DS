//https://leetcode.com/problems/binary-tree-cameras/description/
//Approach: We want to increase camera count(place camera) where it is compulsory
//like never place camera at leaf node, if any of the left or right node exist increase the camera count
//and if parent is NULL and root do not exist in map then increase the count
class Solution {
  unordered_map<TreeNode*, bool> m;
  int camera;

  void PlaceCamera(TreeNode* root, TreeNode* parent) {
    if(root == NULL)
      return;
    PlaceCamera(root->left, root);
    PlaceCamera(root->right, root);
    if((parent == NULL and m.count(root)== 0) or m.count(root->left) == 0 or m.count(root->right)== 0) {
      camera++;
      m[parent] = true;
      m[root] = true;
      m[root->left] = true;
      m[root->right] = true;
    }
  }
public:
    int minCameraCover(TreeNode* root) {
        camera = 0;
        m.insert({NULL, true});
        PlaceCamera(root, NULL);
        return camera;
    }
};