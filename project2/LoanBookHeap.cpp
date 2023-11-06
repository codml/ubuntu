#include "LoanBookHeap.h"

void LoanBookHeap::heapifyUp(LoanBookHeapNode* pN) {
    LoanBookData        *tmp;
    
    if (pN == root || pN->getBookData()->getName() > pN->getParent()->getBookData()->getName())
        return;
    tmp = pN->getBookData();
    pN->setBookData(pN->getParent()->getBookData());
    pN->getParent()->setBookData(tmp);
    heapifyUp(pN->getParent());
}

void LoanBookHeap::heapifyDown(LoanBookHeapNode* pN) {

}

bool LoanBookHeap::Insert(LoanBookData* data) {
    LoanBookHeapNode    *node;

    node = new LoanBookHeapNode;
    node->setBookData(data);
    if (root == NULL)
    {
        root = node;
        v.push_back(node);
        return true;
    }
    if (v.size() % 2)
        v.at(v.size() / 2)->setRightChild(node);
    else
        v.at(v.size() / 2)->setLeftChild(node);
    node->setParent(v.at(v.size() / 2));
    v.push_back(node);
    heapifyUp(node);
    return true;
}