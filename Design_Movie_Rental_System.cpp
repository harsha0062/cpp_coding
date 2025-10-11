#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// MovieRentingSystem class definition with all required methods and comments
class MovieRentingSystem {
public:
    // Stores rented movies as set of {price, shop, movie}
    set<vector<int>> rented;
    // For each movie, stores a set of {price, shop}, sorted by price then shop
    unordered_map<int, set<vector<int>>> unrented;
    // price[movie][shop] gives the price of renting 'movie' at 'shop'
    unordered_map<int, unordered_map<int, int>> price;

    // Constructor: Initialize system with entries [shop, movie, price]
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto i : entries) {
            int shop = i[0];
            int movie = i[1];
            int p = i[2];
            unrented[movie].insert({p, shop});
            price[movie][shop] = p;
        }
    }

    // Returns up to 5 cheapest shops that have this movie available (sorted by price, then shop)
    vector<int> search(int movie) {
        if (unrented.find(movie) == unrented.end())
            return {};
        vector<int> ans;
        for (auto i : unrented[movie]) {
            int shop = i[1];
            ans.push_back(shop);
            if (ans.size() == 5) {
                break;
            }
        }
        return ans;
    }

    // Rents the movie from a given shop: remove from unrented, add to rented
    void rent(int shop, int movie) {
        int p = price[movie][shop];
        unrented[movie].erase(unrented[movie].find({p, shop}));
        rented.insert({p, shop, movie});
    }

    // Drops (returns) the movie to a shop: remove from rented, add to unrented
    void drop(int shop, int movie) {
        int p = price[movie][shop];
        rented.erase({p, shop, movie});
        unrented[movie].insert({p, shop});
    }

    // Reports up to 5 currently rented movies: sorted by price, shop index, movie index
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto i : rented) {
            int shop = i[1];
            int movie = i[2];
            ans.push_back({shop, movie});
            if (ans.size() == 5)
                break;
        }
        return ans;
    }
};

int main() {
    // Example input data: vector of [shop, movie, price]
    vector<vector<int>> entries = {
        {0, 1, 5},
        {0, 2, 6},
        {0, 3, 7},
        {1, 1, 4},
        {1, 2, 7},
        {2, 1, 5}
    };

    // Create system with n = 3 shops
    MovieRentingSystem obj(3, entries);

    // Search for shops that have movie 1
    vector<int> result = obj.search(1);
    cout << "Search for movie 1: ";
    for (int shop : result) cout << shop << " ";
    cout << endl;

    // Rent movie 1 from shop 0
    obj.rent(0, 1);

    // Report rented movies
    vector<vector<int>> rented_list = obj.report();
    cout << "Rented movies: ";
    for (auto v : rented_list) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;

    // Drop (return) movie 1 to shop 0
    obj.drop(0, 1);

    // Report rented movies after drop
    rented_list = obj.report();
    cout << "Rented movies after drop: ";
    for (auto v : rented_list) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;

    return 0;
}
