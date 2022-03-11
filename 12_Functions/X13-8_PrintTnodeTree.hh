#ifndef X13_8_PRINTTNODETREE_HH
#define X13_8_PRINTTNODETREE_HH


namespace X13_8 {


/**
 * struct Tnode - binary tree node for storing strings in collated order
 * @word: C string containing no whitespace
 * @left: pointer to left child, or nullptr
 * @right: pointer to left child, or nullptr
 */
struct Tnode_s {
    const char *word {nullptr};
    Tnode_s* left    {nullptr};
    Tnode_s* right   {nullptr};
};
using Tnode = struct Tnode_s;


void PrintTnodeTree(const Tnode *tree);


}  // namespace X13_8


#endif  // X13_8_PRINTTNODETREE_HH
