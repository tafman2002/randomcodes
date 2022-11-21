/*
Depth-First Search will search the depth of a tree
*/
#include<iostream>
#include <vector>
#include <queue>
#include<memory>
using namespace std;


// Structure to represent a Node data structure
struct Node {
    int data;
    Node * left;
    Node * right;
};


// A funtion that creates a new node using the passed in data and 
// returns it
Node* createNode(int data) {
    Node * newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Preorder algorithm
void preOrderPrint(Node * node) {
    if (node != nullptr) {
        cout << node->data << endl;
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}

// inOrder algorithm
void inOrderPrint(Node * node) {
    if (node != nullptr) {
        inOrderPrint(node->left);
        cout << node->data << endl;
        inOrderPrint(node->right);
    }
}

// PostOrderPrint
void postOrderPrint(Node * node) {
    if (node != nullptr) {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        cout << node->data << endl;
    }
}

  /* This algorithm focuses on returning all values from the different levels of the tree.
        To begin, a queue list and a vector will be needed (the queue data structure will be used to hold the references
        of the nodes while the list will hold the values of the nodes being searched)

        Time Complexity: O(|V|)
        Space Complexity: O(|V|)
        N.B: |V| is the number of nodes

        It is important to note that this algorithm does not take into account the weights of the edges 
        For more information, reference the following link: https://stackoverflow.com/questions/9844193/what-is-the-time-and-space-complexity-of-a-breadth-first-and-depth-first-tree-tr
    */
void breadthFirstSearch(Node * root) {
    cout << "Breadth First Search Algorithm" << endl;
    std::unique_ptr<Node> node (root);
    std::vector<int> list;
    queue <Node> queue;
    // The root node is first inserted into the queue
    queue.push(*node);
    while (queue.size() > 0) {
        /* While there are still nodes in the queue, the current node will be set to the node at the front of the queue shall be referenced and its value will be 
        stored in the vector list. From there, if there are node references to the left or right child of the current node, those node references will be pushed to the queue.
        The node at the beginning of the queue is then popped off (since its value has already been added to the vector list), resulting in the shift of elements in the queue. 
        This process repeats until there is no nodes left in the queue */
        *node = std::move(queue.front());
        list.push_back(node->data);
        if (node->left) {
            queue.push(*node->left);
        }
        if (node->right) {
            queue.push(*node->right);
        }
        queue.pop();
    }
    // Release memory 
    node = nullptr;
    // With the breadth first Search Complete, the last step is to print off all of the values in the vector list that are in the tree
    for (int item : list) {
        cout << item << endl;
    }
}

/* 
Descritpion: return the average value of the nodes on each level in the form of an array.
Input: Node variable that is the root node
Complexity Analysis:
    Time complexity : O(n). The whole tree is traversed atmost once. Here, nnn refers to the number of nodes in the given binary tree.
    Space complexity : O(m). The size of queuequeuequeue or temptemptemp can grow upto atmost the maximum number of nodes at any level in the given binary tree. Here, mmm refers to the maximum mumber of nodes at any level in the input tree.
Explanation: https://leetcode.com/problems/average-of-levels-in-binary-tree/
*/
std::vector<double> getAveragePerLevel(Node * root) {
    cout << "Average Per Level: " << endl;
    std::vector<double> results;
    queue <Node> nodeQueue;
    nodeQueue.push(*root);
    std::unique_ptr<Node> node = nullptr;
    while (!nodeQueue.empty()) {
        long sum = 0;
        long count = 0;
        queue <Node> temp;
        while (!nodeQueue.empty()) {
            *node = std::move(nodeQueue.front());
            sum += node->data;
            count++;
            if (node->left) temp.push(*node->left);
            if (node->right) temp.push(*node->right);
        }
        nodeQueue = temp;
        results.push_back(sum*1.0 / count);
    }
    return results;
}

bool checkNumber(Node * inputNode) {
    if (inputNode == nullptr) return false;

    // Check if any node in the left subtree contains a 1.
    bool left = checkNumber(inputNode->left);
    // Check if any node in the right subtree contains a 1
    bool right = checkNumber(inputNode->right);
    // If the left subtree does not contain a 1, prune the subtree.
    if (!left) inputNode->left = nullptr;        
    // If the right subtree does not contain a 1, prune the subtree.
    if (!right) inputNode->right = nullptr;
    // Return true if the current node, its left or right subtree contains a 1.
    return inputNode->data == 1 || left || right;
}


/* 
Returns the same tree where every subtree (of the given tree) not containing a 1 has been removed.
Prune children of the tree recursively. The only decisions at each node are whether to prune the left child or the right child.

Complexity Analysis
    Time Complexity: O(N), where NNN is the number of nodes in the tree. We process each node once.
    Space Complexity: O(N), the recursion call stack can be as large as the height HHH of the tree. In the worst case scenario, H=NH=NH=N, when the tree is skewed.

Explanation: https://leetcode.com/problems/binary-tree-pruning/
*/
Node * BinaryTreePruning(Node * root) {
    return checkNumber(root) ? root : nullptr;
}

/* 
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
Explanation: https://leetcode.com/problems/sum-root-to-leaf-numbers/

My solution (doesn't solve all test case):
The key to the problem was that each node value is a digit that needed to be concatinated with other values until a leaf node is reached.
By appending each value to a string, the final digit cound be determined and returned back.
At the start of the function, the string numberString is first appended with the root value as its staring point
*/
int sumtotal(Node * node, std::string strNum, int sumCount) {
    if (node) {
        strNum.append(std::to_string(node->data));
        if (!node->left && !node->right) {
            // return complete string
            // sumCount += std::stoi(strNum);
            return std::stoi(strNum);
        } else {
             if (node->left) {
                sumCount += sumtotal(node->left,strNum,sumCount);
            } 
            if (node->right) {
            sumCount+= sumtotal(node->right,strNum,sumCount);
            }
            return sumCount;
        
        }
        
    }
}

int sumRoot(Node * node) {
    // wrong
    int sum = 0;
    std::string numberString {std::to_string(node->data)};
    if (node) {
        if (!node->left && !node->right) return node->data;
        if (node->left) sum += sumtotal(node->left, numberString, sum);
        if (node->right) sum += sumtotal(node->right, numberString, sum);
    }
    return sum;
}

int dfs(Node * node, int num) {
    /* This dfs method first checks to see if the node is valid. If not, 0 is simply returned. Otherwise, the num parameter is then multiplied by 10 before adding the 
    current Node's value to it to get the new digit. e.g for the path 4->9->5 (left), the num is set to 4 and the dfs function is called for the left and right child. For the 
    next node 9, the previous value of 4 is multiplied by 10 to make it into the tenth position (40). That value is then added with 9 to produce the new number of 49. Follow algorithm for more  */
    if (!node) return 0;
    num = num * 10 + node->data;
    if (!node->left && !node->right) return num;
    return dfs(node->left,num) + dfs(node->right,num);
}
    // Real solution
int sumRootAnswer(Node * root) {return dfs(root, 0);}
    
    bool bfs(Node * root) {
        queue<Node> myqueue;
        std::unique_ptr<Node>tempNode (root);
        // At the start of the function, the node is a root node so it's left and right children will be added to the node if they exist.
        // The vector of integers called list will be used to hold all of the node values on each level before emptying the list and proceeding to the
        // next level while the onEvenLevel is used to indicate whether the current level is an even index or not. At the start of the function, the level starts at 1
        if (root->left) myqueue.push(*root->left);
        if (root->right) myqueue.push(*root->right);
        std::vector<int>mylist;
        bool onEvenLevel = false;
        
        while(myqueue.size() > 0) {
            queue <Node> temp;
            while (myqueue.size() > 0) {
                // The node at the front of the queue is retrieved and its children are added to the temporary queue. The value of the node is also added to the 
                // vector list before it is popped off the list
                *tempNode = std::move(myqueue.front());
                mylist.push_back(tempNode->data);
                if (tempNode->left) temp.push(*tempNode->left);
                if (tempNode->right) temp.push(*tempNode->right);
                myqueue.pop();
            }
            
            if (onEvenLevel) {
                // The current level is an Even Level so there are two cases to consider:
                //      1. if there is only one value found at a level, the value of that node is checked to see if it is an even or odd value.
                //      2. if there is more than one value in the list, we traverse the whole list to check if the following conditions are present to satisfy the Even-Odd tree:
                //            - Each value is an odd value
                //            - The values are sorted in a strictly increasing order
                if (mylist.size() == 1 && mylist[0] % 2 == 0)  return false;
                for (int i = 0; i < mylist.size()-1;i++) {
                    if (mylist[i] % 2 == 0 || mylist[i] >= mylist[i+1] || mylist[i+1] % 2 == 0) {
                        return false;
                    }
                  }
            } else {
                // The current level is an Odd Level so there are two cases to consider:
                //      1. if there is only one value found at a level, the value of that node is checked to see if it is an even or odd value.
                //      2. if there is more than one value in the list, we traverse the whole list to check if the following conditions are present to satisfy the Even-Odd tree:
                //            - Each value is an even value
                //            - The values are sorted in a strictly decreasing order
                if (mylist.size() == 1 && mylist[0] % 2 != 0) return false;
                 for (int i = 0; i < mylist.size()-1;i++) {
                    if (mylist[i] % 2 != 0 || mylist[i] <= mylist[i+1] || mylist[i+1] % 2 != 0) {
                        return false;
                    }
                }
            }
            // The onEvenLevel is negated to indicate a change in the level 
            onEvenLevel = !onEvenLevel;
            myqueue = temp;
            mylist.clear();
        }
        return true;
    }

   
 /* 
    A binary tree is named Even-Odd if it meets the following conditions:

    The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
    For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
    For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).

    Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
    https://leetcode.com/problems/even-odd-tree/submissions/
*/
bool isEvenOddTree(Node* root) {
    // A check will first be done to see if the value of the root node is an odd value which satisfies the Even Odd condition. If not, the function returns false, else
    // a modified breadth first search will be done 
    return root->data % 2 == 0 ? false : bfs(root);
}

// Binary Tree Cameras (https://leetcode.com/problems/binary-tree-cameras/submissions/)
// int minCameraCover(TreeNode* root) {
//         // return root->left == nullptr && root->right == nullptr ? 1 : bfs(root);
//          return root->left == nullptr && root->right == nullptr ? 1 : dfs(root,1);
//     }
    
//     int dfs(TreeNode * node, int num) {
//         if (!node) return 0;
//         num++;
//         if (!node->left && !node->right) return num;
//         num += dfs(node->left,num) + dfs(node->right,num);
//         return num / 3;
//     }
    
//     int bfs(TreeNode* root) {
//         TreeNode * node = root;
//         queue <TreeNode> myqueue;
//         std::vector hello;
        
//         int sum = 1;
//         bool needsCamera = true;
//         // The root node is first inserted into the queue
//         myqueue.push(*node);
//         // while (myqueue.size() > 0) {
//         //     *node = myqueue.front();
//         //     // still going to count regardless of the level
//         //     if (node->left) {
//         //         myqueue.push(*node->left);
//         //         sum++;
//         //     }
//         //     if (node->right) {
//         //         myqueue.push(*node->right); 
//         //         sum++;
//         //     }
//         //     myqueue.pop();
//         // }
//     while (myqueue.size() > 0) {
//         queue <TreeNode> temp;
//         while (myqueue.size() > 0) {
//             *node = myqueue.front();
//             // still going to count regardless of the level
//             if (node->left) {
//                 temp.push(*node->left);
//             }
//             if (node->right) {
//                 temp.push(*node->right);     
//             }
//             myqueue.pop();
//         }
//         sum+=temp.size();
//         myqueue = temp;
//     }
//         if (sum == 2) return sum;
//         sum = sum / 3;
//         return sum;
//     }

std::vector<int> subVec(std::vector<int> mylist,int begin, int end) {
    std::vector<int> v2;
    for (int i = begin; i < end; i++) {
        v2.push_back(mylist[i]);
    }
    return v2;
}
Node * constructBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        Node * node = new Node();
        int max = nums[0];
        int indexFound = 0;
        for (int i = 0; i < nums.size();i++){
            if (nums[i]>max) {
                max = nums[i];
                indexFound = i;
            }
        }
        node->data = max;
        if (indexFound == 0) {
            node->left = nullptr;
        } else {
            std::vector<int> subvec = subVec(nums,0,indexFound);
            node->left = constructBinaryTree(subvec);
        }
        
        if (indexFound == nums.size()-1) {
            node->right = nullptr;
        } else {
            std::vector<int> subvec = subVec(nums,indexFound+1,nums.size());
            node->right = constructBinaryTree(subvec);
        }
        return node;
}

Node * constructMaximumBinaryTree(vector<int>& nums) {
    // Works completely (submitted on leetcode) can probably be put in maximumBinaryTree
    // https://leetcode.com/problems/maximum-binary-tree/
    return nums.size() == 0 ? nullptr : constructBinaryTree(nums);
}

// MAIN
int main() {
    std::vector<int> mytest {3,2,1,6,0,5}; 
    constructMaximumBinaryTree(mytest);
    // Level 1
    Node * root=createNode(1);
    // Level 2
    root->left = createNode(2);
    root->right = createNode(3);
    // Level 3
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    // Level 4 
    root->left->right->left=createNode(9);
    root->right->right->left=createNode(15);

    // IsEven
    cout << "Result is " << std::boolalpha << isEvenOddTree(root) << endl;


    // Print out the tree using different algorithms
    cout << "PreOrder: " << endl;
    preOrderPrint(root);
    cout << "PostOrder: " << endl;
    postOrderPrint(root);
    cout << "InOrder: " << endl;
    inOrderPrint(root);
    breadthFirstSearch(root);
    // getAveragePerLevel(root);

    Node * root2 = createNode(1);
    root2->right = createNode(0);
    root2->right->right = createNode(1);
    root2->right->left = createNode(0);
    cout << "The Tree before pruning: " << endl;
    preOrderPrint(root2);
    cout << "The Tree after pruning: " << endl;
    // *root2  = BinaryTreePruning(root2);
    Node * root3 = createNode(4);
    root3->left = createNode(9);
    root3->left->left = createNode(5);
    root3->left->right = createNode(1);
    root3->right = createNode(0);
    preOrderPrint(root2);
    cout << endl;
    preOrderPrint(root3);
    cout << "The sum is " << sumRoot(root2) << endl;

    cout << "_____________________________" << endl;

Node * root4 = createNode(1);
root4->left = createNode(10);
root4->right = createNode(4);
root4->left->left = createNode(3);
root4->left->left->right = createNode(8);
root4->left->left->left = createNode(12);
root4->right->right = createNode(9);
root4->right->left = createNode(7);
root4->right->right->right = createNode(2);
root4->right->left->left = createNode(6);
// breadthFirstSearch(root4);
cout << "Result is " << std::boolalpha << isEvenOddTree(root4) << endl;
return 0;
}