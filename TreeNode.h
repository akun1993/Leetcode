#ifndef __TREE_NODE_H_
#define __TREE_NODE_H_

#include <vector>
#include <math.h>
#include <deque>
#include <stack>
#include "my_types.h"

struct TreeNode {


    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    struct Record_s
    {
        Record_s(TreeNode *node,int idx,int pos): node(node),idx(idx),pos(pos) {  }
        TreeNode *node;
        int idx;
        int pos;
    } ;

    void TranslevelII(TreeNode *root)
    {
        if(root == NULL) return ;

        int max_depth = maxDepth(root);

        int max_cnt =  pow(2, max_depth + 1);

        deque<Record_s> qu;
        qu.push_back(Record_s (root,1,max_cnt / 2));

        int k = 1;
        int null_cnt = 0;
        int cur_depth = 0;

        while(!qu.empty() && null_cnt != (int)qu.size())
        {
            int next_k = 0;

            null_cnt = 0;
            
            int out_idx = 0;

            bool is_left = true;

            while(k > 0)
            {
                Record_s record = qu.front();
                qu.pop_front();
                int idx = record.idx;

                int real_idx ;
                int parent_pos = record.pos;

                if(cur_depth != 0)
                {
                    if(is_left)
                        real_idx = parent_pos  - max_depth + cur_depth;
                    else
                        real_idx = parent_pos + max_depth - cur_depth;
                    is_left = !is_left;
                }
                else
                {
                   real_idx = parent_pos;
                }
                

                

                real_idx = real_idx < out_idx ? out_idx : real_idx;
               // cout << "idx and  real_idx " << idx <<"," << real_idx << endl;
                
                //cout << "mid and  real_idx  and  max_cnt " << mid <<","  << real_idx  <<"," << max_cnt << endl;
                for(int i = out_idx ; i <  max_cnt ; ++i)
                {
                    if( i == real_idx )
                    {
                        if(record.node)
                        {
                            TreeNode * node= record.node;
                            cout << node->val;

                            qu.push_back(Record_s (node->left,2 * idx - 1,i));
                            next_k++;
                            qu.push_back(Record_s (node->right,2 * idx,i));
                            next_k++;

                            if(node->left == NULL )null_cnt++;
                            if(node->right == NULL )null_cnt++;
                        }
                        else
                        {
                            cout << "N" ;
                        }
                        out_idx ++;
                        //cout <<"  " ;
                        break;
                    }
                    else
                    {
                        out_idx++;
                         cout <<"  " ;
                    }
                       

                }
                k--;
            }
            cout << endl  << endl;
            cur_depth++;
            k = next_k;
        }
        return ;
    }


    void Translevel(TreeNode *root)
    {
        if(root == NULL) return ;
        deque<TreeNode *> qu;
        qu.push_back(root);

        int k = 1;
        int null_cnt = 0;

       // int cur_depth = 0;

        while(!qu.empty() && null_cnt != (int)qu.size())
        {
            int next_k = 0;

            null_cnt = 0;

            while(k > 0)
            {
                TreeNode *node = qu.front();
                qu.pop_front();

                if(node)
                {
                    cout << node->val << ", ";
                    qu.push_back(node->left);
                    next_k++;
                    qu.push_back(node->right);
                    next_k++;

                    if(node->left == NULL )null_cnt++;
                    if(node->right == NULL )null_cnt++;
                }
                else
                {
                    cout << "NULL" << ", ";

                }

                k--;
            }
            //cur_depth++;
            k = next_k;
        }
        return ;
    }


    int maxDepth(TreeNode* root)
    {
        if(root == NULL) return 0;
        int depth_left,depth_right;
        depth_left =  1 + maxDepth(root->left);
        depth_right = 1 + maxDepth(root->right);

        return depth_left > depth_right ? depth_left : depth_right;
    }

    TreeNode *GenerateTree(vector<int > &val_list)
    {
        if(val_list.empty() || val_list[0] == 0) return NULL;

        TreeNode *head = new TreeNode(0);

        head->val = val_list[0];

        deque<TreeNode *> qu;
        qu.push_back(head);

        int k = 1;
        int val_idx = 1;

        while(!qu.empty())
        {
            int next_k = 0;
            while(k > 0)
            {
                TreeNode *node = qu.front();
                qu.pop_front();
                for(u32 i = 0;val_idx + i < val_list.size() && i < 2; ++i)
                {
                    if(val_list[val_idx + i] != 0)
                    {
                        TreeNode *new_node = new TreeNode(val_list[val_idx + i]);

                        if(i == 0)
                            node->left = new_node;
                        else
                            node->right = new_node;

                        qu.push_back(new_node);
                        next_k++;
                    }
                }
                val_idx += 2;
                k--;
            }
            k = next_k;
        }
        return head;
    }

    bool __Symmetric(TreeNode* lnode,TreeNode* rnode)
    {
        if(lnode == NULL && rnode == NULL) return true;

        if(!(lnode && rnode)) return false;

        if(lnode->val != rnode->val) return false;

        return __Symmetric(lnode->left,rnode->right) &&  __Symmetric(lnode->right,rnode->left);
    }


