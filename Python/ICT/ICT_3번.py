from collections import Counter
ids_count = int(input())
ids = []
for _ in range(ids_count):
    ids.append(int(input()))
m = int(input())

def deleteProducts(ids, m):
    id_counts = Counter(ids)
    sorted_id_counts = sorted(id_counts.values())
    while True:
        if m == 0:
            break
        if m >= sorted_id_counts[0]:
            m -= sorted_id_counts[0]
            sorted_id_counts.pop(0)
        else:
            break

    return len(sorted_id_counts)

print(deleteProducts(ids,m))