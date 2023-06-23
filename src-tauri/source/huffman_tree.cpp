#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

// 树结点
struct TreeNode
{
    double weight;                 // 权值
    char ch;                       // 字符
    struct TreeNode *left = NULL;  // 左孩子
    struct TreeNode *right = NULL; // 右孩子
};

map<string, char> m; // 定义一个map
bool cmp(TreeNode a, TreeNode b);
TreeNode *createTree(TreeNode *v, int n);
void printCode(struct TreeNode *root, char code[], int location);
void f_decode(string decoding, int len);
// 升序

int main()
{
    int n;
    cin >> n;
    getchar();
    // 定义n个结点，使用vector存放
    TreeNode nodes[2 * n - 1];
    // 输入n个结点
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        stringstream inputline(line);
        inputline >> nodes[i].ch >> nodes[i].weight;
    }
    // 输入需进行译码的串
    string decoding;
    getline(cin, decoding);
    int len = decoding.length(); // 统计长度
    TreeNode *root = createTree(nodes, n);
    char code[60] = {0}; // 存储字符的编码
    // 先序顺序输出所有字符的编码
    printCode(root, code, 0);
    f_decode(decoding, len);
    return 0;
}
// 创建树
TreeNode *createTree(TreeNode *v, int n)
{
    int i = 0, index = n; // i为0 ，从位置0开始合成。index是生成的结点该放的地方
    while (i < 2 * n - 1) // 当i走到最后一个结点，无需再构建，也可以使用index控制
    {
        // 1.先排序
        sort(v + i, v + index, cmp); // 只对范围内的排序。随两个索引变化，排序的范围也变化
        // 2.合并:拿出排好序序列中的前两个结点。
        TreeNode *node1 = &v[i++];
        TreeNode *node2 = &v[i++];
        // 3.生成新节点，给结点赋值
        TreeNode newNode;
        newNode.weight = node1->weight + node2->weight; // 权值相加
        newNode.ch = '-';                               // 随意设置，表示其为中间结点。
        newNode.left = node1;                           // 设置左右孩子
        newNode.right = node2;
        // 4.新节点放入到序列中
        v[index++] = newNode;
    }
    return &v[2 * n - 2]; // 最后一个为根节点
}

bool cmp(TreeNode a, TreeNode b)
{
    return a.weight < b.weight; // 根据权值升序排序
}

// 解码 ，码——>原文
void f_decode(string decoding, int len)
{
    string str;
    int i = 0;
    printf("original:");
    for (i = 0; i < len; i++)
    {
        str += decoding[i]; // 拼接key
        if (m.find(str) != m.end())
        { // 找到了key，输出
            printf("%c", m[str]);
            str = ""; // 清空key，重新拼接
        }
    }
}

// 先序顺序输出所有字符的编码
void printCode(TreeNode *root, char code[], int location)
{
    if (root == NULL)
    {
        return;
    }
    if (root->ch != '-') // 说明已经遍历到叶子节点，输出序列
    {
        printf("%c:", root->ch);
        string key = "";
        for (int i = 0; i < location; i++)
        { // 输出记录的长度。
            printf("%d", code[i]);
            key += to_string(code[i]); // to_string()将参数转为string类型
        }
        printf("\n");
        // cout<<"key:"<<key<<","<<"value："<<root->ch<<endl;
        m.insert(make_pair(key, root->ch)); // 将值以键值对的形式插入到map中
    }
    // 该节点是左孩子,路径设0
    code[location] = 0;
    location++;                            // 下一个位置给下一个节点用
    printCode(root->left, code, location); // 递归该节点。
    location--;                            // 该节点递归完成。取消该节点的记录。

    // 右孩子,1
    code[location] = 1;
    location++;
    printCode(root->right, code, location);
    location--;
}