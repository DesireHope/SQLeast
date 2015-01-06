#include <tclDecls.h>
#include <tkDecls.h>
#include "ix/index.h"

namespace sqleast {
    namespace ix {

        int Node::getPosition(int value) {
            int lo = 0;
            int hi = size;
            int mi;
            while(lo < hi){
                mi = (lo + hi) / 2;
                if(k[mi] == value)
                    return mi;
                if(k[mi] < value)
                    lo = mi + 1;
                else
                    hi = mi;
            }
            return lo - 1;
        }

        bool Node::insertK(int value, int position) {
            if(isLeaf && size == B_PLUS_TREE_BRANCH + 1)
                return false;
            if(!isLeaf && size == B_PLUS_TREE_BRANCH)
                return false;
            size ++;
            for(int i = B_PLUS_TREE_BRANCH ; i > position ; i --)
                k[i] = k[i-1];
            k[position] = value;
            return true;
        }

        bool Node::insertN(RID value, int position) {
            if(size == B_PLUS_TREE_BRANCH + 1)
                return false;
            size ++;
            for(int i = B_PLUS_TREE_BRANCH ; i > position ; i --)
                n[i] = n[i-1];
            n[position] = value;
            return true;
        }

        bool Node::removeK(int position) {
            if(size == 0)
                return false;
            size --;
            for(int i = position ; i < B_PLUS_TREE_BRANCH ; i ++)
                k[i] = k[i+1];
            return true;
        }

        bool Node::removeN(int position) {
            if(size == 0)
                return false;
            size --;
            for(int i = position ; i < B_PLUS_TREE_BRANCH ; i ++)
                n[i] = n[i+1];
            return true;
        }

        RID Index::searchEntry(int key) {
            hot_ = getRootRID();
            Node *v = getNode(hot_);
            while(true){
                int r = v->getPosition(key);
                if(!v->isLeaf){
                    hot_ = v->n[r+1];
                    v = getNode(hot_);
                }
                else{
                    if(r >= 0 && v->k[r] == key){
                        return v->n[r];
                    }
                    else{
                        return RID(-1, r+1); // refer to not find and the second value means the expected position
                    }
                }
            }
        }

        RID Index::insertEntry(int key, RID value) {
            RID v = searchEntry(key);
            if(v.pageNum >= 0)
                return v;
            int posi = v.slotNum;
            Node* leaf = getNode(hot_);
            leaf->insertK(key, posi);
            leaf->insertN(value, posi);
            incIndexSize();
            solveOverFlow(hot_);
            forcePages();
            return value;
        }

        void Index::solveOverFlow(RID rid) {
            Node* v = getNode(rid);
            if(v->isLeaf) {
                if (B_PLUS_TREE_BRANCH + 1 >= v->size) return;
                int half = (B_PLUS_TREE_BRANCH + 1) / 2;
                RID nid = allocateNode();
                Node *n = getNode(nid);
                n->isLeaf = true;
                for (int j = 0; j < B_PLUS_TREE_BRANCH - half; j++) {
                    n->insertN(v->n[half + 1], j);
                    v->removeN(half + 1);
                    n->insertK(v->k[half + 1], j);
                    v->removeK(half + 1);
                }
                if(getRootRID() == rid){
                    RID rt = allocateNode();
                    setRoot(rt);
                    Node* root = getNode(rt);
                    root->isLeaf = false;
                    root->insertN(rid, 0);
                    v->parent = rt;
                }
                RID pid = v->parent;
                Node* p = getNode(pid);
                int rank = p->getPosition(v->k[0]) + 1;
                p->insertK(v->k[half], rank);
                p->insertN(nid, rank + 1);
                n->parent = pid;
                solveOverFlow(pid);
            }
            else
            {
                if (B_PLUS_TREE_BRANCH >= v->size) return;
                int half = (B_PLUS_TREE_BRANCH + 1) / 2;
                RID nid = allocateNode();
                Node *n = getNode(nid);
                n->isLeaf = false;
                for (int j = 0; j < B_PLUS_TREE_BRANCH - half ; j++) {
                    n->insertN(v->n[half + 1], j);
                    v->removeN(half + 1);
                    n->insertK(v->k[half + 1], j);
                    v->removeK(half + 1);
                }
                n->insertN(v->n[half + 1], B_PLUS_TREE_BRANCH - half);
                v->removeN(half + 1);
                if(getRootRID() == rid){
                    RID rt = allocateNode();
                    setRoot(rt);
                    Node* root = getNode(rt);
                    root->isLeaf = false;
                    root->insertN(rid, 0);
                    v->parent = rt;
                }
                RID pid = v->parent;
                Node* p = getNode(pid);
                int rank = p->getPosition(v->k[0]) + 1;
                p->insertK(v->k[half], rank);
                p->insertN(nid, rank + 1);
                v->removeK(half);
                n->parent = pid;
                solveOverFlow(pid);
            }
        }

        Node *Index::getRoot() {
            return getNode(getRootRID());
        }

    }
}