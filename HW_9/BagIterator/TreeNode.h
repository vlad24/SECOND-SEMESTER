#pragma once

template <typename O>
class TreeNode
{
public:
    O value;
    int reps;
    TreeNode* left;
    TreeNode* right;
};
