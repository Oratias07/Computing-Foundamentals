# pseudo code (adjusted)
*used:* → ← ≥ ≤ ≠

# Counts how many elements in the array are greater than 'num'
# findAboveCount(int num, int arr[], int size)

## initialize variables
- i ← 0
- greaterThan ← 0
- num ← the num to compared to
- arr ← the array
- size ← length of arr

## loop throuth array
(LOOP)
    if (size - i ≤ 0) **goto** (CONT)
    if (arr[i] - num ≤ 0) **goto** (CONTLOOP)
    greaterThan ← greaterThan + 1

(CONTLOOP)
    i ← i + 1
    **goto** (LOOP)

## return result
(CONT)
    **return** greaterThan

(END)

# Finds the k-th largest element in the array
# findKth(int arr[], int size, int k)

## initialize variables
- i ← 0
- arr ← the array
- size ← length of arr
- k ← the k index
- aboveCount

## loop throuth array
(LOOP)
    if (size - i ≤ 0) **goto** (CONT)
    aboveCount = findAboveCount(arr[i], arr, size)
    if (k - aboveCount - 1 ≠ 0) **goto** (CONTLOOP)
    **return** arr[i]

(CONTLOOP)
    i ← i + 1
    **goto** (LOOP)

## return result
(CONT)
    **return** -1

(END)

# Main program
## initialize variables
- arr ← {11, 22, 33, 55, 44, 100}      # the array
- size ← length of arr                 # number of elements in array
- k ← 3                                # the k-th largest to find
- kth                                  # variable to store the k-th largest element

**toStack** ← size, arr, kth
## find the k-th largest element
kth ← findKth(arr, size, k)
**freeStack**

**toStack** ← kth, arr, size
## count how many elements are greater than kth
aboveCount ← findAboveCount(kth, arr, size)
**freeStack**

## print result
print "There are", aboveCount, "elements greater than the", k, "-th largest element."

(END)
