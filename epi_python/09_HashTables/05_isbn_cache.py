import collections

class LruCache:
    def __init__(self, capacity: int)->None:
        self._isbn_price_table : collections.OrderedDict[int, int] = collections.OrderedDict()
        self._capacity = capacity

    def lookup(self, isbn: int)->int:
        if isbn not in self._isbn_price_table:
            return -1
        price = self._isbn_price_table.pop(isbn)
        self._isbn_price_table[isbn] = price
        return price

    def insert(self, isbn: int, price: int)->None:
        if isbn in self._isbn_price_table:
            price = self._isbn_price_table.pop(isbn)
        elif len(self._isbn_price_table) == self._capacity:
            self._isbn_price_table.popitem(last=False)
        self._isbn_price_table[isbn] = price

    def erase(self, isbn: int)->bool:
        return self._isbn_price_table.pop(isbn, None) is not None
        