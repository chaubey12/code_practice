from typing import List

def buy_and_sell_stock_once(prices: List[float]) -> float:
    min_price_so_far, max_profit = float('inf'), 0.0
    for price in prices:
        max_profit_sell_today = price - min_price_so_far
        max_profit = max(max_profit, max_profit_sell_today)
        min_price_so_far = min(price, min_price_so_far)
    return max_profit

if __name__ == '__main__':
    prices = [310, 315, 275, 295, 260, 270, 290, 230, 255, 250]
    print(buy_and_sell_stock_once(prices))