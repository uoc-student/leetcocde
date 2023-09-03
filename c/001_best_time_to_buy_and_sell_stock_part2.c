// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/

#include <assert.h>

int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int price_difference = 0;

    for (int i = 0; i < pricesSize - 1; i++) {
        price_difference = prices[i + 1] - prices[i];
        if (price_difference > 0) {
            profit += price_difference;
        }
    }

    return profit;
}

void test1() {
    int prices_size = 6;
    int prices[] = {7,1,5,3,6,4};
    int result = -1;

    result = maxProfit(prices, prices_size);
    assert(result == 7);
}

void test2() {
    int prices_size = 5;
    int prices[] = {1,2,3,4,5};
    int result = 0;

    result = maxProfit(prices, prices_size);
    assert(result == 4);
}

void test3() {
    int prices_size = 5;
    int prices[] = {7,6,4,3,1};
    int result = 0;

    result = maxProfit(prices, prices_size);
    assert(result == 0);
}

void main() {
    test1();
    test2();
    test3();
}
