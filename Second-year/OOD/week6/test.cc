#include "gtest/gtest.h"
#include "node.h"
#include "int_node.h"
#include "string_node.h"
#include "tree_util.h"

class TreeUtilTest : public ::testing::Test {
 public:
    TreeUtilTest() : treeUtil(TreeUtil::GetInstance()) {}

 protected:
    void SetUp() override {}
    void TearDown() override {}
    TreeUtil* treeUtil;
};

TEST_F(TreeUtilTest, PreTest1) {
    StringNode* na = new StringNode("a", NULL, NULL);
    StringNode* nc = new StringNode("c", NULL, NULL);
    StringNode* nb = new StringNode("b", na, NULL);
    IntNode* n4 = new IntNode(4, nb, nc);
    EXPECT_EQ(treeUtil->PreOrderTraversal(n4), "4,b,a,c");
    delete n4;
}

TEST_F(TreeUtilTest, PreTest2) {
    StringNode* nqmark = new StringNode("?", NULL, NULL);
    StringNode* nasterisk = new StringNode("*", NULL, NULL);
    IntNode* n1 = new IntNode(1, nqmark, NULL);
    StringNode* nslash = new StringNode("/", NULL, nasterisk);
    StringNode* nplus = new StringNode("+", nslash, n1);
    EXPECT_EQ(treeUtil->PreOrderTraversal(nplus), "+,/,*,1,?");
    delete nplus;
}

TEST_F(TreeUtilTest, PreTest3) {
    IntNode* n00 = new IntNode(0, NULL, NULL);
    StringNode* nG = new StringNode("G", NULL, NULL);
    IntNode* n0 = new IntNode(0, NULL, nG);
    StringNode* nD = new StringNode("D", n00, NULL);
    StringNode* nC = new StringNode("C", NULL, n0);
    StringNode* nB = new StringNode("B", nD, NULL);
    StringNode* nA = new StringNode("A", nB, nC);
    EXPECT_EQ(treeUtil->PreOrderTraversal(nA), "A,B,D,0,C,0,G");
    delete nA;
}

TEST_F(TreeUtilTest, InTest1) {
    StringNode* na = new StringNode("a", NULL, NULL);
    StringNode* nc = new StringNode("c", NULL, NULL);
    StringNode* nb = new StringNode("b", na, NULL);
    IntNode* n4 = new IntNode(4, nb, nc);
    EXPECT_EQ(treeUtil->InOrderTraversal(n4), "a,b,4,c");
    delete n4;
}

TEST_F(TreeUtilTest, InTest2) {
    StringNode* nqmark = new StringNode("?", NULL, NULL);
    StringNode* nasterisk = new StringNode("*", NULL, NULL);
    IntNode* n1 = new IntNode(1, nqmark, NULL);
    StringNode* nslash = new StringNode("/", NULL, nasterisk);
    StringNode* nplus = new StringNode("+", nslash, n1);
    EXPECT_EQ(treeUtil->InOrderTraversal(nplus), "/,*,+,?,1");
    delete nplus;
}

TEST_F(TreeUtilTest, InTest3) {
    IntNode* n00 = new IntNode(0, NULL, NULL);
    StringNode* nG = new StringNode("G", NULL, NULL);
    IntNode* n0 = new IntNode(0, NULL, nG);
    StringNode* nD = new StringNode("D", n00, NULL);
    StringNode* nC = new StringNode("C", NULL, n0);
    StringNode* nB = new StringNode("B", nD, NULL);
    StringNode* nA = new StringNode("A", nB, nC);
    EXPECT_EQ(treeUtil->InOrderTraversal(nA), "0,D,B,A,C,0,G");
    delete nA;
}

TEST_F(TreeUtilTest, postTest1) {
    StringNode* na = new StringNode("a", NULL, NULL);
    StringNode* nc = new StringNode("c", NULL, NULL);
    StringNode* nb = new StringNode("b", na, NULL);
    IntNode* n4 = new IntNode(4, nb, nc);
    EXPECT_EQ(treeUtil->PostOrderTraversal(n4), "a,b,c,4");
    delete n4;
}

TEST_F(TreeUtilTest, postTest2) {
    StringNode* nqmark = new StringNode("?", NULL, NULL);
    StringNode* nasterisk = new StringNode("*", NULL, NULL);
    IntNode* n1 = new IntNode(1, nqmark, NULL);
    StringNode* nslash = new StringNode("/", NULL, nasterisk);
    StringNode* nplus = new StringNode("+", nslash, n1);
    EXPECT_EQ(treeUtil->PostOrderTraversal(nplus), "*,/,?,1,+");
    delete nplus;
}

TEST_F(TreeUtilTest, postTest3) {
    IntNode* n00 = new IntNode(0, NULL, NULL);
    StringNode* nG = new StringNode("G", NULL, NULL);
    IntNode* n0 = new IntNode(0, NULL, nG);
    StringNode* nD = new StringNode("D", n00, NULL);
    StringNode* nC = new StringNode("C", NULL, n0);
    StringNode* nB = new StringNode("B", nD, NULL);
    StringNode* nA = new StringNode("A", nB, nC);
    EXPECT_EQ(treeUtil->PostOrderTraversal(nA), "0,D,B,G,0,C,A");
    delete nA;
}
