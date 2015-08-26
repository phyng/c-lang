# coding: utf-8

from utils import get_words


class HashTable(object):

    def __init__(self, items=None, hashsize=100):
        self.hashsize = hashsize
        self.hashtable = [None] * hashsize
        if items:
            self.add_items(items)

    def add_item(self, item):
        index = self.hash(item)
        chain = self.hashtable[index]
        if chain is None:
            self.hashtable[index] = [item]
        else:
            chain.append(item)

    def add_items(self, items):
        for item in items:
            self.add_item(item)

    def hash(self, item):
        return hash(item) % self.hashsize

    def search(self, item):
        index = self.hash(item)
        chain = self.hashtable[index]
        if chain is None:
            return None
        else:
            for i in chain:
                if i == item:
                    return i
        return None

    def __iter__(self):
        for i in self.hashtable:
            yield i

    def __str__(self):
        return str(self.hashtable)


def main():
    words = get_words()[:100]
    item = words[0]
    hashtable = HashTable(words, hashsize=10)
    print hashtable
    print hashtable.search(item)

if __name__ == '__main__':
    main()
