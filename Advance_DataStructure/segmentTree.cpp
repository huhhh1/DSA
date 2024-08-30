#include <bits/stdc++.h>
using namespace std;
struct node
{
    struct node *left;
    struct node *right;
    int val;
};

// int defined_function(int i, int j)
// {

// }
struct node *b(int left, int right, int arr[])
{
    if (left <= right)
    {
        struct node *temp;
        int mid = left + (right - left) / 2;
        temp->left = b(left, mid, arr);
        temp->right = b(mid + 1, right, arr);
        // Here We have the Query Which we can Execute : -
        temp->val = max(arr[left], arr[right]);
        return temp;
    }
    return NULL;
}
int q(struct node *segment, int l, int r, int left, int right)
{

    if (l >= left && r <= right)
        return segment->val;
    else if (l >= left || r <= right)
    {
        int mid = left + (right - left) / 2;
        int li = q(segment->left, l, r, left, mid);
        int ri = q(segment->right, l, r, mid + 1, right);
        return max(li, ri);
    }
    else
        return INT_MIN;
};
int segemnt[1000000];
int arr[1000000];
int lazy[1000000];

void build(int index, int low, int high)
{
    if (low == high)
    {
        segemnt[index] = arr[low];
        return;
    }
    int mid = low + ((high - low) / 2);
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);
    segemnt[index] = max(segemnt[(2 * index) + 1], segemnt[(2 * index) + 2]);
    return;
}
//------------------------------------------------------------------------------------------------------
// Point Update :
void update(int index, int low, int high, int key, int value)
{
    if (low == key && high == key)
    {
        segemnt[index] = value;
        return;
    }
    int mid = low + ((high - low) / 2);

    // For the finding the correct route we can use the rangee of low-mid-high if it's Exitst on under the mid and greater the high that go for left side else right side
    if (key <= mid && key >= high)
        update(2 * index + 1, low, mid, key, value);
    else
        update(2 * index + 2, mid + 1, high, key, value);
    segemnt[index] = max(segemnt[(2 * index) + 1], segemnt[(2 * index) + 2]);
    return;
}

//--------------------------------------------------------------------------------------------------------

// Query

int query(int index, int low, int high, int l, int r)
{
    if (low >= l && r >= high)
        return segemnt[index];
    if (high < l || low > r)
        return INT_MIN;
    int mid = low + ((high - low) / 2);
    int left = query((2 * index) + 1, low, mid, l, r);
    int right = query((2 * index) + 2, mid + 1, high, l, r);
    return max(left, right);
}

//----------------------------------------------------------------------------------------------------------------

// Lazy Propagation in Segment Tree
void lazyUpdate(int index, int low, int high, int l, int r, int val)
{

    if (lazy[index] != 0)
    {
        segemnt[index] += ((high - low + 1) * lazy[index]);
        if (high != low)
        {
            lazy[index * 2 + 1] += lazy[index];
            lazy[index * 2 + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (high < low || l > high || r < l)
        return;

    if (low >= l && r <= high)
    {
        segemnt[index] += (val * (high - low + 1));
        if (high != low)
        {
            lazy[index * 2 + 1] += val;
            lazy[index * 2 + 2] += val;
        }
        return;
    }
    int mid = (low + high) >> 1;
    lazyUpdate(index * 2 + 1, low, mid, l, r, val);
    lazyUpdate(index * 2 + 2, low, mid + 1, high, r, val);
    segemnt[index] = segemnt[index * 2 + 1] + segemnt[index * 2 + 2];
    return;
}

int lazyQuerySum(int index, int low, int high, int l, int r)
{
    if (lazy[index] != 0)
    {
        segemnt[index] += ((high - low + 1) * lazy[index]);
        if (high != low)
        {
            lazy[index * 2 + 1] += lazy[index];
            lazy[index * 2 + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (high < low || l > high || r < l)
        return;
    if (low >= l && r <= high)
    {   
        return segemnt[index];
    }
    int mid = (low + high) >> 1;
    lazyUpdate(index * 2 + 1, low, mid, l, r, val);
    lazyUpdate(index * 2 + 2, low, mid + 1, high, r, val);
    segemnt[index] = segemnt[index * 2 + 1] + segemnt[index * 2 + 2];
    return;
}

//----------------------------------------------------------------------------------------------------------------
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << "\n";
    }
    return 0;
}

// 8
// 4 3 1 2 5 6 7 2
// 5
// 0 7
// 0 5
// 4 7
// 3 4
// 2 6