#include <vector>
#include <iostream>
using namespace std;

struct Item {
    string itemName;
    int priceDollars;
};

const int MAX_ITEMS_IN_SHOPPING_BAG = 3;

vector<vector<Item>> ShoppingBagCombinations(vector<Item> currBag, vector<Item> remainingItems) {
    vector<vector<Item>> combinations;
    int bagValue;
    Item tmpGroceryItem;
    unsigned int i;

    if (currBag.size() == MAX_ITEMS_IN_SHOPPING_BAG) {
        combinations.push_back(currBag);
    } else {
        for (i = 0; i < remainingItems.size(); ++i) {
            tmpGroceryItem = remainingItems.at(i);
            remainingItems.erase(remainingItems.begin() + i);
            currBag.push_back(tmpGroceryItem);

            vector<vector<Item>> subCombinations = ShoppingBagCombinations(currBag, remainingItems);
            combinations.insert(combinations.end(), subCombinations.begin(), subCombinations.end());
            //subCombinations.clear();
            remainingItems.insert(remainingItems.begin() + i, tmpGroceryItem);
            currBag.pop_back();
        }
    }

    return combinations;
}

int main() {
    vector<Item> items = {{"Apple", 1}, {"Banana", 2}, {"Orange", 3}, {"Grapes", 4}};
    vector<Item> currBag;
    vector<vector<Item>> result = ShoppingBagCombinations(currBag, items);

    for (const auto& bag : result) {
        int bagValue = 0;
        for (const auto& item : bag) {
            cout << item.itemName << " ";
            bagValue += item.priceDollars;
        }
        cout << "= $" << bagValue << endl;
    }

    return 0;
}