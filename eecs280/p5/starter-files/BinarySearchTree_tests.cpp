// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"
#include <sstream>

using namespace std;


TEST(test_stub) {
    // Add your tests here
    ASSERT_TRUE(true);
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());
    tree.insert(1);
    tree.insert(5);
    tree.insert(9);
    tree.insert(6);
    tree.insert(3);
    ASSERT_TRUE(!tree.empty());
    ASSERT_TRUE(tree.size() == 5);
    ASSERT_TRUE(tree.height() == 4);
    ostringstream oss_preorder;
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "1 5 3 9 6 ");
    ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 3 5 6 9 ");
    ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(test_iterator) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.begin() == tree.end());
    ASSERT_TRUE(tree.begin() == tree.min_element());
    ASSERT_TRUE(tree.begin() == tree.max_element());
    tree.insert(1);
    tree.insert(5);
    tree.insert(9);
    tree.insert(6);
    tree.insert(3);
    BinarySearchTree<int>::Iterator it;
    it = tree.begin();
    ASSERT_TRUE(it == tree.begin());
    ASSERT_TRUE(it == tree.min_element())
    ASSERT_TRUE(*it == 1)
    for (int i = 0; i < 4; ++i) ++it;
    ASSERT_TRUE(it == tree.max_element())
    ASSERT_TRUE(it != tree.end());
    ASSERT_TRUE(*it == 9)
    ASSERT_TRUE(tree.min_greater_than(6) == it);
    ASSERT_TRUE(tree.min_greater_than(5) != it);
    ASSERT_TRUE(tree.min_greater_than(9) != it);
    ASSERT_TRUE(tree.min_greater_than(9) == tree.end());
    ASSERT_TRUE(tree.find(9) == it);
    it++;
    ASSERT_TRUE(it == tree.end());
    ASSERT_TRUE(tree.find(7) == it);
    it = tree.insert(0);
    ASSERT_TRUE(it == tree.begin());
}

TEST(test_copy) {
    BinarySearchTree<int> eert;
    eert.insert(1);
    eert.insert(5);
    eert.insert(9);
    eert.insert(6);
    eert.insert(3);
    BinarySearchTree<int> reet = eert;
    BinarySearchTree<int> tree(reet);
    ASSERT_TRUE(!tree.empty());
    ASSERT_TRUE(tree.size() == 5);
    ASSERT_TRUE(tree.height() == 4);
    ostringstream oss_preorder;
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "1 5 3 9 6 ");
    ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 3 5 6 9 ");
    ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(bst_public_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);

  ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1);

  ASSERT_TRUE(tree.find(5) != tree.end());

  tree.insert(7);
  tree.insert(3);

  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 7);
  ASSERT_TRUE(*tree.min_element() == 3);
  ASSERT_TRUE(*tree.min_greater_than(5) == 7);

  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;

  cout << "cout << tree" << endl << "(uses iterators)" << endl;
  cout << tree << endl << endl;

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "5 3 7 ");

  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "3 5 7 ");
}

TEST_MAIN()
