// Project identifier: 9504853406CBAC39EE89AA3AD238AA12CA198043

#ifndef PAIRINGPQ_H
#define PAIRINGPQ_H

#include "Eecs281PQ.h"
#include <deque>
#include <utility>

// A specialized version of the priority queue ADT implemented as a pairing
// heap.
template<typename TYPE, typename COMP_FUNCTOR = std::less<TYPE>>
class PairingPQ : public Eecs281PQ<TYPE, COMP_FUNCTOR> {
    // This is a way to refer to the base class object.
    using BaseClass = Eecs281PQ<TYPE, COMP_FUNCTOR>;

public:
    // Each node within the pairing heap
    class Node {
        public:
            // TODO: After you add add one extra pointer (see below), be sure
            //       to initialize it here.
            explicit Node(const TYPE &val)
                : elt{ val }, child{ nullptr }, sibling{ nullptr }, prev{ nullptr }
            {}

            // Description: Allows access to the element at that Node's
            //              position. There are two versions, getElt() and a
            //              dereference operator, use whichever one seems
            //              more natural to you.
            // Runtime: O(1) - this has been provided for you.
            const TYPE &getElt() const { return elt; }
            const TYPE &operator*() const { return elt; }

            // The following line allows you to access any private data
            // members of this Node class from within the PairingPQ class.
            // (ie: myNode.elt is a legal statement in PairingPQ's add_node()
            // function).
            friend PairingPQ;

        private:
            TYPE elt;
            Node* child;
            Node* sibling;
            Node* prev;
            // TODO: Add one extra pointer (parent or previous) as desired.
    }; // Node


    // Description: Construct an empty pairing heap with an optional
    //              comparison functor.
    // Runtime: O(1)
    explicit PairingPQ(COMP_FUNCTOR comp = COMP_FUNCTOR()) :
        BaseClass{ comp } {
        // TODO: Implement this function.
        root = nullptr;
        quanti = 0;
    } // PairingPQ()


    // Description: Construct a pairing heap out of an iterator range with an
    //              optional comparison functor.
    // Runtime: O(n) where n is number of elements in range.
    template<typename InputIterator>
    PairingPQ(InputIterator start, InputIterator end, COMP_FUNCTOR comp = COMP_FUNCTOR()) :
        BaseClass{ comp } {
        // TODO: Implement this function.
        std::deque<Node*> children;
        for (auto it = start; it != end; ++it) {
            Node* newNode = new Node(*it);
            children.push_back(newNode);
        }
        quanti = children.size();
        while (children.size() > 1) {
            for (size_t i = 0; i < children.size() / 2; ++i) {
                meld(children[0], children[1]);
                Node* merged = children.front();
                children.pop_front();
                children.pop_front();
                children.push_back(merged);
            }
        }
        root = children[0];
    } // PairingPQ()


    // Description: Copy constructor.
    // Runtime: O(n)
    PairingPQ(const PairingPQ &other) :
        BaseClass{ other.compare } {
        // TODO: Implement this function.
        root = nullptr;
        quanti = 0;
        *this = other;
        // NOTE: The structure does not have to be identical to the original,
        //       but it must still be a valid pairing heap.
    } // PairingPQ()


    // Description: Copy assignment operator.
    // Runtime: O(n)
    PairingPQ &operator=(const PairingPQ &rhs) {
        // TODO: Implement this function.
        PairingPQ temp(rhs);
        std::swap(quanti, temp.quanti);
        std::swap(root, temp.root);
        return *this;
        // HINT: Use the copy-swap method from the "Arrays and Containers"
        //       lecture.

    } // operator=()


    // Description: Destructor
    // Runtime: O(n)
    ~PairingPQ() {
        // TODO: Implement this function.
        clean(root);
        root = nullptr;
    } // ~PairingPQ()


    // Description: Assumes that all elements inside the pairing heap are out
    //              of order and 'rebuilds' the pairing heap by fixing the
    //              pairing heap invariant. You CANNOT delete 'old' nodes
    //              and create new ones!
    // Runtime: O(n)
    virtual void updatePriorities() {
        // TODO: Implement this function.
        std::deque<Node*> children;
        upHelper(root, children);
        quanti = children.size();
        while (children.size() > 1) {
            for (size_t i = 0; i < children.size() / 2; ++i) {
                meld(children[0], children[1]);
                Node* merged = children.front();
                children.pop_front();
                children.pop_front();
                children.push_back(merged);
            }
        }
        root = children[0];
    } // updatePriorities()


    // Description: Add a new element to the pairing heap. This is already
    //              done. You should implement push functionality entirely in
    //              the addNode() function, and this function calls
    //              addNode().
    // Runtime: O(1)
    virtual void push(const TYPE &val) {
        addNode(val);
    } // push()


