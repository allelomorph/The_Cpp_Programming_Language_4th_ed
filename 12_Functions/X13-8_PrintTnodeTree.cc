#include <string>
#include <vector>
#include <iostream>
#include "X13-8_PrintTnodeTree.hh"


namespace X13_8 {


// Adapted from http://stackoverflow.com/a/13755911/5184480


static int DrawTnodeTree(const Tnode *tree, const int offset, const int depth,
                         std::vector<std::string> &lines,
                         bool left_child) {
    if (tree == nullptr)
        return 0;

    std::string fmtd_word {"(\""};
    fmtd_word += tree->word;
    fmtd_word += "\")";  // "(\"" + tree->word + "\")" causes type error
    // node representation char count
    int n_width (fmtd_word.size());
    // left branch length in chars
    int lb_len {DrawTnodeTree(tree->left, offset, depth + 1,
                              lines, (tree->left != nullptr))};
    // right branch length in chars
    int rb_len {DrawTnodeTree(tree->right, offset + lb_len + n_width, depth + 1,
                              lines, false)};

    // write representation of current node to current depth's line
    for (auto i {0}; i < n_width; ++i)
        lines[depth][offset + lb_len + i] = fmtd_word[i];

    if (depth) {
        if (left_child) {
            // draw connecting branch from left of parent node on line above
            for (auto i {0}; i < n_width + rb_len; ++i)
                lines[depth - 1][offset + lb_len + n_width / 2 + i] = '-';
            lines[depth - 1][offset + lb_len + n_width / 2] = '.';
        } else {
            // from right of parent node
            for (auto i {0}; i < lb_len + n_width; ++i)
                lines[depth - 1][offset - n_width / 2 + i] = '-';
            lines[depth - 1][offset + lb_len + n_width / 2] = '.';
        }
    }
    return (lb_len + n_width + rb_len);
}


static size_t TnodeTreeHeight(const Tnode *tree) {
    std::size_t height_l {tree->left ? 1 + TnodeTreeHeight(tree->left) : 0};
    std::size_t height_r {tree->right ? 1 + TnodeTreeHeight(tree->right) : 0};
    return (height_l > height_r) ? height_l : height_r;
}


void PrintTnodeTree(const Tnode *tree) {
    if (!tree)
        return;
    constexpr int dflt_line_width {300};
    std::vector<std::string> lines;
    std::size_t height {TnodeTreeHeight(tree)};
    for (std::size_t i {0}; i < height + 1; ++i)
        lines.push_back(std::string(dflt_line_width, ' '));

    DrawTnodeTree(tree, 0, 0, lines, false);
    for (auto &line : lines) {
        // trim trailing whitespace from lines
        for (std::size_t j {dflt_line_width - 1};
             j > 1 && line[j] == ' '; --j)
            line[j] = '\0';
        std::cout << line << std::endl;
    }
}


}  // namespace X13_8