    bool SymmetricIterator(TreeNode *root)
    {
        if(root == NULL) return true;
        
        bool res = true;

        deque<TreeNode *> qu;
    
        if(root->left == NULL && root->right == NULL) return true;

        if(!(root->left && root->right)) return false;

        qu.push_back(root->left);
        qu.push_back(root->right);

        int k = 1;

        while(!qu.empty() && res)
        {
            int next_k = 0;

            while(k > 0)
            {
                TreeNode *lnode = qu.front();
                qu.pop_front();

                TreeNode *rnode = qu.front();
                qu.pop_front();

                if(lnode->val != rnode->val)
                {
                    res = false;
                    break;
                }

                if((lnode->left == NULL && rnode->right != NULL)
                || (lnode->left != NULL && rnode->right == NULL)
                || (lnode->right == NULL && rnode->left != NULL)
                || (lnode->right != NULL && rnode->left == NULL))
                {
                    res = false;
                    break;
                }
            
                if(lnode->left && rnode->right)
                {
                   // cout << node->val << ", ";
                    qu.push_back(lnode->left);
                    qu.push_back(rnode->right);
                    next_k++;

                }

                if(lnode->right && rnode->left)
                {
                   // cout << node->val << ", ";
                    qu.push_back(lnode->right);
                    qu.push_back(rnode->left);
                    next_k++;
                }
                k--;
            }
            //cur_depth++;
            k = next_k;
        }
        return res;
    }


    vector<int> inorderTraversal(TreeNode* root) 
    {
        
        vector<int>  res;
        if(root == NULL) return res;
        stack<TreeNode *>  st;
        

        while (root)
        {
            /* code */
            st.push(root);
            root = root->left;
        }
        
        while (!st.empty())
        {
            TreeNode *visit = st.top();
            st.pop();
            if(visit && visit->right)
            {
                st.push(visit->right);
                TreeNode *node = visit->right->left;
                while( node)
                {
                    st.push(node);
                    node = node->left;
                } 
            }
            //TreeNode *visit = st.top();
            res.push_back(visit->val);
            //cout << visit->val << " ";
            /* code */
        }
        return res;
    }

    vector<int> inorderTraversalII(TreeNode* root) 
    {
        vector<int>  res;
        if(root == NULL) return res;
        stack<TreeNode *>  st;
        st.push(root);
        
        TreeNode *next = root;
        
        while (!st.empty())
        {
            if(next) 
            {
                TreeNode *node = next->left;
                while( node)
                {
                    st.push(node);
                    node = node->left;
                } 
            }
            TreeNode *visit = st.top();
            st.pop();
            res.push_back(visit->val);
            next = visit->right;
            if(visit->right)
            {
                st.push(visit->right);
            }
        }
        return res;
    }

    //是否是对称二叉树
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL) return true;

        return __Symmetric(root->left,root->right);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == NULL) return NULL;
        if(NULL == q && p == NULL) return NULL;
        if(root == q || p == root) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right,  p, q);

        if(left != NULL && right == NULL)
        {
            return left;
        }
        
        if(left == NULL && right != NULL)
        {
            return right;
        }
        
        if(left == NULL && right != NULL)
        {
            return root;
        }
    }   

   TreeNode* lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL) return NULL;

        TreeNode *ret = NULL; 
        
        deque<TreeNode *> qu;
        qu.push_back(root);

        int k = 1;

       // int cur_depth = 0;

        while(!qu.empty() )
        {
            int next_k = 0;

            while(k > 0)
            {
                TreeNode *node = qu.front();
                qu.pop_front();

                if(node)
                {
                   // cout << node->val << ", ";

                    bool res = CheckNodeIsInTree(node,p);

                    if(res) res = CheckNodeIsInTree(node,q);

                    if(res)
                    {
                        ret = node;
                    }

                    if(node->left != NULL )
                    {
                        qu.push_back(node->left);
                        next_k++;
                    }

                    if(node->right != NULL )
                    {
                        qu.push_back(node->right);
                        next_k++;
                    }
                }

                k--;
            }
            //cur_depth++;
            k = next_k;
        }
        return ret;
    }    

    TreeNode *FindNodeByVal(TreeNode* root,int val)
    {
        if(root == NULL) return NULL;
        if(root->val == val) return root;

        TreeNode *res = FindNodeByVal(root->left,val);

        if(!res) res = FindNodeByVal(root->right,val);
        
        return res;
    }

    bool CheckNodeIsInTree(TreeNode* root,TreeNode* node)
    {
        if(root == NULL) return NULL;
        if(root == node) return true;

        bool res = CheckNodeIsInTree(root->left,node);

        if(!res) res = CheckNodeIsInTree(root->right,node);
        
        return res;
    }


    void flatten(TreeNode* root)
    {
        if(root == NULL) return ;
        if(root->left)
        {
            TreeNode* right = root->right;
            
            root->right = root->left;
            root->left = NULL;

            TreeNode* tmp = root;
            while(tmp->right)
                tmp = tmp->right;

            tmp->right = right;
        }
        flatten(root->right);
    }

};


#endif // __SOLUTION_UNIQUE_WAY_H_

