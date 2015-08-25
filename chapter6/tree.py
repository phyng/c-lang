# coding: utf-8

import json
from random import randrange, shuffle


class Node(object):

    def __init__(self, word):
        self.word = word
        self.count = 1
        self.left = None
        self.right = None

    def __str__(self):
        return '{{"word": "{}", "count": {}, "left": {}, "right": {}}}'.format(
            self.word, self.count, str(self.left or 'null'), str(self.right or 'null'))


def add_to_tree(root_node, word):

    if word == root_node.word:
        root_node.count += 1
    elif word < root_node.word:
        if root_node.left:
            add_to_tree(root_node.left, word)
        else:
            root_node.left = Node(word)
    elif word > root_node.word:
        if root_node.right:
            add_to_tree(root_node.right, word)
        else:
            root_node.right = Node(word)


def main():
    get_alpha = lambda: chr(randrange(97, 123))
    get_word = lambda: ''.join([get_alpha() for i in range(randrange(4, 10))])
    get_article = lambda: ' '.join([' '.join([get_word()] * randrange(10))
        for i in range(randrange(2000, 3000))])
    words = get_article().split()
    shuffle(words)

    root = Node(words.pop())
    for word in words:
        add_to_tree(root, word)
    print json.dumps(json.loads(str(root)), indent=2)


if __name__ == '__main__':
    main()
