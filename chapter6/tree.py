# coding: utf-8

import json
from random import randrange, shuffle


class Node(object):

    def __init__(self, word):
        self.word = word
        self.count = 1
        self.left = None
        self.right = None

    def add(self, word):
        if word == self.word:
            self.count += 1
        elif word < self.word:
            if self.left:
                self.left.add(word)
            else:
                self.left = Node(word)
        elif word > self.word:
            if self.right:
                self.right.add(word)
            else:
                self.right = Node(word)

    def add_words(self, words):
        for word in words:
            self.add(word)

    def search(self, word):
        if word == self.word:
            return self
        elif word < self.word and self.left:
            return self.left.search(word)
        elif word > self.word and self.right:
            return self.right.search(word)
        return None

    def items(self):
        return {
            'word': self.word,
            'count': self.count,
            'left': self.left.items() if self.left else None,
            'right': self.right.items() if self.right else None,
        }

    def __str__(self):
        return json.dumps(self.items(), indent=2)


def main():
    get_alpha = lambda: chr(randrange(97, 123))
    get_word = lambda: ''.join([get_alpha() for i in range(randrange(4, 10))])
    get_article = lambda: ' '.join([' '.join([get_word()] * randrange(10))
        for i in range(randrange(2000, 3000))])
    words = get_article().split()
    shuffle(words)

    a = words.pop()
    root = Node(words.pop())
    root.add_words(words)
    print root
    print root.search(a)


if __name__ == '__main__':
    main()
