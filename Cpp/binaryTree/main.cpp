#include "traverse.h"
#include "BST.h"
#include "feature.h"
#include "path.h"

int main()
{
    Tree* tree = new Tree();
    Traverse* traverse = new Traverse();
    Feature* feature = new Feature();
    BST* bst = new BST();
    List* list = new List();
    Path* path = new Path();

    cout << "Chapter1:Traverse----" << endl;
    cout << "Type1: Reconstruct tree" << endl;
    vector<int> preorder = {1,2,4,5,7,8,3,6};
    vector<int> inorder = {4,2,7,5,8,1,3,6};
    vector<int> postorder = {4,7,8,5,2,6,3,1};

    cout << "Construct tree from preOrder and inOrder tree:" << endl;
    TreeNode* root1_1 = traverse->constructFromPreIn(preorder, inorder);
    tree->printTree(root1_1);

    cout << "Construct tree from preOrder and postOrder tree(multi ans):"<< endl;
    TreeNode* root1_2 = traverse->constructFromPrePost(preorder, postorder);
    tree->printTree(root1_2);

    cout << "Construct tree from inOrder and postOrder tree:"<< endl;
    TreeNode* root1_3 = traverse->constructFromInPost(inorder, postorder);
    tree->printTree(root1_3);


    cout << "Type2: Basic traverse" << endl;
    vector<string> vec2 = {"1","2","3","4","5","null","6","null","null","7","8"};
    TreeNode* root2 = tree->buildTree(vec2);
    cout << "Origin tree:"<<endl;
    tree->printTree(root2);
    cout << "PreOrder traverse:" << endl;
    vector<int> vec2_1 = traverse->preorderTraversal(root2);
    printContrainer(vec2_1);
    vector<int> vec2_2 = traverse->preorderTraversal_iter(root2);
    printContrainer(vec2_2);
    vector<int> vec2_3 = traverse->preorderTraversal_template(root2);
    printContrainer(vec2_3);
    cout << "InOrder traverse:" << endl;
    vector<int> vec2_4 = traverse->inorderTraversal(root2);
    printContrainer(vec2_4);
    vector<int> vec2_5 = traverse->inorderTraversal_iter(root2);
    printContrainer(vec2_5);
    vector<int> vec2_6 = traverse->inorderTraversal_template(root2);
    printContrainer(vec2_6);
    cout << "PostOrder traverse:" << endl;
    vector<int> vec2_7 = traverse->postorderTraversal(root2);
    printContrainer(vec2_7);
    vector<int> vec2_8 = traverse->postorderTraversal_iter(root2);
    printContrainer(vec2_8);
    vector<int> vec2_9 = traverse->postorderTraversal_template(root2);
    printContrainer(vec2_9);
    cout << "Layer traverse:" << endl;
    vector<vector<int>> vec2_10 = traverse->levelOrder(root2);
    for(int i = 0; i < vec2_10.size(); i++){
        printContrainer(vec2_10[i]);
    }
    cout << "zigbag traverse:" << endl;
    vector<vector<int>> vec2_11 = traverse->zigzagLevelOrder(root2);
    for(int i = 0; i < vec2_11.size(); i++){
        printContrainer(vec2_11[i]);
    }
    cout << endl;
    vector<vector<int>> vec2_12 = traverse->zigzagLevelOrder2(root2);
    for(int i = 0; i < vec2_12.size(); i++){
        printContrainer(vec2_12[i]);
    }

    cout << "\nChapter2:Binary search tree----" << endl;
    cout << "Type1: Valid" << endl;
    vector<string> vec3_1 = {"5","1","4","null","null","3","6"};
    vector<string> vec3_2 = {"5","1","7","null","null","6","8"};
    TreeNode* root3_1 = tree->buildTree(vec3_1);
    TreeNode* root3_2 = tree->buildTree(vec3_2);
    bool flag3_1 = bst->isValidBST_inorderVec(root3_1);
    cout << "flag3_1=" << flag3_1 << endl;
    bool flag3_2 = bst->isValidBST_inorderVec(root3_2);
    cout << "flag3_2=" << flag3_2 << endl;
    bool flag3_3 = bst->isValidBST_inorder(root3_1);
    cout << "flag3_3=" << flag3_3 << endl;
    bool flag3_4 = bst->isValidBST_inorder(root3_2);
    cout << "flag3_4=" << flag3_4 << endl;
    bool flag3_5 = bst->isValidBST_iter(root3_1);
    cout << "flag3_5=" << flag3_5 << endl;
    bool flag3_6 = bst->isValidBST_iter(root3_2);
    cout << "flag3_6=" << flag3_6 << endl;

    cout << "Type2: Generate" << endl;
    int n4_1 = bst->numTrees(3);
    cout << "n4_1 = " << n4_1 << endl;
    vector<TreeNode*> roots = bst->generateTrees(3);
    for(TreeNode* root: roots){
        tree->printTree(root);
    }

    cout << "Type3: Recover" << endl;
    vector<string> vec5_1 = {"1","3","null","null","2"};
    TreeNode* root5_1 = tree->buildTree(vec5_1);
    tree->printTree(root5_1);
    bst->recoverTree(root5_1);
    tree->printTree(root5_1);

    cout << "Type4: Convert" << endl;
    cout << "from vector" << endl;
    vector<int> vec6_1 = {-10,-3,0,5,9};
    TreeNode* root = bst->sortedArrayToBST(vec6_1);
    tree->printTree(root);
    cout << "from list" << endl;
    vector<int> vec6_2 = {-10,-3,0,5,9};
    ListNode* head6_2 = list->buildList(vec6_2);
    TreeNode* root6_2 = bst->sortedListToBST(head6_2);
    tree->printTree(root6_2);

    cout << "Type5: Iter" << endl;
    vector<string> vec7_1 = {"7", "3", "15", "null", "null", "9", "20"};
    TreeNode* root7_1 = tree->buildTree(vec7_1);
    tree->printTree(root7_1);
    BSTIterator* iter = new BSTIterator(root7_1);
    int val7_1 = iter->next();
    int val7_2 = iter->next();
    bool flag7_1 = iter->hasNext();
    int val7_3 = iter->next();
    bool flag7_2 = iter->hasNext();
    int val7_4 = iter->next();
    bool flag7_3 = iter->hasNext();
    int val7_5 = iter->next();
    bool flag7_4 = iter->hasNext();
    cout << val7_1 << ',' << val7_2 << ',' << val7_3 << ',' << val7_4 << ','<< val7_5 << endl;
    cout << flag7_1 << ',' << flag7_2 << ',' << flag7_3 <<',' << flag7_4 << endl;

    cout << "Type6: Convert to list" << endl;
    TreeNode* node7_1 = bst->treeToDoublyList(root7_1);

    cout << "\nChapter3:Feature of bitree----" << endl;
    cout << "Feature of Symmetric --" << endl;
    vector<string> vec8_1 = {"1","2","2","3","4","4","3"};
    TreeNode* root8_1 = tree->buildTree(vec8_1);
    tree->printTree(root8_1);
    bool flag8_1 = feature->isSymmetric(root8_1);
    cout << "flag8_1 = " << flag8_1 << endl;
    vector<string> vec8_2 = {"9","-42","-42","null","76","76","null","null","13","null","13"};
    TreeNode* root8_2 = tree->buildTree(vec8_2);
    tree->printTree(root8_2);
    bool flag8_2 = feature->isSymmetric_iter(root8_2);
    cout << "flag8_2 = " << flag8_2 << endl;

    cout << "Feature of Depth --" << endl;
    vector<string> vec8_3 = {"3","9","20","null","null","15","7"};
    TreeNode* root8_3 = tree->buildTree(vec8_3);
    tree->printTree(root8_3);
    int depth8_3 = feature->maxDepth_recur(root8_3);
    cout << "depth8_3 = " << depth8_3 << endl;
    vector<string> vec8_4 = {"0","2","4","1","null","3","-1","5","1","null","6","null","8"};
    TreeNode* root8_4 = tree->buildTree(vec8_4);
    tree->printTree(root8_4);
    int depth8_4 = feature->maxDepth_bfs(root8_4);
    cout << "depth8_4 = " << depth8_4 << endl;

    vector<string> vec8_5 = {"1","2","3","4","null","null","5"};
    TreeNode* root8_5 = tree->buildTree(vec8_5);
    tree->printTree(root8_5);
    int depth8_5 = feature->minDepth_bfs(root8_5);
    cout << "depth8_5 = " << depth8_5 << endl;
    int depth8_6 = feature->minDepth_recur1(root8_5);
    cout << "depth8_6 = " << depth8_6 << endl;

    cout << "617.合并二叉树" << endl;
    vector<string>vec8_7 = {"1","3","2","5"};
    vector<string>vec8_8 = {"2","1","3","null","4","null","7"};
    TreeNode* root8_7 = tree->buildTree(vec8_7);
    TreeNode* root8_8 = tree->buildTree(vec8_8);
    TreeNode* root8_9 = feature->mergeTrees(root8_7, root8_8);
    tree->printTree(root8_7);
    tree->printTree(root8_8);
    tree->printTree(root8_9);

    cout << "剑指 Offer 27.二叉树的镜像" << endl;
    vector<string>vec8_10 = {"4","2","7","1","3","6","9"};
    TreeNode* root8_10 = tree->buildTree(vec8_10);
    tree->printTree(root8_10);
    TreeNode* root8_11 = feature->mirrorTree(root8_10);
    tree->printTree(root8_11);

    cout << "100.相同的树" << endl;
    vector<string>vec8_12 = {"1","2","3"};
    TreeNode* root8_12 = tree->buildTree(vec8_12);
    bool flag8_12 = feature->isSameTree(root8_12, root8_12);
    vector<string>vec8_13 = {"1","2","4"};
    TreeNode* root8_13 = tree->buildTree(vec8_13);
    bool flag8_13 = feature->isSameTree(root8_12, root8_13);
    cout << flag8_12 << endl;
    cout << flag8_13 << endl;
    cout << endl;

    cout << "110.平衡二叉树" << endl;
    vector<string>vec8_14 = {"1","2","2","3","3","null","null","4","4"};
    TreeNode* root8_14 = tree->buildTree(vec8_14);
    tree->printTree(root8_14);
    bool flag8_14 = feature->isBalanced(root8_14);
    cout << "flag8_14 = " << flag8_14 << endl;

    cout << "199.二叉树的右视图" << endl;
    vector<string>vec8_15 = {"1","2","3","null","5","null","4"};
    TreeNode* root8_15 = tree->buildTree(vec8_15);
    tree->printTree(root8_15);
    vector<int> res8_15 = feature->rightSideView(root8_15);
    printContrainer(res8_15);
    vector<int> res8_16 = feature->rightSideView2(root8_15);
    printContrainer(res8_16);


    cout << "\nChapter4:Path problem----" << endl;
    cout << "\n112.路径总和" << endl;
    vector<string>vec8_17 = {"5","4","8","11","null","13","4","7","2","null","null","null","1"};
    TreeNode* root8_17 = tree->buildTree(vec8_17);
    tree->printTree(root8_17);
    bool flag8_17 = path->hasPathSum(root8_17, 22);
    cout << "flag8_17 = " << flag8_17 << endl;
    
    cout << "\n113.路径总和II" << endl;
    vector<vector<int>> vec8_18 = path->pathSum(root8_17, 22);
    for(int i = 0; i < vec8_18.size(); i++){
        printContrainer(vec8_18[i]);
    }

    cout << "\n124. 二叉树中的最大路径和" << endl;
    vector<string>vec8_19 = {"-10","9","20","null","null","15","7"};
    TreeNode* root8_19 = tree->buildTree(vec8_19);
    tree->printTree(root8_19);
    int val8_19 = path->maxPathSum(root8_19);
    cout << val8_19 << endl;

    cout << "\n129. 求根节点到叶节点数字之和" << endl;
    vector<string>vec8_20 = {"4","9","0","5","1"};
    TreeNode* root8_20 = tree->buildTree(vec8_20);
    tree->printTree(root8_20);
    int res = path->sumNumbers(root8_20);
    cout << res << endl;
}   