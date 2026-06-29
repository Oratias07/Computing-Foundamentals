Pseudo Code (Adjusted)
used: → ← ≥ ≤ ≠ &

# Sums only the even elements of an array
# sumArr(int arr[], int size)
## initialize variables
- i ← 0
- sum ← 0
- arr ← the array
- size ← length of arr
- tempBit ← 0

loop through array
(LOOP) if (size - i ≤ 0) goto (CONT)

# Bitwise AND with 1 to check parity (0 if even, 1 if odd)
tempBit ← arr[i] & 1
if (tempBit ≠ 0) **goto** (CONTLOOP)

# If even, add to sum
sum ← sum + arr[i]
(CONTLOOP) i ← i + 1 **goto** (LOOP)

return result
(CONT) return sum

(END)

# Main program
## initialize variables
- arr ← {100, 200, 21, -5}          # the array
- size ← 4                          # length of the array
- result ← 0                        # variable to store the final sum

**toStack** ← arr, size
## call sumArr function
result ← sumArr(arr, size)
**freeStack**

## print result
print "The sum of even members is:", result

(END)