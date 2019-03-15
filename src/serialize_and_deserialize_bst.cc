#include "code_utils.h"
#include <limits.h>
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string str;
        serialize_internal(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
       const int* array = reinterpret_cast<const int*> (str.data());
       int pos = 0;
       int len = str.size()/sizeof(int);
       /*
       for(auto i = 0; i < len; ++i) {
            printf("array[%d] = %d\n",i , array[i]);
       }
       */
       return deserialize_internal(array, len,
                                   pos, INT_MIN, INT_MAX); 
    }
private:
    TreeNode* deserialize_internal(const int* array, int len, int& pos,
                                  int low, int high) {
        if (pos >= len) {
            return  nullptr;
        }
        int val = array[pos];
        TreeNode* root = new TreeNode(val);
        //printf("array[%d] = %d\t%d\t%.d\t%d\n", pos, val, low, val, high);
		// 为什么在前面添加递归条件的判断会更慢呢？
        if (low > val || val > high) {
            return nullptr;
        }
        ++pos;
        root->left = deserialize_internal(array, len,
                                          pos, low, val);
        root->right= deserialize_internal(array, len,
                                          pos, val, high);
        return root;

    }
        
    void serialize_internal(TreeNode* root, string& str ) {
        if (!root) {
            return ;
        }
        
        const char* val_str = reinterpret_cast<const char*>(&root->val);
        str.append(val_str, sizeof(root->val));
        serialize_internal(root->left, str);
        serialize_internal(root->right, str);
        }
};
