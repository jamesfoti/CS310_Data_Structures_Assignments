# 3.6 Exercises
**2. The 0-1 Knapsack:** Encumbrance limits restrict the number of items games allow players to carry. Consequently, while exploring and collecting inventory items, players must manually calculate which items to keep and which to discard. Write a function that performs this calculation auto-mechanically. It shall take three input parameters by constant reference: an array of item weights, and array of item values, and an integer weight limit. It shall return an array of boolean values where a true in the array indicates that the corresponding index item belongs in the array to maximize its value. <br /><br /> Weights: **{1, 2, 3, 4, 5}** <br /><br /> Values: **{15,20,30,40,50}** <br /><br /> Limit: **50** <br /><br /> Return: **{true, false, false, true, false}**  <br /> <br />

**3. Software Decode:** Write a function that accepts an in-order array of unsigned short values. The function shall then scan the array for a specific pattern: Three values contained within the array equally spaced 20 units apart. The function shall return the index position within the original array where the pattern begins or -1 if not present. <br /> <br /> Given the input array: **data[] = {10,20,31,40,55,60,65525}** <br /> <br /> The function shall return: **1**  <br /> <br />

**4. 1-1-0 Detection:** Modify Problem 3 such that it returns the index of the beginning of a sequence where the first two elements are 20 units apart and there is NO element 40 units away from the first. Two elements present, one absent. <br /> <br />

# 5.4 Exercises
**6.** Primitive arrays, using the standard bracket notation, provide powerful functionality in both C and C++, but they lack many of the methods and features object oriented programmers expect. Create a class, called **DynamicCharArray**, which wraps around the standard char array and offers the following features: 

* **Default constructor:** initializes an internal array of 8 elements 
* **Copy constructor:** called implicitly when making a copy 
* **int size():** returns the length of the array 
* **void expand(int amount):** increases the capacity of the array by the specified amount. It will need to create a new internal array and copy the elements over to accomplish this correctly, but it need not initialize the increased space. 
* **Destructor:** if the solution allocates heap memory, the destructor shall free it. 
