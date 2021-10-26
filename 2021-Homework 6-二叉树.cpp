DS Homework 6

1、假设一棵二叉树的先序序列为EBADCFHGIKJ和中序序列为ABCDEFGHIJK，请绘制出该树。
 

2、已知一棵满二叉树的节点个数为20~40之间的素数，此二叉树的叶子节点有多少个？请写出分析和计算过程。
 
3、在二叉树中查找值为x的结点，试设计打印值为x的结点的所有祖先的算法，假设值为x的结点不多于1个。（设计实现要求采用后序遍历的非递归算法）
struct Node{
    int val;
    Node* left;
    Node* right;
};
void findXparents(Node* root,int x)
{
    vector<int> ans;
    stack<Node*> s;
    set<Node*> vis;
    s.push(root);
    while(!root)
    {
        if(root->left && vis.find(root->left)==vis.end())//先访问左子树
        {
            s.push(root->left);
            root=root->left;
        }
        else if(root->right && vis.find(root->right)==vis.end())//再访问右子树
        {
        
            s.push(root->right);
            root=root->right;
        }
        else
        {
            vis.insert(root);//设置此节点已经被处理过
            s.pop();//在栈中弹出此节点
            if(root->val==x)//如果节点是要寻找的节点
            {
                cout<<s.top()->val<<" ";//top()必定是此节点的父节点，打印出来
                s.top()->val=x;//并将父节点的值设置为x,以打印所有的祖先.
            }
            root=s.top();
        }
    }
}
4、假设二叉树以二叉链表的方式进行存储，请结合二叉树层次遍历的方式，设计一个算法，判断一棵二叉树是否为完全二叉树。（注：判断过程需依据完全二叉树的定义进行）。
bool judgeTree(Node* root)
{
    bool toEmpty=false;
    int floor=1;
    queue<Node*> q;
    q.push(root);
    while(q.size())
    {
        auto front=q.front();
        if(!front)
        {
            if(toEmpty)
                return false;
            q.push(front->left);
            q.push(front->right);
        }
        else
            toEmpty=true;
        q.pop();
    }
    return true;
}

