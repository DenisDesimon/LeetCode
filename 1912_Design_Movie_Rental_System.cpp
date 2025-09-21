//#1912 Design Movie Rental System  - https://leetcode.com/problems/design-movie-rental-system/
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

class MovieRentingSystem {
private:
    vector<set<pair<int, int>>> moviesPriceShop = vector<set<pair<int, int>>>(10000);
    vector<set<pair<int, int>>> moviesShopPrice = vector<set<pair<int, int>>>(10000);
    set<pair<int, pair<int,int>>> PriceShopRented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry: entries)
        {
            moviesPriceShop[entry[1]].insert({entry[2], entry[0]});
            moviesShopPrice[entry[1]].insert({entry[0], entry[2]});
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        auto iter = moviesPriceShop[movie].begin();
        for(int i = 0; i < 5 && iter != moviesPriceShop[movie].end(); i++, iter++)
            result.push_back(iter->second);
        return result;
    }

    void rent(int shop, int movie) {
        int price = moviesShopPrice[movie].lower_bound({shop, INT_MIN})->second;
        moviesPriceShop[movie].erase({price, shop});
        PriceShopRented.insert({price, {shop, movie}});
    }

    void drop(int shop, int movie) {
        int price = moviesShopPrice[movie].lower_bound({shop, INT_MIN})->second;
        moviesPriceShop[movie].insert({price, shop});
        PriceShopRented.erase({price, {shop, movie}});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        auto iter = PriceShopRented.begin();
        for(int i = 0; i < 5 && iter != PriceShopRented.end(); i++, iter++)
            result.push_back({iter->second.first, iter->second.second});
        return result;
    }
};

int main()
{
    int givenN = 3;
    vector<vector<int>> givenEntries = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
    MovieRentingSystem solution(givenN, givenEntries);
    vector<int> expectedAnswer = {1, 0, 2};
    int givenMovie = 1;
    assert(solution.search(givenMovie) == expectedAnswer);

    int givenShop = 0;
    givenMovie = 1;
    solution.rent(givenShop, givenMovie);

    givenShop = 1;
    givenMovie = 2;
    solution.rent(givenShop, givenMovie);

    vector<vector<int>> expectedReport = {{0, 1}, {1, 2}};
    assert(solution.report() == expectedReport);

    return 0;
}
