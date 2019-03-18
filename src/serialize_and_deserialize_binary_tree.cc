#include "code_utils.h"
#include <limits.h>
// 用到了memcpy，不是将整数转换为字符串再copy，有利于节省效率
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
       for(auto i = 0; i < len; ++i) {
            printf("array[%d] = %d\n",i , array[i]);
       }
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
        printf("array[%d] = %d\t%d\t%d\n", pos, low, val, high);
        if (low < val || val > high) {
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
        serialize_internal(root->left, str);
        // 此处传递的为 root->val 的地址
        const char* val_str = reinterpret_cast<const char*>(&root->val);
        str.append(val_str, sizeof(root->val));
        serialize_internal(root->right, str);
	}
};
int main(int argc, char *argv[])
{
    (void)argc; 
    (void)argv;
    return 0;
}
