#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class TreeNode
{
public:
    explicit TreeNode(int x) : num(x) {}

    void set_left(std::unique_ptr<TreeNode> &&node) noexcept
    {
        left = std::move(node);
    }

    void set_right(std::unique_ptr<TreeNode> &&node) noexcept
    {
        right = std::move(node);
    }

    void preorder_traversal() const noexcept
    {
        cout << num << ' ';
        if (left != nullptr)
            left->preorder_traversal();
        if (right != nullptr)
            right->preorder_traversal();
    }

    void inorder_traversal() const noexcept
    {
        if (left != nullptr)
            left->inorder_traversal();
        cout << num << ' ';
        if (right != nullptr)
            right->inorder_traversal();
    }

    void postorder_traversal() const noexcept
    {
        if (left != nullptr)
            left->postorder_traversal();
        if (right != nullptr)
            right->postorder_traversal();
        cout << num << ' ';
    }

private:
    int num;
    std::unique_ptr<TreeNode> left = nullptr;
    std::unique_ptr<TreeNode> right = nullptr;
};

auto bt_solve(const std::vector<int> &pre,
              size_t pre_l,
              size_t pre_r,
              const std::vector<int> &in,
              size_t in_l,
              size_t in_r) -> std::unique_ptr<TreeNode>
{

    if (pre_l > pre_r)
        return nullptr;
    else if (pre_l == pre_r)
        return std::make_unique<TreeNode>(pre[pre_l]);
    else
    {
        auto node = std::make_unique<TreeNode>(pre[pre_l]);

        size_t tmp = in_l;
        while (pre[pre_l] != in[tmp])
            tmp++;

        size_t leftTreeSize = tmp - in_l;

        node->set_left(std::move(bt_solve(pre, pre_l + 1, pre_l + leftTreeSize, in, in_l, tmp - 1)));
        node->set_right(std::move(bt_solve(pre, pre_l + leftTreeSize + 1, pre_r, in, tmp + 1, in_r)));

        return node;
    }
}

auto solve(const std::vector<int> &pre, const std::vector<int> &in) -> std::unique_ptr<TreeNode>
{
    return bt_solve(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    std::vector<int> preorder;
    std::vector<int> inorder;
    int n;

    cin >> n;
    {
        int temp;
        for (size_t i(0); i < n; i++)
        {
            cin >> temp;
            preorder.emplace_back(temp);
        }
        for (size_t i(0); i < n; i++)
        {
            cin >> temp;
            inorder.emplace_back(temp);
        }
    }

    auto root = solve(preorder, inorder);

    root->postorder_traversal();
    return 0;
}