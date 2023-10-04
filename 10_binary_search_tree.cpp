#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val <= root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

TreeNode* createBST(vector<int>& nums) {
    TreeNode* root = nullptr;
    for (int num : nums) root = insert(root, num);
    return root;
}

void heapify(TreeNode* root, vector<int>& maxHeap) {
    if (!root) return;
    maxHeap.push_back(root->data);
    int index = maxHeap.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (maxHeap[index] <= maxHeap[parentIndex]) break;
        swap(maxHeap[index], maxHeap[parentIndex]);
        index = parentIndex;
    }

    heapify(root->left, maxHeap);
    heapify(root->right, maxHeap);
}

void heapSort(TreeNode* root) {
    vector<int> maxHeap;
    heapify(root, maxHeap);
    int n = maxHeap.size();

    for (int i = n - 1; i >= 0; i--) {
        swap(maxHeap[0], maxHeap[i]);

        int index = 0, leftChild, rightChild, maxIndex;

        while (true) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            maxIndex = index;

            if (leftChild < i && maxHeap[leftChild] > maxHeap[maxIndex]) maxIndex = leftChild;
            if (rightChild < i && maxHeap[rightChild] > maxHeap[maxIndex]) maxIndex = rightChild;
            if (maxIndex == index) break;

            swap(maxHeap[index], maxHeap[maxIndex]);
            index = maxIndex;
        }
    }

    cout << "Sorted List (Heap Sort): ";
    for (int num : maxHeap) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    TreeNode* root = createBST(nums);

    int choice;
    cout << "1. Create BST\n";
    cout << "2. Heap Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Create BST
            break;

        case 2:
            // Heap Sort
            heapSort(root);
            break;

        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}
