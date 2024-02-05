def binary_search_deluxe(list, key):
    
    left = 0
    right = len(list) - 1
    while left <= right:
        mid = (left + right) // 2
        if list[mid] < key:
            left = mid + 1
        else:
            right = mid - 1

    start = left

    left = 0
    right = len(list) - 1

    while left <= right:
        mid = (left + right) // 2
        if list[mid] <= key:
            left = mid + 1
        else:
            right = mid - 1

    end = left - 1

    return [start, end]


print(binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 10))

