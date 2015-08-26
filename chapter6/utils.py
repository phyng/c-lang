
from random import randrange, shuffle


get_alpha = lambda: chr(randrange(97, 123))


get_word = lambda: ''.join([get_alpha() for i in range(randrange(4, 10))])


get_article = lambda: ' '.join([' '.join([get_word()] * randrange(10))
    for i in range(randrange(2000, 3000))])


def get_words():
    words = get_article().split()
    shuffle(words)
    return words
