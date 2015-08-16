# coding: utf-8

def swap(v, i, j):
    temp = v[i]
    v[i] = v[j]
    v[j] = temp

def qsort(v, left, right):
    if left >= right:
        return
    swap(v, left, (left + right) / 2)
    last = left
    i = left + 1
    while i <= right:
        try:
            if v[i] < v[left]:
                last += 1
                swap(v, last, i)
        except IndexError:
            pass
        i += 1
    swap(v, left, last)
    qsort(v, left, last - 1)
    qsort(v, last + 1, right)

v = [2, 1, 7, 8, 3, 5, 7, 2, 3, 6, 5, 1, 2]
qsort(v, 0, 12)
print v
