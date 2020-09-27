def isMagic(target):
    n = len(target)
    res = [i for i in range(1, n+1) if i & 1 == 0] + [i for i in range(1, n+1) if i & 1 == 1]
    k = 0
    while k < n and res[k] == target[k]:
        k += 1
    if k == n:
        return True
    ans = []
    res = [i for i in range(1, n + 1)]
    cur = 0
    while len(res) != 0:
        res = [res[i-1] for i in range(1, len(res)+1) if i & 1 == 0] + [res[i-1] for i in range(1, len(res)+1) if i & 1 == 1]
        ans += res[:k]
        if res[:k] != target[cur: k]:
            return False
        # if ans != target[:len(ans)]:
        #     return False
        res = res[k:]
        cur += k
    if ans == target:
        return True
    else:
        return False