    // Description: Remove the most extreme (defined by 'compare') element
    //              from the pairing heap.
    // Note: We will not run tests on your code that would require it to pop
    //       an element when the pairing heap is empty. Though you are
    //       welcome to if you are familiar with them, you do not need to use
    //       exceptions in this project.
    // Runtime: Amortized O(log(n))
    virtual void pop() {
        // TODO: Implement this function.
        Node* victim = root;
        if (root->child == nullptr)
            root = nullptr;
        else {
            Node* temp = root->child;
            if (temp->sibling == nullptr)
                root = temp;
            else {
                std::deque<Node*> children;
                while (temp != nullptr) {
                    Node* pmet = temp;
                    pmet->sibling = nullptr;
                    pmet->prev = nullptr;
                    children.push_back(pmet);
                    temp = temp->sibling;
                }
                while (children.size() > 1) {                   
                    for (size_t i = 0; i < children.size() / 2; ++i) {
                        meld(children[0], children[1]);
                        Node* merged = children.front();
                        children.pop_front();
                        children.pop_front();
                        children.push_back(merged);
                    }
                }
                root = children[0];
            }
        }
        delete victim;
        quanti--;

    } // pop()


    // Description: Return the most extreme (defined by 'compare') element of
    //              the pairing heap. This should be a reference for speed.
    //              It MUST be const because we cannot allow it to be
    //              modified, as that might make it no longer be the most
    //              extreme element.
    // Runtime: O(1)
    virtual const TYPE &top() const {
        // TODO: Implement this function
        return root->elt;
    } // top()


    // Description: Get the number of elements in the pairing heap.
    // Runtime: O(1)
    virtual std::size_t size() const {
        // TODO: Implement this function
        return quanti; // TODO: Delete or change this line
    } // size()

    // Description: Return true if the pairing heap is empty.
    // Runtime: O(1)
    virtual bool empty() const {
        // TODO: Implement this function
        return quanti == 0;
    } // empty()


    // Description: Updates the priority of an element already in the pairing
    //              heap by replacing the element refered to by the Node with
    //              new_value. Must maintain pairing heap invariants.
    //
    // PRECONDITION: The new priority, given by 'new_value' must be more
    //               extreme (as defined by comp) than the old priority.
    //
    // Runtime: As discussed in reading material.
    void updateElt(Node* node, const TYPE &new_value) {
        // TODO: Implement this function
        node->elt = new_value;
        if (node == root)
            return;
        if (node->sibling != nullptr)
            node->sibling->prev = node->prev;
        if (node->prev->child == node)
            node->prev->child = node->sibling;
        else
            node->prev->sibling = node->sibling;
        node->prev = nullptr;
        node->sibling = nullptr;
        meld(root, node);
    } // updateElt()


    // Description: Add a new element to the pairing heap. Returns a Node*
    //              corresponding to the newly added element.
    // NOTE: Whenever you create a node, and thus return a Node *, you must
    //       be sure to never move or copy/delete that node in the future,
    //       until it is eliminated by the user calling pop(). Remember this
    //       when you implement updateElt() and updatePriorities().
    // Runtime: O(1)
    Node* addNode(const TYPE &val) {
        // TODO: Implement this function
        Node* newNode = new Node(val);
        if (root == nullptr)
            root = newNode;
        else
            meld(root, newNode);
        quanti++;
        return newNode;
    } // addNode()


private:
    // TODO: Add any additional member variables or member functions you
    //       require here.
    Node* root;
    size_t quanti;
    // TODO: We recommend creating a 'meld' function (see the Pairing Heap
    //       papers).
    void meld(Node*& subj, Node* obj) {
        if (obj == nullptr)
            return;
        if (this->compare(obj->elt, subj->elt)) {
            obj->prev = subj;
            if (subj->child != nullptr)
                subj->child->prev = obj;
            obj->sibling = subj->child;
            subj->child = obj;
        }
        else {
            subj->prev = obj;
            if (obj->child != nullptr)
                obj->child->prev = subj;
            subj->sibling = obj->child;
            obj->child = subj;
            subj = obj;
        }
    }
    void clean(Node* node) {
        if (node != nullptr) {
            clean(node->child);
            clean(node->sibling);
            delete node;
        }
    }
    void upHelper(Node* node, std::deque<Node*> &children) {
        if (node == nullptr)
            return;
        children.push_back(node);
        upHelper(node->child, children);
        upHelper(node->sibling, children);
    }
    // NOTE: For member variables, you are only allowed to add a "root
    //       pointer" and a "count" of the number of nodes. Anything else
    //       (such as a deque) should be declared inside of member functions
    //       as needed.

};


#endif // PAIRINGPQ_H
